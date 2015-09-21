#include "Map.h"
#include "Analyzers.h"
#include <iostream>
#include "SOIL\include\SOIL.h"
#include "boost\filesystem.hpp"

Map::Map(SoundAnalyzer& Sound)
{
	this->RefSound = Sound;

	this->Shader.LoadVertexShader("textureShader.vs");
	this->Shader.LoadFragmentShader("textureShader.fs");
	this->Shader.Create();

	this->ShaderProgram = this->Shader.GetProgram();

	this->ConstructVBO();
	this->ConstructEBO();

	this->GenTexture("grass_01.jpg");
}

void Map::GenTexture(const char* textureName)
{
	glGenTextures(1, &this->TextureBuffer);
	glBindTexture(GL_TEXTURE_2D, this->TextureBuffer);

	int width, height;
	unsigned char* image =
		SOIL_load_image(std::string(boost::filesystem::current_path().parent_path().generic_string() + "/Texture/" + textureName).c_str(), &width, &height, 0, SOIL_LOAD_RGB);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
		GL_UNSIGNED_BYTE, image);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_MIRRORED_REPEAT);

	SOIL_free_image_data(image);
}

void Map::ConstructEBO()
{
	std::vector<unsigned int> indices;
	indices.reserve((this->Length-1) * (this->Length-1) * 6);

	for (float i = 0; i < this->Length-1; ++i)
	{
		for (float j = 0; j < this->Length-1; ++j)
		{
			indices.push_back((unsigned int)(j +     ( i      * this->Length)    ));
			indices.push_back((unsigned int)(j +     ((i + 1) * this->Length) + 1));
			indices.push_back((unsigned int)(j + 1 + (i       * this->Length)    ));

			indices.push_back((unsigned int)(j + ( i      * this->Length)    ));
			indices.push_back((unsigned int)(j + ((i + 1) * this->Length)    ));
			indices.push_back((unsigned int)(j + ((i + 1) * this->Length) + 1));
		}
	}

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices.front(), GL_STATIC_DRAW);
}

void Map::ConstructVBO()
{
	std::vector<float> vertex;

	GetCumuledAmplitudePerTickResult tickAmplitude;
	Analyzers::GetCumuledAmplitudePerTick(RefSound, tickAmplitude);

	this->Length = tickAmplitude.CumuledAmplitudePerTick.size();
	vertex.reserve(this->Length * this->Length * 6); //6 elements par point(x,y,z, RGB) * nbpoint (length * length) pour le moment

	for (float i = -(this->Length / 2.0f); i < (this->Length / 2.0f); ++i)
	{
		float rndR = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		float rndG = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		float rndB = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		for (float j = -(this->Length / 2.0f ); j < (this->Length / 2.0f); ++j)
		{
			vertex.push_back(j); //x
			vertex.push_back((float)tickAmplitude.CumuledAmplitudePerTick[j + (this->Length / 2)]); //y
			vertex.push_back(i); //z

			vertex.push_back(rndR); //r
			vertex.push_back(rndG); //g
			vertex.push_back(rndB); //b
		}
	}

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(float), &vertex.front(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Map::Draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix, const glm::mat4& worldTransform, const float& time) const
{
	glUseProgram(this->ShaderProgram);

	GLint projLocation = glGetUniformLocation(this->ShaderProgram, "u_projectionMatrix");
	glUniformMatrix4fv(projLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	GLint viewLocation = glGetUniformLocation(this->ShaderProgram, "u_viewMatrix");
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	GLint worldLocation = glGetUniformLocation(this->ShaderProgram, "u_worldMatrix");
	glUniformMatrix4fv(worldLocation, 1, GL_FALSE, glm::value_ptr(worldTransform));

	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	GLint positionLocation = glGetAttribLocation(this->ShaderProgram, "a_position");
	glEnableVertexAttribArray(positionLocation);
	glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);

	GLint colorLocation = glGetAttribLocation(this->ShaderProgram, "a_color");
	glEnableVertexAttribArray(colorLocation);
	glVertexAttribPointer(colorLocation, 3, GL_FLOAT, GL_FALSE, sizeof(float)* 6, (void*)(3 * sizeof(float)));

	//GLint texAttrib = glGetAttribLocation(this->ShaderProgram, "texcoord");
	//glEnableVertexAttribArray(texAttrib);
	//glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE,7 * sizeof(float), (void*)(5 * sizeof(float)));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glDrawElements(GL_TRIANGLES, (this->Length-1) * (this->Length-1) * 6, GL_UNSIGNED_INT, nullptr);

	glUseProgram(0);
}

void Map::Destroy()
{
	//delete aussi les textures

	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &VBO);

	this->Shader.Destroy();
}

Map::~Map()
{
	this->Destroy();
}

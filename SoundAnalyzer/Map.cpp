#include "Map.h"

Map::Map()
{
	this->Shader.LoadVertexShader("basic.vs");
	this->Shader.LoadFragmentShader("basic.fs");
	this->Shader.Create();

	this->ShaderProgram = this->Shader.GetProgram();

	this->ConstructVBO();
	this->ConstructEBO();
}

void Map::ConstructEBO()
{
	unsigned short indices[] =
	{
		0, 1, 2,
		0, 2, 3
	};

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void Map::ConstructVBO()
{
	float vertex[] = {
		0, 0, 0, 1.0f, 0.0f, 0.0f,
		0, 0, 10, 0.0f, 1.0f, 0.0f,
		0, 10, 10, 0.0f, 1.0f, 0.0f,
		0, 10, 0, 1.0f, 0.0f, 0.0f
	};

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
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
	glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, sizeof(float)* 3, 0);

	GLint colorLocation = glGetAttribLocation(this->ShaderProgram, "a_color");
	glEnableVertexAttribArray(colorLocation);
	glVertexAttribPointer(colorLocation, 3, GL_FLOAT, GL_FALSE, sizeof(float)* 3, (void*)(3 * sizeof(float)));

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, nullptr);

	glUseProgram(0);
}

void Map::Destroy()
{

}

Map::~Map()
{
}

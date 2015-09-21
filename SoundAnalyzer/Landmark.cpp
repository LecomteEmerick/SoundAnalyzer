#include "Landmark.h"


Landmark::Landmark()
{
	this->Shader.LoadVertexShader("basic.vs");
	this->Shader.LoadFragmentShader("basic.fs");
	this->Shader.Create();

	this->ShaderProgram = this->Shader.GetProgram();

	this->ConstructEBO();
	this->ConstructVBO();
}

void Landmark::ConstructEBO()
{
	glGenBuffers(1, &this->EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void Landmark::ConstructVBO()
{
	glGenBuffers(1, &this->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Landmark::Draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix, const glm::mat4& worldTransform, const float& time) const
{
	glPointSize(5.0f);

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
	glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, sizeof(float)* 6, 0);

	GLint colorLocation = glGetAttribLocation(this->ShaderProgram, "a_color");
	glEnableVertexAttribArray(colorLocation);
	glVertexAttribPointer(colorLocation, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(3 * sizeof(float)));

	glDrawArrays(GL_POINTS, 0, 6);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glDrawElements(GL_LINES, 6, GL_UNSIGNED_SHORT, nullptr);

	glPointSize(1.0f);

	glUseProgram(0);
}

void Landmark::Destroy()
{
	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &VBO);

	this->Shader.Destroy();
}



Landmark::~Landmark()
{
}

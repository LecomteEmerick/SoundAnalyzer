#pragma once
#include "DrawableItem.h"
#include "common\EsgiShader.h"

const float vertex[] = { 
	0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f
};

const unsigned short indices[] = {
	0, 1,
	0, 2,
	0, 3
};

class Landmark : public DrawableItem
{
public:
					Landmark();
	void			Draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix, const glm::mat4& worldTransform, const float& time) const;
	void			Destroy();
					~Landmark();
private:
	void			ConstructEBO();
	void			ConstructVBO();
	GLuint			EBO;
	GLuint			VBO;
	GLuint			ShaderProgram;
	EsgiShader		Shader;
};


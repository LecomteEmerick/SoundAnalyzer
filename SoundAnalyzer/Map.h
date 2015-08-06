#pragma once
#include "DrawableItem.h"
#include "common\EsgiShader.h"

class Map : public DrawableItem
{
public:
				Map();
	void		Draw(const glm::mat4x4& projectionMatrix, const glm::mat4x4& viewMatrix, const glm::mat4x4& worldTransform, const float& time) const;
	void		Destroy();
				~Map();
private:
	void		ConstructEBO();
	void		ConstructVBO();
	GLuint		EBO;
	GLuint		VBO;
	GLuint		ShaderProgram;
	EsgiShader	Shader;
};


#pragma once

#define GLEW_STATIC 1
#include "glew.h"
#include "glm.hpp"
#include "gtc/type_ptr.hpp"

#define GLFW_INCLUDE_GLU
#include "glfw3.h"

class DrawableItem
{
public:
	virtual void	Draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix, const glm::mat4& worldTransform,const float& time) const = 0;
	virtual void	Destroy() = 0;
private:
	virtual void	ConstructEBO() = 0;
	virtual void	ConstructVBO() = 0;
	GLuint			EBO;
	GLuint			VBO;
	GLuint			ShaderProgram;
};


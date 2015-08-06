#pragma once

//WTF fix that shit ! Goto main.cpp
#if _WIN32
#include <Windows.h>
#define FREEGLUT_LIB_PRAGMAS 0
#pragma comment(lib, "freeglut.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glu32.lib")
#endif

#define GLEW_STATIC 1
#include "glew.h"
#include "freeglut.h"
#include "glm.hpp"
#include "gtc/type_ptr.hpp"

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


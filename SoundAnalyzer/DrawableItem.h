#pragma once

#if _WIN32
#include <Windows.h>
#define FREEGLUT_LIB_PRAGMAS 0
#pragma comment(lib, "freeglut.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glu32.lib")
#endif

#include "glew.h"
#include "freeglut.h"

class DrawableItem
{
public:
	GLuint			ShaderProgram;
	virtual void	Construct() = 0;
	virtual void	Draw() = 0;
	virtual void	Destroy() = 0;
};


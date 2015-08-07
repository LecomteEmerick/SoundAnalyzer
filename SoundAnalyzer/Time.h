#pragma once

#define GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_GLU
#include "glfw3.h"

class Time
{
public:
	static void		Start();
	static void		Update();
	static float	GetSecondElapsed();
	static void		Play();
	static void		Pause();
private:
	static float	time_;
	static bool		isStarted_;
	static float	previousTime_;
};


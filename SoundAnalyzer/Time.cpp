#include "Time.h"

float	Time::time_;
int		Time::previousTime_;
bool	Time::isStarted_;

void Time::Start()
{
	Time::previousTime_ = glfwGetTime();
	Time::time_ = 1.0f;
	Time::isStarted_ = true;
}

void Time::Update()
{
	int currentTime;
	int delta;

	currentTime = glfwGetTime();
	delta = currentTime - Time::previousTime_;
	Time::previousTime_ = currentTime;

	Time::time_ = 1.0f;
	if (!isStarted_)
		Time::time_ += delta / 1000.0f;
}

float Time::GetSecondElapsed()
{
	return Time::time_;
}

void Time::Play()
{
	Time::isStarted_ = true;
}

void Time::Pause()
{
	Time::isStarted_ = false;
}
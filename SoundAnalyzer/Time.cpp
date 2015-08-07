#include "Time.h"

float	Time::time_;
float	Time::previousTime_;
bool	Time::isStarted_;

void Time::Start()
{
	Time::previousTime_ = glfwGetTime();
	Time::time_ = 1.0f;
	Time::isStarted_ = true;
}

void Time::Update()
{
	float currentTime;
	float delta;

	currentTime = glfwGetTime();
	delta = currentTime - Time::previousTime_;
	Time::previousTime_ = currentTime;

	Time::time_ = 1.0f;
	if (!isStarted_)
		Time::time_ += delta;
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
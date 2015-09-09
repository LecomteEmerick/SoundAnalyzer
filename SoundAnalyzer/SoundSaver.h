#pragma once
#include "fmod.hpp"

class SoundSaver
{
public:
	static void SaveSound(FMOD::Sound* Sound, char* fileName);
};


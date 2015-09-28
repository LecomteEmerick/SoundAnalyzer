#pragma once
#include "fmod.hpp"
#include <vector>

class MusicPlayer
{
public:
	static void Start();
	static void Update();
private:
	FMOD::SoundGroup playList;
	FMOD::System system;
};


#pragma once
#include <vector>

#include "SoundAnalyzer.h"

class RefSoundLib
{
public:
	static std::vector<std::unique_ptr<SoundAnalyzer>>		SoundLib;
	static void												Initialize(char* MyApplicationPath);
};


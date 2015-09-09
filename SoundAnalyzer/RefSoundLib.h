#pragma once
#include <vector>

#include "SoundAnalyzer.h"

class RefSoundLib
{
public:
	static			std::vector<SoundAnalyzer> SoundLib;
	static void		Initialize(char* MyApplicationPath);
};


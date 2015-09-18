#pragma once
#include "SoundAnalyzer.h"

class SoundFile
{
public:
	static void CheckSaveExist(char* SoundName);
	static void SaveSpectrum(SoundAnalyzer& sound);
	static void LoadSpectrum(SoundAnalyzer& outSound);
};


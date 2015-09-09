#pragma once

#include "SpectrumData.h"
#include "fmod.hpp"

class SoundAnalyzer
{
public:
	FMOD::Sound*		Sound;
	FMOD::System*		sys;
	SoundSpectrum		data;

						SoundAnalyzer() {}
						SoundAnalyzer(char* soundPath, int windowSize );
						SoundAnalyzer::SoundAnalyzer(FMOD::System* sys, FMOD::Sound* sound, int windowSize);
	int					GetWindowSize()																{ return this->windowSize; }
	void				SetFrequencyStep(float frequencyStep)										{ this->frequencyStep_ = frequencyStep; }
						~SoundAnalyzer();
private:
	char*				SoundPath;
	int					windowSize;
	float				frequencyStep_;
};


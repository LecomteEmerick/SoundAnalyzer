#pragma once

#include "SpectrumData.h"
#include "fmod.hpp"

#define MAX_CHANNELS 2

class SoundAnalyzer
{
public:
	FMOD::Sound*		Sound;
	FMOD::System*		sys;
	SoundSpectrum		data;
	std::string			SoundPath;

						SoundAnalyzer() {}
						SoundAnalyzer(const char* soundPath,int windowSize );
						SoundAnalyzer::SoundAnalyzer(FMOD::System* sys, FMOD::Sound* sound, int windowSize);
	int					GetWindowSize()																{ return this->windowSize; }
	void				SetFrequencyStep(float frequencyStep)										{ this->frequencyStep_ = frequencyStep; }
						~SoundAnalyzer();
private:
	int					windowSize;
	float				frequencyStep_;
};


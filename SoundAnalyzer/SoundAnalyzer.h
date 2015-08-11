#pragma once

#include "SpectrumData.h"
#include "fmod.hpp"

class SoundAnalyzer
{
public:
	FMOD::Sound*		Sound;
	FMOD::System*		sys;
	SoundSpectrum		data;

						SoundAnalyzer(char* soundPath, int windowSize );
	int					GetWindowSize()																{ return this->windowSize; }
	float				GetFrequencyRangeStart()													{ return this->frequencyRangeStart_; }
	float				GetFrequencyRangeEnd()														{ return this->frequencyRangeEnd_; }
	void				SetAnalyzeFunction(std::function<void(SoundAnalyzer*)> func)				{ this->AnalyzeFunction = func; }
	void				SetFrequencyStep(float frequencyStep)										{ this->frequencyStep_ = frequencyStep; }
	void				SetAnalyzeTypeAverageAmplitude(int frequencyStart, int frequencyEnd);
	void				ExecuteAnalyze();
						~SoundAnalyzer();
private:
	char*				SoundPath;
	int					windowSize;
	float				frequencyRangeStart_;
	float				frequencyRangeEnd_;
	float				frequencyStep_;

	std::function<void(SoundAnalyzer*)> AnalyzeFunction;
};


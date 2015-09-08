#pragma once

#include "virtualAnalyzerTool.h"
#include "SpectrumData.h"
#include "fmod.hpp"

template<typename T>
class SoundAnalyzer
{
public:
	FMOD::Sound*		Sound;
	FMOD::System*		sys;
	SoundSpectrum		data;
	T					Analyzer;

						SoundAnalyzer(char* soundPath, int windowSize );
	int					GetWindowSize()																{ return this->windowSize; }
	void				SetFrequencyStep(float frequencyStep)										{ this->frequencyStep_ = frequencyStep; }
	void				ExecuteAnalyze()															{ this->Analyzer.Execute(this); }
						~SoundAnalyzer();
private:
	char*				SoundPath;
	int					windowSize;
	float				frequencyStep_;
};


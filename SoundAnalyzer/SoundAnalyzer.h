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
	float				GetFrequencyRangeStart()													{ return this->frequencyRangeStart_; }
	float				GetFrequencyRangeEnd()														{ return this->frequencyRangeEnd_; }
	void				SetFrequencyStep(float frequencyStep)										{ this->frequencyStep_ = frequencyStep; }
	T					ExecuteAnalyze()															{ this->Analyzer.execute(); return this->Analyzer.GetResult(); }
						~SoundAnalyzer();
private:
	char*				SoundPath;
	int					windowSize;
	float				frequencyRangeStart_;
	float				frequencyRangeEnd_;
	float				frequencyStep_;
};


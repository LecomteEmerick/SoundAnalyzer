#pragma once

#include <functional>
#include "SoundAnalyzer.h"

class AnalyzerTool
{
public:
	static void		getSpectrum(SoundAnalyzer& outSoundAnalyzer);
	static void		GetAverageAmplitudeOnRange(const SoundAnalyzer& analyzer);
private:
	static void		ExtractRange(const SoundAnalyzer& analyzer, SpectrumData& outRangedSpectrum);
};


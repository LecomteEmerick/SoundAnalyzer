#pragma once

#include <functional>
#include "virtualAnalyzerTool.h"
#include "SoundAnalyzer.h"

class AnalyzerToolUtils
{
public:
	static void		getSpectrum(SoundAnalyzer* outSoundAnalyzer);
	//
	static void		ExtractRange(const SoundAnalyzer& analyzer, SoundSpectrum& outRangedSpectrum);
};
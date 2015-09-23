#pragma once

#include "SoundAnalyzer.h"

#define SPECTRUM_BUFFER_SIZE 16384 //pr�cision par d�fault 1024 max 16384

class AnalyzerToolUtils
{
public:
	static void			getSpectrum(SoundAnalyzer* outSoundAnalyzer);
	static void			ExtractRange(const SoundAnalyzer& analyzer, SoundSpectrum& outRangedSpectrum);
};
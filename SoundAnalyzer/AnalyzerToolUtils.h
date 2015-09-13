#pragma once

#include "SoundAnalyzer.h"

#define SPECTRUM_BUFFER_SIZE 4096 //précision par défault 1024

class AnalyzerToolUtils
{
public:
	static void										getSpectrum(SoundAnalyzer* outSoundAnalyzer);
	static void										ExtractRange(const SoundAnalyzer& analyzer, SoundSpectrum& outRangedSpectrum);
};
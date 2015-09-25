#pragma once

#include "SoundAnalyzer.h"

#define SPECTRUM_BUFFER_SIZE 16384 //précision par défault 1024 max 16384

class AnalyzerToolUtils
{
public:
	static void			getSpectrum(SoundAnalyzer* outSoundAnalyzer);
	static void			ExtractRange(const SoundAnalyzer& analyzer, SoundSpectrum& outRangedSpectrum);
private:
	static void			AnalyzerToolUtils::ExtractSpectrum(SoundAnalyzer* soundAnalyzer, const FMOD_DSP_PARAMETER_FFT dataSpectrum, int size, float frequencyStep, int index);
};
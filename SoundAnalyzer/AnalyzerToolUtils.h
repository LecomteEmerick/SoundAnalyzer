#pragma once

#include <functional>
#include "virtualAnalyzerTool.h"
#include "SoundAnalyzer.h"

class AnalyzerToolUtils
{
public:
	template<typename T>
	static void		getSpectrum(SoundAnalyzer<T>* outSoundAnalyzer);
	//
	template<typename T>
	static void		ExtractRange(const SoundAnalyzer<T>& analyzer, SoundSpectrum& outRangedSpectrum);
};
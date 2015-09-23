#pragma once
#include "AnalyzerToolUtils.h"
#include "AnalysisResultInclude.h"

class NormalizedDataResult
{
public:
	int Length;
	int Width;
	std::vector<std::vector<float>> Data;
};

class Analyzers
{
public:
	static void GetCumuledAmplitudePerTick(const SoundAnalyzer& analyzer, GetCumuledAmplitudePerTickResult& result);
	static void Analyzers::GetCumuledAmplitudePerTickNormalized(const SoundAnalyzer& analyzer, NormalizedDataResult& result);
};


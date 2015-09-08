#pragma once
#include "SoundAnalyzer.h"
#include "virtualAnalyzerTool.h"

struct GetAverageAmplitudeAnalyzerResult_t
{
	std::vector<float> Spectrum[];
};

class GetAverageAmplitudeAnalyzer : public virtualAnalyzerTool
{
public:
											GetAverageAmplitudeAnalyzer();
	void									Initialize(int StartRangeFrequency, int EndRangeFrequency);
	void									Execute(SoundAnalyzer& SoundInfos);
	GetAverageAmplitudeAnalyzerResult_t		GetResult() { return Result; }
											~GetAverageAmplitudeAnalyzer();
private:
	int startRangeFrequency_, endRangeFrequency_;
	GetAverageAmplitudeAnalyzerResult_t Result;
};


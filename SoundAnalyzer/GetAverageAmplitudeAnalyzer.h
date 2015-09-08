#pragma once
#include "SoundAnalyzer.h"

struct GetAverageAmplitudeAnalyzerResult_t
{
	float Spectrum[];
};

class GetAverageAmplitudeAnalyzer : public virtualAnalyzerTool
{
public:
											GetAverageAmplitudeAnalyzer();
	void									Initialize(int StartRangeFrequency, int EndRangeFrequency);
	void									Execute(SoundAnalyzer<GetAverageAmplitudeAnalyzer>& SoundInfos);
	GetAverageAmplitudeAnalyzerResult_t		GetResult() { return Result; }
											~GetAverageAmplitudeAnalyzer();
private:
	int startRangeFrequency_, endRangeFrequency_;
	GetAverageAmplitudeAnalyzerResult_t Result;
};


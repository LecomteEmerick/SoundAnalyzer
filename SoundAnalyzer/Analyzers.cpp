#include "Analyzers.h"

void Analyzers::GetCumuledAmplitudePerTick(const SoundAnalyzer& analyzer, GetCumuledAmplitudePerTickResult& result)
{
	double tmpIntensityCum = 0;
	result.CumuledAmplitudePerTick.reserve(analyzer.data.SpectrumData.size());
	for (SpectrumSegment segment : analyzer.data.SpectrumData)
	{
		tmpIntensityCum = 0;
		for (SpectrumData data : segment.SegmentData)
		{
			tmpIntensityCum += data.Intensity;
		}
		result.CumuledAmplitudePerTick.push_back(tmpIntensityCum);
	}
}
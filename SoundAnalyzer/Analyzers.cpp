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

void Analyzers::GetCumuledAmplitudePerTickNormalized(const SoundAnalyzer& analyzer, NormalizedDataResult& result)
{
	double tmpIntensityCum = 0;
	result.Width = static_cast<int>(analyzer.data.SpectrumData.size());
	result.Length = result.Width;
	result.Data.resize(analyzer.data.SpectrumData.size());
	for (int j = 0; j < analyzer.data.SpectrumData.size(); ++j)
		result.Data[j].reserve(analyzer.data.SpectrumData.size());

	for (SpectrumSegment segment : analyzer.data.SpectrumData)
	{
		tmpIntensityCum = 0;
		for (SpectrumData data : segment.SegmentData)
		{
			tmpIntensityCum += data.Intensity;
		}
		for (int j = 0; j < analyzer.data.SpectrumData.size(); ++j)
			result.Data[j].push_back(tmpIntensityCum);
	}
}
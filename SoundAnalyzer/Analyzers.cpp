#include "Analyzers.h"
#include "LinkerVS.h"

#include "boost\thread.hpp"

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
	boost::thread_group threadpool;

	int index = 0;

	result.Width = static_cast<int>(analyzer.data.SpectrumData.size());
	result.Length = result.Width;
	result.Data.resize(result.Width);
	for (int j = 0; j < result.Width; ++j)
		result.Data[j].resize(result.Width);

	for (SpectrumSegment segment : analyzer.data.SpectrumData)
	{
		threadpool.create_thread([segment, &result, index]() {
			double tmpIntensityCum = 0;
			for (SpectrumData data : segment.SegmentData)
			{
				tmpIntensityCum += data.Intensity;
			}
			for (int j = 0; j < result.Width; ++j)
				result.Data[j].at(index) = tmpIntensityCum;
		});
		index++;
	}

	threadpool.join_all();
}
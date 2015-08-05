#pragma once

#include <vector>
#include <memory>

class SpectrumData
{
public:
			float Frequency;
			double Intensity;

			SpectrumData() {}
			SpectrumData(const float frequency, const double intensity) : Frequency(frequency), Intensity(intensity)	{}
			~SpectrumData() {}
};

class SpectrumSegment
{
public:
			std::vector<SpectrumData> SegmentData;

			SpectrumSegment()																							{}
			SpectrumSegment(const int size, const float frequencyStep) : frequencyStep_(frequencyStep)					{ this->SegmentData.reserve(sizeof(SpectrumData) * size); }
	void	AddSegment(const float frequency, const double intensity)													{ this->SegmentData.push_back(SpectrumData(frequency, intensity)); }
	void	AddSegment(const double intensity)																			{ this->SegmentData.push_back(SpectrumData(this->SegmentData.size() * this->frequencyStep_, intensity)); }
	void	AddSegment(SpectrumData Segment)																			{ this->SegmentData.push_back(Segment); }
	void	SetFrequencyStep(const double frequencyStep)																{ this->frequencyStep_ = frequencyStep_; }
			~SpectrumSegment() {}

private:
			float frequencyStep_;
};

class SoundSpectrum
{
public:
			std::vector<SpectrumSegment> SpectrumData;

			SoundSpectrum()																								{}
			SoundSpectrum(const int size)																				{ this->SpectrumData.reserve( sizeof(SpectrumSegment) * size); }
	void	AddData(SpectrumSegment data)																				{ this->SpectrumData.push_back(data); }
			~SoundSpectrum() {}
};


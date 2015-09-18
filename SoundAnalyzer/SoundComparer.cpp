#include "SoundComparer.h"

#include <iostream>

#include "RefSoundLib.h"

#define PERCENT_SIMILAR 0.80
#define PERCENT_ACCEPTABLE 20

bool SoundComparer::Compare(SoundAnalyzer& refSound, SoundAnalyzer& outBestSound)
{
	int refSoundSegmentIndex = 0;
	double refIntensity = 0;
	int percent = 0;
	int compatibilityPercent = 0;
	bool find = false;

	/*std::vector<double> segmentSum;
	double maxintensitySegment;
	for (SpectrumSegment segment : refSound.data.SpectrumData)
	{
		segmentSum.push_back(SoundComparer::SumIntensity(segment.SegmentData));
	}

	SoundComparer::MaxIntensity(segmentSum, maxintensitySegment);

	refSoundSegmentIndex = SoundComparer::getIndexWhereIntensityIsMoreThan(segmentSum, maxintensitySegment * 0.20);*/
	SoundAnalyzer analyzer;
	for (unsigned int i = 0; i < RefSoundLib::SoundLib.size(); i++)//SoundAnalyzer analyzer : RefSoundLib::SoundLib)
	{
		analyzer = *RefSoundLib::SoundLib[i].get();
		compatibilityPercent = 0;
		refSoundSegmentIndex = 0; //remplacer 0 par IndexRefStart
		for (SpectrumSegment segment : analyzer.data.SpectrumData)
		{
			percent = 0;
			for (unsigned int i = 0; i < segment.SegmentData.size(); i++)
			{
				refIntensity = refSound.data.SpectrumData[refSoundSegmentIndex].SegmentData[i].Intensity;
				if (segment.SegmentData[i].Intensity >=  refIntensity - (refIntensity / PERCENT_ACCEPTABLE) && segment.SegmentData[i].Intensity <= refIntensity + (refIntensity / PERCENT_ACCEPTABLE))
				{
					percent++;
				}
			}
			if ((double)percent / (double)segment.SegmentData.size() > PERCENT_SIMILAR)
			{
				compatibilityPercent++;
				refSoundSegmentIndex++;
			}
		}
		if ((double)compatibilityPercent / (double)analyzer.data.SpectrumData.size() > PERCENT_SIMILAR)
		{
			outBestSound = analyzer;
			std::cout << analyzer.SoundPath.c_str() << " match with " << ((double)compatibilityPercent / (double)analyzer.data.SpectrumData.size()) * 100 << "%" << std::endl;
			find = true;
		}
		else
		{
			std::cout << analyzer.SoundPath.c_str() << " don't match" << std::endl;
		}
	}

	return find;
}

double SoundComparer::SumIntensity(std::vector<SpectrumData> spectrum)
{
	double sum=0;
	for (SpectrumData data : spectrum)
	{
		sum += data.Intensity;
	}
	return sum;
}

int SoundComparer::MaxIntensity(std::vector<double> intensitySum, double& maxIntensityOut)
{
	int i = 0;
	int index = -1;
	double maxIntensity = 0;
	for (double intensity : intensitySum)
	{
		if (intensity > maxIntensity)
		{
			maxIntensity = intensity;
			index = i;
		}
		i++;
	}
	maxIntensityOut = maxIntensity;
	return index;
}

int SoundComparer::getIndexWhereIntensityIsMoreThan(std::vector<double> intensitySum, double minimumIntensity)
{
	int i = 0;
	for (double intensity : intensitySum)
	{
		if (intensity > minimumIntensity)
		{
			return i;
		}
		i++;
	}
	return -1;
}

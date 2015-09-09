#pragma once
#include "SoundAnalyzer.h"

class SoundComparer
{
public:
	static bool Compare(SoundAnalyzer& refSound, SoundAnalyzer& outBestSound);
private:
	static double SumIntensity(std::vector<SpectrumData> spectrum);
	static int MaxIntensity(std::vector<double> intensitySum, double& maxIntensityOut);
	static int getIndexWhereIntensityIsMoreThan(std::vector<double> intensitySum, double minimumIntensity);
};


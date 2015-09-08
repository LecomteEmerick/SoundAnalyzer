#pragma once
#include "SoundAnalyzer.h"

class virtualAnalyzerTool
{
public:
	virtual void Execute(SoundAnalyzer& SoundInfos) = 0;
};


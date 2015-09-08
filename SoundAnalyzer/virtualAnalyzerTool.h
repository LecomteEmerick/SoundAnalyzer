#pragma once
class virtualAnalyzerTool
{
public:
	template<typename T>
	virtual void Execute(SoundAnalyzer<T>& SoundInfos) = 0;
};


#include "SoundAnalyzer.h"
#include "AnalyzerTool.h"

SoundAnalyzer::SoundAnalyzer(char* soundPath, int windowSize)
{
	//Init and CreateSound
	FMOD::System_Create(&sys);
	this->sys->init(2, FMOD_INIT_NORMAL, NULL);
	FMOD_RESULT res = sys->createSound(soundPath, FMOD_DEFAULT, NULL, &this->Sound);

	this->windowSize = windowSize;

	if (res == FMOD_OK)
	{
		AnalyzerTool::getSpectrum(this);
	}
	else{
		std::exception( (std::string("Can't open sound : ") + std::string(soundPath)).c_str());
	}
}

void SoundAnalyzer::SetAnalyzeTypeAverageAmplitude(int frequencyStart, int frequencyEnd)
{
	this->frequencyRangeStart_ = ((int)(frequencyStart / this->frequencyStep_)) * frequencyStep_;
	this->frequencyRangeEnd_ = ((int)(frequencyEnd / this->frequencyStep_)) * frequencyStep_;
	this->AnalyzeFunction = AnalyzerTool::GetAverageAmplitudeOnRange;
}

void SoundAnalyzer::ExecuteAnalyze()
{
	this->AnalyzeFunction(this);
}

SoundAnalyzer::~SoundAnalyzer()
{
}

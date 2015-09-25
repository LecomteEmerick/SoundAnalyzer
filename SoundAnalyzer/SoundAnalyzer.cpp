#include "SoundAnalyzer.h"
#include "AnalyzerToolUtils.h"

SoundAnalyzer::SoundAnalyzer(const char* soundPath,int windowSize) //WindowSize correspond a la précision d'analyse du spectre sera gapper tout seul vers 18 000
{
	//Init and CreateSound
	FMOD::System_Create(&sys);
	this->sys->init(MAX_CHANNELS, FMOD_INIT_STREAM_FROM_UPDATE, NULL);
	FMOD_RESULT res = sys->createSound(soundPath, FMOD_CREATESTREAM, NULL, &this->Sound);

	this->SoundPath = std::string(soundPath);
	this->windowSize = windowSize;

	if (res == FMOD_OK)
	{
		AnalyzerToolUtils::getSpectrum(this);
	}
	else
	{
		std::exception( (std::string("Can't open sound : ") + std::string(soundPath)).c_str() );
	}
}

SoundAnalyzer::SoundAnalyzer(FMOD::System* system, FMOD::Sound* sound, int windowSize)
{
	this->SoundPath = std::string("NOPATH");
	this->sys = system;
	this->Sound = sound;
	this->windowSize = windowSize;
	AnalyzerToolUtils::getSpectrum(this);
}

SoundAnalyzer::~SoundAnalyzer()
{
	//this->Sound->release();
	//this->sys->release();
}

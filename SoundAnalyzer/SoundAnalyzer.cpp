#include "SoundAnalyzer.h"
#include "AnalyzerToolUtils.h"

SoundAnalyzer::SoundAnalyzer(char* soundPath, int windowSize)
{
	//Init and CreateSound
	FMOD::System_Create(&sys);
	this->sys->init(2, FMOD_INIT_NORMAL, NULL);
	FMOD_RESULT res = sys->createSound(soundPath, FMOD_DEFAULT, NULL, &this->Sound);

	this->windowSize = windowSize;

	if (res == FMOD_OK)
	{
		AnalyzerToolUtils::getSpectrum(this);
	}
	else{
		std::exception( (std::string("Can't open sound : ") + std::string(soundPath)).c_str() );
	}
}

SoundAnalyzer::~SoundAnalyzer()
{
}

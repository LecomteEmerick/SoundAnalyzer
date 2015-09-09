#include "SoundSaver.h"

void SoundSaver::SaveSound(FMOD::Sound* sound, char* fileName)
{
	FMOD::Channel* chan;
	FMOD_RESULT res;
	FMOD::System* sys;
	FMOD::System_Create(&sys);
	unsigned int soundLenght;
	double index = 0;
	int sampleRate = 0;
	unsigned int bufferlength = 0;

	sound->getLength(&soundLenght, FMOD_TIMEUNIT_MS);
	sys->getSoftwareFormat(&sampleRate, 0, 0);
	sys->setOutput(FMOD_OUTPUTTYPE_WAVWRITER_NRT);
	sys->init(2, FMOD_INIT_STREAM_FROM_UPDATE, fileName);
	
	sys->getDSPBufferSize(&bufferlength, 0);

	res = sys->playSound(sound, 0, false, &chan);
	while (index < soundLenght) {
		res = sys->update();
		index += ((double)bufferlength / (double)sampleRate) * 1000;
	}

	sys->release();
}
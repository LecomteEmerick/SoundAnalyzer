#include "MusicPlayer.h"



void MusicPlayer::Start()
{
	FMOD::System_Create(&MusicPlayer::system);
	this->sys->init(2, FMOD_INIT_STREAM_FROM_UPDATE, NULL);
	FMOD_RESULT res = sys->createSound(soundPath, FMOD_, NULL, &this->Sound);
}

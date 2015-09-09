#pragma once
#include <iostream>
#include "SoundAnalyzer.h"

class MicRecorder
{
public:
	bool			checkIsRecording() { return this->isRecording; }

					MicRecorder();
	void			ChangeRecordedDriver();
	void			StartRecording();
	void			StopRecording(); // return type : SoundAnalyzer&
					~MicRecorder();
private:
	FMOD::System* sys;
	FMOD::Sound* Sound=0;

	bool isRecording=false;
	int recordedDriver = 0;
};


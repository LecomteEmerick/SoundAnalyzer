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
	void			StopRecording(SoundAnalyzer& analyzer);
					~MicRecorder();
private:
	FMOD::System* sys;
	FMOD::Sound* Sound=0;

	bool isRecording=false;
	int recordedDriver = 1; //micro externe sur mon pc
};


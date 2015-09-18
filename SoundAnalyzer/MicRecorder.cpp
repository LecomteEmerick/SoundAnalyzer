#include "MicRecorder.h"



MicRecorder::MicRecorder()
{
	FMOD::System_Create(&this->sys);
	this->sys->init(2, FMOD_INIT_NORMAL, NULL);
}

void MicRecorder::ChangeRecordedDriver()
{
	int numDrivers, numConnected;

	char nameBuffer[256];
	int rate;

	this->sys->getRecordNumDrivers(&numDrivers, &numConnected);

	if (numDrivers == 0)
	{
		std::cout << "No driver found" << std::endl;
		return;
	}

	FMOD_RESULT res;
	for (int i = 0; i < numDrivers; i++)
	{
		res = this->sys->getRecordDriverInfo(i, nameBuffer, 256, NULL, &rate, NULL, NULL, NULL);
		if (res == FMOD_OK)
			std::cout << "Id : " << i << std::endl << "Name : " << nameBuffer << std::endl << "Rate : " << rate << std::endl << std::endl;
	}

	std::cout << "Numero du driver ?" << std::endl;
	std::cin >> this->recordedDriver;
}

void MicRecorder::StartRecording()
{
	int const sampleRate = 44100;
	int const channels = 2;

	if (this->Sound != NULL)
		this->Sound->release();

	FMOD_CREATESOUNDEXINFO soundInfo;// = new FMOD_CREATESOUNDEXINFO();
	memset(&soundInfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	soundInfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);

	// The length of the entire sample in bytes, calculated as:
	// Sample rate * number of channels * bits per sample per channel * number of seconds
	soundInfo.length = sampleRate * channels * sizeof(unsigned short) * 10;

	soundInfo.numchannels = channels;
	soundInfo.defaultfrequency = sampleRate;

	// The sound format (here we use 16-bit signed PCM)
	soundInfo.format = FMOD_SOUND_FORMAT_PCM16;

	this->sys->createSound(0, FMOD_LOOP_NORMAL | FMOD_OPENUSER, &soundInfo, &this->Sound);

	this->sys->recordStart(this->recordedDriver, this->Sound, true);

	this->isRecording = true;
}

void MicRecorder::StopRecording(SoundAnalyzer& analyzer)
{

	this->sys->recordStop(this->recordedDriver);

	this->isRecording = false;

	analyzer = SoundAnalyzer(this->sys, this->Sound, 8192);
	//this->sys->playSound(analyzer.Sound, 0, false, 0); //debug

}

MicRecorder::~MicRecorder()
{
}

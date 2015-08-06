#include <stdio.h>
//#include <stdlib.h>

#pragma comment (lib, "fmod_vc.lib")

#if _WIN32
#include <Windows.h>
#define FREEGLUT_LIB_PRAGMAS 0
#pragma comment(lib, "freeglut.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glu32.lib")
#endif

#include "fmod.hpp"
#include "SpectrumData.h"
#include "OpenGLRenderer.h"

void getSpectrum(char* pathToSound, int windowSize, SoundSpectrum* outSpectrum)
{
	//FMod variable
	FMOD::System* sys;
	FMOD::Sound* sound;
	FMOD::DSP* dspSpectrum;
	FMOD::ChannelGroup* masterChannel;
	FMOD::Channel* chan;
	FMOD_DSP_PARAMETER_FFT *dataSpectrum;

	//Variable
	int sampleRate, musicSpectrumSize;
	unsigned int soundTime, i=0;
	double val;
	float niquistRate;

	//Init and CreateSound
	FMOD::System_Create(&sys);
	sys->init(2, FMOD_INIT_NORMAL, NULL);
	FMOD_RESULT res = sys->createSound(pathToSound, FMOD_DEFAULT, NULL, &sound);

	if (res == FMOD_OK)
	{
		//sound time in MS
		sound->getLength(&soundTime, FMOD_TIMEUNIT_MS);
		outSpectrum->SpectrumData.reserve(soundTime / 1000);

		//DSP / FFT / Window
		sys->createDSPByType(FMOD_DSP_TYPE_FFT, &dspSpectrum);
		dspSpectrum->setParameterInt(FMOD_DSP_FFT_WINDOWSIZE, windowSize);
		dspSpectrum->getParameterInt(FMOD_DSP_FFT_WINDOWSIZE, &musicSpectrumSize,0,0);
		dspSpectrum->setParameterInt(FMOD_DSP_FFT_WINDOWTYPE, FMOD_DSP_FFT_WINDOW_BLACKMAN);

		//Master Channel -> Add Dsp
		sys->getMasterChannelGroup(&masterChannel);
		masterChannel->addDSP(0, dspSpectrum);
		sys->setOutput(FMOD_OUTPUTTYPE_NOSOUND_NRT);
		sys->playSound(sound, masterChannel, false, &chan);

		sys->update();

		//Get Samplerate
		sys->getSoftwareFormat(&sampleRate, 0, 0);
		niquistRate = sampleRate / 2.0f;

		do{
			res = dspSpectrum->getParameterData(FMOD_DSP_FFT_SPECTRUMDATA, (void **)&dataSpectrum, 0, 0, 0);
			SpectrumSegment segment(musicSpectrumSize, musicSpectrumSize / niquistRate);
			for (int bin = 0; bin < dataSpectrum->length; bin++)
			{
				val = 0;
				for (int channel = 0; channel < dataSpectrum->numchannels; channel++)
				{
					val += dataSpectrum->spectrum[channel][bin];
				}
				segment.AddSegment(val);
			}

			outSpectrum->AddData(segment);
			sys->update();
			i++;
		} while (i < (soundTime / 1000));

		//free sound
		sound->release();
	}
}

int main(int argc, char **argv)
{
	OpenGLRenderer::Initialize(argc, argv);
	OpenGLRenderer::Start();
	//SoundSpectrum Spectrum;
	//getSpectrum("C:\\Users\\elecomte\\Documents\\Visual Studio 2013\\Projects\\SoundAnalyzer\\09 Avantasia.ogg", 8192, &Spectrum);
	//system("pause");
}
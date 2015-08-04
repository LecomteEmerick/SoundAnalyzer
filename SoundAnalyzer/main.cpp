#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#pragma comment (lib, "fmod_vc.lib")

#include "fmod.hpp"

void getSpectrum(char* pathToSound)
{
	FMOD::System* sys;
	FMOD::Sound* sound;
	FMOD::System_Create(&sys);

	FMOD::DSP* dspSpectrum;
	FMOD::ChannelGroup* masterChannel;
	FMOD::Channel* chan;
	FMOD_DSP_PARAMETER_FFT *dataSpectrum;

	int i;
	double val;
	unsigned int soundTime;
	std::vector<double> spectrum;
	std::vector<std::vector<double>> musicSpectrum;

	sys->init(2, FMOD_INIT_NORMAL, NULL);
	FMOD_RESULT res = sys->createSound(pathToSound, FMOD_DEFAULT, NULL, &sound);

	if (res == FMOD_OK)
	{
		sound->getLength(&soundTime, FMOD_TIMEUNIT_MS);

		sys->createDSPByType(FMOD_DSP_TYPE_FFT, &dspSpectrum);

		dspSpectrum->setParameterInt(FMOD_DSP_FFT_WINDOWSIZE, 44100);
		dspSpectrum->setParameterInt(FMOD_DSP_FFT_WINDOWTYPE, FMOD_DSP_FFT_WINDOW_BLACKMAN);

		sys->getMasterChannelGroup(&masterChannel);
		masterChannel->addDSP(0, dspSpectrum);

		sys->setOutput(FMOD_OUTPUTTYPE_NOSOUND_NRT);
		sys->playSound(sound, masterChannel, false, &chan);

		i = 0;
		do{
			res = dspSpectrum->getParameterData(FMOD_DSP_FFT_SPECTRUMDATA, (void **)&dataSpectrum, 0, 0, 0);

			spectrum.clear();
			for (int bin = 0; bin < dataSpectrum->length; bin++)
			{
				val = 0;
				for (int channel = 0; channel < dataSpectrum->numchannels; channel++)
				{
					val += dataSpectrum->spectrum[channel][bin];
				}
				spectrum.push_back(val);
			}
			musicSpectrum.push_back(spectrum);

			sys->update();
			i += 1000;
		} while (i < soundTime);
		sound->release();
	}
}

int main(int argc, char **argv)
{
	getSpectrum("C:\\Users\\elecomte\\Documents\\Visual Studio 2013\\Projects\\SoundAnalyzer\\09 Avantasia.ogg");
	system("pause");
}
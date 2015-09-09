#include <stdio.h>

#pragma comment (lib, "fmod_vc.lib")

#include "OpenGLRenderer.h"
#include "SoundAnalyzer.h"

int main(int argc, char **argv)
{
	//SoundAnalyzer* sound = new SoundAnalyzer("D:\\GitHub\\SoundAnalyzer\\09 Avantasia.ogg", 8192);
	OpenGLRenderer::Initialize(argc, argv);
	OpenGLRenderer::Start();
	//delete sound;
	//SoundSpectrum Spectrum;
	//getSpectrum("C:\\Users\\elecomte\\Documents\\Visual Studio 2013\\Projects\\SoundAnalyzer\\09 Avantasia.ogg", 8192, &Spectrum);
	//system("pause");
}
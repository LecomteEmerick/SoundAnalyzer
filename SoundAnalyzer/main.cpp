#include <stdio.h>

#pragma comment (lib, "fmod_vc.lib")

#include "OpenGLRenderer.h"
#include "SoundAnalyzer.h"

int main(int argc, char **argv)
{
	OpenGLRenderer::Initialize(argc, argv);
	OpenGLRenderer::Start();
	//SoundSpectrum Spectrum;
	//getSpectrum("C:\\Users\\elecomte\\Documents\\Visual Studio 2013\\Projects\\SoundAnalyzer\\09 Avantasia.ogg", 8192, &Spectrum);
	//system("pause");
}
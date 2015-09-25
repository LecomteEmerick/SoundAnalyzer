#include <stdio.h>

#pragma comment (lib, "fmod_vc.lib")

//#include "LinkerVS.h"
#include "OpenGLRenderer.h"

int main(int argc, char **argv)
{
	OpenGLRenderer::Initialize(argc, argv);
	OpenGLRenderer::Start();
	//system("pause");
}
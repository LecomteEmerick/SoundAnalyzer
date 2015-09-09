#include "RefSoundLib.h"
//#include <boost/filesystem.hpp> //compiler boost
#include <iostream>

std::vector<SoundAnalyzer> RefSoundLib::SoundLib;

void RefSoundLib::Initialize(char* MyApplicationPath)
{

	//char* path = "D:/GitHub/SoundAnalyzer/SoundLib/";// strcat(MyApplicationPath, "../SoundLib/"); // _CRT_SECURE_NO_WARNINGS.  propiété c++ prépocesseur définition
	
	SoundAnalyzer hello("D:/GitHub/SoundAnalyzer/SoundLib/hello.wav", 8192);
	SoundAnalyzer hello2("D:/GitHub/SoundAnalyzer/SoundLib/hello2.wav", 8192);
	SoundAnalyzer hellov2("D:/GitHub/SoundAnalyzer/SoundLib/hellov2.wav", 8192);

	//RefSoundLib::SoundLib.push_back(hello);
	RefSoundLib::SoundLib.push_back(hello2);
	RefSoundLib::SoundLib.push_back(hellov2);

	/*for (auto i = boost::filesystem::directory_iterator(path); i != boost::filesystem::directory_iterator(); i++)
	{
		if (!boost::filesystem::is_directory(i->path())) //we eliminate directories
		{
			std::cout << i->path().filename().string() << std::endl;
		}
		else
			continue;
	}*/
}

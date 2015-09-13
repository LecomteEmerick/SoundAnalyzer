#include "RefSoundLib.h"
#include "boost/filesystem.hpp"
#include <iostream>

std::vector<std::unique_ptr<SoundAnalyzer>> RefSoundLib::SoundLib;

void RefSoundLib::Initialize(char* MyApplicationPath)
{
	char* path = "D:/GitHub/SoundAnalyzer/SoundLib/";

	for (auto i = boost::filesystem::directory_iterator(path); i != boost::filesystem::directory_iterator(); i++)
	{
		if (!boost::filesystem::is_directory(i->path())) //we eliminate directories
		{
			RefSoundLib::SoundLib.push_back(std::unique_ptr<SoundAnalyzer>(new SoundAnalyzer(i->path().string().c_str(), 8192)));
		}
	}
}

#include "RefSoundLib.h"
#include <iostream>

#include "boost\filesystem.hpp"

std::vector<std::unique_ptr<SoundAnalyzer>> RefSoundLib::SoundLib;

void RefSoundLib::Initialize(char* MyApplicationPath)
{
	std::string path = boost::filesystem::current_path().parent_path().generic_string() + "/SoundLib/";

	for (auto i = boost::filesystem::directory_iterator(path); i != boost::filesystem::directory_iterator(); i++)
	{
		if (!boost::filesystem::is_directory(i->path())) //we eliminate directories
		{
			RefSoundLib::SoundLib.push_back(std::unique_ptr<SoundAnalyzer>(new SoundAnalyzer(i->path().string().c_str(), 8192)));
		}
	}
}

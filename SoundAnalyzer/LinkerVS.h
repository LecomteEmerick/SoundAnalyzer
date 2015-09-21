#pragma once

//chercher a automatiser ça 
//0 false
//1 true
#define DEBUG 0

//VS 2015
#if _MSC_PLATFORM_TOOLSET_ == 140
	//Debug
	#if  DEBUG == 0
		#pragma comment (lib, "boost\\libVS2015\\libboost_system-vc140-mt-gd-1_59.lib")
		#pragma comment (lib, "boost\\libVS2015\\libboost_filesystem-vc140-mt-gd-1_59.lib")
		#pragma comment (lib, "glfw\\libVS2015\\Debug\\glfw3.lib")
		#pragma comment (lib, "SOIL\\lib\\VS2015\\debug\\SOIL.lib")	
	//Release
	#else
		#pragma comment (lib, "boost\\libVS2015\\libboost_system-vc140-mt-1_59.lib")
		#pragma comment (lib, "boost\\libVS2015\\libboost_filesystem-vc140-mt-1_59.lib")
		#pragma comment (lib, "glfw\\libVS2015\\Release\\glfw3.lib")
	#endif
//VS 2013
#else
	//Debug
	#if DEBUG == 0
		#pragma comment (lib, "boost\\libVS2013\\libboost_system-vc120-mt-gd-1_59.lib")
		#pragma comment (lib, "boost\\libVS2013\\libboost_filesystem-vc120-mt-gd-1_59.lib")
		#pragma comment (lib, "glfw\\libVS2013\\Debug\\glfw3.lib")
	#else
		#pragma comment (lib, "boost\\libVS2013\\libboost_system-vc120-mt-1_59.lib")
		#pragma comment (lib, "boost\\libVS2013\\libboost_filesystem-vc120-mt-1_59.lib")
		#pragma comment (lib, "glfw\\libVS2013\\Release\\glfw3.lib")
	#endif
#endif
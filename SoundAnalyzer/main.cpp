#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma comment(lib, "libogg.lib")
#pragma comment(lib, "libvorbis.lib")

#include "vorbis/codec.h"
#include < vorbis/vorbisfile.h >
#include < iostream >
#include < vector >

/*#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif*/

#define BUFFER_SIZE   32768

int main(int argc, char **argv)
{
	std::vector<char> bufferData;
	int endian = 0;
	int bitStream;
	long bytes;
	char array[BUFFER_SIZE];
	FILE *f;
	vorbis_info *pInfo;
	OggVorbis_File oggFile;

	fopen_s(&f,"C:\\Users\\elecomte\\Documents\\Visual Studio 2013\\Projects\\SoundAnalyzer\\09 Avantasia.ogg", "rb");
	ov_open(f, &oggFile, NULL, 0);

	do {
		bytes = ov_read(&oggFile, array, BUFFER_SIZE, endian, 2, 1, &bitStream);
		bufferData.insert(bufferData.end(), array, array + bytes);
		std::cout << bytes << std::endl;
	} while (bytes > 0);
	std::cout << bufferData.size() << std::endl;
	ov_clear(&oggFile);
	system("pause");
}
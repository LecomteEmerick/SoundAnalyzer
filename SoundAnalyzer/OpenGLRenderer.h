#pragma once
#include <vector>
#include <memory>

#include "DrawableItem.h"

class OpenGLRenderer
{
public:
	static std::vector<std::shared_ptr<DrawableItem>> DrawableElements;

	static void			Initialize(int argc, char* argv[]);
	static void			Start();
	static void			Close();
	static void			Restart();

	static void			DisplayFunc();
	static void			MouseFunc(int button, int state, int x, int y);
	static void			KeyboardFunc(unsigned char key, int x, int y);
};


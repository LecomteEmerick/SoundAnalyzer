#pragma once
#include <vector>
#include <memory>

#include "vec3.hpp"
#include "vec4.hpp"
#include "mat4x4.hpp"
#include "gtc\matrix_transform.hpp"

#include "DrawableItem.h"

class OpenGLRenderer
{
public:

	static void			Initialize(int argc, char* argv[]);
	static void			Start();
	static void			RegisterElement(const std::shared_ptr<DrawableItem> item);
	static void			Close();
	//static void			Restart();

	static void			DisplayFunc();
	static void			MouseFunc(int button, int state, int x, int y);
	static void			KeyboardFunc(unsigned char key, int x, int y);
	static void			WheelFunc(int button, int dir, int x, int y);
	static void			MotionFunc(int x, int y);
private:
	static std::vector<const std::shared_ptr<DrawableItem>> DrawableElements;
	static int			argcSave;
	static char**		argvSave;
	static float		depth;
	static float		xOffset;
	static float		zOffset;
	static float		xAngle;
	static float		yAngle;
	static float		speed;
	static bool			mouseDown;
	static float		previousMousePosX;
	static float		previousMousePosY;
	static int			windowWidth;
	static int			windowHeight;
	static float		xAngleUnit;
	static float		yAngleUnit;
};


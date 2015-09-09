#pragma once
#include <vector>
#include <map>
#include <memory>

#include "vec3.hpp"
#include "vec4.hpp"
#include "mat4x4.hpp"
#include "gtc\matrix_transform.hpp"

#include "DrawableItem.h"
#include "Camera.h"
#include "Time.h"
#include "MicRecorder.h"
#include "RefSoundLib.h"

class OpenGLRenderer
{
public:
	static void			Initialize(int argc, char* argv[]);
	static void			Start();
	static void			EnterMainLoop();
	static void			ExitMainLoop();
	static void			RegisterElement(std::shared_ptr<DrawableItem> item);
	static void			Close();
private:
	static void			DisplayFunc();
	static void			MouseFunc(GLFWwindow* window, int button, int action, int mods);
	static void			MotionFunc(GLFWwindow* window, double xpos, double ypos);
	static void			KeyboardFunc(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void			UpdateKeyboard();

	static std::vector<std::shared_ptr<DrawableItem>> DrawableElements;
	static bool			ContinueMainLoop;

	static GLFWwindow*	window;
	static int			windowWidth;
	static int			windowHeight;

	static Camera		MainCamera;
	static float		CameraSpeed;
	static float		CameraSensitivity;
	static float		Depth;

	static MicRecorder	micRecorder;

	static RefSoundLib	SoundLib;

	static bool			mouseDown;
	static double		previousMousePosX;
	static double		previousMousePosY;

	static std::map<int, bool> Keys;
};


#include "OpenGLRenderer.h"
#include "Map.h"
#include "Landmark.h"

std::vector<const std::shared_ptr<DrawableItem>> OpenGLRenderer::DrawableElements;

//MainLoop
bool OpenGLRenderer::ContinueMainLoop;

//Window
GLFWwindow*	OpenGLRenderer::window;
int	OpenGLRenderer::windowWidth = 800;
int	OpenGLRenderer::windowHeight = 600;

//Camera
Camera OpenGLRenderer::MainCamera;
float OpenGLRenderer::CameraSpeed;
float OpenGLRenderer::CameraSensitivity;
float OpenGLRenderer::Depth;

//Mouse
bool OpenGLRenderer::mouseDown;
double OpenGLRenderer::previousMousePosX;
double OpenGLRenderer::previousMousePosY;

//keyboard
std::map<int, bool> OpenGLRenderer::Keys;

void OpenGLRenderer::Initialize(int argc, char* argv[])
{
	OpenGLRenderer::MainCamera = Camera();
	OpenGLRenderer::Depth = 10.0f;
	OpenGLRenderer::MainCamera.setPosition(glm::vec3(0.0f, 0.0f, OpenGLRenderer::Depth));
	OpenGLRenderer::MainCamera.lookAt(glm::vec3(0.0f, 0.0f, 0.0f));
	OpenGLRenderer::CameraSpeed = 1.0f;
	OpenGLRenderer::CameraSensitivity = 5.0f;

	glfwInit();

	OpenGLRenderer::window = glfwCreateWindow(OpenGLRenderer::windowWidth, OpenGLRenderer::windowHeight, "Sound Analyzer", NULL, NULL);
	glfwMakeContextCurrent(OpenGLRenderer::window);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	
	glfwSetKeyCallback(window, KeyboardFunc);
	glfwSetMouseButtonCallback(window, MouseFunc);
	glfwSetCursorPosCallback(window, MotionFunc);
}

void OpenGLRenderer::Start()
{
	DrawableElements.clear();

	GLenum error = glewInit();
	if (error != GL_NO_ERROR) {
		// TODO
	}

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	OpenGLRenderer::RegisterElement(std::shared_ptr<DrawableItem>(new Map()));
	OpenGLRenderer::RegisterElement(std::shared_ptr<DrawableItem>(new Landmark()));

	Time::Start();

	OpenGLRenderer::EnterMainLoop();
}

void OpenGLRenderer::EnterMainLoop()
{
	OpenGLRenderer::ContinueMainLoop = true;
	while (!glfwWindowShouldClose(OpenGLRenderer::window) && OpenGLRenderer::ContinueMainLoop)
	{
		OpenGLRenderer::DisplayFunc();
		glfwSwapBuffers(window);
		glfwPollEvents();
		OpenGLRenderer::UpdateKeyboard();
	}
	glfwTerminate();
}

void OpenGLRenderer::ExitMainLoop()
{
	OpenGLRenderer::ContinueMainLoop = false;
}

void OpenGLRenderer::RegisterElement(const std::shared_ptr<DrawableItem> item)
{
	OpenGLRenderer::DrawableElements.push_back(item);
}

void OpenGLRenderer::Close()
{
	OpenGLRenderer::ExitMainLoop();
}

void OpenGLRenderer::DisplayFunc()
{
	int widthWindow;
	int heightWindow;

	Time::Update();

	glfwGetWindowSize(window, &widthWindow, &heightWindow);

	glViewport(0, 0, widthWindow, heightWindow);
	glClearColor(0.f, 0.f, 0.0f, 1.0f);
	glClearDepth(1.F);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 Projection = MainCamera.projection();
	glm::mat4 World = MainCamera.view();
	glm::mat4 View = glm::mat4(1.0f);


	for (auto element : OpenGLRenderer::DrawableElements)
	{
		element.get()->Draw(Projection,View,World,0);
	}
}

void OpenGLRenderer::MouseFunc(GLFWwindow* window, int button, int state, int mods)
{
	OpenGLRenderer::mouseDown = state != GLFW_RELEASE;
	if (OpenGLRenderer::mouseDown)
	{
		glfwGetCursorPos(window, &OpenGLRenderer::previousMousePosX, &OpenGLRenderer::previousMousePosY);
	}
}

void OpenGLRenderer::MotionFunc(GLFWwindow* window, double x, double y)
{
	if (OpenGLRenderer::mouseDown)
	{
		float xAngleUnit = (float)((x - OpenGLRenderer::previousMousePosX) * Time::GetSecondElapsed() * CameraSensitivity);
		float yAngleUnit = (float)((y - OpenGLRenderer::previousMousePosY) * Time::GetSecondElapsed() * CameraSensitivity);
		OpenGLRenderer::MainCamera.offsetOrientation(yAngleUnit, xAngleUnit);
		OpenGLRenderer::previousMousePosX = x;
		OpenGLRenderer::previousMousePosY = y;
	}
}

void OpenGLRenderer::KeyboardFunc(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	OpenGLRenderer::Keys[key] = action != GLFW_RELEASE;
}

void OpenGLRenderer::UpdateKeyboard()
{
	for (std::pair<int,bool> keyState : OpenGLRenderer::Keys)
	{
		if (keyState.second)
		{
			switch (keyState.first)
			{
				case(GLFW_KEY_ESCAPE):
					OpenGLRenderer::Close();
					break;
				case(GLFW_KEY_W):
					MainCamera.offsetPosition((float)Time::GetSecondElapsed() * CameraSpeed * MainCamera.forward());
					break;
				case(GLFW_KEY_S):
					MainCamera.offsetPosition((float)Time::GetSecondElapsed() * CameraSpeed * -MainCamera.forward());
					break;
				case(GLFW_KEY_A):
					MainCamera.offsetPosition((float)Time::GetSecondElapsed() * CameraSpeed * -MainCamera.right());
					break;
				case(GLFW_KEY_D):
					MainCamera.offsetPosition((float)Time::GetSecondElapsed() * CameraSpeed * MainCamera.right());
					break;
				case(GLFW_KEY_SPACE):
					MainCamera.offsetPosition((float)Time::GetSecondElapsed() * CameraSpeed * MainCamera.up());
					break;
				case(GLFW_KEY_LEFT_SHIFT) :
					MainCamera.offsetPosition((float)Time::GetSecondElapsed() * CameraSpeed * -MainCamera.up());
					break;
			}
		}
	}
}
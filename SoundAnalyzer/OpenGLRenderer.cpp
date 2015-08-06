#include "OpenGLRenderer.h"
#include "Map.h"
#include "Landmark.h"

std::vector<const std::shared_ptr<DrawableItem>> OpenGLRenderer::DrawableElements;
float OpenGLRenderer::depth;
float OpenGLRenderer::xOffset;
float OpenGLRenderer::zOffset;
float OpenGLRenderer::xAngle;
float OpenGLRenderer::yAngle;
float OpenGLRenderer::speed;
int OpenGLRenderer::argcSave;
char** OpenGLRenderer::argvSave;
bool OpenGLRenderer::mouseDown;
float OpenGLRenderer::previousMousePosX;
float OpenGLRenderer::previousMousePosY;

float OpenGLRenderer::xAngleUnit;
float OpenGLRenderer::yAngleUnit;

int	OpenGLRenderer::windowWidth=800;
int	OpenGLRenderer::windowHeight=600;

void OpenGLRenderer::Initialize(int argc, char* argv[])
{
	OpenGLRenderer::argcSave = argc;
	OpenGLRenderer::argvSave = argv;

	OpenGLRenderer::depth = -30.0f;
	OpenGLRenderer::xOffset = 0.0f;
	OpenGLRenderer::zOffset = 0.0f;
	OpenGLRenderer::xAngle = 0.0f;
	OpenGLRenderer::yAngle = 0.0f;
	OpenGLRenderer::speed = 0.5f;

	OpenGLRenderer::xAngleUnit = 360.0f / windowWidth;
	OpenGLRenderer::yAngleUnit = 360.0f / windowHeight;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("Sound Analyzer");

#ifdef FREEGLUT
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
		GLUT_ACTION_GLUTMAINLOOP_RETURNS);
#endif
	glutDisplayFunc(DisplayFunc);
	glutMouseFunc(MouseFunc);
	glutKeyboardFunc(KeyboardFunc);
	glutMouseWheelFunc(WheelFunc);
	glutMotionFunc(MotionFunc);
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

	//OpenGLRenderer::RegisterElement(std::shared_ptr<DrawableItem>(new Map()));
	OpenGLRenderer::RegisterElement(std::shared_ptr<DrawableItem>(new Landmark()));
	glutMainLoop();
}

void OpenGLRenderer::RegisterElement(const std::shared_ptr<DrawableItem> item)
{
	OpenGLRenderer::DrawableElements.push_back(item);
}

void OpenGLRenderer::Close()
{
	glutLeaveMainLoop();
}

/*void OpenGLRenderer::Restart()
{
	OpenGLRenderer::Close();
	OpenGLRenderer::Initialize(OpenGLRenderer::argcSave, OpenGLRenderer::argvSave);
	OpenGLRenderer::Start();
}*/

void OpenGLRenderer::DisplayFunc()
{
	glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	glClearColor(0.f, 0.f, 0.0f, 1.0f);
	glClearDepth(1.F);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float w = (float)glutGet(GLUT_WINDOW_WIDTH);
	float h = (float)glutGet(GLUT_WINDOW_HEIGHT);

	glm::mat4 Projection = glm::perspective(45.0f, w / h, 0.1f, 1000.f);

	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, OpenGLRenderer::depth));

	glm::mat4 World = glm::mat4(1.0f);
	World = glm::translate(World, glm::vec3(OpenGLRenderer::xOffset, 0.0f, OpenGLRenderer::zOffset));
	World = glm::rotate(World, OpenGLRenderer::yAngle, glm::vec3(0.0f, 1.0f, 0.0f));
	World = glm::rotate(World, OpenGLRenderer::xAngle, glm::vec3(1.0f, 0.0f, 0.0f));


	for (auto element : OpenGLRenderer::DrawableElements)
	{
		element.get()->Draw(Projection,View,World,0);
	}

	glutSwapBuffers();
}

void OpenGLRenderer::MouseFunc(int button, int state, int x, int y)
{
	mouseDown = state == GLUT_DOWN;
	if (mouseDown)
	{
		OpenGLRenderer::previousMousePosX = x;
		OpenGLRenderer::previousMousePosY = y;
	}
}

void OpenGLRenderer::KeyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27 :
			OpenGLRenderer::Close();
			break;
		case 'z':
			OpenGLRenderer::zOffset += OpenGLRenderer::speed;
			break;
		case 's':
			OpenGLRenderer::zOffset -= OpenGLRenderer::speed;
			break;
		case 'q':
			OpenGLRenderer::xOffset -= OpenGLRenderer::speed;
			break;
		case 'd':
			OpenGLRenderer::xOffset += OpenGLRenderer::speed;
			break;
	}
	glutPostRedisplay();
}

void OpenGLRenderer::MotionFunc(int x, int y)
{
	if (OpenGLRenderer::mouseDown)
	{
		if (OpenGLRenderer::previousMousePosY != y)
			OpenGLRenderer::xAngle += (y - OpenGLRenderer::previousMousePosY) * yAngleUnit / 10;//OpenGLRenderer::previousMousePosY < y ? -yAngleUnit : yAngleUnit;
		if (OpenGLRenderer::previousMousePosX != x)
			OpenGLRenderer::yAngle += (x - OpenGLRenderer::previousMousePosX) * xAngleUnit / 10;//OpenGLRenderer::previousMousePosX < x ? -xAngleUnit : xAngleUnit;
		OpenGLRenderer::previousMousePosY = y;
		OpenGLRenderer::previousMousePosX = x;
		glutPostRedisplay();
	}
}

void OpenGLRenderer::WheelFunc(int button, int dir, int x, int y)
{
	//OpenGLRenderer::depth += dir * 1.5f;
	//glutPostRedisplay();
}
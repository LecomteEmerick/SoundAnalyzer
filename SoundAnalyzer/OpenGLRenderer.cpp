#include "OpenGLRenderer.h"

static std::vector<std::shared_ptr<DrawableItem>> DrawableElements;

void OpenGLRenderer::Initialize(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Sound Analyzer");

#ifdef FREEGLUT
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
		GLUT_ACTION_GLUTMAINLOOP_RETURNS);
#endif
	glutDisplayFunc(DisplayFunc);
	glutMouseFunc(MouseFunc);
	glutKeyboardFunc(KeyboardFunc);

	//glutIdleFunc(_idleCallback);
	//glutMouseWheelFunc(_mouseWheelCallback);
	//glutMotionFunc(_motionCallback);
}

void OpenGLRenderer::DisplayFunc()
{

}

void OpenGLRenderer::MouseFunc(int button, int state, int x, int y)
{

}

void OpenGLRenderer::KeyboardFunc(unsigned char key, int x, int y)
{

}
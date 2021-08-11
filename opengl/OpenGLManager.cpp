#include "OpenGLManager.h"
#include "ErrorManager.h"

#include <GL/glew.h>

#include <string>

OpenGLManager::OpenGLManager()
{
}


OpenGLManager::~OpenGLManager()
{
}

int OpenGLManager::start_up()
{ 
	glewExperimental = GL_TRUE;
	const GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		const GLubyte *errString = glewGetErrorString(err);
		std::cout << err << std::endl;
		Singleton<ErrorManager>::get_instance().push_fatal(" " + err, "In OpenGLManager::start_up()");
	}

	glFrontFace(GL_CCW);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_LESS);

	return 1;
}
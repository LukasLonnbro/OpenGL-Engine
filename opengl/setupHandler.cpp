#include "setupHandler.h"
#include "errorhandler.h"
#include "window.h"

#include <SDL.h>
#include <gl/glew.h>

#include <iostream>
#include <string>

int setupHandler::contextVersionMax = 0;
int setupHandler::contextVersionMin = 0;
int setupHandler::doublebuffer = 0;

void setupHandler::config()
{
	//Read from file and set variables.	
	contextVersionMax	= 4;
	contextVersionMin	= 4;
	doublebuffer		= 1;
}

void setupHandler::setupSDL()
{
	//READ SETTINGS FROM CONFIG FILE.
	config();

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,	contextVersionMax);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,	contextVersionMin);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,			doublebuffer);

	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,				24);

	SDL_GL_SetSwapInterval(0); // Make sure graphic card allows vsync to be disabled if you want to turn vsync off.

	//INIT SDL STUFF
	//Find way to decide what features to be initalized.
	//For now implemented in the various classes related to the init. (For an example window has SDL_INIT_VIDEO).
	//Write program to do initial run over code and setup config file and what parts of SDL to init. 
}

void setupHandler::setupGL()
{
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		const GLubyte *errString = glewGetErrorString(err);
		errorhandler::addError(errString, FATALERROR, "(CLASS: SETUPHANDLER) Glew initalization failed: ");
		std::cout << "stuff.";
	}

	glFrontFace(GL_CCW);
}

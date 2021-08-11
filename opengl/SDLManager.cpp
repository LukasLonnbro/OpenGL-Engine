#include "SDLManager.h"

#include "constants.h"

#include <SDL.h>

SDLManager::SDLManager()
{
}

SDLManager::~SDLManager()
{
}

//Eventually this will read variables from config files.
int SDLManager::config()
{
	contextVersionMax = 4;
	contextVersionMin = 4;
	doublebuffer = 1;

	return 1;
}

int SDLManager::start_up()
{
	//READ SETTINGS FROM CONFIG FILE.
	config();

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, contextVersionMax);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, contextVersionMin);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, doublebuffer);

	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	SDL_GL_SetSwapInterval(0); // Make sure graphic card allows vsync to be disabled if you want to turn vsync off.

	SDL_Init(SDL_INIT_EVERYTHING);
	
	create_window();

	return 1; //Might be unnessecary but should prolly return an error code.
}

int SDLManager::create_window() 
{
	m_Window = new Window("maybe", (int)info::WIDTH(), (int)info::HEIGHT());
	return 1;
}
#include "window.h"
#include <iostream>

window::window(const char* titl, int w, int h)
{
	title = titl;
	width = w;
	height = h;
	if (!SDL_WasInit(SDL_INIT_VIDEO))
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0) 
		{
			//ERROR HANDLING - FATAL
			//errorhandler::addError(SDL_GetError(), FATALERROR);
		} 
	}
	createWindow();
}
window::~window()
{
	//ERROR HANDLING - possible memory leakage.
	SDL_GL_DeleteContext(context_holder);
	SDL_DestroyWindow(window_holder);
}

void window::createWindow()
{
	window_holder = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

	if (!window_holder)
	{
		//errorhandler::addError(SDL_GetError(), FATALERROR, "(CLASS: WINDOW) Window Creation failed: ");
	}

	context_holder = SDL_GL_CreateContext(window_holder);

	if (!context_holder)
	{
		//errorhandler::addError(SDL_GetError(), FATALERROR, "(CLASS: WINDOW) Context creation failed: ");
	}
}


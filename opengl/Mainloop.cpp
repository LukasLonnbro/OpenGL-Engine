#pragma once

#include "Mainloop.h"
#include "gameController.h"

#include <iostream>
#include <string>

#include <GL/glew.h>
#include <SDL.h>
 
#include "Modules.h"


Mainloop::Mainloop()
{
}


Mainloop::~Mainloop()
{
}

void Mainloop::init() 
{
}

void Mainloop::run() 
{
	SDL_GL_SetSwapInterval(0);

	// OI YA CUNT, order is hella important here. Carfule.
	Singleton<SDLManager>::get_instance().start_up();
	Singleton<OpenGLManager>::get_instance().start_up();

	gameController controller(Singleton<SDLManager>::get_instance().get_window());
	controller.run();
}
#include "Mainloop.h"

#include <iostream>
#include <string>

#include <GL/glew.h>
#include <SDL.h>

#include "window.h"
#include "setupHandler.h"
#include "gameController.h"
#include "constants.h"

#include "File.h"
#include "Log_path.h"
#include "Shader_path.h"
#include "Model_path.h"

#include "ErrorManager.h"


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

	setupHandler::setupSDL();
	SDL_Init(SDL_INIT_EVERYTHING);
	window myWindow("maybe", (int)info::WIDTH(), (int)info::HEIGHT());

	setupHandler::setupGL();

	gameController controller(&myWindow);
	controller.run();
}
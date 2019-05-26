#include <iostream>

#include <GL/glew.h>
#include <SDL.h>

#include "window.h"
#include "setupHandler.h"
#include "gameController.h"
#include "constants.h"

#undef main

#define STATIC_ALLOC

int main() {
	std::cout << "Hello world\n";
	
	SDL_GL_SetSwapInterval(0);
	
	setupHandler::setupSDL();
	SDL_Init(SDL_INIT_EVERYTHING);
	window myWindow("maybe", (int)info::WIDTH(), (int)info::HEIGHT());

	setupHandler::setupGL();

	gameController controller(&myWindow);
	controller.run();
}
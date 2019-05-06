#include <iostream>

#include <GL/glew.h>
#include <SDL.h>

#include "window.h"
#include "setupHandler.h"
#include "app.h"
#include "info.h"

#undef main

int main() {
	std::cout << "Hello world\n";
	
	//errorHandler()
	//Collects errors and appends them to error file. Keeps recent errors in list (has to be cleared manually). 

	//SETUP() --> config(), errorHandler()

	//window mainWindow(const char* title, const int windowWidth, const int windowHeight);

	//shader() --> 

	//entity player1(const char* filepath) -->
	//shader(), VB(void data, unsigned float size), 
	//VBLayout(), VA(vb, vblayout), EB(unsigned int indices, (unsigned float size)?), errorHandler();
	//ASSIMP

	//UI(entity listOfEntitites), entity represented as void --> FB(void va), errorHandler()

	//Renderer() --> Serves as a connection between app and entities. 

	//InputHandler()

	//App(int windowWidth, int windowHeight, title) --> Wrapper for all previously mentioned classes.
	//Contains the gameloop. 
	//On successful setup, retrieves an error handler and starts app. Is responisble for mintanance of app.
	//Upon fatal error, shuts down app. Upon minor error, informs dev/user.

	//Setup typedefs so that the library can work with other langugages. 
	//(For an example in bufferlayout unsigned char is set to represent normalization because it allows you to directly pass GL_FALSE)
	
	SDL_GL_SetSwapInterval(0);
	
	setupHandler::setupSDL();
	SDL_Init(SDL_INIT_EVERYTHING);
	window myWindow("maybe", (int)info::WIDTH(), (int)info::HEIGHT());

	setupHandler::setupGL();

	gameController controller(&myWindow);
	controller.run();
}
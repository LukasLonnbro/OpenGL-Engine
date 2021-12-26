#pragma once

#include "Mainloop.h"

#include "Modules.h"
#include "USER_IO.h"
#include "resourceManager.h"

#include <iostream>
#include <string>

#include <GL/glew.h>
#include <SDL.h>


Mainloop::Mainloop()
{
}


Mainloop::~Mainloop()
{
}

void Mainloop::init() 
{
	SDL_GL_SetSwapInterval(0);

	// OI YA CUNT, order is hella important here. Careful.
	// NOTE : In OGRE singletons are explicitly newed at each creation to make sure initiation happens 
	//		in the correct order. The template should take care of that but might cause issues in the future?
	Singleton<SDLManager>::get_instance().start_up();
	Singleton<OpenGLManager>::get_instance().start_up();


	m_Window = Singleton<SDLManager>::get_instance().get_window();
}

void Mainloop::run() 
{
	init();

	ResourceManager data;
	data.loadEntities();

	m_Renderer.setLights(data.getLights());
	m_Renderer.prep(data.getEntities());

	int GAMETICKS = 0;
	int curTick = 0;
	while (true) {
		curTick = SDL_GetTicks();
		if (curTick - lastTick >= (1000 / 144)) { //update 144 times per second
			lastTick = curTick;
			GAMETICKS++;

			USER_IO::update();

			m_Renderer.render();

			if (GAMETICKS % 144 == 0) {
				system("cls");
				std::cout << "FPS: " << frames << std::endl;
				frames = 0;
			}
			frames++;
			SDL_GL_SwapWindow(m_Window->getWindowHolder());
		}
	}
}
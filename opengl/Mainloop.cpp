#pragma once

#include "Mainloop.h"

#include "Modules.h"
#include "USER_IO.h"
#include "resourceManager.h"
#include "Timeline_manager.h"

#include <iostream>
#include <string>

#include <GL/glew.h>
#include <SDL.h>


Mainloop::Mainloop(): last_tick(0)
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
	
	Singleton<Timeline_manager>::get_instance().start_up();


	m_Window = Singleton<SDLManager>::get_instance().get_window();
}

//Should maybe be moved into renderer?
void Mainloop::frame_count()
{	
	if (Singleton<Timeline_manager>::get_instance().get_tick() - last_tick >= 1000) { 
		frame_count(); 
		last_tick = Singleton<Timeline_manager>::get_instance().get_tick();
		std::cout << "FPS: " << frames << std::endl;
		frames = 0;
	}
	
	frames++;
}

void Mainloop::run() 
{
	init();

	//Residue from old engine thought process. Will be removed. 
	//;;
	ResourceManager data;
	data.loadEntities();

	m_Renderer.setLights(data.getLights());
	m_Renderer.prep(data.getEntities());
	//;;

	while (true) {			
		Singleton<Timeline_manager>::get_instance().update();

		m_Renderer.render();

		SDL_GL_SwapWindow(m_Window->getWindowHolder());
		
		frame_count();
	}
}
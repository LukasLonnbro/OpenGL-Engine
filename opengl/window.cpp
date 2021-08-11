#include "window.h"

#include "ErrorManager.h"

#include <iostream>

//TODO : Currently relys on SDL, would be nice to not, but that's a huge change that isn't needed right now.

Window::Window(std::string title, int w, int h)
{
	m_Title = title;
	width = w;
	height = h;

	create_window();
}
Window::~Window()
{
	//ERROR HANDLING - possible memory leakage.
	SDL_GL_DeleteContext(context_holder);
	SDL_DestroyWindow(window_holder);
}

void Window::create_window()
{
	window_holder = SDL_CreateWindow(m_Title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

	if (!window_holder)
	{
		Singleton<ErrorManager>::get_instance().push_fatal(SDL_GetError(), "Class: window.cpp in create_window()");
	}

	context_holder = SDL_GL_CreateContext(window_holder);

	if (!context_holder)
	{
		ErrorManager::get_instance().push_fatal(SDL_GetError(), "Class: window.cpp");
	}
}


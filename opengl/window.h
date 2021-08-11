#pragma once

#include <string>

#include <SDL.h>

//SETS UP SDL OPENGL WINDOW.
//NOTE TO SELF: Requires proper SDL_OPENGL flags to be already set up. 
class Window
{
public:
	Window(std::string title, int w, int h);
	~Window();

	inline SDL_Window* getWindowHolder() const { return window_holder; }
	void create_window();

private: 
	SDL_Window * window_holder;
	SDL_GLContext context_holder;

	std::string m_Title;
	int width;
	int height;
};


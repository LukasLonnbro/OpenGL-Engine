#pragma once

#include <string>

#include <SDL.h>

//SETS UP SDL OPENGL WINDOW.
//NOTE TO SELF: Requires proper SDL_OPENGL flags to be already set up. 
class window
{
public:
	window(const char* titl, int w, int h);
	~window();

	inline SDL_Window* getWindowHolder() const { return window_holder; }
	void createWindow();

private: 
	SDL_Window * window_holder;
	SDL_GLContext context_holder;

	std::string title;
	int width;
	int height;
};


#include "eventHandler.h"

#include <SDL/SDL.h>

eventBools eventHandler::events;

eventHandler::eventHandler()
{
}
eventHandler::~eventHandler()
{
}

void eventHandler::setMousePos(int x, int y)
{
	SDL_WarpMouseInWindow(SDL_GetMouseFocus(), x, y);
}

void eventHandler::update()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) 
	{
		switch (evnt.type) 
		{
		case SDL_KEYDOWN:
			switch (evnt.key.keysym.sym)
			{
			case SDLK_w:
				events.w = true;
				break;
			case SDLK_s:
				events.s = true;
				break;
			case SDLK_a:
				events.a = true;
				break;
			case SDLK_d:
				events.d = true;
				break;
			case SDLK_q:
				events.q = true;
				break;
			case SDLK_SPACE:
				events.space = true;
				break;
			case SDLK_LSHIFT:
				events.shift = true;
				break;
			}
			break;
		case SDL_KEYUP:
			switch (evnt.key.keysym.sym)
			{
			case SDLK_w:
				events.w = false;
				break;
			case SDLK_s:
				events.s = false;
				break;
			case SDLK_a:
				events.a = false;
				break;
			case SDLK_d:
				events.d = false;
				break;
			case SDLK_q:
				events.q = false;
				break;
			case SDLK_SPACE:
				events.space = false;
				break;
			case SDLK_LSHIFT:
				events.shift = false;
				break;
			}
			break;
		}
	}

	SDL_GetMouseState(&events.mouseX, &events.mouseY);
}
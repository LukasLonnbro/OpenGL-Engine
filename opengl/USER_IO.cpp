#include "USER_IO.h"

#include <SDL.h>

// Messy, fix naming convention.
Keyboard USER_IO::m_Keyboard;

USER_IO::USER_IO()
{
}
USER_IO::~USER_IO()
{
}

void USER_IO::setMousePos(int x, int y)
{
	SDL_WarpMouseInWindow(SDL_GetMouseFocus(), x, y);
}

void USER_IO::update()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) 
	{
		switch (evnt.type) 
		{
		case SDL_KEYDOWN:
			switch (evnt.key.keysym.sym)
			{
			case SDLK_a: m_Keyboard.a = true; break;
			case SDLK_d: m_Keyboard.d = true; break;
			case SDLK_e: m_Keyboard.e = true; break;
			case SDLK_f: m_Keyboard.f = true; break; 
			case SDLK_q: m_Keyboard.q = true; break;
			case SDLK_r: m_Keyboard.r = true; break;
			case SDLK_s: m_Keyboard.s = true; break;
			case SDLK_w: m_Keyboard.w = true; break;
			case SDLK_x: m_Keyboard.x = true; break;
			case SDLK_SPACE: m_Keyboard.space = true; break;
			case SDLK_LSHIFT: m_Keyboard.shift = true; break;
			}
			break;
		case SDL_KEYUP:
			switch (evnt.key.keysym.sym)
			{
			case SDLK_a: m_Keyboard.a = false; break;
			case SDLK_d: m_Keyboard.d = false; break;
			case SDLK_e: m_Keyboard.e = false; break;
			case SDLK_f: m_Keyboard.f = false; break;
			case SDLK_q: m_Keyboard.q = false; break;
			case SDLK_r: m_Keyboard.r = false; break;
			case SDLK_s: m_Keyboard.s = false; break;
			case SDLK_w: m_Keyboard.w = false; break;
			case SDLK_x: m_Keyboard.x = false; break;
			case SDLK_SPACE: m_Keyboard.space = false; break;
			case SDLK_LSHIFT: m_Keyboard.shift = false; break;
			}
			break;
		}
	}

	SDL_GetMouseState(&m_Keyboard.mouseX, &m_Keyboard.mouseY);
}
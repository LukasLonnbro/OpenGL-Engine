#pragma once

#include "renderer.h"
#include "window.h"

class gameController
{
public:
	gameController(const Window * aWindow);
	~gameController();

	int update();
	void run();

private: 
	const Window * m_Window;
	renderer m_Renderer;

	int lastTick;
	int frameTick;
	int frames;
};


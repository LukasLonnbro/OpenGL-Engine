#pragma once

#include "renderer.h"
#include "window.h"

class Mainloop
{
public:
	Mainloop();
	~Mainloop();

	void run();
private:
	void init();

	const Window * m_Window;
	renderer m_Renderer;

	int lastTick;
	int frameTick;
	int frames;
};


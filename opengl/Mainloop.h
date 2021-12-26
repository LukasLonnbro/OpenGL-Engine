#pragma once

#include "renderer.h"
#include "window.h"

class Mainloop
{
public:
	Mainloop();
	~Mainloop();

	void run();

	void frame_count();
private:
	void init();

	const Window * m_Window;
	renderer m_Renderer;

	int last_tick;
	int frames;
};


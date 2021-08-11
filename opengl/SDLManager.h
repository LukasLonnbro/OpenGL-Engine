#pragma once

#include "Singleton.h"
#include "window.h"
#include "constants.h"

// Manages all things SDL, essentially a wrapper.

// TODO : Read config variables from file.
// TODO : Window currently heap allocated as a pointer. Treat with care.

class SDLManager : public Singleton<SDLManager>
{
	friend class Singleton<SDLManager>;

public:
	int start_up();
	inline const Window* get_window() const { return m_Window; }

private:
	int config();
	int create_window();

	int contextVersionMax;
	int contextVersionMin;
	int doublebuffer;

	Window* m_Window;


protected:
	SDLManager();
	~SDLManager();
};


#pragma once

#include "Singleton.h"

#include <SDL.h>

// This is gonna be clumpsy for now. This is really only relative for debugging for now
// so gonna do something simple. Slowmotion and freezing time with the press of a button.
// Debating wether to add an update function or just to do it in the "get_update_interval".
// For now I'm going with the simplest. 
class Timeline_manager : public Singleton<Timeline_manager>
{
	friend class Singleton<Timeline_manager>;

public:
	inline int get_tick() { return SDL_GetTicks(); }

	void start_up() {}
	void update();
	int get_update_interval();

private:
	int last_tick;
	int interval;

	bool toggle;

protected:
	Timeline_manager();
	~Timeline_manager();
};


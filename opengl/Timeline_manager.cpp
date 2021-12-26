#include "Timeline_manager.h"

#include "USER_IO.h"
#include <iostream>

Timeline_manager::Timeline_manager() : toggle(false), interval(1000/144), last_tick(0)
{
}


Timeline_manager::~Timeline_manager()
{
}

int Timeline_manager::get_update_interval() 
{
	
	if (USER_IO::get_keyboard()->f) {
		toggle = !toggle;
	}

	if (toggle) { 
		interval = 1000 / 20; 
	} else { 
		interval = 1000 / 144; 
	}
	
	return interval;
}

void Timeline_manager::update()
{
	int current_tick = get_tick();
	if (current_tick - last_tick >= get_update_interval()) {
		last_tick = current_tick;
		USER_IO::update();
	}
}
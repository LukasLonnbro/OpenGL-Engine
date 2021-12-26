#include "Timeline_manager.h"

#include "USER_IO.h"

Timeline_manager::Timeline_manager() : toggle(false), interval(1000/144)
{
}


Timeline_manager::~Timeline_manager()
{
}

int Timeline_manager::get_update_interval() {
	
	if (USER_IO::get_keyboard()->f)

	return interval;
}
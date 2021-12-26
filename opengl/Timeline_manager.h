#pragma once

// This is gonna be clumpsy for now. This is really only relative for debugging for now
// so gonna do something simple. Slowmotion and freezing time with the press of a button.
// Debating wether to add an update function or just to do it in the "get_update_interval".
// For now I'm going with the simplest. 
class Timeline_manager
{
public:
	Timeline_manager();
	~Timeline_manager();

	int get_update_interval();

private:
	int interval;
	bool toggle;
};


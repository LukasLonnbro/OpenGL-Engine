#pragma once
#include "constants.h"

#define evt eventHandler::getEvents()

class eventHandler
{
public:
	eventHandler();
	~eventHandler();

	static void update();

	const inline static eventBools * getEvents() { return &events; };

	static void setMousePos(int xPos, int yPos);

private:
	static eventBools events;
};



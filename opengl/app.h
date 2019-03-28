#pragma once

#include "errorhandler.h"
#include "window.h"
#include "gameController.h"

class app
{
public:
	//app(window * aWindow);
	//~app();

	void run();
private: 
	void apploop();

	gameController mainController;
};


#include "app.h"

#include "window.h"
#include "eventHandler.h"

#include <string>
#include <iostream>

#include <gl/glew.h>

/*app::app(window aWindow) : mainController(aWindow)
{
}
app::~app()
{
}*/

void app::run()
{
	mainController.run();
}

void app::apploop() 
{
	/*bool run = true;
	while (run)
	{
		//Collect errors.
		auto error = errorhandler::getErrorImpact();
		if (error == FATALERROR)
		{
			auto errorList = errorhandler::getErrors();

			std::cout << "Fatal error encountered\n";
			for (unsigned int i = 0; i < errorList.size(); i++)
			{
				std::cout << i << ": ";
				std::cout << reinterpret_cast<const char*>(errorList[i]);
				if ((i+1) % 2 == 0) { std::cout << "\n"; }
			}

			//shutdown

			std::string a;
			getline(std::cin, a);
		}
		else if (error == NONFATALERROR)
		{
			auto errorList = errorhandler::getErrors();

			std::cout << "Minor error encountered: ";
			for (unsigned int i = 0; i < errorList.size(); i++)
			{
				std::cout << i<<": " << std::endl;
				std::cout << reinterpret_cast<const char*>(errorList[i]);
				if (i % 2 == 0) { std::cout << "\n"; }
			}

			std::string a;
			getline(std::cin, a);
		}


		// Update user input:
		eventHandler::update();

		// Run app.
		// If the gameController returns less than 0 on an update, it's a request for app shutdown.
		if (mainController.update() < 1)
		{
			//shutdown app
			run = false;

		}
		errorhandler::clear();

		//system("cls");

	}*/

}

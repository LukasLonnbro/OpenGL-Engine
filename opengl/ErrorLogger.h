#pragma once

#include "Logger.h"

#include <string>

/*
Logger at logs/Errorlog.txt

(For usage see Logger.h)

TODO : Add clear function.
TODO : Initiate a new log every time it starts. Or at least give the option to.

TODO : Graphical interface?
*/

class ErrorLogger : Logger
{
public:
	ErrorLogger();
	~ErrorLogger();

	void push_fatal(std::string error, std::string function_info);
	void push_error(std::string error, std::string function_info);
	void push_warning(std::string error, std::string function_info);

private:
};


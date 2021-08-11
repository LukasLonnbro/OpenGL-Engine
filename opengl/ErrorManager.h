#pragma once

#include "Singleton.h"
#include "Log_path.h"
#include "File.h"

#include <string>

/*
Logger at logs/Errorlog.txt

(For usage see Logger.h)

TODO : Add more functionality than logging.
TODO : Add halt functionality outside of main loop. How?
TODO : Add clear function.
TODO : Initiate a new log every time it starts. Or at least give the option to.
TODO : Add date and time of creation to log name.

TODO : Graphical interface?
*/

class ErrorManager : public Singleton<ErrorManager>
{
	friend class Singleton<ErrorManager>;

public:
	void push_fatal(std::string error, std::string function_info);
	void push_error(std::string error, std::string function_info);
	void push_warning(std::string error, std::string function_info);

private:
	ErrorManager() : m_File(Log_path("Errorlogger.txt")) {}
	~ErrorManager() {}
	File m_File;

	void log(std::string to_log, std::string function_info);
};

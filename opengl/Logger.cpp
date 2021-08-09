#include "Logger.h"

#include "Log_path.h"
#include "File.h"
#include "ErrorManager.h"


int Logger::init(Path path) 
{
	m_File.late_init_path(path);
	been_initialized = true;
	return 1;
}

void Logger::push(std::string text_to_push) 
{
	if (been_initialized) {
		m_File.write(text_to_push);
	} else {
		ErrorManager::get_instance().push_warning("Logger not initialzied.", "In Logger.cpp");
	}
}

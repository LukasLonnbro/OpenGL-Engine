#include "Logger.h"

#include "Log_path.h"
#include "File.h"

void Logger::init(Path path) 
{
	m_File.late_init_path(path);
}

void Logger::push(std::string text_to_push) 
{
	m_File.write(text_to_push);
}

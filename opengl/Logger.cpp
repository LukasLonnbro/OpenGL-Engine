#include "Logger.h"

#include "Log_path.h"
#include "File.h"

Logger::Logger(std::string log_name) : m_Logpath(log_name), m_File(m_Logpath)
{
}
Logger::~Logger()
{
}

void Logger::push(std::string text_to_push) {
	m_File.write(text_to_push);
}

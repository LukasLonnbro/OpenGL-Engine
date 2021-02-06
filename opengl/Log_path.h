#pragma once

#include "Path.h"

#include <string>

class Log_path : public Path
{
public:
	Log_path(std::string log_name) : Path() {
		m_Path = m_Dependency_path + "logs\\" + log_name;
		m_Path_is_set = true;
	}
};
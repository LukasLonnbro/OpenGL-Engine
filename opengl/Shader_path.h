#pragma once

#include "Path.h"

#include <string>

class Shader_path : public Path
{
public:
	Shader_path(std::string shader_name) : Path() {
		m_Path = m_Dependency_path + "shaders\\" + shader_name;
		m_Path_is_set = true;
	}
};

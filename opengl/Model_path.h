#pragma once

#include "Path.h"

#include <string>

class Model_path : public Path
{
public:
	Model_path(std::string model_name) : Path() {
		m_Path = m_Dependency_path + "models\\" + model_name;
		m_Path_is_set = true;
	}
};

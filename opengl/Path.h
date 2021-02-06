#pragma once

#include <string>

//Path superclass with A specific path for each children. So Model_path, Texture_path etc.
//Currently relying on the mess that is "paths.h"
class Path
{
public:
	Path();
	~Path();
	
	//Bool that keeps track if the path has been initialized properly.
	virtual bool is_set();
	virtual std::string  get_as_string();
protected:
	std::string m_Path;
	std::string m_Dependency_path;
	std::string m_Exec_path;
	bool m_Path_is_set;
};


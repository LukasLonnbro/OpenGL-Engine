#include "Path.h"
#include "paths.h"


Path::Path(): m_Dependency_path(paths::getDependencyPath()), m_Exec_path(paths::getExecPath())
{
}

Path::~Path()
{
}

bool Path::is_set() {
	return m_Path_is_set;
}

std::string Path::get_as_string() {
	return m_Path;
}
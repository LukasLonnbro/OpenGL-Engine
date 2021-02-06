#include "paths.h"


//UGLY SOLUTION FIIIIIIX
std::string paths::getExecPath()
{
	char path[MAX_PATH];
	GetModuleFileName(NULL, path, MAX_PATH);
	return std::string(path);
}
const std::string paths::dependencyPath()
{
	std::string path = getExecPath();

	for (int i = 0; i < 2; i++) {
		size_t found = path.find_last_of("/\\");
		path = path.substr(0, found);
	}

	const std::string rtnpath = path;

	return rtnpath;
}

std::string paths::dependencies = dependencyPath() + "\\deps\\";
std::string paths::shaders = dependencies + "shaders\\";
std::string paths::models = dependencies + "models\\";
std::string paths::logs = dependencies + "logs\\";
#pragma once

#include <string>
#include <Shlwapi.h>

class paths
{
public:
	static std::string getExecPath()
	{
		char path[MAX_PATH];
		GetModuleFileName(NULL, path, MAX_PATH);
		return std::string(path);
	}
	static const std::string dependencyPath()
	{
		std::string path = getExecPath();

		for (int i = 0; i < 2; i++) {
			size_t found = path.find_last_of("/\\");
			path = path.substr(0, found);
		}

		const std::string rtnpath = path;

		return rtnpath;
	}

	static const inline std::string getDependencyPath() { return dependencies; }
	static const inline std::string getShaderPath() { return shaders; };
	static const inline std::string getModelPath() { return models; };

private:
	static std::string dependencies;
	static std::string shaders;
	static std::string models;
};

std::string paths::dependencies = dependencyPath() + "\\deps\\";
std::string paths::shaders		= dependencies + "shaders\\";
std::string paths::models		= dependencies + "models\\";
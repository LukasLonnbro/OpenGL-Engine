#pragma once

#include <string>
#include <Shlwapi.h>

//UGLY AS HELL FIX
class paths
{
public:
	static std::string getExecPath();
	static const std::string dependencyPath();

	static const inline std::string getDependencyPath() { return dependencies; }
	static const inline std::string getShaderPath() { return shaders; };
	static const inline std::string getModelPath() { return models; };

private:
	static std::string dependencies;
	static std::string shaders;
	static std::string models;
};
#pragma once

#include <string>
#include <Shlwapi.h>

//UGLY AS HELL FIX

// Will be removed in future.

class paths
{
public:
	static std::string getExecPath();
	static const std::string dependencyPath();

	static const inline std::string getDependencyPath() { return dependencies; }
	static const inline std::string getShaderPath() { return shaders; };
	static const inline std::string getModelPath() { return models; };
	static const inline std::string getLogsPath() { return logs; };

private:
	static std::string dependencies;
	static std::string shaders;
	static std::string models;
	static std::string logs;
};
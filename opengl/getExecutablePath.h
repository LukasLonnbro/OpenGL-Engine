#pragma once

#include <shlwapi.h>
#include <iostream>
#include <string>

// TODO : Add crossplatform reliability.
std::string getExecutableDirPath()
{
	char path[MAX_PATH];
	GetModuleFileName(NULL, path, MAX_PATH);
	PathRemoveFileSpec(path);
	return std::string(path);
}
#pragma once

#include <string>

#include "Path.h"

//Think of a good way to do this. Maybe set a working directory and then work locally. 

//For now just a wrapper for fstream. 
class File
{
public:
	File(Path path);
	~File();

private: 
	Path m_Path;
};


#pragma once

#include <string>

#include "Path.h"

#include <iostream>
#include <fstream>

//Think of a good way to do this. Maybe set a working directory and then work locally. 

//For now just a wrapper for fstream. 
class File
{
public:
	File(Path path);
	~File(){}

	void print_path() { std::cout << m_Path.get_as_string() << std::endl; }

	void write(std::string to_write);
private: 
	Path m_Path;
	std::fstream m_File;
};


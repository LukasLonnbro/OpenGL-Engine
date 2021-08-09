#pragma once

#include <string>

#include "Path.h"

#include <iostream>
#include <fstream>

/* 
	Think of a good way to do this. Maybe set a working directory and then work locally. 
	For now just a wrapper for fstream. 

	Takes a Path and creates a file at that path.

	__ EXAMPLE __

	Log_path path("test_log.txt");
	File m_File(path);
	m_File.write("Hello World!");
*/

class File
{
public:
	File();
	File(Path path);
	~File(){}

	void print_path() { std::cout << m_Path.get_as_string() << std::endl; }
	
	void late_init_path(Path path);
	void write(std::string to_write);

private: 
	Path m_Path;
	std::fstream m_File;
};


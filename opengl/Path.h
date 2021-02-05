#pragma once

#include <string>

//For now just a wrapper for a string. But in case it becomes relevant I wanna make file independant of hard coded paths.
//Maybe Im stupid.
//This needs to be more clever. 
class Path
{
public:
	Path();

	//Takes a name and generates a path to relevant folder.
	void model_path(std::string model_name);
	void get_shader_path(std::string shader_name);
	void get_texture_path(std::string texture_name);

	//Dude seriously, naming conventions my guy.
	void set_path_set();
private:
	std::string m_Path;
	bool path_is_set;
};


#include "Path.h"
#include "paths.h"

Path::Path() 
{
}

void Path::set_path_set() { 
	path_is_set = true; 
}

void Path::model_path(std::string model_name) {
	m_Path = paths::getModelPath() + model_name;
	set_path_set();
}
void Path::get_shader_path(std::string shader_name) {
	m_Path = paths::getModelPath() + shader_name;
}
void Path::get_texture_path(std::string texture_name) {
	m_Path = paths::getModelPath() + texture_name;
}
#include "ErrorManager.h"

#include "Path.h"

#include <iostream>

void ErrorManager::push_fatal(std::string error, std::string function_info)
{
	push_error("_FATAL_: " + error, function_info);
}

void ErrorManager::push_error(std::string error, std::string function_info) 
{
	std::cout << " Pushing Error: " << error << "\nIn: " << function_info << std::endl;
	m_File.write("_ERROR_: " + error + function_info + "\n");
}

void ErrorManager::push_warning(std::string error, std::string function_info)
{
	push_error("_WARNING_: " + error, function_info);
}

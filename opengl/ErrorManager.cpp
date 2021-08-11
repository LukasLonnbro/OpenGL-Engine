#include "ErrorManager.h"

#include "Path.h"

#include <iostream>

void ErrorManager::push_fatal(std::string error, std::string function_info)
{
	log("_FATAL_: " + error, function_info);
	std::cout << "FATAL ERROR. EXIT APPLICATION.";
	int a;
	std::cin >> a;
}

void ErrorManager::push_error(std::string error, std::string function_info) 
{
	log("_ERROR_: " + error, function_info);
}

void ErrorManager::push_warning(std::string error, std::string function_info)
{
	log("_WARNING_: " + error, function_info);
}

void ErrorManager::log(std::string error, std::string function_info) 
{
	std::cout << " Logging some error: ";
	m_File.write(error + " || ( " + function_info + " )\n");
}
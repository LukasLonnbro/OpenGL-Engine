#include "ErrorLogger.h"

#include "Path.h"

#include <iostream>

ErrorLogger::ErrorLogger() : Logger("Errorlog.txt")
{
}


ErrorLogger::~ErrorLogger()
{
}

void ErrorLogger::push_error(std::string error, std::string function_info) 
{
	std::cout << " Pushing Error: " << error << "\nIn: " << function_info << std::endl;
	push(error + function_info + "\n");
}

void ErrorLogger::push_fatal(std::string error, std::string function_info)
{
	push_error(error, function_info);
}

void ErrorLogger::push_warning(std::string error, std::string function_info)
{
	push_error(error, function_info);
}

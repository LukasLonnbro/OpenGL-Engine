#include "errorhandler.h"

#include <iostream>

std::vector<const void*> errorhandler::errorList = {};
int errorhandler::errorImpact = 0;

errorhandler::errorhandler()
{
}


errorhandler::~errorhandler()
{
}

//Const*, program will crash upon reading errors if data changes. 
//By passing SDL_GetError you pass a pointer that only points to the last occured error. 
//If a new error occurs the data will change and so you will end up with a bunch of the same error. 
//Unless SDL stores all errors and points to a special error not to the "Last error occured" memory buffer. 
//The data translation should be done in the class. Take in raw data (const void*) that is guaranteed to be a set of chars,
//and then create a local copy of the data (as opposed to the pointer) and store it in vector.

//EDIT: SDL_GetError return a const char* ...
void errorhandler::addError(const void* error, int type, const char* beautifier)
{
	if (type < errorImpact || errorImpact == 0)
	{
		errorImpact = type;
	}
	errorList.push_back(beautifier);
	errorList.push_back(error);
}
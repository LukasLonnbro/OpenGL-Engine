#pragma once

#include "Logger.h"

class ErrorLogger : Logger
{
public:
	ErrorLogger();
	~ErrorLogger();

private: 
	void push_fatal();
	void push_exception();
	void push_warning();
};


#pragma once

#include <fstream>

#include "Log_path.h"
#include "File.h"

/*
	Asyncronous Logger

	 Takes a log_name and creates a file at the deps//log//{log_name} (Dont forget to add .txt to the file name)

	 __ EXAMPLE __ usage
	 Logger log("Test_log.txt");
	 log.push("Hello World!);

	 void push(std::string text_to_push) {}
	 Pushes string to the log file.

	 Use file and log paths to do dis shit. 
	 TODO : make asynchrnous. Not sure how to handle threads yet thou.
	 TODO : .txt extension check
 */

class Logger
{
public:
	Logger(std::string log_name);
	virtual ~Logger();

	void push(std::string);

protected:
	Log_path m_Logpath;
	File	 m_File;

private: 

};
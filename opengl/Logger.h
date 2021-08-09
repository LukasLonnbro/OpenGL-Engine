#pragma once

#include <fstream>

#include "Singleton.h"
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
	 TODO : This kinda ugly, might need a revisit to filesystem
	 TODO : make asynchrnous. Not sure how to handle threads yet thou.
	 TODO : .txt extension check
 */

class Logger : public Singleton<Logger>
{
	friend class Singleton<Logger>;

public:
	void push(std::string);
	void init(Path path);

protected:
	Logger() {}
	File m_File;

};
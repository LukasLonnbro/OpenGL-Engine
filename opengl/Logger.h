#pragma once

#include <fstream>

#include "Singleton.h"
#include "Log_path.h"
#include "File.h"

/* OBS BEH�VER MER TANKE, ANV�NDS EJ F�R TILLF�LLET.*/

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
	 TODO : Dont like singleton. Might need to remake in order to make less error prone. Currently requires init, dont like.
 */


 /* OBS BEH�VER MER TANKE, ANV�NDS EJ F�R TILLF�LLET.*/


class Logger : public Singleton<Logger>
{
	friend class Singleton<Logger>;

public:
	void push(std::string);
	int init(Path path);

protected:
	Logger() {}
	File m_File;
	bool been_initialized;
};
#include "File.h"

#include <fstream>
#include <iostream>

void File::late_init_path(Path path) 
{
	m_Path = path;
}

File::File(Path path) : m_Path(path), m_File()
{
}
void File::write(std::string to_write) 
{
	if (!m_Path.is_set()) {
		std::cout << "Error, filepath not initialized in File construction.";
		int a;
		std::cin >> a;
	} else {

		m_File.open(m_Path.get_as_string(), std::ios_base::app | std::ios_base::in);
		if (m_File.is_open()) {
			m_File << to_write;
		}
		else {
			std::cout << "Error, unable to open file.\n";
			int a;
			std::cin >> a;
		}
		m_File.close();
	}
}


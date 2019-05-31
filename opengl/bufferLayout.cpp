#include "bufferLayout.h"

#include <iostream>

BufferLayout::BufferLayout()
{
}


BufferLayout::~BufferLayout()
{
}

void BufferLayout::tellMe()
{
	int size = elements.size();
	std::cout << "---\n" << size << " objects in layoutHolder:\n";
	for (int i = 0; i < size; i++)
	{
		auto cur = elements[i];
		std::cout << i << "| Count: " << cur.count << " Stride: " << stride << " Normalized: " << cur.normalized << std::endl; 
	}
	std::cout << "---\n";
}

//Create template class and make functions for different types of data.

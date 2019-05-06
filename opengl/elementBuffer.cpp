#include "elementBuffer.h"

#include <gl/glew.h>
#include <iostream>

elementBuffer::elementBuffer(const void* indices, const int& size)
{
	std::cout << "Creating element buffer.\n";
	glGenBuffers(1, &eb);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}
elementBuffer::~elementBuffer()
{
	std::cout << "Deleteing elementBuffer.";
	glDeleteBuffers(1, &eb);
}

void elementBuffer::bind() 
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb);
}

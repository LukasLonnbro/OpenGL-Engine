#include "elementBuffer.h"

#include <gl/glew.h>
#include <iostream>

ElementBuffer::ElementBuffer(const void* indices, const int& s, unsigned int c) : eb(0)
{
	std::cout << "Creating element buffer.\n";
	glGenBuffers(1, &eb);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, s, indices, GL_STATIC_DRAW);

	count = c;
}
ElementBuffer::~ElementBuffer()
{
	std::cout << "Deleting elementBuffer.\n";
	glDeleteBuffers(1, &eb);
}

void ElementBuffer::bind() 
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb);
}

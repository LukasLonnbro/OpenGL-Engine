#include "vertexBuffer.h"

#include <iostream>

//Ensures that the value uploaded is the value passed to the function.
//Create local pointer which points to a constant value, upon buffer update, simply change what the pointer points to. (?)
vertexBuffer::vertexBuffer(const void* data, unsigned int size)
{
	std::cout << "Creating vertexBuffer.";
	glGenBuffers(1, &vb);
	bind();
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
vertexBuffer::~vertexBuffer()
{
	std::cout << "Deleteing vertexBuffer.";
	glDeleteBuffers(1, &vb);
}
void vertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, vb);
}

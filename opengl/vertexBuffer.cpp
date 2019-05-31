#include "vertexBuffer.h"

#include <iostream>

//Ensures that the value uploaded is the value passed to the function.
//Create local pointer which points to a constant value, upon buffer update, simply change what the pointer points to. (?)
VertexBuffer::VertexBuffer(const void* data, unsigned int size) : vb(0)
{
	std::cout << "Creating vertexBuffer.\n";
	glGenBuffers(1, &vb);
	bind();
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
VertexBuffer::~VertexBuffer()
{
	std::cout << "Deleteing vertexBuffer.\n";
	glDeleteBuffers(1, &vb);
}
void VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, vb);
}

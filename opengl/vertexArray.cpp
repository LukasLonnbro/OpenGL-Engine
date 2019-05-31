#include "vertexArray.h"

#include <iostream>

#include <gl/glew.h>
#include <SDL.h>

VertexArray::VertexArray() : vao(0)
{
	std::cout << "VertexArray constructor.\n";
	glGenVertexArrays(1, &vao);
	bind();
}
VertexArray::VertexArray(const VertexArray &other) 
{
	std::cout << "VertexArray copy constructor.\n";
	vao = other.getID();
}
VertexArray::~VertexArray()
{
	std::cout << "VertexArray destructor.\n";
	glDeleteVertexArrays(1, &vao);
}
void VertexArray::bind() const
{
	glBindVertexArray(vao);
}

void VertexArray::addBuffer(const VertexBuffer& vb, const BufferLayout& layout)
{
	bind();
	vb.bind();
	int offset = 0;
	const auto& attributes = layout.getLayout();
	for (unsigned int i = 0; i < attributes.size(); i++)
	{
		const auto& attribute = attributes[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, attribute.count, attribute.type, (attribute.normalized ? GL_FALSE : GL_TRUE), layout.getStride(), (void*)offset);
		offset += layout.getTypeSize(attribute.type, attribute.count);
	}
}
#include "vertexArray.h"

#include <iostream>

#include <glew/glew.h>
#include <SDL/SDL.h>

vertexArray::vertexArray() : vao(0)
{
	std::cout << "Creating vertex array: ";
	glGenVertexArrays(1, &vao);
	std::cout << vao << std::endl;
	bind();
}
vertexArray::~vertexArray()
{
	std::cout << "Deleting va: ";
	std::cout << vao << std::endl;
	glDeleteVertexArrays(1, &vao);
}

void vertexArray::bind() const
{
	glBindVertexArray(vao);
}

void vertexArray::addBuffer(const vertexBuffer& vb, const bufferLayout& layout)
{
	bind();
	vb.bind();
	int offset = 0;
	const auto& attributes = layout.getLayout();
	for (unsigned int i = 0; i < attributes.size(); i++)
	{
		const auto& attribute = attributes[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, attribute.count, GL_FLOAT, attribute.normalized ? GL_FALSE : GL_TRUE, layout.getStride(), (char*)offset);
		offset += layout.getTypeSize(attribute.type) * attribute.count;
	}

	vbs.push_back(vb);
}
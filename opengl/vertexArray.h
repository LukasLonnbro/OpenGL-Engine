#pragma once

#include "vertexBuffer.h"
#include "bufferLayout.h"

class VertexArray
{
public:
	VertexArray();
	VertexArray(const VertexArray &other);
	~VertexArray();

	void bind() const;
	void addBuffer(const VertexBuffer& vb, const BufferLayout& layout);

	inline const unsigned int getID() const { return vao; };

private:
	GLuint vao;
};


#pragma once

#include <gl/glew.h>

class VertexBuffer
{
public:
	VertexBuffer(const void * data, unsigned int size);
	//vertexBuffer(const vertexBuffer& vb);
	~VertexBuffer(); 

	void bind() const;
private:
	GLuint vb;
};


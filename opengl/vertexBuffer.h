#pragma once

#include <gl/glew.h>

class vertexBuffer
{
public:
	vertexBuffer(const void * const data, unsigned int size);
	//vertexBuffer(const vertexBuffer& vb);
	~vertexBuffer(); 

	void bind() const;
private:
	GLuint vb;
};


#pragma once

#include "vertexBuffer.h"
#include "bufferLayout.h"

class vertexArray
{
public:
	vertexArray();
	~vertexArray();

	void bind() const;
	void addBuffer(const vertexBuffer& vb, const bufferLayout& layout);

	inline const unsigned int getID() { return vao; };

private:
	GLuint vao;
	std::vector<vertexBuffer> vbs;
};


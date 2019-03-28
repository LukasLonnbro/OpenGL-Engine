#pragma once
class elementBuffer
{
public:
	elementBuffer(const void* indices, const int& size);
	~elementBuffer();

	void bind();

private:
	unsigned int eb;
};


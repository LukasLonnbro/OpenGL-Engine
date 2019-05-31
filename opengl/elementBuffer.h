#pragma once
class ElementBuffer
{
public:
	ElementBuffer(const void* indices, const int& size, unsigned int count);
	~ElementBuffer();

	void bind();
	unsigned int getCount() const { return count; }

private:
	unsigned int eb;
	unsigned int count;
};


#pragma once

template <typename T>
class StackAllocator
{
public:

	StackAllocator(size_t size)
	{
		stack = new T[size];
	}
	~StackAllocator();

	//Push new element.
	void push();
	void pop();
	void get_marker();
	void free_to_marker();

private:
	T* stack;
};


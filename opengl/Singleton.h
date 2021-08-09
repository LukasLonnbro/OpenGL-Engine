#pragma once

//TODO : Currently not thread-safe?

//Singletons are not deallocated until program termination. Careful with usage.
template <typename T>
class Singleton
{
public:
	//Declare in function, instantiated on first use. Guaranteed to be destroyed.
	static T& get_instance() {
		static T instance;
		return instance; 
	}

protected:
	Singleton(){}
	~Singleton(){}

public:
	//Not declared to avoid potential copies. Could use delete, but nah. Too scary
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const &) = delete;
};


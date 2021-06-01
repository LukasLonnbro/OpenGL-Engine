#pragma once

//Currently not thread-safe?

//Singletons are not deallocated until program termination. Careful with usage.
class Singleton
{
public:
	//Declare in function, instantiated on first use. Guaranteed to be destroyed.
	Singleton& get_instance() {
		static Singleton instance;

		return instance; 
	}

private:
	Singleton(){}
	virtual ~Singleton(){}
	
	//Not declared to avoid potential copies. Could use delete, but nah. Too scary
	Singleton(Singleton const&);
	void operator=(Singleton const&);
};


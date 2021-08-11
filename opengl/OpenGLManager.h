#pragma once

#include "Singleton.h"

//TODO : No clue how to retrieve erros yet.

class OpenGLManager : public Singleton<OpenGLManager> 
{
	friend class Singleton<OpenGLManager>;

public:
	int start_up();

protected:
	OpenGLManager();
	~OpenGLManager();

};


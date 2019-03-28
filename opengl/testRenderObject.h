#pragma once
#include "abstractRenderObject.h"

class testRenderObject : public abstractRenderObject
{
public: 
	testRenderObject(abstractShader * shader, const char* modelPath) : abstractRenderObject(shader, modelPath)
	{
	}
};
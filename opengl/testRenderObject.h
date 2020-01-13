#pragma once
#include "abstractRenderObject.h"

#define TEST_RO 0x02;

class testRenderObject : public abstractRenderObject
{
public: 
	testRenderObject(abstractShader * shader, const char* modelPath) : 
		abstractRenderObject(shader, modelPath)
	{
		identifier = TEST_RO;
	}
};
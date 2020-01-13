#pragma once
#include "abstractRenderObject.h"

#define INSTANCED 0x02;
class instancedRenderObject : public abstractRenderObject
{
public:
	instancedRenderObject(abstractShader * shader, const char* modelPath) : abstractRenderObject(shader, modelPath)
	{
		identifier = INSTANCED;
	}

	void renderMeshes()
	{
	}
};
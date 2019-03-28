#pragma once
#include "abstractRenderObject.h"

class instancedRenderObject : public abstractRenderObject
{
public:
	instancedRenderObject(abstractShader * shader, const char* modelPath) : abstractRenderObject(shader, modelPath)
	{
	}

	void renderMeshes()
	{

	}
};
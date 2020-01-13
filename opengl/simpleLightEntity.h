#pragma once
#include "abstractLightEntity.h"

class simpleLightEntity : public abstractLightEntity
{
public:
	simpleLightEntity(glm::vec3 pos, abstractLightRender* renderObject) :
		abstractLightEntity(pos, renderObject)
	{}
};
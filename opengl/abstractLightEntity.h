#pragma once
#include "abstractEntity.h"
#include "abstractLightRender.h"

class abstractLightEntity : public abstractEntity
{
public:
	abstractLightEntity(glm::vec3 pos, abstractLightRender* renderObject) : 
		abstractEntity(pos, renderObject), m_RenderObject(renderObject)
	{}

	const abstractLightRender* getRenderObject() const { return m_RenderObject; }

protected: 
	abstractLightRender* m_RenderObject;
};
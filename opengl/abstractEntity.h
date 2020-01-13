#pragma once

#include "type.h"
#include "basicShader.h"
#include "camera.h"
#include "abstractRenderObject.h"

#include <glm/mat4x4.hpp>

class abstractEntity
{
public:
public:
	abstractEntity(glm::vec3 pos, abstractRenderObject * renderObject) :
		position(pos),
		m_RenderObject(renderObject)
	{
		position = pos;
		m_RenderObject->setPosition(position);

	}

	virtual void update()
	{
		m_RenderObject->setPosition(position);
	}

	virtual inline const abstractRenderObject * getRenderObject() const { return m_RenderObject; };
	virtual void setDataPointer(abstractRenderObject * data) { m_RenderObject = data; };

protected:
	glm::vec3 position;
	abstractRenderObject* m_RenderObject;
};


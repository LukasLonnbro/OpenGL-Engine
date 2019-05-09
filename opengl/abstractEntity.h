#pragma once

#include "type.h"
#include "basicShader.h"
#include "camera.h"
#include "abstractRenderObject.h"

#include <glm/mat4x4.hpp>

class abstractEntity
{
public:
	abstractEntity(abstractRenderObject * RO) : m_RenderObject(RO) {}

	virtual void update() {};

	//Fix macros as opposed to returning the enum. 
	virtual inline const type getType() const { return m_Type; }

	virtual inline const abstractRenderObject * getRenderObject() const { return m_RenderObject; };
	virtual inline const glm::mat4* getModelMat() const { return &modelMatrix; }
	
	virtual void setDataPointer(abstractRenderObject * data) { m_RenderObject = data; };

protected:
	// TODO: replace with physicsObject
	type m_Type;

	glm::vec3 pos;

	glm::mat4 modelMatrix;

private:
	abstractRenderObject * m_RenderObject;
};


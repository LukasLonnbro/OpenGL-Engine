#pragma once

#include "type.h"
#include "basicShader.h"
#include "camera.h"
#include "abstractRenderObject.h"

#include <glm/mat4x4.hpp>

class abstractEntity
{
public:
	abstractEntity(abstractRenderObject * renderOBject) : m_RenderObject(renderOBject) {}

	virtual void update() {};

	//Fix macros as opposed to returning the enum. 
	virtual inline const type getType() const { return m_Type; }
	virtual inline const abstractShader *  getShader() { return m_RenderObject->getShader(); };
	virtual inline const abstractRenderObject *  getRenderObject() { return m_RenderObject; };
	virtual inline const glm::mat4* getModelMat() { return &modelMatrix; }
	virtual inline const shaderType getShaderType() { return m_ShaderType; }
	
protected:
	// TODO: replace with physicsObject
	type m_Type;
	shaderType m_ShaderType;

	glm::vec3 pos;

	glm::mat4 modelMatrix;
private:
	abstractRenderObject * m_RenderObject;
};


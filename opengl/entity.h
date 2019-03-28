#pragma once

#include "type.h"
#include "basicShader.h"

class entity
{
public:
	entity();
	virtual ~entity();

	virtual void update();
	virtual void draw();

	//Fix macros as opposed to returning the enum. 
	inline type getType() const { return m_Type; }
	
	virtual shader * getShader() { return &m_Shader; };

protected:
	type m_Type;

private:
	basicShader m_Shader;
};


#pragma once

#include "abstractEntity.h"

#include <vector>





class level
{
public:
	level();
	~level();

	inline const std::vector<abstractEntity*> * getEntities() const { return &m_Entities; }

	void update();

private:
	std::vector<abstractEntity*> m_Entities;
	std::vector<abstractShader*> m_Shaders;
	std::vector<abstractRenderObject*> m_RenderObjects;

};


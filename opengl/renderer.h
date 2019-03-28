#pragma once

#include "abstractEntity.h"
#include "errorhandler.h"
#include "camera.h"

#include <vector>

class renderer
{
public:
	renderer();
	~renderer();

	void render();
	void updateEntities(const std::vector<abstractEntity*> * entities);
private: 
	void sortByRenderObject(const std::vector<abstractEntity*> * entities);
	void sortByShader();
	void sortByVa();

	camera m_Camera;
	std::vector<std::vector<abstractEntity*>> m_Entities;
};


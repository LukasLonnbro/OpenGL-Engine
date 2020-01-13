#pragma once

#include "abstractEntity.h"
#include "abstractLightEntity.h"

#include "errorhandler.h"
#include "camera.h"

#include <vector>

class renderer
{
public:
	renderer();
	~renderer();

	void render();

	//This can be written much more clearly. 
	void prep(const std::vector<abstractEntity>* entities);

	//Currently deep copying data, pass the pointer instead.
	void setLights(const std::vector<abstractLightEntity>* lights) { m_Lights = lights; }

private: 
	void sortByRenderObject(const std::vector<abstractEntity>* entities);
	void sortByShader(const std::vector<abstractEntity>& entities) {}
	void sortByVa() {}

	camera m_Camera;
	std::vector<const abstractEntity*> sortedEntities;
	
	const std::vector<abstractLightEntity>* m_Lights;
};


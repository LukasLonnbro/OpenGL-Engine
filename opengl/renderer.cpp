#include "renderer.h"

#include <iostream>

#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>


renderer::renderer()
{
}
renderer::~renderer()
{
}

// Entities all inherit a renderObject. Renderobject are specific types of object that the renderer knows how to interpret data from
// thus allowing entities to contain all data regarding rendering without interfering with renderer data interpretation. 
// Pre game execution, all raw rendering data from the relevant renderObjects are loaded and sorted into arrays of data execution (these 
// calculations can be done before any run time rendering happens) to reduce necessary texture binds, sort by shaders etc. 
// During actual rendering, the renderer grabs all relevant renderObjects, and based of index provided in the preload phase, 
// renders entities in a certain order, keeping texture binds and buffer binds at a minimum.

// The renderer should only work with models that are in work memory. FOr smaller games essentially all models can be loaded into memory at once.
// For larger games with more complex models, this has to be done during in game loading phases.

// TLDR: Renderer grabs renderObjects, sorts bindable objects in a manner that reduces necessary binds, 
// and ships it off to the datamanager for data storage management.

void renderer::prep(const std::vector<abstractEntity> *entities)
{
	sortByRenderObject(entities);
}
void renderer::sortByRenderObject(const std::vector<abstractEntity> *entities)
{
	std::vector<const abstractEntity *> temp;
	const abstractEntity *current, *previous = &(*entities)[0];

	//Should be a linked list at sorting, and then copied over to a vector.
	//Also presumes all entities are created in order, doesn't 
	for (unsigned int i = 0; i < entities->size(); i++) {
		current = &(*entities)[i];
		if (typeid(current) == typeid(previous)) {
			temp.push_back(current);
		}
		else {
			sortedEntities.push_back(temp);
			temp.clear();
		}
	}
	sortedEntities.push_back(temp);
}


void renderer::render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	m_Camera.update();

	glm::mat4 viewMat = (*m_Camera.getViewMatrix());
	glm::mat4 projMat = (*m_Camera.getProjectionMatrix());
	glm::mat4 modelMat = glm::mat4(1.0f);

	for (unsigned int i = 0; i < sortedEntities.size(); i++) {
		//std::cout << "New shaders binds.\n";

		//Unnecessary copy
		const abstractRenderObject * renderObject = sortedEntities[i][0]->getRenderObject();
		const abstractShader * shader = renderObject->getShader();
		
		shader->use();
		shader->setMat4("view", glm::value_ptr(viewMat));
		shader->setMat4("projection", glm::value_ptr(projMat));

		int size = sortedEntities[i].size();
		for (int j = 0; j < size; j++) {
			renderObject->renderMeshes();
		}
	}
}
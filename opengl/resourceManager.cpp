#include "resourceManager.h"

#include "basicShader.h"
#include "testRenderObject.h"
#include "player.h"
#include "simpleLightRender.h"
#include "simpleLightEntity.h"

#include "paths.h"

#include <glm/glm.hpp>

/* 
	Thought: Predefined amount of storage set aside for things to always have in memory.
	Everything else is dynamically loaded as a linked list* with priority queues:
	
	*There is a lot of data to copy so vectors should be slower.

	IF : PRIO_RENDER added to the head or tail of the list, dataManager keeps an index 
	of priority renders and all other data is put behind that index, if deletion of data i necessary, 
	it will never delete priority renders.
	IF : ALWAYS_IN_MEMORY it's allocated in the predefined space - needs some sort of check if the memory is full.

	PRE_ALLOC_BUFFER_SIZE is the size of the always in memory buffer. 
	
	Buffer setups?
*/

dataManager::dataManager() : priorityIndex(0), staticAllocIndex(0)
{
}
// OBS : using destructor, care for exceptions when using copy and assignment constructors.
dataManager::~dataManager()
{
	for (auto v : shaderPrograms)
		delete v;

	for (auto v : dynamicRenderData)
		delete v;
}

// TODO :
// Automate creation based on text file.
// Add static allocation based on entity preference.
std::vector<abstractEntity>* dataManager::loadEntities()
{
	//Probably doesn't have to be heap allocated. 
	basicShader* shader = new basicShader;
	shaderPrograms.push_back(shader);
	
	testRenderObject* m_TeapotRenderOBject = new testRenderObject(shaderPrograms[0],
		(paths::getModelPath() + "teapot.obj").c_str());
	player m_Player(glm::vec3(0.0f), m_TeapotRenderOBject);

	simpleLightRender* m_CubeRenderObject = new simpleLightRender(
		shaderPrograms[0],
		(paths::getModelPath() + "teapot.obj").c_str(),
		glm::vec3(0.1f, 0.1f, 0.1f),
		glm::vec3(0.5f, 0.0f, 0.5f),
		glm::vec3(1.0f, 1.0f, 1.0f)
	);
	simpleLightEntity light(glm::vec3(4.0f, 4.0f, 4.0f), m_CubeRenderObject);

	dynamicRenderData.push_back(m_TeapotRenderOBject);
	dynamicRenderData.push_back(m_CubeRenderObject);

	entities.push_back(m_Player);
	entities.push_back(light);
	lights.push_back(light);

	return &entities;
}

void dataManager::loadMap(/*MAP map = null*/)
{
}
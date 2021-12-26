 #pragma once
#include "abstractShader.h"
#include "abstractRenderObject.h"
#include "abstractEntity.h"
#include "abstractLightEntity.h"

#include "Singleton.h"

#include <vector>
#include <list>



// TODO : Implement different types of allocators.
// Should probably have a default type.

//Rewrite too static member variables set on initiation for readability?
#ifndef STATIC_ALLOC
	#define STATIC_ALLOC			false
#endif
#define ALWAYS_IN_MEMORY			0x01
#define PRIORITY_RENDER				0x02
#define STATIC_ALLOC_MEMORY_SIZE	100

class ResourceManager : public Singleton<ResourceManager>
{
	friend class Singleton<ResourceManager>;

public:
	ResourceManager();
	~ResourceManager();

	inline const std::vector<abstractEntity>* getEntities() const { return &entities; }
	inline const std::vector<abstractLightEntity>* getLights() const { return &lights; }

	void loadMap();
	std::vector<abstractEntity>* loadEntities();


private:

	//Needs to be heap allocated, make sure to delete in destructor. Currently memory leak.
	abstractRenderObject * staticRenderData[STATIC_ALLOC_MEMORY_SIZE];
	std::list<abstractRenderObject *> dynamicRenderData;

	std::vector<abstractEntity> entities;
	std::vector<abstractLightEntity> lights;

	unsigned int priorityIndex;
	unsigned int staticAllocIndex;

	//Linked list might be slightly faster?
	std::vector<abstractShader *> shaderPrograms;
};

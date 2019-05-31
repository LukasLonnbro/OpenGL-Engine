 #pragma once
#include "abstractShader.h"
#include "abstractRenderObject.h"
#include "abstractEntity.h"

#include <vector>
#include <list>

#ifndef STATIC_ALLOC
	#define STATIC_ALLOC			false
#endif
#define ALWAYS_IN_MEMORY			0x01
#define PRIORITY_RENDER				0x02
#define STATIC_ALLOC_MEMORY_SIZE	100

class dataManager
{
public:
	dataManager();
	~dataManager();

	const inline std::vector<abstractEntity> * getEntities() const { return &entities; }

	void loadMap();
	std::vector<abstractEntity>* loadEntities();

private:
	//Needs to be heap allocated, make sure to delete in destructor. Currently memory leak.
	abstractRenderObject * staticRenderData[STATIC_ALLOC_MEMORY_SIZE];
	std::list<abstractRenderObject *> dynamicRenderData;
	std::vector<abstractEntity> entities;

	unsigned int priorityIndex;
	unsigned int staticAllocIndex;

	//Linked list might be slightly faster?
	std::vector<abstractShader *> shaderPrograms;
};

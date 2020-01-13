#pragma once

#include "abstractEntity.h"
#include "testRenderObject.h"

#include <glm/mat4x4.hpp>

class player : public abstractEntity
{
public:
	player(glm::vec3 position, testRenderObject * tRO);
	~player();
};


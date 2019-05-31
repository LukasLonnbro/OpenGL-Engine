#include "player.h"
#include "eventHandler.h"
#include "basicShader.h"
#include "testRenderObject.h"

#include "abstractEntity.h"

#include <iostream>

#include <gl/glew.h>
#include <glm/gtc/matrix_transform.hpp>

player::player(glm::vec3 position, testRenderObject * tRO) : abstractEntity(tRO) 
{
	m_Type = type::ACTIVE;
	pos = position;
	modelMatrix = glm::translate(glm::mat4(1.0f), pos);
}

player::~player()
{
}

void player::update()
{
	m_renderData->setModelMat(modelMatrix);
}
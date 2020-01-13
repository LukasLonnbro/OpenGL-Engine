#include "player.h"
#include "eventHandler.h"
#include "basicShader.h"
#include "testRenderObject.h"

#include "abstractEntity.h"

#include <iostream>

#include <gl/glew.h>
#include <glm/gtc/matrix_transform.hpp>

player::player(glm::vec3 position, testRenderObject * tRO) : abstractEntity(position, tRO) 
{
}

player::~player()
{
}
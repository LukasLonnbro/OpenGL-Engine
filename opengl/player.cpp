#include "player.h"
#include "eventHandler.h"
#include "basicShader.h"
#include "testRenderObject.h"

#include <iostream>

#include <gl/glew.h>
#include <glm/gtc/matrix_transform.hpp>

player::player(glm::vec3 position, testRenderObject * renderObject) : abstractEntity(renderObject)
{
	m_Type = type::ACTIVE;
	m_ShaderType = shaderType::BASICSHADER;
	pos = position;
	modelMatrix = glm::translate(glm::mat4(1.0f), pos);
	m_RenderObject = renderObject;
}

player::~player()
{
}

void player::update()
{
	if (attached)
	{
		const glm::vec3 newPos = *m_Camera.getPos();
		//m_RenderObject->setModelMatrix(newPos, pos);
		pos = newPos;

		//std::cout << "attached position: " << pos.x << " | " << pos.y << " | " << pos.z << " | \n";
	}
	else
	{
		//std::cout << "position: " << pos.x << " | " << pos.y << " | " << pos.z << " | \n";
	}
}
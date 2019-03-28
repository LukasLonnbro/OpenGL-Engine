#include "level.h"
#include "player.h"
#include "testRenderObject.h"

#include <iostream>

/*

Serves as a middle point between the gamecontroller and entities.
In case of changes to the entity class, no changes to the gamecontroller is necessary.

If pursuing a physics engine, the gamecontroller simply collects entities and sends them off
to the physics engine who interracts with the entities updaters.

*/

// Entity declarations: 
// TODO : Level creation through a file. 
level::level()
{
	basicShader * shader = new basicShader();
	testRenderObject * m_TestRenderObject = new testRenderObject(shader, "C:\\Users\\Lukas\\source\\repos\\opengl\\opengl\\deps\\models\\triangle.obj");

	m_RenderObjects.push_back(m_TestRenderObject);
	m_Shaders.push_back(shader);

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			abstractEntity *m_Player = new player(glm::vec3((float)j * 10, 0.0f, (float)i * 10), m_TestRenderObject);
			m_Entities.push_back(m_Player);
		}
	}
}
level::~level()
{
	for (unsigned int i = 0; i < m_Entities.size(); i++)
		delete m_Entities[i];

	for (unsigned int i = 0; i < m_Shaders.size(); i++)
		delete m_Shaders[i];

	for (unsigned int i = 0; i < m_RenderObjects.size(); i++)
		delete m_RenderObjects[i];

}

void level::update()
{
	for (unsigned int i = 0; i < m_Entities.size(); i++)
		m_Entities[i]->update();
}
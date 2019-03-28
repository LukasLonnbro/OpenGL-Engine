#include "entityController.h"
#include "player.h"

#include <iostream>

/*

Serves as a middle point between the gamecontroller and entities. 
In case of changes to the entity class, no changes to the gamecontroller is necessary. 

If pursuing a physics engine, the gamecontroller simply collects entities and sends them off 
to the physics engine who interracts with the entities updaters. 

*/

// Entity declarations: 
// Automate declarations somehow ? 
level::level() 
{
	abstractEntity *m_Player = new player(glm::vec3(0.0f, 0.0f, -5.0f));
	abstractEntity *m_Player1 = new player(glm::vec3(0.0f, 0.0f, 1.0f));

	m_Entities = {
		m_Player,
		m_Player1
	};
}
level::~level()
{
	for (unsigned int i = 0; i < m_Entities.size(); i++)
		delete m_Entities[i];
}

void level::update()
{
	for (unsigned int i = 0; i < m_Entities.size(); i++)
		m_Entities[i]->update();
}
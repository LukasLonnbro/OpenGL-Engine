#include "gameController.h"
#include "eventHandler.h"
#include "abstractRenderObject.h"
#include "constants.h"
#include "resourceManager.h"

//#include "entity.h"
//#include "eventHandler.h

#include <iostream>
#include <string>
#include <stdlib.h>

#include <gl/glew.h>
#include <SDL.h>



// --- CURRENT IDEAS ---

// Gamecontroller is responsible for distributing necessary data based on state and levels.
// Given a certain state, the gameController fetches either relevant UI and or level.

// TODO : eventController

// FUTURE IMPLEMENTATIONS
// phsyics engine

gameController::gameController(const Window * aWindow) : lastTick(0)
{
	m_Window = aWindow;
}
gameController::~gameController()
{
}

int gameController::update()
{
	
		/*
		const std::vector<abstractRenderObject*> * renderOBjects = level.getRenderObjects();
		const std::vector<abstractPhysicsObject*> * physicsObjects = level.getPhysicsObjects();

		level.updateEntities();

		m_PhysicsEngine.update(physicsObjects);
		m_Renderer.render(renderObjects());
		*/

	return 1;
}

void gameController::run() 
{
	dataManager data;
	data.loadEntities();

	//Can be rewritten to more easily read code. 
	m_Renderer.setLights(data.getLights());
	m_Renderer.prep(data.getEntities());

	int GAMETICKS = 0;
	int curTick = 0;
	while (true) {
		curTick = SDL_GetTicks();
		if (curTick - lastTick >= (1000 / 144)) { //update 144 times per second
			lastTick = curTick;
			GAMETICKS++;

			eventHandler::update();

			// Entity updating 

			m_Renderer.render();

			if (GAMETICKS % 144 == 0) {
				system("cls");
				std::cout << "FPS: " << frames << std::endl;
				frames = 0;
			}
			frames++;
			SDL_GL_SwapWindow(m_Window->getWindowHolder());
		}
	}
}
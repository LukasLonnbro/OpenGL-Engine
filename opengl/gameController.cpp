#include "gameController.h"
#include "eventHandler.h"
#include "abstractRenderObject.h"

//#include "entity.h"
//#include "eventHandler.h

#include <iostream>
#include <string>

#include <gl/glew.h>
#include <SDL.h>

#include "info.h"

// --- CURRENT IDEAS ---

// Gamecontroller is responsible for distributing necessary data based on state and levels.
// Given a certain state, the gameController fetches either relevant UI and or level.

// TODO : eventController

// FUTURE IMPLEMENTATIONS
// phsyics engine

gameController::gameController(const window * aWindow) : lastTick(0)
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
	m_Level.update();

	const std::vector<abstractEntity*> * entities = m_Level.getEntities();
	m_Renderer.updateEntities(entities);
	
	while (true) {
		eventHandler::update();

		m_Renderer.render();

		int curTick = SDL_GetTicks();
		if (curTick - frameTick >= 1000) {
			std::cout << "FPS: " << frames << std::endl;
			frames = 0;

			frameTick = curTick;
		}
		frames++;

		lastTick = curTick;

		SDL_GL_SwapWindow(m_Window->getWindowHolder());
	}
}
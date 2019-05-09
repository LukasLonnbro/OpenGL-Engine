#pragma once

#include "abstractEntity.h"
#include "testRenderObject.h"

#include <glm/mat4x4.hpp>

class player : public abstractEntity
{
public:
	player(glm::vec3 position, testRenderObject * tRO);
	~player();

	void update();
	void attachCamera(camera cameraToAttach) { m_Camera = cameraToAttach; attached = true; };

private:
	// TODO? : replace with cameraObject
	camera m_Camera;
	bool attached;

	testRenderObject * m_renderData;

	//TODO? : add eventObject.
};


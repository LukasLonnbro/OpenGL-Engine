#pragma once

#include "abstractEntity.h"
#include "testRenderObject.h"

#include <glm/glm/mat4x4.hpp>

class player : public abstractEntity
{
public:
	player(glm::vec3 position, testRenderObject * renderObject);
	~player();

	void update();

	void attachCamera(camera cameraToAttach) { m_Camera = cameraToAttach; attached = true; };

private:
	testRenderObject * m_RenderObject;


	// TODO? : replace with cameraObject
	camera m_Camera;
	bool attached;

	//TODO? : add eventObject.
};


#pragma once

#include <glm/ext/matrix_float4x4.hpp>

class camera
{
public:
	camera();
	~camera();

	void update();

	//change to glm::value_ptr
	const glm::mat4 * const getViewMatrix() { return &viewMatrix; };
	const glm::mat4 * const getProjectionMatrix() { return &projectionMatrix; };
	const glm::vec3 * const getPos() { return &pos; };

private:
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;

	glm::vec3 pos;
	glm::vec3 front;
	glm::vec3 up;

	void moveByKeyboard();
	void rotateByMouse();

	float directionX;
	float directionY;

	float sensitivity;
};


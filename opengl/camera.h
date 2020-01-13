#pragma once

#include <glm/ext/matrix_float4x4.hpp>

class camera
{
public:
	camera();
	~camera();

	void update();
	void update_FIXED_CENTER();

	//change to glm::value_ptr
	const glm::mat4* getViewMatrix() const { return &viewMatrix; };
	const glm::mat4* getProjectionMatrix() const { return &projectionMatrix; };
	
	const glm::vec3* getPos() const { return &pos; }
	const glm::vec3* getDir() const { return &front; }

private:
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;

	glm::vec3 pos;
	glm::vec3 front;
	glm::vec3 up;

	void moveByKeyboard();
	void rotateByMouse();
	void rotateByKeyboard();

	float directionX;
	float directionY;

	float sensitivity;

	float distance;
};


#include "camera.h"

#include <SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "constants.h"
#include "USER_IO.h"

#include <iostream>

camera::camera() :
	viewMatrix(glm::mat4(1.0f)),
	projectionMatrix(glm::mat4(1.0f)),
	sensitivity(0.5f),
	distance(20.0f)
{
	pos = glm::vec3(2.0f, 2.0f, 2.0f);
	front = glm::vec3(0.0f, 0.0f, 1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);

	viewMatrix = glm::lookAt(pos, pos + front, up);
	projectionMatrix = glm::perspective(
		glm::radians(45.0f),
		(float)(info::WIDTH() / info::WIDTH()),
		0.1f, 100.0f
	);
}
camera::~camera()
{
}


void camera::moveByKeyboard()
{
	glm::vec3 norm_front = glm::normalize(front);
	if (evt->w)
	{
		pos += norm_front * 0.1f;
	}
	if (evt->s)
	{
		pos -= norm_front * 0.1f;
	}
	if (evt->a)
	{
		pos += glm::cross(up, front) * 0.1f;
	}
	if (evt->d)
	{
		pos -= glm::cross(up, front) * 0.1f;
	}
	if (evt->space)
	{
		pos.y += 0.1f;
	}
	if (evt->shift)
	{
		pos.y -= 0.1f;
	}
}

void camera::rotateByKeyboard()
{
	if (evt->q){
		directionX -= 1.0f * sensitivity;
	} if (evt->e){
		directionX += 1.0f * sensitivity;
	}
	if (evt->f) {
		directionY -= 1.0f * sensitivity;
	} if (evt->r) {
		directionY += 1.0f * sensitivity;
	}

	float angleX = glm::radians(directionX);
	float angleY = glm::radians(directionY);

	front.x = cos(angleY) * cos(angleX);
	front.y = sin(angleY);
	front.z = cos(angleY) * sin(angleX);
	front = glm::normalize(front);
}

void camera::rotateByMouse()
{
	//std::cout << "MusePos: " << eventHandler::getEvents()->mouseX << " | " << eventHandler::getEvents()->mouseX << std::endl;

	float deltaX = evt->mouseX - (info::WIDTH() / 2);
	float deltaY = (info::HEIGHT() / 2) - evt->mouseY;

	directionY += deltaY * sensitivity;
	directionX += deltaX * sensitivity;

	if (directionY > 89.0f)
		directionY = 89.0f;
	if (directionY < -89.0f)
		directionY = -89.0f;

	float angleX = glm::radians(directionX);
	float angleY = glm::radians(directionY);

	front.x = cos(angleY) * cos(angleX);
	front.y = sin(angleY);
	front.z = cos(angleY) * sin(angleX);
	front = glm::normalize(front);

	USER_IO::setMousePos(info::WIDTH() / 2, info::HEIGHT() / 2);
}


void camera::update()
{
	//rotateByMouse();
	rotateByKeyboard();
	moveByKeyboard();

	if (evt->x)
	{
		pos = glm::vec3(5.0f, 5.0f, 5.0f);
		front = glm::vec3(0.0f, 0.0f, 1.0f);
		directionY = 0;
		directionX = 0;
	}


	viewMatrix = glm::lookAt(pos, pos + front, up);
	projectionMatrix = glm::perspective(
		glm::radians(50.0f),
		info::WIDTH() / info::WIDTH(),
		0.1f, 
		100.0f
	);

	//std::cout << "position: " << pos.x << " | " << pos.y << " | " << pos.z << " | \n";
	//std::cout << "front: " << front.x << " | " << front.y << " | " << front.z << " | \n";
}

void camera::update_FIXED_CENTER() {
	if (evt->w) { distance += 0.1f; }
	if (evt->s) { distance -= 0.1f; }
	if (evt->a) { directionX -= 0.01f; }
	if (evt->d) { directionX += 0.01f; }
	if (evt->space) { pos.y += 0.1f; }
	if (evt->shift) { pos.y -= 0.1f; }

	pos.x = sin(directionX) * distance;
	pos.z = cos(directionX) * distance;

	glm::vec3 center = glm::vec3(0.0f, 0.0f, 0.0f);
	viewMatrix = glm::lookAt(pos, center, up);
}
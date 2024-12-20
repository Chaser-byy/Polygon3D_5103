#include "Camera.h"

Camera::Camera(const Config& config) 
{
	pEntity = NULL;

	position = { 0.0f, 0.0f, 3.5f };

	projMatrix = glm::perspective(glm::radians(config.fov), config.WindowX / config.WindowY, 0.1f, 100.0f);
	viewMatrix = glm::lookAt(position, position + glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

const glm::mat4& Camera::getViewMatrix() const
{
	return viewMatrix;
}

const glm::mat4& Camera::getProjMatrix() const
{
	return projMatrix;
}

void Camera::linkEntity(const Entity& entity) 
{
	pEntity = &entity;
}

void Camera::update()
{
	//position = pEntity->position;
	//rotation = pEntity->rotation;
	
	//rotation.y += mouse.getXoffset();

	//rotation.x += mouse.getYoffset();

	if (rotation.x > 89.0f)
		rotation.x = 89.0f;
	if (rotation.x < -89.0f)
		rotation.x = -89.0f;

	viewMatrix = glm::lookAt(position, position + front, up);
}

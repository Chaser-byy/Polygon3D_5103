#pragma once
#ifndef _CAMERA_H
#define _CAMERA_H

#include "../Util/glm.h"
#include "../Util/Entity.h"
#include "../Util/Config.h"

//#include "../Control/Mouse/Mouse.h"

class Camera : public Entity
{
public:
	Camera(const Config& config);

	const glm::mat4& getViewMatrix() const;
	const glm::mat4& getProjMatrix() const;
	void linkEntity(const Entity& entity);
	void update();

private:
	glm::mat4 viewMatrix;
	glm::mat4 projMatrix;
	
	glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 up	= glm::vec3(0.0f, 1.0f, 0.0f);

	const Entity* pEntity ;

};
#endif

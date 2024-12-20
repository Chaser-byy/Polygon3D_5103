#pragma once
#ifndef _ENTITY_H
#define _ENTITY_H

#include "glm.h"

struct Entity
{
	glm::vec3 position = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);

	glm::mat4 getModelMatrix();
};

#endif

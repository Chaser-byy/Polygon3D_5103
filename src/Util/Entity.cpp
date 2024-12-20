#include "Entity.h"

glm::mat4 Entity::getModelMatrix()
{
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, position);

	model = glm::rotate(model, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

	return model;
}
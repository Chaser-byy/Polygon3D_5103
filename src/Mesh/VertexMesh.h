#pragma once
#ifndef _VERTEXMESH_H
#define _VERTEXMESH_H

#include "../Util/glm.h"

struct VertexMesh
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texcoord;
};
#endif

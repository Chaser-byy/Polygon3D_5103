#pragma once
#ifndef _MESH_H
#define _MESH_H

#include <vector>

#include "TextureMesh.h"
#include "VertexMesh.h"

#include "../Shader/Shader.h"

using std::vector;

class Mesh
{
public:
	vector<VertexMesh> mVertices;
	vector<TextureMesh> mTextures;
	vector<unsigned int> mIndices;

	Mesh(vector<VertexMesh> vertices, vector<TextureMesh> textures, vector<unsigned int> indices);

	void Draw(Shader& shader);
private:
	unsigned int VAO, EBO, VBO;

	void setMesh();
};

#endif 

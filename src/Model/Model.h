#pragma once
#ifndef _MODEL_H
#define _MODEL_H

#include "../Mesh/Mesh.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <stbi/stb_image.h>

#include <iostream>

class Model
{
public:
	Model(const std::string& path);
	
	void Draw(Shader& Shader);

private:
	vector<Mesh> mMeshes;
	std::string directory;

	void loadModel(const std::string& path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	vector<TextureMesh> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
};

#endif

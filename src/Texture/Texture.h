#pragma once
#ifndef _TEXTURE_H
#define _TEXTURE_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <STBI/stb_image.h>
#include <vector>
#include <iostream>

using std::vector;

enum class TextureType
{

};

class Texture
{
public:
	unsigned int id;
	Texture(const vector<std::string> &dataPath)
	{
		glGenTextures(1, &id);
	}

	void use()
	{
		glBindTexture(GL_TEXTURE_2D, id);
	}

	void loadData()
	{

	}
};

class SkyboxTexture : public Texture
{
public:
	SkyboxTexture(const vector<std::string> &dataPath) : Texture(dataPath)
	{
		glBindTexture(GL_TEXTURE_2D, id);
		int width, height, nrChannels;
		for (unsigned int i = 0; i < dataPath.size(); ++i)
		{
			unsigned char* data = stbi_load(dataPath[i].c_str(), &width, &height, &nrChannels, 0);
			if (data)
			{
				glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
					0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data
				);
			}
			else
			{
				std::cout << "ERROR::TEXTURE::FAIL_TO_LOAD_FILE:: " << dataPath[i] << std::endl;
			}
			stbi_image_free(data);
		}
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
};

class CubeTexture : public Texture
{
public:
	CubeTexture(const vector<std::string> &dataPath) : Texture(dataPath)
	{
		glBindTexture(GL_TEXTURE_2D, id);
		int width, height, nrChannels;
		for (unsigned int i = 0; i < dataPath.size(); ++i)
		{
			unsigned char* data = stbi_load(dataPath[i].c_str(), &width, &height, &nrChannels, 0);
			if (data)
			{
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
				glGenerateMipmap(id);
			}
			else
			{
				std::cout << "ERROR::TEXTURE::FAIL_TO_LOAD_FILE:: " << dataPath[i] << std::endl;
			}
			stbi_image_free(data);
		}
		glBindTexture(GL_TEXTURE_2D, id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
};
#endif

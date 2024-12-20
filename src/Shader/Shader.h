#pragma once
#ifndef _SHADER_H
#define _SHADER_H

#include "..\Util\NonCopyable.h"

#include "..\Util\glm.h"

#include <string>

enum class UniformType
{
	INT,
	FLOAT,
	MAT4
};

class Shader : public NonCopyable
{
public:
	Shader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
	~Shader();

	void use();

	void setUniform(const std::string& name, int value,     UniformType uniformType = UniformType::INT) const;
	void setUniform(const std::string& name, float value,	UniformType uniformType = UniformType::FLOAT) const;
	void setUniform(const std::string& name, glm::mat4 mat, UniformType uniformType = UniformType::MAT4) const;

protected:
	unsigned int id;

};


#endif

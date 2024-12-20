#include "Shader.h"

#include "ShaderGenerator.h"

#include <iostream>

Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
	id = genShader(vertexShaderPath, fragmentShaderPath);
	use();
}

Shader::~Shader()
{
	glDeleteProgram(id);
}

void Shader::use()
{
    glUseProgram(id);
}

void Shader::setUniform(const std::string& name, int value, UniformType uniformType) const
{
	if (uniformType != UniformType::INT)
	{
		std::cout << "ERROR::SHADER::SET_UNIFORM_TYPE_ERROR::INT_EXPECTED" << std::endl;
	}
	else glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::setUniform(const std::string& name, float value, UniformType uniformType) const
{
	if (uniformType != UniformType::FLOAT)
	{
		std::cout << "ERROR::SHADER::SET_UNIFORM_TYPE_ERROR::FLOAT_EXPECTED" << std::endl;
	}
	glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}


void Shader::setUniform(const std::string& name, glm::mat4 mat, UniformType uniformType) const  
{
	if (uniformType != UniformType::MAT4)
	{
		std::cout << "ERROR::SHADER::SET_UNIFORM_TYPE_ERROR::MAT4_EXPECTED" << std::endl;
	}
	glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}


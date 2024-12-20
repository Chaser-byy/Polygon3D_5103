#include "ShaderGenerator.h"

#include "..\Util\FileUtil.h"

#include <iostream>

namespace
{
	unsigned int compileShader(unsigned int shaderType, const std::string& source)
	{
		unsigned int shaderID = glCreateShader(shaderType);
		const char* src = source.c_str();
		glShaderSource(shaderID, 1, &src, nullptr);
		glCompileShader(shaderID);
		//get shader_compilation status
		int success;
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
		//deal with error
		if (success == GL_FALSE)
		{
			std::string typeString = shaderType == GL_VERTEX_SHADER ? "VERTEX_SHADER" : "FRAGMENT_SHADER";
			//get info log length
			int length;
			glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)alloca(length * sizeof(char));
			glGetShaderInfoLog(shaderID, length, &length, message);
			//print info log
			std::cout << "ERROR::SHADER::" << typeString << "::COMPILATION_FAILED" << std::endl;
			std::cout << message << std::endl;
			//delete error shader
			glDeleteShader(shaderID);
			
			return 0;
		}

		return shaderID;
	}
}

unsigned int genShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
	unsigned int shader = glCreateProgram();

    std::string   vertexShaderSource = getFileContent(  vertexShaderPath);
    std::string fragmentShaderSource = getFileContent(fragmentShaderPath);

    unsigned int fragmentShaderID = compileShader(  GL_VERTEX_SHADER,   vertexShaderSource);
    unsigned int   vertexShaderID = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

	glAttachShader(shader,   vertexShaderID);
	glAttachShader(shader, fragmentShaderID);

	glLinkProgram(shader);

	glDeleteShader(  vertexShaderID);
	glDeleteShader(fragmentShaderID);

	return shader;
}


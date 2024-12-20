#pragma once
#ifndef _SHADERGENERATOR_H
#define _SHADERGENERATOR_H

#include <string> 
#include <glad/glad.h>
#include <GLFW/glfw3.h>


unsigned int genShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);

#endif

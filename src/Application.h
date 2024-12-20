#pragma once
#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Util/Config.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

//#include "Control/Mouse/Mouse.h"

#include "Mesh/Mesh.h"
#include "Model/Model.h"

#include "Camera/Camera.h"
#include "Texture/Texture.h"

#include "Util/glm.h"

class Application
{
public:
	Application();
	~Application();
	
	void runloop();

private:
	GLFWwindow* window;
	const Config config;
	Camera camera;

	//Mouse mouse;
};

#endif

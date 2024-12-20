#pragma once
#ifndef _MOUSE_H
#define _MOUSE_H

#include <functional>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../../Util/NonCopyable.h"

class Mouse : public NonCopyable
{
	friend void mouseCallback(GLFWwindow* window, double x, double y);
public:
	Mouse(GLFWwindow* window);

	float getXoffset() const;
	float getYoffset() const;

private:
	static float	lastX , 
					lastY ;
	static float xOffset, yOffset;
	static bool firstMouse;
	static float Sensitivity;
};

#endif

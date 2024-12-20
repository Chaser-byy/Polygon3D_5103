#include "Mouse.h"

bool Mouse::firstMouse = true;
float Mouse::lastX = 1280 / 2;
float Mouse::lastY = 960 / 2;
float Mouse::Sensitivity = 0.05;

void mouseCallback(GLFWwindow* window, double xpos, double ypos)
{
	if (Mouse::firstMouse)
	{
		Mouse::lastX = xpos;
		Mouse::lastY = ypos;
		Mouse::firstMouse = false;
	}
	Mouse::xOffset = xpos - Mouse::lastX;
	Mouse::yOffset = Mouse::lastY - ypos;
}


Mouse::Mouse(GLFWwindow* window)
{
	glfwSetCursorPosCallback(window, mouseCallback);
}

float Mouse::getXoffset() const
{
	return Mouse::xOffset * Mouse::Sensitivity;
}

float Mouse::getYoffset() const
{
	return Mouse::yOffset * Mouse::Sensitivity;
}

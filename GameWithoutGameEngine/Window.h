#pragma once
#include <GL\glew.h>
#include <glfw3.h>
class Window
{
private:
	GLFWwindow* _window;
	unsigned int counter;
public:
	Window(int windowWidth, int windowHeight, bool setCurrentContext, bool enableZIndex);
	GLFWwindow* getWindow() const;
	void displayFrameRate();
};
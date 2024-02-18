#pragma once
#include "Includes.h"

class Window
{
private:
	GLFWwindow* _window;
	unsigned int counter;
public:
	int windowWidth;
	int windowHeight;

	Window(int windowWidth, int windowHeight, bool setCurrentContext, bool enableZIndex);
	GLFWwindow* getWindow() const;
	void displayFrameRate();
};
#include "Window.h"

Window::Window(int windowWidth, int windowHeight, bool setCurrentContext, bool enableZIndex) : windowHeight(windowHeight), windowWidth(windowWidth)
{
	counter = 0;
	if (!glfwInit())
	{
		throw "Failed to intialize GLFW";
		glfwTerminate();
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	this->_window = glfwCreateWindow(windowWidth, windowHeight, "GameWithoutGameEngine", NULL, NULL);
	if (this->_window == NULL)
	{
		throw "Failed to create GLFW window";
		glfwTerminate();
	}
	if (setCurrentContext)
	{
		glfwMakeContextCurrent(this->_window);
	}
	glfwSwapInterval(25);
	glViewport(0, 0, windowWidth, windowHeight);

	if (glewInit())
	{
		throw"Failed to intialize GLEW";
		glfwTerminate();
	}
	if (enableZIndex)
	{
		glEnable(GL_DEPTH_TEST);
	}
}

GLFWwindow* Window::getWindow() const
{
	return this->_window;
}

void Window::displayFrameRate()
{
	double prevTime = 0.0;
	double currTime = 0.0;
	double timeDiff;

	currTime = glfwGetTime();
	timeDiff = currTime - prevTime;
	counter++;
	if (timeDiff >= 1.0 / 30.0)
	{
		std::string fps = std::to_string((1.0 / timeDiff) * counter);
		std::string ms = std::to_string((timeDiff / counter) * 1000);
		glfwSetWindowTitle(this->_window, (fps + " FPS, " + ms + " MS").c_str());
	}
}
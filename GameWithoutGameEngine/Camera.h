#pragma once
#include "Includes.h"
#include "ShaderProgram.h"
#include "Window.h"

class Camera
{
private:
	bool firstClick = true;
public:
	glm::vec3 position;
	glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

	int width;
	int height;
	float speed = 0.01f;
	float sensitivity = 100.f;

	Camera(int width, int height, glm::vec3 position);
	void matrix(float FOVdeg, float nearPlane, float faarPlane, ShaderProgram& shader, std::string uniform);
	void inputs(Window& window);
};

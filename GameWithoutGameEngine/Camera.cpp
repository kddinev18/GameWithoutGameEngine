#include "Camera.h"

Camera::Camera(int width, int height, glm::vec3 position) : width(width), height(height), position(position) {}


void Camera::matrix(float FOVdeg, float nearPlane, float faarPlane, ShaderProgram& shader, std::string uniform)
{
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(position, position + orientation, up);
	projection = glm::perspective(glm::radians(FOVdeg), (float)(width/height), nearPlane, faarPlane);

	shader.setMat4(uniform, projection * view);
}

void Camera::inputs(Window& window)
{
	GLFWwindow* glwindow = window.getWindow();
	if (glfwGetKey(glwindow, GLFW_KEY_W))
	{
		position += speed * orientation;
	}
	if (glfwGetKey(glwindow, GLFW_KEY_A))
	{
		position += speed * -glm::normalize(glm::cross(orientation, up));
	}
	if (glfwGetKey(glwindow, GLFW_KEY_S))
	{
		position += speed * -orientation;
	}
	if (glfwGetKey(glwindow, GLFW_KEY_D))
	{
		position += speed * glm::normalize(glm::cross(orientation, up));
	}


	if (glfwGetKey(glwindow, GLFW_KEY_SPACE))
	{
		position += speed * up;
	}
	if (glfwGetKey(glwindow, GLFW_KEY_LEFT_SHIFT))
	{
		position += speed * -up;
	}


	if (glfwGetKey(glwindow, GLFW_KEY_LEFT_CONTROL))
	{
		speed = 0.05f;
	}
	else if (!glfwGetKey(glwindow, GLFW_KEY_LEFT_CONTROL))
	{
		speed = 0.01f;
	}





	if (glfwGetMouseButton(glwindow, GLFW_MOUSE_BUTTON_LEFT))
	{
		// Hides mouse cursor
		glfwSetInputMode(glwindow, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		// Prevents camera from jumping on the first click
		if (firstClick)
		{
			glfwSetCursorPos(glwindow, (width / 2), (height / 2));
			firstClick = false;
		}

		// Stores the coordinates of the cursor
		double mouseX;
		double mouseY;
		// Fetches the coordinates of the cursor
		glfwGetCursorPos(glwindow, &mouseX, &mouseY);

		// Normalizes and shifts the coordinates of the cursor such that they being in the middle of the screen
		// and then "transforms" them into degrees 
		float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
		float rotY = sensitivity * (float)(mouseX - (height / 2)) / height;

		// Calculates upcoming vertical change in the Orientation
		glm::vec3 newOrientation = glm::rotate(orientation, glm::radians(-rotX), glm::normalize(glm::cross(orientation, up)));

		// Decides whether or not the next vertical Orientation is legal or not
		if (abs(glm::angle(newOrientation, up) - glm::radians(90.0f)) <= glm::radians(85.0f))
		{
			orientation = newOrientation;
		}

		// Rotates the Orientation left and right
		orientation = glm::rotate(orientation, glm::radians(-rotY), up);

		// Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
		glfwSetCursorPos(glwindow, (width / 2), (height / 2));
	}
	else if (!glfwGetMouseButton(glwindow, GLFW_MOUSE_BUTTON_LEFT))
	{
		// Unhides cursor since camera is not looking around anymore
		glfwSetInputMode(glwindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		// Makes sure the next time the camera looks around it doesn't jump
		firstClick = true;
	}
}
#include <GLFW/glfw3.h>
#include "GameWithoutGameEngine.h"

int main()
{
    GLFWInit();
    int width = 800;
    int height = 800;
    GLFWwindow* window = glfwCreateWindow(width, height,"Hello Window", NULL, NULL);
    if (window != NULL)
    {
        glfwMakeContextCurrent(window);
        glViewport(0, 0, width, height);
        while (!glfwWindowShouldClose(window))
        {

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
    else
    {
        glfwTerminate();
        return -1;
    }

    glfwTerminate();
    return 0;
}

void GLFWInit()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

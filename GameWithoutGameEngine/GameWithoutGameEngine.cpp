#include <GLFW/glfw3.h>
#include "GameWithoutGameEngine.h"

int main()
{
    GLFWInit();
    GLFWwindow* window = glfwCreateWindow(800,800,"Hello Window", NULL, NULL);
    if (window != NULL)
    {
        glfwMakeContextCurrent(window);
        
    }
    else
    {
        glfwTerminate();
        return -1;
    }

    return 0;
}

void GLFWInit()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

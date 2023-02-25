#include <GL\glew.h>
#include <glfw3.h>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include "ShaderProgram.h"
#include "FragmentShader.h"
#include "VertexShader.h"
#include "ErrorHandling.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Renderer.h"


bool intialiseWindow(GLFWwindow* &window, int windowWidth, int windowHeight)
{
    if (!glfwInit())
    {
        std::cout << "Failed to intialize GLFW" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(windowWidth, windowHeight, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(25);
    glViewport(0, 0, windowWidth, windowHeight);

    if (glewInit())
    {
        std::cout << "Failed to intialize GLEW" << std::endl;
        glfwTerminate();
        return false;
    }

    return true;
}

int main()
{
    GLFWwindow* window;
    intialiseWindow(window, 600, 600);

    ShaderProgram shaderProgram;
    Renderer renderer;

    float vertices[] = {
         0.0f ,  0.0f ,  0.0f,    1.0f, 0.0f, 0.0f, //a
         0.5f ,  0.0f ,  0.0f,    1.0f, 1.0f, 0.0f, //b
         0.45f,  0.20f,  0.0f,    1.0f, 0.0f, 1.0f, //1
         0.35f,  0.35f,  0.0f,    1.0f, 1.0f, 1.0f, //i
         0.20f,  0.45f,  0.0f,    0.0f, 1.0f, 0.0f, //j
         0.0f ,  0.5f ,  0.0f,    1.0f, 1.0f, 0.0f, //d
        -0.20f,  0.45f,  0.0f,    0.0f, 1.0f, 1.0f, //l
        -0.35f,  0.35f,  0.0f,    1.0f, 1.0f, 1.0f, //g
        -0.45f,  0.20f,  0.0f,    0.0f, 0.0f, 1.0f, //o
        -0.5f ,  0.0f ,  0.0f,    1.0f, 0.0f, 1.0f, //e
        -0.45f, -0.20f,  0.0f,    0.0f, 1.0f, 1.0f, //p
        -0.35f, -0.35f,  0.0f,    1.0f, 1.0f, 1.0f, //h
        -0.20f, -0.45f,  0.0f,    1.0f, 0.0f, 0.0f, //k
         0.0f , -0.5f ,  0.0f,    1.0f, 1.0f, 0.0f, //c
         0.20f, -0.45f,  0.0f,    1.0f, 0.0f, 1.0f, //m
         0.35f, -0.35f,  0.0f,    1.0f, 1.0f, 1.0f, //f
         0.45f, -0.20f,  0.0f,    0.0f, 1.0f, 0.0f, //n
    };
    unsigned int indices[] = {
        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        0, 4, 5,

        0, 5, 6,
        0, 6, 7,
        0, 7, 8,
        0, 8, 9,

        0, 9, 10,
        0, 10, 11,
        0, 11, 12,
        0, 12, 13,

        0, 13, 14,
        0, 14, 15,
        0, 15, 16,
        0, 16, 1,
    };

    VertexArray VAO;
    VertexBuffer VBO(vertices, sizeof(vertices), GL_STATIC_DRAW);
    IndexBuffer EBO(indices, int(sizeof(indices)/sizeof(float)));

    VertexBufferLayout VBL;
    VBL.push<float>(3, false);
    VBL.push<float>(3, false);
    VAO.addBuffer(VBO, VBL);

    while (!glfwWindowShouldClose(window))
    {
        renderer.clear();

        renderer.draw(VAO, EBO, shaderProgram);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    

    glfwTerminate();
    return 0;
}

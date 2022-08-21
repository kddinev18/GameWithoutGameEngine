#include <GL\glew.h>
#include <glfw3.h>
#include <iostream>
#include <string>
#include "Shader.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

std::string vertexShaderSourcePath = "Shaders\\VertextShader.txt";
std::string fragmentShaderSourcePath = "Shaders\\FragmentShader.txt";

void processInput(GLFWwindow* window, float* vertices);
void moveUp(float* vertices);

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    Shader* shader = new Shader(vertexShaderSourcePath, fragmentShaderSourcePath);


    float vertices[] = {
        // positions         // colors
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
    };

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    while (!glfwWindowShouldClose(window))
    {
        processInput(window, vertices);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader->use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    delete shader;
    return 0;
}

void processInput(GLFWwindow* window, float* vertices)
{
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        moveUp(vertices);
}

void moveUp(float* vertices)
{
    for (size_t i = 0; i < 9; i = i + 3)
    {
        if (vertices[i + 1] != 0)
        {
            vertices[i + 1] += 0.1f;
            if (vertices[i + 1] > 1)
            {
                vertices[i + 1] = 1;
            }
        }
    }
}

void moveDown(float* vertices)
{

}

void moveRight(float* vertices)
{

}

void moveLeft(float* vertices)
{

}

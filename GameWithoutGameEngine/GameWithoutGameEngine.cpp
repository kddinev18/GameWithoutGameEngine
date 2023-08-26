#include <GL\glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
#include "Texture.h"


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

    window = glfwCreateWindow(windowWidth, windowHeight, "GameWithoutGameEngine", NULL, NULL);
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
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    VertexArray VAO;
    VertexBuffer VBO(vertices, sizeof(vertices), GL_STATIC_DRAW);
    IndexBuffer EBO(indices, int(sizeof(indices)/sizeof(float)));

    VertexBufferLayout VBL;
    VBL.push<float>(3, false);
    VBL.push<float>(3, false);
    VBL.push<float>(2, false);
    VAO.addBuffer(VBO, VBL);

    Texture texture("test.png");
    texture.Bind(0);
    shaderProgram.setInt("Texture", 0);

    while (!glfwWindowShouldClose(window))
    {
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
        trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
        shaderProgram.setMat4("transform", trans);

        renderer.clear();

        renderer.draw(VAO, EBO, shaderProgram);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

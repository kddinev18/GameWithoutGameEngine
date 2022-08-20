#include <GL\glew.h>
#include <glfw3.h>
unsigned int setUpVertexBufferObjects(float* vertices)
{
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

    return VBO;
}

unsigned int setUpVertexShader(const char* vertexShaderSource)
{
    
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    return vertexShader;
}

unsigned int setUpFragmenShader(const char* fragmentShaderSource)
{

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    return fragmentShader;
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    int width = 800;
    int height = 800;
    GLFWwindow* window = glfwCreateWindow(width, height,"Hello Window", NULL, NULL);
    if (window != NULL)
    {
        glfwMakeContextCurrent(window);
        glewInit();

        unsigned int VBO = setUpVertexBufferObjects(new float [] {
            -0.5f, -0.5f, 0.0f,
                0.5f, -0.5f, 0.0f,
                0.0f, 0.5f, 0.0f
            });
        unsigned int vertexShader = setUpVertexShader(
            "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\0");
        unsigned int fragmentShader = setUpFragmenShader(
            "#version 330 core\n"
            "out vec4 FragColor;\n"
            "void main()\n"
            "{\n"
            "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
            "}\0");
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
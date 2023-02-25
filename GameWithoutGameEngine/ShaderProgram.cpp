#include "ShaderProgram.h"
#include "FragmentShader.h"
#include "VertexShader.h"
#include <GL/glew.h>
#include <iostream>

unsigned int ShaderProgram::compileShader(const std::string& sourceCode, unsigned int type)
{
    unsigned int id = glCreateShader(type);
    const char* src = sourceCode.c_str();
    glShaderSource(id, 1, &src, NULL);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int lenght;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);
        char* message = new char[lenght];
        glGetShaderInfoLog(id, lenght, &lenght, message);
        std::cout << "Shader compilation failed ";
        std::cout << (type == GL_VERTEX_SHADER ? "vertex " : "fragment ");
        std::cout << message << std::endl;
        delete[] message;
        glDeleteShader(id);
        return NULL;
    }

    return id;
}

ShaderProgram::ShaderProgram()
{
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(vertexShader, GL_VERTEX_SHADER);
    unsigned int fs = compileShader(fragmentShader, GL_FRAGMENT_SHADER);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    id = program;
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(id);
}

void ShaderProgram::use() const
{
    glUseProgram(id);
}

void ShaderProgram::setBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}
void ShaderProgram::setInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}
void ShaderProgram::setFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}

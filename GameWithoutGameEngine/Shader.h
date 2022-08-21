#pragma once
#include <GL/glew.h> // include glad to get all the required OpenGL headers

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader
{
private:
    unsigned int ID;
public:
    Shader(std::string vertexPath, std::string fragmentPath);
    ~Shader();
    void use();
    void setBool(const std::string& name, bool value);
    void setInt(const std::string& name, int value);
    void setFloat(const std::string& name, float value);
};
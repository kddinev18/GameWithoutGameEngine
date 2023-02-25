#pragma once
#include <string>

const std::string fragmentShader = R"glsl(
    #version 330 core
    out vec4 FragColor;
  
    in vec4 vertexColor;

    void main()
    {
        FragColor = vertexColor;
    } 
)glsl";
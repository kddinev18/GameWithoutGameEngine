#pragma once
#include <string>

const std::string fragmentShader = R"glsl(
    out vec4 FragColor;
  
    in vec3 ourColor;
    in vec2 TexCoord;

    uniform sampler2D Texture;

    void main()
    {
        FragColor = texture(Texture, TexCoord) * vec4(ourColor, 1.0);
    }
)glsl";
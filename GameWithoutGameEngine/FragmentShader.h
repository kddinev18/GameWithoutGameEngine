#pragma once
#include <string>

const std::string fragmentShader = R"glsl(
    out vec4 FragColor;

    in vec2 TexCoord;

    uniform sampler2D Texture;

    void main()
    {
        FragColor = texture(Texture, TexCoord) * vec4(0.5f,0.2f,0.2f,1.0f);
    }
)glsl";
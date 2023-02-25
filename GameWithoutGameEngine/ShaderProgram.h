#pragma once
#include <string>

class ShaderProgram
{
private:

    unsigned int id;
    unsigned int compileShader(const std::string& sourceCode, unsigned int type);

public:

    ShaderProgram();
    ~ShaderProgram();
    void use() const;
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
};
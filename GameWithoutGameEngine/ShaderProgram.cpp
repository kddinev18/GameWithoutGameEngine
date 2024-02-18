#include "ShaderProgram.h"
#include "FragmentShader.h"
#include "VertexShader.h"
#include "ErrorHandling.h"

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
    use();
    glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}
void ShaderProgram::setInt(const std::string& name, int value) const
{
    use();
    glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}
void ShaderProgram::setFloat(const std::string& name, float value) const
{
    use();
    glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}
void ShaderProgram::setVec2(const std::string& name, const glm::vec2& value) const
{
    use();
    glUniform2fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
}
void ShaderProgram::setVec2(const std::string& name, float x, float y) const
{
    use();
    glUniform2f(glGetUniformLocation(id, name.c_str()), x, y);
}
void ShaderProgram::setVec3(const std::string& name, const glm::vec3& value) const
{
    use();
    glUniform3fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
}
void ShaderProgram::setVec3(const std::string& name, float x, float y, float z) const
{
    use();
    glUniform3f(glGetUniformLocation(id, name.c_str()), x, y, z);
}
void ShaderProgram::setVec4(const std::string& name, const glm::vec4& value) const
{
    use();
    glUniform4fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
}
void ShaderProgram::setVec4(const std::string& name, float x, float y, float z, float w) const
{
    use();
    glUniform4f(glGetUniformLocation(id, name.c_str()), x, y, z, w);
}
void ShaderProgram::setMat2(const std::string& name, const glm::mat2& mat) const
{
    use();
    glUniformMatrix2fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
void ShaderProgram::setMat3(const std::string& name, const glm::mat3& mat) const
{
    use();
    glUniformMatrix3fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
void ShaderProgram::setMat4(const std::string& name, const glm::mat4& mat) const
{
    use();
    glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

unsigned int ShaderProgram::getId() const
{
    return id;
}

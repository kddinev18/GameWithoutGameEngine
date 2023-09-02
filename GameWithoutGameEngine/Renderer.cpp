#include "Renderer.h"

void Renderer::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw(const VertexArray& VAO, const IndexBuffer& EBO, const ShaderProgram& shader) const
{
    shader.use();
    VAO.bind();
    EBO.bind();

    glDrawElements(GL_TRIANGLES, EBO.getCount(), GL_UNSIGNED_INT, 0);
}

void Renderer::draw(const VertexArray& VAO, const ShaderProgram& shader, unsigned int count) const
{
    shader.use();
    VAO.bind();

    glDrawArrays(GL_TRIANGLES, 0, count);
}
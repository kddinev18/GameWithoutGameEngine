#include "VertexBuffer.h"
#include <GL/glew.h>

VertexBuffer::VertexBuffer(const void* data, unsigned int size, unsigned int drawType)
{
    glGenBuffers(1, &vertexBufferId);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
    glBufferData(GL_ARRAY_BUFFER, size, data, drawType);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &vertexBufferId);
}

void VertexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
}

void VertexBuffer::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

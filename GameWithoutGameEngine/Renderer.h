#pragma once
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "ShaderProgram.h"
class Renderer
{
public:
	void clear() const;
	void draw(const VertexArray& VAO, const IndexBuffer& EBO, const ShaderProgram& program) const;
};
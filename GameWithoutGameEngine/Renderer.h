#pragma once
#include "Includes.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "ShaderProgram.h"
class Renderer
{
public:
	void clear() const;
	void draw(const VertexArray& VAO, const IndexBuffer& EBO, const ShaderProgram& program) const;
	void draw(const VertexArray& VAO, const ShaderProgram& shader, unsigned int count) const;
};
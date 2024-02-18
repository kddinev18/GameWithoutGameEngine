#pragma once
#include "Includes.h"

class VertexBuffer
{
private:
	unsigned int vertexBufferId;
public:
	VertexBuffer(const void* data, unsigned int size, unsigned int drawType);
	~VertexBuffer();

	void bind() const;
	void unbind() const;
};
#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &vertexArrayId);
	glBindVertexArray(vertexArrayId);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &vertexArrayId);
}

void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	vb.bind();
	const std::vector<Layout>& layouts = layout.getLayout();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < layouts.size(); i++)
	{
		const Layout& element = layouts[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.normalized ? GL_TRUE : GL_FALSE, layout.getStride(), (void*)offset);
		offset += element.count * Layout::GetSizeOfType(element.type);
	}
}

void VertexArray::bind() const
{
	glBindVertexArray(vertexArrayId);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}

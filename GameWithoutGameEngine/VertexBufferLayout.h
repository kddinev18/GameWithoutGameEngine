#pragma once
#include "Includes.h"

struct Layout
{
	unsigned int type;
	unsigned int count;
	bool normalized;

	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT: return 4;
		case GL_UNSIGNED_INT: return 4;
		case GL_UNSIGNED_BYTE: return 1;
		default: throw;
		}
	}
};

class VertexBufferLayout
{
private:
	std::vector<Layout> layouts;
	unsigned int stride;
public:
	VertexBufferLayout()
	{
		stride = 0;
	}

	template<typename T>
	void push(unsigned int count, bool normalized);

	template<>
	void push<float>(unsigned int count, bool normalized)
	{
		Layout layout { GL_FLOAT, count, normalized };
		layouts.push_back(layout);
		stride += Layout::GetSizeOfType(GL_FLOAT) * count;
	}

	template<>
	void push<unsigned int>(unsigned int count, bool normalized)
	{
		Layout layout{ GL_UNSIGNED_INT, count, normalized };
		layouts.push_back(layout);
		stride += Layout::GetSizeOfType(GL_UNSIGNED_INT) * count;
	}

	template<>
	void push<unsigned char>(unsigned int count, bool normalized)
	{
		Layout layout{ GL_UNSIGNED_BYTE, count, normalized };
		layouts.push_back(layout);
		stride += Layout::GetSizeOfType(GL_UNSIGNED_BYTE) * count;
	}

	inline const std::vector<Layout> getLayout() const& { return layouts; };
	inline unsigned int getStride() const { return stride; };
};
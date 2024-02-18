#pragma once
#include "Includes.h"

class Texture
{
private:
	unsigned int textureId;
	std::string filePath;
	unsigned char* localBuffer;
	int width, height, bytesPerPixel;

public:
	Texture(const std::string& path);
	~Texture();
	void Bind(unsigned int slots = 0) const;
	void Unbind() const;

	inline int GetWidth() const { return width; }
	inline int GetHeight() const { return height; }
};
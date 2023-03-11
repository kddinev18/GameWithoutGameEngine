#include "Texture.h"
#include <GL\glew.h>
#include <glfw3.h>
#include "stb_image.h"
Texture::Texture(const std::string& path) : filePath(path)
{
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);

	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(1);
	localBuffer = stbi_load(path.c_str(), &width, &height, &bytesPerPixel, 0);
	if (localBuffer)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	if (localBuffer)
		stbi_image_free(localBuffer);
}

Texture::~Texture()
{
	glDeleteTextures(1, &textureId);
}

void Texture::Bind(unsigned int slots) const
{
	glActiveTexture(GL_TEXTURE0 + slots);
	glBindTexture(GL_TEXTURE_2D, textureId);
}

void Texture::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

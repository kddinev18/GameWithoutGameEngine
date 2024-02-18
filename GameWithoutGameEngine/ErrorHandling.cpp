#include "ErrorHandling.h"

void glClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool glCheckError(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << "Error: " << error << std::endl;
        std::cout << "Funcrion: " << function << " " << line << " " << file << std::endl;
        return false;
    }
    return true;
}

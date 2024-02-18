#pragma once
#include "Includes.h"

#define ASSERT(x) if(!(x)) __debugbreak();
#define glTryCall(x) glClearError();\
    x;\
    ASSERT(glCheckError(#x, __FILE__, __LINE__))

void glClearError();
bool glCheckError(const char* function, const char* file, int line);
#pragma once

#include <iostream>

#include "GL/glew.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearErrors(); x; ASSERT(GLCheckError(#x, __FILE__, __LINE__));

void GLClearErrors();
bool GLCheckError(const char* function, const char* file, int line);


class Renderer {
public:
	void Draw(const VertexArray& vao, const IndexBuffer& ibo, const Shader& shader) const;
	void Clear() const;
};
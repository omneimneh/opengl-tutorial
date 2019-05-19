#include "Renderer.h"

void GLClearErrors() {
	while (glGetError() != GL_NO_ERROR);
}

bool GLCheckError(const char* function, const char* file, int line) {
	bool flag = true;
	while (GLenum error = glGetError())
	{
		std::cout << std::endl;
		std::cout << "[OPENGL ERROR] error code: " << error << "\n" << function << " " << file << ":" << line << std::endl;
		std::cout << std::endl;
		flag = false;
	}
	return flag;
}

void Renderer::Draw(const VertexArray& vao, const IndexBuffer& ibo, const Shader& shader) const
{
	vao.Bind();
	ibo.Bind();
	shader.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear() const
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

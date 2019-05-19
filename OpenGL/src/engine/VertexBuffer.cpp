#include "VertexBuffer.h"
#include "Renderer.h"


VertexBuffer::VertexBuffer(void* bufferData, int bufferSize)
{
	GLCall(glGenBuffers(1, &m_RendererId));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererId));
	GLCall(glBufferData(GL_ARRAY_BUFFER, bufferSize, bufferData, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_RendererId));
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererId);
}

void VertexBuffer::UnBind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

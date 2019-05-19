#pragma once

class VertexBuffer
{
private:
	unsigned int m_RendererId;
public:
	VertexBuffer(void* bufferData, int bufferSize);
	~VertexBuffer();

	void Bind() const;
	void UnBind() const;
};


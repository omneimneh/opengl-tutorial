#pragma once

#include "VertexBuffer.h"
#include "VertexLayout.h"

class VertexArray
{
private:
	unsigned int m_RendererId;
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vb, const VertexLayout& layout);

	void Bind() const;
	void UnBind() const;
};


#include "VertexArray.h"
#include "Renderer.h"

VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &m_RendererId));
}

VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1, &m_RendererId))
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexLayout& layout)
{
	Bind();
	vb.Bind();
	std::vector<LayoutAttribute> attributes = layout.GetAttributes();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < attributes.size(); i++)
	{
		const LayoutAttribute& attr = attributes[i];

		glEnableVertexAttribArray(i);
		GLCall(glVertexAttribPointer(i, attr.count, attr.type, attr.normalized, layout.GetStride(), (const void*) offset));

		offset += VertexLayout::SizeOfType(attr.type) * attr.count;
	}
}

void VertexArray::Bind() const
{
	GLCall(glBindVertexArray(m_RendererId));
}

void VertexArray::UnBind() const
{
	GLCall(glBindVertexArray(0));
}

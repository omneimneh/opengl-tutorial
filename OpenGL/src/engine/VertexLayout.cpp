#include "VertexLayout.h"
#include "Renderer.h"

VertexLayout::VertexLayout() : m_Stride(0)
{
}


VertexLayout::~VertexLayout()
{
}

void VertexLayout::Push(LayoutAttribute attr) {
	m_Attributes.push_back(attr);
	m_Stride += attr.count * SizeOfType(attr.type);
}

unsigned int VertexLayout::SizeOfType(unsigned int type) {
	switch (type)
	{
	case GL_FLOAT:
		return sizeof(float);
	case GL_UNSIGNED_INT:
		return sizeof(unsigned int);
	case GL_UNSIGNED_BYTE:
		return sizeof(char);
	}
	ASSERT(false);
	return 0;
}
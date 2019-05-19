#pragma once

#include <vector>

#include "LayoutAttribute.h"

class VertexLayout
{
	std::vector<LayoutAttribute> m_Attributes;
	unsigned int m_Stride;
public:
	VertexLayout();
	~VertexLayout();

	inline unsigned int GetStride() const { return m_Stride; };
	inline std::vector<LayoutAttribute> GetAttributes() const { return m_Attributes; };

	void Push(LayoutAttribute attr);

	static unsigned int SizeOfType(unsigned int type);
};


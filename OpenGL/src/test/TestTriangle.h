#pragma once
#include "Test.h"
#include "../engine/Renderer.h"
class TestTriangle :
	public Test
{
private: Renderer m_Renderer;
		 Shader shader;
		 IndexBuffer ibo;
		 VertexBuffer vbo;
		 VertexArray vao;
		 VertexLayout layout;
public:
	TestTriangle();
	~TestTriangle();

	void OnRender() override;
	void OnImGuiRender() override;
};


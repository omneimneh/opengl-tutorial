#pragma once
#include "Test.h"
#include "../engine/Renderer.h"
class TestRectangle :
	public Test
{
private: Renderer m_Renderer;
		 Shader shader;
		 IndexBuffer ibo;
		 VertexBuffer vbo;
		 VertexArray vao;
		 VertexLayout layout;
public:
	TestRectangle();
	~TestRectangle();

	void OnRender() override;
	void OnImGuiRender() override;
};


#pragma once
#include "Test.h"
#include "../engine/Renderer.h"
#include "../engine/Texture.h"
class TestTexture :
	public Test
{
private: Renderer m_Renderer;
		 Shader shader;
		 IndexBuffer ibo;
		 VertexBuffer vbo;
		 VertexArray vao;
		 VertexLayout layout;
		 Texture texture;
public:
	TestTexture();
	~TestTexture();

	void OnRender() override;
	void OnImGuiRender() override;
};


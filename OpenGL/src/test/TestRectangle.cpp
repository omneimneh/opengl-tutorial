#include "TestRectangle.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"

static float positions[]{
	-0.5f, -0.5f,
	 0.5f, -0.5f,
	 0.5f,  0.5f,
	-0.5f,  0.5f
};

static unsigned int indices[]{
	0, 1, 2, 2, 3, 0
};

TestRectangle::TestRectangle()
	: shader("src/shaders/basic.shader"),
	ibo(indices, 6),
	vbo(positions, 8 * sizeof(float))
{

	layout.Push({ GL_FLOAT, 2, false });
	vao.AddBuffer(vbo, layout);
}


TestRectangle::~TestRectangle()
{
}

void TestRectangle::OnRender()
{
	m_Renderer.Draw(vao, ibo, shader);
}

void TestRectangle::OnImGuiRender() {
	ImGui::Text("This test shows a white rectangle!");
}

#include "TestTriangle.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"

static float positions[]{
	-0.5f, -0.5f,
	 0.0f,  0.5f,
	 0.5f, -0.5f
};

static unsigned int indices[]{
	0, 1, 2
};

TestTriangle::TestTriangle()
	: shader("src/shaders/basic.shader"),
	ibo(indices, 3),
	vbo(positions, 6 * sizeof(float))
{

	layout.Push({ GL_FLOAT, 2, false });
	vao.AddBuffer(vbo, layout);
}


TestTriangle::~TestTriangle()
{
}

void TestTriangle::OnRender()
{
	m_Renderer.Draw(vao, ibo, shader);
}

void TestTriangle::OnImGuiRender() {
	ImGui::Text("Hello World OpenGL Triangle!");
}

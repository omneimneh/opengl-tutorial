#include "TestTexture.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"

static float positions[]{
	-0.5f, -0.5f, 0.0f, 0.0f,
	 0.5f, -0.5f, 1.0f, 0.0f,
	 0.5f,  0.5f, 1.0f, 1.0f,
	-0.5f,  0.5f, 0.0f, 1.0f
};

static unsigned int indices[]{
	0, 1, 2, 2, 3, 0
};

TestTexture::TestTexture()
	: shader("src/shaders/Texture2D.shader"),
	ibo(indices, 6),
	vbo(positions, 16 * sizeof(float)),
	texture("src/img/mclaren.png")
{
	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	layout.Push({ GL_FLOAT, 2, false });
	layout.Push({ GL_FLOAT, 2, false });
	vao.AddBuffer(vbo, layout);

	shader.Bind();
	texture.Bind(0);
	shader.SetUniform1i("u_Texture", 0);
}


TestTexture::~TestTexture()
{
}

void TestTexture::OnRender()
{
	m_Renderer.Draw(vao, ibo, shader);
}

void TestTexture::OnImGuiRender() {
	ImGui::Text("This test shows a mclaren!");
	ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
}

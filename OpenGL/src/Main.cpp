#include "engine/Renderer.h"
#include "engine/VertexBuffer.h"
#include "engine/IndexBuffer.h"
#include "engine/VertexLayout.h"
#include "engine/VertexArray.h"
#include "engine/Shader.h"

#include "GLFW/glfw3.h"

#include "test/TestMenu.h"
#include "test/TestRectangle.h"
#include "test/TestTriangle.h"
#include "test/TestTexture.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

int main() {
	GLFWwindow* window;

	if (!glfwInit()) return -1;

	window = glfwCreateWindow(640, 480, "OpenGL Series", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) return -1;


	{
		Renderer renderer;

		ImGui::CreateContext();
		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 130");

		Test* currentTest = nullptr;
		TestMenu* testMenu = new TestMenu(currentTest);
		testMenu->RegisterTest<TestTriangle>("Triangle Test");
		testMenu->RegisterTest<TestRectangle>("Rectangle Test");
		testMenu->RegisterTest<TestTexture>("Texture Test");
		currentTest = testMenu;

		while (!glfwWindowShouldClose(window))
		{
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			renderer.Clear();

			currentTest->OnRender();

			{
				ImGui::Begin("Navigator");

				if (currentTest != testMenu) {
					if (ImGui::Button("<-")) {
						delete currentTest;
						currentTest = testMenu;
					}
				}

				currentTest->OnImGuiRender();

				ImGui::End();
				ImGui::Render();
				ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
			}

			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		if (testMenu != currentTest) {
			delete currentTest;
			delete testMenu;
		}
		else {
			delete currentTest;
		}
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();


	return 0;
}
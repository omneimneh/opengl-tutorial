#include "TestMenu.h"

#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"


TestMenu::TestMenu(Test*& initial) : currentTest(initial)
{
}


TestMenu::~TestMenu()
{
}

void TestMenu::OnImGuiRender()
{
	for (const auto& test : m_Tests) {
		if (ImGui::Button(test.first.c_str())) {
			currentTest = test.second();
		}
	}
}

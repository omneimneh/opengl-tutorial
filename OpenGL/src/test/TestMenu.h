#pragma once

#include <string>
#include <vector>
#include <functional>

#include "Test.h"

class TestMenu : public Test
{
private:
	std::vector<std::pair<std::string, std::function<Test*()>>> m_Tests;
	Test*& currentTest;
public:
	TestMenu(Test*& initial);
	~TestMenu();
	
	template<typename T>
	void RegisterTest(const std::string& testName) {
		m_Tests.push_back(std::make_pair(testName, [] { return new T(); }));
	}

	void OnImGuiRender() override;
};


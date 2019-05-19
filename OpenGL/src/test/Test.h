#pragma once
class Test
{
public:
	Test();
	virtual ~Test();

	virtual void OnRender() {};
	virtual void OnUpdate(float deltaTime) {};
	virtual void OnImGuiRender() {};
};


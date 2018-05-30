#pragma once
#include "MyApplication.h"
class TestApplication :
	public MyApplication
{
public:
	TestApplication();
	~TestApplication();

	bool startup();
	void update(float deltaTime);
	void draw();
	void shutdown();

protected:
	glm::mat4 m_view;
	glm::mat4 m_projection;

	
};


#include "TestApplication.h"
#include <GLFW\glfw3.h>
#include <Gizmos.h>

using aie::Gizmos;
using glm::vec3;
using glm::vec4;

TestApplication::TestApplication()
{
	
}


TestApplication::~TestApplication()
{
}

bool TestApplication::startup()
{
	setBackgroundColour(0.4f, 0.3f, 0.6f);
	Gizmos::create(10000, 10000, 10000, 10000);
	
	m_view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	m_projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);

	return true;
}

void TestApplication::shutdown()
{
	Gizmos::destroy();
}

void TestApplication::update(float deltaTime)
{
	Gizmos::clear();

	for (int i = 0; i < 21; ++i) {
		Gizmos::addLine(vec3(-10 + i, 0, 10),
			vec3(-10 + i, 0, -10),
			i == 10 ? vec4(1) : vec4(0,0,0,1));
		Gizmos::addLine(vec3(10, 0, -10 + i),
			vec3(-10, 0, -10 + i),
			i == 10 ? vec4(1) : vec4(0, 0, 0, 1));
	}

	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE))
	{
		quit();
	}
}

void TestApplication::draw()
{
	Gizmos::draw(m_projection * m_view);
}



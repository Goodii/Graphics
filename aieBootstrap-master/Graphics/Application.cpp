#include "Application.h"
#include <stdio.h>
#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <Gizmos.h>


using glm::vec3;
using glm::vec4;
using glm::mat4;
using namespace aie;

bool Application::startup()
{
	if (glfwInit() == false)
		return -1;

	m_window = glfwCreateWindow(1280, 720, "Application", nullptr, nullptr);

	if (m_window == nullptr)
		glfwTerminate(); return -2;

	glfwMakeContextCurrent(m_window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return -3;
	}

	//check gl version
	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);

	Gizmos::create(10000, 10000, 10000, 10000);
	//set viewpoint
	m_view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	m_projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);

	glClearColor(0.35f, 0.35f, 0.35f, 1);
	glEnable(GL_DEPTH_TEST);
}

bool Application::update()
{
	while (glfwWindowShouldClose(m_window) == false && glfwGetKey(m_window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		// updates every frame
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Gizmos::clear();

		Gizmos::addTransform(mat4(1));

		vec4 white(1);
		vec4 black(0, 0, 0, 1);

		for (int i = 0; i < 21; ++i)
		{
			Gizmos::addLine(vec3(-10 + i, 0, 10),
				vec3(-10 + i, 0, -10),
				i == 10 ? white : black);

			Gizmos::addLine(vec3(10, 0, -10 + i),
				vec3(-10, 0, -10 + i),
				i == 10 ? white : black);
		}

		draw();

		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
}

void Application::draw()
{
	Gizmos::draw(m_projection * m_view);
}

void Application::shutdown()
{
	Gizmos::destroy();
	glfwDestroyWindow(m_window);
	//delete m_window;
	glfwTerminate();
}


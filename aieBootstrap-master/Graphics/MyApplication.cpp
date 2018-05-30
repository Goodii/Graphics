#include "MyApplication.h"
#include <stdio.h>
#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <Gizmos.h>


using glm::vec3;
using glm::vec4;
using glm::mat4;
using namespace aie;

MyApplication::MyApplication()
{
	m_gameRunning = true;
}

MyApplication::~MyApplication()
{
	
}

bool MyApplication::createWindow(const char* title, int width, int height, bool fullscreen)
{
	//check if glfw lib initialises
	if (glfwInit() == false)
		return false;
	//create window
	m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	//check for window
	if (m_window == nullptr)
		glfwTerminate(); return false;

	glfwMakeContextCurrent(m_window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return false;
	}

	//check gl version
	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);

	glEnable(GL_DEPTH_TEST);

	return true;
}

void MyApplication::destroyWindow()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void MyApplication::setBackgroundColour(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void MyApplication::run(const char* title, int width, int height, bool fullscreen)
{
	//check for succesful window and startup
	if (createWindow(title, width, height, fullscreen) && startup())
	{
		//time variables
		double prevTime = glfwGetTime();
		double currTime = 0;
		double deltaTime = 0;

		//while game is running loop
		while (m_gameRunning)
		{
			//update deltatime
			currTime = glfwGetTime();
			deltaTime = currTime - prevTime;
			prevTime = currTime;

			//clears screen
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			//call update
			update(deltaTime);

			//call draw
			draw();

			glfwSwapBuffers(m_window);
			glfwPollEvents();

			//ensure game should still be running
			m_gameRunning = m_gameRunning || glfwWindowShouldClose(m_window) == GLFW_TRUE;
		}

		//call shutdown
		shutdown();
		//destroy window
		destroyWindow();
	}
}


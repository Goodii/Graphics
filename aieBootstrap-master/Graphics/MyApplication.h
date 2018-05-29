#pragma once
#include <glm/glm.hpp>
#include <glm/ext.hpp>

class MyApplication
{
public:
	MyApplication();
	virtual ~MyApplication();

	void run(const char* title, int width, int height, bool fullscreen);

	bool startup();
	bool update();
	void draw();
	void shutdown();

protected:
	bool m_gameRunning;
	struct GLFWwindow* m_window;
	glm::mat4 m_view;
	glm::mat4 m_projection;
};
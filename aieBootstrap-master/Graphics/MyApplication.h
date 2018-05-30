#pragma once
#include <glm/glm.hpp>
#include <glm/ext.hpp>

class MyApplication
{
public:
	MyApplication();
	virtual ~MyApplication();

	void run(const char* title, int width, int height, bool fullscreen);

	virtual bool startup() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw() = 0;
	virtual void shutdown() = 0;

	void setBackgroundColour(float r, float g, float b, float a = 1.f);

protected:
	bool m_gameRunning;
	struct GLFWwindow* m_window;
	glm::mat4 m_view;
	glm::mat4 m_projection;

	bool createWindow(const char* title, int width, int height, bool fullscreen);
	void destroyWindow();
};
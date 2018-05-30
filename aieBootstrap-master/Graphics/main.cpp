#pragma once
#include "TestApplication.h"

int main()
{
	auto app = new TestApplication;
	app->run("Graphics", 1280, 720, false);

	delete app;
	return 0;
}
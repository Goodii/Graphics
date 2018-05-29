#pragma once
#include "MyApplication.h"

int main()
{
	MyApplication* app = new MyApplication();
	if (app->startup() == true)
	{
		while (app->update() == true)
			app->draw();
		app->shutdown();
	}

	delete app;
	return 0;
}
#pragma once
#include <iostream>
#include "vibdec.h"
#include "Application/Application.h"
#include "States/mainstate.h"

int main(int argc, char* argv[])
{
	Application* app = Application::Instance();

	app->pushState(Mainstate::Instance());
	while (app->running())
	{
		app->handleEvents();
		app->update();
		app->draw();
	}
	app->cleanup();

	return 0;
}

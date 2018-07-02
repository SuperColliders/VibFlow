#include "Application.h"
#include <iostream>
#include "State.h"

Application Application::application(1280, 720, "Vibflow");

void Application::initialize(uint width, uint height, const char * title)
{
	if (!glfwInit())
	{
		std::cout << "Glfw3 failed to initialize..." << std::endl;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_SAMPLES, 4);

	window = glfwCreateWindow(width, height, title, NULL, NULL);

	w = width;
	h = height;

	glfwMakeContextCurrent(window);

	glewExperimental = true;
	GLenum status = glewInit();
	if (status != GLEW_OK)
	{
		std::cout << "Glew failed to initialize - Cause: " << glewGetErrorString(status) << std::endl;
	}
	else
	{
		std::cout << "Glew initialized sucessfully - VERSION " << glewGetString(GLEW_VERSION) << std::endl;
	}

	glDepthFunc(GL_LESS);
	//glEnable(GL_FRAMEBUFFER_SRGB); Gama correction set to manual
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_DEPTH_TEST);

	isRunning = true;
}

Application::Application(uint width, uint height, const char* windowName)
{
	initialize(width, height, windowName);
}

void Application::cleanup()
{
	//CleanUp states
	while (!states.empty())
	{
		states.top()->cleanup();
		states.pop();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	isRunning = false;
}

void Application::changeState(State * state)
{
	if (!states.empty())
	{
		states.top()->cleanup();
		states.pop();
	}

	states.push(state);
	states.top()->initialize(Application::Instance());
}

void Application::pushState(State * state)
{
	if (!states.empty())
	{
		states.top()->pause();
	}

	states.push(state);
	states.top()->initialize(Application::Instance());
}

void Application::popState()
{
	if (!states.empty())
	{
		states.top()->cleanup();
		states.pop();
	}

	if (!states.empty())
	{
		states.top()->resume();
	}
}

void Application::handleEvents()
{
	states.top()->handleEvents(Application::Instance());

	isRunning = !glfwWindowShouldClose(window);
	glfwPollEvents();
}

void Application::update()
{
	states.top()->update(Application::Instance());
}

void Application::draw()
{
	states.top()->draw(Application::Instance());

	glfwSwapBuffers(window);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool Application::running()
{
	return isRunning;
}

void Application::quit()
{
	std::cout << "Application terminating..." << std::endl;
	isRunning = false;
}
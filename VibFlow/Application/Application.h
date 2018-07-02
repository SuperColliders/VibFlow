#pragma once
#include "../vibdec.h"
#include <stack>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class State;

class Application
{
public:
	void initialize(uint width, uint height, const char* title);

	//Static application getters
	static Application * Instance()
	{
		return &application;
	}
	GLFWwindow * Window()
	{
		return window;
	}
	const vfm::dvec2 getWindowStats()
	{
		return vfm::dvec2(w, h);
	}

	void cleanup();

	void pushState(State * state);
	void changeState(State * state);
	void popState();

	void handleEvents();
	void update();
	void draw();

	bool running();
	void quit();

protected:
	Application(uint width, uint height, const char* windowName);

private:
	static Application application;
	GLFWwindow* window;

	std::stack<State*> states;

	bool isRunning;
	uint w, h;
};
#pragma once
#include <iostream>
#include <stack>
#include <GL/glew.h>
#include "Canvas.h"

class GraphicsSystem
{
public:
	static GraphicsSystem * Instance()
	{
		return &GSystem;
	}

	static void createNewCanvas();

protected:
	GraphicsSystem();

private:
	static GraphicsSystem GSystem;
	std::stack<Canvas*> canvas;
};


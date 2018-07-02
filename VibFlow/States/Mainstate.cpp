#include <stdio.h>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <map>
#include <vector>
#include <iostream>
#include <GL\glew.h>
#include "Mainstate.h"

Mainstate Mainstate::m_state;

Mainstate::Mainstate()
{
}

void Mainstate::initialize(Application * app)
{
	auto getSource = [ ](const std::string& sourceFile, const std::string& type) -> std::string
	{
		std::ifstream infile(sourceFile + "." + type);
		std::string source;
		std::stringstream stringStream;

		if (!infile.is_open())
		{
			throw std::runtime_error("Couldn't open shader source: " + sourceFile);
		}

		stringStream << infile.rdbuf();
		source = stringStream.str();

		return source;
	};

	auto compileShader = [ ](const GLchar* source, GLenum type)
	{
		GLuint shader = glCreateShader(type);
		glShaderSource(shader, 1, &source, nullptr);
		glCompileShader(shader);

		GLint status;
		GLchar infolog[512];

		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
		if (!status)
		{
			glGetShaderInfoLog(shader, 512, nullptr, infolog);
			throw std::runtime_error("Error compiling shader: " + std::string(infolog));
		}

		return shader;
	};

	auto createProgram = [](GLuint vertexShader, GLuint fragmentShader)
	{
		GLuint program = glCreateProgram();

		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);

		glLinkProgram(program);

		GLint status;
		GLchar infolog[512];

		glGetProgramiv(program, GL_LINK_STATUS, &status);
		if (!status)
		{
			glGetProgramInfoLog(program, 512, nullptr, infolog);
			throw std::runtime_error("Error linking program: " + std::string(infolog));
		}

		return program;
	};

		std::string vSource, fSource;
	try
	{
		vSource = getSource("vertex", "vs");
		fSource = getSource("fragment", "fs");
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	GLuint vsID, fsID;
	try
	{
		vsID = compileShader(vSource.c_str(), GL_VERTEX_SHADER);
		fsID = compileShader(fSource.c_str(), GL_FRAGMENT_SHADER);
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
		//exit(-1);
	}

	try
		{
		programID = createProgram(vsID, fsID);
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	glDeleteShader(vsID);
	glDeleteShader(fsID);

	bool isp = glIsProgram(programID);

	if (isp)
	{
		std::cout << "Hurray!!" << std::endl;
	}

	auto drawRect = [](float x3, float y3, float sidelength) -> std::vector<vfm::vec2>
	{
		double halfside = sidelength / 2;

		std::vector<vfm::vec2> a;
		a.push_back(vfm::vec2(x3 - halfside, y3 - halfside));
		a.push_back(vfm::vec2(x3 - halfside, y3 + halfside));
		a.push_back(vfm::vec2(x3 + halfside, y3 + halfside));
		a.push_back(vfm::vec2(x3 - halfside, y3 - halfside));
		a.push_back(vfm::vec2(x3 + halfside, y3 - halfside));
		a.push_back(vfm::vec2(x3 + halfside, y3 + halfside));

		return a;
	};

	vecs = drawRect(0.0f, 0.0f, 2.0f);

	glUseProgram(programID);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vecs.size() * sizeof(vfm::vec2), &vecs.front(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	time_loc = glGetUniformLocation(programID, "time");
	glUniform1f(time_loc, 0.0f);

}

void Mainstate::cleanup()
{
}

void Mainstate::pause()
{
}

void Mainstate::resume()
{
}

void Mainstate::handleEvents(Application * app)
{
}

void Mainstate::update(Application * app)
{
	static float dt = 0.01f;
	static float time = 0.0f;
	glUniform1f(time_loc, time += dt);
}

void Mainstate::draw(Application * app)
{
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

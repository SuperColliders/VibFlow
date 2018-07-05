#include <iostream>
#include <GL/glew.h>
#include "Mainstate.h"
#include "../Common/common.h"
#include "../Core/GraphicsSystem/Program.h"

Mainstate Mainstate::m_state;

Mainstate::Mainstate()
{
}

void Mainstate::initialize(Application * app)
{
	p = new Program("vertex", "fragment");

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

	p->bind();

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vecs.size() * sizeof(vfm::vec2), &vecs.front(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	p->loadFloat("time", 0.0f);

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
	p->loadFloat("time", time += dt);
}

void Mainstate::draw(Application * app)
{
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

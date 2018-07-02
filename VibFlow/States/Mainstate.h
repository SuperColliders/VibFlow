#pragma once
#include "../Application/State.h"
#include "../vibdec.h"
#include <vector>

class Mainstate : public State
{
public:
	void initialize(Application * app);
	void cleanup();

	void pause();
	void resume();

	void handleEvents(Application * app);
	void update(Application * app);
	void draw(Application * app);

	static Mainstate * Instance()
	{
		return &m_state;
	}

protected:
	Mainstate();

private:
	static Mainstate m_state;
	GLuint programID;
	std::vector<vfm::vec2> vecs;

	GLuint vao;
	GLuint vbo;

	GLuint time_loc;
};
#pragma once

class Application;

class State
{
public:
	virtual void initialize(Application * app) = 0;
	virtual void cleanup() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void handleEvents(Application * app) = 0;
	virtual void update(Application * app) = 0;
	virtual void draw(Application * app) = 0;

	void changeState(Application * app, State * state);

protected:
	State();
};

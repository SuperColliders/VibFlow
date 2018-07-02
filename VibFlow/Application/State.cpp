#include "State.h"
#include "Application.h"


State::State() { }

void State::changeState(Application * app, State * state)
{
	app->changeState(state);
}

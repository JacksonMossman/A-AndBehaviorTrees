#pragma once
#include "Agent.h"
#include <vector>

/*	State
A State in a finite state machine is a node that tells the
Agent how it should behave. When a State is entered, init()
is called, and when a State is exited, exit() is called. The
update() function is called every update. Any transitions
that have been added to the State are checked each update
by the FSM, which will change States if any have been
triggered.
*/

class Transition;

class State
{
public:
	State() {}
	virtual ~State() {}

	virtual void init(Agent* agent) {}
	virtual void update(Agent* agent, float deltaTime) = 0;
	virtual void exit(Agent* agent) {}

	void addTransitions(Transition* transition) {
		m_transitions.push_back(transition);
	}

	Transition* getTriggeredTransition(Agent* agent);

protected:
	std::vector<Transition*> m_transitions;
};

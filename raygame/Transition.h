#pragma once
#include "Agent.h"
#include "Condition.h"

/*	Transition
A Transition in a finite state machine is an edge between
two States. Transitions hold Conditions that are tested to
determine whether the FSM should change its current state
to the Transition's target.
*/

class State;

class Transition
{
public:
	Transition(State* target, Condition* condition)
		: m_target(target), m_condition(condition) {}
	~Transition() {}

	State* getTargetState() { return m_target; }

	bool hasTriggered(Agent* agent) { return m_condition->test(agent); }

private:
	State*		m_target;
	Condition*	m_condition;
};

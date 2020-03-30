#pragma once
#include "Behavior.h"
#include "State.h"
#include "Transition.h"
#include "Condition.h"

class FSM : public Behavior
{
public:
	FSM() : m_currentState(nullptr) {}
	virtual ~FSM();

	void addState(State* state) { m_states.push_back(state); }
	void addTransition(Transition* transition) { m_transitions.push_back(transition); }
	void addCondition(Condition* condition) { m_conditions.push_back(condition); }

	void setCurrentState(State* state) { m_currentState = state; }
	State* getCurrentState() { return m_currentState; }

	virtual void update(Agent* agent, float deltaTime);

protected:
	std::vector<State*>			m_states;
	std::vector<Transition*>	m_transitions;
	std::vector<Condition*>		m_conditions;

	State* m_currentState;
};


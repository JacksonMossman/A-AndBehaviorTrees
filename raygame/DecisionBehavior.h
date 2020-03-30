#pragma once
#include "Behavior.h"
#include "Decision.h"

class DecisionBehavior : public Behavior
{
public:
	DecisionBehavior(Decision* decision) : m_decision(decision) {}
	virtual ~DecisionBehavior() {}

	virtual void update(Agent* agent, float deltaTime);

private:
	Decision* m_decision;
};


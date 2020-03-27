#pragma once
#include "Behavior.h"

class Condition : public Behavior
{
public:
	Condition() {}
	virtual ~Condition() {}

	virtual bool test(Agent* agent) const = 0;

	virtual bool execute(Agent* agent, float deltaTime) {
		return test(agent);
	}
};


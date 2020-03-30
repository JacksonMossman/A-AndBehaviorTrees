#pragma once
#include "Behavior.h"

class EvadeBehavior : public Behavior
{
public:
	EvadeBehavior() {}
	virtual ~EvadeBehavior() {}

	virtual void update(Agent* agent, float deltaTime);
	void setTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target = nullptr;
};

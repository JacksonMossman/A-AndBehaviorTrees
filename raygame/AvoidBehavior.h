#pragma once
#include "Behavior.h"

class AvoidBehavior : public Behavior
{
public:
	AvoidBehavior() {}
	virtual ~AvoidBehavior() {}

	virtual Vector2 update(Agent* agent, float deltaTime);
	void setTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target = nullptr;
};

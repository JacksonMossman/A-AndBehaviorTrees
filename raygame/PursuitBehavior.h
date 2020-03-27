#pragma once
#include "Behavior.h"

class PursuitBehavior : public Behavior
{
public:
	PursuitBehavior() {}
	virtual ~PursuitBehavior() {}

	virtual Vector2 update(Agent* agent, float deltaTime);
	void setTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target = nullptr;
};


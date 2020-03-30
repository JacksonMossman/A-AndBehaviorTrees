#pragma once
#include "Behavior.h"

class PursuitBehavior : public Behavior
{
public:
	PursuitBehavior() {}
	virtual ~PursuitBehavior() {}

	virtual void update(Agent* agent, float deltaTime);
	void setTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target = nullptr;
};


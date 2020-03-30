#pragma once
#include "Behavior.h"

class FleeBehavior : public Behavior
{
public:
	FleeBehavior() {}
	virtual ~FleeBehavior() {}

	virtual void update(Agent* agent, float deltaTime);
	void setTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target = nullptr;
};


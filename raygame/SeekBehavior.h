#pragma once
#include "Behavior.h"

class SeekBehavior : public Behavior
{
public:
	SeekBehavior() {}
	virtual ~SeekBehavior() {}

	virtual void update(Agent* agent, float deltaTime);
	void setTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target = nullptr;
};


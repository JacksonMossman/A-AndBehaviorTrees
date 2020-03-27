#pragma once
#include "Behavior.h"

class ArriveBehavior : public Behavior
{
public:
	ArriveBehavior() {}
	virtual ~ArriveBehavior() {}

	virtual Vector2 update(Agent* agent, float deltaTime);
	void setTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target = nullptr;
};

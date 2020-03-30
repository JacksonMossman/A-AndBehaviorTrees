#pragma once
#include "Behavior.h"

class ScreenEdgeBehavior : public Behavior
{
public:
	ScreenEdgeBehavior() {}
	virtual ~ScreenEdgeBehavior() {}

	virtual void update(Agent* agent, float deltaTime);
};


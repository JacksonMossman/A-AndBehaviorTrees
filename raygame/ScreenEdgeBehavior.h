#pragma once
#include "Behavior.h"

class ScreenEdgeBehavior : public Behavior
{
public:
	ScreenEdgeBehavior() {}
	virtual ~ScreenEdgeBehavior() {}

	virtual Vector2 update(Agent* agent, float deltaTime);
};


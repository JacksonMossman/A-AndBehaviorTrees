#pragma once
#include "Behavior.h"

class KeyboardBehavior : public Behavior
{
public:
	KeyboardBehavior() {}
	virtual ~KeyboardBehavior() {}

	virtual Vector2 update(Agent* agent, float deltaTime);
};


#pragma once
#include "Behavior.h"

class KeyboardBehavior : public Behavior
{
public:
	KeyboardBehavior() {}
	virtual ~KeyboardBehavior() {}

	virtual void update(Agent* agent, float deltaTime);
};


#pragma once
#include "Behavior.h"

class Condition : public Behavior
{
public:
	Condition() {}
	virtual ~Condition() {}

	virtual bool test(Agent* agent) const = 0;

	virtual Vector2 update(Agent* agent, float deltaTime) {
		return Vector2{ 0.0f, 0.0f };
	}
};

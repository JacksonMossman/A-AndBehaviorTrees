#pragma once
#include "Agent.h";

class Behavior
{
public:
	Behavior() {}
	virtual ~Behavior() {}

	virtual void update(Agent* agent, float deltaTime) = 0;
};

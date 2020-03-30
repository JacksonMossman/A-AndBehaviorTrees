#pragma once
#include "Behavior.h"

class WanderBehavior : public Behavior
{
public:
	WanderBehavior() {}
	virtual ~WanderBehavior() {}

	virtual void update(Agent* agent, float deltaTime);

private:
	float m_radius = 2000.0f;
	float m_offset = 0.0f;
	float m_jitter = 500.0f;
	Vector2 m_prevTarget = { 0.0f, 0.0f };
};


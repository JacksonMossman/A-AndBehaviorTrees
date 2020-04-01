#pragma once
#include "Decision.h"

class MoveToTargetDecision : public Decision
{
public:
	MoveToTargetDecision(Agent* target, float speed) : m_target(target), m_speed(speed) {}
	~MoveToTargetDecision() {}

	void makeDecision(Agent* agent, float deltaTime);

private:
	Agent* m_target;
	float m_speed;
};


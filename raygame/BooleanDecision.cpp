#include "BooleanDecision.h"

void BooleanDecision::makeDecision(Agent* agent, float deltaTime)
{
	if (testCondition(agent))
		a->makeDecision(agent, deltaTime);
	else
		b->makeDecision(agent, deltaTime);
}

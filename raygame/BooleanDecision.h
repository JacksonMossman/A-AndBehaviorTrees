#pragma once
#include "Decision.h"

class BooleanDecision : public Decision
{
public:
	virtual void makeDecision(Agent* agent, float deltaTime);
protected:
	virtual bool testCondition(Agent* agent) { return false; }
private:
	Decision* a;
	Decision* b;
};

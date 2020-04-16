#pragma once
#include "Condition.h"
#include "StarAgent.h"
class CapturedCondition :
	public Condition
{

	//CapturedCondition(StarAgent star);

	virtual bool test(Agent* agent) const;
};


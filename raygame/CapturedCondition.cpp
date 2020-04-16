#include "CapturedCondition.h"

bool CapturedCondition::test(Agent* agent) const
{
	
	StarAgent* temp = (StarAgent*)agent;
	return temp->captured;
	
}

#pragma once
#include "Condition.h"
class CapturedCondition :
	public Condition
{
public:
	CapturedCondition();

	virtual bool test(Agent* agent) const;

private:
	Agent* m_target;
	float m_range;
};


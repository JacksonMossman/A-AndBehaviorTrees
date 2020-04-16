#pragma once
#include "Agent.h"
#include "KeyboardBehavior.h"
#include "ScreenEdgeBehavior.h"

class PlayerAgent : public Agent
{
public:
	PlayerAgent();
	virtual ~PlayerAgent() {}
	void intialize();
};


#pragma once
#include "Agent.h";

/*	Behavior
A Behavior performs an action or actions each time it is
updated. The Behavior class itself it pure virtual; classes
must be inherited from it. These classes can be simple
Behaviors such as seek and flee, or they can be more
complex such as a finite state machine or a decision tree.
*/

class Behavior
{
public:
	Behavior() {}
	virtual ~Behavior() {}

	virtual void update(Agent* agent, float deltaTime) = 0;
};

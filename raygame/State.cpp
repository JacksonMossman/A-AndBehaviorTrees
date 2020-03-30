#include "State.h"
#include "Transition.h"

Transition* State::getTriggeredTransition(Agent* agent)
{
	for (Transition* transition : m_transitions) {
		if (transition->hasTriggered(agent)) {
			return transition;
		}
	}
	return nullptr;
}

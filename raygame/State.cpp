#include "State.h"
#include "Transition.h"

Transition* State::getTriggeredTransition(Agent* agent)
{
	//Check if transitions have triggered until we find one that has
	for (Transition* transition : m_transitions) {
		if (transition->hasTriggered(agent)) {
			return transition;
		}
	}
	return nullptr;
}

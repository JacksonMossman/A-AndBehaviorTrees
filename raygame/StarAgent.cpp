#include "StarAgent.h"
#include "WanderBehavior.h"
StarAgent::StarAgent()
{
	WanderBehavior* wander = new WanderBehavior();
	addBehavior(wander);
	/*FlockingBehavior* flockingBehavior = new FlockingBehavior();
	BehaviorDecision* flockingDescition = new BehaviorDecision(flockingBehavior);*/

	//FleeBehavior* FleeBehavior


		//BooleanDecision capturedDescision = new BooleanDecision()
}

StarAgent::~StarAgent()
{
}

void StarAgent::draw()
{
	DetectionRange->draw();
	__super::draw();
}

void StarAgent::update(float deltaTime)
{
	DetectionRange->update(deltaTime);
	__super::update(deltaTime);
}

#include "StarAgent.h"
#include "WanderBehavior.h"


StarAgent::StarAgent(Agent* playerRef)
{
	setSpeed(30);
	player = playerRef;
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

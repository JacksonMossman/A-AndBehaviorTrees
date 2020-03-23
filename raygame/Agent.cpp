#include "Agent.h"

void Agent::update(float deltaTime)
{
	//Set total force to zero
	//For each Behavior in the Behavior list
		//Call the Behavior's update function
		//Add the returned value to total force
	//Add total force times delta time to velocity
	//Add velocity times delta time to position
}

void Agent::draw()
{
	DrawRectangle(m_Position.x, m_Position.y, 10, 10, MAROON);
}

void Agent::addBehavior(Behavior* behavior)
{
}

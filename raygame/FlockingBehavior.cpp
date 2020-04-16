#include "FlockingBehavior.h"
#include<raymath.h>

FlockingBehavior::FlockingBehavior(std::vector<Agent*> flock, Agent* leader)
	{
		m_flock = flock;
		m_leader = leader;
	}

FlockingBehavior::~FlockingBehavior()
	{
	}

void FlockingBehavior::update(Agent* agent, float deltaTime)
{
		Vector2 averagePosition{ 0,0 };
		//calculate average position of all flock agents
		for (Agent* i : m_flock)
		{
			averagePosition += i->getPosition();
		}
		
		averagePosition.x  =averagePosition.x / m_flock.size();
		averagePosition.y = averagePosition.y / m_flock.size();
		//normalize the direction of the average position
		averagePosition = averagePosition.normalize();
		Vector2 force = averagePosition * agent->getSpeed();
		force = force - agent->getVelocity();
		
		agent->addForce(force);
}


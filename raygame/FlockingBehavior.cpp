#include "FlockingBehavior.h"
#include<raymath.h>
//*a Verson of faked
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
		
		averagePosition.x = averagePosition.x / m_flock.size();
		averagePosition.y = averagePosition.y / m_flock.size();
		//normalize the direction of the average position
		averagePosition = averagePosition - agent->getPosition();
		


		//Get this agent's position
		Vector2 pos = agent->getPosition();
		//Get the position of the leader agent
		Vector2 targetPos = m_leader->getPosition();

		//Calculate the vector describing the direction to the target and normalize it
		Vector2 LeadDirection = targetPos - pos;	
		
		//add direction of the flock and leader with a favoring towards the leader
		Vector2 direction =((LeadDirection * 5) + averagePosition).normalize();
		//Multiply the direction by the speed we want the agent to move
		Vector2 force = direction * agent->getSpeed();
		//Subtract the agent's current velocity from the result to get the force we need to apply
		agent->addForce(force);
		agent->setColor(BLUE);
}


#include "FollowPathBehavior.h"
#include <iostream>
FollowPathBehavior::FollowPathBehavior()
{
}

FollowPathBehavior::~FollowPathBehavior()
{
}

void FollowPathBehavior::update(Agent* agent, float deltaTime)
{

	//If the target is null
	if (agent == nullptr || m_target == nullptr) {
		//Return a zero vector
		return;
	}

	//Get the target postion
	Vector2 RangeChecktargetPos = m_target->getPosition();

	//Get this agent's position
	Vector2 RangeCheckPos = agent->getPosition();

	//Find the distance
	float distance = (RangeChecktargetPos - RangeCheckPos).magnitude();

	//Return the result
	if(distance <= 20)
	{
		//check if its time to go backwards
		if (!goBack)
		{
			if (m_pathPosition < m_path.size() - 1) {
				m_pathPosition++;
				//print out current node thats target
				std::cout << m_pathPosition << std::endl << m_path.size();
				m_target = m_path.at(m_pathPosition);
			}
			else
			{
				goBack = true;
			}
		}
		//go on path backwards	
		else
		{
			if (m_pathPosition > 0) {
				m_pathPosition--;
				std::cout << m_pathPosition << std::endl << m_path.size();
				m_target = m_path.at(m_pathPosition);
			}
			//send the node back 
			else
			{
				goBack = false;
			}
		}
		
	}

	//Get this agent's position
	Vector2 pos = agent->getPosition();
	//Get the position of the target agent
	Vector2 targetPos = m_target->getPosition();

	//Calculate the vector describing the direction to the target and normalize it
	Vector2 direction = targetPos - pos;
	direction = direction.normalize();
	//Multiply the direction by the speed we want the agent to move
	Vector2 force = direction * agent->getSpeed();
	//Subtract the agent's current velocity from the result to get the force we need to apply
	force = force - agent->getVelocity();


	//Return the force
	agent->addForce(force);

	agent->setColor(GREEN);

	
}


#include "Agent.h"
#include "Behavior.h"

void Agent::update(float deltaTime)
{
	//Set total force to zero
	Vector2 totalForce = { 0.0f, 0.0f };
	//For each Behavior in the Behavior list
	for (auto i = m_behaviorList.begin(); i != m_behaviorList.end(); i++) {
		//Call the Behavior's update function
		Vector2 force = (*i)->update(this, deltaTime);
		//Add the returned value to total force
		totalForce += force;
	}
	//Add total force times delta time to velocity
	addForce(totalForce * deltaTime);
	//Add velocity times delta time to position
	m_position += m_velocity * deltaTime;
}

void Agent::draw()
{
	DrawRectangle(m_position.x, m_position.y, 100, 100, m_color);
}

void Agent::addBehavior(Behavior* behavior)
{
	//Add the Behavior to the Behavior list
	m_behaviorList.insert(m_behaviorList.end(), behavior);
}

void Agent::addForce(Vector2 force)
{
	m_velocity += force;
}

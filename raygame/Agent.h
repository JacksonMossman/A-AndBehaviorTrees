#pragma once
#include "raylib.h"
#include <vector>

class Behavior;

class Agent
{
public:
	Agent() {}
	virtual ~Agent() {}

	//Update the agent and its behaviors
	virtual void update(float deltaTime);

	//Draw the agent
	virtual void draw();

	//Add a behavior to the agent
	void addBehavior(Behavior* behavior);

	//Movement functions
	void setPosition(Vector2 position) { m_Position = position; }
	Vector2 getPosition() { return m_Position; }
	void setVelocity(Vector2 velocity) { m_Velocity = velocity; }
	Vector2 getVelocity() { return m_Velocity; }

protected:
	std::vector<Behavior*> m_BehaviorList;

	Vector2 m_Position = { 0,0 };
	Vector2 m_Velocity = { 0,0 };
};


#pragma once
#include "Game.h"
#include "Behavior.h"

class FlockingBehavior :
	public Behavior
{
public:
	FlockingBehavior(std::vector<Agent*> flock, Agent* leader);
		~FlockingBehavior();
	void update(Agent* agent, float deltaTime);
private:
	std::vector<Agent*> m_flock;
	Agent* m_leader;
};



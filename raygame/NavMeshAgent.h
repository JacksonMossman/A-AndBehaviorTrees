#pragma once
#include "NodeAgent.h"
class NavMeshAgent :
	public Agent
{
public:
	NavMeshAgent(float screenX, float screenY);
	~NavMeshAgent();
	void draw();
	void SelectPath(std::vector<NodeAgent*> path);
	std::vector<NodeAgent*> navMeshAgents;
	NodeAgent* start;
	NodeAgent* target;
};


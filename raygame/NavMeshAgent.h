#pragma once
#include "NodeAgent.h"
#include "AStar.h"
class NavMeshAgent :
	public Agent
{
public:
	NavMeshAgent(float screenX, float screenY);
	~NavMeshAgent();
	void draw();
	void SelectPath(std::vector<NodeAgent*> path);
	void SetNewTarget();
	std::vector<NodeAgent*> navMeshAgents;
	NodeAgent* start;
	NodeAgent* target;
	bool changedPath = false;
	std::vector<NodeAgent*> m_path;
	AStar* astar = new AStar;
	void update(float deltaTime) override;
private:
	
};


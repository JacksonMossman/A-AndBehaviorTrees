#pragma once
#include "Behavior.h"
#include "NodeAgent.h"
class FollowPathBehavior :
	public Behavior
{
public:
	FollowPathBehavior();
	~FollowPathBehavior();
	virtual void update(Agent* agent, float deltaTime);
	void setPath(std::vector<NodeAgent*> path) { m_path = path; m_pathPosition = 0; m_target = path.at(m_pathPosition); }
	bool goBack = false;
private:
		std::vector<NodeAgent*> m_path;
		NodeAgent* m_target;
		
		int m_pathPosition =0;
};


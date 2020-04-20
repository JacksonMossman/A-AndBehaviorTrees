#include "NavMeshAgent.h"

NavMeshAgent::NavMeshAgent(float screenX, float screenY)
{
	float yAgents = screenX / 100;
	float xAgents = screenY / 100;
		for (int i = 0; i < yAgents; i++)
		{
			for (int j = 0; j < xAgents; j++)
			{
				float random = rand() % 4;
				NodeAgent* newStar = new NodeAgent();
				Vector2* position = new Vector2{ 100.0f * i,100.0f * j };
				newStar->setPosition(*position);
				/*newStar->node->position = position;*/
				if (i == 0 && j == 0)
				{
					start = newStar;
				}
				if (i == 8 && j == 8)
				{
					target = newStar;
				}
				if (random == 1 && newStar != start && newStar != target)
				{
					newStar->blocked = true;
					newStar->setColor(RED);
					
				}
				else
				{
					newStar->setColor(BLUE);
				}
				navMeshAgents.push_back(newStar);

			}
		}
		//compare each agent to every other agent 
		for (NodeAgent*  agent1 : navMeshAgents )
		{
			agent1->connections;
			for (NodeAgent* agent2 : navMeshAgents)
			{
				if (agent1 != agent2)
				{
					//check if agent 2 is in the radius of agent 1 and makes  a new edge if in range
					if ((agent2->getPosition() - agent1->getPosition()).magnitude() < 101)
					{
						
						//make a new edge of all the avaliable targets and give it a cost based off the distance from the original point
						Edge* newEdge = new Edge;
						//set values of new edge to agent 2 node if in range
						newEdge->target = agent2;
						newEdge->cost = (agent1->getPosition() + agent2->getPosition()).magnitude();
						if (agent2->blocked== true)
						{
							newEdge->cost = 9999999999999999;
						}
						//push node onto connections
						agent1->connections.push_back(*newEdge);

					}
				}
			}
		}
		

}
NavMeshAgent::~NavMeshAgent()
{
}

void NavMeshAgent::draw()
{
	for (NodeAgent* i : navMeshAgents)
	{
		i->draw();
	}
	changedPath = false;
}

void NavMeshAgent::SelectPath(std::vector<NodeAgent*> path)
{
	for (NodeAgent* agent : navMeshAgents)
	{
		if (agent->blocked)
		{
			agent->setColor(RED);
		}
		else
		{
			agent->setColor(BLUE);
		}
	}
	
	for (NodeAgent* node : path)
	{
		node->setColor(YELLOW);
	}
}

void NavMeshAgent::SetNewTarget()
{
	if (IsMouseButtonPressed(0))
	{
		float ShortestDistance = 99999.99999f;
		NodeAgent* curretClosestTocursor = new NodeAgent;
		for (NodeAgent* agent : navMeshAgents)
		{
			Vector2 temp;
			temp = agent->getPosition() - GetMousePosition();
			if (temp.magnitude() < ShortestDistance)
			{
				ShortestDistance = temp.magnitude();
				curretClosestTocursor = agent;
				changedPath = true;
			}
		}
		if(curretClosestTocursor != target)
		{
			if (target->blocked)
			{
				target->setColor(RED);
			}
			else
			{
				target->setColor(BLUE);
			}
			
			
			
		}
		start = target;
		target = curretClosestTocursor;
		curretClosestTocursor->setColor(PURPLE);	
	}
}

void NavMeshAgent::update(float deltaTime)
{
	SetNewTarget();
	m_path = astar->AStarSearch(start, target);
	SelectPath(m_path);

}


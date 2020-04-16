#include "NavMeshAgent.h"
#include "NodeAgent.h"

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
				if (i == 5 && j == 5)
				{
					target = newStar;
				}
				if (random == 1)
				{
					newStar->blocked = true;
					newStar->setColor(RED);
				}
				if (newStar->blocked)
				{
					newStar->setPosition(Vector2{ 99999.0f,99999.0f });
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
			agent1->node->connections;
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
						newEdge->target = agent2->node;
						newEdge->cost = agent1->getPosition().magnitude() + agent2->getPosition().magnitude();
						//push node onto connections
						agent1->node->connections.push_back(*newEdge);

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
}

void NavMeshAgent::SelectPath(std::vector<NodeAgent*> path)
{
	for (NodeAgent* node : path)
	{
		node->setColor(YELLOW);
	}
}

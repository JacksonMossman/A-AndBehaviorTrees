#include "NavMeshAgent.h"
//* NavMesh Agent Acts As a manager for a grid of agents that are used as visual represention of the grid which can be used for navagation



//create a number of Node agents and randomly assigns a blocked or not blocked bool then generates the first path the agents will follow  
NavMeshAgent::NavMeshAgent(float screenX, float screenY)
{
	//create a number of agents based off the size of the screen
	float yAgents = screenX / 100;
	float xAgents = screenY / 100;
		for (int i = 0; i < yAgents; i++)
		{
			for (int j = 0; j < xAgents; j++)
			{
				float random = rand() % 4;
				//make new star every 100 units
				NodeAgent* newStar = new NodeAgent();
				Vector2* position = new Vector2{ 100.0f * i,100.0f * j };
				newStar->setPosition(*position);
				/*newStar->node->position = position;*/
				//set first start star
				if (i == 0 && j == 0)
				{
					start = newStar;
				}
				//set first target 
				if (i == 8 && j == 8)
				{
					target = newStar;
				}
				//sees if the star will be blocked
				if (random == 1 && newStar != start && newStar != target)
				{
					newStar->blocked = true;
					newStar->setColor(RED);
					
				}
				//sets star to blue if avaliable
				else
				{
					newStar->setColor(BLUE);
				}
				//add to nave mesh agent list
				navMeshAgents.push_back(newStar);

				
			}
		}
		//compare each agent to every other agent then create connections based off distance from origonal agent
		for (NodeAgent*  agent1 : navMeshAgents )
		{
		
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
						//not adding blocked agents to 
						if (agent2->blocked == false)
						{
							agent1->connections.push_back(*newEdge);
						}
						
						//push node onto connections
						//agent1->connections.push_back(*newEdge);

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
	//draw the agent
	for (NodeAgent* i : navMeshAgents)
	{
		i->draw();
	}
	//set to false before next update
	changedPath = false;
}

void NavMeshAgent::SelectPath(std::vector<NodeAgent*> path)
{
	//resets nodes
	for (NodeAgent* agent : navMeshAgents)
	{
		//set old path back to normal
		if (agent->blocked)
		{
			agent->setColor(RED);
		}
		else
		{
			agent->setColor(BLUE);
		}
	}
	//highights next path
	for (NodeAgent* node : path)
	{
		if (node == target || node == start)
		{
			node->setColor(PURPLE);
		}
		node->setColor(YELLOW);
	}
}
//allows the player to click to select the new end target for the agent
void NavMeshAgent::SetNewTarget()
{
	//checks if mouse button has been clicked then finds the closest node to the mouse
	if (IsMouseButtonPressed(0))
	{
		//a temporary value to be above likley screen sizes
		float ShortestDistance = 99999.99999f;
		NodeAgent* curretClosestTocursor = new NodeAgent;
		//compare all agents to mouse position  then select the one closest to the mouse
		for (NodeAgent* agent : navMeshAgents)
		{
			Vector2 temp;
			temp = agent->getPosition() - GetMousePosition();
			//compare all nodes to current shortestDistance
			if (temp.magnitude() < ShortestDistance)
			{
				ShortestDistance = temp.magnitude();
				curretClosestTocursor = agent;
				changedPath = true;
			}
		}
		//set old target to orignal color
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
		//set start to the current target
		start = target;
		//set target to targeted Node
		target = curretClosestTocursor;
	}
}

void NavMeshAgent::update(float deltaTime)
{
	//check if a new target has been selected
	SetNewTarget();
	//set new path based off current information
	m_path = astar->AStarSearch(start, target);
	//select the path
	SelectPath(m_path);

}


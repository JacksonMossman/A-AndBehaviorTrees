#pragma once
#include "NodeAgent.h"
#include<vector>
#include<raylib.h>

	class AStar
	{
	public:

		AStar();
		~AStar();

		std::vector<NodeAgent*> AStarSearch(NodeAgent* startNode, NodeAgent* endNode);
		float heuristic(NodeAgent* target, NodeAgent* endNode);
	private:

	};



#pragma once
#include<vector>
#include<raylib.h>
	struct Edge;

	struct Node
	{
		Vector2* position;

		float gScore = 0.0f;
		//## Add hScore ##//
		float hScore = 0.0f;
		//## Add fScore ##//
		float fScore = 0.0f;
		Node* previous = nullptr;

		std::vector<Edge> connections ;

	};
	struct Edge
	{
		Node* target;
		float cost;
	};

	class AStar
	{
	public:

		AStar();
		~AStar();

		std::vector<Node*> AStarSearch(Node* startNode, Node* endNode);
		float heuristic(Node* target, Node* endNode);
	private:

	};



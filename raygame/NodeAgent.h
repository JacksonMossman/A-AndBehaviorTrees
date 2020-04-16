#pragma once
#include "Agent.h"
#include "Game.h"
struct Edge;
class NodeAgent :
	public Agent
{
public:

	NodeAgent();
	~NodeAgent();
	bool blocked = false;
	
	Vector2* position;

	float gScore = 0.0f;
	//## Add hScore ##//
	float hScore = 0.0f;
	//## Add fScore ##//
	float fScore = 0.0f;
	NodeAgent* previous = nullptr;

	std::vector<Edge> connections;
	
};

struct Edge
{
	NodeAgent* target;
	float cost;
};
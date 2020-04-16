#pragma once
#include "Agent.h"
#include "AStar.h"

class NodeAgent :
	public Agent
{
public:

	NodeAgent();
	~NodeAgent();
	bool blocked = false;
	Node* node = new Node;
	
};


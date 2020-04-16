#pragma once
#include "raylib.h"
#include "Agent.h"
#include "PlayerAgent.h"
#include "StarAgent.h"
#include <vector>

class Game
{
public:
	Game();
	~Game();
	void run();
	int screenWidth = 1800;
	int screenHeight = 1000;
	std::vector<Agent*> starList;

};

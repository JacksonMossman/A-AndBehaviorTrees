#include "Game.h"
#include "FlockingBehavior.h"
#include "SeekBehavior.h"
#include "AABB.h"
#include "NavMeshAgent.h"
#include "AStar.h"
#include "NodeAgent.h"
Game::Game()
{
}

Game::~Game()
{
}

void Game::run()
{
	// Initialization
	//--------------------------------------------------------------------------------------

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	//Create the player
	
	PlayerAgent* player = new PlayerAgent();
	AABB* aabb = new AABB(100,100,player);
	player->setSpeed(10000);
	
	StarAgent* star1 = new StarAgent();
	star1->setPosition(Vector2{ 500,500 });
	
	star1->setSpeed(100);
	starList.push_back(star1);

	StarAgent* star2 = new StarAgent();
	star2->setPosition(Vector2{ 400,500 });
	
	star2->setSpeed(100);
	starList.push_back(star2);

	FlockingBehavior* flocking = new FlockingBehavior(starList, player);
	SeekBehavior* seek1 = new SeekBehavior();
	seek1->setTarget(player);
	star1->addBehavior(flocking);
	FlockingBehavior* flocking2 = new FlockingBehavior(starList, player);
	SeekBehavior* seek2 = new SeekBehavior();
	star2->addBehavior(flocking);
	seek2->setTarget(player);
	star2->addBehavior(seek2);

	NavMeshAgent* navmesh = new NavMeshAgent(screenWidth,screenHeight);
	
	AStar* astar = new AStar;

	std::vector<Node*> path = astar->AStarSearch(navmesh->start->node, navmesh->target->node);

	//navmesh->SelectPath(path);
	StarAgent* star3 = new StarAgent();
	StarAgent* star4 = new StarAgent();
	StarAgent* star5 = new StarAgent();


	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		float deltaTime = GetFrameTime();

		player->update(deltaTime);
		aabb->update(deltaTime);
		for (Agent* i : starList)
		{
			i->update(deltaTime);
		}
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		player->draw();
		aabb->draw();
		navmesh->draw();
		for (Agent* i : starList)
		{
			i->draw();
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------
}
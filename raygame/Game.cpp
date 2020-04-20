#include "Game.h"
#include "FlockingBehavior.h"
#include "SeekBehavior.h"
#include "AABB.h"
#include "NavMeshAgent.h"
#include "AStar.h"
#include "NodeAgent.h"
#include "FollowPathBehavior.h"
#include "WithinRangeCondition.h"
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
	NavMeshAgent* navmesh = new NavMeshAgent(screenWidth,screenHeight);
	PlayerAgent* player = new PlayerAgent();
	this->player = player;
	AABB* aabb = new AABB(100,100,player);
	player->setSpeed(10000);
	
	StarAgent* star1 = new StarAgent(player);
	star1->setPosition(Vector2{ 100,100 });	
	star1->setSpeed(100);


	StarAgent* star2 = new StarAgent(player);
	star2->setPosition(Vector2{ 400,500 });
	star2->setSpeed(90);
		

	
	
	AStar* astar = new AStar;

	std::vector<NodeAgent*> path = astar->AStarSearch(navmesh->start, navmesh->target);
	navmesh->SelectPath(path);

	FollowPathBehavior* followPath = new FollowPathBehavior();
	FleeBehavior* flee = new FleeBehavior();
	BehaviorDecision* pathingDecision = new BehaviorDecision(followPath);
	BehaviorDecision* fleeDecision = new BehaviorDecision(flee);
	flee->setTarget(player);
	WithinRangeCondition* FleeRange = new WithinRangeCondition(player,100);
	
	BooleanDecision* behaviorDecision = new BooleanDecision(fleeDecision, pathingDecision, FleeRange);
	DecisionTreeBehavior* decisionTree = new DecisionTreeBehavior(behaviorDecision);
	followPath->setPath(path);
	star1->addBehavior(decisionTree);	
	starList.push_back(star1);
	starList.push_back(star2);
	star2->addBehavior(decisionTree);

	
	//StarAgent* star4 = new StarAgent(player);
	//
	//StarAgent* star3 = new StarAgent(player);
	//StarAgent* star5 = new StarAgent(player);


	//starList.push_back(star2);
	//starList.push_back(star3);
	//starList.push_back(star4);
	//starList.push_back(star5);
	
	FlockingBehavior* flockingBehavior = new FlockingBehavior(starList, star1);

	//
	//star2->addBehavior(flockingBehavior);
	//star3->addBehavior(flockingBehavior);
	//star4->addBehavior(flockingBehavior);
	//star5->addBehavior(flockingBehavior);
	


	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		float deltaTime = GetFrameTime();

		player->update(deltaTime);
		aabb->update(deltaTime);
		navmesh->update(deltaTime);
		if (navmesh->changedPath)
		{
			followPath->setPath(navmesh->m_path);
		}
	
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
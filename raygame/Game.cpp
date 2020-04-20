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
	//create the first star set its position to top left corner
	StarAgent* star1 = new StarAgent(player);
	star1->setPosition(Vector2{ 100,100 });	
	star1->setSpeed(100);

	//generate second star position
	
		

	
	//build behavior tree for both agent one 
	AStar* astar = new AStar;
	//set first path of path following behavior
	std::vector<NodeAgent*> path = astar->AStarSearch(navmesh->start, navmesh->target);
	navmesh->SelectPath(path);

	//make behaviors for behavior tree
	FollowPathBehavior* followPath = new FollowPathBehavior();
	FleeBehavior* flee = new FleeBehavior();
	flee->setTarget(player);
	followPath->setPath(path);


	//create Decisions
	BehaviorDecision* pathingDecision = new BehaviorDecision(followPath);
	BehaviorDecision* fleeDecision = new BehaviorDecision(flee);

	//create Condition
	WithinRangeCondition* FleeRange = new WithinRangeCondition(player,100);	

	//Create Decision
	BooleanDecision* behaviorDecision = new BooleanDecision(fleeDecision, pathingDecision, FleeRange);

	//Create Decision Tree
	DecisionTreeBehavior* decisionTree = new DecisionTreeBehavior(behaviorDecision);


	//create new stars
	StarAgent* star2 = new StarAgent(player);
	StarAgent* star3 = new StarAgent(player);
	StarAgent* star4 = new StarAgent(player);
	StarAgent* star5 = new StarAgent(player);

	//add stars to star list
	starList.push_back(star1);
	starList.push_back(star2);
	starList.push_back(star3);
	starList.push_back(star4);
	starList.push_back(star5);
	
	FlockingBehavior* flockingBehavior = new FlockingBehavior(starList, star1);

	//give stars behaviors
	star1->addBehavior(decisionTree);	
	star2->addBehavior(flockingBehavior);
	star3->addBehavior(flockingBehavior);
	star4->addBehavior(flockingBehavior);
	star5->addBehavior(flockingBehavior);
		
	

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		float deltaTime = GetFrameTime();
		//update game objects
		player->update(deltaTime);
		aabb->update(deltaTime);
		navmesh->update(deltaTime);
		//check if path has changed
		if (navmesh->changedPath)
		{
			followPath->setPath(navmesh->m_path);
		}
		//update all stars
		for (Agent* i : starList)
		{
			i->update(deltaTime);
		}
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);
		//draw all game objects
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
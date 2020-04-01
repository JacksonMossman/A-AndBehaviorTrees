/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Agent.h"
#include "KeyboardBehavior.h"
#include "ScreenEdgeBehavior.h"
#include "WanderBehavior.h"
#include "SeekBehavior.h"
#include "PursuitBehavior.h"
#include "FSM.h" 
#include "IdleState.h"
#include "EnemyAttackState.h"
#include "WithinRangeCondition.h"
#include "DecisionTreeBehavior.h"
#include "BooleanDecision.h"
#include "BehaviorDecision.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 3200;
	int screenHeight = 1800;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	
	//Create the player
	Agent* player = new Agent();
	player->setPosition(Vector2{ 1600.0f, 900.0f });
	player->setSpeed(500.0f);
	player->setColor(SKYBLUE);
	//Create and add keyboard behavior
	KeyboardBehavior* keyboardBehavior = new KeyboardBehavior();
	player->addBehavior(keyboardBehavior);
	//Create and add screen edge behavior
	ScreenEdgeBehavior* screenEdgeBehavior = new ScreenEdgeBehavior();
	player->addBehavior(screenEdgeBehavior);

	//Create the enemy
	Agent* enemy = new Agent();
	enemy->setPosition(Vector2{ 800.0f, 450.0f });
	enemy->setSpeed(250.0f);
	enemy->setColor(DARKBLUE);

	//Create and add the enemy's FSM
	FSM* enemyFSM = new FSM();
	//enemy->addBehavior(enemyFSM);
	//Create and add the idle state
	IdleState* idleState = new IdleState();
	enemyFSM->addState(idleState);
	//Create and add the attack state
	EnemyAttackState* attackState = new EnemyAttackState(player, 250.0f);
	enemyFSM->addState(attackState);
	//Create and add the condition
	Condition* withinRangeCondition = new WithinRangeCondition(player, 200.0f);
	enemyFSM->addCondition(withinRangeCondition);
	//Create and add the transition
	Transition* toAttackTransition = new Transition(attackState, withinRangeCondition);
	enemyFSM->addTransition(toAttackTransition);
	idleState->addTransitions(toAttackTransition);
	//Set current state to idle
	enemyFSM->setCurrentState(idleState);

	//Leaves
	WanderBehavior* wanderBehavior = new WanderBehavior();
	BehaviorDecision* wanderDecision = new BehaviorDecision(wanderBehavior);
	SeekBehavior* seekBehavior = new SeekBehavior();
	seekBehavior->setTarget(player);
	BehaviorDecision* seekDecision = new BehaviorDecision(seekBehavior);
	PursuitBehavior* pursuitBehavior = new PursuitBehavior();
	pursuitBehavior->setTarget(player);
	BehaviorDecision* pursuitDecision = new BehaviorDecision(pursuitBehavior);
	//Branches
	WithinRangeCondition* canSeeCondition = new WithinRangeCondition(player, 500);
	BooleanDecision* canSeeDecision = new BooleanDecision(pursuitDecision, seekDecision, canSeeCondition);
	WithinRangeCondition* canHearCondition = new WithinRangeCondition(player, 1000);
	BooleanDecision* canHearDecision = new BooleanDecision(canSeeDecision, wanderDecision, canHearCondition);
	//Enemy decision tree
	DecisionTreeBehavior* enemyDecisionTree = new DecisionTreeBehavior(canHearDecision);
	enemy->addBehavior(enemyDecisionTree);
	enemy->addBehavior(screenEdgeBehavior);
	
	//MoveToTargetDecision* chaseDecision = new MoveToTargetDecision(player, 500.0f);
	//Condition* inSightCondition = new WithinRangeCondition(player, 1000.0f);
	//BooleanDecision* inSightDecision = new BooleanDecision()
	//DecisionBehavior* enemyDecisionTree = new DecisionBehavior()
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		float deltaTime = GetFrameTime();

		player->update(deltaTime);
		enemy->update(deltaTime);
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		player->draw();
		enemy->draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
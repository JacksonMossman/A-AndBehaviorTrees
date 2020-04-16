#pragma once
#include "Agent.h"
#include "BehaviorDecision.h"
#include "DecisionTreeBehavior.h"
#include "BooleanDecision.h"
#include "FlockingBehavior.h"
#include "CapturedCondition.h"
#include "FleeBehavior.h"
#include "AABB.h"
class StarAgent :
	public Agent
{
	public:
		StarAgent();
		~StarAgent();
		bool captured = false;
		AABB* DetectionRange = new AABB(100,100,this);
		void draw();
		
		void update(float deltaTime)override;
		
};


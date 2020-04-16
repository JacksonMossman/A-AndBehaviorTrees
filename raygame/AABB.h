#pragma once
#include "Agent.h"

class AABB :
	public Agent
{
public:
	float Width;
	float Height;
	float top();
	float bottom;
	float left();
	float right;
	AABB(float height, float width, Agent* parent);
	bool detectCollision(AABB other);
	virtual void update(float deltaTime);
	void draw() override;
	Agent* Parent = nullptr;
private:
	Color color = RED;
};


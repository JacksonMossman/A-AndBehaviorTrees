#include "KeyboardBehavior.h"

Vector2 KeyboardBehavior::update(Agent* agent, float deltaTime)
{
	Vector2 force = { 0, 0 };

	if (IsKeyDown(KEY_UP))		force.y = -500.0f;
	if (IsKeyDown(KEY_DOWN))	force.y = 500.0f;
	if (IsKeyDown(KEY_LEFT))	force.x = -500.0f;
	if (IsKeyDown(KEY_RIGHT))	force.x = 500.0f;

	return force;
}

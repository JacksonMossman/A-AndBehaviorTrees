#include "PlayerAgent.h"

PlayerAgent::PlayerAgent()
{
	intialize();
}

void PlayerAgent::intialize()
{
	setPosition(Vector2{ 1600.0f, 900.0f });
	setSpeed(500.0f);
	setColor(SKYBLUE);
	//Create and add keyboard behavior
	KeyboardBehavior* keyboardBehavior = new KeyboardBehavior();
	addBehavior(keyboardBehavior);
	//Create and add screen edge behavior
	ScreenEdgeBehavior* screenEdgeBehavior = new ScreenEdgeBehavior();
	addBehavior(screenEdgeBehavior);

}


#pragma once
#include "Vector2D.h"

class TransformComponent
{
public:
	void moveForward()
	{
		position.x += velocity.x;
	}
	void moveBackwards()
	{
		position.x -= velocity.x;
	}

	void moveUp()
	{
		position.y -= velocity.y;
	}
	void moveDown()
	{
		position.y += velocity.y;
	}
private:
	Vector2D position;
	Vector2D velocity;
};
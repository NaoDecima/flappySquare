#pragma once

#include <SDL.h>


class Player
{
public:
	Player()
		: velocity (0.1f), y(0), x(0), playerWidth(25),playerHeight(25), gravity(0.1f), jumpVelocity(-5.0f)
	{}
	~Player() {}

	void init()
	{
		playerCol.x = x = 375;
		playerCol.y = y = 250;
		playerCol.w =  playerWidth = 25;
		playerCol.h = playerHeight = 25;
		
	}
	void jump()
	{
		velocity = jumpVelocity;
	}
	void update()
	{
		velocity += gravity;
		playerCol.y = y += velocity;
	}
	
	void draw(SDL_Renderer* renderer)
	{
		
		SDL_Rect playerRect = { static_cast<int>(x),static_cast<int>(y), playerWidth,playerHeight };
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &playerRect);
		
	}
	void print()
	{
		std::cout <<"player position" << x << y << std::endl;
	}
	SDL_Rect getCol()
	{
		return playerCol;
	}

private:
	float velocity;
	float y,x;
	int playerWidth;
	int playerHeight;
	float gravity;
	const float jumpVelocity;
	SDL_Rect playerCol;
	
	


};
#pragma once
#include "SDL.h"


class Entity
{
public:
	Entity()
	{

	}
	~Entity()
	{

	}
	void update()
	{

	}
public:
	void setRect(const SDL_Rect* rect)
	{
		srcRect = rect;
	}
private:
	int x;
	int y;
	const SDL_Rect* srcRect = nullptr;
};
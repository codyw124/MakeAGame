#pragma once
#include <SDL.h>

class ItemDropper
{
public:
	virtual void dropItems(SDL_Renderer* renderer) = 0;
};
//cody ware
//2/21/2020

#pragma once

#include <iostream>
#include <SDL.h>
#include "GameObject.h"

class Item : public GameObject
{
public:
	Item(SDL_Point location = { 0,0 });
	void render(SDL_Renderer* renderer, const int& xOffset = 0, const int& yOffset = 0);
	void handleEvent(SDL_Event* event, SDL_Renderer* renderer);
private:
	SDL_Color color;
	int radius;
};

Item::Item(SDL_Point location)
{
	setLocation(location);
	color = { 0,0,255,255 };
	radius = 10;
}

void Item::render(SDL_Renderer* renderer, const int& xOffset, const int& yOffset)
{
	Uint8 rBefore;
	Uint8 gBefore;
	Uint8 bBefore;
	Uint8 aBefore;

	if (SDL_GetRenderDrawColor(renderer, &rBefore, &gBefore, &bBefore, &aBefore) != 0)
	{
		throw std::runtime_error("ERROR:clear screen couldnt get colors before\n");
	}
	else
	{
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		SDL_Helper::SDL_RenderFillCircle(renderer, position.x, position.y, radius);
	}
}

void Item::handleEvent(SDL_Event* event, SDL_Renderer* renderer)
{
}

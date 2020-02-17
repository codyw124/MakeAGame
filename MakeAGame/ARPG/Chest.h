#pragma once
#include <iostream>
#include <SDL.h>
#include "GameObject.h"

class Chest : public GameObject
{
public:
	Chest(SDL_Point location = {0,0});
	void render(SDL_Renderer* renderer, const int& xOffset = 0, const int& yOffset = 0);
	void handleEvent(SDL_Event* event, SDL_Renderer* renderer);

private:
	SDL_Color color;
	int width;
	int height;
};

Chest::Chest(SDL_Point location)
{
	setLocation(location);
	color = { 0,255,0,255 };
	width = 50;
	height = 50;
}

void Chest::render(SDL_Renderer* renderer, const int& xOffset, const int& yOffset)
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
		SDL_Rect chest = { position.x - (width / 2), position.y - (height / 2), width, height };
		SDL_RenderFillRect(renderer, &chest);
	}
}

void Chest::handleEvent(SDL_Event* event, SDL_Renderer* renderer)
{

}
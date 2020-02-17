#pragma once

#include <SDL.h>
#include "GameObject.h"

class Wall : public GameObject
{
public:
	Wall(SDL_Point location = { 0,0 }, const int& width = 0, const int& height = 0);
	void render(SDL_Renderer* renderer, const int& xOffset = 0, const int& yOffset = 0);
	void handleEvent(SDL_Event* event, SDL_Renderer* renderer);

private:
	SDL_Color color_;
	int width_;
	int height_;
};

Wall::Wall(SDL_Point location, const int& width, const int& height)
{
	setLocation(location);
	color_ = { 255,125,0,255 };
	width_ = width;
	height_ = height;
}

void Wall::render(SDL_Renderer* renderer, const int& xOffset, const int& yOffset)
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
		SDL_SetRenderDrawColor(renderer, color_.r, color_.g, color_.b, color_.a);
		SDL_Rect wall = { position.x, position.y, width_, height_ };
		SDL_RenderFillRect(renderer, &wall);
	}
}

void Wall::handleEvent(SDL_Event* event, SDL_Renderer* renderer)
{
	
}
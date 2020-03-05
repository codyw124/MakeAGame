//cody ware
//2/21/2020

#pragma once
#include <SDL.h>

class Renderable
{
public:
	virtual void render(SDL_Renderer* renderer, const int& x = 0, const int& y = 0) = 0;
	void renderAt(SDL_Renderer* renderer, const SDL_Point& location);
	void setLocation(const SDL_Point& location);
	SDL_Point& getLocation();
protected:
	SDL_Point position;
};

void Renderable::renderAt(SDL_Renderer* renderer, const SDL_Point& location)
{
	SDL_Point old(position);
	setLocation(location);
	render(renderer);
	position = old;
}

void Renderable::setLocation(const SDL_Point& location)
{
	position = location;
}

SDL_Point& Renderable::getLocation()
{
	return position;
}

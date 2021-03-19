//cody ware
//2/21/2020

#pragma once

#include <iostream>
#include <SDL.h>
#include "SDL_Helper.h"
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(SDL_Point location = { 0,0 });
	void render(SDL_Renderer* renderer, const int& xOffset = 0, const int& yOffset = 0);
	void handleEvent(SDL_Event* event, SDL_Renderer* renderer);
	size_t health;
	size_t mana;
	size_t maxHealth;
	size_t maxMana;
	
private:
	int radius;
	SDL_Color color;
	size_t movementSpeed;
	SDL_Point locationToMoveTo;
};

Player::Player(SDL_Point location)
{
	setLocation(location);
	locationToMoveTo = location;
	radius = 25;
	color = { 0,0,0,255 };
	movementSpeed = 1;
	health = 100;
	mana = 100;
	maxHealth = 100;
	maxMana = 100;
}

void Player::render(SDL_Renderer* renderer, const int& xOffset, const int& yOffset)
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

	SDL_SetRenderDrawColor(renderer, rBefore, gBefore, bBefore, aBefore);
}

void Player::handleEvent(SDL_Event* event, SDL_Renderer* renderer)
{
	//If mouse event happened
	if (event->type == SDL_MOUSEBUTTONDOWN)
	{
		//Get mouse position
		int x;
		int y;
		SDL_GetMouseState(&x, &y);
		
		std::cout << "destination:" << x << "," << y << std::endl;


	}

		//can this replace above x and y
		locationToMoveTo.x = x;
		locationToMoveTo.y = y;

	if (locationToMoveTo.x != position.x || locationToMoveTo.y != position.y)
	{
		if (locationToMoveTo.x > position.x)
		{
			position.x += movementSpeed;
		}
		else if (locationToMoveTo.x < position.x)
		{
			position.x -= movementSpeed;
		}
		if (locationToMoveTo.y > position.y)
		{
			position.y += movementSpeed;
		}
		else if (locationToMoveTo.y < position.y)
		{
			position.y -= movementSpeed;
		}
	}
}
//cody ware
//2/21/2020

#pragma once

#include <SDL.h>

class WindowMainLoop
{
public:
	virtual void runMainLoop(SDL_Window* window, SDL_Renderer* renderer) = 0;
protected:
	SDL_Event event;
	
	void clearScreen(SDL_Renderer* renderer);
};

void WindowMainLoop::clearScreen(SDL_Renderer* renderer)
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
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, rBefore, gBefore, bBefore, aBefore);
	}
}
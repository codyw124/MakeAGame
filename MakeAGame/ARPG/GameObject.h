#pragma once
#include "Renderable.h"
#include "EventHandler.h"

class GameObject : public Renderable, public EventHandler
{
public:
	void render(SDL_Renderer* renderer, const int& xOffset = 0, const int& yOffset = 0) = 0;
	void handleEvent(SDL_Event* event, SDL_Renderer* renderer) = 0;
};
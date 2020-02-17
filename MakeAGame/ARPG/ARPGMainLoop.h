#pragma once

#include <SDL.h>
#include "WindowMainLoop.h"
#include "Player.h"
#include "Wall.h"
#include "UI.h"
#include "Item.h"
#include "Enemy.h"
#include "Chest.h"
#include "Menu.h"
#include "XMLLoader.h"
#include "GameObject.h"

class ARPGMainLoop : public WindowMainLoop
{
public:
	virtual void runMainLoop(SDL_Window* window, SDL_Renderer* renderer);
};

void ARPGMainLoop::runMainLoop(SDL_Window* window, SDL_Renderer* renderer)
{
	//load stuff from xml
	XMLLoader xmlLoader;
	vector<GameObject*> renderables = xmlLoader("ARPGStuff.xml");

	//initialize screen and renderer stuff
	bool mainLoopRunning = true;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	clearScreen(renderer);
	SDL_RenderPresent(renderer);

	//while not quit
	while (mainLoopRunning)
	{
		SDL_PollEvent(&event);

		//User requests quit
		if (event.type == SDL_QUIT)
		{
			mainLoopRunning = false;
		}
		else
		{
			//handle events
			for (EventHandler* x : renderables)
			{
				x->handleEvent(&event, renderer);
			}

			//Clear screen
			clearScreen(renderer);

			//render stuff
			for (Renderable* x : renderables)
			{
				x->render(renderer);
			}

			//Update screen
			SDL_RenderPresent(renderer);
		}
	}
}
//cody ware
//2/21/2020

#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "GameObject.h"

class Menu : public GameObject
{
public:
	Menu();
	void render(SDL_Renderer* renderer, const int& xOffset = 0, const int& yOffset = 0);
	void initResumeSurface(SDL_Renderer* renderer);
	void handleEvent(SDL_Event* event, SDL_Renderer* renderer);
	~Menu();

private:
	SDL_Color backgroundColor;
	SDL_Color fontColor;
	bool open;
	SDL_Texture* resumeTexture;
	bool escapeCanBePressed;
	TTF_Font* font;
};

Menu::Menu()
{
	backgroundColor = { 255,192,203,255 };
	fontColor = { 0,0,0,255 };
	open = false;
	escapeCanBePressed = true;
	resumeTexture = NULL;
	font = TTF_OpenFont("Roboto-Medium.ttf", 12);

}

Menu::~Menu()
{
	SDL_DestroyTexture(resumeTexture);
	resumeTexture = NULL;
}

void Menu::render(SDL_Renderer* renderer, const int& xOffset, const int& yOffset)
{
	if (open) 
	{
		int w;
		int h;
		SDL_GetRendererOutputSize(renderer, &w, &h);

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
			SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
			SDL_Rect menuBackground = { w / 4, 0, w / 2, h };
			SDL_RenderFillRect(renderer, &menuBackground);

			if (resumeTexture == NULL)
			{
				initResumeSurface(renderer);
			}

			//Set rendering space and render to screen
			SDL_Rect renderQuad = { 250, 250, 250, 250};

			//Render to screen
			SDL_RenderCopyEx(renderer, resumeTexture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);

			SDL_SetRenderDrawColor(renderer, rBefore, gBefore, bBefore, aBefore);
		}
	}
}

void Menu::initResumeSurface(SDL_Renderer* renderer)
{
	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Resume", fontColor);
	if (textSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		//Create texture from surface pixels
		resumeTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (resumeTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			//mWidth = textSurface->w;
			//mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}
}

void Menu::handleEvent(SDL_Event* event, SDL_Renderer* renderer)
{
	if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE && escapeCanBePressed)
	{
		open = !open;
		escapeCanBePressed = false;
	} 
	else if (event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_ESCAPE)
	{
		escapeCanBePressed = true;
	}
}
//#pragma once
//
//#include <iostream>
//#include <SDL.h>
//#include "SDL_Helper.h"
//#include "GameObject.h"
//
//class UI : public GameObject
//{
//public:
//	UI();
//	void render(SDL_Renderer* renderer, const int& xOffset = 0, const int& yOffset = 0);
//	void handleEvent(SDL_Event* event, SDL_Renderer* renderer);
//	double missingHealthPercentage;
//	double missingManaPercent;
//};
//
//UI::UI()
//{
//	missingHealthPercentage = 0;
//	missingManaPercent = 0;
//}
//
//void UI::render(SDL_Renderer* renderer, const int& xOffset, const int& yOffset)
//{
//	Uint8 rBefore;
//	Uint8 gBefore;
//	Uint8 bBefore;
//	Uint8 aBefore;
//
//	if (SDL_GetRenderDrawColor(renderer, &rBefore, &gBefore, &bBefore, &aBefore) != 0)
//	{
//		throw std::runtime_error("ERROR:clear screen couldnt get colors before\n");
//	}
//	else
//	{
//		int w;
//		int h;
//		SDL_GetRendererOutputSize(renderer, &w, &h);
//		SDL_Rect uiBacking = { 0, h * 3 / 4, w, h / 4 };
//		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//		SDL_RenderFillRect(renderer, &uiBacking);
//
//		//health bar
//		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//		SDL_Helper::SDL_RenderFillCircle(renderer, w / 8, h - h / 8, h / 8);
//
//
//		//mana bar
//		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
//		SDL_Helper::SDL_RenderFillCircle(renderer, w - w / 8, h - h / 8, h / 8);
//
//		//covers
//		//health bar cover
//		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//		SDL_Rect healthCover = { 0, h * 3 / 4, w / 2, h / 4 * missingHealthPercentage};
//		SDL_Rect manaConver = { w / 2, h * 3 / 4, w / 2, h / 4 * missingManaPercent};
//		SDL_RenderFillRect(renderer, &healthCover);
//		SDL_RenderFillRect(renderer, &manaConver);
//
//	}
//}
//
//void UI::handleEvent(SDL_Event* event, SDL_Renderer* renderer)
//{
//}

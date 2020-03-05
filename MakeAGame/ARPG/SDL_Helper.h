//cody ware
//2/21/2020

#pragma once

#include <SDL.h>

class SDL_Helper
{
public:
	//found https://stackoverflow.com/questions/38334081/howto-draw-circles-arcs-and-vector-graphics-in-sdl
	//do not guarantee this works as i did not write it
	static void SDL_RenderDrawCircle(SDL_Renderer* renderer, int32_t centreX, int32_t centreY, int32_t radius);
	static void SDL_RenderFillCircle(SDL_Renderer* renderer, int32_t centreX, int32_t centreY, int32_t radius);
private:

};

void SDL_Helper::SDL_RenderDrawCircle(SDL_Renderer* renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
	const int32_t diameter = (radius * 2);

	int32_t x = (radius - 1);
	int32_t y = 0;
	int32_t tx = 1;
	int32_t ty = 1;
	int32_t error = (tx - diameter);

	while (x >= y)
	{
		//  Each of the following renders an octant of the circle
		SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
		SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
		SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
		SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
		SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
		SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
		SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
		SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

		if (error <= 0)
		{
			++y;
			error += ty;
			ty += 2;
		}

		if (error > 0)
		{
			--x;
			tx += 2;
			error += (tx - diameter);
		}
	}
}

void SDL_Helper::SDL_RenderFillCircle(SDL_Renderer* renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
	const int32_t diameter = (radius * 2);

	int32_t x = (radius - 1);
	int32_t y = 0;
	int32_t tx = 1;
	int32_t ty = 1;
	int32_t error = (tx - diameter);

	while (x >= y)
	{
		//  Each of the following renders an octant of the circle
		SDL_RenderDrawLine(renderer, centreX + x, centreY - y, centreX + x, centreY + y);
		SDL_RenderDrawLine(renderer, centreX - x, centreY - y, centreX - x, centreY + y);
		SDL_RenderDrawLine(renderer, centreX + y, centreY - x, centreX + y, centreY + x);
		SDL_RenderDrawLine(renderer, centreX - y, centreY - x, centreX - y, centreY + x);

		if (error <= 0)
		{
			++y;
			error += ty;
			ty += 2;
		}

		if (error > 0)
		{
			--x;
			tx += 2;
			error += (tx - diameter);
		}
	}
}
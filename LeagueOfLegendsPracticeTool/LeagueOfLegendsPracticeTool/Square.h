//cody ware
//9/25/2019

#pragma once

#include <SDL.h>
#include "Renderable.h"

class Square : public Renderable
{
public:
	Square(const int& x, const int& y, const int& w, const int& h);
	~Square();
	void render(SDL_Renderer* renderer);

private:

	SDL_Rect rect_;
};
//cody ware
//9/25/2019

#include "Square.h"

Square::Square(const int& x, const int& y, const int& w, const int& h) : Renderable()
{
	rect_.x = x;
	rect_.y = y;
	rect_.w = w;
	rect_.h = h;

}

Square::~Square()
{
}


void Square::render(SDL_Renderer* renderer) const
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &rect_);
}
//Cody Ware
//5/19/19

#pragma once

#include <list>
#include <string>
#include <SDL.h>
#include "Matrix.h"

class Renderable
{
private:
	Matrix transform_;
public:
	Renderable();
	~Renderable();
	virtual void render(SDL_Renderer* renderer) const = 0;
};
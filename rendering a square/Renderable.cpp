//Cody Ware
//5/19/19

#include "Renderable.h"

Renderable::Renderable()
{
	transform_ = Matrix(3, 3);
	transform_[0][0] = 0;
	transform_[1][1] = 0;
	transform_[2][2] = 0;
}

Renderable::~Renderable()
{
}
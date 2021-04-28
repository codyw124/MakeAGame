//Cody Ware
//4/3/21 
#include "Circle.h"

Circle::Circle(const Point& position, const double& radius)
{
	position_ = position;
	radius_ = radius;
}

Circle::~Circle()
{
}

Point Circle::getPosition() const
{
	return position_;
}

double Circle::getRadius() const
{
	return radius_;
}

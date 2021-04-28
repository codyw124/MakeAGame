//Cody Ware
//4/3/21 

#include "Rectangle.h"

Rectangle::Rectangle(const Point& origin, const PhysicsVector& size)
{
	origin_ = origin;
	size_ = size;
}

Rectangle::Rectangle(const PhysicsVector& min, const PhysicsVector& max)
{
	origin_ = min;
	size_ = max - min;
}

Rectangle::~Rectangle()
{
}

PhysicsVector Rectangle::getMin() const
{
	PhysicsVector p1 = origin_;
	PhysicsVector p2 = origin_ + size_;
	double* values = new double[2];
	values[0] = fminf(p1[0], p2[0]);
	values[1] = fminf(p1[1], p2[1]);
	return PhysicsVector(values, 2);
}

PhysicsVector Rectangle::getMax() const
{
	PhysicsVector p1 = origin_;
	PhysicsVector p2 = origin_ + size_;
	double* values = new double[2];
	values[0] = fminf(p1[0], p2[0]);
	values[1] = fminf(p1[1], p2[1]);
	return PhysicsVector(values, 2);
}

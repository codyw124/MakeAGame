//Cody Ware
//4/3/21 

#pragma once

#include "PhysicsVector.h"
#include "Point.h";
//TODO BIG5(6)
class Rectangle
{
public:
	Rectangle(const Point& origin, const PhysicsVector& size);
	Rectangle(const PhysicsVector& min, const PhysicsVector& max);
	~Rectangle();

	PhysicsVector getMin() const;
	PhysicsVector getMax() const;

private:
	Point origin_;
	PhysicsVector size_;
};

//Cody Ware
//4/3/21 

#pragma once

#include "PhysicsVector.h"
#include "Point.h";
//TODO BIG5(6)
class OrientedRectangle
{
public:
	OrientedRectangle();
	OrientedRectangle(const Point& position, const PhysicsVector& halfExtents);
	OrientedRectangle(const Point& position, const PhysicsVector& halfExtents, const double& rotation);
	~OrientedRectangle();

private:
	Point position_;
	PhysicsVector halfExtents_;
	double rotation_;
};

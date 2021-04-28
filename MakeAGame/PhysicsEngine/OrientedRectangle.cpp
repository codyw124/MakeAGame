//Cody Ware
//4/3/21 

#include "OrientedRectangle.h"

OrientedRectangle::OrientedRectangle()
{
	double* values = new double[2];
	values[0] = 1.0;
	values[1] = 1.0;

	halfExtents_ = PhysicsVector(values, 2);
	rotation_ = 0.0;
}

OrientedRectangle::OrientedRectangle(const Point& position, const PhysicsVector& halfExtents)
{
	rotation_ = 0.0;
	position_ = position;
	halfExtents_ = halfExtents;
}

OrientedRectangle::OrientedRectangle(const Point& position, const PhysicsVector& halfExtents, const double& rotation)
{
	rotation_ = rotation;
	position_ = position;
	halfExtents_ = halfExtents;
}

OrientedRectangle::~OrientedRectangle()
{
}

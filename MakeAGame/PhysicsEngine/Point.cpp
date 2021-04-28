//Cody Ware
//4/3/21 

#include "Point.h"
#include "PhysicsHelper.h"

Point::Point()
{
	PhysicsVector();
}

Point::Point(double* dimensionValues, const size_t& numberOfDimensions)
{
	PhysicsVector(dimensionValues, numberOfDimensions);
}

Point::Point(const PhysicsVector& other)
{
	PhysicsVector(other);
}

Point::Point(PhysicsVector&& other) noexcept
{
	PhysicsVector(other);
}

Point& Point::operator=(const PhysicsVector& other)
{
	PhysicsVector::operator=(other);
}

Point& Point::operator=(PhysicsVector&& other) noexcept
{
	PhysicsVector::operator*(other);
}

Point::~Point()
{
	
}

bool Point::onLine(const Line& line)
{
	// Find the slope
	double dy = (line.getEnd()[1] - line.getStart()[1]);
	double dx = (line.getEnd()[0] - line.getStart()[0]);
	double slope = dy / dx;
	// Find the Y-Intercept
	double yIntercept = line.getStart()[1] - slope * line.getStart()[0];
	// Check line equation
	return PhysicsHelper::epsilonCompare(dimensionValues_[1], slope * dimensionValues_[0] + yIntercept);
}

bool Point::inCircle(const Circle& c)
{
	Line line(*this, c.getPosition());
	return line.lengthSquared() < (c.getRadius() * c.getRadius());
}

bool Point::inRectangle(const Rectangle& rectangle)
{
	PhysicsVector min = rectangle.getMin();
	PhysicsVector max = rectangle.getMax();
	return min[0] <= (*this)[0] &&	min[1] <= (*this)[1] && (*this)[0] <= max[0] && (*this)[1] <= max[1];
}

bool Point::inOrientedRectangle(const OrientedRectangle& rectangle)
{
	return false;
}

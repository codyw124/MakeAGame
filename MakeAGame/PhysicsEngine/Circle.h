//Cody Ware
//4/3/21 

#pragma once

#include "Point.h";
//TODO BIG5(6)
class Circle
{
public:
	Circle(const Point& position, const double& radius);
	~Circle();

	Point getPosition() const;
	double getRadius() const;

private:
	Point position_;
	double radius_;
};

//Cody Ware
//7/26/19 

#pragma once

#include "Point2D.h";
//TODO BIG5(6)
class Line2D
{
public:
	Line2D();
	~Line2D();

	double magnitude() const;
	double magnitudeSquared() const;

private:
	Point2D start;
	Point2D end;

};

Line2D::Line2D()
{
}

Line2D::~Line2D()
{
}

double Line2D::magnitude() const
{
	return (start - end).magnitude();
}

double Line2D::magnitudeSquared() const
{
	return (start - end).magnitudeSquared();
}

//Cody Ware
//7/26/19 

#pragma once

#include "Point3D.h";
//TODO BIG5(6)
class Line3D
{
public:
	Line3D();
	~Line3D();

	double magnitude() const;
	double magnitudeSquared() const;

private:
	Point3D start;
	Point3D end;

};

Line3D::Line3D()
{
}

Line3D::~Line3D()
{
}

double Line3D::magnitude() const
{
	return (start - end).magnitude();
}

double Line3D::magnitudeSquared() const
{
	return (start - end).magnitudeSquared();
}

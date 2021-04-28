//Cody Ware
//4/3/2021

#include "Line.h"

Line::Line()
{
	double* startValues = new double[2];
	startValues[0] = 0.0;
	startValues[1] = 0.0;

	double* endValues = new double[2];
	endValues[0] = 0.0;
	endValues[1] = 0.0;

	Point start(startValues, 2);
	Point end(endValues, 2);

	initLine(start, end);
}

Line::Line(const double& x1, const double& y1, const double& x2, const double& y2)
{
	double* startValues = new double[2];
	startValues[0] = x1;
	startValues[1] = y1;

	double* endValues = new double[2];
	endValues[0] = x2;
	endValues[1] = y2;

	Point start(startValues, 2);
	Point end(endValues, 2);

	initLine(start, end);
}

Line::Line(const Point& start, const Point& end)
{
	initLine(start, end);
}

Line::~Line()
{
}

double Line::length() const
{
	return (start_ - end_).magnitude();
}

double Line::lengthSquared() const
{
	return (start_ - end_).magnitudeSquared();
}

Point Line::getStart() const
{
	return start_;
}

Point Line::getEnd() const
{
	return end_;
}


void Line::initLine(const Point& start, const Point& end)
{
	start_ = start;
	end_ = end;
}
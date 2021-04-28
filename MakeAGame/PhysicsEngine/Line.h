//Cody Ware
//7/26/19 

#pragma once

#include "Point.h";
//TODO BIG5(6)
class Line
{
public:
	Line();
	Line(const double& x1, const double& y1, const double& x2, const double& y2);
	Line(const Point& start, const Point& end);
	~Line();

	double length() const;
	double lengthSquared() const;

	Point getStart() const;
	Point getEnd() const;

private:
	Point start_;
	Point end_;

	void initLine(const Point& start, const Point& end);
};

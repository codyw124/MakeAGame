//Cody Ware
//7/26/19 

#pragma once

#ifndef PHYSICSENGINE_EXPORTS
#define PHYSICSENGINE __declspec(dllexport)
#else
#define PHYSICSENGINE __declspec(dllimport)
#endif

#include "PhysicsVector.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"
#include "OrientedRectangle.h"

class PHYSICSENGINE Point : public PhysicsVector
{
public:
	Point();
	Point(double* dimensionValues, const size_t& numberOfDimensions);
	Point(const PhysicsVector& other);
	Point(PhysicsVector&& other) noexcept;
	Point& operator=(const PhysicsVector& other);
	Point& operator=(PhysicsVector&& other) noexcept;
	~Point();

	bool onLine(const Line& line);
	bool inCircle(const Circle& c);
	bool inRectangle(const Rectangle& rectangle);
	bool inOrientedRectangle(const OrientedRectangle& rectangle);
private:
};
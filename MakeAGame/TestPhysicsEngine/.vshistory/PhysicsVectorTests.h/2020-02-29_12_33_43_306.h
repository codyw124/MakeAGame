//Cody Ware
//10/2/18

#pragma once

#include <iostream>
#include <sstream>
#include <cmath>
#include <cfloat>
#include "PhysicsVector.h"
#include "Test.h"

using namespace std;

class PhysicsVectorTests : public Test
{
public:
	void runAllTests();

	void constructor2D();
	void constructorWithValues2D();
	void copyConstructor2D();
	void moveConstructor2D();
	void assignmentOperator2D();
	void moveAssignmentOperator2D();
	void additionOperator2D();
	void subtractionOperator2D();
	void multiplyOperator2D();
	void multiplyByDoubleOperator2D();
	void equivalenceOperators2D();
	void dotProduct2D();
	void magnitude2D();
	void magnitudeSquared2D();
	void divideOperator2D();
	void divideByDoubleOperator2D();
	void additionShorthandOperator2D();
	void subtractionShorthandOperator2D();
	void multiplyShorthandOperator2D();
	void multiplyByDoubleShorthandOperator2D();
	void divideShorthandOperator2D();
	void divideByDoubleShorthandOperator2D();
	void distance2D();
	void distanceSquared2D();
	void normalize2D();
	void normalized2D();
	void project2D();
	void outputOperator2D();
	void perpendicular2D();
	void rotate2D();
	void angle2D();
	void reflect2D();
	void constructor3D();
	void constructorWithValues3D();
	void copyConstructor3D();
	void moveConstructor3D();
	void assignmentOperator3D();
	void moveAssignmentOperator3D();
	void additionOperator3D();
	void subtractionOperator3D();
	void multiply2Vector3sOperator3D();
	void multiplyVector3ByDouble3D();
	void equivalenceOperators3D();
	void dotProduct3D();
	void magnitude3D();
	void magnitudeSquared3D();
	void divide2Vector3sOperator3D();
	void divideVector3ByDoubleOperator3D();
	void additionShorthandOperator3D();
	void subtractionShorthandOperator3D();
	void multiply2Vector3sShorthandOperator3D();
	void multiplyVector3ByDoubleShorthandOperator3D();
	void divide2Vector3sShorthandOperator3D();
	void divideVector3ByDoubleShorthandOperator3D();
	void distance3D();
	void distanceSquared3D();
	void normalize3D();
	void normalized3D();
	void project3D();
	void outputOperator3D();
	void perpendicular3D();
	void angle3D();
	void reflect3D();
	void crossProduct3D();
};
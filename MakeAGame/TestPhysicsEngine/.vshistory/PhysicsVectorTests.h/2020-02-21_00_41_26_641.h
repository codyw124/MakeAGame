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

	void T01_constructor2D();
	void T02_constructorWithValues2D();
	void T03_copyConstructor2D();
	void T04_moveConstructor2D();
	void T05_assignmentOperator2D();
	void T06_moveAssignmentOperator2D();
	void T07_additionOperator2D();
	void T08_subtractionOperator2D();
	void T09_multiplyOperator2D();
	void T10_multiplyByDoubleOperator2D();
	void T11_equivalenceOperators2D();
	void T12_dotProduct2D();
	void T13_magnitude2D();
	void T14_magnitudeSquared2D();
	void T15_divideOperator2D();
	void T16_divideByDoubleOperator2D();
	void T17_additionShorthandOperator2D();
	void T18_subtractionShorthandOperator2D();
	void T19_multiplyShorthandOperator2D();
	void T20_multiplyByDoubleShorthandOperator2D();
	void T21_divideShorthandOperator2D();
	void T22_divideByDoubleShorthandOperator2D();
	void T23_distance2D();
	void T24_distanceSquared2D();
	void T25_normalize2D();
	void T26_normalized2D();
	void T27_project2D();
	void T28_outputOperator2D();
	void T29_perpendicular2D();
	void T30_rotate2D();
	void T31_angle2D();
	void T32_reflect2D();
	void T33_constructor3D();
	void T34_constructorWithValues3D();
	void T35_copyConstructor3D();
	void T36_moveConstructor3D();
	void T37_assignmentOperator3D();
	void T38_moveAssignmentOperator3D();
	void T39_additionOperator3D();
	void T40_subtractionOperator3D();
	void T41_multiply2Vector3sOperator3D();
	void T42_multiplyVector3ByDouble3D();
	void T43_equivalenceOperators3D();
	void T44_dotProduct3D();
	void T45_magnitude3D();
	void T46_magnitudeSquared3D();
	void T47_divide2Vector3sOperator3D();
	void T48_divideVector3ByDoubleOperator3D();
	void T49_additionShorthandOperator3D();
	void T50_subtractionShorthandOperator3D();
	void T51_multiply2Vector3sShorthandOperator3D();
	void T52_multiplyVector3ByDoubleShorthandOperator3D();
	void T53_divide2Vector3sShorthandOperator3D();
	void T54_divideVector3ByDoubleShorthandOperator3D();
	void T55_distance3D();
	void T56_distanceSquared3D();
	void T57_normalize3D();
	void T58_normalized3D();
	void T59_project3D();
	void T60_outputOperator3D();
	void T61_perpendicular3D();
	void T62_angle3D();
	void T63_reflect3D();
	void T64_crossProduct3D();
};
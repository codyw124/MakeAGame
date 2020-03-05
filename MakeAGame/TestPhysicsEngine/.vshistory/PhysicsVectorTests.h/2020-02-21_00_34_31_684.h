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

	static void T01_constructor2D();
	static void T02_constructorWithValues2D();
	static void T03_copyConstructor2D();
	static void T04_moveConstructor2D();
	static void T05_assignmentOperator2D();
	static void T06_moveAssignmentOperator2D();
	static void T07_additionOperator2D();
	static void T08_subtractionOperator2D();
	static void T09_multiplyOperator2D();
	static void T10_multiplyByDoubleOperator2D();
	static void T11_equivalenceOperators2D();
	static void T12_dotProduct2D();
	static void T13_magnitude2D();
	static void T14_magnitudeSquared2D();
	static void T15_divideOperator2D();
	static void T16_divideByDoubleOperator2D();
	static void T17_additionShorthandOperator2D();
	static void T18_subtractionShorthandOperator2D();
	static void T19_multiplyShorthandOperator2D();
	static void T20_multiplyByDoubleShorthandOperator2D();
	static void T21_divideShorthandOperator2D();
	static void T22_divideByDoubleShorthandOperator2D();
	static void T23_distance2D();
	static void T24_distanceSquared2D();
	static void T25_normalize2D();
	static void T26_normalized2D();
	static void T27_project2D();
	static void T28_outputOperator2D();
	static void T29_perpendicular2D();
	static void T30_rotate2D();
	static void T31_angle2D();
	static void T32_reflect2D();
	static void T33_constructor3D();
	static void T34_constructorWithValues3D();
	static void T35_copyConstructor3D();
	static void T36_moveConstructor3D();
	static void T37_assignmentOperator3D();
	static void T38_moveAssignmentOperator3D();
	static void T39_additionOperator3D();
	static void T40_subtractionOperator3D();
	static void T41_multiply2Vector3sOperator3D();
	static void T42_multiplyVector3ByDouble3D();
	static void T43_equivalenceOperators3D();
	static void T44_dotProduct3D();
	static void T45_magnitude3D();
	static void T46_magnitudeSquared3D();
	static void T47_divide2Vector3sOperator3D();
	static void T48_divideVector3ByDoubleOperator3D();
	static void T49_additionShorthandOperator3D();
	static void T50_subtractionShorthandOperator3D();
	static void T51_multiply2Vector3sShorthandOperator3D();
	static void T52_multiplyVector3ByDoubleShorthandOperator3D();
	static void T53_divide2Vector3sShorthandOperator3D();
	static void T54_divideVector3ByDoubleShorthandOperator3D();
	static void T55_distance3D();
	static void T56_distanceSquared3D();
	static void T57_normalize3D();
	static void T58_normalized3D();
	static void T59_project3D();
	static void T60_outputOperator3D();
	static void T61_perpendicular3D();
	static void T62_angle3D();
	static void T63_reflect3D();
	static void T64_crossProduct3D();
};
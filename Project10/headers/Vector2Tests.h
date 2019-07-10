//Cody Ware
//10/2/18

#pragma once

#include <iostream>
#include <sstream>
#include <cmath>
#include <cfloat>
#include "Vector2.h"
#include "Test.h"

using namespace std;

class Vector2Tests : public Test
{
	public:
		void runAllTests();
	
	private:
		void T01_constructor();
		void T02_constructorWithValues();
		void T03_copyConstructor();
		void T04_moveConstructor();
		void T05_assignmentOperator();
		void T06_moveAssignmentOperator();
		void T07_additionOperator();
		void T08_subtractionOperator();
		void T09_multiplyOperator();
		void T10_multiplyByDoubleOperator();
		void T11_equivalenceOperators();
		void T12_dotProduct();
		void T13_magnitude();
		void T14_magnitudeSquared();
		void T15_divideOperator();
		void T16_divideByDoubleOperator();
		void T17_additionShorthandOperator();
		void T18_subtractionShorthandOperator();
		void T19_multiplyShorthandOperator();
		void T20_multiplyByDoubleShorthandOperator();
		void T21_divideShorthandOperator();
		void T22_divideByDoubleShorthandOperator();
		void T23_distance();
		void T24_distanceSquared();
		void T25_normalize();
		void T26_normalized();
		void T27_project();
		void T28_outputOperator();
		void T29_perpendicular();
		void T30_rotate();
		void T31_angle();
		void T32_reflect();
};
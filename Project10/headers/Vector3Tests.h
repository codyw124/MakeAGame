//Cody Ware
//10/4/18

#pragma once

#include <iostream>
#include <sstream>
#include <cmath>
#include <cfloat>
#include "Vector3.h"
#include "Test.h"

using namespace std;

class Vector3Tests : public Test
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
        void T09_multiply2Vector3sOperator();
        void T10_multiplyVector3ByDouble();
        void T11_equivalenceOperators();
        void T12_dotProduct();
        void T13_magnitude();
        void T14_magnitudeSquared();
        void T15_divide2Vector3sOperator();
        void T16_divideVector3ByDoubleOperator();
        void T17_additionShorthandOperator();
        void T18_subtractionShorthandOperator();
        void T19_multiply2Vector3sShorthandOperator();
        void T20_multiplyVector3ByDoubleShorthandOperator();
        void T21_divide2Vector3sShorthandOperator();
        void T22_divideVector3ByDoubleShorthandOperator();
        void T23_distance();
        void T24_distanceSquared();
        void T25_normalize();
        void T26_normalized();
        void T27_project();
        void T28_outputOperator();
        void T29_perpendicular();
        void T30_angle();
        void T31_reflect();
        void T32_crossProduct();
};
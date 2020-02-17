//Cody Ware
//5/30/19

#pragma once

#include <iostream>
#include "Matrix.h"
#include "Test.h"

using namespace std;

class MatricesTests : public Test
{
    public:
        void runAllTests();
    private:
        void T01_defaultConstructor();
        void T02_copyConstructor();
        void T03_moveConstructor();
        void T04_assignmentOperator();
        void T05_moveAssignmentOperator();
        void T06_accessOperator();
        void T07_transpose();
        void T08_transposed();
        void T09_multiplicationOperator();
        void T10_additionOperator();
        void T11_subtractionOperator();
        void T12_equivalence();
        void T13_outputoperator();
        void T15_cut();
        void T16_testDeterminant();
        void T17_testMinors();
        void T18_testCofactors();
        void T19_testAdjugate();
        void T20_testInverse();
};
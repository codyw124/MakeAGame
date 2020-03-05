//Cody Ware
//5/30/19

#pragma once

#include "Matrix.h"

class MatricesTests
{
public:
    void defaultConstructor();
    void copyConstructor();
    void moveConstructor();
    void assignmentOperator();
    void moveAssignmentOperator();
    void accessOperator();
    void transpose();
    void transposed();
    void multiplicationOperator();
    void additionOperator();
    void subtractionOperator();
    void equivalence();
    void outputoperator();
    void cut();
    void testDeterminant();
    void testMinors();
    void testCofactors();
    void testAdjugate();
    void testInverse();
};
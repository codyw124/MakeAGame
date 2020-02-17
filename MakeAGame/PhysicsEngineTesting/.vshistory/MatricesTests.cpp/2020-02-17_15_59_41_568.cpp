//Cody Ware
//5/30/19

#include "../headers/MatricesTests.h"

void MatricesTests::runAllTests()
{
	T01_defaultConstructor();
	T02_copyConstructor();
	T03_moveConstructor();
	T04_assignmentOperator();
	T05_moveAssignmentOperator();
	T06_accessOperator();
	T07_transpose();
	T08_transposed();
	T09_multiplicationOperator();
	T10_additionOperator();
	T11_subtractionOperator();
	T12_equivalence();
	T13_outputoperator();
	T15_cut();
	T16_testDeterminant();
	T17_testMinors();
	T18_testCofactors();
	T19_testAdjugate();
	T20_testInverse();

	cout<< "Passed: All Matrices Tests" << endl;
}

void MatricesTests::T01_defaultConstructor()
{
	Matrix a(3, 3);

	assert(1.0 == a[0][0], "T01_defaultConstructor");
	assert(0.0 == a[0][1], "T01_defaultConstructor");
	assert(0.0 == a[0][2], "T01_defaultConstructor");
	assert(0.0 == a[1][0], "T01_defaultConstructor");
	assert(1.0 == a[1][1], "T01_defaultConstructor");
	assert(0.0 == a[1][2], "T01_defaultConstructor");
	assert(0.0 == a[2][0], "T01_defaultConstructor");
	assert(0.0 == a[2][1], "T01_defaultConstructor");
	assert(1.0 == a[2][2], "T01_defaultConstructor");

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	assert(0.0 == a[0][0], "T01_defaultConstructor");
	assert(1.0 == a[0][1], "T01_defaultConstructor");
	assert(2.0 == a[0][2], "T01_defaultConstructor");
	assert(3.0 == a[1][0], "T01_defaultConstructor");
	assert(4.0 == a[1][1], "T01_defaultConstructor");
	assert(5.0 == a[1][2], "T01_defaultConstructor");
	assert(6.0 == a[2][0], "T01_defaultConstructor");
	assert(7.0 == a[2][1], "T01_defaultConstructor");
	assert(8.0 == a[2][2], "T01_defaultConstructor");
}

void MatricesTests::T02_copyConstructor()
{
	Matrix a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	assert(0.0 == a[0][0], "T02_copyConstructor");
	assert(1.0 == a[0][1], "T02_copyConstructor");
	assert(2.0 == a[0][2], "T02_copyConstructor");
	assert(3.0 == a[1][0], "T02_copyConstructor");
	assert(4.0 == a[1][1], "T02_copyConstructor");
	assert(5.0 == a[1][2], "T02_copyConstructor");
	assert(6.0 == a[2][0], "T02_copyConstructor");
	assert(7.0 == a[2][1], "T02_copyConstructor");
	assert(8.0 == a[2][2], "T02_copyConstructor");

	Matrix b(a);

	assert(0.0 == b[0][0], "T02_copyConstructor");
	assert(1.0 == b[0][1], "T02_copyConstructor");
	assert(2.0 == b[0][2], "T02_copyConstructor");
	assert(3.0 == b[1][0], "T02_copyConstructor");
	assert(4.0 == b[1][1], "T02_copyConstructor");
	assert(5.0 == b[1][2], "T02_copyConstructor");
	assert(6.0 == b[2][0], "T02_copyConstructor");
	assert(7.0 == b[2][1], "T02_copyConstructor");
	assert(8.0 == b[2][2], "T02_copyConstructor");

	b[0][0] = 7;

	assert(7.0 == b[0][0], "T02_copyConstructor");
	assert(0.0 == a[0][0], "T02_copyConstructor");
}

void MatricesTests::T03_moveConstructor()
{
	//make a 3X3 matrix with those values
	Matrix a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	//make sure they are in the matrix
	assert(0.0 == a[0][0], "T03_moveConstructor");
	assert(1.0 == a[0][1], "T03_moveConstructor");
	assert(2.0 == a[0][2], "T03_moveConstructor");
	assert(3.0 == a[1][0], "T03_moveConstructor");
	assert(4.0 == a[1][1], "T03_moveConstructor");
	assert(5.0 == a[1][2], "T03_moveConstructor");
	assert(6.0 == a[2][0], "T03_moveConstructor");
	assert(7.0 == a[2][1], "T03_moveConstructor");
	assert(8.0 == a[2][2], "T03_moveConstructor");

	//make a matrix and move the memory of 'a' into this matrix
	Matrix moveHere(std::move(a));

	//make sure the rows and columns reflect the dimensions of a matrix with no data
	assert(0 == a.getRows(), "T03_moveConstructor");
	assert(0 == a.getColumns(), "T03_moveConstructor");

	//make sure that everything got moved
	assert(0.0 == moveHere[0][0], "T03_moveConstructor");
	assert(1.0 == moveHere[0][1], "T03_moveConstructor");
	assert(2.0 == moveHere[0][2], "T03_moveConstructor");
	assert(3.0 == moveHere[1][0], "T03_moveConstructor");
	assert(4.0 == moveHere[1][1], "T03_moveConstructor");
	assert(5.0 == moveHere[1][2], "T03_moveConstructor");
	assert(6.0 == moveHere[2][0], "T03_moveConstructor");
	assert(7.0 == moveHere[2][1], "T03_moveConstructor");
	assert(8.0 == moveHere[2][2], "T03_moveConstructor");
}

void MatricesTests::T04_assignmentOperator()
{
	//make a 3X3 matrix with those values
	Matrix a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	//make sure they are in the matrix
	assert(0.0 == a[0][0], "T04_assignmentOperator");
	assert(1.0 == a[0][1], "T04_assignmentOperator");
	assert(2.0 == a[0][2], "T04_assignmentOperator");
	assert(3.0 == a[1][0], "T04_assignmentOperator");
	assert(4.0 == a[1][1], "T04_assignmentOperator");
	assert(5.0 == a[1][2], "T04_assignmentOperator");
	assert(6.0 == a[2][0], "T04_assignmentOperator");
	assert(7.0 == a[2][1], "T04_assignmentOperator");
	assert(8.0 == a[2][2], "T04_assignmentOperator");

	//make a matrix and move the memory of 'a' into this matrix
	Matrix assignment(3, 3);

	assignment = a;

	//check that 'a' still has its original values
	assert(0.0 == a[0][0], "T04_assignmentOperator");
	assert(1.0 == a[0][1], "T04_assignmentOperator");
	assert(2.0 == a[0][2], "T04_assignmentOperator");
	assert(3.0 == a[1][0], "T04_assignmentOperator");
	assert(4.0 == a[1][1], "T04_assignmentOperator");
	assert(5.0 == a[1][2], "T04_assignmentOperator");
	assert(6.0 == a[2][0], "T04_assignmentOperator");
	assert(7.0 == a[2][1], "T04_assignmentOperator");
	assert(8.0 == a[2][2], "T04_assignmentOperator");

	//make sure that everything got moved
	assert(0.0 == assignment[0][0], "T04_assignmentOperator");
	assert(1.0 == assignment[0][1], "T04_assignmentOperator");
	assert(2.0 == assignment[0][2], "T04_assignmentOperator");
	assert(3.0 == assignment[1][0], "T04_assignmentOperator");
	assert(4.0 == assignment[1][1], "T04_assignmentOperator");
	assert(5.0 == assignment[1][2], "T04_assignmentOperator");
	assert(6.0 == assignment[2][0], "T04_assignmentOperator");
	assert(7.0 == assignment[2][1], "T04_assignmentOperator");
	assert(8.0 == assignment[2][2], "T04_assignmentOperator");
}

void MatricesTests::T05_moveAssignmentOperator()
{
	//make a 3X3 matrix with those values
	Matrix a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	//make sure they are in the matrix
	assert(0.0 == a[0][0], "T05_moveAssignmentOperator");
	assert(1.0 == a[0][1], "T05_moveAssignmentOperator");
	assert(2.0 == a[0][2], "T05_moveAssignmentOperator");
	assert(3.0 == a[1][0], "T05_moveAssignmentOperator");
	assert(4.0 == a[1][1], "T05_moveAssignmentOperator");
	assert(5.0 == a[1][2], "T05_moveAssignmentOperator");
	assert(6.0 == a[2][0], "T05_moveAssignmentOperator");
	assert(7.0 == a[2][1], "T05_moveAssignmentOperator");
	assert(8.0 == a[2][2], "T05_moveAssignmentOperator");

	//make a matrix and move the memory of 'a' into this matrix
	Matrix moveHere = std::move(a);

	//make sure the rows and columns reflect the dimensions of a matrix with no data
	assert(0 == a.getRows(), "T05_moveAssignmentOperator");
	assert(0 == a.getColumns(), "T05_moveAssignmentOperator");

	//make sure that everything got moved
	assert(0.0 == moveHere[0][0], "T05_moveAssignmentOperator");
	assert(1.0 == moveHere[0][1], "T05_moveAssignmentOperator");
	assert(2.0 == moveHere[0][2], "T05_moveAssignmentOperator");
	assert(3.0 == moveHere[1][0], "T05_moveAssignmentOperator");
	assert(4.0 == moveHere[1][1], "T05_moveAssignmentOperator");
	assert(5.0 == moveHere[1][2], "T05_moveAssignmentOperator");
	assert(6.0 == moveHere[2][0], "T05_moveAssignmentOperator");
	assert(7.0 == moveHere[2][1], "T05_moveAssignmentOperator");
	assert(8.0 == moveHere[2][2], "T05_moveAssignmentOperator");
}

void MatricesTests::T06_accessOperator()
{
	//make a 3X3 matrix with those values
	Matrix a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	//make sure they are in the matrix
	assert(0.0 == a[0][0], "T06_accessOperator");
	assert(1.0 == a[0][1], "T06_accessOperator");
	assert(2.0 == a[0][2], "T06_accessOperator");
	assert(3.0 == a[1][0], "T06_accessOperator");
	assert(4.0 == a[1][1], "T06_accessOperator");
	assert(5.0 == a[1][2], "T06_accessOperator");
	assert(6.0 == a[2][0], "T06_accessOperator");
	assert(7.0 == a[2][1], "T06_accessOperator");
	assert(8.0 == a[2][2], "T06_accessOperator");

	const int X = 0;
	assert(0.0 == a[X][X], "T06_accessOperator");
}

void MatricesTests::T07_transpose()
{
	//make a 3X3 matrix with those values
	Matrix a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	//make sure they are in the matrix
	assert(0.0 == a[0][0], "T07_transpose");assert(1.0 == a[0][1], "T07_transpose");assert(2.0 == a[0][2], "T07_transpose");
	assert(3.0 == a[1][0], "T07_transpose");assert(4.0 == a[1][1], "T07_transpose");assert(5.0 == a[1][2], "T07_transpose");
	assert(6.0 == a[2][0], "T07_transpose");assert(7.0 == a[2][1], "T07_transpose");assert(8.0 == a[2][2], "T07_transpose");

	//transpose it
	a.transpose();

	//make sure they are transposed
	assert(0.0 == a[0][0], "T07_transpose");assert(3.0 == a[0][1], "T07_transpose");assert(6.0 == a[0][2], "T07_transpose");
	assert(1.0 == a[1][0], "T07_transpose");assert(4.0 == a[1][1], "T07_transpose");assert(7.0 == a[1][2], "T07_transpose");
	assert(2.0 == a[2][0], "T07_transpose");assert(5.0 == a[2][1], "T07_transpose");assert(8.0 == a[2][2], "T07_transpose");
}

void MatricesTests::T08_transposed()
{

	//make a 3X3 matrix with those values
	Matrix a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	//make sure they are in the matrix
	assert(0.0 == a[0][0], "T08_transposed");
	assert(1.0 == a[0][1], "T08_transposed");
	assert(2.0 == a[0][2], "T08_transposed");
	assert(3.0 == a[1][0], "T08_transposed");
	assert(4.0 == a[1][1], "T08_transposed");
	assert(5.0 == a[1][2], "T08_transposed");
	assert(6.0 == a[2][0], "T08_transposed");
	assert(7.0 == a[2][1], "T08_transposed");
	assert(8.0 == a[2][2], "T08_transposed");

	//transpose it
	Matrix transposed = a.transposed();

	//make sure they are transposed
	assert(0.0 == transposed[0][0], "T08_transposed");
	assert(3.0 == transposed[0][1], "T08_transposed");
	assert(6.0 == transposed[0][2], "T08_transposed");
	assert(1.0 == transposed[1][0], "T08_transposed");
	assert(4.0 == transposed[1][1], "T08_transposed");
	assert(7.0 == transposed[1][2], "T08_transposed");
	assert(2.0 == transposed[2][0], "T08_transposed");
	assert(5.0 == transposed[2][1], "T08_transposed");
	assert(8.0 == transposed[2][2], "T08_transposed");
}

void MatricesTests::T09_multiplicationOperator()
{
	//make a 3X3 matrix with those values
	Matrix a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	//make sure they are in the matrix
	assert(0.0 == a[0][0], "T09_multiplicationOperator");
	assert(1.0 == a[0][1], "T09_multiplicationOperator");
	assert(2.0 == a[0][2], "T09_multiplicationOperator");
	assert(3.0 == a[1][0], "T09_multiplicationOperator");
	assert(4.0 == a[1][1], "T09_multiplicationOperator");
	assert(5.0 == a[1][2], "T09_multiplicationOperator");
	assert(6.0 == a[2][0], "T09_multiplicationOperator");
	assert(7.0 == a[2][1], "T09_multiplicationOperator");
	assert(8.0 == a[2][2], "T09_multiplicationOperator");

	//multiply by 3
	Matrix b = a * 3;

	//make sure matrix a is the same
	assert(0.0 == a[0][0], "T09_multiplicationOperator");
	assert(1.0 == a[0][1], "T09_multiplicationOperator");
	assert(2.0 == a[0][2], "T09_multiplicationOperator");
	assert(3.0 == a[1][0], "T09_multiplicationOperator");
	assert(4.0 == a[1][1], "T09_multiplicationOperator");
	assert(5.0 == a[1][2], "T09_multiplicationOperator");
	assert(6.0 == a[2][0], "T09_multiplicationOperator");
	assert(7.0 == a[2][1], "T09_multiplicationOperator");
	assert(8.0 == a[2][2], "T09_multiplicationOperator");

	//make sure matrix b has the right values
	assert(0.0 == b[0][0],  "T09_multiplicationOperator");
	assert(3.0 == b[0][1],  "T09_multiplicationOperator");
	assert(6.0 == b[0][2],  "T09_multiplicationOperator");
	assert(9.0 == b[1][0],  "T09_multiplicationOperator");
	assert(12.0 == b[1][1], "T09_multiplicationOperator");
	assert(15.0 == b[1][2], "T09_multiplicationOperator");
	assert(18.0 == b[2][0], "T09_multiplicationOperator");
	assert(21.0 == b[2][1], "T09_multiplicationOperator");
	assert(24.0 == b[2][2], "T09_multiplicationOperator");

	//use shorthand
	a *= 3;

	//make sure a has right values now
	assert(0.0 == a[0][0],  "T09_multiplicationOperator");
	assert(3.0 == a[0][1],  "T09_multiplicationOperator");
	assert(6.0 == a[0][2],  "T09_multiplicationOperator");
	assert(9.0 == a[1][0],  "T09_multiplicationOperator");
	assert(12.0 == a[1][1], "T09_multiplicationOperator");
	assert(15.0 == a[1][2], "T09_multiplicationOperator");
	assert(18.0 == a[2][0], "T09_multiplicationOperator");
	assert(21.0 == a[2][1], "T09_multiplicationOperator");
	assert(24.0 == a[2][2], "T09_multiplicationOperator");

	//make a 2X3 matrix and a 3X2 matrix and a 2X2 to test multiplying two matrices
	//make a 2X3 matrix with those values
	Matrix x(2, 3);

	x[0][0] = 2;
	x[0][1] = 3;
	x[0][2] = 4;
	x[1][0] = 5;
	x[1][1] = 6;
	x[1][2] = 7;

	//make a 3X2 matrix with those values
	Matrix y(3, 2);

	y[0][0] = 10;
	y[0][1] = 20;
	y[1][0] = 30;
	y[1][1] = 40;
	y[2][0] = 50;
	y[2][1] = 60;

	//make a 2X2 matrix with those values
	Matrix z(2, 2);

	z[0][0] = 310;
	z[0][1] = 400;
	z[1][0] = 580;
	z[1][1] = 760;

	//check the operator=(Matrix other)
	assert(z == (x*y), "T09_multiplicationOperator");

	//check the operator*=(Matrix other)
	x *= y;

	assert(z == x, "T09_multiplicationOperator");
}

void MatricesTests::T10_additionOperator()
{
	//make a 3X3 matrix with those values
	Matrix a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	Matrix b(3, 3);

	b[0][0] = 0.0;
	b[0][1] = 1.0;
	b[0][2] = 2.0;
	b[1][0] = 3.0;
	b[1][1] = 4.0;
	b[1][2] = 5.0;
	b[2][0] = 6.0;
	b[2][1] = 7.0;
	b[2][2] = 8.0;

	Matrix aplusb(3, 3);

	aplusb[0][0] = 0.0;
	aplusb[0][1] = 2.0;
	aplusb[0][2] = 4.0;
	aplusb[1][0] = 6.0;
	aplusb[1][1] = 8.0;
	aplusb[1][2] = 10.0;
	aplusb[2][0] = 12.0;
	aplusb[2][1] = 14.0;
	aplusb[2][2] = 16.0;

	assert((a + b) == aplusb, "T10_additionOperator");

	b += a;

	assert(b == aplusb, "T10_additionOperator");

	//make a 2X2 matrix
	Matrix twobytwo(2, 2);

	twobytwo[0][0] = 0.0;
	twobytwo[0][1] = 1.0;
	twobytwo[1][0] = 2.0;
	twobytwo[1][1] = 3.0;

	//do an operation that should thow an exception
	try
	{
		//if it doesnt throw it should fail
		Matrix result = a + twobytwo;
		assert(false, "T10_additionOperator");
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true, "T10_additionOperator");
	}
}

void MatricesTests::T11_subtractionOperator()
{
	//make a 3X3 matrix with those values
	Matrix a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	Matrix b(3, 3);

	b[0][0] = 0.0;
	b[0][1] = 1.0;
	b[0][2] = 2.0;
	b[1][0] = 3.0;
	b[1][1] = 4.0;
	b[1][2] = 5.0;
	b[2][0] = 6.0;
	b[2][1] = 7.0;
	b[2][2] = 8.0;

	Matrix aminusb(3, 3);

	aminusb[0][0] = 0.0;
	aminusb[0][1] = 0.0;
	aminusb[0][2] = 0.0;
	aminusb[1][0] = 0.0;
	aminusb[1][1] = 0.0;
	aminusb[1][2] = 0.0;
	aminusb[2][0] = 0.0;
	aminusb[2][1] = 0.0;
	aminusb[2][2] = 0.0;

	assert((a - b) == aminusb, "T11_subtractionOperator");

	b -= a;

	assert(b == aminusb, "T11_subtractionOperator");

	//make a 2X2 matrix
	Matrix twobytwo(2, 2);

	twobytwo[0][0] = 0;
	twobytwo[0][1] = 1;
	twobytwo[1][0] = 2;
	twobytwo[1][1] = 3;

	//do an operation that should trhow an exception
	try
	{
		//if it doesn't throw it should fail
		Matrix result = a - twobytwo;
		assert(false, "T11_subtractionOperator");
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true, "T11_subtractionOperator");
	}
}

void MatricesTests::T12_equivalence()
{
	Matrix a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	Matrix b(a);

	Matrix c(3, 3);

	c[0][0] = 4.0;
	c[0][1] = 4.0;
	c[0][2] = 4.0;
	c[1][0] = 4.0;
	c[1][1] = 4.0;
	c[1][2] = 4.0;
	c[2][0] = 4.0;
	c[2][1] = 4.0;
	c[2][2] = 4.0;

	Matrix d(2, 3);

	d[0][0] = 4.0;
	d[0][1] = 4.0;
	d[0][2] = 4.0;
	d[1][0] = 4.0;
	d[1][1] = 4.0;
	d[1][2] = 4.0;

	//equal if same size and data
	assert(a == b, "T12_equivalence");

	//not equal if same size different data
	assert(a != c, "T12_equivalence");

	//not equal if different size similar data
	assert(d != c, "T12_equivalence");

}

void MatricesTests::T13_outputoperator()
{
	Matrix a(3,3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	std::stringstream out;

	out << a;

	std::string testText = "[\t0\t1\t2\t]\n[\t3\t4\t5\t]\n[\t6\t7\t8\t]\n";

	assert(testText == out.str(), "T13_outputoperator");
}

void MatricesTests::T15_cut()
{
	Matrix a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	Matrix b = a.getCut(1,1);

	Matrix c(2, 2);

	c[0][0] = 0;
	c[0][1] = 2;
	c[1][0] = 6;
	c[1][1] = 8;

	assert(b == c, "T15_cut");

	Matrix d(1, 1);

	//make sure you cant cut a 1 dimensional matrix
	try
	{
		Matrix cut = d.getCut(1,1);
		assert(false, "T15_cut");
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true, "T15_cut");
	}

	//make sure that it throws an exception for out of range tests
	try
	{
		Matrix cut = a.getCut(5,5);
		assert(false, "T15_cut");
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true, "T15_cut");
	}
}

void MatricesTests::T16_testDeterminant()
{
	Matrix a(1, 1);

	a[0][0] = 5.0;
	
	double adet = a.getDeterminant();

	assert(adet == 5, "T16_testDeterminant");

	Matrix b(3, 3);

	b[0][0] = 1.0;
	b[0][1] = 2.0;
	b[0][2] = 3.0;
	b[1][0] = 4.0;
	b[1][1] = 5.0;
	b[1][2] = 6.0;
	b[2][0] = 7.0;
	b[2][1] = 8.0;
	b[2][2] = 9.0;

	double bdet = b.getDeterminant();

	assert(bdet == 0, "T16_testDeterminant");
}

void MatricesTests::T17_testMinors()
{
	Matrix a(1, 1);

	a[0][0] = 5;

	try
	{
		Matrix smallMatrixMinors = a.getMinors();
		assert(false, "T17_testMinors");
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true, "T17_testMinors");
	}

	//make sure that it throws an exception for out of range tests
	try
	{
		a.getMinor(5,5);
		assert(false, "T17_testMinors");
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true, "T17_testMinors");
	}

	Matrix b(3, 3);

	b[0][0] = 1.0;
	b[0][1] = 2.0;
	b[0][2] = 3.0;
	b[1][0] = 4.0;
	b[1][1] = 5.0;
	b[1][2] = 6.0;
	b[2][0] = 7.0;
	b[2][1] = 8.0;
	b[2][2] = 9.0;

	Matrix bMinors = b.getMinors();

	Matrix bExpectedMinors(3, 3);

	bExpectedMinors[0][0] = -3;
	bExpectedMinors[0][1] = -6;
	bExpectedMinors[0][2] = -3;
	bExpectedMinors[1][0] = -6;
	bExpectedMinors[1][1] = -12;
	bExpectedMinors[1][2] = -6;
	bExpectedMinors[2][0] = -3;
	bExpectedMinors[2][1] = -6;
	bExpectedMinors[2][2] = -3;

	assert(bExpectedMinors == bMinors, "T17_testMinors");
}

void MatricesTests::T18_testCofactors()
{
	Matrix smallMatrix(1, 1);

	smallMatrix[0][0] = 5;

	try
	{
		Matrix smallMatrixCofactors =  smallMatrix.getCofactors();
		assert(false, "T18_testCofactors");
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true, "T18_testCofactors");
	}

	//make sure that it throws an exception for out of range tests
	try
	{
		smallMatrix.getCofactor(5,5);
		assert(false, "T18_testCofactors");
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true, "T18_testCofactors");
	}

	Matrix b(3, 3);

	b[0][0] = 1.0;
	b[0][1] = 2.0;
	b[0][2] = 3.0;
	b[1][0] = 4.0;
	b[1][1] = 5.0;
	b[1][2] = 6.0;
	b[2][0] = 7.0;
	b[2][1] = 8.0;
	b[2][2] = 9.0;

	Matrix bCofactors = b.getCofactors();

	Matrix bExpectedCofactors(3, 3);

	bExpectedCofactors[0][0] = -3;
	bExpectedCofactors[0][1] = 6;
	bExpectedCofactors[0][2] = -3;
	bExpectedCofactors[1][0] = 6;
	bExpectedCofactors[1][1] = -12;
	bExpectedCofactors[1][2] = 6;
	bExpectedCofactors[2][0] = -3;
	bExpectedCofactors[2][1] = 6;
	bExpectedCofactors[2][2] = -3;

	assert(bExpectedCofactors == bCofactors, "T18_testCofactors");
}

void MatricesTests::T19_testAdjugate()
{
	Matrix smallMatrix(1, 1);

	smallMatrix[0][0] = 5;

	try
	{
		Matrix smallMatrixAdjugates = smallMatrix.getAdjugate();
		assert(false, "T19_testAdjugate");
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true, "T19_testAdjugate");
	}

	Matrix b(3, 3);

	b[0][0] = 1.0;
	b[0][1] = 2.0;
	b[0][2] = 3.0;
	b[1][0] = 4.0;
	b[1][1] = 5.0;
	b[1][2] = 6.0;
	b[2][0] = 7.0;
	b[2][1] = 8.0;
	b[2][2] = 9.0;

	Matrix bAdjugate = b.getAdjugate();

	Matrix bExpectedAdjugates(3, 3);

	bExpectedAdjugates[0][0] = -3;
	bExpectedAdjugates[0][1] = 6;
	bExpectedAdjugates[0][2] = -3;
	bExpectedAdjugates[1][0] = 6;
	bExpectedAdjugates[1][1] = -12;
	bExpectedAdjugates[1][2] = 6;
	bExpectedAdjugates[2][0] = -3;
	bExpectedAdjugates[2][1] = 6;
	bExpectedAdjugates[2][2] = -3;

	assert(bExpectedAdjugates == bAdjugate, "T19_testAdjugate");
}

void MatricesTests::T20_testInverse()
{
	Matrix b(3, 3);

	b[0][0] = 1.0;
	b[0][1] = 2.0;
	b[0][2] = 3.0;
	b[1][0] = 4.0;
	b[1][1] = 5.0;
	b[1][2] = 6.0;
	b[2][0] = 7.0;
	b[2][1] = 8.0;
	b[2][2] = 9.0;

	Matrix bInverse = b.getInverse();

	Matrix bInverseExpected(3, 3);

	bInverseExpected[0][0] = 1.0;
	bInverseExpected[0][1] = 0.0;
	bInverseExpected[0][2] = 0.0;
	bInverseExpected[1][0] = 0.0;
	bInverseExpected[1][1] = 1.0;
	bInverseExpected[1][2] = 0.0;
	bInverseExpected[2][0] = 0.0;
	bInverseExpected[2][1] = 0.0;
	bInverseExpected[2][2] = 1.0;

	assert(bInverseExpected == bInverse, "T20_testInverse");

	Matrix c(3, 3);

	c[0][0] = 1.0;
	c[0][1] = 0.0;
	c[0][2] = -3.0;
	c[1][0] = 2.0;
	c[1][1] = -2.0;
	c[1][2] = 1.0;
	c[2][0] = 0.0;
	c[2][1] = -1.0;
	c[2][2] = 3.0;

	Matrix cInverse = c.getInverse();

	Matrix cInverseExpected(3, 3);

	cInverseExpected[0][0] = -5.0;
	cInverseExpected[0][1] = 3.0;
	cInverseExpected[0][2] = -6.0;
	cInverseExpected[1][0] = -6.0;
	cInverseExpected[1][1] = 3.0;
	cInverseExpected[1][2] = -7.0;
	cInverseExpected[2][0] = -2.0;
	cInverseExpected[2][1] = 1.0;
	cInverseExpected[2][2] = -2.0;

	assert(cInverseExpected == cInverse, "T20_testInverse");	
}
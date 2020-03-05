//Cody Ware
//5/30/19

#include "MatricesTests.h"

void MatricesTests::defaultConstructor()
{
	Matrix a(3, 3);

	assert(1.0 == a[0][0], "defaultConstructor");
	assert(0.0 == a[0][1], "defaultConstructor");
	assert(0.0 == a[0][2], "defaultConstructor");
	assert(0.0 == a[1][0], "defaultConstructor");
	assert(1.0 == a[1][1], "defaultConstructor");
	assert(0.0 == a[1][2], "defaultConstructor");
	assert(0.0 == a[2][0], "defaultConstructor");
	assert(0.0 == a[2][1], "defaultConstructor");
	assert(1.0 == a[2][2], "defaultConstructor");

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	assert(0.0 == a[0][0], "defaultConstructor");
	assert(1.0 == a[0][1], "defaultConstructor");
	assert(2.0 == a[0][2], "defaultConstructor");
	assert(3.0 == a[1][0], "defaultConstructor");
	assert(4.0 == a[1][1], "defaultConstructor");
	assert(5.0 == a[1][2], "defaultConstructor");
	assert(6.0 == a[2][0], "defaultConstructor");
	assert(7.0 == a[2][1], "defaultConstructor");
	assert(8.0 == a[2][2], "defaultConstructor");
}

void MatricesTests::copyConstructor()
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

	assert(0.0 == a[0][0], "copyConstructor");
	assert(1.0 == a[0][1], "copyConstructor");
	assert(2.0 == a[0][2], "copyConstructor");
	assert(3.0 == a[1][0], "copyConstructor");
	assert(4.0 == a[1][1], "copyConstructor");
	assert(5.0 == a[1][2], "copyConstructor");
	assert(6.0 == a[2][0], "copyConstructor");
	assert(7.0 == a[2][1], "copyConstructor");
	assert(8.0 == a[2][2], "copyConstructor");

	Matrix b(a);

	assert(0.0 == b[0][0], "copyConstructor");
	assert(1.0 == b[0][1], "copyConstructor");
	assert(2.0 == b[0][2], "copyConstructor");
	assert(3.0 == b[1][0], "copyConstructor");
	assert(4.0 == b[1][1], "copyConstructor");
	assert(5.0 == b[1][2], "copyConstructor");
	assert(6.0 == b[2][0], "copyConstructor");
	assert(7.0 == b[2][1], "copyConstructor");
	assert(8.0 == b[2][2], "copyConstructor");

	b[0][0] = 7;

	assert(7.0 == b[0][0], "copyConstructor");
	assert(0.0 == a[0][0], "copyConstructor");
}

void MatricesTests::moveConstructor()
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
	assert(0.0 == a[0][0], "moveConstructor");
	assert(1.0 == a[0][1], "moveConstructor");
	assert(2.0 == a[0][2], "moveConstructor");
	assert(3.0 == a[1][0], "moveConstructor");
	assert(4.0 == a[1][1], "moveConstructor");
	assert(5.0 == a[1][2], "moveConstructor");
	assert(6.0 == a[2][0], "moveConstructor");
	assert(7.0 == a[2][1], "moveConstructor");
	assert(8.0 == a[2][2], "moveConstructor");

	//make a matrix and move the memory of 'a' into this matrix
	Matrix moveHere(std::move(a));

	//make sure the rows and columns reflect the dimensions of a matrix with no data
	assert(0 == a.getRows(), "moveConstructor");
	assert(0 == a.getColumns(), "moveConstructor");

	//make sure that everything got moved
	assert(0.0 == moveHere[0][0], "moveConstructor");
	assert(1.0 == moveHere[0][1], "moveConstructor");
	assert(2.0 == moveHere[0][2], "moveConstructor");
	assert(3.0 == moveHere[1][0], "moveConstructor");
	assert(4.0 == moveHere[1][1], "moveConstructor");
	assert(5.0 == moveHere[1][2], "moveConstructor");
	assert(6.0 == moveHere[2][0], "moveConstructor");
	assert(7.0 == moveHere[2][1], "moveConstructor");
	assert(8.0 == moveHere[2][2], "moveConstructor");
}

void MatricesTests::assignmentOperator()
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
	assert(0.0 == a[0][0], "assignmentOperator");
	assert(1.0 == a[0][1], "assignmentOperator");
	assert(2.0 == a[0][2], "assignmentOperator");
	assert(3.0 == a[1][0], "assignmentOperator");
	assert(4.0 == a[1][1], "assignmentOperator");
	assert(5.0 == a[1][2], "assignmentOperator");
	assert(6.0 == a[2][0], "assignmentOperator");
	assert(7.0 == a[2][1], "assignmentOperator");
	assert(8.0 == a[2][2], "assignmentOperator");

	//make a matrix and move the memory of 'a' into this matrix
	Matrix assignment(3, 3);

	assignment = a;

	//check that 'a' still has its original values
	assert(0.0 == a[0][0], "assignmentOperator");
	assert(1.0 == a[0][1], "assignmentOperator");
	assert(2.0 == a[0][2], "assignmentOperator");
	assert(3.0 == a[1][0], "assignmentOperator");
	assert(4.0 == a[1][1], "assignmentOperator");
	assert(5.0 == a[1][2], "assignmentOperator");
	assert(6.0 == a[2][0], "assignmentOperator");
	assert(7.0 == a[2][1], "assignmentOperator");
	assert(8.0 == a[2][2], "assignmentOperator");

	//make sure that everything got moved
	assert(0.0 == assignment[0][0], "assignmentOperator");
	assert(1.0 == assignment[0][1], "assignmentOperator");
	assert(2.0 == assignment[0][2], "assignmentOperator");
	assert(3.0 == assignment[1][0], "assignmentOperator");
	assert(4.0 == assignment[1][1], "assignmentOperator");
	assert(5.0 == assignment[1][2], "assignmentOperator");
	assert(6.0 == assignment[2][0], "assignmentOperator");
	assert(7.0 == assignment[2][1], "assignmentOperator");
	assert(8.0 == assignment[2][2], "assignmentOperator");
}

void MatricesTests::moveAssignmentOperator()
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
	assert(0.0 == a[0][0], "moveAssignmentOperator");
	assert(1.0 == a[0][1], "moveAssignmentOperator");
	assert(2.0 == a[0][2], "moveAssignmentOperator");
	assert(3.0 == a[1][0], "moveAssignmentOperator");
	assert(4.0 == a[1][1], "moveAssignmentOperator");
	assert(5.0 == a[1][2], "moveAssignmentOperator");
	assert(6.0 == a[2][0], "moveAssignmentOperator");
	assert(7.0 == a[2][1], "moveAssignmentOperator");
	assert(8.0 == a[2][2], "moveAssignmentOperator");

	//make a matrix and move the memory of 'a' into this matrix
	Matrix moveHere = std::move(a);

	//make sure the rows and columns reflect the dimensions of a matrix with no data
	assert(0 == a.getRows(), "moveAssignmentOperator");
	assert(0 == a.getColumns(), "moveAssignmentOperator");

	//make sure that everything got moved
	assert(0.0 == moveHere[0][0], "moveAssignmentOperator");
	assert(1.0 == moveHere[0][1], "moveAssignmentOperator");
	assert(2.0 == moveHere[0][2], "moveAssignmentOperator");
	assert(3.0 == moveHere[1][0], "moveAssignmentOperator");
	assert(4.0 == moveHere[1][1], "moveAssignmentOperator");
	assert(5.0 == moveHere[1][2], "moveAssignmentOperator");
	assert(6.0 == moveHere[2][0], "moveAssignmentOperator");
	assert(7.0 == moveHere[2][1], "moveAssignmentOperator");
	assert(8.0 == moveHere[2][2], "moveAssignmentOperator");
}

void MatricesTests::accessOperator()
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
	assert(0.0 == a[0][0], "accessOperator");
	assert(1.0 == a[0][1], "accessOperator");
	assert(2.0 == a[0][2], "accessOperator");
	assert(3.0 == a[1][0], "accessOperator");
	assert(4.0 == a[1][1], "accessOperator");
	assert(5.0 == a[1][2], "accessOperator");
	assert(6.0 == a[2][0], "accessOperator");
	assert(7.0 == a[2][1], "accessOperator");
	assert(8.0 == a[2][2], "accessOperator");

	const int X = 0;
	assert(0.0 == a[X][X], "accessOperator");
}

void MatricesTests::transpose()
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
	assert(0.0 == a[0][0], "transpose"); assert(1.0 == a[0][1], "transpose"); assert(2.0 == a[0][2], "transpose");
	assert(3.0 == a[1][0], "transpose"); assert(4.0 == a[1][1], "transpose"); assert(5.0 == a[1][2], "transpose");
	assert(6.0 == a[2][0], "transpose"); assert(7.0 == a[2][1], "transpose"); assert(8.0 == a[2][2], "transpose");

	//transpose it
	a.transpose();

	//make sure they are transposed
	assert(0.0 == a[0][0], "transpose"); assert(3.0 == a[0][1], "transpose"); assert(6.0 == a[0][2], "transpose");
	assert(1.0 == a[1][0], "transpose"); assert(4.0 == a[1][1], "transpose"); assert(7.0 == a[1][2], "transpose");
	assert(2.0 == a[2][0], "transpose"); assert(5.0 == a[2][1], "transpose"); assert(8.0 == a[2][2], "transpose");
}

void MatricesTests::transposed()
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
	assert(0.0 == a[0][0], "transposed");
	assert(1.0 == a[0][1], "transposed");
	assert(2.0 == a[0][2], "transposed");
	assert(3.0 == a[1][0], "transposed");
	assert(4.0 == a[1][1], "transposed");
	assert(5.0 == a[1][2], "transposed");
	assert(6.0 == a[2][0], "transposed");
	assert(7.0 == a[2][1], "transposed");
	assert(8.0 == a[2][2], "transposed");

	//transpose it
	Matrix transposed = a.transposed();

	//make sure they are transposed
	assert(0.0 == transposed[0][0], "transposed");
	assert(3.0 == transposed[0][1], "transposed");
	assert(6.0 == transposed[0][2], "transposed");
	assert(1.0 == transposed[1][0], "transposed");
	assert(4.0 == transposed[1][1], "transposed");
	assert(7.0 == transposed[1][2], "transposed");
	assert(2.0 == transposed[2][0], "transposed");
	assert(5.0 == transposed[2][1], "transposed");
	assert(8.0 == transposed[2][2], "transposed");
}

void MatricesTests::multiplicationOperator()
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
	assert(0.0 == a[0][0], "multiplicationOperator");
	assert(1.0 == a[0][1], "multiplicationOperator");
	assert(2.0 == a[0][2], "multiplicationOperator");
	assert(3.0 == a[1][0], "multiplicationOperator");
	assert(4.0 == a[1][1], "multiplicationOperator");
	assert(5.0 == a[1][2], "multiplicationOperator");
	assert(6.0 == a[2][0], "multiplicationOperator");
	assert(7.0 == a[2][1], "multiplicationOperator");
	assert(8.0 == a[2][2], "multiplicationOperator");

	//multiply by 3
	Matrix b = a * 3;

	//make sure matrix a is the same
	assert(0.0 == a[0][0], "multiplicationOperator");
	assert(1.0 == a[0][1], "multiplicationOperator");
	assert(2.0 == a[0][2], "multiplicationOperator");
	assert(3.0 == a[1][0], "multiplicationOperator");
	assert(4.0 == a[1][1], "multiplicationOperator");
	assert(5.0 == a[1][2], "multiplicationOperator");
	assert(6.0 == a[2][0], "multiplicationOperator");
	assert(7.0 == a[2][1], "multiplicationOperator");
	assert(8.0 == a[2][2], "multiplicationOperator");

	//make sure matrix b has the right values
	assert(0.0 == b[0][0], "multiplicationOperator");
	assert(3.0 == b[0][1], "multiplicationOperator");
	assert(6.0 == b[0][2], "multiplicationOperator");
	assert(9.0 == b[1][0], "multiplicationOperator");
	assert(12.0 == b[1][1], "multiplicationOperator");
	assert(15.0 == b[1][2], "multiplicationOperator");
	assert(18.0 == b[2][0], "multiplicationOperator");
	assert(21.0 == b[2][1], "multiplicationOperator");
	assert(24.0 == b[2][2], "multiplicationOperator");

	//use shorthand
	a *= 3;

	//make sure a has right values now
	assert(0.0 == a[0][0], "multiplicationOperator");
	assert(3.0 == a[0][1], "multiplicationOperator");
	assert(6.0 == a[0][2], "multiplicationOperator");
	assert(9.0 == a[1][0], "multiplicationOperator");
	assert(12.0 == a[1][1], "multiplicationOperator");
	assert(15.0 == a[1][2], "multiplicationOperator");
	assert(18.0 == a[2][0], "multiplicationOperator");
	assert(21.0 == a[2][1], "multiplicationOperator");
	assert(24.0 == a[2][2], "multiplicationOperator");

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
	assert(z == (x * y), "multiplicationOperator");

	//check the operator*=(Matrix other)
	x *= y;

	assert(z == x, "multiplicationOperator");
}

void MatricesTests::additionOperator()
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

	assert((a + b) == aplusb, "additionOperator");

	b += a;

	assert(b == aplusb, "additionOperator");

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
		assert(false, "additionOperator");
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true, "additionOperator");
	}
}

void MatricesTests::subtractionOperator()
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

	assert((a - b) == aminusb, "subtractionOperator");

	b -= a;

	assert(b == aminusb, "subtractionOperator");

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
		assert(false, "subtractionOperator");
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true, "subtractionOperator");
	}
}

void MatricesTests::equivalence()
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
	assert(a == b, "equivalence");

	//not equal if same size different data
	assert(a != c, "equivalence");

	//not equal if different size similar data
	assert(d != c, "equivalence");

}

void MatricesTests::outputoperator()
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

	std::stringstream out;

	out << a;

	std::string testText = "[\t0\t1\t2\t]\n[\t3\t4\t5\t]\n[\t6\t7\t8\t]\n";

	assert(testText == out.str(), "outputoperator");
}

void MatricesTests::cut()
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

	Matrix b = a.getCut(1, 1);

	Matrix c(2, 2);

	c[0][0] = 0;
	c[0][1] = 2;
	c[1][0] = 6;
	c[1][1] = 8;

	assert(b == c, "cut");

	Matrix d(1, 1);

	//make sure you cant cut a 1 dimensional matrix
	try
	{
		Matrix cut = d.getCut(1, 1);
		assert(false, "cut");
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true, "cut");
	}

	//make sure that it throws an exception for out of range tests
	try
	{
		Matrix cut = a.getCut(5, 5);
		assert(false, "cut");
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true, "cut");
	}
}

void MatricesTests::testDeterminant()
{
	Matrix a(1, 1);

	a[0][0] = 5.0;

	double adet = a.getDeterminant();

	assert(adet == 5, "testDeterminant");

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

	assert(bdet == 0, "testDeterminant");
}

void MatricesTests::testMinors()
{
	Matrix a(1, 1);

	a[0][0] = 5;

	try
	{
		Matrix smallMatrixMinors = a.getMinors();
		assert(false, "testMinors");
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true, "testMinors");
	}

	//make sure that it throws an exception for out of range tests
	try
	{
		a.getMinor(5, 5);
		assert(false, "testMinors");
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true, "testMinors");
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

	assert(bExpectedMinors == bMinors, "testMinors");
}

void MatricesTests::testCofactors()
{
	Matrix smallMatrix(1, 1);

	smallMatrix[0][0] = 5;

	try
	{
		Matrix smallMatrixCofactors = smallMatrix.getCofactors();
		assert(false, "testCofactors");
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true, "testCofactors");
	}

	//make sure that it throws an exception for out of range tests
	try
	{
		smallMatrix.getCofactor(5, 5);
		assert(false, "testCofactors");
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true, "testCofactors");
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

	assert(bExpectedCofactors == bCofactors, "testCofactors");
}

void MatricesTests::testAdjugate()
{
	Matrix smallMatrix(1, 1);

	smallMatrix[0][0] = 5;

	try
	{
		Matrix smallMatrixAdjugates = smallMatrix.getAdjugate();
		assert(false, "testAdjugate");
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true, "testAdjugate");
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

	assert(bExpectedAdjugates == bAdjugate, "testAdjugate");
}

void MatricesTests::testInverse()
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

	assert(bInverseExpected == bInverse, "testInverse");

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

	assert(cInverseExpected == cInverse, "testInverse");
}
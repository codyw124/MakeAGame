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

	cout<< "All Matrices Tests Passed" << endl;
}

void MatricesTests::T01_defaultConstructor()
{
	Matrix<int> a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);
}

void MatricesTests::T02_copyConstructor()
{
	Matrix<int> a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);

	Matrix<int> b(a);

	assert(0.0 == b[0][0]);
	assert(1.0 == b[0][1]);
	assert(2.0 == b[0][2]);
	assert(3.0 == b[1][0]);
	assert(4.0 == b[1][1]);
	assert(5.0 == b[1][2]);
	assert(6.0 == b[2][0]);
	assert(7.0 == b[2][1]);
	assert(8.0 == b[2][2]);

	b[0][0] = 7;

	assert(7.0 == b[0][0]);
	assert(0.0 == a[0][0]);
}

void MatricesTests::T03_moveConstructor()
{
	//make a 3X3 matrix with those values
	Matrix<int> a(3, 3);

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
	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);

	//make a matrix and move the memory of 'a' into this matrix
	Matrix<int> moveHere(std::move(a));

	//make sure the rows and columns reflect the dimensions of a matrix with no data
	assert(0 == a.getRows());
	assert(0 == a.getColumns());

	//make sure that everything got moved
	assert(0.0 == moveHere[0][0]);
	assert(1.0 == moveHere[0][1]);
	assert(2.0 == moveHere[0][2]);
	assert(3.0 == moveHere[1][0]);
	assert(4.0 == moveHere[1][1]);
	assert(5.0 == moveHere[1][2]);
	assert(6.0 == moveHere[2][0]);
	assert(7.0 == moveHere[2][1]);
	assert(8.0 == moveHere[2][2]);
}

void MatricesTests::T04_assignmentOperator()
{
	//make a 3X3 matrix with those values
	Matrix<int> a(3, 3);

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
	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);

	//make a matrix and move the memory of 'a' into this matrix
	Matrix<int> assignment(3, 3);

	assignment = a;

	//check that 'a' still has its original values
	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);

	//make sure that everything got moved
	assert(0.0 == assignment[0][0]);
	assert(1.0 == assignment[0][1]);
	assert(2.0 == assignment[0][2]);
	assert(3.0 == assignment[1][0]);
	assert(4.0 == assignment[1][1]);
	assert(5.0 == assignment[1][2]);
	assert(6.0 == assignment[2][0]);
	assert(7.0 == assignment[2][1]);
	assert(8.0 == assignment[2][2]);
}

void MatricesTests::T05_moveAssignmentOperator()
{
	//make a 3X3 matrix with those values
	Matrix<int> a(3, 3);

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
	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);

	//make a matrix and move the memory of 'a' into this matrix
	Matrix<int> moveHere = std::move(a);

	//make sure the rows and columns reflect the dimensions of a matrix with no data
	assert(0 == a.getRows());
	assert(0 == a.getColumns());

	//make sure that everything got moved
	assert(0.0 == moveHere[0][0]);
	assert(1.0 == moveHere[0][1]);
	assert(2.0 == moveHere[0][2]);
	assert(3.0 == moveHere[1][0]);
	assert(4.0 == moveHere[1][1]);
	assert(5.0 == moveHere[1][2]);
	assert(6.0 == moveHere[2][0]);
	assert(7.0 == moveHere[2][1]);
	assert(8.0 == moveHere[2][2]);
}

void MatricesTests::T06_accessOperator()
{
	//make a 3X3 matrix with those values
	Matrix<int> a(3, 3);

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
	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);

	const int X = 0;
	assert(0.0 == a[X][X]);
}

void MatricesTests::T07_transpose()
{
	//make a 3X3 matrix with those values
	Matrix<int> a(3, 3);

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
	assert(0.0 == a[0][0]);assert(1.0 == a[0][1]);assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);assert(4.0 == a[1][1]);assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);assert(7.0 == a[2][1]);assert(8.0 == a[2][2]);

	//transpose it
	a.transpose();

	//make sure they are transposed
	assert(0.0 == a[0][0]);assert(3.0 == a[0][1]);assert(6.0 == a[0][2]);
	assert(1.0 == a[1][0]);assert(4.0 == a[1][1]);assert(7.0 == a[1][2]);
	assert(2.0 == a[2][0]);assert(5.0 == a[2][1]);assert(8.0 == a[2][2]);
}

void MatricesTests::T08_transposed()
{

	//make a 3X3 matrix with those values
	Matrix<int> a(3, 3);

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
	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);

	//transpose it
	Matrix<int> transposed = a.transposed();

	//make sure they are transposed
	assert(0.0 == transposed[0][0]);
	assert(3.0 == transposed[0][1]);
	assert(6.0 == transposed[0][2]);
	assert(1.0 == transposed[1][0]);
	assert(4.0 == transposed[1][1]);
	assert(7.0 == transposed[1][2]);
	assert(2.0 == transposed[2][0]);
	assert(5.0 == transposed[2][1]);
	assert(8.0 == transposed[2][2]);
}

void MatricesTests::T09_multiplicationOperator()
{
	//make a 3X3 matrix with those values
	Matrix<int> a(3, 3);

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
	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);

	//multiply by 3
	Matrix<int> b = a * 3;

	//make sure matrix a is the same
	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);

	//make sure matrix b has the right values
	assert(0.0 == b[0][0]);
	assert(3.0 == b[0][1]);
	assert(6.0 == b[0][2]);
	assert(9.0 == b[1][0]);
	assert(12.0 == b[1][1]);
	assert(15.0 == b[1][2]);
	assert(18.0 == b[2][0]);
	assert(21.0 == b[2][1]);
	assert(24.0 == b[2][2]);

	//use shorthand
	a *= 3;

	//make sure a has right values now
	assert(0.0 == a[0][0]);
	assert(3.0 == a[0][1]);
	assert(6.0 == a[0][2]);
	assert(9.0 == a[1][0]);
	assert(12.0 == a[1][1]);
	assert(15.0 == a[1][2]);
	assert(18.0 == a[2][0]);
	assert(21.0 == a[2][1]);
	assert(24.0 == a[2][2]);

	//make a 2X3 matrix and a 3X2 matrix and a 2X2 to test multiplying two matrices
	//make a 2X3 matrix with those values
	Matrix<int> x(2, 3);

	x[0][0] = 2;
	x[0][1] = 3;
	x[0][2] = 4;
	x[1][0] = 5;
	x[1][1] = 6;
	x[1][2] = 7;

	//make a 3X2 matrix with those values
	Matrix<int> y(3, 2);

	y[0][0] = 10;
	y[0][1] = 20;
	y[1][0] = 30;
	y[1][1] = 40;
	y[2][0] = 50;
	y[2][1] = 60;

	//make a 2X2 matrix with those values
	Matrix<int> z(2, 2);

	z[0][0] = 310;
	z[0][1] = 400;
	z[1][0] = 580;
	z[1][1] = 760;

	//check the operator=(Matrix other)
	assert(z == (x*y));

	//check the operator*=(Matrix other)
	x *= y;

	assert(z == x);
}

void MatricesTests::T10_additionOperator()
{
	//make a 3X3 matrix with those values
	Matrix<int> a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	Matrix<int> b(3, 3);

	b[0][0] = 0.0;
	b[0][1] = 1.0;
	b[0][2] = 2.0;
	b[1][0] = 3.0;
	b[1][1] = 4.0;
	b[1][2] = 5.0;
	b[2][0] = 6.0;
	b[2][1] = 7.0;
	b[2][2] = 8.0;

	Matrix<int> aplusb(3, 3);

	aplusb[0][0] = 0.0;
	aplusb[0][1] = 2.0;
	aplusb[0][2] = 4.0;
	aplusb[1][0] = 6.0;
	aplusb[1][1] = 8.0;
	aplusb[1][2] = 10.0;
	aplusb[2][0] = 12.0;
	aplusb[2][1] = 14.0;
	aplusb[2][2] = 16.0;

	assert((a + b) == aplusb);

	b += a;

	assert(b == aplusb);

	//make a 2X2 matrix
	Matrix<int> twobytwo(2, 2);

	twobytwo[0][0] = 0.0;
	twobytwo[0][1] = 1.0;
	twobytwo[1][0] = 2.0;
	twobytwo[1][1] = 3.0;

	//do an operation that should thow an exception
	try
	{
		//if it doesnt throw it should fail
		a + twobytwo;
		assert(false);
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true);
	}
}

void MatricesTests::T11_subtractionOperator()
{
	//make a 3X3 matrix with those values
	Matrix<int> a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	Matrix<int> b(3, 3);

	b[0][0] = 0.0;
	b[0][1] = 1.0;
	b[0][2] = 2.0;
	b[1][0] = 3.0;
	b[1][1] = 4.0;
	b[1][2] = 5.0;
	b[2][0] = 6.0;
	b[2][1] = 7.0;
	b[2][2] = 8.0;

	Matrix<int> aminusb(3, 3);

	aminusb[0][0] = 0.0;
	aminusb[0][1] = 0.0;
	aminusb[0][2] = 0.0;
	aminusb[1][0] = 0.0;
	aminusb[1][1] = 0.0;
	aminusb[1][2] = 0.0;
	aminusb[2][0] = 0.0;
	aminusb[2][1] = 0.0;
	aminusb[2][2] = 0.0;

	assert((a - b) == aminusb);

	b -= a;

	assert(b == aminusb);

	//make a 2X2 matrix
	Matrix<int> twobytwo(2, 2);

	twobytwo[0][0] = 0;
	twobytwo[0][1] = 1;
	twobytwo[1][0] = 2;
	twobytwo[1][1] = 3;

	//do an operation that should trhow an exception
	try
	{
		//if it doesn't throw it should fail
		a - twobytwo;
		assert(false);
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true);
	}
}

void MatricesTests::T12_equivalence()
{
	Matrix<int> a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	Matrix<int> b(a);

	Matrix<int> c(3, 3);

	c[0][0] = 4.0;
	c[0][1] = 4.0;
	c[0][2] = 4.0;
	c[1][0] = 4.0;
	c[1][1] = 4.0;
	c[1][2] = 4.0;
	c[2][0] = 4.0;
	c[2][1] = 4.0;
	c[2][2] = 4.0;

	Matrix<int> d(2, 3);

	d[0][0] = 4.0;
	d[0][1] = 4.0;
	d[0][2] = 4.0;
	d[1][0] = 4.0;
	d[1][1] = 4.0;
	d[1][2] = 4.0;

	//equal if same size and data
	assert(a == b);

	//not equal if same size different data
	assert(a != c);

	//not equal if different size similar data
	assert(d != c);

}

void MatricesTests::T13_outputoperator()
{
	Matrix<int> a(3,3);

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

	assert(testText == out.str());
}

void MatricesTests::T15_cut()
{
	Matrix<int> a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	Matrix<int> b = a.getCut(1,1);

	Matrix<int> c(2, 2);

	c[0][0] = 0;
	c[0][1] = 2;
	c[1][0] = 6;
	c[1][1] = 8;

	assert(b == c);

	Matrix<int> d(1, 1);

	//make sure you cant cut a 1 dimensional matrix
	try
	{
		d.getCut(1,1);
		assert(false);
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true);
	}

	//make sure that it throws an exception for out of range tests
	try
	{
		a.getCut(5,5);
		assert(false);
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true);
	}
}

void MatricesTests::T16_testDeterminant()
{
	Matrix<int> a(1, 1);

	a[0][0] = 5.0;
	
	int adet = a.getDeterminant();

	assert(adet == 5);

	Matrix<int> b(3, 3);

	b[0][0] = 1.0;
	b[0][1] = 2.0;
	b[0][2] = 3.0;
	b[1][0] = 4.0;
	b[1][1] = 5.0;
	b[1][2] = 6.0;
	b[2][0] = 7.0;
	b[2][1] = 8.0;
	b[2][2] = 9.0;

	int bdet = b.getDeterminant();

	assert(bdet == 0);
}

void MatricesTests::T17_testMinors()
{
	Matrix<int> a(1, 1);

	a[0][0] = 5;

	try
	{
		a.getMinors();
		assert(false);
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true);
	}

	//make sure that it throws an exception for out of range tests
	try
	{
		a.getMinor(5,5);
		assert(false);
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true);
	}

	Matrix<int> b(3, 3);

	b[0][0] = 1.0;
	b[0][1] = 2.0;
	b[0][2] = 3.0;
	b[1][0] = 4.0;
	b[1][1] = 5.0;
	b[1][2] = 6.0;
	b[2][0] = 7.0;
	b[2][1] = 8.0;
	b[2][2] = 9.0;

	Matrix<int> bMinors = b.getMinors();

	Matrix<int> bExpectedMinors(3, 3);

	bExpectedMinors[0][0] = -3;
	bExpectedMinors[0][1] = -6;
	bExpectedMinors[0][2] = -3;
	bExpectedMinors[1][0] = -6;
	bExpectedMinors[1][1] = -12;
	bExpectedMinors[1][2] = -6;
	bExpectedMinors[2][0] = -3;
	bExpectedMinors[2][1] = -6;
	bExpectedMinors[2][2] = -3;

	assert(bExpectedMinors == bMinors);
}

void MatricesTests::T18_testCofactors()
{
	Matrix<int> a(1, 1);

	a[0][0] = 5;

	try
	{
		a.getCofactors();
		assert(false);
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true);
	}

	//make sure that it throws an exception for out of range tests
	try
	{
		a.getCofactor(5,5);
		assert(false);
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true);
	}

	Matrix<int> b(3, 3);

	b[0][0] = 1.0;
	b[0][1] = 2.0;
	b[0][2] = 3.0;
	b[1][0] = 4.0;
	b[1][1] = 5.0;
	b[1][2] = 6.0;
	b[2][0] = 7.0;
	b[2][1] = 8.0;
	b[2][2] = 9.0;

	Matrix<int> bCofactors = b.getCofactors();

	Matrix<int> bExpectedCofactors(3, 3);

	bExpectedCofactors[0][0] = -3;
	bExpectedCofactors[0][1] = 6;
	bExpectedCofactors[0][2] = -3;
	bExpectedCofactors[1][0] = 6;
	bExpectedCofactors[1][1] = -12;
	bExpectedCofactors[1][2] = 6;
	bExpectedCofactors[2][0] = -3;
	bExpectedCofactors[2][1] = 6;
	bExpectedCofactors[2][2] = -3;

	assert(bExpectedCofactors == bCofactors);
}

void MatricesTests::T19_testAdjugate()
{
	Matrix<int> a(1, 1);

	a[0][0] = 5;

	try
	{
		a.getAdjugate();
		assert(false);
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true);
	}

	Matrix<int> b(3, 3);

	b[0][0] = 1.0;
	b[0][1] = 2.0;
	b[0][2] = 3.0;
	b[1][0] = 4.0;
	b[1][1] = 5.0;
	b[1][2] = 6.0;
	b[2][0] = 7.0;
	b[2][1] = 8.0;
	b[2][2] = 9.0;

	Matrix<int> bAdjugate = b.getAdjugate();

	Matrix<int> bExpectedAdjugates(3, 3);

	bExpectedAdjugates[0][0] = -3;
	bExpectedAdjugates[0][1] = 6;
	bExpectedAdjugates[0][2] = -3;
	bExpectedAdjugates[1][0] = 6;
	bExpectedAdjugates[1][1] = -12;
	bExpectedAdjugates[1][2] = 6;
	bExpectedAdjugates[2][0] = -3;
	bExpectedAdjugates[2][1] = 6;
	bExpectedAdjugates[2][2] = -3;

	assert(bExpectedAdjugates == bAdjugate);
}

void MatricesTests::T20_testInverse()
{
	Matrix<int> b(3, 3);

	b[0][0] = 1.0;
	b[0][1] = 2.0;
	b[0][2] = 3.0;
	b[1][0] = 4.0;
	b[1][1] = 5.0;
	b[1][2] = 6.0;
	b[2][0] = 7.0;
	b[2][1] = 8.0;
	b[2][2] = 9.0;

	Matrix<int> bInverse = b.getInverse();

	Matrix<int> bInverseExpected(3, 3);

	bInverseExpected[0][0] = 1.0;
	bInverseExpected[0][1] = 0.0;
	bInverseExpected[0][2] = 0.0;
	bInverseExpected[1][0] = 0.0;
	bInverseExpected[1][1] = 1.0;
	bInverseExpected[1][2] = 0.0;
	bInverseExpected[2][0] = 0.0;
	bInverseExpected[2][1] = 0.0;
	bInverseExpected[2][2] = 1.0;

	assert(bInverseExpected == bInverse);

	Matrix<int> c(3, 3);

	c[0][0] = 1.0;
	c[0][1] = 0.0;
	c[0][2] = -3.0;
	c[1][0] = 2.0;
	c[1][1] = -2.0;
	c[1][2] = 1.0;
	c[2][0] = 0.0;
	c[2][1] = -1.0;
	c[2][2] = 3.0;

	Matrix<int> cInverse = c.getInverse();

	Matrix<int> cInverseExpected(3, 3);

	cInverseExpected[0][0] = -5.0;
	cInverseExpected[0][1] = 3.0;
	cInverseExpected[0][2] = -6.0;
	cInverseExpected[1][0] = -6.0;
	cInverseExpected[1][1] = 3.0;
	cInverseExpected[1][2] = -7.0;
	cInverseExpected[2][0] = -2.0;
	cInverseExpected[2][1] = 1.0;
	cInverseExpected[2][2] = -2.0;

	assert(cInverseExpected == cInverse);	
}
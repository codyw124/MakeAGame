//Cody Ware
//1/1/19

#include <cassert>
#include "../headers/Matrix.h"







void T10_additionOperator)
{
	//make 9 values
	int x[9] = { 0,1,2,3,4,5,6,7,8 };

	int result[9] = { 0,2,4,6,8,10,12,14,16 };

	//make a 3X3 matrix with those values
	Matrix a = Matrix(3, 3, x);

	Matrix b = Matrix(3, 3, x);

	Matrix aplusb = Matrix(3, 3, result);

	Assert::IsTrue(a + b == aplusb);

	b += a;

	Assert::IsTrue(b == aplusb);

	//make a 2x2 data
	int smallData[4] = { 0,1,2,3 };

	//make a 2X2 matrix
	Matrix twobytwo = Matrix(2, 2, smallData);

	//do an operation that should thow an exception
	try
	{
		//if it doesnt throw it should fail
		a + twobytwo;
		Assert::Fail();
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		Assert::IsTrue(true);
	}
}

void T11_subtractionOperator)
{
	//make 9 values
	int x[9] = { 0,1,2,3,4,5,6,7,8 };

	int result[9] = { 0,0,0,0,0,0,0,0,0 };

	//make a 3X3 matrix with those values
	Matrix a = Matrix(3, 3, x);

	Matrix b = Matrix(3, 3, x);

	Matrix aminusb = Matrix(3, 3, result);

	Assert::IsTrue(a - b == aminusb);

	b -= a;

	Assert::IsTrue(b == aminusb);

		//make a 2x2 data
		int smallData[4] = { 0,1,2,3 };

	//make a 2X2 matrix
	Matrix twobytwo = Matrix(2, 2, smallData);

	//do an operation that should trhow an exception
	try
	{
		//if it doesn't throw it should fail
		a - twobytwo;
		Assert::Fail();
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		Assert::IsTrue(true);
	}
}

void T12_equivalence)
{
	int x[9] = { 0,1,2,3,4,5,6,7,8 };
	int y[9] = { 4,4,4,4,4,4,4,4,4 };
	int z[6] = { 4,4,4,4,4,4 };

	Matrix a = Matrix(3, 3, x);

	Matrix b = Matrix(3, 3, x);

	Matrix c = Matrix(3, 3, y);

	Matrix d = Matrix(2, 3, z);

	//equal if same size and data
	Assert::IsTrue(a == b);

	//not equal if same size different data
	Assert::IsTrue(a != c);

	//not equal if different size similar data
	Assert::IsTrue(d != c);

}

void T13_outputoperator)
{
	int x[9] = { 0,1,2,3,4,5,6,7,8 };

	Matrix test = Matrix(3,3,x);

	std::stringstream out;

	out << test;

	std::string testText = "[\t0\t1\t2\t]\n[\t3\t4\t5\t]\n[\t6\t7\t8\t]\n";

	Assert::AreEqual(testText, out.str());
}
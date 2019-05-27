//Cody Ware
//1/1/19

#include "stdafx.h"
#include "CppUnitTest.h"
#include <cassert>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../GamePhysics/Matrix.h"

using namespace GamePhysics;

namespace GamePhysicsTest
{
	TEST_CLASS(MatrixTests)
	{
	public:


		TEST_METHOD(T01_defaultConstructorWithValues)
		{
			int x[9] = { 0,1,2,3,4,5,6,7,8 };
			
			Matrix a = Matrix(3, 3, x);

			Assert::AreEqual(0.0, a[0][0]);
			Assert::AreEqual(1.0, a[0][1]);
			Assert::AreEqual(2.0, a[0][2]);
			Assert::AreEqual(3.0, a[1][0]);
			Assert::AreEqual(4.0, a[1][1]);
			Assert::AreEqual(5.0, a[1][2]);
			Assert::AreEqual(6.0, a[2][0]);
			Assert::AreEqual(7.0, a[2][1]);
			Assert::AreEqual(8.0, a[2][2]);
		}

		TEST_METHOD(T02_copyConstructor)
		{
			int x[9] = { 0,1,2,3,4,5,6,7,8 };

			Matrix a = Matrix(3, 3, x);

			Assert::AreEqual(0.0, a[0][0]);
			Assert::AreEqual(1.0, a[0][1]);
			Assert::AreEqual(2.0, a[0][2]);
			Assert::AreEqual(3.0, a[1][0]);
			Assert::AreEqual(4.0, a[1][1]);
			Assert::AreEqual(5.0, a[1][2]);
			Assert::AreEqual(6.0, a[2][0]);
			Assert::AreEqual(7.0, a[2][1]);
			Assert::AreEqual(8.0, a[2][2]);

			Matrix b = Matrix(a);

			Assert::AreEqual(0.0, b[0][0]);
			Assert::AreEqual(1.0, b[0][1]);
			Assert::AreEqual(2.0, b[0][2]);
			Assert::AreEqual(3.0, b[1][0]);
			Assert::AreEqual(4.0, b[1][1]);
			Assert::AreEqual(5.0, b[1][2]);
			Assert::AreEqual(6.0, b[2][0]);
			Assert::AreEqual(7.0, b[2][1]);
			Assert::AreEqual(8.0, b[2][2]);

			b[0][0] = 77;

			Assert::AreEqual(77.0, b[0][0]);

			Assert::AreEqual(0.0, a[0][0]);
		}

		TEST_METHOD(T03_moveConstructor)
		{
			//make 9 values
			int x[9] = { 0,1,2,3,4,5,6,7,8 };

			//make a 3X3 matrix with those values
			Matrix a = Matrix(3, 3, x);

			//make sure they are in the matrix
			Assert::AreEqual(0.0, a[0][0]);
			Assert::AreEqual(1.0, a[0][1]);
			Assert::AreEqual(2.0, a[0][2]);
			Assert::AreEqual(3.0, a[1][0]);
			Assert::AreEqual(4.0, a[1][1]);
			Assert::AreEqual(5.0, a[1][2]);
			Assert::AreEqual(6.0, a[2][0]);
			Assert::AreEqual(7.0, a[2][1]);
			Assert::AreEqual(8.0, a[2][2]);

			//make a matrix and move the memory of 'a' into this matrix
			Matrix moveHere(std::move(a));

			//make sure the rows and columns reflect the dimensions of a matrix with no data
			Assert::AreEqual(0, a.getRows());
			Assert::AreEqual(0, a.getColumns());

			//make sure that everything got moved
			Assert::AreEqual(0.0, moveHere[0][0]);
			Assert::AreEqual(1.0, moveHere[0][1]);
			Assert::AreEqual(2.0, moveHere[0][2]);
			Assert::AreEqual(3.0, moveHere[1][0]);
			Assert::AreEqual(4.0, moveHere[1][1]);
			Assert::AreEqual(5.0, moveHere[1][2]);
			Assert::AreEqual(6.0, moveHere[2][0]);
			Assert::AreEqual(7.0, moveHere[2][1]);
			Assert::AreEqual(8.0, moveHere[2][2]);

			//check that there is no data in a
			Assert::IsTrue(NULL == a.getData());
		}

		TEST_METHOD(T04_assignmentOperator)
		{
			//make 9 values
			int x[9] = { 0,1,2,3,4,5,6,7,8 };
			int y[9] = { 9,9,9,9,9,9,9,9,9 };

			//make a 3X3 matrix with those values
			Matrix a = Matrix(3, 3, x);

			//make sure they are in the matrix
			Assert::AreEqual(0.0, a[0][0]);
			Assert::AreEqual(1.0, a[0][1]);
			Assert::AreEqual(2.0, a[0][2]);
			Assert::AreEqual(3.0, a[1][0]);
			Assert::AreEqual(4.0, a[1][1]);
			Assert::AreEqual(5.0, a[1][2]);
			Assert::AreEqual(6.0, a[2][0]);
			Assert::AreEqual(7.0, a[2][1]);
			Assert::AreEqual(8.0, a[2][2]);

			//make a matrix and move the memory of 'a' into this matrix
			Matrix assignment = Matrix(3, 3, y);

			assignment = a;

			//check that 'a' still has its original values
			Assert::AreEqual(0.0, a[0][0]);
			Assert::AreEqual(1.0, a[0][1]);
			Assert::AreEqual(2.0, a[0][2]);
			Assert::AreEqual(3.0, a[1][0]);
			Assert::AreEqual(4.0, a[1][1]);
			Assert::AreEqual(5.0, a[1][2]);
			Assert::AreEqual(6.0, a[2][0]);
			Assert::AreEqual(7.0, a[2][1]);
			Assert::AreEqual(8.0, a[2][2]);

			//make sure that everything got moved
			Assert::AreEqual(0.0, assignment[0][0]);
			Assert::AreEqual(1.0, assignment[0][1]);
			Assert::AreEqual(2.0, assignment[0][2]);
			Assert::AreEqual(3.0, assignment[1][0]);
			Assert::AreEqual(4.0, assignment[1][1]);
			Assert::AreEqual(5.0, assignment[1][2]);
			Assert::AreEqual(6.0, assignment[2][0]);
			Assert::AreEqual(7.0, assignment[2][1]);
			Assert::AreEqual(8.0, assignment[2][2]);
		}

		TEST_METHOD(T05_moveAssignmentOperator)
		{
			//make 9 values
			int x[9] = { 0,1,2,3,4,5,6,7,8 };

			//make a 3X3 matrix with those values
			Matrix a = Matrix(3, 3, x);

			//make sure they are in the matrix
			Assert::AreEqual(0.0, a[0][0]);
			Assert::AreEqual(1.0, a[0][1]);
			Assert::AreEqual(2.0, a[0][2]);
			Assert::AreEqual(3.0, a[1][0]);
			Assert::AreEqual(4.0, a[1][1]);
			Assert::AreEqual(5.0, a[1][2]);
			Assert::AreEqual(6.0, a[2][0]);
			Assert::AreEqual(7.0, a[2][1]);
			Assert::AreEqual(8.0, a[2][2]);

			//make a matrix and move the memory of 'a' into this matrix
			Matrix moveHere = std::move(a);

			//make sure the rows and columns reflect the dimensions of a matrix with no data
			Assert::AreEqual(0, a.getRows());
			Assert::AreEqual(0, a.getColumns());

			//make sure that everything got moved
			Assert::AreEqual(0.0, moveHere[0][0]);
			Assert::AreEqual(1.0, moveHere[0][1]);
			Assert::AreEqual(2.0, moveHere[0][2]);
			Assert::AreEqual(3.0, moveHere[1][0]);
			Assert::AreEqual(4.0, moveHere[1][1]);
			Assert::AreEqual(5.0, moveHere[1][2]);
			Assert::AreEqual(6.0, moveHere[2][0]);
			Assert::AreEqual(7.0, moveHere[2][1]);
			Assert::AreEqual(8.0, moveHere[2][2]);

			//check that there is no data in a
			Assert::IsTrue(NULL == a.getData());
		}

		TEST_METHOD(T06_accessOperator)
		{
			//make 9 values
			int x[9] = { 0,1,2,3,4,5,6,7,8 };

			//make a 3X3 matrix with those values
			Matrix a = Matrix(3, 3, x);

			//make sure they are in the matrix
			Assert::AreEqual(0.0, a[0][0]);
			Assert::AreEqual(1.0, a[0][1]);
			Assert::AreEqual(2.0, a[0][2]);
			Assert::AreEqual(3.0, a[1][0]);
			Assert::AreEqual(4.0, a[1][1]);
			Assert::AreEqual(5.0, a[1][2]);
			Assert::AreEqual(6.0, a[2][0]);
			Assert::AreEqual(7.0, a[2][1]);
			Assert::AreEqual(8.0, a[2][2]);
		}

		TEST_METHOD(T07_transpose)
		{
			//make 9 values
			int x[9] = { 0,1,2,3,4,5,6,7,8 };

			//make a 3X3 matrix with those values
			Matrix a = Matrix(3, 3, x);

			//make sure they are in the matrix
			Assert::AreEqual(0.0, a[0][0]);Assert::AreEqual(1.0, a[0][1]);Assert::AreEqual(2.0, a[0][2]);
			Assert::AreEqual(3.0, a[1][0]);Assert::AreEqual(4.0, a[1][1]);Assert::AreEqual(5.0, a[1][2]);
			Assert::AreEqual(6.0, a[2][0]);Assert::AreEqual(7.0, a[2][1]);Assert::AreEqual(8.0, a[2][2]);

			//transpose it
			a.transpose();

			//make sure they are transposed
			Assert::AreEqual(0.0, a[0][0]);Assert::AreEqual(3.0, a[0][1]);Assert::AreEqual(6.0, a[0][2]);
			Assert::AreEqual(1.0, a[1][0]);Assert::AreEqual(4.0, a[1][1]);Assert::AreEqual(7.0, a[1][2]);
			Assert::AreEqual(2.0, a[2][0]);Assert::AreEqual(5.0, a[2][1]);Assert::AreEqual(8.0, a[2][2]);
		}

		TEST_METHOD(T08_transposed)
		{
			//make 9 values
			int x[9] = { 0,1,2,3,4,5,6,7,8 };

			//make a 3X3 matrix with those values
			Matrix a = Matrix(3, 3, x);

			//make sure they are in the matrix
			Assert::AreEqual(0.0, a[0][0]);
			Assert::AreEqual(1.0, a[0][1]);
			Assert::AreEqual(2.0, a[0][2]);
			Assert::AreEqual(3.0, a[1][0]);
			Assert::AreEqual(4.0, a[1][1]);
			Assert::AreEqual(5.0, a[1][2]);
			Assert::AreEqual(6.0, a[2][0]);
			Assert::AreEqual(7.0, a[2][1]);
			Assert::AreEqual(8.0, a[2][2]);

			//transpose it
			Matrix transposed = a.transposed();

			//make sure they are transposed
			Assert::AreEqual(0.0, transposed[0][0]);
			Assert::AreEqual(3.0, transposed[0][1]);
			Assert::AreEqual(6.0, transposed[0][2]);
			Assert::AreEqual(1.0, transposed[1][0]);
			Assert::AreEqual(4.0, transposed[1][1]);
			Assert::AreEqual(7.0, transposed[1][2]);
			Assert::AreEqual(2.0, transposed[2][0]);
			Assert::AreEqual(5.0, transposed[2][1]);
			Assert::AreEqual(8.0, transposed[2][2]);
		}

		TEST_METHOD(T09_multiplicationOperator)
		{
			//make 9 values
			int ninevalues[9] = { 0,1,2,3,4,5,6,7,8 };

			//make a 3X3 matrix with those values
			Matrix a = Matrix(3, 3, ninevalues);

			//make sure they are in the matrix
			Assert::AreEqual(0.0, a[0][0]);
			Assert::AreEqual(1.0, a[0][1]);
			Assert::AreEqual(2.0, a[0][2]);
			Assert::AreEqual(3.0, a[1][0]);
			Assert::AreEqual(4.0, a[1][1]);
			Assert::AreEqual(5.0, a[1][2]);
			Assert::AreEqual(6.0, a[2][0]);
			Assert::AreEqual(7.0, a[2][1]);
			Assert::AreEqual(8.0, a[2][2]);

			//multiply by 3
			Matrix b = a * 3;

			//make sure matrix a is the same
			Assert::AreEqual(0.0, a[0][0]);
			Assert::AreEqual(1.0, a[0][1]);
			Assert::AreEqual(2.0, a[0][2]);
			Assert::AreEqual(3.0, a[1][0]);
			Assert::AreEqual(4.0, a[1][1]);
			Assert::AreEqual(5.0, a[1][2]);
			Assert::AreEqual(6.0, a[2][0]);
			Assert::AreEqual(7.0, a[2][1]);
			Assert::AreEqual(8.0, a[2][2]);


			//make sure matrix b has the right values
			Assert::AreEqual(0.0, b[0][0]);
			Assert::AreEqual(3.0, b[0][1]);
			Assert::AreEqual(6.0, b[0][2]);
			Assert::AreEqual(9.0, b[1][0]);
			Assert::AreEqual(12.0, b[1][1]);
			Assert::AreEqual(15.0, b[1][2]);
			Assert::AreEqual(18.0, b[2][0]);
			Assert::AreEqual(21.0, b[2][1]);
			Assert::AreEqual(24.0, b[2][2]);

			//use shorthand
			a *= 3;

			//make sure a has right values now
			Assert::AreEqual(0.0, a[0][0]);
			Assert::AreEqual(3.0, a[0][1]);
			Assert::AreEqual(6.0, a[0][2]);
			Assert::AreEqual(9.0, a[1][0]);
			Assert::AreEqual(12.0, a[1][1]);
			Assert::AreEqual(15.0, a[1][2]);
			Assert::AreEqual(18.0, a[2][0]);
			Assert::AreEqual(21.0, a[2][1]);
			Assert::AreEqual(24.0, a[2][2]);

			//make a 2X3 matrix and a 3X2 matrix and a 2X2 to test multiplying two matrices
			//make 9 values
			int l[6] = { 2,3,4,5,6,7 };

			//make a 2X3 matrix with those values
			Matrix x = Matrix(2, 3, l);

			//make 9 values
			int m[6] = { 10,20,30,40,50,60 };

			//make a 3X2 matrix with those values
			Matrix y = Matrix(3, 2, m);

			//make 9 values
			int n[9] = { 0,1,2,3,4,5,6,7,8 };

			//make a 2X2 matrix with those values
			Matrix z = Matrix(2, 2, n);

			//check the operator=(Matrix other)
			Assert::IsTrue(z == (x*y));

			//check the operator*=(Matrix other)
			x *= y;

			Assert::IsTrue(z == x);
		}

		TEST_METHOD(T10_additionOperator)
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

		TEST_METHOD(T11_subtractionOperator)
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

		TEST_METHOD(T12_equivalence)
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

		TEST_METHOD(T13_outputoperator)
		{
			int x[9] = { 0,1,2,3,4,5,6,7,8 };

			Matrix test = Matrix(3,3,x);

			std::stringstream out;

			out << test;

			std::string testText = "[\t0\t1\t2\t]\n[\t3\t4\t5\t]\n[\t6\t7\t8\t]\n";

			Assert::AreEqual(testText, out.str());
		}
	};
}
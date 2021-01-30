//Cody Ware
//6/30/19

#include "CppUnitTest.h"
#include "Matrix.h"
#include "Transform.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PhysicsEngineTester
{
	TEST_CLASS(TransformTester)
	{

		TEST_METHOD(T_001_bigFive)
		{
			//default constructor
			Transform x;

			Assert::IsTrue(x.isRowMajor() == true, L"defaults to row major");
			Transform a;

			a.toOtherMajor();

			//copy constructor
			Transform y(a);

			Assert::IsTrue(y.isRowMajor() == false, L"test that copy constructor copies major");

			//move constructor
			Transform z(std::move(x));

			//operator=
			x = a;

			//move operator
			z = std::move(a);
		}

		TEST_METHOD(T_002_switchMajors)
		{
			Transform a;

			a.toOtherMajor();

			Assert::IsTrue(!a.isRowMajor(), L"test that changing majors works");
		}

		TEST_METHOD(T_003_getSetTranslate)
		{
			Transform a;

			PhysicsVector x;
			x.addDimension(1);
			x.addDimension(2);
			x.addDimension(3);

			a.setTranslate(x);

			Assert::IsTrue(a.getTranslate() == x, L"make sure that the transform was set when row major");

			a.toOtherMajor();

			Assert::IsTrue(a.getTranslate() == x, L"changing majors to column major must maintain transform");

			Transform b;

			b.toOtherMajor();

			b.setTranslate(x);

			Assert::IsTrue(b.getTranslate() == x, L"make sure that transform is set when column major");

			Assert::IsTrue(b.getTranslate() == x, L"changing majors to row major must maintain transform");
		}

		TEST_METHOD(T_004_getSetScale)
		{
			Transform a;

			PhysicsVector x;
			x.addDimension(1);
			x.addDimension(2);
			x.addDimension(3);

			a.setScale(x);

			Assert::IsTrue(a.getScale() == x, L"make sure that the scale was set in row major");

			a.toOtherMajor();

			Assert::IsTrue(a.getScale() == x, L"changing majors to column major must maintain scale");

			Transform b;

			b.toOtherMajor();

			b.setScale(x);

			Assert::IsTrue(b.getScale() == x, L"make sure that setting scale in column major works");

			b.toOtherMajor();

			Assert::IsTrue(b.getScale() == x, L"make sure that changing major to row major maintains the scale");
		}

		TEST_METHOD(T_005_getSetXYZAxis)
		{
			Transform rowMajorTest;

			PhysicsVector rowMajorTestVector;
			rowMajorTestVector.addDimension(1);
			rowMajorTestVector.addDimension(2);
			rowMajorTestVector.addDimension(3);

			//xaxis
			rowMajorTest.setXAxis(rowMajorTestVector);

			Assert::IsTrue(rowMajorTest.getXAxis() == rowMajorTestVector, L"make sure xaxis get set");

			//yaxis
			rowMajorTestVector *= 2;
			rowMajorTest.setYAxis(rowMajorTestVector);

			Assert::IsTrue(rowMajorTest.getYAxis() == rowMajorTestVector, L"make sure y axis gets set");

			//zaxis
			rowMajorTestVector *= 2;
			rowMajorTest.setZAxis(rowMajorTestVector);

			Assert::IsTrue(rowMajorTest.getZAxis() == rowMajorTestVector, L"make sure z axis gets set");

			rowMajorTest.toOtherMajor();

			Assert::IsTrue(rowMajorTest.getZAxis() == rowMajorTestVector, L"make sure z axis is maintained after changing majors");
			rowMajorTestVector /= 2;
			Assert::IsTrue(rowMajorTest.getYAxis() == rowMajorTestVector, L"make sure y axis is maintained after changing majors");
			rowMajorTestVector /= 2;
			Assert::IsTrue(rowMajorTest.getXAxis() == rowMajorTestVector, L"make sure x axis is maintained after changing majors");

			//test again but start with a column major
			Transform columnMajorTest;
			columnMajorTest.toOtherMajor();

			PhysicsVector columnMajorTestVector;
			columnMajorTestVector.addDimension(1);
			columnMajorTestVector.addDimension(2);
			columnMajorTestVector.addDimension(3);

			//xaxis
			columnMajorTest.setXAxis(columnMajorTestVector);

			Assert::IsTrue(columnMajorTest.getXAxis() == columnMajorTestVector, L"make sure xaxis get set");

			//yaxis
			columnMajorTestVector *= 2;
			columnMajorTest.setYAxis(columnMajorTestVector);

			Assert::IsTrue(columnMajorTest.getYAxis() == columnMajorTestVector, L"make sure y axis gets set");

			//zaxis
			columnMajorTestVector *= 2;
			columnMajorTest.setZAxis(columnMajorTestVector);

			Assert::IsTrue(columnMajorTest.getZAxis() == columnMajorTestVector, L"make sure z axis gets set");

			columnMajorTest.toOtherMajor();

			Assert::IsTrue(columnMajorTest.getZAxis() == columnMajorTestVector, L"make sure z axis is maintained after changing majors");
			columnMajorTestVector /= 2;
			Assert::IsTrue(columnMajorTest.getYAxis() == columnMajorTestVector, L"make sure y axis is maintained after changing majors");
			columnMajorTestVector /= 2;
			Assert::IsTrue(columnMajorTest.getXAxis() == columnMajorTestVector, L"make sure x axis is maintained after changing majors");

		}

		TEST_METHOD(T_006_rotateZ)
		{
			Matrix expectedAfterRotating45degrees;
			//hard coded numbers i got from doing paper math
			expectedAfterRotating45degrees[0][0] = 0.52532198881772973;
			expectedAfterRotating45degrees[0][1] = 0.85090352453411844;
			expectedAfterRotating45degrees[1][0] = -0.85090352453411844;
			expectedAfterRotating45degrees[1][1] = 0.52532198881772973;

			Transform x;

			Matrix actualAfter45DegreeZRotate = x.rotateZ(45);

			Assert::IsTrue(actualAfter45DegreeZRotate == expectedAfterRotating45degrees, L"rotating Z 45 degrees doesnt work as expected");
		}

		TEST_METHOD(T_007_rotateY)
		{
			Matrix expectedAfterRotating45degrees;
			//hard coded numbers i got from doing paper math
			expectedAfterRotating45degrees[0][0] = 0.52532198881772973;
			expectedAfterRotating45degrees[0][2] = -0.85090352453411844;
			expectedAfterRotating45degrees[2][0] = 0.85090352453411844;
			expectedAfterRotating45degrees[2][2] = 0.52532198881772973;

			Transform x;

			Matrix actualAfter45DegreeYRotate = x.rotateY(45);

			Assert::IsTrue(actualAfter45DegreeYRotate == expectedAfterRotating45degrees, L"rotating Y 45 degrees doesnt work as expected");
		}

		TEST_METHOD(T_008_rotateX)
		{
			Matrix expectedAfterRotating45degrees;
			//hard coded numbers i got from doing paper math
			expectedAfterRotating45degrees[1][1] = 0.52532198881772973;
			expectedAfterRotating45degrees[1][2] = 0.85090352453411844;
			expectedAfterRotating45degrees[2][1] = -0.85090352453411844;
			expectedAfterRotating45degrees[2][2] = 0.52532198881772973;

			Transform x;

			Matrix actualAfter45DegreeXRotate = x.rotateX(45);

			Assert::IsTrue(actualAfter45DegreeXRotate == expectedAfterRotating45degrees, L"rotating X 45 degrees doesnt work as expected");
		}

		TEST_METHOD(T_009_rotate)
		{
			Matrix expectedAfterRotating;
			//hard coded numbers i got from doing paper math
			expectedAfterRotating[0][0] = 0.89204866381000347;
			expectedAfterRotating[0][1] = 0.4469983318002789;
			expectedAfterRotating[0][2] = -0.066645875810550259;
			expectedAfterRotating[1][0] = -0.066645875810550259;
			expectedAfterRotating[1][1] = 0.27596319193541492796;

			expectedAfterRotating[1][2] = 0.95885486072411519;
			expectedAfterRotating[2][0] = 0.44699833180027893556;
			expectedAfterRotating[2][1] = -0.85090352453411844;
			expectedAfterRotating[2][2] = 0.27596319193541492796;

			Transform x;

			Matrix actual = x.getRotationMatrix(45, 45, 45);

			Assert::IsTrue(actual == expectedAfterRotating, L"rotation matrix is not as expected");
		}

		TEST_METHOD(T_010_axisAngleRotate)
		{
			Assert::IsTrue(false, L"testAxisAngleRotate not implemented");
		}


	};
}

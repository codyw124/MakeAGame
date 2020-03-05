//cody ware
//2/21/2020

#include "CppUnitTest.h"
#include "PhysicsVectorTests.h"
#include "PointTests.h"
#include "MatricesTests.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestPhysicsEngine
{
	TEST_CLASS(TestPhysicsVectorClass)
	{
	public:

		TEST_METHOD(constructor)
		{
			PhysicsVectorTests test;
			test.T01_constructor2D();
		}

		TEST_METHOD(constructorWithValues2D)
		{
			PhysicsVectorTests test;
			test.T02_constructorWithValues2D();
		}

		TEST_METHOD(copyConstructor2D)
		{
			PhysicsVectorTests test;
			test.T03_copyConstructor2D();
		}

		TEST_METHOD(moveConstructor2D)
		{
			PhysicsVectorTests test;
			test.T04_moveConstructor2D();
		}

		TEST_METHOD(assignmentOperator2D)
		{
			PhysicsVectorTests test;
			test.T05_assignmentOperator2D();
		}

		TEST_METHOD(moveAssignmentOperator2D)
		{
			PhysicsVectorTests test;
			test.T06_moveAssignmentOperator2D();
		}

		TEST_METHOD(additionOperator2D)
		{
			PhysicsVectorTests test;
			test.T07_additionOperator2D();
		}

		TEST_METHOD(subtractionOperator2D)
		{
			PhysicsVectorTests test;
			test.T08_subtractionOperator2D();
		}

		TEST_METHOD(multiplyOperator2D)
		{
			PhysicsVectorTests test;
			test.T09_multiplyOperator2D();
		}

		TEST_METHOD(multiplyByDoubleOperator2D)
		{
			PhysicsVectorTests test;
			test.T10_multiplyByDoubleOperator2D();
		}

		TEST_METHOD(equivalenceOperators2D)
		{
			PhysicsVectorTests test;
			test.T11_equivalenceOperators2D();
		}

		TEST_METHOD(dotProduct2D)
		{
			PhysicsVectorTests test;
			test.T12_dotProduct2D();
		}

		TEST_METHOD(magnitude2D)
		{
			PhysicsVectorTests test;
			test.T13_magnitude2D();
		}

		TEST_METHOD(magnitudeSquared2D)
		{
			PhysicsVectorTests test;
			test.T14_magnitudeSquared2D();
		}

		TEST_METHOD(divideOperator2D)
		{
			PhysicsVectorTests test;
			test.T15_divideOperator2D();
		}

		TEST_METHOD(divideByDoubleOperator2D)
		{
			PhysicsVectorTests test;
			test.T16_divideByDoubleOperator2D();
		}

		TEST_METHOD(additionShorthandOperator2D)
		{
			PhysicsVectorTests test;
			test.T17_additionShorthandOperator2D();
		}

		TEST_METHOD(subtractionShorthandOperator2D)
		{
			PhysicsVectorTests test;
			test.T18_subtractionShorthandOperator2D();
		}

		TEST_METHOD(multiplyShorthandOperator2D)
		{
			PhysicsVectorTests test;
			test.T19_multiplyShorthandOperator2D();
		}

		TEST_METHOD(multiplyByDoubleShorthandOperator2D)
		{
			PhysicsVectorTests test;
			test.T20_multiplyByDoubleShorthandOperator2D();
		}

		TEST_METHOD(divideShorthandOperator2D)
		{
			PhysicsVectorTests test;
			test.T21_divideShorthandOperator2D();
		}

		TEST_METHOD(divideByDoubleShorthandOperator2D)
		{
			PhysicsVectorTests test;
			test.T22_divideByDoubleShorthandOperator2D();
		}

		TEST_METHOD(distance2D)
		{
			PhysicsVectorTests test;
			test.T23_distance2D();
		}

		TEST_METHOD(distanceSquared2D)
		{
			PhysicsVectorTests test;
			test.T24_distanceSquared2D();
		}

		TEST_METHOD(normalize2D)
		{
			PhysicsVectorTests test;
			test.T25_normalize2D();
		}

		TEST_METHOD(normalized2D)
		{
			PhysicsVectorTests test;
			test.T26_normalized2D();
		}

		TEST_METHOD(project2D)
		{
			PhysicsVectorTests test;
			test.T27_project2D();
		}

		TEST_METHOD(outputOperator2D)
		{
			PhysicsVectorTests test;
			test.T28_outputOperator2D();
		}

		TEST_METHOD(perpendicular2D)
		{
			PhysicsVectorTests test;
			test.T29_perpendicular2D();
		}

		TEST_METHOD(rotate2D)
		{
			PhysicsVectorTests test;
			test.T30_rotate2D();
		}

		TEST_METHOD(angle2D)
		{
			PhysicsVectorTests test;
			test.T31_angle2D();
		}

		TEST_METHOD(reflect2D)
		{
			PhysicsVectorTests test;
			test.T32_reflect2D();
		}

		TEST_METHOD(constructor3D)
		{
			PhysicsVectorTests test;
			test.T33_constructor3D();
		}

		TEST_METHOD(constructorWithValues3D)
		{
			PhysicsVectorTests test;
			test.T34_constructorWithValues3D();
		}

		TEST_METHOD(copyConstructor3D)
		{
			PhysicsVectorTests test;
			test.T35_copyConstructor3D();
		}

		TEST_METHOD(moveConstructor3D)
		{
			PhysicsVectorTests test;
			test.T36_moveConstructor3D();
		}

		TEST_METHOD(assignmentOperator3D)
		{
			PhysicsVectorTests test;
			test.T37_assignmentOperator3D();
		}

		TEST_METHOD(moveAssignmentOperator3D)
		{
			PhysicsVectorTests test;
			test.T38_moveAssignmentOperator3D();
		}

		TEST_METHOD(additionOperator3D)
		{
			PhysicsVectorTests test;
			test.T39_additionOperator3D();
		}

		TEST_METHOD(subtractionOperator3D)
		{
			PhysicsVectorTests test;
			test.T40_subtractionOperator3D();
		}

		TEST_METHOD(multiply2Vector3sOperator3D)
		{
			PhysicsVectorTests test;
			test.T41_multiply2Vector3sOperator3D();
		}

		TEST_METHOD(multiplyVector3ByDouble3D)
		{
			PhysicsVectorTests test;
			test.T42_multiplyVector3ByDouble3D();
		}

		TEST_METHOD(equivalenceOperators3D)
		{
			PhysicsVectorTests test;
			test.T43_equivalenceOperators3D();
		}

		TEST_METHOD(dotProduct3D)
		{
			PhysicsVectorTests test;
			test.T44_dotProduct3D();
		}

		TEST_METHOD(magnitude3D)
		{
			PhysicsVectorTests test;
			test.T45_magnitude3D();
		}

		TEST_METHOD(magnitudeSquared3D)
		{
			PhysicsVectorTests test;
			test.T46_magnitudeSquared3D();
		}

		TEST_METHOD(divide2Vector3sOperator3D)
		{
			PhysicsVectorTests test;
			test.T47_divide2Vector3sOperator3D();
		}

		TEST_METHOD(divideVector3ByDoubleOperator3D)
		{
			PhysicsVectorTests test;
			test.T48_divideVector3ByDoubleOperator3D();
		}

		TEST_METHOD(additionShorthandOperator3D)
		{
			PhysicsVectorTests test;
			test.T49_additionShorthandOperator3D();
		}

		TEST_METHOD(subtractionShorthandOperator3D)
		{
			PhysicsVectorTests test;
			test.T50_subtractionShorthandOperator3D();
		}

		TEST_METHOD(multiply2Vector3sShorthandOperator3D)
		{
			PhysicsVectorTests test;
			test.T51_multiply2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(multiplyVector3ByDoubleShorthandOperator3D)
		{
			PhysicsVectorTests test;
			test.T52_multiplyVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(divide2Vector3sShorthandOperator3D)
		{
			PhysicsVectorTests test;
			test.T53_divide2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(divideVector3ByDoubleShorthandOperator3D)
		{
			PhysicsVectorTests test;
			test.T54_divideVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(distance3D)
		{
			PhysicsVectorTests test;
			test.T55_distance3D();
		}

		TEST_METHOD(distanceSquared3D)
		{
			PhysicsVectorTests test;
			test.T56_distanceSquared3D();
		}

		TEST_METHOD(normalize3D)
		{
			PhysicsVectorTests test;
			test.T57_normalize3D();
		}

		TEST_METHOD(normalized3D)
		{
			PhysicsVectorTests test;
			test.T58_normalized3D();
		}

		TEST_METHOD(project3D)
		{
			PhysicsVectorTests test;
			test.T59_project3D();
		}

		TEST_METHOD(outputOperator3D)
		{
			PhysicsVectorTests test;
			test.T60_outputOperator3D();
		}

		TEST_METHOD(perpendicular3D)
		{
			PhysicsVectorTests test;
			test.T61_perpendicular3D();
		}

		TEST_METHOD(angle3D)
		{
			PhysicsVectorTests test;
			test.T62_angle3D();
		}

		TEST_METHOD(reflect3D)
		{
			PhysicsVectorTests test;
			test.T63_reflect3D();
		}

		TEST_METHOD(crossProduct3D)
		{
			PhysicsVectorTests test;
			test.T64_crossProduct3D();
		}
	};

	TEST_CLASS(TestPointClass)
	{
	public:
		TEST_METHOD(constructor2D)
		{
			PointTests test;
			test.T01_constructor2D();
		}

		TEST_METHOD(constructorWithValues2D)
		{
			PointTests test;
			test.T02_constructorWithValues2D();
		}

		TEST_METHOD(copyConstructor2D)
		{
			PointTests test;
			test.T03_copyConstructor2D();
		}

		TEST_METHOD(moveConstructor2D)
		{
			PointTests test;
			test.T04_moveConstructor2D();
		}

		TEST_METHOD(assignmentOperator2D)
		{
			PointTests test;
			test.T05_assignmentOperator2D();
		}

		TEST_METHOD(moveAssignmentOperator2D)
		{
			PointTests test;
			test.T06_moveAssignmentOperator2D();
		}

		TEST_METHOD(additionOperator2D)
		{
			PointTests test;
			test.T07_additionOperator2D();
		}

		TEST_METHOD(subtractionOperator2D)
		{
			PointTests test;
			test.T08_subtractionOperator2D();
		}

		TEST_METHOD(multiplyOperator2D)
		{
			PointTests test;
			test.T09_multiplyOperator2D();
		}

		TEST_METHOD(multiplyByDoubleOperator2D)
		{
			PointTests test;
			test.T10_multiplyByDoubleOperator2D();
		}

		TEST_METHOD(equivalenceOperators2D)
		{
			PointTests test;
			test.T11_equivalenceOperators2D();
		}

		TEST_METHOD(dotProduct2D)
		{
			PointTests test;
			test.T12_dotProduct2D();
		}

		TEST_METHOD(magnitude2D)
		{
			PointTests test;
			test.T13_magnitude2D();
		}

		TEST_METHOD(magnitudeSquared2D)
		{
			PointTests test;
			test.T14_magnitudeSquared2D();
		}

		TEST_METHOD(divideOperator2D)
		{
			PointTests test;
			test.T15_divideOperator2D();
		}

		TEST_METHOD(divideByDoubleOperator2D)
		{
			PointTests test;
			test.T16_divideByDoubleOperator2D();
		}

		TEST_METHOD(additionShorthandOperator2D)
		{
			PointTests test;
			test.T17_additionShorthandOperator2D();
		}

		TEST_METHOD(subtractionShorthandOperator2D)
		{
			PointTests test;
			test.T18_subtractionShorthandOperator2D();
		}

		TEST_METHOD(multiplyShorthandOperator2D)
		{
			PointTests test;
			test.T19_multiplyShorthandOperator2D();
		}

		TEST_METHOD(multiplyByDoubleShorthandOperator2D)
		{
			PointTests test;
			test.T20_multiplyByDoubleShorthandOperator2D();
		}

		TEST_METHOD(divideShorthandOperator2D)
		{
			PointTests test;
			test.T21_divideShorthandOperator2D();
		}

		TEST_METHOD(divideByDoubleShorthandOperator2D)
		{
			PointTests test;
			test.T22_divideByDoubleShorthandOperator2D();
		}

		TEST_METHOD(distance2D)
		{
			PointTests test;
			test.T23_distance2D();
		}

		TEST_METHOD(distanceSquared2D)
		{
			PointTests test;
			test.T24_distanceSquared2D();
		}

		TEST_METHOD(normalize2D)
		{
			PointTests test;
			test.T25_normalize2D();
		}

		TEST_METHOD(normalized2D)
		{
			PointTests test;
			test.T26_normalized2D();
		}

		TEST_METHOD(project2D)
		{
			PointTests test;
			test.T27_project2D();
		}

		TEST_METHOD(outputOperator2D)
		{
			PointTests test;
			test.T28_outputOperator2D();
		}

		TEST_METHOD(perpendicular2D)
		{
			PointTests test;
			test.T29_perpendicular2D();
		}

		TEST_METHOD(rotate2D)
		{
			PointTests test;
			test.T30_rotate2D();
		}

		TEST_METHOD(angle2D)
		{
			PointTests test;
			test.T31_angle2D();
		}

		TEST_METHOD(reflect2D)
		{
			PointTests test;
			test.T32_reflect2D();
		}

		TEST_METHOD(constructor3D)
		{
			PointTests test;
			test.T33_constructor3D();
		}

		TEST_METHOD(constructorWithValues3D)
		{
			PointTests test;
			test.T34_constructorWithValues3D();
		}

		TEST_METHOD(copyConstructor3D)
		{
			PointTests test;
			test.T35_copyConstructor3D();
		}

		TEST_METHOD(moveConstructor3D)
		{
			PointTests test;
			test.T36_moveConstructor3D();
		}

		TEST_METHOD(assignmentOperator3D)
		{
			PointTests test;
			test.T37_assignmentOperator3D();
		}

		TEST_METHOD(moveAssignmentOperator3D)
		{
			PointTests test;
			test.T38_moveAssignmentOperator3D();
		}

		TEST_METHOD(additionOperator3D)
		{
			PointTests test;
			test.T39_additionOperator3D();
		}

		TEST_METHOD(subtractionOperator3D)
		{
			PointTests test;
			test.T40_subtractionOperator3D();
		}

		TEST_METHOD(multiply2Vector3sOperator3D)
		{
			PointTests test;
			test.T41_multiply2Vector3sOperator3D();
		}

		TEST_METHOD(multiplyVector3ByDouble3D)
		{
			PointTests test;
			test.T42_multiplyVector3ByDouble3D();
		}

		TEST_METHOD(equivalenceOperators3D)
		{
			PointTests test;
			test.T43_equivalenceOperators3D();
		}

		TEST_METHOD(dotProduct3D)
		{
			PointTests test;
			test.T44_dotProduct3D();
		}

		TEST_METHOD(magnitude3D)
		{
			PointTests test;
			test.T45_magnitude3D();
		}

		TEST_METHOD(magnitudeSquared3D)
		{
			PointTests test;
			test.T46_magnitudeSquared3D();
		}

		TEST_METHOD(divide2Vector3sOperator3D)
		{
			PointTests test;
			test.T47_divide2Vector3sOperator3D();
		}

		TEST_METHOD(divideVector3ByDoubleOperator3D)
		{
			PointTests test;
			test.T48_divideVector3ByDoubleOperator3D();
		}

		TEST_METHOD(additionShorthandOperator3D)
		{
			PointTests test;
			test.T49_additionShorthandOperator3D();
		}

		TEST_METHOD(subtractionShorthandOperator3D)
		{
			PointTests test;
			test.T50_subtractionShorthandOperator3D();
		}

		TEST_METHOD(multiply2Vector3sShorthandOperator3D)
		{
			PointTests test;
			test.T51_multiply2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(multiplyVector3ByDoubleShorthandOperator3D)
		{
			PointTests test;
			test.T52_multiplyVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(divide2Vector3sShorthandOperator3D)
		{
			PointTests test;
			test.T53_divide2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(divideVector3ByDoubleShorthandOperator3D)
		{
			PointTests test;
			test.T54_divideVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(distance3D)
		{
			PointTests test;
			test.T55_distance3D();
		}

		TEST_METHOD(distanceSquared3D)
		{
			PointTests test;
			test.T56_distanceSquared3D();
		}

		TEST_METHOD(normalize3D)
		{
			PointTests test;
			test.T57_normalize3D();
		}

		TEST_METHOD(normalized3D)
		{
			PointTests test;
			test.T58_normalized3D();
		}

		TEST_METHOD(project3D)
		{
			PointTests test;
			test.T59_project3D();
		}

		TEST_METHOD(outputOperator3D)
		{
			PointTests test;
			test.T60_outputOperator3D();
		}

		TEST_METHOD(perpendicular3D)
		{
			PointTests test;
			test.T61_perpendicular3D();
		}

		TEST_METHOD(angle3D)
		{
			PointTests test;
			test.T62_angle3D();
		}

		TEST_METHOD(reflect3D)
		{
			PointTests test;
			test.T63_reflect3D();
		}

		TEST_METHOD(crossProduct3D)
		{
			PointTests test;
			test.T64_crossProduct3D();
		}
	};

	TEST_CLASS(TestMatrixClass)
	{
		TEST_METHOD(defaultConstructor)
		{
			MatricesTests test;
			test.T01_defaultConstructor();
		}

		TEST_METHOD(copyConstructor)
		{
			MatricesTests test;
			test.T02_copyConstructor();
		}

		TEST_METHOD(moveConstructor)
		{
			MatricesTests test;
			test.T03_moveConstructor();
		}

		TEST_METHOD(assignmentOperator)
		{
			MatricesTests test;
			test.T04_assignmentOperator();
		}

		TEST_METHOD(moveAssignmentOperator)
		{
			MatricesTests test;
			test.T05_moveAssignmentOperator();
		}

		TEST_METHOD(accessOperator)
		{
			MatricesTests test;
			test.T06_accessOperator();
		}

		TEST_METHOD(transpose)
		{
			MatricesTests test;
			test.T07_transpose();
		}

		TEST_METHOD(transposed)
		{
			MatricesTests test;
			test.T08_transposed();
		}

		TEST_METHOD(multiplicationOperator)
		{
			MatricesTests test;
			test.T09_multiplicationOperator();
		}

		TEST_METHOD(additionOperator)
		{
			MatricesTests test;
			test.T10_additionOperator();
		}

		TEST_METHOD(subtractionOperator)
		{
			MatricesTests test;
			test.T11_subtractionOperator();
		}

		TEST_METHOD(equivalence)
		{
			MatricesTests test;
			test.T12_equivalence();
		}

		TEST_METHOD(outputoperator)
		{
			MatricesTests test;
			test.T13_outputoperator();
		}

		TEST_METHOD(cut)
		{
			MatricesTests test;
			test.T15_cut();
		}

		TEST_METHOD(testDeterminant)
		{
			MatricesTests test;
			test.T16_testDeterminant();
		}

		TEST_METHOD(testMinors)
		{
			MatricesTests test;
			test.T17_testMinors();
		}

		TEST_METHOD(testCofactors)
		{
			MatricesTests test;
			test.T18_testCofactors();
		}

		TEST_METHOD(testAdjugate)
		{
			MatricesTests test;
			test.T19_testAdjugate();
		}

		TEST_METHOD(testInverse)
		{
			MatricesTests test;
			test.T20_testInverse();
		}
	};
}
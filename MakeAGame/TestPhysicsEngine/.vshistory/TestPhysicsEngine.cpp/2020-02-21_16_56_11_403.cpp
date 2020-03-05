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

		TEST_METHOD(TestMethod01constructor2D)
		{
			PhysicsVectorTests test;
			test.T01_constructor2D();
		}

		TEST_METHOD(TestMethod02constructorWithValues2D)
		{
			PhysicsVectorTests test;
			test.T02_constructorWithValues2D();
		}

		TEST_METHOD(TestMethod03copyConstructor2D)
		{
			PhysicsVectorTests test;
			test.T03_copyConstructor2D();
		}

		TEST_METHOD(TestMethod04moveConstructor2D)
		{
			PhysicsVectorTests test;
			test.T04_moveConstructor2D();
		}

		TEST_METHOD(TestMethod05assignmentOperator2D)
		{
			PhysicsVectorTests test;
			test.T05_assignmentOperator2D();
		}

		TEST_METHOD(TestMethod06moveAssignmentOperator2D)
		{
			PhysicsVectorTests test;
			test.T06_moveAssignmentOperator2D();
		}

		TEST_METHOD(TestMethod07additionOperator2D)
		{
			PhysicsVectorTests test;
			test.T07_additionOperator2D();
		}

		TEST_METHOD(TestMethod08subtractionOperator2D)
		{
			PhysicsVectorTests test;
			test.T08_subtractionOperator2D();
		}

		TEST_METHOD(TestMethod09multiplyOperator2D)
		{
			PhysicsVectorTests test;
			test.T09_multiplyOperator2D();
		}

		TEST_METHOD(TestMethod10multiplyByDoubleOperator2D)
		{
			PhysicsVectorTests test;
			test.T10_multiplyByDoubleOperator2D();
		}

		TEST_METHOD(TestMethod11equivalenceOperators2D)
		{
			PhysicsVectorTests test;
			test.T11_equivalenceOperators2D();
		}

		TEST_METHOD(TestMethod12dotProduct2D)
		{
			PhysicsVectorTests test;
			test.T12_dotProduct2D();
		}

		TEST_METHOD(TestMethod13magnitude2D)
		{
			PhysicsVectorTests test;
			test.T13_magnitude2D();
		}

		TEST_METHOD(TestMethod14magnitudeSquared2D)
		{
			PhysicsVectorTests test;
			test.T14_magnitudeSquared2D();
		}

		TEST_METHOD(TestMethod15divideOperator2D)
		{
			PhysicsVectorTests test;
			test.T15_divideOperator2D();
		}

		TEST_METHOD(TestMethod16divideByDoubleOperator2D)
		{
			PhysicsVectorTests test;
			test.T16_divideByDoubleOperator2D();
		}

		TEST_METHOD(TestMethod17additionShorthandOperator2D)
		{
			PhysicsVectorTests test;
			test.T17_additionShorthandOperator2D();
		}

		TEST_METHOD(TestMethod18subtractionShorthandOperator2D)
		{
			PhysicsVectorTests test;
			test.T18_subtractionShorthandOperator2D();
		}

		TEST_METHOD(TestMethod19multiplyShorthandOperator2D)
		{
			PhysicsVectorTests test;
			test.T19_multiplyShorthandOperator2D();
		}

		TEST_METHOD(TestMethod20multiplyByDoubleShorthandOperator2D)
		{
			PhysicsVectorTests test;
			test.T20_multiplyByDoubleShorthandOperator2D();
		}

		TEST_METHOD(TestMethod21divideShorthandOperator2D)
		{
			PhysicsVectorTests test;
			test.T21_divideShorthandOperator2D();
		}

		TEST_METHOD(TestMethod22divideByDoubleShorthandOperator2D)
		{
			PhysicsVectorTests test;
			test.T22_divideByDoubleShorthandOperator2D();
		}

		TEST_METHOD(TestMethod23distance2D)
		{
			PhysicsVectorTests test;
			test.T23_distance2D();
		}

		TEST_METHOD(TestMethod24distanceSquared2D)
		{
			PhysicsVectorTests test;
			test.T24_distanceSquared2D();
		}

		TEST_METHOD(TestMethod25normalize2D)
		{
			PhysicsVectorTests test;
			test.T25_normalize2D();
		}

		TEST_METHOD(TestMethod26normalized2D)
		{
			PhysicsVectorTests test;
			test.T26_normalized2D();
		}

		TEST_METHOD(TestMethod27project2D)
		{
			PhysicsVectorTests test;
			test.T27_project2D();
		}

		TEST_METHOD(TestMethod28outputOperator2D)
		{
			PhysicsVectorTests test;
			test.T28_outputOperator2D();
		}

		TEST_METHOD(TestMethod29perpendicular2D)
		{
			PhysicsVectorTests test;
			test.T29_perpendicular2D();
		}

		TEST_METHOD(TestMethod30rotate2D)
		{
			PhysicsVectorTests test;
			test.T30_rotate2D();
		}

		TEST_METHOD(TestMethod31angle2D)
		{
			PhysicsVectorTests test;
			test.T31_angle2D();
		}

		TEST_METHOD(TestMethod32reflect2D)
		{
			PhysicsVectorTests test;
			test.T32_reflect2D();
		}

		TEST_METHOD(TestMethod33constructor3D)
		{
			PhysicsVectorTests test;
			test.T33_constructor3D();
		}

		TEST_METHOD(TestMethod34constructorWithValues3D)
		{
			PhysicsVectorTests test;
			test.T34_constructorWithValues3D();
		}

		TEST_METHOD(TestMethod35copyConstructor3D)
		{
			PhysicsVectorTests test;
			test.T35_copyConstructor3D();
		}

		TEST_METHOD(TestMethod36moveConstructor3D)
		{
			PhysicsVectorTests test;
			test.T36_moveConstructor3D();
		}

		TEST_METHOD(TestMethod37assignmentOperator3D)
		{
			PhysicsVectorTests test;
			test.T37_assignmentOperator3D();
		}

		TEST_METHOD(TestMethod38moveAssignmentOperator3D)
		{
			PhysicsVectorTests test;
			test.T38_moveAssignmentOperator3D();
		}

		TEST_METHOD(TestMethod39additionOperator3D)
		{
			PhysicsVectorTests test;
			test.T39_additionOperator3D();
		}

		TEST_METHOD(TestMethod40subtractionOperator3D)
		{
			PhysicsVectorTests test;
			test.T40_subtractionOperator3D();
		}

		TEST_METHOD(TestMethod41multiply2Vector3sOperator3D)
		{
			PhysicsVectorTests test;
			test.T41_multiply2Vector3sOperator3D();
		}

		TEST_METHOD(TestMethod42multiplyVector3ByDouble3D)
		{
			PhysicsVectorTests test;
			test.T42_multiplyVector3ByDouble3D();
		}

		TEST_METHOD(TestMethod43equivalenceOperators3D)
		{
			PhysicsVectorTests test;
			test.T43_equivalenceOperators3D();
		}

		TEST_METHOD(TestMethod44dotProduct3D)
		{
			PhysicsVectorTests test;
			test.T44_dotProduct3D();
		}

		TEST_METHOD(TestMethod45magnitude3D)
		{
			PhysicsVectorTests test;
			test.T45_magnitude3D();
		}

		TEST_METHOD(TestMethod46magnitudeSquared3D)
		{
			PhysicsVectorTests test;
			test.T46_magnitudeSquared3D();
		}

		TEST_METHOD(TestMethod47divide2Vector3sOperator3D)
		{
			PhysicsVectorTests test;
			test.T47_divide2Vector3sOperator3D();
		}

		TEST_METHOD(TestMethod48divideVector3ByDoubleOperator3D)
		{
			PhysicsVectorTests test;
			test.T48_divideVector3ByDoubleOperator3D();
		}

		TEST_METHOD(TestMethod49additionShorthandOperator3D)
		{
			PhysicsVectorTests test;
			test.T49_additionShorthandOperator3D();
		}

		TEST_METHOD(TestMethod50subtractionShorthandOperator3D)
		{
			PhysicsVectorTests test;
			test.T50_subtractionShorthandOperator3D();
		}

		TEST_METHOD(TestMethod51multiply2Vector3sShorthandOperator3D)
		{
			PhysicsVectorTests test;
			test.T51_multiply2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(TestMethod52multiplyVector3ByDoubleShorthandOperator3D)
		{
			PhysicsVectorTests test;
			test.T52_multiplyVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(TestMethod53divide2Vector3sShorthandOperator3D)
		{
			PhysicsVectorTests test;
			test.T53_divide2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(TestMethod54divideVector3ByDoubleShorthandOperator3D)
		{
			PhysicsVectorTests test;
			test.T54_divideVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(TestMethod55distance3D)
		{
			PhysicsVectorTests test;
			test.T55_distance3D();
		}

		TEST_METHOD(TestMethod56distanceSquared3D)
		{
			PhysicsVectorTests test;
			test.T56_distanceSquared3D();
		}

		TEST_METHOD(TestMethod57normalize3D)
		{
			PhysicsVectorTests test;
			test.T57_normalize3D();
		}

		TEST_METHOD(TestMethod58normalized3D)
		{
			PhysicsVectorTests test;
			test.T58_normalized3D();
		}

		TEST_METHOD(TestMethod59project3D)
		{
			PhysicsVectorTests test;
			test.T59_project3D();
		}

		TEST_METHOD(TestMethod60outputOperator3D)
		{
			PhysicsVectorTests test;
			test.T60_outputOperator3D();
		}

		TEST_METHOD(TestMethod61perpendicular3D)
		{
			PhysicsVectorTests test;
			test.T61_perpendicular3D();
		}

		TEST_METHOD(TestMethod62angle3D)
		{
			PhysicsVectorTests test;
			test.T62_angle3D();
		}

		TEST_METHOD(TestMethod63reflect3D)
		{
			PhysicsVectorTests test;
			test.T63_reflect3D();
		}

		TEST_METHOD(TestMethod64crossProduct3D)
		{
			PhysicsVectorTests test;
			test.T64_crossProduct3D();
		}
	};

	TEST_CLASS(TestPointClass)
	{
	public:
		TEST_METHOD(TestMethod01constructor2D)
		{
			PointTests test;
			test.T01_constructor2D();
		}

		TEST_METHOD(TestMethod02constructorWithValues2D)
		{
			PointTests test;
			test.T02_constructorWithValues2D();
		}

		TEST_METHOD(TestMethod03copyConstructor2D)
		{
			PointTests test;
			test.T03_copyConstructor2D();
		}

		TEST_METHOD(TestMethod04moveConstructor2D)
		{
			PointTests test;
			test.T04_moveConstructor2D();
		}

		TEST_METHOD(TestMethod05assignmentOperator2D)
		{
			PointTests test;
			test.T05_assignmentOperator2D();
		}

		TEST_METHOD(TestMethod06moveAssignmentOperator2D)
		{
			PointTests test;
			test.T06_moveAssignmentOperator2D();
		}

		TEST_METHOD(TestMethod07additionOperator2D)
		{
			PointTests test;
			test.T07_additionOperator2D();
		}

		TEST_METHOD(TestMethod08subtractionOperator2D)
		{
			PointTests test;
			test.T08_subtractionOperator2D();
		}

		TEST_METHOD(TestMethod09multiplyOperator2D)
		{
			PointTests test;
			test.T09_multiplyOperator2D();
		}

		TEST_METHOD(TestMethod10multiplyByDoubleOperator2D)
		{
			PointTests test;
			test.T10_multiplyByDoubleOperator2D();
		}

		TEST_METHOD(TestMethod11equivalenceOperators2D)
		{
			PointTests test;
			test.T11_equivalenceOperators2D();
		}

		TEST_METHOD(TestMethod12dotProduct2D)
		{
			PointTests test;
			test.T12_dotProduct2D();
		}

		TEST_METHOD(TestMethod13magnitude2D)
		{
			PointTests test;
			test.T13_magnitude2D();
		}

		TEST_METHOD(TestMethod14magnitudeSquared2D)
		{
			PointTests test;
			test.T14_magnitudeSquared2D();
		}

		TEST_METHOD(TestMethod15divideOperator2D)
		{
			PointTests test;
			test.T15_divideOperator2D();
		}

		TEST_METHOD(TestMethod16divideByDoubleOperator2D)
		{
			PointTests test;
			test.T16_divideByDoubleOperator2D();
		}

		TEST_METHOD(TestMethod17additionShorthandOperator2D)
		{
			PointTests test;
			test.T17_additionShorthandOperator2D();
		}

		TEST_METHOD(TestMethod18subtractionShorthandOperator2D)
		{
			PointTests test;
			test.T18_subtractionShorthandOperator2D();
		}

		TEST_METHOD(TestMethod19multiplyShorthandOperator2D)
		{
			PointTests test;
			test.T19_multiplyShorthandOperator2D();
		}

		TEST_METHOD(TestMethod20multiplyByDoubleShorthandOperator2D)
		{
			PointTests test;
			test.T20_multiplyByDoubleShorthandOperator2D();
		}

		TEST_METHOD(TestMethod21divideShorthandOperator2D)
		{
			PointTests test;
			test.T21_divideShorthandOperator2D();
		}

		TEST_METHOD(TestMethod22divideByDoubleShorthandOperator2D)
		{
			PointTests test;
			test.T22_divideByDoubleShorthandOperator2D();
		}

		TEST_METHOD(TestMethod23distance2D)
		{
			PointTests test;
			test.T23_distance2D();
		}

		TEST_METHOD(TestMethod24distanceSquared2D)
		{
			PointTests test;
			test.T24_distanceSquared2D();
		}

		TEST_METHOD(TestMethod25normalize2D)
		{
			PointTests test;
			test.T25_normalize2D();
		}

		TEST_METHOD(TestMethod26normalized2D)
		{
			PointTests test;
			test.T26_normalized2D();
		}

		TEST_METHOD(TestMethod27project2D)
		{
			PointTests test;
			test.T27_project2D();
		}

		TEST_METHOD(TestMethod28outputOperator2D)
		{
			PointTests test;
			test.T28_outputOperator2D();
		}

		TEST_METHOD(TestMethod29perpendicular2D)
		{
			PointTests test;
			test.T29_perpendicular2D();
		}

		TEST_METHOD(TestMethod30rotate2D)
		{
			PointTests test;
			test.T30_rotate2D();
		}

		TEST_METHOD(TestMethod31angle2D)
		{
			PointTests test;
			test.T31_angle2D();
		}

		TEST_METHOD(TestMethod32reflect2D)
		{
			PointTests test;
			test.T32_reflect2D();
		}

		TEST_METHOD(TestMethod33constructor3D)
		{
			PointTests test;
			test.T33_constructor3D();
		}

		TEST_METHOD(TestMethod34constructorWithValues3D)
		{
			PointTests test;
			test.T34_constructorWithValues3D();
		}

		TEST_METHOD(TestMethod35copyConstructor3D)
		{
			PointTests test;
			test.T35_copyConstructor3D();
		}

		TEST_METHOD(TestMethod36moveConstructor3D)
		{
			PointTests test;
			test.T36_moveConstructor3D();
		}

		TEST_METHOD(TestMethod37assignmentOperator3D)
		{
			PointTests test;
			test.T37_assignmentOperator3D();
		}

		TEST_METHOD(TestMethod38moveAssignmentOperator3D)
		{
			PointTests test;
			test.T38_moveAssignmentOperator3D();
		}

		TEST_METHOD(TestMethod39additionOperator3D)
		{
			PointTests test;
			test.T39_additionOperator3D();
		}

		TEST_METHOD(TestMethod40subtractionOperator3D)
		{
			PointTests test;
			test.T40_subtractionOperator3D();
		}

		TEST_METHOD(TestMethod41multiply2Vector3sOperator3D)
		{
			PointTests test;
			test.T41_multiply2Vector3sOperator3D();
		}

		TEST_METHOD(TestMethod42multiplyVector3ByDouble3D)
		{
			PointTests test;
			test.T42_multiplyVector3ByDouble3D();
		}

		TEST_METHOD(TestMethod43equivalenceOperators3D)
		{
			PointTests test;
			test.T43_equivalenceOperators3D();
		}

		TEST_METHOD(TestMethod44dotProduct3D)
		{
			PointTests test;
			test.T44_dotProduct3D();
		}

		TEST_METHOD(TestMethod45magnitude3D)
		{
			PointTests test;
			test.T45_magnitude3D();
		}

		TEST_METHOD(TestMethod46magnitudeSquared3D)
		{
			PointTests test;
			test.T46_magnitudeSquared3D();
		}

		TEST_METHOD(TestMethod47divide2Vector3sOperator3D)
		{
			PointTests test;
			test.T47_divide2Vector3sOperator3D();
		}

		TEST_METHOD(TestMethod48divideVector3ByDoubleOperator3D)
		{
			PointTests test;
			test.T48_divideVector3ByDoubleOperator3D();
		}

		TEST_METHOD(TestMethod49additionShorthandOperator3D)
		{
			PointTests test;
			test.T49_additionShorthandOperator3D();
		}

		TEST_METHOD(TestMethod50subtractionShorthandOperator3D)
		{
			PointTests test;
			test.T50_subtractionShorthandOperator3D();
		}

		TEST_METHOD(TestMethod51multiply2Vector3sShorthandOperator3D)
		{
			PointTests test;
			test.T51_multiply2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(TestMethod52multiplyVector3ByDoubleShorthandOperator3D)
		{
			PointTests test;
			test.T52_multiplyVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(TestMethod53divide2Vector3sShorthandOperator3D)
		{
			PointTests test;
			test.T53_divide2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(TestMethod54divideVector3ByDoubleShorthandOperator3D)
		{
			PointTests test;
			test.T54_divideVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(TestMethod55distance3D)
		{
			PointTests test;
			test.T55_distance3D();
		}

		TEST_METHOD(TestMethod56distanceSquared3D)
		{
			PointTests test;
			test.T56_distanceSquared3D();
		}

		TEST_METHOD(TestMethod57normalize3D)
		{
			PointTests test;
			test.T57_normalize3D();
		}

		TEST_METHOD(TestMethod58normalized3D)
		{
			PointTests test;
			test.T58_normalized3D();
		}

		TEST_METHOD(TestMethod59project3D)
		{
			PointTests test;
			test.T59_project3D();
		}

		TEST_METHOD(TestMethod60outputOperator3D)
		{
			PointTests test;
			test.T60_outputOperator3D();
		}

		TEST_METHOD(TestMethod61perpendicular3D)
		{
			PointTests test;
			test.T61_perpendicular3D();
		}

		TEST_METHOD(TestMethod62angle3D)
		{
			PointTests test;
			test.T62_angle3D();
		}

		TEST_METHOD(TestMethod63reflect3D)
		{
			PointTests test;
			test.T63_reflect3D();
		}

		TEST_METHOD(TestMethod64crossProduct3D)
		{
			PointTests test;
			test.T64_crossProduct3D();
		}
	};

	TEST_CLASS(TestMatrixClass)
	{
		TEST_METHOD(TestMethod01defaultConstructor)
		{
			MatricesTests test;
			test.T01_defaultConstructor();
		}

		TEST_METHOD(TestMethod02copyConstructor)
		{
			MatricesTests test;
			test.T02_copyConstructor();
		}

		TEST_METHOD(TestMethod03moveConstructor)
		{
			MatricesTests test;
			test.T03_moveConstructor();
		}

		TEST_METHOD(TestMethod04assignmentOperator)
		{
			MatricesTests test;
			test.T04_assignmentOperator();
		}

		TEST_METHOD(TestMethod05moveAssignmentOperator)
		{
			MatricesTests test;
			test.T05_moveAssignmentOperator();
		}

		TEST_METHOD(TestMethod06accessOperator)
		{
			MatricesTests test;
			test.T06_accessOperator();
		}

		TEST_METHOD(TestMethod07transpose)
		{
			MatricesTests test;
			test.T07_transpose();
		}

		TEST_METHOD(TestMethod08transposed)
		{
			MatricesTests test;
			test.T08_transposed();
		}

		TEST_METHOD(TestMethod09multiplicationOperator)
		{
			MatricesTests test;
			test.T09_multiplicationOperator();
		}

		TEST_METHOD(TestMethod10additionOperator)
		{
			MatricesTests test;
			test.T10_additionOperator();
		}

		TEST_METHOD(TestMethod11subtractionOperator)
		{
			MatricesTests test;
			test.T11_subtractionOperator();
		}

		TEST_METHOD(TestMethod12equivalence)
		{
			MatricesTests test;
			test.T12_equivalence();
		}

		TEST_METHOD(TestMethod13outputoperator)
		{
			MatricesTests test;
			test.T13_outputoperator();
		}

		TEST_METHOD(TestMethod15cut)
		{
			MatricesTests test;
			test.T15_cut();
		}

		TEST_METHOD(TestMethod16testDeterminant)
		{
			MatricesTests test;
			test.T16_testDeterminant();
		}

		TEST_METHOD(TestMethod17testMinors)
		{
			MatricesTests test;
			test.T17_testMinors();
		}

		TEST_METHOD(TestMethod18testCofactors)
		{
			MatricesTests test;
			test.T18_testCofactors();
		}

		TEST_METHOD(TestMethod19testAdjugate)
		{
			MatricesTests test;
			test.T19_testAdjugate();
		}

		TEST_METHOD(TestMethod20testInverse)
		{
			MatricesTests test;
			test.T20_testInverse();
		}
	};
}
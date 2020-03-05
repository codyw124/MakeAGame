#include "CppUnitTest.h"
#include "PhysicsVectorTests.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestPhysicsEngine
{
	TEST_CLASS(TestPhysicsEngine)
	{
	public:
		
		TEST_METHOD(TestMethod01constructor2D)
		{
			PhysicsVectorTests::T01_constructor2D();
		}

		TEST_METHOD(TestMethod02constructorWithValues2D)
		{
			PhysicsVectorTests::T02_constructorWithValues2D();
		}

		TEST_METHOD(TestMethod03copyConstructor2D)
		{
			PhysicsVectorTests::T03_copyConstructor2D();
		}

		TEST_METHOD(TestMethod04moveConstructor2D)
		{
			PhysicsVectorTests::T04_moveConstructor2D();
		}

		TEST_METHOD(TestMethod05assignmentOperator2D)
		{
			PhysicsVectorTests::T05_assignmentOperator2D();
		}

		TEST_METHOD(TestMethod06moveAssignmentOperator2D)
		{
			PhysicsVectorTests::T06_moveAssignmentOperator2D();
		}

		TEST_METHOD(TestMethod07additionOperator2D)
		{
			PhysicsVectorTests::T07_additionOperator2D();
		}

		TEST_METHOD(TestMethod08subtractionOperator2D)
		{
			PhysicsVectorTests::T08_subtractionOperator2D();
		}

		TEST_METHOD(TestMethod09multiplyOperator2D)
		{
			PhysicsVectorTests::T09_multiplyOperator2D();
		}

		TEST_METHOD(TestMethod10multiplyByDoubleOperator2D)
		{
			PhysicsVectorTests::T10_multiplyByDoubleOperator2D();
		}

		TEST_METHOD(TestMethod11equivalenceOperators2D)
		{
			PhysicsVectorTests::T11_equivalenceOperators2D();
		}

		TEST_METHOD(TestMethod12dotProduct2D)
		{
			PhysicsVectorTests::T12_dotProduct2D();
		}

		TEST_METHOD(TestMethod13magnitude2D)
		{
			PhysicsVectorTests::T13_magnitude2D();
		}

		TEST_METHOD(TestMethod14magnitudeSquared2D)
		{
			PhysicsVectorTests::T14_magnitudeSquared2D();
		}

		TEST_METHOD(TestMethod15divideOperator2D)
		{
			PhysicsVectorTests::T15_divideOperator2D();
		}

		TEST_METHOD(TestMethod16divideByDoubleOperator2D)
		{
			PhysicsVectorTests::T16_divideByDoubleOperator2D();
		}

		TEST_METHOD(TestMethod17additionShorthandOperator2D)
		{
			PhysicsVectorTests::T17_additionShorthandOperator2D();
		}

		TEST_METHOD(TestMethod18subtractionShorthandOperator2D)
		{
			PhysicsVectorTests::T18_subtractionShorthandOperator2D();
		}

		TEST_METHOD(TestMethod19multiplyShorthandOperator2D)
		{
			PhysicsVectorTests::T19_multiplyShorthandOperator2D();
		}

		TEST_METHOD(TestMethod20multiplyByDoubleShorthandOperator2D)
		{
			PhysicsVectorTests::T20_multiplyByDoubleShorthandOperator2D();
		}

		TEST_METHOD(TestMethod21divideShorthandOperator2D)
		{
			PhysicsVectorTests::T21_divideShorthandOperator2D();
		}

		TEST_METHOD(TestMethod22divideByDoubleShorthandOperator2D)
		{
			PhysicsVectorTests::T22_divideByDoubleShorthandOperator2D();
		}

		TEST_METHOD(TestMethod23distance2D)
		{
			PhysicsVectorTests::T23_distance2D();
		}

		TEST_METHOD(TestMethod24distanceSquared2D)
		{
			PhysicsVectorTests::T24_distanceSquared2D();
		}

		TEST_METHOD(TestMethod25normalize2D)
		{
			PhysicsVectorTests::T25_normalize2D();
		}

		TEST_METHOD(TestMethod26normalized2D)
		{
			PhysicsVectorTests::T26_normalized2D();
		}

		TEST_METHOD(TestMethod27project2D)
		{
			PhysicsVectorTests::T27_project2D();
		}

		TEST_METHOD(TestMethod28outputOperator2D)
		{
			PhysicsVectorTests::T28_outputOperator2D();
		}

		TEST_METHOD(TestMethod29perpendicular2D)
		{
			PhysicsVectorTests::T29_perpendicular2D();
		}

		TEST_METHOD(TestMethod30rotate2D)
		{
			PhysicsVectorTests::T30_rotate2D();
		}

		TEST_METHOD(TestMethod31angle2D)
		{
			PhysicsVectorTests::T31_angle2D();
		}

		TEST_METHOD(TestMethod32reflect2D)
		{
			PhysicsVectorTests::T32_reflect2D();
		}

		TEST_METHOD(TestMethod33constructor3D)
		{
			PhysicsVectorTests::T33_constructor3D();
		}

		TEST_METHOD(TestMethod34constructorWithValues3D)
		{
			PhysicsVectorTests::T34_constructorWithValues3D();
		}

		TEST_METHOD(TestMethod35copyConstructor3D)
		{
			PhysicsVectorTests::T35_copyConstructor3D();
		}

		TEST_METHOD(TestMethod36moveConstructor3D)
		{
			PhysicsVectorTests::T36_moveConstructor3D();
		}

		TEST_METHOD(TestMethod37assignmentOperator3D)
		{
			PhysicsVectorTests::T37_assignmentOperator3D();
		}

		TEST_METHOD(TestMethod38moveAssignmentOperator3D)
		{
			PhysicsVectorTests::T38_moveAssignmentOperator3D();
		}

		TEST_METHOD(TestMethod39additionOperator3D)
		{
			PhysicsVectorTests::T39_additionOperator3D();
		}

		TEST_METHOD(TestMethod40subtractionOperator3D)
		{
			PhysicsVectorTests::T40_subtractionOperator3D();
		}

		TEST_METHOD(TestMethod41multiply2Vector3sOperator3D)
		{
			PhysicsVectorTests::T41_multiply2Vector3sOperator3D();
		}

		TEST_METHOD(TestMethod42multiplyVector3ByDouble3D)
		{
			PhysicsVectorTests::T42_multiplyVector3ByDouble3D();
		}

		TEST_METHOD(TestMethod43equivalenceOperators3D)
		{
			PhysicsVectorTests::T43_equivalenceOperators3D();
		}

		TEST_METHOD(TestMethod44dotProduct3D)
		{
			PhysicsVectorTests::T44_dotProduct3D();
		}

		TEST_METHOD(TestMethod45magnitude3D)
		{
			PhysicsVectorTests::T45_magnitude3D();
		}

		TEST_METHOD(TestMethod46magnitudeSquared3D)
		{
			PhysicsVectorTests::T46_magnitudeSquared3D();
		}

		TEST_METHOD(TestMethod47divide2Vector3sOperator3D)
		{
			PhysicsVectorTests::T47_divide2Vector3sOperator3D();
		}

		TEST_METHOD(TestMethod48divideVector3ByDoubleOperator3D)
		{
			PhysicsVectorTests::T48_divideVector3ByDoubleOperator3D();
		}

		TEST_METHOD(TestMethod49additionShorthandOperator3D)
		{
			PhysicsVectorTests::T49_additionShorthandOperator3D();
		}

		TEST_METHOD(TestMethod50subtractionShorthandOperator3D)
		{
			PhysicsVectorTests::T50_subtractionShorthandOperator3D();
		}

		TEST_METHOD(TestMethod51multiply2Vector3sShorthandOperator3D)
		{
			PhysicsVectorTests::T51_multiply2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(TestMethod52multiplyVector3ByDoubleShorthandOperator3D)
		{
			PhysicsVectorTests::T52_multiplyVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(TestMethod53divide2Vector3sShorthandOperator3D)
		{
			PhysicsVectorTests::T53_divide2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(TestMethod54divideVector3ByDoubleShorthandOperator3D)
		{
			PhysicsVectorTests::T54_divideVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(TestMethod55distance3D)
		{
			PhysicsVectorTests::T55_distance3D();
		}

		TEST_METHOD(TestMethod56distanceSquared3D)
		{
			PhysicsVectorTests::T56_distanceSquared3D();
		}

		TEST_METHOD(TestMethod57normalize3D)
		{
			PhysicsVectorTests::T57_normalize3D();
		}

		TEST_METHOD(TestMethod58normalized3D)
		{
			PhysicsVectorTests::T58_normalized3D();
		}

		TEST_METHOD(TestMethod59project3D)
		{
			PhysicsVectorTests::T59_project3D();
		}

		TEST_METHOD(TestMethod60outputOperator3D)
		{
			PhysicsVectorTests::T60_outputOperator3D();
		}

		TEST_METHOD(TestMethod61perpendicular3D)
		{
			PhysicsVectorTests::T61_perpendicular3D();
		}

		TEST_METHOD(TestMethod62angle3D)
		{
			PhysicsVectorTests::T62_angle3D();
		}

		TEST_METHOD(TestMethod63reflect3D)
		{
			PhysicsVectorTests::T63_reflect3D();
		}

		TEST_METHOD(TestMethod64crossProduct3D)
		{
			PhysicsVectorTests::T64_crossProduct3D();
		}

	};
}

#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestPhysicsEngine
{
	TEST_CLASS(TestPhysicsEngine)
	{
	public:
		
		TEST_METHOD(TestMethod01constructor2D)
		{
			T01_constructor2D();
		}

		TEST_METHOD(TestMethod02constructorWithValues2D)
		{
			T02_constructorWithValues2D();
		}

		TEST_METHOD(TestMethod03copyConstructor2D)
		{
			T03_copyConstructor2D();
		}

		TEST_METHOD(TestMethod04moveConstructor2D)
		{
			T04_moveConstructor2D();
		}

		TEST_METHOD(TestMethod05assignmentOperator2D)
		{
			T05_assignmentOperator2D();
		}

		TEST_METHOD(TestMethod06moveAssignmentOperator2D)
		{
			T06_moveAssignmentOperator2D();
		}

		TEST_METHOD(TestMethod07additionOperator2D)
		{
			T07_additionOperator2D();
		}

		TEST_METHOD(TestMethod08subtractionOperator2D)
		{
			T08_subtractionOperator2D();
		}

		TEST_METHOD(TestMethod09multiplyOperator2D)
		{
			T09_multiplyOperator2D();
		}

		TEST_METHOD(TestMethod10multiplyByDoubleOperator2D)
		{
			T10_multiplyByDoubleOperator2D();
		}

		TEST_METHOD(TestMethod11equivalenceOperators2D)
		{
			T11_equivalenceOperators2D();
		}

		TEST_METHOD(TestMethod12dotProduct2D)
		{
			T12_dotProduct2D();
		}

		TEST_METHOD(TestMethod13magnitude2D)
		{
			T13_magnitude2D();
		}

		TEST_METHOD(TestMethod14magnitudeSquared2D)
		{
			T14_magnitudeSquared2D();
		}

		TEST_METHOD(TestMethod15divideOperator2D)
		{
			T15_divideOperator2D();
		}

		TEST_METHOD(TestMethod16divideByDoubleOperator2D)
		{
			T16_divideByDoubleOperator2D();
		}

		TEST_METHOD(TestMethod17additionShorthandOperator2D)
		{
			T17_additionShorthandOperator2D();
		}

		TEST_METHOD(TestMethod18subtractionShorthandOperator2D)
		{
			T18_subtractionShorthandOperator2D();
		}

		TEST_METHOD(TestMethod19multiplyShorthandOperator2D)
		{
			T19_multiplyShorthandOperator2D();
		}

		TEST_METHOD(TestMethod20multiplyByDoubleShorthandOperator2D)
		{
			T20_multiplyByDoubleShorthandOperator2D();
		}

		TEST_METHOD(TestMethod21divideShorthandOperator2D)
		{
			T21_divideShorthandOperator2D();
		}

		TEST_METHOD(TestMethod22divideByDoubleShorthandOperator2D)
		{
			T22_divideByDoubleShorthandOperator2D();
		}

		TEST_METHOD(TestMethod23distance2D)
		{
			T23_distance2D();
		}

		TEST_METHOD(TestMethod24distanceSquared2D)
		{
			T24_distanceSquared2D();
		}

		TEST_METHOD(TestMethod25normalize2D)
		{
			T25_normalize2D();
		}

		TEST_METHOD(TestMethod26normalized2D)
		{
			T26_normalized2D();
		}

		TEST_METHOD(TestMethod27project2D)
		{
			T27_project2D();
		}

		TEST_METHOD(TestMethod28outputOperator2D)
		{
			T28_outputOperator2D();
		}

		TEST_METHOD(TestMethod29perpendicular2D)
		{
			T29_perpendicular2D();
		}

		TEST_METHOD(TestMethod30rotate2D)
		{
			T30_rotate2D();
		}

		TEST_METHOD(TestMethod31angle2D)
		{
			T31_angle2D();
		}

		TEST_METHOD(TestMethod32reflect2D)
		{
			T32_reflect2D();
		}

		TEST_METHOD(TestMethod33constructor3D)
		{
			T33_constructor3D();
		}

		TEST_METHOD(TestMethod34constructorWithValues3D)
		{
			T34_constructorWithValues3D();
		}

		TEST_METHOD(TestMethod35copyConstructor3D)
		{
			T35_copyConstructor3D();
		}

		TEST_METHOD(TestMethod36moveConstructor3D)
		{
			T36_moveConstructor3D();
		}

		TEST_METHOD(TestMethod37assignmentOperator3D)
		{
			T37_assignmentOperator3D();
		}

		TEST_METHOD(TestMethod38moveAssignmentOperator3D)
		{
			T38_moveAssignmentOperator3D();
		}

		TEST_METHOD(TestMethod39additionOperator3D)
		{
			T39_additionOperator3D();
		}

		TEST_METHOD(TestMethod40subtractionOperator3D)
		{
			T40_subtractionOperator3D();
		}

		TEST_METHOD(TestMethod41multiply2Vector3sOperator3D)
		{
			T41_multiply2Vector3sOperator3D();
		}

		TEST_METHOD(TestMethod42multiplyVector3ByDouble3D)
		{
			T42_multiplyVector3ByDouble3D();
		}

		TEST_METHOD(TestMethod43equivalenceOperators3D)
		{
			T43_equivalenceOperators3D();
		}

		TEST_METHOD(TestMethod44dotProduct3D)
		{
			T44_dotProduct3D();
		}

		TEST_METHOD(TestMethod45magnitude3D)
		{
			T45_magnitude3D();
		}

		TEST_METHOD(TestMethod46magnitudeSquared3D)
		{
			T46_magnitudeSquared3D();
		}

		TEST_METHOD(TestMethod47divide2Vector3sOperator3D)
		{
			T47_divide2Vector3sOperator3D();
		}

		TEST_METHOD(TestMethod48divideVector3ByDoubleOperator3D)
		{
			T48_divideVector3ByDoubleOperator3D();
		}

		TEST_METHOD(TestMethod49additionShorthandOperator3D)
		{
			T49_additionShorthandOperator3D();
		}

		TEST_METHOD(TestMethod50subtractionShorthandOperator3D)
		{
			T50_subtractionShorthandOperator3D();
		}

		TEST_METHOD(TestMethod51multiply2Vector3sShorthandOperator3D)
		{
			T51_multiply2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(TestMethod52multiplyVector3ByDoubleShorthandOperator3D)
		{
			T52_multiplyVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(TestMethod53divide2Vector3sShorthandOperator3D)
		{
			T53_divide2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(TestMethod54divideVector3ByDoubleShorthandOperator3D)
		{
			T54_divideVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(TestMethod55distance3D)
		{
			T55_distance3D();
		}

		TEST_METHOD(TestMethod56distanceSquared3D)
		{
			T56_distanceSquared3D();
		}

		TEST_METHOD(TestMethod57normalize3D)
		{
			T57_normalize3D();
		}

		TEST_METHOD(TestMethod58normalized3D)
		{
			T58_normalized3D();
		}

		TEST_METHOD(TestMethod59project3D)
		{
			T59_project3D();
		}

		TEST_METHOD(TestMethod60outputOperator3D)
		{
			T60_outputOperator3D();
		}

		TEST_METHOD(TestMethod61perpendicular3D)
		{
			T61_perpendicular3D();
		}

		TEST_METHOD(TestMethod62angle3D)
		{
			T62_angle3D();
		}

		TEST_METHOD(TestMethod63reflect3D)
		{
			T63_reflect3D();
		}

		TEST_METHOD(TestMethod64crossProduct3D)
		{
			T64_crossProduct3D();
		}


	};
}

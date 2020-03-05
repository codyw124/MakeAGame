#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestPhysicsEngine
{
	TEST_CLASS(TestPhysicsEngine)
	{
	public:
		
		TEST_METHOD(T01_constructor2D)
		{
			T01_constructor2D();
		}

		TEST_METHOD(T02_constructorWithValues2D)
		{
			T02_constructorWithValues2D();
		}

		TEST_METHOD(T03_copyConstructor2D)
		{
			T03_copyConstructor2D();
		}

		TEST_METHOD(T04_moveConstructor2D)
		{
			T04_moveConstructor2D();
		}

		TEST_METHOD(T05_assignmentOperator2D)
		{
			T05_assignmentOperator2D();
		}

		TEST_METHOD(T06_moveAssignmentOperator2D)
		{
			T06_moveAssignmentOperator2D();
		}

		TEST_METHOD(T07_additionOperator2D)
		{
			T07_additionOperator2D();
		}

		TEST_METHOD(T08_subtractionOperator2D)
		{
			T08_subtractionOperator2D();
		}

		TEST_METHOD(T09_multiplyOperator2D)
		{
			T09_multiplyOperator2D();
		}

		TEST_METHOD(T10_multiplyByDoubleOperator2D)
		{
			T10_multiplyByDoubleOperator2D();
		}

		TEST_METHOD(T11_equivalenceOperators2D)
		{
			T11_equivalenceOperators2D();
		}

		TEST_METHOD(T12_dotProduct2D)
		{
			T12_dotProduct2D();
		}

		TEST_METHOD(T13_magnitude2D)
		{
			T13_magnitude2D();
		}

		TEST_METHOD(T14_magnitudeSquared2D)
		{
			T14_magnitudeSquared2D();
		}

		TEST_METHOD(T15_divideOperator2D)
		{
			T15_divideOperator2D();
		}

		TEST_METHOD(T16_divideByDoubleOperator2D)
		{
			T16_divideByDoubleOperator2D();
		}

		TEST_METHOD(T17_additionShorthandOperator2D)
		{
			T17_additionShorthandOperator2D();
		}

		TEST_METHOD(T18_subtractionShorthandOperator2D)
		{
			T18_subtractionShorthandOperator2D();
		}

		TEST_METHOD(T19_multiplyShorthandOperator2D)
		{
			T19_multiplyShorthandOperator2D();
		}

		TEST_METHOD(T20_multiplyByDoubleShorthandOperator2D)
		{
			T20_multiplyByDoubleShorthandOperator2D();
		}

		TEST_METHOD(T21_divideShorthandOperator2D)
		{
			T21_divideShorthandOperator2D();
		}

		TEST_METHOD(T22_divideByDoubleShorthandOperator2D)
		{
			T22_divideByDoubleShorthandOperator2D();
		}

		TEST_METHOD(T23_distance2D)
		{
			T23_distance2D();
		}

		TEST_METHOD(T24_distanceSquared2D)
		{
			T24_distanceSquared2D();
		}

		TEST_METHOD(T25_normalize2D)
		{
			T25_normalize2D();
		}

		TEST_METHOD(T26_normalized2D)
		{
			T26_normalized2D();
		}

		TEST_METHOD(T27_project2D)
		{
			T27_project2D();
		}

		TEST_METHOD(T28_outputOperator2D)
		{
			T28_outputOperator2D();
		}

		TEST_METHOD(T29_perpendicular2D)
		{
			T29_perpendicular2D();
		}

		TEST_METHOD(T30_rotate2D)
		{
			T30_rotate2D();
		}

		TEST_METHOD(T31_angle2D)
		{
			T31_angle2D();
		}

		TEST_METHOD(T32_reflect2D)
		{
			T32_reflect2D();
		}

		TEST_METHOD(T33_constructor3D)
		{
			T33_constructor3D();
		}

		TEST_METHOD(T34_constructorWithValues3D)
		{
			T34_constructorWithValues3D();
		}

		TEST_METHOD(T35_copyConstructor3D)
		{
			T35_copyConstructor3D();
		}

		TEST_METHOD(T36_moveConstructor3D)
		{
			T36_moveConstructor3D();
		}

		TEST_METHOD(T37_assignmentOperator3D)
		{
			T37_assignmentOperator3D();
		}

		TEST_METHOD(T38_moveAssignmentOperator3D)
		{
			T38_moveAssignmentOperator3D();
		}

		TEST_METHOD(T39_additionOperator3D)
		{
			T39_additionOperator3D();
		}

		TEST_METHOD(T40_subtractionOperator3D)
		{
			T40_subtractionOperator3D();
		}

		TEST_METHOD(T41_multiply2Vector3sOperator3D)
		{
			T41_multiply2Vector3sOperator3D();
		}

		TEST_METHOD(T42_multiplyVector3ByDouble3D)
		{
			T42_multiplyVector3ByDouble3D();
		}

		TEST_METHOD(T43_equivalenceOperators3D)
		{
			T43_equivalenceOperators3D();
		}

		TEST_METHOD(T44_dotProduct3D)
		{
			T44_dotProduct3D();
		}

		TEST_METHOD(T45_magnitude3D)
		{
			T45_magnitude3D();
		}

		TEST_METHOD(T46_magnitudeSquared3D)
		{
			T46_magnitudeSquared3D();
		}

		TEST_METHOD(T47_divide2Vector3sOperator3D)
		{
			T47_divide2Vector3sOperator3D();
		}

		TEST_METHOD(T48_divideVector3ByDoubleOperator3D)
		{
			T48_divideVector3ByDoubleOperator3D();
		}

		TEST_METHOD(T49_additionShorthandOperator3D)
		{
			T49_additionShorthandOperator3D();
		}

		TEST_METHOD(T50_subtractionShorthandOperator3D)
		{
			T50_subtractionShorthandOperator3D();
		}

		TEST_METHOD(T51_multiply2Vector3sShorthandOperator3D)
		{
			T51_multiply2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(T52_multiplyVector3ByDoubleShorthandOperator3D)
		{
			T52_multiplyVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(T53_divide2Vector3sShorthandOperator3D)
		{
			T53_divide2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(T54_divideVector3ByDoubleShorthandOperator3D)
		{
			T54_divideVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(T55_distance3D)
		{
			T55_distance3D();
		}

		TEST_METHOD(T56_distanceSquared3D)
		{
			T56_distanceSquared3D();
		}

		TEST_METHOD(T57_normalize3D)
		{
			T57_normalize3D();
		}

		TEST_METHOD(T58_normalized3D)
		{
			T58_normalized3D();
		}

		TEST_METHOD(T59_project3D)
		{
			T59_project3D();
		}

		TEST_METHOD(T60_outputOperator3D)
		{
			T60_outputOperator3D();
		}

		TEST_METHOD(T61_perpendicular3D)
		{
			T61_perpendicular3D();
		}

		TEST_METHOD(T62_angle3D)
		{
			T62_angle3D();
		}

		TEST_METHOD(T63_reflect3D)
		{
			T63_reflect3D();
		}

		TEST_METHOD(T64_crossProduct3D)
		{
			T64_crossProduct3D();
		}


	};
}

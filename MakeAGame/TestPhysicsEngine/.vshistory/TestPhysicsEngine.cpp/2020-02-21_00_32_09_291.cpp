#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestPhysicsEngine
{
	TEST_CLASS(TestPhysicsEngine)
	{
	public:
		
		TEST_METHOD(TestMethod01-T01_constructor2D)
		{
			T01_constructor2D();
		}

		TEST_METHOD(TestMethod02-T02_constructorWithValues2D)
		{
			T02_constructorWithValues2D();
		}

		TEST_METHOD(TestMethod03-T03_copyConstructor2D)
		{
			T03_copyConstructor2D();
		}

		TEST_METHOD(TestMethod04-T04_moveConstructor2D)
		{
			T04_moveConstructor2D();
		}

		TEST_METHOD(TestMethod05-T05_assignmentOperator2D)
		{
			T05_assignmentOperator2D();
		}

		TEST_METHOD(TestMethod06-T06_moveAssignmentOperator2D)
		{
			T06_moveAssignmentOperator2D();
		}

		TEST_METHOD(TestMethod07-T07_additionOperator2D)
		{
			T07_additionOperator2D();
		}

		TEST_METHOD(TestMethod08-T08_subtractionOperator2D)
		{
			T08_subtractionOperator2D();
		}

		TEST_METHOD(TestMethod09-T09_multiplyOperator2D)
		{
			T09_multiplyOperator2D();
		}

		TEST_METHOD(TestMethod10-T10_multiplyByDoubleOperator2D)
		{
			T10_multiplyByDoubleOperator2D();
		}

		TEST_METHOD(TestMethod11-T11_equivalenceOperators2D)
		{
			T11_equivalenceOperators2D();
		}

		TEST_METHOD(TestMethod12-T12_dotProduct2D)
		{
			T12_dotProduct2D();
		}

		TEST_METHOD(TestMethod13-T13_magnitude2D)
		{
			T13_magnitude2D();
		}

		TEST_METHOD(TestMethod14-T14_magnitudeSquared2D)
		{
			T14_magnitudeSquared2D();
		}

		TEST_METHOD(TestMethod15-T15_divideOperator2D)
		{
			T15_divideOperator2D();
		}

		TEST_METHOD(TestMethod16-T16_divideByDoubleOperator2D)
		{
			T16_divideByDoubleOperator2D();
		}

		TEST_METHOD(TestMethod17-T17_additionShorthandOperator2D)
		{
			T17_additionShorthandOperator2D();
		}

		TEST_METHOD(TestMethod18-T18_subtractionShorthandOperator2D)
		{
			T18_subtractionShorthandOperator2D();
		}

		TEST_METHOD(TestMethod19-T19_multiplyShorthandOperator2D)
		{
			T19_multiplyShorthandOperator2D();
		}

		TEST_METHOD(TestMethod20-T20_multiplyByDoubleShorthandOperator2D)
		{
			T20_multiplyByDoubleShorthandOperator2D();
		}

		TEST_METHOD(TestMethod21-T21_divideShorthandOperator2D)
		{
			T21_divideShorthandOperator2D();
		}

		TEST_METHOD(TestMethod22-T22_divideByDoubleShorthandOperator2D)
		{
			T22_divideByDoubleShorthandOperator2D();
		}

		TEST_METHOD(TestMethod23-T23_distance2D)
		{
			T23_distance2D();
		}

		TEST_METHOD(TestMethod24-T24_distanceSquared2D)
		{
			T24_distanceSquared2D();
		}

		TEST_METHOD(TestMethod25-T25_normalize2D)
		{
			T25_normalize2D();
		}

		TEST_METHOD(TestMethod26-T26_normalized2D)
		{
			T26_normalized2D();
		}

		TEST_METHOD(TestMethod27-T27_project2D)
		{
			T27_project2D();
		}

		TEST_METHOD(TestMethod28-T28_outputOperator2D)
		{
			T28_outputOperator2D();
		}

		TEST_METHOD(TestMethod29-T29_perpendicular2D)
		{
			T29_perpendicular2D();
		}

		TEST_METHOD(TestMethod30-T30_rotate2D)
		{
			T30_rotate2D();
		}

		TEST_METHOD(TestMethod31-T31_angle2D)
		{
			T31_angle2D();
		}

		TEST_METHOD(TestMethod32-T32_reflect2D)
		{
			T32_reflect2D();
		}

		TEST_METHOD(TestMethod33-T33_constructor3D)
		{
			T33_constructor3D();
		}

		TEST_METHOD(TestMethod34-T34_constructorWithValues3D)
		{
			T34_constructorWithValues3D();
		}

		TEST_METHOD(TestMethod35-T35_copyConstructor3D)
		{
			T35_copyConstructor3D();
		}

		TEST_METHOD(TestMethod36-T36_moveConstructor3D)
		{
			T36_moveConstructor3D();
		}

		TEST_METHOD(TestMethod37-T37_assignmentOperator3D)
		{
			T37_assignmentOperator3D();
		}

		TEST_METHOD(TestMethod38-T38_moveAssignmentOperator3D)
		{
			T38_moveAssignmentOperator3D();
		}

		TEST_METHOD(TestMethod39-T39_additionOperator3D)
		{
			T39_additionOperator3D();
		}

		TEST_METHOD(TestMethod40-T40_subtractionOperator3D)
		{
			T40_subtractionOperator3D();
		}

		TEST_METHOD(TestMethod41-T41_multiply2Vector3sOperator3D)
		{
			T41_multiply2Vector3sOperator3D();
		}

		TEST_METHOD(TestMethod42-T42_multiplyVector3ByDouble3D)
		{
			T42_multiplyVector3ByDouble3D();
		}

		TEST_METHOD(TestMethod43-T43_equivalenceOperators3D)
		{
			T43_equivalenceOperators3D();
		}

		TEST_METHOD(TestMethod44-T44_dotProduct3D)
		{
			T44_dotProduct3D();
		}

		TEST_METHOD(TestMethod45-T45_magnitude3D)
		{
			T45_magnitude3D();
		}

		TEST_METHOD(TestMethod46-T46_magnitudeSquared3D)
		{
			T46_magnitudeSquared3D();
		}

		TEST_METHOD(TestMethod47-T47_divide2Vector3sOperator3D)
		{
			T47_divide2Vector3sOperator3D();
		}

		TEST_METHOD(TestMethod48-T48_divideVector3ByDoubleOperator3D)
		{
			T48_divideVector3ByDoubleOperator3D();
		}

		TEST_METHOD(TestMethod49-T49_additionShorthandOperator3D)
		{
			T49_additionShorthandOperator3D();
		}

		TEST_METHOD(TestMethod50-T50_subtractionShorthandOperator3D)
		{
			T50_subtractionShorthandOperator3D();
		}

		TEST_METHOD(TestMethod51-T51_multiply2Vector3sShorthandOperator3D)
		{
			T51_multiply2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(TestMethod52-T52_multiplyVector3ByDoubleShorthandOperator3D)
		{
			T52_multiplyVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(TestMethod53-T53_divide2Vector3sShorthandOperator3D)
		{
			T53_divide2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(TestMethod54-T54_divideVector3ByDoubleShorthandOperator3D)
		{
			T54_divideVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(TestMethod55-T55_distance3D)
		{
			T55_distance3D();
		}

		TEST_METHOD(TestMethod56-T56_distanceSquared3D)
		{
			T56_distanceSquared3D();
		}

		TEST_METHOD(TestMethod57-T57_normalize3D)
		{
			T57_normalize3D();
		}

		TEST_METHOD(TestMethod58-T58_normalized3D)
		{
			T58_normalized3D();
		}

		TEST_METHOD(TestMethod59-T59_project3D)
		{
			T59_project3D();
		}

		TEST_METHOD(TestMethod60-T60_outputOperator3D)
		{
			T60_outputOperator3D();
		}

		TEST_METHOD(TestMethod61-T61_perpendicular3D)
		{
			T61_perpendicular3D();
		}

		TEST_METHOD(TestMethod62-T62_angle3D)
		{
			T62_angle3D();
		}

		TEST_METHOD(TestMethod63-T63_reflect3D)
		{
			T63_reflect3D();
		}

		TEST_METHOD(TestMethod64-T64_crossProduct3D)
		{
			T64_crossProduct3D();
		}


	};
}

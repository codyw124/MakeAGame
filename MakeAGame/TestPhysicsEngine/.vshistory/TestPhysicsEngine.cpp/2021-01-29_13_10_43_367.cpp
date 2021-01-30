//cody ware
//2/21/2020

#include "CppUnitTest.h"
#include "PointTests.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PhysicsEngineTester
{
	TEST_CLASS(TestPointClass)
	{
	public:
		TEST_METHOD(constructor)
		{
			PointTests test;
			test.constructor2D();
		}

		TEST_METHOD(constructorWithValues)
		{
			PointTests test;
			test.constructorWithValues2D();
		}

		TEST_METHOD(copyConstructor)
		{
			PointTests test;
			test.copyConstructor2D();
		}

		TEST_METHOD(moveConstructor)
		{
			PointTests test;
			test.moveConstructor2D();
		}

		TEST_METHOD(assignmentOperator)
		{
			PointTests test;
			test.assignmentOperator2D();
		}

		TEST_METHOD(moveAssignmentOperator)
		{
			PointTests test;
			test.moveAssignmentOperator2D();
		}

		TEST_METHOD(additionOperator)
		{
			PointTests test;
			test.additionOperator2D();
		}

		TEST_METHOD(subtractionOperator)
		{
			PointTests test;
			test.subtractionOperator2D();
		}

		TEST_METHOD(multiplyOperator)
		{
			PointTests test;
			test.multiplyOperator2D();
		}

		TEST_METHOD(multiplyByDoubleOperator)
		{
			PointTests test;
			test.multiplyByDoubleOperator2D();
		}

		TEST_METHOD(equivalenceOperators)
		{
			PointTests test;
			test.equivalenceOperators2D();
		}

		TEST_METHOD(dotProduct)
		{
			PointTests test;
			test.dotProduct2D();
		}

		TEST_METHOD(magnitude)
		{
			PointTests test;
			test.magnitude2D();
		}

		TEST_METHOD(magnitudeSquared)
		{
			PointTests test;
			test.magnitudeSquared2D();
		}

		TEST_METHOD(divideOperator)
		{
			PointTests test;
			test.divideOperator2D();
		}

		TEST_METHOD(divideByDoubleOperator)
		{
			PointTests test;
			test.divideByDoubleOperator2D();
		}

		TEST_METHOD(additionShorthandOperator)
		{
			PointTests test;
			test.additionShorthandOperator2D();
		}

		TEST_METHOD(subtractionShorthandOperator)
		{
			PointTests test;
			test.subtractionShorthandOperator2D();
		}

		TEST_METHOD(multiplyShorthandOperator)
		{
			PointTests test;
			test.multiplyShorthandOperator2D();
		}

		TEST_METHOD(multiplyByDoubleShorthandOperator)
		{
			PointTests test;
			test.multiplyByDoubleShorthandOperator2D();
		}

		TEST_METHOD(divideShorthandOperator)
		{
			PointTests test;
			test.divideShorthandOperator2D();
		}

		TEST_METHOD(divideByDoubleShorthandOperator)
		{
			PointTests test;
			test.divideByDoubleShorthandOperator2D();
		}

		TEST_METHOD(distance)
		{
			PointTests test;
			test.distance2D();
		}

		TEST_METHOD(distanceSquared)
		{
			PointTests test;
			test.distanceSquared2D();
		}

		TEST_METHOD(normalize)
		{
			PointTests test;
			test.normalize2D();
		}

		TEST_METHOD(normalized)
		{
			PointTests test;
			test.normalized2D();
		}

		TEST_METHOD(project)
		{
			PointTests test;
			test.project2D();
		}

		TEST_METHOD(outputOperator)
		{
			PointTests test;
			test.outputOperator2D();
		}

		TEST_METHOD(perpendicular)
		{
			PointTests test;
			test.perpendicular2D();
		}

		TEST_METHOD(rotate)
		{
			PointTests test;
			test.rotate2D();
		}

		TEST_METHOD(angle)
		{
			PointTests test;
			test.angle2D();
		}

		TEST_METHOD(reflect)
		{
			PointTests test;
			test.reflect2D();
		}

		TEST_METHOD(constructor3D)
		{
			PointTests test;
			test.constructor3D();
		}

		TEST_METHOD(constructorWithValues3D)
		{
			PointTests test;
			test.constructorWithValues3D();
		}

		TEST_METHOD(copyConstructor3D)
		{
			PointTests test;
			test.copyConstructor3D();
		}

		TEST_METHOD(moveConstructor3D)
		{
			PointTests test;
			test.moveConstructor3D();
		}

		TEST_METHOD(assignmentOperator3D)
		{
			PointTests test;
			test.assignmentOperator3D();
		}

		TEST_METHOD(moveAssignmentOperator3D)
		{
			PointTests test;
			test.moveAssignmentOperator3D();
		}

		TEST_METHOD(additionOperator3D)
		{
			PointTests test;
			test.additionOperator3D();
		}

		TEST_METHOD(subtractionOperator3D)
		{
			PointTests test;
			test.subtractionOperator3D();
		}

		TEST_METHOD(multiply2Vector3sOperator3D)
		{
			PointTests test;
			//test.multiply2Vector3sOperator3D();
			Assert::Fail();
			
		}

		TEST_METHOD(multiplyVector3ByDouble3D)
		{
			PointTests test;
			//test.multiplyVector3ByDouble3D();
			Assert::Fail();
		}

		TEST_METHOD(equivalenceOperators3D)
		{
			PointTests test;
			test.equivalenceOperators3D();
		}

		TEST_METHOD(dotProduct3D)
		{
			PointTests test;
			test.dotProduct3D();
		}

		TEST_METHOD(magnitude3D)
		{
			PointTests test;
			test.magnitude3D();
		}

		TEST_METHOD(magnitudeSquared3D)
		{
			PointTests test;
			test.magnitudeSquared3D();
		}

		TEST_METHOD(divide2Vector3sOperator3D)
		{
			PointTests test;
			//test.divide2Vector3sOperator3D();
			Assert::Fail();
		}

		TEST_METHOD(divideVector3ByDoubleOperator3D)
		{
			PointTests test;
			//test.divideVector3ByDoubleOperator3D();
			Assert::Fail();
		}

		TEST_METHOD(additionShorthandOperator3D)
		{
			PointTests test;
			test.additionShorthandOperator3D();
		}

		TEST_METHOD(subtractionShorthandOperator3D)
		{
			PointTests test;
			test.subtractionShorthandOperator3D();
		}

		TEST_METHOD(multiply2Vector3sShorthandOperator3D)
		{
			PointTests test;
			//test.multiply2Vector3sShorthandOperator3D();
			Assert::Fail();
		}

		TEST_METHOD(multiplyVector3ByDoubleShorthandOperator3D)
		{
			PointTests test;
			//test.multiplyVector3ByDoubleShorthandOperator3D();
			Assert::Fail();
		}

		TEST_METHOD(divide2Vector3sShorthandOperator3D)
		{
			PointTests test;
			//test.divide2Vector3sShorthandOperator3D();
			Assert::Fail();
		}

		TEST_METHOD(divideVector3ByDoubleShorthandOperator3D)
		{
			PointTests test;
			//test.divideVector3ByDoubleShorthandOperator3D();
			Assert::Fail();
		}

		TEST_METHOD(distance3D)
		{
			PointTests test;
			test.distance3D();
		}

		TEST_METHOD(distanceSquared3D)
		{
			PointTests test;
			test.distanceSquared3D();
		}

		TEST_METHOD(normalize3D)
		{
			PointTests test;
			test.normalize3D();
		}

		TEST_METHOD(normalized3D)
		{
			PointTests test;
			test.normalized3D();
		}

		TEST_METHOD(project3D)
		{
			PointTests test;
			test.project3D();
		}

		TEST_METHOD(outputOperator3D)
		{
			PointTests test;
			test.outputOperator3D();
		}

		TEST_METHOD(perpendicular3D)
		{
			PointTests test;
			test.perpendicular3D();
		}

		TEST_METHOD(angle3D)
		{
			PointTests test;
			test.angle3D();
		}

		TEST_METHOD(reflect3D)
		{
			PointTests test;
			test.reflect3D();
		}

		TEST_METHOD(crossProduct3D)
		{
			PointTests test;
			test.crossProduct3D();
		}
	};


}
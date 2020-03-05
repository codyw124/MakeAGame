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
			test.constructor2D();
		}

		TEST_METHOD(constructorWithValues2D)
		{
			PhysicsVectorTests test;
			test.constructorWithValues2D();
		}

		TEST_METHOD(copyConstructor2D)
		{
			PhysicsVectorTests test;
			test.copyConstructor2D();
		}

		TEST_METHOD(moveConstructor2D)
		{
			PhysicsVectorTests test;
			test.moveConstructor2D();
		}

		TEST_METHOD(assignmentOperator2D)
		{
			PhysicsVectorTests test;
			test.assignmentOperator2D();
		}

		TEST_METHOD(moveAssignmentOperator2D)
		{
			PhysicsVectorTests test;
			test.moveAssignmentOperator2D();
		}

		TEST_METHOD(additionOperator2D)
		{
			PhysicsVectorTests test;
			test.additionOperator2D();
		}

		TEST_METHOD(subtractionOperator2D)
		{
			PhysicsVectorTests test;
			test.subtractionOperator2D();
		}

		TEST_METHOD(multiplyOperator2D)
		{
			PhysicsVectorTests test;
			test.multiplyOperator2D();
		}

		TEST_METHOD(multiplyByDoubleOperator2D)
		{
			PhysicsVectorTests test;
			test.multiplyByDoubleOperator2D();
		}

		TEST_METHOD(equivalenceOperators2D)
		{
			PhysicsVectorTests test;
			test.equivalenceOperators2D();
		}

		TEST_METHOD(dotProduct2D)
		{
			PhysicsVectorTests test;
			test.dotProduct2D();
		}

		TEST_METHOD(magnitude2D)
		{
			PhysicsVectorTests test;
			test.magnitude2D();
		}

		TEST_METHOD(magnitudeSquared2D)
		{
			PhysicsVectorTests test;
			test.magnitudeSquared2D();
		}

		TEST_METHOD(divideOperator2D)
		{
			PhysicsVectorTests test;
			test.divideOperator2D();
		}

		TEST_METHOD(divideByDoubleOperator2D)
		{
			PhysicsVectorTests test;
			test.divideByDoubleOperator2D();
		}

		TEST_METHOD(additionShorthandOperator2D)
		{
			PhysicsVectorTests test;
			test.additionShorthandOperator2D();
		}

		TEST_METHOD(subtractionShorthandOperator2D)
		{
			PhysicsVectorTests test;
			test.subtractionShorthandOperator2D();
		}

		TEST_METHOD(multiplyShorthandOperator2D)
		{
			PhysicsVectorTests test;
			test.multiplyShorthandOperator2D();
		}

		TEST_METHOD(multiplyByDoubleShorthandOperator2D)
		{
			PhysicsVectorTests test;
			test.multiplyByDoubleShorthandOperator2D();
		}

		TEST_METHOD(divideShorthandOperator2D)
		{
			PhysicsVectorTests test;
			test.divideShorthandOperator2D();
		}

		TEST_METHOD(divideByDoubleShorthandOperator2D)
		{
			PhysicsVectorTests test;
			test.divideByDoubleShorthandOperator2D();
		}

		TEST_METHOD(distance2D)
		{
			PhysicsVectorTests test;
			test.distance2D();
		}

		TEST_METHOD(distanceSquared2D)
		{
			PhysicsVectorTests test;
			test.distanceSquared2D();
		}

		TEST_METHOD(normalize2D)
		{
			PhysicsVectorTests test;
			test.normalize2D();
		}

		TEST_METHOD(normalized2D)
		{
			PhysicsVectorTests test;
			test.normalized2D();
		}

		TEST_METHOD(project2D)
		{
			PhysicsVectorTests test;
			test.project2D();
		}

		TEST_METHOD(outputOperator2D)
		{
			PhysicsVectorTests test;
			test.outputOperator2D();
		}

		TEST_METHOD(perpendicular2D)
		{
			PhysicsVectorTests test;
			test.perpendicular2D();
		}

		TEST_METHOD(rotate2D)
		{
			PhysicsVectorTests test;
			test.rotate2D();
		}

		TEST_METHOD(angle2D)
		{
			PhysicsVectorTests test;
			test.angle2D();
		}

		TEST_METHOD(reflect2D)
		{
			PhysicsVectorTests test;
			test.reflect2D();
		}

		TEST_METHOD(constructor3D)
		{
			PhysicsVectorTests test;
			test.constructor3D();
		}

		TEST_METHOD(constructorWithValues3D)
		{
			PhysicsVectorTests test;
			test.constructorWithValues3D();
		}

		TEST_METHOD(copyConstructor3D)
		{
			PhysicsVectorTests test;
			test.copyConstructor3D();
		}

		TEST_METHOD(moveConstructor3D)
		{
			PhysicsVectorTests test;
			test.moveConstructor3D();
		}

		TEST_METHOD(assignmentOperator3D)
		{
			PhysicsVectorTests test;
			test.assignmentOperator3D();
		}

		TEST_METHOD(moveAssignmentOperator3D)
		{
			PhysicsVectorTests test;
			test.moveAssignmentOperator3D();
		}

		TEST_METHOD(additionOperator3D)
		{
			PhysicsVectorTests test;
			test.additionOperator3D();
		}

		TEST_METHOD(subtractionOperator3D)
		{
			PhysicsVectorTests test;
			test.subtractionOperator3D();
		}

		TEST_METHOD(multiply2Vector3sOperator3D)
		{
			PhysicsVectorTests test;
			test.multiply2Vector3sOperator3D();
		}

		TEST_METHOD(multiplyVector3ByDouble3D)
		{
			PhysicsVectorTests test;
			test.multiplyVector3ByDouble3D();
		}

		TEST_METHOD(equivalenceOperators3D)
		{
			PhysicsVectorTests test;
			test.equivalenceOperators3D();
		}

		TEST_METHOD(dotProduct3D)
		{
			PhysicsVectorTests test;
			test.dotProduct3D();
		}

		TEST_METHOD(magnitude3D)
		{
			PhysicsVectorTests test;
			test.magnitude3D();
		}

		TEST_METHOD(magnitudeSquared3D)
		{
			PhysicsVectorTests test;
			test.magnitudeSquared3D();
		}

		TEST_METHOD(divide2Vector3sOperator3D)
		{
			PhysicsVectorTests test;
			test.divide2Vector3sOperator3D();
		}

		TEST_METHOD(divideVector3ByDoubleOperator3D)
		{
			PhysicsVectorTests test;
			test.divideVector3ByDoubleOperator3D();
		}

		TEST_METHOD(additionShorthandOperator3D)
		{
			PhysicsVectorTests test;
			test.additionShorthandOperator3D();
		}

		TEST_METHOD(subtractionShorthandOperator3D)
		{
			PhysicsVectorTests test;
			test.subtractionShorthandOperator3D();
		}

		TEST_METHOD(multiply2Vector3sShorthandOperator3D)
		{
			PhysicsVectorTests test;
			test.multiply2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(multiplyVector3ByDoubleShorthandOperator3D)
		{
			PhysicsVectorTests test;
			test.multiplyVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(divide2Vector3sShorthandOperator3D)
		{
			PhysicsVectorTests test;
			test.divide2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(divideVector3ByDoubleShorthandOperator3D)
		{
			PhysicsVectorTests test;
			test.divideVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(distance3D)
		{
			PhysicsVectorTests test;
			test.distance3D();
		}

		TEST_METHOD(distanceSquared3D)
		{
			PhysicsVectorTests test;
			test.distanceSquared3D();
		}

		TEST_METHOD(normalize3D)
		{
			PhysicsVectorTests test;
			test.normalize3D();
		}

		TEST_METHOD(normalized3D)
		{
			PhysicsVectorTests test;
			test.normalized3D();
		}

		TEST_METHOD(project3D)
		{
			PhysicsVectorTests test;
			test.project3D();
		}

		TEST_METHOD(outputOperator3D)
		{
			PhysicsVectorTests test;
			test.outputOperator3D();
		}

		TEST_METHOD(perpendicular3D)
		{
			PhysicsVectorTests test;
			test.perpendicular3D();
		}

		TEST_METHOD(angle3D)
		{
			PhysicsVectorTests test;
			test.angle3D();
		}

		TEST_METHOD(reflect3D)
		{
			PhysicsVectorTests test;
			test.reflect3D();
		}

		TEST_METHOD(crossProduct3D)
		{
			PhysicsVectorTests test;
			test.crossProduct3D();
		}
	};

	TEST_CLASS(TestPointClass)
	{
	public:
		TEST_METHOD(constructor2D)
		{
			PointTests test;
			test.constructor2D();
		}

		TEST_METHOD(constructorWithValues2D)
		{
			PointTests test;
			test.constructorWithValues2D();
		}

		TEST_METHOD(copyConstructor2D)
		{
			PointTests test;
			test.copyConstructor2D();
		}

		TEST_METHOD(moveConstructor2D)
		{
			PointTests test;
			test.moveConstructor2D();
		}

		TEST_METHOD(assignmentOperator2D)
		{
			PointTests test;
			test.assignmentOperator2D();
		}

		TEST_METHOD(moveAssignmentOperator2D)
		{
			PointTests test;
			test.moveAssignmentOperator2D();
		}

		TEST_METHOD(additionOperator2D)
		{
			PointTests test;
			test.additionOperator2D();
		}

		TEST_METHOD(subtractionOperator2D)
		{
			PointTests test;
			test.subtractionOperator2D();
		}

		TEST_METHOD(multiplyOperator2D)
		{
			PointTests test;
			test.multiplyOperator2D();
		}

		TEST_METHOD(multiplyByDoubleOperator2D)
		{
			PointTests test;
			test.multiplyByDoubleOperator2D();
		}

		TEST_METHOD(equivalenceOperators2D)
		{
			PointTests test;
			test.equivalenceOperators2D();
		}

		TEST_METHOD(dotProduct2D)
		{
			PointTests test;
			test.dotProduct2D();
		}

		TEST_METHOD(magnitude2D)
		{
			PointTests test;
			test.magnitude2D();
		}

		TEST_METHOD(magnitudeSquared2D)
		{
			PointTests test;
			test.magnitudeSquared2D();
		}

		TEST_METHOD(divideOperator2D)
		{
			PointTests test;
			test.divideOperator2D();
		}

		TEST_METHOD(divideByDoubleOperator2D)
		{
			PointTests test;
			test.divideByDoubleOperator2D();
		}

		TEST_METHOD(additionShorthandOperator2D)
		{
			PointTests test;
			test.additionShorthandOperator2D();
		}

		TEST_METHOD(subtractionShorthandOperator2D)
		{
			PointTests test;
			test.subtractionShorthandOperator2D();
		}

		TEST_METHOD(multiplyShorthandOperator2D)
		{
			PointTests test;
			test.multiplyShorthandOperator2D();
		}

		TEST_METHOD(multiplyByDoubleShorthandOperator2D)
		{
			PointTests test;
			test.multiplyByDoubleShorthandOperator2D();
		}

		TEST_METHOD(divideShorthandOperator2D)
		{
			PointTests test;
			test.divideShorthandOperator2D();
		}

		TEST_METHOD(divideByDoubleShorthandOperator2D)
		{
			PointTests test;
			test.divideByDoubleShorthandOperator2D();
		}

		TEST_METHOD(distance2D)
		{
			PointTests test;
			test.distance2D();
		}

		TEST_METHOD(distanceSquared2D)
		{
			PointTests test;
			test.distanceSquared2D();
		}

		TEST_METHOD(normalize2D)
		{
			PointTests test;
			test.normalize2D();
		}

		TEST_METHOD(normalized2D)
		{
			PointTests test;
			test.normalized2D();
		}

		TEST_METHOD(project2D)
		{
			PointTests test;
			test.project2D();
		}

		TEST_METHOD(outputOperator2D)
		{
			PointTests test;
			test.outputOperator2D();
		}

		TEST_METHOD(perpendicular2D)
		{
			PointTests test;
			test.perpendicular2D();
		}

		TEST_METHOD(rotate2D)
		{
			PointTests test;
			test.rotate2D();
		}

		TEST_METHOD(angle2D)
		{
			PointTests test;
			test.angle2D();
		}

		TEST_METHOD(reflect2D)
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
			test.multiply2Vector3sOperator3D();
		}

		TEST_METHOD(multiplyVector3ByDouble3D)
		{
			PointTests test;
			test.multiplyVector3ByDouble3D();
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
			test.divide2Vector3sOperator3D();
		}

		TEST_METHOD(divideVector3ByDoubleOperator3D)
		{
			PointTests test;
			test.divideVector3ByDoubleOperator3D();
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
			test.multiply2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(multiplyVector3ByDoubleShorthandOperator3D)
		{
			PointTests test;
			test.multiplyVector3ByDoubleShorthandOperator3D();
		}

		TEST_METHOD(divide2Vector3sShorthandOperator3D)
		{
			PointTests test;
			test.divide2Vector3sShorthandOperator3D();
		}

		TEST_METHOD(divideVector3ByDoubleShorthandOperator3D)
		{
			PointTests test;
			test.divideVector3ByDoubleShorthandOperator3D();
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

	TEST_CLASS(TestMatrixClass)
	{
		TEST_METHOD(defaultConstructor)
		{
			MatricesTests test;
			test.defaultConstructor();
		}

		TEST_METHOD(copyConstructor)
		{
			MatricesTests test;
			test.copyConstructor();
		}

		TEST_METHOD(moveConstructor)
		{
			MatricesTests test;
			test.moveConstructor();
		}

		TEST_METHOD(assignmentOperator)
		{
			MatricesTests test;
			test.assignmentOperator();
		}

		TEST_METHOD(moveAssignmentOperator)
		{
			MatricesTests test;
			test.moveAssignmentOperator();
		}

		TEST_METHOD(accessOperator)
		{
			MatricesTests test;
			test.accessOperator();
		}

		TEST_METHOD(transpose)
		{
			MatricesTests test;
			test.transpose();
		}

		TEST_METHOD(transposed)
		{
			MatricesTests test;
			test.transposed();
		}

		TEST_METHOD(multiplicationOperator)
		{
			MatricesTests test;
			test.multiplicationOperator();
		}

		TEST_METHOD(additionOperator)
		{
			MatricesTests test;
			test.additionOperator();
		}

		TEST_METHOD(subtractionOperator)
		{
			MatricesTests test;
			test.subtractionOperator();
		}

		TEST_METHOD(equivalence)
		{
			MatricesTests test;
			test.equivalence();
		}

		TEST_METHOD(outputoperator)
		{
			MatricesTests test;
			test.outputoperator();
		}

		TEST_METHOD(cut)
		{
			MatricesTests test;
			test.cut();
		}

		TEST_METHOD(testDeterminant)
		{
			MatricesTests test;
			test.testDeterminant();
		}

		TEST_METHOD(testMinors)
		{
			MatricesTests test;
			test.testMinors();
		}

		TEST_METHOD(testCofactors)
		{
			MatricesTests test;
			test.testCofactors();
		}

		TEST_METHOD(testAdjugate)
		{
			MatricesTests test;
			test.testAdjugate();
		}

		TEST_METHOD(testInverse)
		{
			MatricesTests test;
			test.testInverse();
		}
	};
}
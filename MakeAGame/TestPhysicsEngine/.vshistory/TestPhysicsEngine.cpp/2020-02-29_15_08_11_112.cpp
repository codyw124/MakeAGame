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
			test.constructor3D();
		}

		TEST_METHOD(constructorWithValues)
		{
			PhysicsVectorTests test;
			test.constructorWithValues2D();
			test.constructorWithValues3D();
		}

		TEST_METHOD(copyConstructor)
		{
			PhysicsVectorTests test;
			test.copyConstructor2D();
			test.copyConstructor3D();
		}

		TEST_METHOD(moveConstructor)
		{
			PhysicsVectorTests test;
			test.moveConstructor2D();
			test.moveConstructor3D();
		}

		TEST_METHOD(assignmentOperator)
		{
			PhysicsVectorTests test;
			test.assignmentOperator2D();
			test.assignmentOperator3D();
		}

		TEST_METHOD(moveAssignmentOperator)
		{
			PhysicsVectorTests test;
			test.moveAssignmentOperator2D();
			test.moveAssignmentOperator3D();
		}

		TEST_METHOD(accessOperator)
		{
			PhysicsVectorTests test;
			test.accessOperator();
		}

		TEST_METHOD(additionOperator)
		{
			PhysicsVectorTests test;
			test.additionOperator2D();
			test.additionOperator3D();
		}

		TEST_METHOD(subtractionOperator)
		{
			PhysicsVectorTests test;
			test.subtractionOperator2D();
			test.subtractionOperator3D();
		}

		TEST_METHOD(multiplyOperator)
		{
			PhysicsVectorTests test;
			test.multiplyOperator2D();
			test.multiplyOperator3D();
		}

		TEST_METHOD(multiplyByDoubleOperator)
		{
			PhysicsVectorTests test;
			test.multiplyByDoubleOperator2D();
			test.multiplyByDoubleOperator3D();
		}

		TEST_METHOD(divideOperator)
		{
			PhysicsVectorTests test;
			test.divideOperator2D();
			test.divideOperator3D();
		}

		TEST_METHOD(divideByDoubleOperator)
		{
			PhysicsVectorTests test;
			test.divideByDoubleOperator2D();
			test.divideByDoubleOperator3D();
		}

		TEST_METHOD(additionShorthandOperator)
		{
			PhysicsVectorTests test;
			test.additionShorthandOperator2D();
			test.additionShorthandOperator3D();
		}

		TEST_METHOD(subtractionShorthandOperator)
		{
			PhysicsVectorTests test;
			test.subtractionShorthandOperator2D();
			test.subtractionShorthandOperator3D();
		}

		TEST_METHOD(multiplyShorthandOperator)
		{
			PhysicsVectorTests test;
			test.multiplyShorthandOperator2D();
			test.multiplyShorthandOperator3D();
		}

		TEST_METHOD(multiplyByDoubleShorthandOperator)
		{
			PhysicsVectorTests test;
			test.multiplyByDoubleShorthandOperator2D();
			test.multiplyByDoubleShorthandOperator3D();
		}

		TEST_METHOD(divideShorthandOperator)
		{
			PhysicsVectorTests test;
			test.divideShorthandOperator2D();
			test.divideShorthandOperator3D();
		}

		TEST_METHOD(divideByDoubleShorthandOperator)
		{
			PhysicsVectorTests test;
			test.divideByDoubleShorthandOperator2D();
			test.divideByDoubleShorthandOperator3D();
		}

		TEST_METHOD(equivalenceOperators)
		{
			PhysicsVectorTests test;
			test.equivalenceOperators2D();
			test.equivalenceOperators3D();
		}

		TEST_METHOD(dotProduct)
		{
			PhysicsVectorTests test;
			test.dotProduct2D();
			test.dotProduct3D();
		}

		TEST_METHOD(magnitude)
		{
			PhysicsVectorTests test;
			test.magnitude2D(); test;
			test.magnitude3D();
		}

		TEST_METHOD(magnitudeSquared)
		{
			PhysicsVectorTests test;
			test.magnitudeSquared2D();
			test.magnitudeSquared3D();
		}
		
		TEST_METHOD(distance)
		{
			PhysicsVectorTests test;
			test.distance2D();
			test.distance3D();
		}

		TEST_METHOD(distanceSquared)
		{
			PhysicsVectorTests test;
			test.distanceSquared2D();
			test.distanceSquared3D();
		}

		/*TEST_METHOD(rotate)
		{
			PhysicsVectorTests test;
			test.rotate2D();
			test.rotate3D();
		}*/

		TEST_METHOD(crossProduct3D)
		{
			PhysicsVectorTests test;
			test.crossProduct3D();
		}

		TEST_METHOD(normalize)
		{
			PhysicsVectorTests test;
			test.normalize2D();
			test.normalize3D();
		}

		TEST_METHOD(normalized)
		{
			PhysicsVectorTests test;
			test.normalized2D();
			test.normalized3D();
		}

		TEST_METHOD(angle)
		{
			PhysicsVectorTests test;
			test.angle2D();
			test.angle3D();
		}

		TEST_METHOD(project)
		{
			PhysicsVectorTests test;
			test.project2D();
			test.project3D();
		}

		TEST_METHOD(perpendicular)
		{
			PhysicsVectorTests test;
			test.perpendicular2D();
			test.perpendicular3D();
		}

		TEST_METHOD(reflect)
		{
			PhysicsVectorTests test;
			test.reflect2D();
			test.reflect3D();
		}

		TEST_METHOD(getAndAddDimensions) {
			
		}

		TEST_METHOD(outputOperator)
		{
			PhysicsVectorTests test;
			test.outputOperator2D();
			test.outputOperator3D();
		}
	};

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
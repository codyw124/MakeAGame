//Cody Ware
//6/30/19

#include "PointTests.h"

void PointTests::constructor2D()
{
	double* values = new double[2];
	values[0] = 0.0;
	values[1] = 0.0;

	Point test(values, 2);

	assert(test[0] == 0.0, "constructor failed");

	assert(test[1] == 0.0, "constructor failed");
}

void PointTests::constructorWithValues2D()
{
	double* values = new double[2];
	values[0] = 5.5;
	values[1] = 7.1;

	Point test(values, 2);

	assert(test[0] == 5.5, "constructorWithValues");

	assert(test[1] == 7.1, "constructorWithValues");
}

void PointTests::copyConstructor2D()
{
	double* values = new double[2];
	values[0] = 5.5;
	values[1] = 7.1;

	Point test(values, 2);

	Point copy(test);

	//make sure they have the right values
	assert(test[0] == 5.5, "copyConstructor");

	assert(test[1] == 7.1, "copyConstructor");

	assert(copy[0] == 5.5, "copyConstructor");

	assert(copy[1] == 7.1, "copyConstructor");

	//make sure each has its own memory
	assert(&test[0] != &copy[0], "copyConstructor");

	assert(&test[1] != &copy[1], "copyConstructor");
}

void PointTests::moveConstructor2D()
{
	double* values = new double[2];
	values[0] = 5.0;
	values[1] = 6.0;

	Point test(values, 2);

	Point moveHere(std::move(test));

	//make sure they have the righ tvalues
	assert(test.getNumberOfDimensions() == 0, "moveConstructor");

	assert(moveHere[0] == 5.0, "moveConstructor");

	assert(moveHere[1] == 6.0, "moveConstructor");
}

void PointTests::assignmentOperator2D()
{
	double* values = new double[2];
	values[0] = 55;
	values[1] = 10;

	Point test(values, 2);

	Point assigned = test;

	//make sure they have the righ tvalues
	assert(test[0] == 55.0, "assignmentOperator");

	assert(test[1] == 10.0, "assignmentOperator");

	assert(assigned[0] == 55.0, "assignmentOperator");

	assert(assigned[1] == 10.0, "assignmentOperator");

	//make sure each has its own memory
	assert(&test[0] != &assigned[0], "assignmentOperator");

	assert(&test[1] != &assigned[1], "assignmentOperator");
}

void PointTests::moveAssignmentOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 6;

	Point test(values, 2);

	Point moveAssignHere = std::move(test);

	//make sure they have the righ tvalues
	assert(test.getNumberOfDimensions() == 0.0, "moveAssignmentOperator");

	assert(moveAssignHere[0] == 5.0, "moveAssignmentOperator");

	assert(moveAssignHere[1] == 6.0, "moveAssignmentOperator");
}

void PointTests::additionOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	Point orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 1;
	values2[1] = 2;

	Point plus(values2, 2);

	Point sum = orig + plus;

	assert(sum[0] == 6.0, "additionOperator 1");

	assert(sum[1] == 12.0, "additionOperator 2");

	assert(&sum[0] != &orig[0], "additionOperator 3");

	assert(&sum[1] != &orig[1], "additionOperator 4");

	assert(&sum[0] != &plus[0], "additionOperator 5");

	assert(&sum[1] != &plus[1], "additionOperator 6");
}

void PointTests::subtractionOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	Point orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 1;
	values2[1] = 2;

	Point minus(values2, 2);

	Point difference = orig - minus;

	assert(difference[0] == 4.0, "subtractionOperator");

	assert(difference[1] == 8.0, "subtractionOperator");

	assert(&difference[0] != &orig[0], "subtractionOperator");

	assert(&difference[1] != &orig[1], "subtractionOperator");

	assert(&difference[0] != &minus[0], "subtractionOperator");

	assert(&difference[1] != &minus[1], "subtractionOperator");
}

void PointTests::multiplyOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	Point orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 2;
	values2[1] = 2;

	Point times(values2, 2);

	Point product = orig * times;

	assert(product[0] == 10.0, "multiplyOperator");

	assert(product[1] == 20.0, "multiplyOperator");

	assert(&product[0] != &orig[0], "multiplyOperator");

	assert(&product[1] != &orig[1], "multiplyOperator");

	assert(&product[0] != &times[0], "multiplyOperator");

	assert(&product[1] != &times[1], "multiplyOperator");
}

void PointTests::multiplyByDoubleOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	Point orig(values, 2);

	double times = 2;

	Point product = orig * times;

	assert(product[0] == 10.0, "multiplyByDoubleOperator");

	assert(product[1] == 20.0, "multiplyByDoubleOperator");

	assert(&product[0] != &orig[0], "multiplyByDoubleOperator");

	assert(&product[1] != &orig[1], "multiplyByDoubleOperator");
}

void PointTests::equivalenceOperators2D()
{
	double* values = new double[2];
	values[0] = 50;
	values[1] = 70;

	Point test(values, 2);

	double* values2 = new double[2];
	values2[0] = 50;
	values2[1] = 70;

	Point test2(values2, 2);

	double* values3 = new double[2];
	values3[0] = 50.0000000000000001;
	values3[1] = 70.0000000000000001;

	Point test3(values3, 2);

	double* values4 = new double[2];
	values4[0] = 6;
	values4[1] = 7;

	Point test4(values4, 2);

	assert(test == test2, "equivalenceOperators 1");

	assert(test == test3, "equivalenceOperators 2");

	assert(test != test4, "equivalenceOperators 3");
}

void PointTests::dotProduct2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	Point orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 2;
	values2[1] = 3;

	Point dot(values2, 2);

	double product = orig.dot(dot);

	assert(product == 40.0, "dotProduct");
}

void PointTests::magnitude2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	Point test(values, 2);

	double magnitude = test.magnitude();

	assert(magnitude > 11.1 && magnitude < 11.2, "magnitude");
}

void PointTests::magnitudeSquared2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	Point test(values, 2);

	double magnitudeSq = test.magnitudeSquared();

	assert(magnitudeSq == 125.0, "magnitudeSquared");
}

void PointTests::divideOperator2D()
{
	double* values = new double[2];
	values[0] = 6;
	values[1] = 10;

	Point orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 2;
	values2[1] = 5;

	Point divisor(values2, 2);

	Point quotient = orig / divisor;

	assert(quotient[0] == 3.0, "divideOperator");

	assert(quotient[1] == 2.0, "divideOperator");

	assert(&quotient[0] != &orig[0], "divideOperator");

	assert(&quotient[1] != &orig[1], "divideOperator");

	assert(&quotient[0] != &divisor[0], "divideOperator");

	assert(&quotient[1] != &divisor[1], "divideOperator");
}

void PointTests::divideByDoubleOperator2D()
{
	double* values = new double[2];
	values[0] = 6;
	values[1] = 10;

	Point orig(values, 2);

	double divisor = 2;

	Point quotient = orig / divisor;

	assert(quotient[0] == 3.0, "divideByDoubleOperator");

	assert(quotient[1] == 5.0, "divideByDoubleOperator");

	assert(&quotient[0] != &orig[0], "divideByDoubleOperator");

	assert(&quotient[1] != &orig[1], "divideByDoubleOperator");
}

void PointTests::additionShorthandOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	Point orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 1;
	values2[1] = 2;

	Point plus(values2, 2);

	orig += plus;

	assert(orig[0] == 6.0, "additionShorthandOperator");

	assert(orig[1] == 12.0, "additionShorthandOperator");

	assert(&orig[0] != &plus[0], "additionShorthandOperator");

	assert(&orig[1] != &plus[1], "additionShorthandOperator");
}

void PointTests::subtractionShorthandOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	Point orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 1;
	values2[1] = 2;

	Point minus(values2, 2);

	orig -= minus;

	assert(orig[0] == 4.0, "subtractionShorthandOperator");

	assert(orig[1] == 8.0, "subtractionShorthandOperator");

	assert(&orig[0] != &minus[0], "subtractionShorthandOperator");

	assert(&orig[1] != &minus[1], "subtractionShorthandOperator");
}

void PointTests::multiplyShorthandOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	Point orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 2;
	values2[1] = 2;

	Point times(values2, 2);

	orig *= times;

	assert(orig[0] == 10.0, "multiplyShorthandOperator 1");

	assert(orig[1] == 20.0, "multiplyShorthandOperator 2");

	assert(&orig[0] != &times[0], "multiplyShorthandOperator 3");

	assert(&orig[1] != &times[1], "multiplyShorthandOperator 4");
}

void PointTests::multiplyByDoubleShorthandOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	Point orig(values, 2);

	double times = 2;

	orig *= times;

	assert(orig[0] == 10.0, "multiplyByDoubleShorthandOperator 1");

	assert(orig[1] == 20.0, "multiplyByDoubleShorthandOperator 2");
}

void PointTests::divideShorthandOperator2D()
{
	double* values = new double[2];
	values[0] = 6;
	values[1] = 10;

	Point orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 2;
	values2[1] = 5;

	Point divisor(values2, 2);

	orig /= divisor;

	assert(orig[0] == 3.0, "divideShorthandOperator");

	assert(orig[1] == 2.0, "divideShorthandOperator");

	assert(&orig[0] != &divisor[0], "divideShorthandOperator");

	assert(&orig[1] != &divisor[1], "divideShorthandOperator");
}

void PointTests::divideByDoubleShorthandOperator2D()
{
	double* values = new double[2];
	values[0] = 6;
	values[1] = 10;

	Point orig(values, 2);

	double divisor = 2;

	orig /= divisor;

	assert(orig[0] == 3.0, "divideByDoubleShorthandOperator 1");

	assert(orig[1] == 5.0, "divideByDoubleShorthandOperator 2");
}

void PointTests::distance2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	Point test(values, 2);

	double* values2 = new double[2];
	values2[0] = 7;
	values2[1] = 2;

	Point test2(values2, 2);

	double distance = test.distance(test2);

	double alsoDistance = test2.distance(test);

	const double shouldBeThis = 8.2462112512353212;

	assert(distance == alsoDistance, "distance2D");

	assert(distance == shouldBeThis, "distance2D");
}

void PointTests::distanceSquared2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	Point test(values, 2);

	double* values2 = new double[2];
	values2[0] = 7;
	values2[1] = 3;

	Point test2(values2, 2);

	double distanceSquared = test.distanceSquared(test2);

	double alsoDistanceSquared = test2.distanceSquared(test);

	assert(distanceSquared == alsoDistanceSquared, "distanceSquared");

	assert(distanceSquared == 53.0, "distanceSquared");
}

void PointTests::normalize2D()
{
	double* values = new double[2];
	values[0] = 0;
	values[1] = 10;

	Point test(values, 2);

	double* values2 = new double[2];
	values2[0] = 10;
	values2[1] = 0;

	Point test2(values2, 2);

	double* values3 = new double[2];
	values3[0] = 10;
	values3[1] = 10;

	Point test3(values3, 2);

	test.normalize();
	test2.normalize();

	assert(0.0 == test[0], "normalize2D 1");
	assert(1.0 == test[1], "normalize2D 2");

	assert(1.0 == test2[0], "normalize2D 3");
	assert(0.0 == test2[1], "normalize2D 4");

	double testNormal = (10.0 * 10.0) + (10.0 * 10.0);
	testNormal = sqrt(testNormal);
	testNormal = 1 / testNormal;
	Point normalizedTest3 = test3 * testNormal;

	test3.normalize();

	assert(normalizedTest3 == test3, "normalize2D 5");

	Point test4 = Point(0, 0);

	try
	{
		test4.normalize();
		assert(false, "normalize2D 6");
	}
	catch (std::logic_error e)
	{
		assert(true, "normalize2D 7");
	}
}

void PointTests::normalized2D()
{
	Point test = Point();
	test.addDimension(0);
	test.addDimension(10);

	Point test2 = Point();
	test2.addDimension(10);
	test2.addDimension(0);

	Point test3 = Point();
	test3.addDimension(10);
	test3.addDimension(10);

	Point testNormalized = test.normalized();
	Point test2Normalized = test2.normalized();

	assert(0.0 == testNormalized[0], "normalized");
	assert(1.0 == testNormalized[1], "normalized");

	assert(1.0 == test2Normalized[0], "normalized");
	assert(0.0 == test2Normalized[1], "normalized");

	assert(&test[0] != &test2Normalized[0], "normalized");
	assert(&test2[0] != &test2Normalized[1], "normalized");

	double testNormal = (10.0 * 10.0) + (10.0 * 10.0);
	testNormal = sqrt(testNormal);
	testNormal = 1 / testNormal;
	Point normalizedTest3 = test3 * testNormal;

	Point test3Normalized = test3.normalized();

	assert(normalizedTest3 == test3Normalized, "normalized");

	Point test4 = Point(0, 0);

	try
	{
		Point test4Normalized = test4.normalized();
		assert(false, "normalized");
	}
	catch (std::logic_error e)
	{
		assert(true, "normalized");
	}
}

void PointTests::project2D()
{
	Point first = Point();
	first.addDimension(5);
	first.addDimension(5);

	Point second = Point();
	second.addDimension(-3);
	second.addDimension(2);

	Point projected = first.project(second);

	assert(15.0 / 13.0 == projected[0], "project");
	assert(-10.0 / 13.0 == projected[1], "project");
}

void PointTests::outputOperator2D()
{
	Point test = Point();
	test.addDimension(55);
	test.addDimension(703);

	std::stringstream out;

	out << test;

	std::string testText = "(55, 703)";

	assert(testText == out.str(), "outputOperator");
}

void PointTests::perpendicular2D()
{
	Point first = Point();
	first.addDimension(5);
	first.addDimension(5);

	Point second = Point();
	second.addDimension(-3);
	second.addDimension(2);

	Point perpendicular = first.perpendicular(second);

	assert(3.84 < perpendicular[0], "perpendicular");
	assert(3.86 > perpendicular[0], "perpendicular");

	assert(5.75 < perpendicular[1], "perpendicular");
	assert(5.77 > perpendicular[1], "perpendicular");

	Point test2 = Point();
	test2.addDimension(10.0);
	test2.addDimension(0.0);

	Point test3 = Point();
	test3.addDimension(5.0);
	test3.addDimension(5.0);

	Point perpendicular2 = test3.perpendicular(test2);

	assert(0.0 == perpendicular2[0], "perpendicular");
	assert(5.0 == perpendicular2[1], "perpendicular");

}

void PointTests::rotate2D()
{
	Point test = Point();
	test.addDimension(5);
	test.addDimension(5);

	Point rotatedRight = test.rotate2D(-45.0);

	Point rotatedLeft = test.rotate2D(45.0);

	assert(rotatedRight[1] < 1, "rotate");
	assert(rotatedRight[1] >= 0, "rotate");
	assert(rotatedLeft[0] < 1, "rotate");
	assert(rotatedLeft[0] >= 0, "rotate");
}

void PointTests::angle2D()
{
	Point first = Point();
	first.addDimension(5);
	first.addDimension(5);

	Point second = Point();
	second.addDimension(-5);
	second.addDimension(5);

	assert(90.0 == first.angle(second), "angle");

	Point third = Point();
	third.addDimension(2);
	third.addDimension(7);

	Point fourth = Point();
	fourth.addDimension(-4);
	fourth.addDimension(-1);

	double testAngle2 = third.angle(fourth);

	assert(testAngle2 > 119.9, "angle");
	assert(testAngle2 < 120, "angle");
}

void PointTests::reflect2D()
{
	Point right = Point();
	right.addDimension(1);
	right.addDimension(0);

	Point up = Point();
	up.addDimension(0);
	up.addDimension(1);

	Point reflectedLeft = right.reflect(up);

	Point rotatedDown = up.reflect(right);

	assert(-1.0 == reflectedLeft[0], "reflect");
	assert(0.0 == reflectedLeft[1], "reflect");
	assert(0.0 == rotatedDown[0], "reflect");
	assert(-1.0 == rotatedDown[1], "reflect");
}

void PointTests::constructor3D()
{
	Point test;
	test.addDimension(0);
	test.addDimension(0);
	test.addDimension(0);

	assert(test[0] == 0.0, "constructor3D");

	assert(test[1] == 0.0, "constructor3D");

	assert(test[2] == 0.0, "constructor3D");
}

void PointTests::constructorWithValues3D()
{
	Point test;
	test.addDimension(5.5);
	test.addDimension(7.1);
	test.addDimension(9.6);

	assert(test[0] == 5.5, "constructorWithValues3D");

	assert(test[1] == 7.1, "constructorWithValues3D");

	assert(test[2] == 9.6, "constructorWithValues3D");
}

void PointTests::copyConstructor3D()
{
	Point test;
	test.addDimension(5.5);
	test.addDimension(7.1);
	test.addDimension(9.6);

	Point copy = Point(test);

	//make sure they have the right values
	assert(test[0] == 5.5, "copyConstructor3D");

	assert(test[1] == 7.1, "copyConstructor3D");

	assert(test[2] == 9.6, "copyConstructor3D");

	assert(copy[0] == 5.5, "copyConstructor3D");

	assert(copy[1] == 7.1, "copyConstructor3D");

	assert(copy[2] == 9.6, "copyConstructor3D");

	//make sure each has its own memory
	assert(&test[0] != &copy[0], "copyConstructor3D");

	assert(&test[1] != &copy[1], "copyConstructor3D");

	assert(&test[2] != &copy[2], "copyConstructor3D");
}

void PointTests::moveConstructor3D()
{
	Point test;
	test.addDimension(5);
	test.addDimension(6);
	test.addDimension(9);

	Point moveHere(std::move(test));

	//make sure they have the righ tvalues
	assert(test.getNumberOfDimensions() == 0, "moveConstructor3D");

	assert(moveHere[0] == 5.0, "moveConstructor3D");

	assert(moveHere[1] == 6.0, "moveConstructor3D");

	assert(moveHere[2] == 9.0, "moveConstructor3D");
}

void PointTests::assignmentOperator3D()
{
	Point test;
	test.addDimension(55);
	test.addDimension(10);
	test.addDimension(6);

	Point assigned = test;

	//make sure they have the righ tvalues
	assert(test[0] == 55.0, "assignmentOperator3D");

	assert(test[1] == 10.0, "assignmentOperator3D");

	assert(test[2] == 6.0, "assignmentOperator3D");

	assert(assigned[0] == 55.0, "assignmentOperator3D");

	assert(assigned[1] == 10.0, "assignmentOperator3D");

	assert(assigned[2] == 6.0, "assignmentOperator3D");

	//make sure each has its own memory
	assert(&test[0] != &assigned[0], "assignmentOperator3D");

	assert(&test[1] != &assigned[1], "assignmentOperator3D");

	assert(&test[2] != &assigned[2], "assignmentOperator3D");
}

void PointTests::moveAssignmentOperator3D()
{
	Point test;
	test.addDimension(5);
	test.addDimension(6);
	test.addDimension(8);

	Point moveAssignHere = std::move(test);

	//make sure they have the righ tvalues
	assert(test.getNumberOfDimensions() == 0, "moveAssignmentOperator3D");

	assert(moveAssignHere[0] == 5.0, "moveAssignmentOperator3D");

	assert(moveAssignHere[1] == 6.0, "moveAssignmentOperator3D");

	assert(moveAssignHere[2] == 8.0, "moveAssignmentOperator3D");
}

void PointTests::additionOperator3D()
{
	Point orig;
	orig.addDimension(5);
	orig.addDimension(10);
	orig.addDimension(2);

	Point plus;
	plus.addDimension(1);
	plus.addDimension(2);
	plus.addDimension(25);

	Point sum = orig + plus;

	assert(sum[0] == 6.0, "additionOperator3D");

	assert(sum[1] == 12.0, "additionOperator3D");

	assert(sum[2] == 27.0, "additionOperator3D");

	assert(&sum[0] != &orig[0], "additionOperator3D");

	assert(&sum[1] != &orig[1], "additionOperator3D");

	assert(&sum[2] != &orig[2], "additionOperator3D");

	assert(&sum[0] != &plus[0], "additionOperator3D");

	assert(&sum[1] != &plus[1], "additionOperator3D");

	assert(&sum[2] != &plus[2], "additionOperator3D");
}

void PointTests::subtractionOperator3D()
{
	Point orig;
	orig.addDimension(5);
	orig.addDimension(10);
	orig.addDimension(6);

	Point minus;
	minus.addDimension(1);
	minus.addDimension(2);
	minus.addDimension(3);

	Point difference = orig - minus;

	assert(difference[0] == 4.0, "subtractionOperator3D");

	assert(difference[1] == 8.0, "subtractionOperator3D");

	assert(difference[2] == 3.0, "subtractionOperator3D");

	assert(&difference[0] != &orig[0], "subtractionOperator3D");

	assert(&difference[1] != &orig[1], "subtractionOperator3D");

	assert(&difference[2] != &orig[2], "subtractionOperator3D");

	assert(&difference[0] != &minus[0], "subtractionOperator3D");

	assert(&difference[1] != &minus[1], "subtractionOperator3D");

	assert(&difference[2] != &minus[2], "subtractionOperator3D");
}

void PointTests::multiply2Vector3sOperator3D()
{
	Point orig;
	orig.addDimension(5);
	orig.addDimension(10);
	orig.addDimension(15);

	Point times;
	times.addDimension(2);
	times.addDimension(3);
	times.addDimension(1);

	Point product = orig * times;

	assert(product[0] == 10.0, "multiply2Vector3sOperator3D");

	assert(product[1] == 30.0, "multiply2Vector3sOperator3D");

	assert(product[2] == 15.0, "multiply2Vector3sOperator3D");

	assert(&product[0] != &orig[0], "multiply2Vector3sOperator3D");

	assert(&product[1] != &orig[1], "multiply2Vector3sOperator3D");

	assert(&product[2] != &orig[2], "multiply2Vector3sOperator3D");

	assert(&product[0] != &times[0], "multiply2Vector3sOperator3D");

	assert(&product[1] != &times[1], "multiply2Vector3sOperator3D");

	assert(&product[2] != &times[2], "multiply2Vector3sOperator3D");
}

void PointTests::multiplyVector3ByDouble3D()
{
	Point orig;
	orig.addDimension(5);
	orig.addDimension(10);
	orig.addDimension(6);

	double times = 2;

	Point product = orig * times;

	assert(product[0] == 10.0, "multiplyVector3ByDouble3D");

	assert(product[1] == 20.0, "multiplyVector3ByDouble3D");

	assert(product[2] == 12.0, "multiplyVector3ByDouble3D");

	assert(&product[0] != &orig[0], "multiplyVector3ByDouble3D");

	assert(&product[1] != &orig[1], "multiplyVector3ByDouble3D");

	assert(&product[2] != &orig[2], "multiplyVector3ByDouble3D");
}

void PointTests::equivalenceOperators3D()
{
	Point test;
	test.addDimension(50);
	test.addDimension(70);
	test.addDimension(60);

	Point test2;
	test2.addDimension(50);
	test2.addDimension(70);
	test2.addDimension(60);

	Point test3;
	test3.addDimension(50.0000000000000001);
	test3.addDimension(70.0000000000000001);
	test3.addDimension(60.0000000000000001);

	Point test4;
	test4.addDimension(6);
	test4.addDimension(7);
	test4.addDimension(11);

	assert(test == test2, "equivalenceOperators3D");

	assert(test == test3, "equivalenceOperators3D");

	assert(test != test4, "equivalenceOperators3D");
}

void PointTests::dotProduct3D()
{
	Point orig;
	orig.addDimension(5);
	orig.addDimension(10);
	orig.addDimension(3);

	Point dot;
	dot.addDimension(2);
	dot.addDimension(3);
	dot.addDimension(4);

	double product = orig.dot(dot);

	assert(product == 52.0, "dotProduct3D");
}

void PointTests::magnitude3D()
{
	Point test;
	test.addDimension(5);
	test.addDimension(10);
	test.addDimension(12);

	double magnitude = test.magnitude();

	assert(magnitude == sqrt(269), "magnitude3D");
}

void PointTests::magnitudeSquared3D()
{
	Point test;
	test.addDimension(5);
	test.addDimension(10);
	test.addDimension(12);

	double magnitudeSq = test.magnitudeSquared();

	assert(magnitudeSq == 269.0, "magnitudeSquared3D");
}

void PointTests::divide2Vector3sOperator3D()
{
	Point orig;
	orig.addDimension(6);
	orig.addDimension(10);
	orig.addDimension(9);

	Point divisor;
	divisor.addDimension(2);
	divisor.addDimension(5);
	divisor.addDimension(3);

	Point quotient = orig / divisor;

	assert(quotient[0] == 3.0, "divide2Vector3sOperator3D");

	assert(quotient[1] == 2.0, "divide2Vector3sOperator3D");

	assert(quotient[2] == 3.0, "divide2Vector3sOperator3D");

	assert(&quotient[0] != &orig[0], "divide2Vector3sOperator3D");

	assert(&quotient[1] != &orig[1], "divide2Vector3sOperator3D");

	assert(&quotient[2] != &orig[2], "divide2Vector3sOperator3D");

	assert(&quotient[0] != &divisor[0], "divide2Vector3sOperator3D");

	assert(&quotient[1] != &divisor[1], "divide2Vector3sOperator3D");

	assert(&quotient[2] != &divisor[2], "divide2Vector3sOperator3D");
}

void PointTests::divideVector3ByDoubleOperator3D()
{
	Point orig;
	orig.addDimension(6);
	orig.addDimension(10);
	orig.addDimension(15);

	double divisor = 2;

	Point quotient = orig / divisor;

	assert(quotient[0] == 3.0, "divideVector3ByDoubleOperator3D");

	assert(quotient[1] == 5.0, "divideVector3ByDoubleOperator3D");

	assert(quotient[2] == 7.5, "divideVector3ByDoubleOperator3D");

	assert(&quotient[0] != &orig[0], "divideVector3ByDoubleOperator3D");

	assert(&quotient[1] != &orig[1], "divideVector3ByDoubleOperator3D");

	assert(&quotient[2] != &orig[2], "divideVector3ByDoubleOperator3D");
}

void PointTests::additionShorthandOperator3D()
{
	Point orig;
	orig.addDimension(5);
	orig.addDimension(10);
	orig.addDimension(19);

	Point plus;
	plus.addDimension(1);
	plus.addDimension(2);
	plus.addDimension(1);

	orig += plus;

	assert(orig[0] == 6.0, "additionShorthandOperator3D");

	assert(orig[1] == 12.0, "additionShorthandOperator3D");

	assert(orig[2] == 20.0, "additionShorthandOperator3D");

	assert(&orig[0] != &plus[0], "additionShorthandOperator3D");

	assert(&orig[1] != &plus[1], "additionShorthandOperator3D");

	assert(&orig[2] != &plus[2], "additionShorthandOperator3D");
}

void PointTests::subtractionShorthandOperator3D()
{
	Point orig;
	orig.addDimension(5);
	orig.addDimension(10);
	orig.addDimension(25);

	Point minus;
	minus.addDimension(1);
	minus.addDimension(2);
	minus.addDimension(5);

	orig -= minus;

	assert(orig[0] == 4.0, "subtractionShorthandOperator3D");

	assert(orig[1] == 8.0, "subtractionShorthandOperator3D");

	assert(orig[2] == 20.0, "subtractionShorthandOperator3D");

	assert(&orig[0] != &minus[0], "subtractionShorthandOperator3D");

	assert(&orig[1] != &minus[1], "subtractionShorthandOperator3D");

	assert(&orig[2] != &minus[2], "subtractionShorthandOperator3D");
}

void PointTests::multiply2Vector3sShorthandOperator3D()
{
	Point orig;
	orig.addDimension(5);
	orig.addDimension(10);
	orig.addDimension(15);

	Point times;
	times.addDimension(2);
	times.addDimension(2);
	times.addDimension(2);

	orig *= times;

	assert(orig[0] == 10.0, "multiply2Vector3sShorthandOperator3D");

	assert(orig[1] == 20.0, "multiply2Vector3sShorthandOperator3D");

	assert(orig[2] == 30.0, "multiply2Vector3sShorthandOperator3D");

	assert(&orig[0] != &times[0], "multiply2Vector3sShorthandOperator3D");

	assert(&orig[1] != &times[1], "multiply2Vector3sShorthandOperator3D");

	assert(&orig[2] != &times[2], "multiply2Vector3sShorthandOperator3D");
}

void PointTests::multiplyVector3ByDoubleShorthandOperator3D()
{
	Point orig;
	orig.addDimension(5);
	orig.addDimension(10);
	orig.addDimension(30);

	double times = 2;

	orig *= times;

	assert(orig[0] == 10.0, "multiplyVector3ByDoubleShorthandOperator3D");

	assert(orig[1] == 20.0, "multiplyVector3ByDoubleShorthandOperator3D");

	assert(orig[2] == 60.0, "multiplyVector3ByDoubleShorthandOperator3D");
}

void PointTests::divide2Vector3sShorthandOperator3D()
{
	Point orig;
	orig.addDimension(6);
	orig.addDimension(10);
	orig.addDimension(9);

	Point divisor;
	divisor.addDimension(2);
	divisor.addDimension(5);
	divisor.addDimension(3);

	orig /= divisor;

	assert(orig[0] == 3.0, "divide2Vector3sShorthandOperator3D");

	assert(orig[1] == 2.0, "divide2Vector3sShorthandOperator3D");

	assert(orig[2] == 3.0, "divide2Vector3sShorthandOperator3D");

	assert(&orig[0] != &divisor[0], "divide2Vector3sShorthandOperator3D");

	assert(&orig[1] != &divisor[1], "divide2Vector3sShorthandOperator3D");

	assert(&orig[2] != &divisor[2], "divide2Vector3sShorthandOperator3D");
}

void PointTests::divideVector3ByDoubleShorthandOperator3D()
{
	Point orig;
	orig.addDimension(6);
	orig.addDimension(10);
	orig.addDimension(20);

	double divisor = 2;

	orig /= divisor;

	assert(orig[0] == 3.0, "divideVector3ByDoubleShorthandOperator3D");

	assert(orig[1] == 5.0, "divideVector3ByDoubleShorthandOperator3D");

	assert(orig[2] == 10.0, "divideVector3ByDoubleShorthandOperator3D");
}

void PointTests::distance3D()
{
	Point test;
	test.addDimension(5);
	test.addDimension(10);
	test.addDimension(20);

	Point test2;
	test2.addDimension(7);
	test2.addDimension(3);
	test2.addDimension(6);

	double distance = test.distance(test2);

	double alsoDistance = test2.distance(test);

	assert(distance == alsoDistance, "distance3D");

	assert(distance == sqrt(249.0), "distance3D");
}

void PointTests::distanceSquared3D()
{
	Point test;
	test.addDimension(5);
	test.addDimension(10);
	test.addDimension(20);

	Point test2;
	test2.addDimension(7);
	test2.addDimension(3);
	test2.addDimension(6);

	double distance = test.distanceSquared(test2);

	double alsoDistance = test2.distanceSquared(test);

	assert(distance == alsoDistance, "distanceSquared3D");

	assert(distance == 249.0, "distanceSquared3D");
}

void PointTests::normalize3D()
{
	Point test;
	test.addDimension(0);
	test.addDimension(10);
	test.addDimension(0);

	Point test2;
	test2.addDimension(10);
	test2.addDimension(0);
	test2.addDimension(0);

	Point test3;
	test3.addDimension(0);
	test3.addDimension(0);
	test3.addDimension(10);

	Point test4;
	test4.addDimension(4);
	test4.addDimension(6);
	test4.addDimension(8);

	test.normalize();
	test2.normalize();
	test3.normalize();
	test4.normalize();

	assert(0.0 == test[0], "normalize3D");
	assert(1.0 == test[1], "normalize3D");
	assert(0.0 == test[2], "normalize3D");

	assert(1.0 == test2[0], "normalize3D");
	assert(0.0 == test2[1], "normalize3D");
	assert(0.0 == test2[2], "normalize3D");

	assert(0.0 == test3[0], "normalize3D");
	assert(0.0 == test3[1], "normalize3D");
	assert(1.0 == test3[2], "normalize3D");

	assert(0.371 < test4[0], "normalize3D");
	assert(0.557 < test4[1], "normalize3D");
	assert(0.742 < test4[2], "normalize3D");
	assert(0.372 > test4[0], "normalize3D");
	assert(0.558 > test4[1], "normalize3D");
	assert(0.743 > test4[2], "normalize3D");


	Point test5;
	test5.addDimension(0);
	test5.addDimension(0);
	test5.addDimension(0);

	try
	{
		test5.normalize();
		assert(false, "normalize3D");
	}
	catch (std::logic_error e)
	{
		assert(true, "normalize3D");
	}
}

void PointTests::normalized3D()
{
	Point test;
	test.addDimension(0);
	test.addDimension(10);
	test.addDimension(0);

	Point test2;
	test2.addDimension(10);
	test2.addDimension(0);
	test2.addDimension(0);

	Point test3;
	test3.addDimension(0);
	test3.addDimension(0);
	test3.addDimension(10);

	Point test4;
	test4.addDimension(4);
	test4.addDimension(6);
	test4.addDimension(8);

	Point test1Normalized = test.normalized();
	Point test2Normalized = test2.normalized();
	Point test3Normalized = test3.normalized();
	Point test4Normalized = test4.normalized();

	assert(0.0 == test1Normalized[0], "normalized3D");
	assert(1.0 == test1Normalized[1], "normalized3D");
	assert(0.0 == test1Normalized[2], "normalized3D");

	assert(1.0 == test2Normalized[0], "normalized3D");
	assert(0.0 == test2Normalized[1], "normalized3D");
	assert(0.0 == test2Normalized[2], "normalized3D");

	assert(0.0 == test3Normalized[0], "normalized3D");
	assert(0.0 == test3Normalized[1], "normalized3D");
	assert(1.0 == test3Normalized[2], "normalized3D");

	assert(0.371 < test4Normalized[0], "normalized3D");
	assert(0.557 < test4Normalized[1], "normalized3D");
	assert(0.742 < test4Normalized[2], "normalized3D");
	assert(0.372 > test4Normalized[0], "normalized3D");
	assert(0.558 > test4Normalized[1], "normalized3D");
	assert(0.743 > test4Normalized[2], "normalized3D");


	Point test5;
	test5.addDimension(0);
	test5.addDimension(0);
	test5.addDimension(0);

	try
	{
		Point throwaway = test5.normalized();
		assert(false, "normalized3D");
	}
	catch (std::logic_error e)
	{
		assert(true, "normalized3D");
	}
}

void PointTests::project3D()
{
	Point first = Point();
	first.addDimension(3);
	first.addDimension(4);
	first.addDimension(-3);

	Point second;
	second.addDimension(2);
	second.addDimension(0);
	second.addDimension(6);

	Point projected = second.project(first);

	assert(-18.0 / 17.0 == projected[0], "project3D");
	assert(-24.0 / 17.0 == projected[1], "project3D");
	assert(18.0 / 17.0 == projected[2], "project3D");
}

void PointTests::outputOperator3D()
{
	Point test;
	test.addDimension(55);
	test.addDimension(703);
	test.addDimension(5.5);

	std::stringstream out;

	out << test;

	std::string testText = "(55, 703, 5.5)";

	assert(testText == out.str(), "outputOperator3D");
}

void PointTests::perpendicular3D()
{
	Point first;
	first.addDimension(5);
	first.addDimension(5);
	first.addDimension(11);

	Point second = Point();
	second.addDimension(-3);
	second.addDimension(2);
	second.addDimension(8);

	Point perpendicular = first.perpendicular(second);

	assert(8.3 > perpendicular[0], "perpendicular3D");
	assert(8.2 < perpendicular[0], "perpendicular3D");

	assert(2.9 > perpendicular[1], "perpendicular3D");
	assert(2.8 < perpendicular[1], "perpendicular3D");

	assert(2.4 > perpendicular[2], "perpendicular3D");
	assert(2.3 < perpendicular[2], "perpendicular3D");

	Point test2;
	test2.addDimension(10.0);
	test2.addDimension(0.0);
	test2.addDimension(0.0);
	Point test3;
	test3.addDimension(5.0);
	test3.addDimension(5.0);
	test3.addDimension(5.0);

	Point perpendicular2 = test3.perpendicular(test2);

	assert(0.0 == perpendicular2[0], "perpendicular3D");
	assert(5.0 == perpendicular2[1], "perpendicular3D");
	assert(5.0 == perpendicular2[2], "perpendicular3D");
}

void PointTests::angle3D()
{
	Point first;
	first.addDimension(5);
	first.addDimension(5);
	first.addDimension(5);

	Point second = Point();
	second.addDimension(-5);
	second.addDimension(5);
	second.addDimension(5);

	double test1 = first.angle(second);

	assert(70.52877 < test1, "angle3D");
	assert(70.52878 > test1, "angle3D");

	Point third;
	third.addDimension(2);
	third.addDimension(7);
	third.addDimension(3);

	Point fourth = Point();
	fourth.addDimension(-4);
	fourth.addDimension(-1);
	fourth.addDimension(-3);

	double test2 = third.angle(fourth);

	assert(126.70982 < test2, "angle3D");
	assert(126.70983 > test2, "angle3D");
}

void PointTests::reflect3D()
{
	Point a;
	a.addDimension(5);
	a.addDimension(0);
	a.addDimension(5);

	Point b;
	b.addDimension(0);
	b.addDimension(5);
	b.addDimension(0);

	Point ab = a.reflect(b);

	Point ba = b.reflect(a);

	assert(-5.0 == ab[0], "reflect3D");
	assert(0.0 == ab[1], "reflect3D");
	assert(-5.0 == ab[2], "reflect3D");
	assert(0.0 == ba[0], "reflect3D");
	assert(-5.0 == ba[1], "reflect3D");
	assert(0.0 == ba[2], "reflect3D");
}

void PointTests::crossProduct3D()
{
	Point right;
	right.addDimension(5);
	right.addDimension(0);
	right.addDimension(0);
	Point up;
	up.addDimension(0);
	up.addDimension(5);
	up.addDimension(0);
	Point into;
	into.addDimension(0);
	into.addDimension(0);
	into.addDimension(25);

	assert(into[0] == right.crossProduct(up)[0], "crossProduct3D");
	assert(into[1] == right.crossProduct(up)[1], "crossProduct3D");
	assert(into[2] == right.crossProduct(up)[2], "crossProduct3D");
}
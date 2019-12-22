//Cody Ware
//10/2/18

#include "../headers/PhysicsVectorTests.h"

void PhysicsVectorTests::runAllTests()
{
	//test 2d
	T01_constructor2D();
	T02_constructorWithValues2D();
	T03_copyConstructor2D();
	T04_moveConstructor2D();
	T05_assignmentOperator2D();
	T06_moveAssignmentOperator2D();
	T07_additionOperator2D();
	T08_subtractionOperator2D();
	T09_multiplyOperator2D();
	T10_multiplyByDoubleOperator2D();
	T11_equivalenceOperators2D();
	T12_dotProduct2D();
	T13_magnitude2D();
	T14_magnitudeSquared2D();
	T15_divideOperator2D();
	T16_divideByDoubleOperator2D();
	T17_additionShorthandOperator2D();
	T18_subtractionShorthandOperator2D();
	T19_multiplyShorthandOperator2D();
	T20_multiplyByDoubleShorthandOperator2D();
	T21_divideShorthandOperator2D();
	T22_divideByDoubleShorthandOperator2D();
	T23_distance2D();
	T24_distanceSquared2D();
	T25_normalize2D();
	T26_normalized2D();
	T27_project2D();
	T28_outputOperator2D();
	T29_perpendicular2D();
	T30_rotate2D();
	T31_angle2D();
	T32_reflect2D();

	//test 3d
	T33_constructor3D();
	T34_constructorWithValues3D();
	T35_copyConstructor3D();
	T36_moveConstructor3D();
	T37_assignmentOperator3D();
	T38_moveAssignmentOperator3D();
	T39_additionOperator3D();
	T40_subtractionOperator3D();
	T41_multiply2Vector3sOperator3D();
	T42_multiplyVector3ByDouble3D();
	T43_equivalenceOperators3D();
	T44_dotProduct3D();
	T45_magnitude3D();
	T46_magnitudeSquared3D();
	T47_divide2Vector3sOperator3D();
	T48_divideVector3ByDoubleOperator3D();
	T49_additionShorthandOperator3D();
	T50_subtractionShorthandOperator3D();
	T51_multiply2Vector3sShorthandOperator3D();
	T52_multiplyVector3ByDoubleShorthandOperator3D();
	T53_divide2Vector3sShorthandOperator3D();
	T54_divideVector3ByDoubleShorthandOperator3D();
	T55_distance3D();
	T56_distanceSquared3D();
	T57_normalize3D();
	T58_normalized3D();
	T59_project3D();
	T60_outputOperator3D();
	T61_perpendicular3D();
	T62_angle3D();
	T63_reflect3D();
	T64_crossProduct3D();

	cout << "Passed: All PhysicsVector Tests\n";
}

void PhysicsVectorTests::T01_constructor2D()
{
	double* values = new double[2];
	values[0] = 0.0;
	values[1] = 0.0;

	PhysicsVector test(values, 2);

	assert(test[0] == 0.0, "T01_constructor failed");

	assert(test[1] == 0.0, "T01_constructor failed");
}

void PhysicsVectorTests::T02_constructorWithValues2D()
{
	double* values = new double[2];
	values[0] = 5.5;
	values[1] = 7.1;

	PhysicsVector test(values, 2);

	assert(test[0] == 5.5, "T02_constructorWithValues");

	assert(test[1] == 7.1, "T02_constructorWithValues");
}

void PhysicsVectorTests::T03_copyConstructor2D()
{
	double* values = new double[2];
	values[0] = 5.5;
	values[1] = 7.1;

	PhysicsVector test(values, 2);

	PhysicsVector copy(test);

	//make sure they have the right values
	assert(test[0] == 5.5, "T03_copyConstructor");

	assert(test[1] == 7.1, "T03_copyConstructor");

	assert(copy[0] == 5.5, "T03_copyConstructor");

	assert(copy[1] == 7.1, "T03_copyConstructor");

	//make sure each has its own memory
	assert(&test[0] != &copy[0], "T03_copyConstructor");

	assert(&test[1] != &copy[1], "T03_copyConstructor");
}

void PhysicsVectorTests::T04_moveConstructor2D()
{
	double* values = new double[2];
	values[0] = 5.0;
	values[1] = 6.0;

	PhysicsVector test(values, 2);

	PhysicsVector moveHere(std::move(test));

	//make sure they have the righ tvalues
	assert(test.getNumberOfDimensions() == 0, "T04_moveConstructor");

	assert(moveHere[0] == 5.0, "T04_moveConstructor");

	assert(moveHere[1] == 6.0, "T04_moveConstructor");
}

void PhysicsVectorTests::T05_assignmentOperator2D()
{
	double* values = new double[2];
	values[0] = 55;
	values[1] = 10;

	PhysicsVector test(values, 2);

	PhysicsVector assigned = test;

	//make sure they have the righ tvalues
	assert(test[0] == 55.0, "T05_assignmentOperator");

	assert(test[1] == 10.0, "T05_assignmentOperator");

	assert(assigned[0] == 55.0, "T05_assignmentOperator");

	assert(assigned[1] == 10.0, "T05_assignmentOperator");

	//make sure each has its own memory
	assert(&test[0] != &assigned[0], "T05_assignmentOperator");

	assert(&test[1] != &assigned[1], "T05_assignmentOperator");
}

void PhysicsVectorTests::T06_moveAssignmentOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 6;

	PhysicsVector test(values, 2);

	PhysicsVector moveAssignHere = std::move(test);

	//make sure they have the righ tvalues
	assert(test.getNumberOfDimensions() == 0.0, "T06_moveAssignmentOperator");

	assert(moveAssignHere[0] == 5.0, "T06_moveAssignmentOperator");

	assert(moveAssignHere[1] == 6.0, "T06_moveAssignmentOperator");
}

void PhysicsVectorTests::T07_additionOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 1;
	values2[1] = 2;

	PhysicsVector plus(values2, 2);

	PhysicsVector sum = orig + plus;

	assert(sum[0] == 6.0, "T07_additionOperator 1");

	assert(sum[1] == 12.0, "T07_additionOperator 2");

	assert(&sum[0] != &orig[0], "T07_additionOperator 3");

	assert(&sum[1] != &orig[1], "T07_additionOperator 4");

	assert(&sum[0] != &plus[0], "T07_additionOperator 5");

	assert(&sum[1] != &plus[1], "T07_additionOperator 6");
}

void PhysicsVectorTests::T08_subtractionOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 1;
	values2[1] = 2;

	PhysicsVector minus(values2, 2);

	PhysicsVector difference = orig - minus;

	assert(difference[0] == 4.0, "T08_subtractionOperator");

	assert(difference[1] == 8.0, "T08_subtractionOperator");

	assert(&difference[0] != &orig[0], "T08_subtractionOperator");

	assert(&difference[1] != &orig[1], "T08_subtractionOperator");

	assert(&difference[0] != &minus[0], "T08_subtractionOperator");

	assert(&difference[1] != &minus[1], "T08_subtractionOperator");
}

void PhysicsVectorTests::T09_multiplyOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 2;
	values2[1] = 2;

	PhysicsVector times(values2, 2);

	PhysicsVector product = orig * times;

	assert(product[0] == 10.0, "T09_multiplyOperator");

	assert(product[1] == 20.0, "T09_multiplyOperator");

	assert(&product[0] != &orig[0], "T09_multiplyOperator");

	assert(&product[1] != &orig[1], "T09_multiplyOperator");

	assert(&product[0] != &times[0], "T09_multiplyOperator");

	assert(&product[1] != &times[1], "T09_multiplyOperator");
}

void PhysicsVectorTests::T10_multiplyByDoubleOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double times = 2;

	PhysicsVector product = orig * times;

	assert(product[0] == 10.0, "T10_multiplyByDoubleOperator");

	assert(product[1] == 20.0, "T10_multiplyByDoubleOperator");

	assert(&product[0] != &orig[0], "T10_multiplyByDoubleOperator");

	assert(&product[1] != &orig[1], "T10_multiplyByDoubleOperator");
}

void PhysicsVectorTests::T11_equivalenceOperators2D()
{
	double* values = new double[2];
	values[0] = 50;
	values[1] = 70;

	PhysicsVector test(values, 2);

	double* values2 = new double[2];
	values2[0] = 50;
	values2[1] = 70;

	PhysicsVector test2(values2, 2);

	double* values3 = new double[2];
	values3[0] = 50.0000000000000001;
	values3[1] = 70.0000000000000001;

	PhysicsVector test3(values3, 2);

	double* values4 = new double[2];
	values4[0] = 6;
	values4[1] = 7;

	PhysicsVector test4(values4, 2);

	assert(test == test2, "T11_equivalenceOperators 1");

	assert(test == test3, "T11_equivalenceOperators 2");

	assert(test != test4, "T11_equivalenceOperators 3");
}

void PhysicsVectorTests::T12_dotProduct2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 2;
	values2[1] = 3;

	PhysicsVector dot(values2, 2);

	double product = orig.dot(dot);

	assert(product == 40.0, "T12_dotProduct");
}

void PhysicsVectorTests::T13_magnitude2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector test(values, 2);

	double magnitude = test.magnitude();

	assert(magnitude > 11.1 && magnitude < 11.2, "T13_magnitude");
}

void PhysicsVectorTests::T14_magnitudeSquared2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector test(values, 2);

	double magnitudeSq = test.magnitudeSquared();

	assert(magnitudeSq == 125.0, "T14_magnitudeSquared");
}

void PhysicsVectorTests::T15_divideOperator2D()
{
	double* values = new double[2];
	values[0] = 6;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 2;
	values2[1] = 5;

	PhysicsVector divisor(values2, 2);

	PhysicsVector quotient = orig / divisor;

	assert(quotient[0] == 3.0, "T15_divideOperator");

	assert(quotient[1] == 2.0, "T15_divideOperator");

	assert(&quotient[0] != &orig[0], "T15_divideOperator");

	assert(&quotient[1] != &orig[1], "T15_divideOperator");

	assert(&quotient[0] != &divisor[0], "T15_divideOperator");

	assert(&quotient[1] != &divisor[1], "T15_divideOperator");
}

void PhysicsVectorTests::T16_divideByDoubleOperator2D()
{
	double* values = new double[2];
	values[0] = 6;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double divisor = 2;

	PhysicsVector quotient = orig / divisor;

	assert(quotient[0] == 3.0, "T16_divideByDoubleOperator");

	assert(quotient[1] == 5.0, "T16_divideByDoubleOperator");

	assert(&quotient[0] != &orig[0], "T16_divideByDoubleOperator");

	assert(&quotient[1] != &orig[1], "T16_divideByDoubleOperator");
}

void PhysicsVectorTests::T17_additionShorthandOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 1;
	values2[1] = 2;

	PhysicsVector plus(values2, 2);

	orig += plus;

	assert(orig[0] == 6.0, "T17_additionShorthandOperator");

	assert(orig[1] == 12.0, "T17_additionShorthandOperator");

	assert(&orig[0] != &plus[0], "T17_additionShorthandOperator");

	assert(&orig[1] != &plus[1], "T17_additionShorthandOperator");
}

void PhysicsVectorTests::T18_subtractionShorthandOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 1;
	values2[1] = 2;

	PhysicsVector minus(values2, 2);

	orig -= minus;

	assert(orig[0] == 4.0, "T18_subtractionShorthandOperator");

	assert(orig[1] == 8.0, "T18_subtractionShorthandOperator");

	assert(&orig[0] != &minus[0], "T18_subtractionShorthandOperator");

	assert(&orig[1] != &minus[1], "T18_subtractionShorthandOperator");
}

void PhysicsVectorTests::T19_multiplyShorthandOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 2;
	values2[1] = 2;

	PhysicsVector times(values2, 2);

	orig *= times;

	assert(orig[0] == 10.0, "T19_multiplyShorthandOperator 1");

	assert(orig[1] == 20.0, "T19_multiplyShorthandOperator 2");

	assert(&orig[0] != &times[0], "T19_multiplyShorthandOperator 3");

	assert(&orig[1] != &times[1], "T19_multiplyShorthandOperator 4");
}

void PhysicsVectorTests::T20_multiplyByDoubleShorthandOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double times = 2;

	orig *= times;

	assert(orig[0] == 10.0, "T20_multiplyByDoubleShorthandOperator 1");

	assert(orig[1] == 20.0, "T20_multiplyByDoubleShorthandOperator 2");
}

void PhysicsVectorTests::T21_divideShorthandOperator2D()
{
	double* values = new double[2];
	values[0] = 6;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 2;
	values2[1] = 5;

	PhysicsVector divisor(values2, 2);

	orig /= divisor;

	assert(orig[0] == 3.0, "T21_divideShorthandOperator");

	assert(orig[1] == 2.0, "T21_divideShorthandOperator");

	assert(&orig[0] != &divisor[0], "T21_divideShorthandOperator");

	assert(&orig[1] != &divisor[1], "T21_divideShorthandOperator");
}

void PhysicsVectorTests::T22_divideByDoubleShorthandOperator2D()
{
	double* values = new double[2];
	values[0] = 6;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double divisor = 2;

	orig /= divisor;

	assert(orig[0] == 3.0, "T22_divideByDoubleShorthandOperator 1");

	assert(orig[1] == 5.0, "T22_divideByDoubleShorthandOperator 2");
}

void PhysicsVectorTests::T23_distance2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector test(values, 2);

	double* values2 = new double[2];
	values2[0] = 7;
	values2[1] = 2;

	PhysicsVector test2(values2, 2);

	double distance = test.distance(test2);

	double alsoDistance = test2.distance(test);

	const double shouldBeThis = 8.2462112512353212;

	assert(distance == alsoDistance, "T23_distance2D");

	assert(distance == shouldBeThis, "T23_distance2D");
}

void PhysicsVectorTests::T24_distanceSquared2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector test(values, 2);

	double* values2 = new double[2];
	values2[0] = 7;
	values2[1] = 3;

	PhysicsVector test2(values2, 2);

	double distanceSquared = test.distanceSquared(test2);

	double alsoDistanceSquared = test2.distanceSquared(test);

	assert(distanceSquared == alsoDistanceSquared, "T24_distanceSquared");

	assert(distanceSquared == 53.0, "T24_distanceSquared");
}

void PhysicsVectorTests::T25_normalize2D()
{
	double* values = new double[2];
	values[0] = 0;
	values[1] = 10;

	PhysicsVector test(values, 2);

	double* values2 = new double[2];
	values2[0] = 10;
	values2[1] = 0;

	PhysicsVector test2(values2, 2);

	double* values3 = new double[2];
	values3[0] = 10;
	values3[1] = 10;

	PhysicsVector test3(values3, 2);

	test.normalize();
	test2.normalize();

	assert(0.0 == test[0], "T25_normalize2D 1");
	assert(1.0 == test[1], "T25_normalize2D 2");

	assert(1.0 == test2[0], "T25_normalize2D 3");
	assert(0.0 == test2[1], "T25_normalize2D 4");

	double testNormal = (10.0 * 10.0) + (10.0 * 10.0);
	testNormal = sqrt(testNormal);
	testNormal = 1 / testNormal;
	PhysicsVector normalizedTest3 = test3 * testNormal;

	test3.normalize();

	assert(normalizedTest3 == test3, "T25_normalize2D 5");

	PhysicsVector test4 = PhysicsVector(0, 0);

	try
	{
		test4.normalize();
		assert(false, "T25_normalize2D 6");
	}
	catch (std::logic_error e)
	{
		assert(true, "T25_normalize2D 7");
	}
}

void PhysicsVectorTests::T26_normalized2D()
{
	PhysicsVector test = PhysicsVector();
	test.addDimension(0);
	test.addDimension(10);

	PhysicsVector test2 = PhysicsVector();
	test2.addDimension(10);
	test2.addDimension(0);

	PhysicsVector test3 = PhysicsVector();
	test3.addDimension(10);
	test3.addDimension(10);

	PhysicsVector testNormalized = test.normalized();
	PhysicsVector test2Normalized = test2.normalized();

	assert(0.0 == testNormalized[0], "T26_normalized");
	assert(1.0 == testNormalized[1], "T26_normalized");

	assert(1.0 == test2Normalized[0], "T26_normalized");
	assert(0.0 == test2Normalized[1], "T26_normalized");

	assert(&test[0] != &test2Normalized[0], "T26_normalized");
	assert(&test2[0] != &test2Normalized[1], "T26_normalized");

	double testNormal = (10.0 * 10.0) + (10.0 * 10.0);
	testNormal = sqrt(testNormal);
	testNormal = 1 / testNormal;
	PhysicsVector normalizedTest3 = test3 * testNormal;

	PhysicsVector test3Normalized = test3.normalized();

	assert(normalizedTest3 == test3Normalized, "T26_normalized");

	PhysicsVector test4 = PhysicsVector(0, 0);

	try
	{
		PhysicsVector test4Normalized = test4.normalized();
		assert(false, "T26_normalized");
	}
	catch (std::logic_error e)
	{
		assert(true, "T26_normalized");
	}
}

void PhysicsVectorTests::T27_project2D()
{
	PhysicsVector first = PhysicsVector();
	first.addDimension(5);
	first.addDimension(5);

	PhysicsVector second = PhysicsVector();
	second.addDimension(-3);
	second.addDimension(2);

	PhysicsVector projected = first.project(second);

	assert(15.0 / 13.0 == projected[0], "T27_project");
	assert(-10.0 / 13.0 == projected[1], "T27_project");
}

void PhysicsVectorTests::T28_outputOperator2D()
{
	PhysicsVector test = PhysicsVector();
	test.addDimension(55);
	test.addDimension(703);

	std::stringstream out;

	out << test;

	std::string testText = "(55, 703)";

	assert(testText == out.str(), "T28_outputOperator");
}

void PhysicsVectorTests::T29_perpendicular2D()
{
	PhysicsVector first = PhysicsVector();
	first.addDimension(5);
	first.addDimension(5);

	PhysicsVector second = PhysicsVector();
	second.addDimension(-3);
	second.addDimension(2);

	PhysicsVector perpendicular = first.perpendicular(second);

	assert(3.84 < perpendicular[0], "T29_perpendicular");
	assert(3.86 > perpendicular[0], "T29_perpendicular");

	assert(5.75 < perpendicular[1], "T29_perpendicular");
	assert(5.77 > perpendicular[1], "T29_perpendicular");

	PhysicsVector test2 = PhysicsVector();
	test2.addDimension(10.0);
	test2.addDimension(0.0);

	PhysicsVector test3 = PhysicsVector();
	test3.addDimension(5.0);
	test3.addDimension(5.0);

	PhysicsVector perpendicular2 = test3.perpendicular(test2);

	assert(0.0 == perpendicular2[0], "T29_perpendicular");
	assert(5.0 == perpendicular2[1], "T29_perpendicular");

}

void PhysicsVectorTests::T30_rotate2D()
{
	PhysicsVector test = PhysicsVector();
	test.addDimension(5);
	test.addDimension(5);

	PhysicsVector rotatedRight = test.rotate2D(-45.0);

	PhysicsVector rotatedLeft = test.rotate2D(45.0);

	assert(rotatedRight[1] < 1, "T30_rotate");
	assert(rotatedRight[1] >= 0, "T30_rotate");
	assert(rotatedLeft[0] < 1, "T30_rotate");
	assert(rotatedLeft[0] >= 0, "T30_rotate");
}

void PhysicsVectorTests::T31_angle2D()
{
	PhysicsVector first = PhysicsVector();
	first.addDimension(5);
	first.addDimension(5);

	PhysicsVector second = PhysicsVector();
	second.addDimension(-5);
	second.addDimension(5);

	assert(90.0 == first.angle(second), "T31_angle");

	PhysicsVector third = PhysicsVector();
	third.addDimension(2);
	third.addDimension(7);

	PhysicsVector fourth = PhysicsVector();
	fourth.addDimension(-4);
	fourth.addDimension(-1);

	double testAngle2 = third.angle(fourth);

	assert(testAngle2 > 119.9, "T31_angle");
	assert(testAngle2 < 120, "T31_angle");
}

void PhysicsVectorTests::T32_reflect2D()
{
	PhysicsVector right = PhysicsVector();
	right.addDimension(1);
	right.addDimension(0);

	PhysicsVector up = PhysicsVector();
	up.addDimension(0);
	up.addDimension(1);

	PhysicsVector reflectedLeft = right.reflect(up);

	PhysicsVector rotatedDown = up.reflect(right);

	assert(-1.0 == reflectedLeft[0], "T32_reflect");
	assert(0.0 == reflectedLeft[1], "T32_reflect");
	assert(0.0 == rotatedDown[0], "T32_reflect");
	assert(-1.0 == rotatedDown[1], "T32_reflect");
}

void PhysicsVectorTests::T33_constructor3D()
{
	PhysicsVector test;
	test.addDimension(0);
	test.addDimension(0);
	test.addDimension(0);
	
	assert(test[0] == 0.0, "T33_constructor3D");
	
	assert(test[1] == 0.0, "T33_constructor3D");
	
	assert(test[2] == 0.0, "T33_constructor3D");
}

void PhysicsVectorTests::T34_constructorWithValues3D()
{
	PhysicsVector test; 
	test.addDimension(5.5); 
	test.addDimension(7.1); 
	test.addDimension(9.6);
	
	assert(test[0] == 5.5, "T34_constructorWithValues3D");
	
	assert(test[1] == 7.1, "T34_constructorWithValues3D");
	
	assert(test[2] == 9.6, "T34_constructorWithValues3D");
}

void PhysicsVectorTests::T35_copyConstructor3D()
{
	PhysicsVector test; 
	test.addDimension(5.5); 
	test.addDimension(7.1); 
	test.addDimension(9.6);
	
	PhysicsVector copy = PhysicsVector(test);
	
	//make sure they have the right values
	assert(test[0] == 5.5, "T35_copyConstructor3D");
	
	assert(test[1] == 7.1, "T35_copyConstructor3D");
	
	assert(test[2] == 9.6, "T35_copyConstructor3D");
	
	assert(copy[0] == 5.5, "T35_copyConstructor3D");
	
	assert(copy[1] == 7.1, "T35_copyConstructor3D");
	
	assert(copy[2] == 9.6, "T35_copyConstructor3D");
	
	//make sure each has its own memory
	assert(&test[0] != &copy[0], "T35_copyConstructor3D");
	
	assert(&test[1] != &copy[1], "T35_copyConstructor3D");
	
	assert(&test[2] != &copy[2], "T35_copyConstructor3D");
}

void PhysicsVectorTests::T36_moveConstructor3D()
{
	PhysicsVector test; 
	test.addDimension(5); 
	test.addDimension(6); 
	test.addDimension(9);
	
	PhysicsVector moveHere(std::move(test));
	
	//make sure they have the righ tvalues
	assert(test.getNumberOfDimensions() == 0, "T36_moveConstructor3D");
	
	assert(moveHere[0] == 5.0, "T36_moveConstructor3D");
	
	assert(moveHere[1] == 6.0, "T36_moveConstructor3D");
	
	assert(moveHere[2] == 9.0, "T36_moveConstructor3D");
}

void PhysicsVectorTests::T37_assignmentOperator3D()
{
	PhysicsVector test; 
	test.addDimension(55); 
	test.addDimension(10); 
	test.addDimension(6);
	
	PhysicsVector assigned = test;
	
	//make sure they have the righ tvalues
	assert(test[0] == 55.0, "T37_assignmentOperator3D");
	
	assert(test[1] == 10.0, "T37_assignmentOperator3D");
	
	assert(test[2] == 6.0, "T37_assignmentOperator3D");
	
	assert(assigned[0] == 55.0, "T37_assignmentOperator3D");
	
	assert(assigned[1] == 10.0, "T37_assignmentOperator3D");
	
	assert(assigned[2] == 6.0, "T37_assignmentOperator3D");
	
	//make sure each has its own memory
	assert(&test[0] != &assigned[0], "T37_assignmentOperator3D");
	
	assert(&test[1] != &assigned[1], "T37_assignmentOperator3D");
	
	assert(&test[2] != &assigned[2], "T37_assignmentOperator3D");
}

void PhysicsVectorTests::T38_moveAssignmentOperator3D()
{
	PhysicsVector test; 
	test.addDimension(5); 
	test.addDimension(6); 
	test.addDimension(8);

	PhysicsVector moveAssignHere = std::move(test);

	//make sure they have the righ tvalues
	assert(test.getNumberOfDimensions() == 0, "T38_moveAssignmentOperator3D");

	assert(moveAssignHere[0] == 5.0, "T38_moveAssignmentOperator3D");

	assert(moveAssignHere[1] == 6.0, "T38_moveAssignmentOperator3D");

	assert(moveAssignHere[2] == 8.0, "T38_moveAssignmentOperator3D");
}

void PhysicsVectorTests::T39_additionOperator3D()
{
		PhysicsVector orig; 
		orig.addDimension(5); 
		orig.addDimension(10); 
		orig.addDimension(2);
	
		PhysicsVector plus; 
		plus.addDimension(1); 
		plus.addDimension(2); 
		plus.addDimension(25);
	
		PhysicsVector sum = orig + plus;
	
		assert(sum[0] == 6.0, "T39_additionOperator3D");
	
		assert(sum[1] == 12.0, "T39_additionOperator3D");
	
		assert(sum[2] == 27.0, "T39_additionOperator3D");
	
		assert(&sum[0] != &orig[0], "T39_additionOperator3D");
	
		assert(&sum[1] != &orig[1], "T39_additionOperator3D");
	
		assert(&sum[2] != &orig[2], "T39_additionOperator3D");
	
		assert(&sum[0] != &plus[0], "T39_additionOperator3D");
	
		assert(&sum[1] != &plus[1], "T39_additionOperator3D");
	
		assert(&sum[2] != &plus[2], "T39_additionOperator3D");
}

void PhysicsVectorTests::T40_subtractionOperator3D()
{
		PhysicsVector orig; 
		orig.addDimension(5); 
		orig.addDimension(10); 
		orig.addDimension(6);
	
		PhysicsVector minus; 
		minus.addDimension(1); 
		minus.addDimension(2); 
		minus.addDimension(3);
	
		PhysicsVector difference = orig - minus;
	
		assert(difference[0] == 4.0, "T40_subtractionOperator3D");
	
		assert(difference[1] == 8.0, "T40_subtractionOperator3D");
	
		assert(difference[2] == 3.0, "T40_subtractionOperator3D");
	
		assert(&difference[0] != &orig[0], "T40_subtractionOperator3D");
	
		assert(&difference[1] != &orig[1], "T40_subtractionOperator3D");
	
		assert(&difference[2] != &orig[2], "T40_subtractionOperator3D");
	
		assert(&difference[0] != &minus[0], "T40_subtractionOperator3D");
	
		assert(&difference[1] != &minus[1], "T40_subtractionOperator3D");
	
		assert(&difference[2] != &minus[2], "T40_subtractionOperator3D");
}

void PhysicsVectorTests::T41_multiply2Vector3sOperator3D()
{
		PhysicsVector orig; 
		orig.addDimension(5); 
		orig.addDimension(10); 
		orig.addDimension(15);
	
		PhysicsVector times; 
		times.addDimension(2); 
		times.addDimension(3); 
		times.addDimension(1);
	
		PhysicsVector product = orig * times;
	
		assert(product[0] == 10.0, "T41_multiply2Vector3sOperator3D");
	
		assert(product[1] == 30.0, "T41_multiply2Vector3sOperator3D");
	
		assert(product[2] == 15.0, "T41_multiply2Vector3sOperator3D");
	
		assert(&product[0] != &orig[0], "T41_multiply2Vector3sOperator3D");
	
		assert(&product[1] != &orig[1], "T41_multiply2Vector3sOperator3D");
	
		assert(&product[2] != &orig[2], "T41_multiply2Vector3sOperator3D");
	
		assert(&product[0] != &times[0], "T41_multiply2Vector3sOperator3D");
	
		assert(&product[1] != &times[1], "T41_multiply2Vector3sOperator3D");
	
		assert(&product[2] != &times[2], "T41_multiply2Vector3sOperator3D");
}

void PhysicsVectorTests::T42_multiplyVector3ByDouble3D()
{
		PhysicsVector orig; 
		orig.addDimension(5); 
		orig.addDimension(10); 
		orig.addDimension(6);
	
		double times = 2;
	
		PhysicsVector product = orig * times;
	
		assert(product[0] == 10.0, "T42_multiplyVector3ByDouble3D");
	
		assert(product[1] == 20.0, "T42_multiplyVector3ByDouble3D");
	
		assert(product[2] == 12.0, "T42_multiplyVector3ByDouble3D");
	
		assert(&product[0] != &orig[0], "T42_multiplyVector3ByDouble3D");
	
		assert(&product[1] != &orig[1], "T42_multiplyVector3ByDouble3D");
	
		assert(&product[2] != &orig[2], "T42_multiplyVector3ByDouble3D");
}

void PhysicsVectorTests::T43_equivalenceOperators3D()
{
		PhysicsVector test; 
		test.addDimension(50); 
		test.addDimension(70); 
		test.addDimension(60);
	
		PhysicsVector test2; 
		test2.addDimension(50); 
		test2.addDimension(70); 
		test2.addDimension(60);
	
		PhysicsVector test3; 
		test3.addDimension(50.0000000000000001); 
		test3.addDimension(70.0000000000000001); 
		test3.addDimension(60.0000000000000001);
	
		PhysicsVector test4; 
		test4.addDimension(6); 
		test4.addDimension(7); 
		test4.addDimension(11);
	
		assert(test == test2, "T43_equivalenceOperators3D");
	
		assert(test == test3, "T43_equivalenceOperators3D");
	
		assert(test != test4, "T43_equivalenceOperators3D");
}

void PhysicsVectorTests::T44_dotProduct3D()
{
		PhysicsVector orig; 
		orig.addDimension(5); 
		orig.addDimension(10); 
		orig.addDimension(3);
	
		PhysicsVector dot; 
		dot.addDimension(2); 
		dot.addDimension(3); 
		dot.addDimension(4);
	
		double product = orig.dot(dot);
	
		assert(product == 52.0, "T44_dotProduct3D");
}

void PhysicsVectorTests::T45_magnitude3D()
{
		PhysicsVector test; 
		test.addDimension(5); 
		test.addDimension(10); 
		test.addDimension(12);
	
		double magnitude = test.magnitude();
	
		assert(magnitude == sqrt(269), "T45_magnitude3D");
}

void PhysicsVectorTests::T46_magnitudeSquared3D()
{
		PhysicsVector test; 
		test.addDimension(5); 
		test.addDimension(10); 
		test.addDimension(12);
	
		double magnitudeSq = test.magnitudeSquared();
	
		assert(magnitudeSq == 269.0, "T46_magnitudeSquared3D");
}

void PhysicsVectorTests::T47_divide2Vector3sOperator3D()
{
		PhysicsVector orig; 
		orig.addDimension(6); 
		orig.addDimension(10); 
		orig.addDimension(9);
	
		PhysicsVector divisor; 
		divisor.addDimension(2); 
		divisor.addDimension(5); 
		divisor.addDimension(3);
	
		PhysicsVector quotient = orig / divisor;
	
		assert(quotient[0] == 3.0, "T47_divide2Vector3sOperator3D");
	
		assert(quotient[1] == 2.0, "T47_divide2Vector3sOperator3D");
	
		assert(quotient[2] == 3.0, "T47_divide2Vector3sOperator3D");
	
		assert(&quotient[0] != &orig[0], "T47_divide2Vector3sOperator3D");
	
		assert(&quotient[1] != &orig[1], "T47_divide2Vector3sOperator3D");
	
		assert(&quotient[2] != &orig[2], "T47_divide2Vector3sOperator3D");
	
		assert(&quotient[0] != &divisor[0], "T47_divide2Vector3sOperator3D");
	
		assert(&quotient[1] != &divisor[1], "T47_divide2Vector3sOperator3D");
	
		assert(&quotient[2] != &divisor[2], "T47_divide2Vector3sOperator3D");
}

void PhysicsVectorTests::T48_divideVector3ByDoubleOperator3D()
{
		PhysicsVector orig; 
		orig.addDimension(6); 
		orig.addDimension(10); 
		orig.addDimension(15);
	
		double divisor = 2;
	
		PhysicsVector quotient = orig / divisor;
	
		assert(quotient[0] == 3.0, "T48_divideVector3ByDoubleOperator3D");
	
		assert(quotient[1] == 5.0, "T48_divideVector3ByDoubleOperator3D");
	
		assert(quotient[2] == 7.5, "T48_divideVector3ByDoubleOperator3D");
	
		assert(&quotient[0] != &orig[0], "T48_divideVector3ByDoubleOperator3D");
	
		assert(&quotient[1] != &orig[1], "T48_divideVector3ByDoubleOperator3D");
	
		assert(&quotient[2] != &orig[2], "T48_divideVector3ByDoubleOperator3D");
}

void PhysicsVectorTests::T49_additionShorthandOperator3D()
{
		PhysicsVector orig; 
		orig.addDimension(5); 
		orig.addDimension(10); 
		orig.addDimension(19);
	
		PhysicsVector plus; 
		plus.addDimension(1); 
		plus.addDimension(2); 
		plus.addDimension(1);
	
		orig += plus;
	
		assert(orig[0] == 6.0, "T49_additionShorthandOperator3D");
	
		assert(orig[1] == 12.0, "T49_additionShorthandOperator3D");
	
		assert(orig[2] == 20.0, "T49_additionShorthandOperator3D");
	
		assert(&orig[0] != &plus[0], "T49_additionShorthandOperator3D");
	
		assert(&orig[1] != &plus[1], "T49_additionShorthandOperator3D");
	
		assert(&orig[2] != &plus[2], "T49_additionShorthandOperator3D");
}

void PhysicsVectorTests::T50_subtractionShorthandOperator3D()
{
		PhysicsVector orig; 
		orig.addDimension(5); 
		orig.addDimension(10); 
		orig.addDimension(25);
	
		PhysicsVector minus; 
		minus.addDimension(1); 
		minus.addDimension(2); 
		minus.addDimension(5);
	
		orig -= minus;
	
		assert(orig[0] == 4.0, "T50_subtractionShorthandOperator3D");
	
		assert(orig[1] == 8.0, "T50_subtractionShorthandOperator3D");
	
		assert(orig[2] == 20.0, "T50_subtractionShorthandOperator3D");
	
		assert(&orig[0] != &minus[0], "T50_subtractionShorthandOperator3D");
	
		assert(&orig[1] != &minus[1], "T50_subtractionShorthandOperator3D");
	
		assert(&orig[2] != &minus[2], "T50_subtractionShorthandOperator3D");
}

void PhysicsVectorTests::T51_multiply2Vector3sShorthandOperator3D()
{
		PhysicsVector orig; 
		orig.addDimension(5); 
		orig.addDimension(10); 
		orig.addDimension(15);
	
		PhysicsVector times; 
		times.addDimension(2); 
		times.addDimension(2); 
		times.addDimension(2);
	
		orig *= times;
	
		assert(orig[0] == 10.0, "T51_multiply2Vector3sShorthandOperator3D");
	
		assert(orig[1] == 20.0, "T51_multiply2Vector3sShorthandOperator3D");
	
		assert(orig[2] == 30.0, "T51_multiply2Vector3sShorthandOperator3D");
	
		assert(&orig[0] != &times[0], "T51_multiply2Vector3sShorthandOperator3D");
	
		assert(&orig[1] != &times[1], "T51_multiply2Vector3sShorthandOperator3D");
	
		assert(&orig[2] != &times[2], "T51_multiply2Vector3sShorthandOperator3D");
}

void PhysicsVectorTests::T52_multiplyVector3ByDoubleShorthandOperator3D()
{
		PhysicsVector orig; 
		orig.addDimension(5); 
		orig.addDimension(10); 
		orig.addDimension(30);
	
		double times = 2;
	
		orig *= times;
	
		assert(orig[0] == 10.0, "T52_multiplyVector3ByDoubleShorthandOperator3D");
	
		assert(orig[1] == 20.0, "T52_multiplyVector3ByDoubleShorthandOperator3D");
	
		assert(orig[2] == 60.0, "T52_multiplyVector3ByDoubleShorthandOperator3D");
}

void PhysicsVectorTests::T53_divide2Vector3sShorthandOperator3D()
{
		PhysicsVector orig; 
		orig.addDimension(6); 
		orig.addDimension(10); 
		orig.addDimension(9);
	
		PhysicsVector divisor; 
		divisor.addDimension(2); 
		divisor.addDimension(5); 
		divisor.addDimension(3);
	
		orig /= divisor;
	
		assert(orig[0] == 3.0, "T53_divide2Vector3sShorthandOperator3D");
	
		assert(orig[1] == 2.0, "T53_divide2Vector3sShorthandOperator3D");
	
		assert(orig[2] == 3.0, "T53_divide2Vector3sShorthandOperator3D");
	
		assert(&orig[0] != &divisor[0], "T53_divide2Vector3sShorthandOperator3D");
	
		assert(&orig[1] != &divisor[1], "T53_divide2Vector3sShorthandOperator3D");
	
		assert(&orig[2] != &divisor[2], "T53_divide2Vector3sShorthandOperator3D");
}

void PhysicsVectorTests::T54_divideVector3ByDoubleShorthandOperator3D()
{
		PhysicsVector orig; 
		orig.addDimension(6); 
		orig.addDimension(10); 
		orig.addDimension(20);
	
		double divisor = 2;
	
		orig /= divisor;
	
		assert(orig[0] == 3.0, "T54_divideVector3ByDoubleShorthandOperator3D");
	
		assert(orig[1] == 5.0, "T54_divideVector3ByDoubleShorthandOperator3D");
	
		assert(orig[2] == 10.0, "T54_divideVector3ByDoubleShorthandOperator3D");
}

void PhysicsVectorTests::T55_distance3D()
{
		PhysicsVector test; 
		test.addDimension(5); 
		test.addDimension(10); 
		test.addDimension(20);
	
		PhysicsVector test2; 
		test2.addDimension(7); 
		test2.addDimension(3); 
		test2.addDimension(6);
	
		double distance = test.distance(test2);
	
		double alsoDistance = test2.distance(test);
	
		assert(distance == alsoDistance, "T55_distance3D");
	
		assert(distance == sqrt(249.0), "T55_distance3D");
}

void PhysicsVectorTests::T56_distanceSquared3D()
{
		PhysicsVector test; 
		test.addDimension(5); 
		test.addDimension(10); 
		test.addDimension(20);
	
		PhysicsVector test2; 
		test2.addDimension(7); 
		test2.addDimension(3); 
		test2.addDimension(6);
	
		double distance = test.distanceSquared(test2);
	
		double alsoDistance = test2.distanceSquared(test);
	
		assert(distance == alsoDistance, "T56_distanceSquared3D");
	
		assert(distance == 249.0, "T56_distanceSquared3D");
}

void PhysicsVectorTests::T57_normalize3D()
{
		PhysicsVector test; 
		test.addDimension(0); 
		test.addDimension(10); 
		test.addDimension(0);
	
		PhysicsVector test2; 
		test2.addDimension(10); 
		test2.addDimension(0); 
		test2.addDimension(0);
	
		PhysicsVector test3; 
		test3.addDimension(0); 
		test3.addDimension(0); 
		test3.addDimension(10);
	
		PhysicsVector test4; 
		test4.addDimension(4); 
		test4.addDimension(6); 
		test4.addDimension(8);
	
		test.normalize();
		test2.normalize();
		test3.normalize();
		test4.normalize();
	
		assert(0.0 == test[0], "T57_normalize3D");
		assert(1.0 == test[1], "T57_normalize3D");
		assert(0.0 == test[2], "T57_normalize3D");
	
		assert(1.0 == test2[0], "T57_normalize3D");
		assert(0.0 == test2[1], "T57_normalize3D");
		assert(0.0 == test2[2], "T57_normalize3D");
	
		assert(0.0 == test3[0], "T57_normalize3D");
		assert(0.0 == test3[1], "T57_normalize3D");
		assert(1.0 == test3[2], "T57_normalize3D");
	
		assert(0.371 < test4[0], "T57_normalize3D");
		assert(0.557 < test4[1], "T57_normalize3D");
		assert(0.742 < test4[2], "T57_normalize3D");
		assert(0.372 > test4[0], "T57_normalize3D");
		assert(0.558 > test4[1], "T57_normalize3D");
		assert(0.743 > test4[2], "T57_normalize3D");
	
	
		PhysicsVector test5; 
		test5.addDimension(0); 
		test5.addDimension(0); 
		test5.addDimension(0);
	
		try
		{
			test5.normalize();
			assert(false, "T57_normalize3D");
		}
		catch (std::logic_error e)
		{
			assert(true, "T57_normalize3D");
		}
}

void PhysicsVectorTests::T58_normalized3D()
{
		PhysicsVector test; 
		test.addDimension(0); 
		test.addDimension(10); 
		test.addDimension(0);
	
		PhysicsVector test2; 
		test2.addDimension(10); 
		test2.addDimension(0); 
		test2.addDimension(0);
	
		PhysicsVector test3; 
		test3.addDimension(0); 
		test3.addDimension(0); 
		test3.addDimension(10);
	
		PhysicsVector test4; 
		test4.addDimension(4); 
		test4.addDimension(6); 
		test4.addDimension(8);
	
		PhysicsVector test1Normalized = test.normalized();
		PhysicsVector test2Normalized = test2.normalized();
		PhysicsVector test3Normalized = test3.normalized();
		PhysicsVector test4Normalized = test4.normalized();
	
		assert(0.0 == test1Normalized[0], "T58_normalized3D");
		assert(1.0 == test1Normalized[1], "T58_normalized3D");
		assert(0.0 == test1Normalized[2], "T58_normalized3D");
	
		assert(1.0 == test2Normalized[0], "T58_normalized3D");
		assert(0.0 == test2Normalized[1], "T58_normalized3D");
		assert(0.0 == test2Normalized[2], "T58_normalized3D");
	
		assert(0.0 == test3Normalized[0], "T58_normalized3D");
		assert(0.0 == test3Normalized[1], "T58_normalized3D");
		assert(1.0 == test3Normalized[2], "T58_normalized3D");
	
		assert(0.371 < test4Normalized[0], "T58_normalized3D");
		assert(0.557 < test4Normalized[1], "T58_normalized3D");
		assert(0.742 < test4Normalized[2], "T58_normalized3D");
		assert(0.372 > test4Normalized[0], "T58_normalized3D");
		assert(0.558 > test4Normalized[1], "T58_normalized3D");
		assert(0.743 > test4Normalized[2], "T58_normalized3D");
	
	
		PhysicsVector test5; 
		test5.addDimension(0); 
		test5.addDimension(0); 
		test5.addDimension(0);
	
		try
		{
			test5.normalized();
			assert(false, "T58_normalized3D");
		}
		catch (std::logic_error e)
		{
			assert(true, "T58_normalized3D");
		}
}

void PhysicsVectorTests::T59_project3D()
{
		PhysicsVector first = PhysicsVector();
		first.addDimension(3);
		first.addDimension(4);
		first.addDimension(-3);

		PhysicsVector second;
		second.addDimension(2); 
		second.addDimension(0); 
		second.addDimension(6);
	
		PhysicsVector projected = second.project(first);
	
		assert(-18.0 / 17.0 == projected[0], "T59_project3D");
		assert(-24.0 / 17.0 == projected[1], "T59_project3D");
		assert(18.0 / 17.0 == projected[2], "T59_project3D");
}

void PhysicsVectorTests::T60_outputOperator3D()
{
		PhysicsVector test; 
		test.addDimension(55); 
		test.addDimension(703); 
		test.addDimension(5.5);
	
		std::stringstream out;
	
		out << test;
	
		std::string testText = "(55, 703, 5.5)";
	
		assert(testText == out.str(), "T60_outputOperator3D");
}

void PhysicsVectorTests::T61_perpendicular3D()
{
		PhysicsVector first; 
		first.addDimension(5); 
		first.addDimension(5); 
		first.addDimension(11);

		PhysicsVector second = PhysicsVector();
		second.addDimension(-3);
		second.addDimension(2);
		second.addDimension(8);
	
		PhysicsVector perpendicular = first.perpendicular(second);
	
		assert(8.3 > perpendicular[0], "T61_perpendicular3D");
		assert(8.2 < perpendicular[0], "T61_perpendicular3D");
	
		assert(2.9 > perpendicular[1], "T61_perpendicular3D");
		assert(2.8 < perpendicular[1], "T61_perpendicular3D");
	
		assert(2.4 > perpendicular[2], "T61_perpendicular3D");
		assert(2.3 < perpendicular[2], "T61_perpendicular3D");
	
		PhysicsVector test2; 
		test2.addDimension(10.0); 
		test2.addDimension(0.0); 
		test2.addDimension(0.0);
		PhysicsVector test3; 
		test3.addDimension(5.0); 
		test3.addDimension(5.0); 
		test3.addDimension(5.0);
	
		PhysicsVector perpendicular2 = test3.perpendicular(test2);
	
		assert(0.0 == perpendicular2[0], "T61_perpendicular3D");
		assert(5.0 == perpendicular2[1], "T61_perpendicular3D");
		assert(5.0 == perpendicular2[2], "T61_perpendicular3D");
}

void PhysicsVectorTests::T62_angle3D()
{
		PhysicsVector first; 
		first.addDimension(5); 
		first.addDimension(5); 
		first.addDimension(5);

		PhysicsVector second = PhysicsVector();
		second.addDimension(-5);
		second.addDimension(5);
		second.addDimension(5);
	
		double test1 = first.angle(second);
	
		assert(70.52877 < test1, "T62_angle3D");
		assert(70.52878 > test1, "T62_angle3D");
	
		PhysicsVector third; 
		third.addDimension(2); 
		third.addDimension(7); 
		third.addDimension(3);

		PhysicsVector fourth = PhysicsVector();
		fourth.addDimension(-4);
		fourth.addDimension(-1);
		fourth.addDimension(-3);
	
		double test2 = third.angle(fourth);
	
		assert(126.70982 < test2, "T62_angle3D");
		assert(126.70983 > test2, "T62_angle3D");
}

void PhysicsVectorTests::T63_reflect3D()
{
		PhysicsVector a; 
		a.addDimension(5); 
		a.addDimension(0); 
		a.addDimension(5);
	
		PhysicsVector b; 
		b.addDimension(0); 
		b.addDimension(5); 
		b.addDimension(0);
	
		PhysicsVector ab = a.reflect(b);
	
		PhysicsVector ba = b.reflect(a);
	
		assert(-5.0 == ab[0], "T63_reflect3D");
		assert(0.0 == ab[1], "T63_reflect3D");
		assert(-5.0 == ab[2], "T63_reflect3D");
		assert(0.0 == ba[0], "T63_reflect3D");
		assert(-5.0 == ba[1], "T63_reflect3D");
		assert(0.0 == ba[2], "T63_reflect3D");
}

void PhysicsVectorTests::T64_crossProduct3D()
{
		PhysicsVector right; 
		right.addDimension(5); 
		right.addDimension(0); 
		right.addDimension(0);
		PhysicsVector up; 
		up.addDimension(0); 
		up.addDimension(5); 
		up.addDimension(0);
		PhysicsVector into; 
		into.addDimension(0); 
		into.addDimension(0); 
		into.addDimension(25);
	
		assert(into[0] == right.crossProduct(up)[0], "T64_crossProduct3D");
		assert(into[1] == right.crossProduct(up)[1], "T64_crossProduct3D");
		assert(into[2] == right.crossProduct(up)[2], "T64_crossProduct3D");
}
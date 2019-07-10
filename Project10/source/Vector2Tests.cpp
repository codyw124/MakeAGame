//Cody Ware
//10/2/18

#include "../headers/Vector2Tests.h"

void Vector2Tests::runAllTests()
{
	T01_constructor();
	T02_constructorWithValues();
	T03_copyConstructor();
	T04_moveConstructor();
	T05_assignmentOperator();
	T06_moveAssignmentOperator();
	T07_additionOperator();
	T08_subtractionOperator();
	T09_multiplyOperator();
	T10_multiplyByDoubleOperator();
	T11_equivalenceOperators();
	T12_dotProduct();
	T13_magnitude();
	T14_magnitudeSquared();
	T15_divideOperator();
	T16_divideByDoubleOperator();
	T17_additionShorthandOperator();
	T18_subtractionShorthandOperator();
	T19_multiplyShorthandOperator();
	T20_multiplyByDoubleShorthandOperator();
	T21_divideShorthandOperator();
	T22_divideByDoubleShorthandOperator();
	T23_distance();
	T24_distanceSquared();
	T25_normalize();
	T26_normalized();
	T27_project();
	T28_outputOperator();
	T29_perpendicular();
	T30_rotate();
	T31_angle();
	T32_reflect();

	cout<<"All Vector2 Tests Passed\n";
}

void Vector2Tests::T01_constructor()
{
	Vector2 test = Vector2();

	assert(test[0] == 0.0, "T01_constructor failed");

	assert(test[1] == 0.0, "T01_constructor failed");
}

void Vector2Tests::T02_constructorWithValues()
{
	Vector2 test = Vector2(5.5, 7.1);

	assert(test[0] == 5.5, "T02_constructorWithValues");

	assert(test[1] == 7.1, "T02_constructorWithValues");
}

void Vector2Tests::T03_copyConstructor()
{
	Vector2 test = Vector2(5.5, 7.1);

	Vector2 copy = Vector2(test);

	//make sure they have the right values
	assert(test[0] == 5.5, "T03_copyConstructor");

	assert(test[1] == 7.1, "T03_copyConstructor");

	assert(copy[0] == 5.5, "T03_copyConstructor");

	assert(copy[1] == 7.1, "T03_copyConstructor");

	//make sure each has its own memory
	assert(&test[0] != &copy[0], "T03_copyConstructor");

	assert(&test[1] != &copy[1], "T03_copyConstructor");
}

void Vector2Tests::T04_moveConstructor()
{
	Vector2 test = Vector2(5, 6);

	Vector2 moveHere(std::move(test));

	//make sure they have the righ tvalues
	assert(test[0] == 0.0, "T04_moveConstructor");

	assert(test[1] == 0.0, "T04_moveConstructor");

	assert(moveHere[0] == 5.0, "T04_moveConstructor");

	assert(moveHere[1] == 6.0, "T04_moveConstructor");
}

void Vector2Tests::T05_assignmentOperator()
{
	Vector2 test = Vector2(55, 10);

	Vector2 assigned = test;

	//make sure they have the righ tvalues
	assert(test[0] == 55.0, "T05_assignmentOperator");

	assert(test[1] == 10.0, "T05_assignmentOperator");

	assert(assigned[0] == 55.0, "T05_assignmentOperator");

	assert(assigned[1] == 10.0, "T05_assignmentOperator");

	//make sure each has its own memory
	assert(&test[0] != &assigned[0], "T05_assignmentOperator");

	assert(&test[1] != &assigned[1], "T05_assignmentOperator");
}

void Vector2Tests::T06_moveAssignmentOperator()
{
	Vector2 test = Vector2(5, 6);

	Vector2 moveAssignHere = std::move(test);

	//make sure they have the righ tvalues
	assert(test[0] == 0.0, "T06_moveAssignmentOperator");

	assert(test[1] == 0.0, "T06_moveAssignmentOperator");

	assert(moveAssignHere[0] == 5.0, "T06_moveAssignmentOperator");

	assert(moveAssignHere[1] == 6.0, "T06_moveAssignmentOperator");
}

void Vector2Tests::T07_additionOperator()
{
	Vector2 orig = Vector2(5, 10);

	Vector2 plus = Vector2(1, 2);

	Vector2 sum = orig + plus;

	assert(sum[0] == 6.0, "T07_additionOperator");

	assert(sum[1] ==  12.0, "T07_additionOperator");

	assert(&sum[0] != &orig[0], "T07_additionOperator");

	assert(&sum[1] != &orig[1], "T07_additionOperator");

	assert(&sum[0] != &plus[0], "T07_additionOperator");

	assert(&sum[1] != &plus[1], "T07_additionOperator");
}

void Vector2Tests::T08_subtractionOperator()
{
	Vector2 orig = Vector2(5, 10);

	Vector2 minus = Vector2(1, 2);

	Vector2 difference = orig - minus;

	assert(difference[0] == 4.0, "T08_subtractionOperator");

	assert(difference[1] == 8.0, "T08_subtractionOperator");

	assert(&difference[0] != &orig[0], "T08_subtractionOperator");

	assert(&difference[1] != &orig[1], "T08_subtractionOperator");

	assert(&difference[0] != &minus[0], "T08_subtractionOperator");

	assert(&difference[1] != &minus[1], "T08_subtractionOperator");
}

void Vector2Tests::T09_multiplyOperator()
{
	Vector2 orig = Vector2(5, 10);

	Vector2 times = Vector2(2, 2);

	Vector2 product = orig * times;

	assert(product[0] == 10.0, "T09_multiplyOperator");

	assert(product[1] == 20.0, "T09_multiplyOperator");

	assert(&product[0] != &orig[0], "T09_multiplyOperator");

	assert(&product[1] != &orig[1], "T09_multiplyOperator");

	assert(&product[0] != &times[0], "T09_multiplyOperator");

	assert(&product[1] != &times[1], "T09_multiplyOperator");
}

void Vector2Tests::T10_multiplyByDoubleOperator()
{
	Vector2 orig = Vector2(5, 10);

	double times = 2;

	Vector2 product = orig * times;

	assert(product[0] == 10.0, "T10_multiplyByDoubleOperator");

	assert(product[1] == 20.0, "T10_multiplyByDoubleOperator");

	assert(&product[0] != &orig[0], "T10_multiplyByDoubleOperator");

	assert(&product[1] != &orig[1], "T10_multiplyByDoubleOperator");
}

void Vector2Tests::T11_equivalenceOperators()
{
	Vector2 test = Vector2(50, 70);

	Vector2 test2 = Vector2(50, 70);

	Vector2 test3 = Vector2(50.0000000000000001, 70.0000000000000001);

	Vector2 test4 = Vector2(6, 7);

	assert(test == test2, "T11_equivalenceOperators");

	assert(test == test3, "T11_equivalenceOperators");

	assert(test != test4, "T11_equivalenceOperators");
}

void Vector2Tests::T12_dotProduct()
{
	Vector2 orig = Vector2(5, 10);

	Vector2 dot = Vector2(2, 3);

	double product = orig.dot(dot);

	assert(product == 40.0, "T12_dotProduct");
}

void Vector2Tests::T13_magnitude()
{
	Vector2 test = Vector2(5, 10);

	double magnitude = test.magnitude();

	assert(magnitude > 11.1 && magnitude < 11.2, "T13_magnitude");
}

void Vector2Tests::T14_magnitudeSquared()
{
	Vector2 test = Vector2(5, 10);

	double magnitudeSq = test.magnitudeSquared();

	assert(magnitudeSq == 125.0, "T14_magnitudeSquared");
}

void Vector2Tests::T15_divideOperator()
{
	Vector2 orig = Vector2(6, 10);

	Vector2 divisor = Vector2(2, 5);

	Vector2 quotient = orig / divisor;

	assert(quotient[0] == 3.0, "T15_divideOperator");

	assert(quotient[1] == 2.0, "T15_divideOperator");

	assert(&quotient[0] != &orig[0], "T15_divideOperator");

	assert(&quotient[1] != &orig[1], "T15_divideOperator");

	assert(&quotient[0] != &divisor[0], "T15_divideOperator");

	assert(&quotient[1] != &divisor[1], "T15_divideOperator");
}

void Vector2Tests::T16_divideByDoubleOperator()
{
	Vector2 orig = Vector2(6, 10);

	double divisor = 2;

	Vector2 quotient = orig / divisor;

	assert(quotient[0] == 3.0, "T16_divideByDoubleOperator");

	assert(quotient[1] == 5.0, "T16_divideByDoubleOperator");

	assert(&quotient[0] != &orig[0], "T16_divideByDoubleOperator");

	assert(&quotient[1] != &orig[1], "T16_divideByDoubleOperator");
}

void Vector2Tests::T17_additionShorthandOperator()
{
	Vector2 orig = Vector2(5, 10);

	Vector2 plus = Vector2(1, 2);

	orig += plus;

	assert(orig[0] == 6.0, "T17_additionShorthandOperator");

	assert(orig[1] == 12.0, "T17_additionShorthandOperator");

	assert(&orig[0] != &plus[0], "T17_additionShorthandOperator");

	assert(&orig[1] != &plus[1], "T17_additionShorthandOperator");
}

void Vector2Tests::T18_subtractionShorthandOperator()
{
	Vector2 orig = Vector2(5, 10);

	Vector2 minus = Vector2(1, 2);

	orig -= minus;

	assert(orig[0] == 4.0, "T18_subtractionShorthandOperator");

	assert(orig[1] == 8.0, "T18_subtractionShorthandOperator");

	assert(&orig[0] != &minus[0], "T18_subtractionShorthandOperator");

	assert(&orig[1] != &minus[1], "T18_subtractionShorthandOperator");
}

void Vector2Tests::T19_multiplyShorthandOperator()
{
	Vector2 orig = Vector2(5, 10);

	Vector2 times = Vector2(2, 2);

	orig *= times;

	assert(orig[0] == 10.0, "T19_multiplyShorthandOperator");

	assert(orig[1] == 20.0, "T19_multiplyShorthandOperator");

	assert(&orig[0] != &times[0], "T19_multiplyShorthandOperator");

	assert(&orig[1] != &times[1], "T19_multiplyShorthandOperator");
}

void Vector2Tests::T20_multiplyByDoubleShorthandOperator()
{
	Vector2 orig = Vector2(5, 10);

	double times = 2;

	orig *= times;

	assert(orig[0] == 10.0, "T20_multiplyByDoubleShorthandOperator");

	assert(orig[1] == 20.0, "T20_multiplyByDoubleShorthandOperator");
}

void Vector2Tests::T21_divideShorthandOperator()
{
	Vector2 orig = Vector2(6, 10);

	Vector2 divisor = Vector2(2, 5);

	orig /= divisor;

	assert(orig[0] == 3.0, "T21_divideShorthandOperator");

	assert(orig[1] == 2.0, "T21_divideShorthandOperator");

	assert(&orig[0] != &divisor[0], "T21_divideShorthandOperator");

	assert(&orig[1] != &divisor[1], "T21_divideShorthandOperator");
}

void Vector2Tests::T22_divideByDoubleShorthandOperator()
{
	Vector2 orig = Vector2(6, 10);

	double divisor = 2;

	orig /= divisor;

	assert(orig[0] == 3.0, "T22_divideByDoubleShorthandOperator");

	assert(orig[1] == 5.0, "T22_divideByDoubleShorthandOperator");
}

void Vector2Tests::T23_distance()
{
	Vector2 test = Vector2(5, 10);

	Vector2 test2 = Vector2(7, 3);

	double distance = test.distance(test2);

	double alsoDistance = test2.distance(test);

	assert(distance == alsoDistance, "T23_distance");

	assert(distance == sqrt(53.0), "T23_distance");
}

void Vector2Tests::T24_distanceSquared()
{
	Vector2 test = Vector2(5, 10);

	Vector2 test2 = Vector2(7, 3);

	double distanceSquared = test.distanceSquared(test2);

	double alsoDistanceSquared = test2.distanceSquared(test);

	assert(distanceSquared == alsoDistanceSquared, "T24_distanceSquared");

	assert(distanceSquared == 53.0, "T24_distanceSquared");
}

void Vector2Tests::T25_normalize()
{
	Vector2 test = Vector2(0, 10);

	Vector2 test2 = Vector2(10, 0);

	Vector2 test3 = Vector2(10, 10);

	test.normalize();
	test2.normalize();

	assert(0.0 == test[0], "T25_normalize");
	assert(1.0 == test[1], "T25_normalize");

	assert(1.0 == test2[0], "T25_normalize");
	assert(0.0 == test2[1], "T25_normalize");

	double testNormal = (10.0 * 10.0) + (10.0 * 10.0);
	testNormal = sqrt(testNormal);
	testNormal = 1 / testNormal;
	Vector2 normalizedTest3 = test3 * testNormal;

	test3.normalize();

	assert(normalizedTest3 == test3, "T25_normalize");

	Vector2 test4 = Vector2(0, 0);

	try
	{
		test4.normalize();
		assert(false, "T25_normalize");
	}
	catch(std::logic_error e)
	{
		assert(true, "T25_normalize");
	}
}

void Vector2Tests::T26_normalized()
{
	Vector2 test = Vector2(0, 10);

	Vector2 test2 = Vector2(10, 0);

	Vector2 test3 = Vector2(10, 10);

	Vector2 testNormalized = test.normalized();
	Vector2 test2Normalized = test2.normalized();

	assert(0.0 == testNormalized[0], "T26_normalized");
	assert(1.0 == testNormalized[1], "T26_normalized");

	assert(1.0 == test2Normalized[0], "T26_normalized");
	assert(0.0 == test2Normalized[1], "T26_normalized");

	assert(&test[0] != &test2Normalized[0], "T26_normalized");
	assert(&test2[0] != &test2Normalized[1], "T26_normalized");

	double testNormal = (10.0 * 10.0) + (10.0 * 10.0);
	testNormal = sqrt(testNormal);
	testNormal = 1 / testNormal;
	Vector2 normalizedTest3 = test3 * testNormal;

	Vector2 test3Normalized = test3.normalized();

	assert(normalizedTest3 == test3Normalized, "T26_normalized");

	Vector2 test4 = Vector2(0, 0);

	try
	{
		Vector2 test4Normalized = test4.normalized();
		assert(false, "T26_normalized");
	}
	catch (std::logic_error e)
	{
		assert(true, "T26_normalized");
	}
}

void Vector2Tests::T27_project()
{
	Vector2 first = Vector2(5, 5);
	Vector2 second = Vector2(-3, 2);

	Vector2 projected = first.project(second);

	assert(15.0/13.0 == projected[0], "T27_project");
	assert(-10.0/13.0 == projected[1], "T27_project");
}

void Vector2Tests::T28_outputOperator()
{
	Vector2 test = Vector2(55, 703);

	std::stringstream out;

	out << test;

	std::string testText = "(55, 703)";

	assert(testText == out.str(), "T28_outputOperator");
}

void Vector2Tests::T29_perpendicular()
{
	Vector2 first = Vector2(5, 5);
	Vector2 second = Vector2(-3, 2);

	Vector2 perpendicular = first.perpendicular(second);

	assert(3.84 < perpendicular[0], "T29_perpendicular");
	assert(3.86 > perpendicular[0], "T29_perpendicular");

	assert(5.75 < perpendicular[1], "T29_perpendicular");
	assert(5.77 > perpendicular[1], "T29_perpendicular");

	Vector2 test2 = Vector2(10.0, 0.0);
	Vector2 test3 = Vector2(5.0, 5.0);

	Vector2 perpendicular2 = test3.perpendicular(test2);

	assert(0.0 == perpendicular2[0], "T29_perpendicular");
	assert(5.0 == perpendicular2[1], "T29_perpendicular");

}

void Vector2Tests::T30_rotate()
{
	Vector2 test = Vector2(5, 5);

	Vector2 rotatedRight = test.rotate(-45.0);

	Vector2 rotatedLeft = test.rotate(45.0);

	assert(rotatedRight[1] < 1, "T30_rotate");
	assert(rotatedRight[1] >= 0, "T30_rotate");
	assert(rotatedLeft[0] < 1, "T30_rotate");
	assert(rotatedLeft[0] >= 0, "T30_rotate");
}

void Vector2Tests::T31_angle()
{
	Vector2 first = Vector2(5, 5);
	Vector2 second = Vector2(-5, 5);

	assert(90.0 == first.angle(second), "T31_angle");

	Vector2 third = Vector2(2, 7);
	Vector2 fourth = Vector2(-4, -1);

	double testAngle2 = third.angle(fourth);

	assert(testAngle2 > 119.9, "T31_angle");
	assert(testAngle2 < 120, "T31_angle");
}

void Vector2Tests::T32_reflect()
{
	Vector2 right = Vector2(1, 0);

	Vector2 up = Vector2(0, 1);

	Vector2 reflectedLeft = right.reflect(up);

	Vector2 rotatedDown = up.reflect(right);

	assert(-1.0 == reflectedLeft[0], "T32_reflect");
	assert(0.0 == reflectedLeft[1], "T32_reflect");
	assert(0.0 == rotatedDown[0], "T32_reflect");
	assert(-1.0 == rotatedDown[1], "T32_reflect");
}
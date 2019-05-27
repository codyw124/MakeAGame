//Cody Ware
//10/2/18

#include <iostream>
#include <sstream>
#include <cassert>
#include <cmath>
#include <cfloat>
#include "../headers/Vector2.h"
// #include "../headers/PhysicsVector.h"

using namespace std;

void T01_constructor();
void T02_constructorWithValues();
void T03_copyConstructor();
void T04_moveConstructor();
void T05_assignmentOperator();
void T06_moveAssignmentOperator();
void T07_additionOperator();
void T08_subtractionOperator();
void T09_multiplyOperator();
void T10_multiplyByDoubleOperator();
void T11_equivalenceOperators();
void T12_dotProduct();
void T13_magnitude();
void T14_magnitudeSquared();
void T15_divideOperator();
void T16_divideByDoubleOperator();
void T17_additionShorthandOperator();
void T18_subtractionShorthandOperator();
void T19_multiplyShorthandOperator();
void T20_multiplyByDoubleShorthandOperator();
void T21_divideShorthandOperator();
void T22_divideByDoubleShorthandOperator();
void T23_distance();
void T24_distanceSquared();
void T25_normalize();
void T26_normalized();
void T27_project();
void T28_outputOperator();
void T29_perpendicular();
void T30_rotate();
void T31_angle();
void T32_reflect();

int main()
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

	cout<<"All Tests Passed\n";
	return 0;
}

void T01_constructor()
{
	Vector2 test = Vector2();

	assert(test[0] == 0.0);

	assert(test[1] == 0.0);
}

void T02_constructorWithValues()
{
	Vector2 test = Vector2(5.5, 7.1);

	assert(test[0] == 5.5);

	assert(test[1] == 7.1);
}

void T03_copyConstructor()
{
	Vector2 test = Vector2(5.5, 7.1);

	Vector2 copy = Vector2(test);

	//make sure they have the right values
	assert(test[0] == 5.5);

	assert(test[1] == 7.1);

	assert(copy[0] == 5.5);

	assert(copy[1] == 7.1);

	//make sure each has its own memory
	assert(&test[0] != &copy[0]);

	assert(&test[1] != &copy[1]);
}

void T04_moveConstructor()
{
	Vector2 test = Vector2(5, 6);

	Vector2 moveHere(std::move(test));

	//make sure they have the righ tvalues
	assert(test[0] == 0.0);

	assert(test[1] == 0.0);

	assert(moveHere[0] == 5.0);

	assert(moveHere[1] == 6.0);
}

void T05_assignmentOperator()
{
	Vector2 test = Vector2(55, 10);

	Vector2 assigned = test;

	//make sure they have the righ tvalues
	assert(test[0] == 55.0);

	assert(test[1] == 10.0);

	assert(assigned[0] == 55.0);

	assert(assigned[1] == 10.0);

	//make sure each has its own memory
	assert(&test[0] != &assigned[0]);

	assert(&test[1] != &assigned[1]);
}

void T06_moveAssignmentOperator()
{
	Vector2 test = Vector2(5, 6);

	Vector2 moveAssignHere = std::move(test);

	//make sure they have the righ tvalues
	assert(test[0] == 0.0);

	assert(test[1] == 0.0);

	assert(moveAssignHere[0] == 5.0);

	assert(moveAssignHere[1] == 6.0);
}

void T07_additionOperator()
{
	Vector2 orig = Vector2(5, 10);

	Vector2 plus = Vector2(1, 2);

	Vector2 sum = orig + plus;

	assert(sum[0] == 6.0);

	assert(sum[1] ==  12.0);

	assert(&sum[0] != &orig[0]);

	assert(&sum[1] != &orig[1]);

	assert(&sum[0] != &plus[0]);

	assert(&sum[1] != &plus[1]);
}

void T08_subtractionOperator()
{
	Vector2 orig = Vector2(5, 10);

	Vector2 minus = Vector2(1, 2);

	Vector2 difference = orig - minus;

	assert(difference[0] == 4.0);

	assert(difference[1] == 8.0);

	assert(&difference[0] != &orig[0]);

	assert(&difference[1] != &orig[1]);

	assert(&difference[0] != &minus[0]);

	assert(&difference[1] != &minus[1]);
}

void T09_multiplyOperator()
{
	Vector2 orig = Vector2(5, 10);

	Vector2 times = Vector2(2, 2);

	Vector2 product = orig * times;

	assert(product[0] == 10.0);

	assert(product[1] == 20.0);

	assert(&product[0] != &orig[0]);

	assert(&product[1] != &orig[1]);

	assert(&product[0] != &times[0]);

	assert(&product[1] != &times[1]);
}

void T10_multiplyByDoubleOperator()
{
	Vector2 orig = Vector2(5, 10);

	double times = 2;

	Vector2 product = orig * times;

	assert(product[0] == 10.0);

	assert(product[1] == 20.0);

	assert(&product[0] != &orig[0]);

	assert(&product[1] != &orig[1]);
}

void T11_equivalenceOperators()
{
	Vector2 test = Vector2(50, 70);

	Vector2 test2 = Vector2(50, 70);

	Vector2 test3 = Vector2(50.0000000000000001, 70.0000000000000001);

	Vector2 test4 = Vector2(6, 7);

	assert(test == test2);

	assert(test == test3);

	assert(test != test4);
}

void T12_dotProduct()
{
	Vector2 orig = Vector2(5, 10);

	Vector2 dot = Vector2(2, 3);

	double product = orig.dot(dot);

	assert(product == 40.0);
}

void T13_magnitude()
{
	Vector2 test = Vector2(5, 10);

	double magnitude = test.magnitude();

	assert(magnitude > 11.1 && magnitude < 11.2);
}

void T14_magnitudeSquared()
{
	Vector2 test = Vector2(5, 10);

	double magnitudeSq = test.magnitudeSquared();

	assert(magnitudeSq == 125.0);
}

void T15_divideOperator()
{
	Vector2 orig = Vector2(6, 10);

	Vector2 divisor = Vector2(2, 5);

	Vector2 quotient = orig / divisor;

	assert(quotient[0] == 3.0);

	assert(quotient[1] == 2.0);

	assert(&quotient[0] != &orig[0]);

	assert(&quotient[1] != &orig[1]);

	assert(&quotient[0] != &divisor[0]);

	assert(&quotient[1] != &divisor[1]);
}

void T16_divideByDoubleOperator()
{
	Vector2 orig = Vector2(6, 10);

	double divisor = 2;

	Vector2 quotient = orig / divisor;

	assert(quotient[0] == 3.0);

	assert(quotient[1] == 5.0);

	assert(&quotient[0] != &orig[0]);

	assert(&quotient[1] != &orig[1]);
}

void T17_additionShorthandOperator()
{
	Vector2 orig = Vector2(5, 10);

	Vector2 plus = Vector2(1, 2);

	orig += plus;

	assert(orig[0] == 6.0);

	assert(orig[1] == 12.0);

	assert(&orig[0] != &plus[0]);

	assert(&orig[1] != &plus[1]);
}

void T18_subtractionShorthandOperator()
{
	Vector2 orig = Vector2(5, 10);

	Vector2 minus = Vector2(1, 2);

	orig -= minus;

	assert(orig[0] == 4.0);

	assert(orig[1] == 8.0);

	assert(&orig[0] != &minus[0]);

	assert(&orig[1] != &minus[1]);
}

void T19_multiplyShorthandOperator()
{
	Vector2 orig = Vector2(5, 10);

	Vector2 times = Vector2(2, 2);

	orig *= times;

	assert(orig[0] == 10.0);

	assert(orig[1] == 20.0);

	assert(&orig[0] != &times[0]);

	assert(&orig[1] != &times[1]);
}

void T20_multiplyByDoubleShorthandOperator()
{
	Vector2 orig = Vector2(5, 10);

	double times = 2;

	orig *= times;

	assert(orig[0] == 10.0);

	assert(orig[1] == 20.0);
}

void T21_divideShorthandOperator()
{
	Vector2 orig = Vector2(6, 10);

	Vector2 divisor = Vector2(2, 5);

	orig /= divisor;

	assert(orig[0] == 3.0);

	assert(orig[1] == 2.0);

	assert(&orig[0] != &divisor[0]);

	assert(&orig[1] != &divisor[1]);
}

void T22_divideByDoubleShorthandOperator()
{
	Vector2 orig = Vector2(6, 10);

	double divisor = 2;

	orig /= divisor;

	assert(orig[0] == 3.0);

	assert(orig[1] == 5.0);
}

void T23_distance()
{
	Vector2 test = Vector2(5, 10);

	Vector2 test2 = Vector2(7, 3);

	double distance = test.distance(test2);

	double alsoDistance = test2.distance(test);

	assert(distance == alsoDistance);

	assert(distance == sqrt(53.0));
}

void T24_distanceSquared()
{
	Vector2 test = Vector2(5, 10);

	Vector2 test2 = Vector2(7, 3);

	double distanceSquared = test.distanceSquared(test2);

	double alsoDistanceSquared = test2.distanceSquared(test);

	assert(distanceSquared == alsoDistanceSquared);

	assert(distanceSquared == 53.0);
}

void T25_normalize()
{
	Vector2 test = Vector2(0, 10);

	Vector2 test2 = Vector2(10, 0);

	Vector2 test3 = Vector2(10, 10);

	test.normalize();
	test2.normalize();

	assert(0.0 == test[0]);
	assert(1.0 == test[1]);

	assert(1.0 == test2[0]);
	assert(0.0 == test2[1]);

	double testNormal = (10.0 * 10.0) + (10.0 * 10.0);
	testNormal = sqrt(testNormal);
	testNormal = 1 / testNormal;
	Vector2 normalizedTest3 = test3 * testNormal;

	test3.normalize();

	assert(normalizedTest3 == test3);

	Vector2 test4 = Vector2(0, 0);

	try
	{
		test4.normalize();
		assert(false);
	}
	catch(std::logic_error e)
	{
		assert(true);
	}
}

void T26_normalized()
{
	Vector2 test = Vector2(0, 10);

	Vector2 test2 = Vector2(10, 0);

	Vector2 test3 = Vector2(10, 10);

	Vector2 testNormalized = test.normalized();
	Vector2 test2Normalized = test2.normalized();

	assert(0.0 == testNormalized[0]);
	assert(1.0 == testNormalized[1]);

	assert(1.0 == test2Normalized[0]);
	assert(0.0 == test2Normalized[1]);

	assert(&test[0] != &test2Normalized[0]);
	assert(&test2[0] != &test2Normalized[1]);

	double testNormal = (10.0 * 10.0) + (10.0 * 10.0);
	testNormal = sqrt(testNormal);
	testNormal = 1 / testNormal;
	Vector2 normalizedTest3 = test3 * testNormal;

	Vector2 test3Normalized = test3.normalized();

	assert(normalizedTest3 == test3Normalized);

	Vector2 test4 = Vector2(0, 0);

	try
	{
		Vector2 test4Normalized = test4.normalized();
		assert(false);
	}
	catch (std::logic_error e)
	{
		assert(true);
	}
}

void T27_project()
{
	Vector2 first = Vector2(5, 5);
	Vector2 second = Vector2(-3, 2);

	Vector2 projected = first.project(second);

	assert(15.0/13.0 == projected[0]);
	assert(-10.0/13.0 == projected[1]);
}

void T28_outputOperator()
{
	Vector2 test = Vector2(55, 703);

	std::stringstream out;

	out << test;

	std::string testText = "(55, 703)";

	assert(testText == out.str());
}

void T29_perpendicular()
{
	Vector2 first = Vector2(5, 5);
	Vector2 second = Vector2(-3, 2);

	Vector2 perpendicular = first.perpendicular(second);

	assert(3.84 < perpendicular[0]);
	assert(3.86 > perpendicular[0]);

	assert(5.75 < perpendicular[1]);
	assert(5.77 > perpendicular[1]);

	Vector2 test2 = Vector2(10.0, 0.0);
	Vector2 test3 = Vector2(5.0, 5.0);

	Vector2 perpendicular2 = test3.perpendicular(test2);

	assert(0.0 == perpendicular2[0]);
	assert(5.0 == perpendicular2[1]);

}

void T30_rotate()
{
	Vector2 test = Vector2(5, 5);

	Vector2 rotatedRight = test.rotate(-45.0);

	Vector2 rotatedLeft = test.rotate(45.0);

	assert(rotatedRight[1] < 1);
	assert(rotatedRight[1] >= 0);
	assert(rotatedLeft[0] < 1);
	assert(rotatedLeft[0] >= 0);
}

void T31_angle()
{
	Vector2 first = Vector2(5, 5);
	Vector2 second = Vector2(-5, 5);

	assert(90.0 == first.angle(second));

	Vector2 third = Vector2(2, 7);
	Vector2 fourth = Vector2(-4, -1);

	double testAngle2 = third.angle(fourth);

	assert(testAngle2 > 119.9);
	assert(testAngle2 < 120);
}

void T32_reflect()
{
	Vector2 right = Vector2(1, 0);

	Vector2 up = Vector2(0, 1);

	Vector2 reflectedLeft = right.reflect(up);

	Vector2 rotatedDown = up.reflect(right);

	assert(-1.0 == reflectedLeft[0]);
	assert(0.0 == reflectedLeft[1]); 
	assert(0.0 == rotatedDown[0]);
	assert(-1.0 == rotatedDown[1]);
}
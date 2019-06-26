//Cody Ware
//10/4/18

#include "../headers/Vector3Tests.h"

void Vector3Tests::runAllTests()
{
	T01_constructor();
	T02_constructorWithValues();
	T03_copyConstructor();
	T04_moveConstructor();
	T05_assignmentOperator();
	T06_moveAssignmentOperator();
	T07_additionOperator();
	T08_subtractionOperator();
	T09_multiply2Vector3sOperator();
	T10_multiplyVector3ByDouble();
	T11_equivalenceOperators();
	T12_dotProduct();
	T13_magnitude();
	T14_magnitudeSquared();
	T15_divide2Vector3sOperator();
	T16_divideVector3ByDoubleOperator();
	T17_additionShorthandOperator();
	T18_subtractionShorthandOperator();
	T19_multiply2Vector3sShorthandOperator();
	T20_multiplyVector3ByDoubleShorthandOperator();
	T21_divide2Vector3sShorthandOperator();
	T22_divideVector3ByDoubleShorthandOperator();
	T23_distance();
	T24_distanceSquared();
	T25_normalize();
	T26_normalized();
	T27_project();
	T28_outputOperator();
	T29_perpendicular();
	T30_angle();
	T31_reflect();
	T32_crossProduct();

	cout << "All Vector3 Tests Passed\n";
}

void Vector3Tests::T01_constructor()
{
	Vector3 test = Vector3();

	assert(test[0] == 0.0);

	assert(test[1] == 0.0);

	assert(test[2] == 0.0);
}

void Vector3Tests::T02_constructorWithValues()
{
	Vector3 test = Vector3(5.5, 7.1, 9.6);

	assert(test[0] == 5.5);

	assert(test[1] == 7.1);

	assert(test[2] == 9.6);
}

void Vector3Tests::T03_copyConstructor()
{
	Vector3 test = Vector3(5.5, 7.1, 9.6);

	Vector3 copy = Vector3(test);

	//make sure they have the right values
	assert(test[0] == 5.5);

	assert(test[1] == 7.1);

	assert(test[2] == 9.6);

	assert(copy[0] == 5.5);

	assert(copy[1] == 7.1);

	assert(copy[2] == 9.6);

	//make sure each has its own memory
	assert(&test[0] != &copy[0]);

	assert(&test[1] != &copy[1]);

	assert(&test[2] != &copy[2]);
}

void Vector3Tests::T04_moveConstructor()
{
	Vector3 test = Vector3(5, 6, 9);

	Vector3 moveHere(std::move(test));

	//make sure they have the righ tvalues
	assert(test[0] == 0.0);

	assert(test[1] == 0.0);

	assert(test[2] == 0.0);

	assert(moveHere[0] == 5.0);

	assert(moveHere[1] == 6.0);

	assert(moveHere[2] == 9.0);
}

void Vector3Tests::T05_assignmentOperator()
{
	Vector3 test = Vector3(55, 10, 6);

	Vector3 assigned = test;

	//make sure they have the righ tvalues
	assert(test[0] == 55.0);

	assert(test[1] == 10.0);

	assert(test[2] == 6.0);

	assert(assigned[0] == 55.0);

	assert(assigned[1] == 10.0);

	assert(assigned[2] == 6.0);

	//make sure each has its own memory
	assert(&test[0] != &assigned[0]);

	assert(&test[1] != &assigned[1]);

	assert(&test[2] != &assigned[2]);
}

void Vector3Tests::T06_moveAssignmentOperator()
{
	Vector3 test = Vector3(5, 6, 8);

	Vector3 moveAssignHere = std::move(test);

	//make sure they have the righ tvalues
	assert(test[0] == 0.0);

	assert(test[1] == 0.0);

	assert(test[2] == 0.0);

	assert(moveAssignHere[0] == 5.0);

	assert(moveAssignHere[1] == 6.0);

	assert(moveAssignHere[2] == 8.0);
}

void Vector3Tests::T07_additionOperator()
{
	Vector3 orig = Vector3(5, 10, 2);

	Vector3 plus = Vector3(1, 2, 25);

	Vector3 sum = orig + plus;

	assert(sum[0] == 6.0);

	assert(sum[1] == 12.0);

	assert(sum[2] == 27.0);

	assert(&sum[0] != &orig[0]);

	assert(&sum[1] != &orig[1]);

	assert(&sum[2] != &orig[2]);

	assert(&sum[0] != &plus[0]);

	assert(&sum[1] != &plus[1]);

	assert(&sum[2] != &plus[2]);
}

void Vector3Tests::T08_subtractionOperator()
{
	Vector3 orig = Vector3(5, 10, 6);

	Vector3 minus = Vector3(1, 2, 3);

	Vector3 difference = orig - minus;

	assert(difference[0] == 4.0);

	assert(difference[1] == 8.0);

	assert(difference[2] == 3.0);

	assert(&difference[0] != &orig[0]);

	assert(&difference[1] != &orig[1]);

	assert(&difference[2] != &orig[2]);

	assert(&difference[0] != &minus[0]);

	assert(&difference[1] != &minus[1]);

	assert(&difference[2] != &minus[2]);
}

void Vector3Tests::T09_multiply2Vector3sOperator()
{
	Vector3 orig = Vector3(5, 10, 15);

	Vector3 times = Vector3(2, 3, 1);

	Vector3 product = orig * times;

	assert(product[0] == 10.0);

	assert(product[1] == 30.0);

	assert(product[2] == 15.0);

	assert(&product[0] != &orig[0]);

	assert(&product[1] != &orig[1]);

	assert(&product[2] != &orig[2]);

	assert(&product[0] != &times[0]);

	assert(&product[1] != &times[1]);

	assert(&product[2] != &times[2]);
}

void Vector3Tests::T10_multiplyVector3ByDouble()
{
	Vector3 orig = Vector3(5, 10, 6);

	double times = 2;

	Vector3 product = orig * times;

	assert(product[0] == 10.0);

	assert(product[1] == 20.0);

	assert(product[2] == 12.0);

	assert(&product[0]!= &orig[0]);

	assert(&product[1]!= &orig[1]);

	assert(&product[2]!= &orig[2]);
}

void Vector3Tests::T11_equivalenceOperators()
{
	Vector3 test = Vector3(50, 70, 60);

	Vector3 test2 = Vector3(50, 70, 60);

	Vector3 test3 = Vector3(50.0000000000000001, 70.0000000000000001, 60.0000000000000001);

	Vector3 test4 = Vector3(6, 7, 11);

	assert(test == test2);

	assert(test == test3);

	assert(test != test4);
}

void Vector3Tests::T12_dotProduct()
{
	Vector3 orig = Vector3(5, 10, 3);

	Vector3 dot = Vector3(2, 3, 4);

	double product = orig.dot(dot);

	assert(product == 52.0);
}

void Vector3Tests::T13_magnitude()
{
	Vector3 test = Vector3(5, 10, 12);

	double magnitude = test.magnitude();

	assert(magnitude == sqrt(269));
}

void Vector3Tests::T14_magnitudeSquared()
{
	Vector3 test = Vector3(5, 10, 12);

	double magnitudeSq = test.magnitudeSquared();

	assert(magnitudeSq == 269.0);
}

void Vector3Tests::T15_divide2Vector3sOperator()
{
	Vector3 orig = Vector3(6, 10, 9);

	Vector3 divisor = Vector3(2, 5, 3);

	Vector3 quotient = orig / divisor;

	assert(quotient[0] == 3.0);

	assert(quotient[1] == 2.0); 

	assert(quotient[2] == 3.0);

	assert(&quotient[0] != &orig[0]);

	assert(&quotient[1] != &orig[1]);

	assert(&quotient[2] != &orig[2]);

	assert(&quotient[0] != &divisor[0]);

	assert(&quotient[1] != &divisor[1]);

	assert(&quotient[2] != &divisor[2]);
}

void Vector3Tests::T16_divideVector3ByDoubleOperator()
{
	Vector3 orig = Vector3(6, 10, 15);

	double divisor = 2;

	Vector3 quotient = orig / divisor;

	assert(quotient[0] == 3.0);

	assert(quotient[1] == 5.0);

	assert(quotient[2] == 7.5);

	assert(&quotient[0] != &orig[0]);

	assert(&quotient[1] != &orig[1]);

	assert(&quotient[2] != &orig[2]);
}

void Vector3Tests::T17_additionShorthandOperator()
{
	Vector3 orig = Vector3(5, 10, 19);

	Vector3 plus = Vector3(1, 2, 1);

	orig += plus;

	assert(orig[0] == 6.0);

	assert(orig[1] == 12.0);

	assert(orig[2] == 20.0);

	assert(&orig[0] != &plus[0]);

	assert(&orig[1] != &plus[1]);

	assert(&orig[2] != &plus[2]);
}

void Vector3Tests::T18_subtractionShorthandOperator()
{
	Vector3 orig = Vector3(5, 10, 25);

	Vector3 minus = Vector3(1, 2, 5);

	orig -= minus;

	assert(orig[0] == 4.0);

	assert(orig[1] == 8.0);

	assert(orig[2] == 20.0);

	assert(&orig[0] != &minus[0]);

	assert(&orig[1] != &minus[1]);

	assert(&orig[2] != &minus[2]);
}

void Vector3Tests::T19_multiply2Vector3sShorthandOperator()
{
	Vector3 orig = Vector3(5, 10, 15);

	Vector3 times = Vector3(2, 2, 2);

	orig *= times;

	assert(orig[0] == 10.0);

	assert(orig[1] == 20.0);

	assert(orig[2] == 30.0);

	assert(&orig[0] != &times[0]);

	assert(&orig[1] != &times[1]);

	assert(&orig[2] != &times[2]);
}

void Vector3Tests::T20_multiplyVector3ByDoubleShorthandOperator()
{
	Vector3 orig = Vector3(5, 10, 30);

	double times = 2;

	orig *= times;

	assert(orig[0] == 10.0);

	assert(orig[1] == 20.0);

	assert(orig[2] == 60.0);
}

void Vector3Tests::T21_divide2Vector3sShorthandOperator()
{
	Vector3 orig = Vector3(6, 10, 9);

	Vector3 divisor = Vector3(2, 5, 3);

	orig /= divisor;

	assert(orig[0] == 3.0);

	assert(orig[1] == 2.0);

	assert(orig[2] == 3.0);

	assert(&orig[0] != &divisor[0]);

	assert(&orig[1] != &divisor[1]);

	assert(&orig[2] != &divisor[2]);
}

void Vector3Tests::T22_divideVector3ByDoubleShorthandOperator()
{
	Vector3 orig = Vector3(6, 10, 20);

	double divisor = 2;

	orig /= divisor;

	assert(orig[0] == 3.0);

	assert(orig[1] == 5.0);

	assert(orig[2] == 10.0);
}

void Vector3Tests::T23_distance()
{
	Vector3 test = Vector3(5, 10, 20);

	Vector3 test2 = Vector3(7, 3, 6);

	double distance = test.distance(test2);

	double alsoDistance = test2.distance(test);

	assert(distance == alsoDistance);

	assert(distance == sqrt(249.0));
}

void Vector3Tests::T24_distanceSquared()
{
	Vector3 test = Vector3(5, 10, 20);

	Vector3 test2 = Vector3(7, 3, 6);

	double distance = test.distanceSquared(test2);

	double alsoDistance = test2.distanceSquared(test);

	assert(distance == alsoDistance);

	assert(distance == 249.0);
}

void Vector3Tests::T25_normalize()
{
	Vector3 test = Vector3(0, 10, 0);

	Vector3 test2 = Vector3(10, 0, 0);

	Vector3 test3 = Vector3(0, 0, 10);

	Vector3 test4 = Vector3(4, 6, 8);

	test.normalize();
	test2.normalize();
	test3.normalize();
	test4.normalize();

	assert(0.0 == test[0]);
	assert(1.0 == test[1]);
	assert(0.0 == test[2]);

	assert(1.0 == test2[0]);
	assert(0.0 == test2[1]);
	assert(0.0 == test2[2]);

	assert(0.0 == test3[0]);
	assert(0.0 == test3[1]);
	assert(1.0 == test3[2]);

	assert(0.371 < test4[0]);
	assert(0.557 < test4[1]);
	assert(0.742 < test4[2]);
	assert(0.372 > test4[0]);
	assert(0.558 > test4[1]);
	assert(0.743 > test4[2]);


	Vector3 test5 = Vector3(0, 0, 0);

	try
	{
		test5.normalize();
		assert(false);
	}
	catch (std::logic_error e)
	{
		assert(true);
	}
}

void Vector3Tests::T26_normalized()
{
	Vector3 test = Vector3(0, 10, 0);

	Vector3 test2 = Vector3(10, 0, 0);

	Vector3 test3 = Vector3(0, 0, 10);

	Vector3 test4 = Vector3(4, 6, 8);

	Vector3 test1Normalized = test.normalized();
	Vector3 test2Normalized = test2.normalized();
	Vector3 test3Normalized = test3.normalized();
	Vector3 test4Normalized = test4.normalized();

	assert(0.0 == test1Normalized[0]);
	assert(1.0 == test1Normalized[1]);
	assert(0.0 == test1Normalized[2]);

	assert(1.0 == test2Normalized[0]);
	assert(0.0 == test2Normalized[1]);
	assert(0.0 == test2Normalized[2]);

	assert(0.0 == test3Normalized[0]);
	assert(0.0 == test3Normalized[1]);
	assert(1.0 == test3Normalized[2]);

	assert(0.371 < test4Normalized[0]);
	assert(0.557 < test4Normalized[1]);
	assert(0.742 < test4Normalized[2]);
	assert(0.372 > test4Normalized[0]);
	assert(0.558 > test4Normalized[1]);
	assert(0.743 > test4Normalized[2]);


	Vector3 test5 = Vector3(0, 0, 0);

	try
	{
		test5.normalized();
		assert(false);
	}
	catch (std::logic_error e)
	{
		assert(true);
	}
}

void Vector3Tests::T27_project()
{
		Vector3 first = Vector3(3, 4, -3);
		Vector3 second = Vector3(2,0,6);

		Vector3 projected = second.project(first);

		assert(-18.0 / 17.0 == projected[0]);
		assert(-24.0 / 17.0 == projected[1]);
		assert(18.0 / 17.0 == projected[2]);
}

void Vector3Tests::T28_outputOperator()
{
	Vector3 test = Vector3(55, 703, 5.5);

	std::stringstream out;

	out << test;

	std::string testText = "(55, 703, 5.5)";

	assert(testText == out.str());
}

void Vector3Tests::T29_perpendicular()
{
		Vector3 first = Vector3(5, 5, 11);
		Vector3 second = Vector3(-3, 2, 8);

		Vector3 perpendicular = first.perpendicular(second);

		assert(8.3 > perpendicular[0]);
		assert(8.2 < perpendicular[0]);

		assert(2.9 > perpendicular[1]);
		assert(2.8 < perpendicular[1]);

		assert(2.4 > perpendicular[2]);
		assert(2.3 < perpendicular[2]);

		Vector3 test2 = Vector3(10.0, 0.0, 0.0);
		Vector3 test3 = Vector3(5.0, 5.0, 5.0);

		Vector3 perpendicular2 = test3.perpendicular(test2);

		assert(0.0 == perpendicular2[0]);
		assert(5.0 == perpendicular2[1]);
		assert(5.0 == perpendicular2[2]);
}

void Vector3Tests::T30_angle()
{
		Vector3 first = Vector3(5, 5, 5);
		Vector3 second = Vector3(-5, 5, 5);

		double test1 = first.angle(second);

		assert(70.52877 < test1);
		assert(70.52878 > test1);

		Vector3 third = Vector3(2, 7, 3);
		Vector3 fourth = Vector3(-4, -1 , -3);

		double test2 = third.angle(fourth);

		assert(126.70982 < test2);
		assert(126.70983 > test2);
}

void Vector3Tests::T31_reflect()
{
	Vector3 a = Vector3(5, 0, 5);

	Vector3 b = Vector3(0, 5, 0);

	Vector3 ab = a.reflect(b);

	Vector3 ba = b.reflect(a);

		assert(-5.0 == ab[0]);
		assert(0.0 == ab[1]);
		assert(-5.0 == ab[2]);
		assert(0.0 == ba[0]);
		assert(-5.0 == ba[1]);
		assert(0.0 == ba[2]);
}

void Vector3Tests::T32_crossProduct()
{
	Vector3 right = Vector3(5, 0, 0);
	Vector3 up = Vector3(0, 5, 0);
	Vector3 into = Vector3(0, 0, 25);

	assert(into[0] == right.crossProduct(up)[0]);
	assert(into[1] == right.crossProduct(up)[1]);
	assert(into[2] == right.crossProduct(up)[2]);

}
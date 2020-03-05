////Cody Ware
////6/30/19
//
//#include "PointTests.h"
//
//void PointTests::runAllTests()
//{
//	//test 2d
//	T01_constructor2D();
//	T02_constructorWithValues2D();
//	T03_copyConstructor2D();
//	T04_moveConstructor2D();
//	T05_assignmentOperator2D();
//	T06_moveAssignmentOperator2D();
//	T07_additionOperator2D();
//	T08_subtractionOperator2D();
//	T09_multiplyOperator2D();
//	T10_multiplyByDoubleOperator2D();
//	T11_equivalenceOperators2D();
//	T12_dotProduct2D();
//	T13_magnitude2D();
//	T14_magnitudeSquared2D();
//	T15_divideOperator2D();
//	T16_divideByDoubleOperator2D();
//	T17_additionShorthandOperator2D();
//	T18_subtractionShorthandOperator2D();
//	T19_multiplyShorthandOperator2D();
//	T20_multiplyByDoubleShorthandOperator2D();
//	T21_divideShorthandOperator2D();
//	T22_divideByDoubleShorthandOperator2D();
//	T23_distance2D();
//	T24_distanceSquared2D();
//	T25_normalize2D();
//	T26_normalized2D();
//	T27_project2D();
//	T28_outputOperator2D();
//	T29_perpendicular2D();
//	T30_rotate2D();
//	T31_angle2D();
//	T32_reflect2D();
//
//	//test 3d
//	T33_constructor3D();
//	T34_constructorWithValues3D();
//	T35_copyConstructor3D();
//	T36_moveConstructor3D();
//	T37_assignmentOperator3D();
//	T38_moveAssignmentOperator3D();
//	T39_additionOperator3D();
//	T40_subtractionOperator3D();
//	T41_multiply2Vector3sOperator3D();
//	T42_multiplyVector3ByDouble3D();
//	T43_equivalenceOperators3D();
//	T44_dotProduct3D();
//	T45_magnitude3D();
//	T46_magnitudeSquared3D();
//	T47_divide2Vector3sOperator3D();
//	T48_divideVector3ByDoubleOperator3D();
//	T49_additionShorthandOperator3D();
//	T50_subtractionShorthandOperator3D();
//	T51_multiply2Vector3sShorthandOperator3D();
//	T52_multiplyVector3ByDoubleShorthandOperator3D();
//	T53_divide2Vector3sShorthandOperator3D();
//	T54_divideVector3ByDoubleShorthandOperator3D();
//	T55_distance3D();
//	T56_distanceSquared3D();
//	T57_normalize3D();
//	T58_normalized3D();
//	T59_project3D();
//	T60_outputOperator3D();
//	T61_perpendicular3D();
//	T62_angle3D();
//	T63_reflect3D();
//	T64_crossProduct3D();
//
//	cout << "Passed: All Point Tests\n";
//}
//
//void PointTests::T01_constructor2D()
//{
//	double* values = new double[2];
//	values[0] = 0.0;
//	values[1] = 0.0;
//
//	Point test(values, 2);
//
//	assert(test[0] == 0.0, "T01_constructor failed");
//
//	assert(test[1] == 0.0, "T01_constructor failed");
//}
//
//void PointTests::T02_constructorWithValues2D()
//{
//	double* values = new double[2];
//	values[0] = 5.5;
//	values[1] = 7.1;
//
//	Point test(values, 2);
//
//	assert(test[0] == 5.5, "T02_constructorWithValues");
//
//	assert(test[1] == 7.1, "T02_constructorWithValues");
//}
//
//void PointTests::T03_copyConstructor2D()
//{
//	double* values = new double[2];
//	values[0] = 5.5;
//	values[1] = 7.1;
//
//	Point test(values, 2);
//
//	Point copy(test);
//
//	//make sure they have the right values
//	assert(test[0] == 5.5, "T03_copyConstructor");
//
//	assert(test[1] == 7.1, "T03_copyConstructor");
//
//	assert(copy[0] == 5.5, "T03_copyConstructor");
//
//	assert(copy[1] == 7.1, "T03_copyConstructor");
//
//	//make sure each has its own memory
//	assert(&test[0] != &copy[0], "T03_copyConstructor");
//
//	assert(&test[1] != &copy[1], "T03_copyConstructor");
//}
//
//void PointTests::T04_moveConstructor2D()
//{
//	double* values = new double[2];
//	values[0] = 5.0;
//	values[1] = 6.0;
//
//	Point test(values, 2);
//
//	Point moveHere(std::move(test));
//
//	//make sure they have the righ tvalues
//	assert(test.getNumberOfDimensions() == 0, "T04_moveConstructor");
//
//	assert(moveHere[0] == 5.0, "T04_moveConstructor");
//
//	assert(moveHere[1] == 6.0, "T04_moveConstructor");
//}
//
//void PointTests::T05_assignmentOperator2D()
//{
//	double* values = new double[2];
//	values[0] = 55;
//	values[1] = 10;
//
//	Point test(values, 2);
//
//	Point assigned = test;
//
//	//make sure they have the righ tvalues
//	assert(test[0] == 55.0, "T05_assignmentOperator");
//
//	assert(test[1] == 10.0, "T05_assignmentOperator");
//
//	assert(assigned[0] == 55.0, "T05_assignmentOperator");
//
//	assert(assigned[1] == 10.0, "T05_assignmentOperator");
//
//	//make sure each has its own memory
//	assert(&test[0] != &assigned[0], "T05_assignmentOperator");
//
//	assert(&test[1] != &assigned[1], "T05_assignmentOperator");
//}
//
//void PointTests::T06_moveAssignmentOperator2D()
//{
//	double* values = new double[2];
//	values[0] = 5;
//	values[1] = 6;
//
//	Point test(values, 2);
//
//	Point moveAssignHere = std::move(test);
//
//	//make sure they have the righ tvalues
//	assert(test.getNumberOfDimensions() == 0.0, "T06_moveAssignmentOperator");
//
//	assert(moveAssignHere[0] == 5.0, "T06_moveAssignmentOperator");
//
//	assert(moveAssignHere[1] == 6.0, "T06_moveAssignmentOperator");
//}
//
//void PointTests::T07_additionOperator2D()
//{
//	double* values = new double[2];
//	values[0] = 5;
//	values[1] = 10;
//
//	Point orig(values, 2);
//
//	double* values2 = new double[2];
//	values2[0] = 1;
//	values2[1] = 2;
//
//	Point plus(values2, 2);
//
//	Point sum = orig + plus;
//
//	assert(sum[0] == 6.0, "T07_additionOperator 1");
//
//	assert(sum[1] == 12.0, "T07_additionOperator 2");
//
//	assert(&sum[0] != &orig[0], "T07_additionOperator 3");
//
//	assert(&sum[1] != &orig[1], "T07_additionOperator 4");
//
//	assert(&sum[0] != &plus[0], "T07_additionOperator 5");
//
//	assert(&sum[1] != &plus[1], "T07_additionOperator 6");
//}
//
//void PointTests::T08_subtractionOperator2D()
//{
//	double* values = new double[2];
//	values[0] = 5;
//	values[1] = 10;
//
//	Point orig(values, 2);
//
//	double* values2 = new double[2];
//	values2[0] = 1;
//	values2[1] = 2;
//
//	Point minus(values2, 2);
//
//	Point difference = orig - minus;
//
//	assert(difference[0] == 4.0, "T08_subtractionOperator");
//
//	assert(difference[1] == 8.0, "T08_subtractionOperator");
//
//	assert(&difference[0] != &orig[0], "T08_subtractionOperator");
//
//	assert(&difference[1] != &orig[1], "T08_subtractionOperator");
//
//	assert(&difference[0] != &minus[0], "T08_subtractionOperator");
//
//	assert(&difference[1] != &minus[1], "T08_subtractionOperator");
//}
//
//void PointTests::T09_multiplyOperator2D()
//{
//	double* values = new double[2];
//	values[0] = 5;
//	values[1] = 10;
//
//	Point orig(values, 2);
//
//	double* values2 = new double[2];
//	values2[0] = 2;
//	values2[1] = 2;
//
//	Point times(values2, 2);
//
//	Point product = orig * times;
//
//	assert(product[0] == 10.0, "T09_multiplyOperator");
//
//	assert(product[1] == 20.0, "T09_multiplyOperator");
//
//	assert(&product[0] != &orig[0], "T09_multiplyOperator");
//
//	assert(&product[1] != &orig[1], "T09_multiplyOperator");
//
//	assert(&product[0] != &times[0], "T09_multiplyOperator");
//
//	assert(&product[1] != &times[1], "T09_multiplyOperator");
//}
//
//void PointTests::T10_multiplyByDoubleOperator2D()
//{
//	double* values = new double[2];
//	values[0] = 5;
//	values[1] = 10;
//
//	Point orig(values, 2);
//
//	double times = 2;
//
//	Point product = orig * times;
//
//	assert(product[0] == 10.0, "T10_multiplyByDoubleOperator");
//
//	assert(product[1] == 20.0, "T10_multiplyByDoubleOperator");
//
//	assert(&product[0] != &orig[0], "T10_multiplyByDoubleOperator");
//
//	assert(&product[1] != &orig[1], "T10_multiplyByDoubleOperator");
//}
//
//void PointTests::T11_equivalenceOperators2D()
//{
//	double* values = new double[2];
//	values[0] = 50;
//	values[1] = 70;
//
//	Point test(values, 2);
//
//	double* values2 = new double[2];
//	values2[0] = 50;
//	values2[1] = 70;
//
//	Point test2(values2, 2);
//
//	double* values3 = new double[2];
//	values3[0] = 50.0000000000000001;
//	values3[1] = 70.0000000000000001;
//
//	Point test3(values3, 2);
//
//	double* values4 = new double[2];
//	values4[0] = 6;
//	values4[1] = 7;
//
//	Point test4(values4, 2);
//
//	assert(test == test2, "T11_equivalenceOperators 1");
//
//	assert(test == test3, "T11_equivalenceOperators 2");
//
//	assert(test != test4, "T11_equivalenceOperators 3");
//}
//
//void PointTests::T12_dotProduct2D()
//{
//	double* values = new double[2];
//	values[0] = 5;
//	values[1] = 10;
//
//	Point orig(values, 2);
//
//	double* values2 = new double[2];
//	values2[0] = 2;
//	values2[1] = 3;
//
//	Point dot(values2, 2);
//
//	double product = orig.dot(dot);
//
//	assert(product == 40.0, "T12_dotProduct");
//}
//
//void PointTests::T13_magnitude2D()
//{
//	double* values = new double[2];
//	values[0] = 5;
//	values[1] = 10;
//
//	Point test(values, 2);
//
//	double magnitude = test.magnitude();
//
//	assert(magnitude > 11.1 && magnitude < 11.2, "T13_magnitude");
//}
//
//void PointTests::T14_magnitudeSquared2D()
//{
//	double* values = new double[2];
//	values[0] = 5;
//	values[1] = 10;
//
//	Point test(values, 2);
//
//	double magnitudeSq = test.magnitudeSquared();
//
//	assert(magnitudeSq == 125.0, "T14_magnitudeSquared");
//}
//
//void PointTests::T15_divideOperator2D()
//{
//	double* values = new double[2];
//	values[0] = 6;
//	values[1] = 10;
//
//	Point orig(values, 2);
//
//	double* values2 = new double[2];
//	values2[0] = 2;
//	values2[1] = 5;
//
//	Point divisor(values2, 2);
//
//	Point quotient = orig / divisor;
//
//	assert(quotient[0] == 3.0, "T15_divideOperator");
//
//	assert(quotient[1] == 2.0, "T15_divideOperator");
//
//	assert(&quotient[0] != &orig[0], "T15_divideOperator");
//
//	assert(&quotient[1] != &orig[1], "T15_divideOperator");
//
//	assert(&quotient[0] != &divisor[0], "T15_divideOperator");
//
//	assert(&quotient[1] != &divisor[1], "T15_divideOperator");
//}
//
//void PointTests::T16_divideByDoubleOperator2D()
//{
//	double* values = new double[2];
//	values[0] = 6;
//	values[1] = 10;
//
//	Point orig(values, 2);
//
//	double divisor = 2;
//
//	Point quotient = orig / divisor;
//
//	assert(quotient[0] == 3.0, "T16_divideByDoubleOperator");
//
//	assert(quotient[1] == 5.0, "T16_divideByDoubleOperator");
//
//	assert(&quotient[0] != &orig[0], "T16_divideByDoubleOperator");
//
//	assert(&quotient[1] != &orig[1], "T16_divideByDoubleOperator");
//}
//
//void PointTests::T17_additionShorthandOperator2D()
//{
//	double* values = new double[2];
//	values[0] = 5;
//	values[1] = 10;
//
//	Point orig(values, 2);
//
//	double* values2 = new double[2];
//	values2[0] = 1;
//	values2[1] = 2;
//
//	Point plus(values2, 2);
//
//	orig += plus;
//
//	assert(orig[0] == 6.0, "T17_additionShorthandOperator");
//
//	assert(orig[1] == 12.0, "T17_additionShorthandOperator");
//
//	assert(&orig[0] != &plus[0], "T17_additionShorthandOperator");
//
//	assert(&orig[1] != &plus[1], "T17_additionShorthandOperator");
//}
//
//void PointTests::T18_subtractionShorthandOperator2D()
//{
//	double* values = new double[2];
//	values[0] = 5;
//	values[1] = 10;
//
//	Point orig(values, 2);
//
//	double* values2 = new double[2];
//	values2[0] = 1;
//	values2[1] = 2;
//
//	Point minus(values2, 2);
//
//	orig -= minus;
//
//	assert(orig[0] == 4.0, "T18_subtractionShorthandOperator");
//
//	assert(orig[1] == 8.0, "T18_subtractionShorthandOperator");
//
//	assert(&orig[0] != &minus[0], "T18_subtractionShorthandOperator");
//
//	assert(&orig[1] != &minus[1], "T18_subtractionShorthandOperator");
//}
//
//void PointTests::T19_multiplyShorthandOperator2D()
//{
//	double* values = new double[2];
//	values[0] = 5;
//	values[1] = 10;
//
//	Point orig(values, 2);
//
//	double* values2 = new double[2];
//	values2[0] = 2;
//	values2[1] = 2;
//
//	Point times(values2, 2);
//
//	orig *= times;
//
//	assert(orig[0] == 10.0, "T19_multiplyShorthandOperator 1");
//
//	assert(orig[1] == 20.0, "T19_multiplyShorthandOperator 2");
//
//	assert(&orig[0] != &times[0], "T19_multiplyShorthandOperator 3");
//
//	assert(&orig[1] != &times[1], "T19_multiplyShorthandOperator 4");
//}
//
//void PointTests::T20_multiplyByDoubleShorthandOperator2D()
//{
//	double* values = new double[2];
//	values[0] = 5;
//	values[1] = 10;
//
//	Point orig(values, 2);
//
//	double times = 2;
//
//	orig *= times;
//
//	assert(orig[0] == 10.0, "T20_multiplyByDoubleShorthandOperator 1");
//
//	assert(orig[1] == 20.0, "T20_multiplyByDoubleShorthandOperator 2");
//}
//
//void PointTests::T21_divideShorthandOperator2D()
//{
//	double* values = new double[2];
//	values[0] = 6;
//	values[1] = 10;
//
//	Point orig(values, 2);
//
//	double* values2 = new double[2];
//	values2[0] = 2;
//	values2[1] = 5;
//
//	Point divisor(values2, 2);
//
//	orig /= divisor;
//
//	assert(orig[0] == 3.0, "T21_divideShorthandOperator");
//
//	assert(orig[1] == 2.0, "T21_divideShorthandOperator");
//
//	assert(&orig[0] != &divisor[0], "T21_divideShorthandOperator");
//
//	assert(&orig[1] != &divisor[1], "T21_divideShorthandOperator");
//}
//
//void PointTests::T22_divideByDoubleShorthandOperator2D()
//{
//	double* values = new double[2];
//	values[0] = 6;
//	values[1] = 10;
//
//	Point orig(values, 2);
//
//	double divisor = 2;
//
//	orig /= divisor;
//
//	assert(orig[0] == 3.0, "T22_divideByDoubleShorthandOperator 1");
//
//	assert(orig[1] == 5.0, "T22_divideByDoubleShorthandOperator 2");
//}
//
//void PointTests::T23_distance2D()
//{
//	double* values = new double[2];
//	values[0] = 5;
//	values[1] = 10;
//
//	Point test(values, 2);
//
//	double* values2 = new double[2];
//	values2[0] = 7;
//	values2[1] = 2;
//
//	Point test2(values2, 2);
//
//	double distance = test.distance(test2);
//
//	double alsoDistance = test2.distance(test);
//
//	const double shouldBeThis = 8.2462112512353212;
//
//	assert(distance == alsoDistance, "T23_distance2D");
//
//	assert(distance == shouldBeThis, "T23_distance2D");
//}
//
//void PointTests::T24_distanceSquared2D()
//{
//	double* values = new double[2];
//	values[0] = 5;
//	values[1] = 10;
//
//	Point test(values, 2);
//
//	double* values2 = new double[2];
//	values2[0] = 7;
//	values2[1] = 3;
//
//	Point test2(values2, 2);
//
//	double distanceSquared = test.distanceSquared(test2);
//
//	double alsoDistanceSquared = test2.distanceSquared(test);
//
//	assert(distanceSquared == alsoDistanceSquared, "T24_distanceSquared");
//
//	assert(distanceSquared == 53.0, "T24_distanceSquared");
//}
//
//void PointTests::T25_normalize2D()
//{
//	double* values = new double[2];
//	values[0] = 0;
//	values[1] = 10;
//
//	Point test(values, 2);
//
//	double* values2 = new double[2];
//	values2[0] = 10;
//	values2[1] = 0;
//
//	Point test2(values2, 2);
//
//	double* values3 = new double[2];
//	values3[0] = 10;
//	values3[1] = 10;
//
//	Point test3(values3, 2);
//
//	test.normalize();
//	test2.normalize();
//
//	assert(0.0 == test[0], "T25_normalize2D 1");
//	assert(1.0 == test[1], "T25_normalize2D 2");
//
//	assert(1.0 == test2[0], "T25_normalize2D 3");
//	assert(0.0 == test2[1], "T25_normalize2D 4");
//
//	double testNormal = (10.0 * 10.0) + (10.0 * 10.0);
//	testNormal = sqrt(testNormal);
//	testNormal = 1 / testNormal;
//	Point normalizedTest3 = test3 * testNormal;
//
//	test3.normalize();
//
//	assert(normalizedTest3 == test3, "T25_normalize2D 5");
//
//	Point test4 = Point(0, 0);
//
//	try
//	{
//		test4.normalize();
//		assert(false, "T25_normalize2D 6");
//	}
//	catch (std::logic_error e)
//	{
//		assert(true, "T25_normalize2D 7");
//	}
//}
//
//void PointTests::T26_normalized2D()
//{
//	Point test = Point();
//	test.addDimension(0);
//	test.addDimension(10);
//
//	Point test2 = Point();
//	test2.addDimension(10);
//	test2.addDimension(0);
//
//	Point test3 = Point();
//	test3.addDimension(10);
//	test3.addDimension(10);
//
//	Point testNormalized = test.normalized();
//	Point test2Normalized = test2.normalized();
//
//	assert(0.0 == testNormalized[0], "T26_normalized");
//	assert(1.0 == testNormalized[1], "T26_normalized");
//
//	assert(1.0 == test2Normalized[0], "T26_normalized");
//	assert(0.0 == test2Normalized[1], "T26_normalized");
//
//	assert(&test[0] != &test2Normalized[0], "T26_normalized");
//	assert(&test2[0] != &test2Normalized[1], "T26_normalized");
//
//	double testNormal = (10.0 * 10.0) + (10.0 * 10.0);
//	testNormal = sqrt(testNormal);
//	testNormal = 1 / testNormal;
//	Point normalizedTest3 = test3 * testNormal;
//
//	Point test3Normalized = test3.normalized();
//
//	assert(normalizedTest3 == test3Normalized, "T26_normalized");
//
//	Point test4 = Point(0, 0);
//
//	try
//	{
//		Point test4Normalized = test4.normalized();
//		assert(false, "T26_normalized");
//	}
//	catch (std::logic_error e)
//	{
//		assert(true, "T26_normalized");
//	}
//}
//
//void PointTests::T27_project2D()
//{
//	Point first = Point();
//	first.addDimension(5);
//	first.addDimension(5);
//
//	Point second = Point();
//	second.addDimension(-3);
//	second.addDimension(2);
//
//	Point projected = first.project(second);
//
//	assert(15.0 / 13.0 == projected[0], "T27_project");
//	assert(-10.0 / 13.0 == projected[1], "T27_project");
//}
//
//void PointTests::T28_outputOperator2D()
//{
//	Point test = Point();
//	test.addDimension(55);
//	test.addDimension(703);
//
//	std::stringstream out;
//
//	out << test;
//
//	std::string testText = "(55, 703)";
//
//	assert(testText == out.str(), "T28_outputOperator");
//}
//
//void PointTests::T29_perpendicular2D()
//{
//	Point first = Point();
//	first.addDimension(5);
//	first.addDimension(5);
//
//	Point second = Point();
//	second.addDimension(-3);
//	second.addDimension(2);
//
//	Point perpendicular = first.perpendicular(second);
//
//	assert(3.84 < perpendicular[0], "T29_perpendicular");
//	assert(3.86 > perpendicular[0], "T29_perpendicular");
//
//	assert(5.75 < perpendicular[1], "T29_perpendicular");
//	assert(5.77 > perpendicular[1], "T29_perpendicular");
//
//	Point test2 = Point();
//	test2.addDimension(10.0);
//	test2.addDimension(0.0);
//
//	Point test3 = Point();
//	test3.addDimension(5.0);
//	test3.addDimension(5.0);
//
//	Point perpendicular2 = test3.perpendicular(test2);
//
//	assert(0.0 == perpendicular2[0], "T29_perpendicular");
//	assert(5.0 == perpendicular2[1], "T29_perpendicular");
//
//}
//
//void PointTests::T30_rotate2D()
//{
//	Point test = Point();
//	test.addDimension(5);
//	test.addDimension(5);
//
//	Point rotatedRight = test.rotate2D(-45.0);
//
//	Point rotatedLeft = test.rotate2D(45.0);
//
//	assert(rotatedRight[1] < 1, "T30_rotate");
//	assert(rotatedRight[1] >= 0, "T30_rotate");
//	assert(rotatedLeft[0] < 1, "T30_rotate");
//	assert(rotatedLeft[0] >= 0, "T30_rotate");
//}
//
//void PointTests::T31_angle2D()
//{
//	Point first = Point();
//	first.addDimension(5);
//	first.addDimension(5);
//
//	Point second = Point();
//	second.addDimension(-5);
//	second.addDimension(5);
//
//	assert(90.0 == first.angle(second), "T31_angle");
//
//	Point third = Point();
//	third.addDimension(2);
//	third.addDimension(7);
//
//	Point fourth = Point();
//	fourth.addDimension(-4);
//	fourth.addDimension(-1);
//
//	double testAngle2 = third.angle(fourth);
//
//	assert(testAngle2 > 119.9, "T31_angle");
//	assert(testAngle2 < 120, "T31_angle");
//}
//
//void PointTests::T32_reflect2D()
//{
//	Point right = Point();
//	right.addDimension(1);
//	right.addDimension(0);
//
//	Point up = Point();
//	up.addDimension(0);
//	up.addDimension(1);
//
//	Point reflectedLeft = right.reflect(up);
//
//	Point rotatedDown = up.reflect(right);
//
//	assert(-1.0 == reflectedLeft[0], "T32_reflect");
//	assert(0.0 == reflectedLeft[1], "T32_reflect");
//	assert(0.0 == rotatedDown[0], "T32_reflect");
//	assert(-1.0 == rotatedDown[1], "T32_reflect");
//}
//
//void PointTests::T33_constructor3D()
//{
//	Point test;
//	test.addDimension(0);
//	test.addDimension(0);
//	test.addDimension(0);
//
//	assert(test[0] == 0.0, "T33_constructor3D");
//
//	assert(test[1] == 0.0, "T33_constructor3D");
//
//	assert(test[2] == 0.0, "T33_constructor3D");
//}
//
//void PointTests::T34_constructorWithValues3D()
//{
//	Point test;
//	test.addDimension(5.5);
//	test.addDimension(7.1);
//	test.addDimension(9.6);
//
//	assert(test[0] == 5.5, "T34_constructorWithValues3D");
//
//	assert(test[1] == 7.1, "T34_constructorWithValues3D");
//
//	assert(test[2] == 9.6, "T34_constructorWithValues3D");
//}
//
//void PointTests::T35_copyConstructor3D()
//{
//	Point test;
//	test.addDimension(5.5);
//	test.addDimension(7.1);
//	test.addDimension(9.6);
//
//	Point copy = Point(test);
//
//	//make sure they have the right values
//	assert(test[0] == 5.5, "T35_copyConstructor3D");
//
//	assert(test[1] == 7.1, "T35_copyConstructor3D");
//
//	assert(test[2] == 9.6, "T35_copyConstructor3D");
//
//	assert(copy[0] == 5.5, "T35_copyConstructor3D");
//
//	assert(copy[1] == 7.1, "T35_copyConstructor3D");
//
//	assert(copy[2] == 9.6, "T35_copyConstructor3D");
//
//	//make sure each has its own memory
//	assert(&test[0] != &copy[0], "T35_copyConstructor3D");
//
//	assert(&test[1] != &copy[1], "T35_copyConstructor3D");
//
//	assert(&test[2] != &copy[2], "T35_copyConstructor3D");
//}
//
//void PointTests::T36_moveConstructor3D()
//{
//	Point test;
//	test.addDimension(5);
//	test.addDimension(6);
//	test.addDimension(9);
//
//	Point moveHere(std::move(test));
//
//	//make sure they have the righ tvalues
//	assert(test.getNumberOfDimensions() == 0, "T36_moveConstructor3D");
//
//	assert(moveHere[0] == 5.0, "T36_moveConstructor3D");
//
//	assert(moveHere[1] == 6.0, "T36_moveConstructor3D");
//
//	assert(moveHere[2] == 9.0, "T36_moveConstructor3D");
//}
//
//void PointTests::T37_assignmentOperator3D()
//{
//	Point test;
//	test.addDimension(55);
//	test.addDimension(10);
//	test.addDimension(6);
//
//	Point assigned = test;
//
//	//make sure they have the righ tvalues
//	assert(test[0] == 55.0, "T37_assignmentOperator3D");
//
//	assert(test[1] == 10.0, "T37_assignmentOperator3D");
//
//	assert(test[2] == 6.0, "T37_assignmentOperator3D");
//
//	assert(assigned[0] == 55.0, "T37_assignmentOperator3D");
//
//	assert(assigned[1] == 10.0, "T37_assignmentOperator3D");
//
//	assert(assigned[2] == 6.0, "T37_assignmentOperator3D");
//
//	//make sure each has its own memory
//	assert(&test[0] != &assigned[0], "T37_assignmentOperator3D");
//
//	assert(&test[1] != &assigned[1], "T37_assignmentOperator3D");
//
//	assert(&test[2] != &assigned[2], "T37_assignmentOperator3D");
//}
//
//void PointTests::T38_moveAssignmentOperator3D()
//{
//	Point test;
//	test.addDimension(5);
//	test.addDimension(6);
//	test.addDimension(8);
//
//	Point moveAssignHere = std::move(test);
//
//	//make sure they have the righ tvalues
//	assert(test.getNumberOfDimensions() == 0, "T38_moveAssignmentOperator3D");
//
//	assert(moveAssignHere[0] == 5.0, "T38_moveAssignmentOperator3D");
//
//	assert(moveAssignHere[1] == 6.0, "T38_moveAssignmentOperator3D");
//
//	assert(moveAssignHere[2] == 8.0, "T38_moveAssignmentOperator3D");
//}
//
//void PointTests::T39_additionOperator3D()
//{
//	Point orig;
//	orig.addDimension(5);
//	orig.addDimension(10);
//	orig.addDimension(2);
//
//	Point plus;
//	plus.addDimension(1);
//	plus.addDimension(2);
//	plus.addDimension(25);
//
//	Point sum = orig + plus;
//
//	assert(sum[0] == 6.0, "T39_additionOperator3D");
//
//	assert(sum[1] == 12.0, "T39_additionOperator3D");
//
//	assert(sum[2] == 27.0, "T39_additionOperator3D");
//
//	assert(&sum[0] != &orig[0], "T39_additionOperator3D");
//
//	assert(&sum[1] != &orig[1], "T39_additionOperator3D");
//
//	assert(&sum[2] != &orig[2], "T39_additionOperator3D");
//
//	assert(&sum[0] != &plus[0], "T39_additionOperator3D");
//
//	assert(&sum[1] != &plus[1], "T39_additionOperator3D");
//
//	assert(&sum[2] != &plus[2], "T39_additionOperator3D");
//}
//
//void PointTests::T40_subtractionOperator3D()
//{
//	Point orig;
//	orig.addDimension(5);
//	orig.addDimension(10);
//	orig.addDimension(6);
//
//	Point minus;
//	minus.addDimension(1);
//	minus.addDimension(2);
//	minus.addDimension(3);
//
//	Point difference = orig - minus;
//
//	assert(difference[0] == 4.0, "T40_subtractionOperator3D");
//
//	assert(difference[1] == 8.0, "T40_subtractionOperator3D");
//
//	assert(difference[2] == 3.0, "T40_subtractionOperator3D");
//
//	assert(&difference[0] != &orig[0], "T40_subtractionOperator3D");
//
//	assert(&difference[1] != &orig[1], "T40_subtractionOperator3D");
//
//	assert(&difference[2] != &orig[2], "T40_subtractionOperator3D");
//
//	assert(&difference[0] != &minus[0], "T40_subtractionOperator3D");
//
//	assert(&difference[1] != &minus[1], "T40_subtractionOperator3D");
//
//	assert(&difference[2] != &minus[2], "T40_subtractionOperator3D");
//}
//
//void PointTests::T41_multiply2Vector3sOperator3D()
//{
//	Point orig;
//	orig.addDimension(5);
//	orig.addDimension(10);
//	orig.addDimension(15);
//
//	Point times;
//	times.addDimension(2);
//	times.addDimension(3);
//	times.addDimension(1);
//
//	Point product = orig * times;
//
//	assert(product[0] == 10.0, "T41_multiply2Vector3sOperator3D");
//
//	assert(product[1] == 30.0, "T41_multiply2Vector3sOperator3D");
//
//	assert(product[2] == 15.0, "T41_multiply2Vector3sOperator3D");
//
//	assert(&product[0] != &orig[0], "T41_multiply2Vector3sOperator3D");
//
//	assert(&product[1] != &orig[1], "T41_multiply2Vector3sOperator3D");
//
//	assert(&product[2] != &orig[2], "T41_multiply2Vector3sOperator3D");
//
//	assert(&product[0] != &times[0], "T41_multiply2Vector3sOperator3D");
//
//	assert(&product[1] != &times[1], "T41_multiply2Vector3sOperator3D");
//
//	assert(&product[2] != &times[2], "T41_multiply2Vector3sOperator3D");
//}
//
//void PointTests::T42_multiplyVector3ByDouble3D()
//{
//	Point orig;
//	orig.addDimension(5);
//	orig.addDimension(10);
//	orig.addDimension(6);
//
//	double times = 2;
//
//	Point product = orig * times;
//
//	assert(product[0] == 10.0, "T42_multiplyVector3ByDouble3D");
//
//	assert(product[1] == 20.0, "T42_multiplyVector3ByDouble3D");
//
//	assert(product[2] == 12.0, "T42_multiplyVector3ByDouble3D");
//
//	assert(&product[0] != &orig[0], "T42_multiplyVector3ByDouble3D");
//
//	assert(&product[1] != &orig[1], "T42_multiplyVector3ByDouble3D");
//
//	assert(&product[2] != &orig[2], "T42_multiplyVector3ByDouble3D");
//}
//
//void PointTests::T43_equivalenceOperators3D()
//{
//	Point test;
//	test.addDimension(50);
//	test.addDimension(70);
//	test.addDimension(60);
//
//	Point test2;
//	test2.addDimension(50);
//	test2.addDimension(70);
//	test2.addDimension(60);
//
//	Point test3;
//	test3.addDimension(50.0000000000000001);
//	test3.addDimension(70.0000000000000001);
//	test3.addDimension(60.0000000000000001);
//
//	Point test4;
//	test4.addDimension(6);
//	test4.addDimension(7);
//	test4.addDimension(11);
//
//	assert(test == test2, "T43_equivalenceOperators3D");
//
//	assert(test == test3, "T43_equivalenceOperators3D");
//
//	assert(test != test4, "T43_equivalenceOperators3D");
//}
//
//void PointTests::T44_dotProduct3D()
//{
//	Point orig;
//	orig.addDimension(5);
//	orig.addDimension(10);
//	orig.addDimension(3);
//
//	Point dot;
//	dot.addDimension(2);
//	dot.addDimension(3);
//	dot.addDimension(4);
//
//	double product = orig.dot(dot);
//
//	assert(product == 52.0, "T44_dotProduct3D");
//}
//
//void PointTests::T45_magnitude3D()
//{
//	Point test;
//	test.addDimension(5);
//	test.addDimension(10);
//	test.addDimension(12);
//
//	double magnitude = test.magnitude();
//
//	assert(magnitude == sqrt(269), "T45_magnitude3D");
//}
//
//void PointTests::T46_magnitudeSquared3D()
//{
//	Point test;
//	test.addDimension(5);
//	test.addDimension(10);
//	test.addDimension(12);
//
//	double magnitudeSq = test.magnitudeSquared();
//
//	assert(magnitudeSq == 269.0, "T46_magnitudeSquared3D");
//}
//
//void PointTests::T47_divide2Vector3sOperator3D()
//{
//	Point orig;
//	orig.addDimension(6);
//	orig.addDimension(10);
//	orig.addDimension(9);
//
//	Point divisor;
//	divisor.addDimension(2);
//	divisor.addDimension(5);
//	divisor.addDimension(3);
//
//	Point quotient = orig / divisor;
//
//	assert(quotient[0] == 3.0, "T47_divide2Vector3sOperator3D");
//
//	assert(quotient[1] == 2.0, "T47_divide2Vector3sOperator3D");
//
//	assert(quotient[2] == 3.0, "T47_divide2Vector3sOperator3D");
//
//	assert(&quotient[0] != &orig[0], "T47_divide2Vector3sOperator3D");
//
//	assert(&quotient[1] != &orig[1], "T47_divide2Vector3sOperator3D");
//
//	assert(&quotient[2] != &orig[2], "T47_divide2Vector3sOperator3D");
//
//	assert(&quotient[0] != &divisor[0], "T47_divide2Vector3sOperator3D");
//
//	assert(&quotient[1] != &divisor[1], "T47_divide2Vector3sOperator3D");
//
//	assert(&quotient[2] != &divisor[2], "T47_divide2Vector3sOperator3D");
//}
//
//void PointTests::T48_divideVector3ByDoubleOperator3D()
//{
//	Point orig;
//	orig.addDimension(6);
//	orig.addDimension(10);
//	orig.addDimension(15);
//
//	double divisor = 2;
//
//	Point quotient = orig / divisor;
//
//	assert(quotient[0] == 3.0, "T48_divideVector3ByDoubleOperator3D");
//
//	assert(quotient[1] == 5.0, "T48_divideVector3ByDoubleOperator3D");
//
//	assert(quotient[2] == 7.5, "T48_divideVector3ByDoubleOperator3D");
//
//	assert(&quotient[0] != &orig[0], "T48_divideVector3ByDoubleOperator3D");
//
//	assert(&quotient[1] != &orig[1], "T48_divideVector3ByDoubleOperator3D");
//
//	assert(&quotient[2] != &orig[2], "T48_divideVector3ByDoubleOperator3D");
//}
//
//void PointTests::T49_additionShorthandOperator3D()
//{
//	Point orig;
//	orig.addDimension(5);
//	orig.addDimension(10);
//	orig.addDimension(19);
//
//	Point plus;
//	plus.addDimension(1);
//	plus.addDimension(2);
//	plus.addDimension(1);
//
//	orig += plus;
//
//	assert(orig[0] == 6.0, "T49_additionShorthandOperator3D");
//
//	assert(orig[1] == 12.0, "T49_additionShorthandOperator3D");
//
//	assert(orig[2] == 20.0, "T49_additionShorthandOperator3D");
//
//	assert(&orig[0] != &plus[0], "T49_additionShorthandOperator3D");
//
//	assert(&orig[1] != &plus[1], "T49_additionShorthandOperator3D");
//
//	assert(&orig[2] != &plus[2], "T49_additionShorthandOperator3D");
//}
//
//void PointTests::T50_subtractionShorthandOperator3D()
//{
//	Point orig;
//	orig.addDimension(5);
//	orig.addDimension(10);
//	orig.addDimension(25);
//
//	Point minus;
//	minus.addDimension(1);
//	minus.addDimension(2);
//	minus.addDimension(5);
//
//	orig -= minus;
//
//	assert(orig[0] == 4.0, "T50_subtractionShorthandOperator3D");
//
//	assert(orig[1] == 8.0, "T50_subtractionShorthandOperator3D");
//
//	assert(orig[2] == 20.0, "T50_subtractionShorthandOperator3D");
//
//	assert(&orig[0] != &minus[0], "T50_subtractionShorthandOperator3D");
//
//	assert(&orig[1] != &minus[1], "T50_subtractionShorthandOperator3D");
//
//	assert(&orig[2] != &minus[2], "T50_subtractionShorthandOperator3D");
//}
//
//void PointTests::T51_multiply2Vector3sShorthandOperator3D()
//{
//	Point orig;
//	orig.addDimension(5);
//	orig.addDimension(10);
//	orig.addDimension(15);
//
//	Point times;
//	times.addDimension(2);
//	times.addDimension(2);
//	times.addDimension(2);
//
//	orig *= times;
//
//	assert(orig[0] == 10.0, "T51_multiply2Vector3sShorthandOperator3D");
//
//	assert(orig[1] == 20.0, "T51_multiply2Vector3sShorthandOperator3D");
//
//	assert(orig[2] == 30.0, "T51_multiply2Vector3sShorthandOperator3D");
//
//	assert(&orig[0] != &times[0], "T51_multiply2Vector3sShorthandOperator3D");
//
//	assert(&orig[1] != &times[1], "T51_multiply2Vector3sShorthandOperator3D");
//
//	assert(&orig[2] != &times[2], "T51_multiply2Vector3sShorthandOperator3D");
//}
//
//void PointTests::T52_multiplyVector3ByDoubleShorthandOperator3D()
//{
//	Point orig;
//	orig.addDimension(5);
//	orig.addDimension(10);
//	orig.addDimension(30);
//
//	double times = 2;
//
//	orig *= times;
//
//	assert(orig[0] == 10.0, "T52_multiplyVector3ByDoubleShorthandOperator3D");
//
//	assert(orig[1] == 20.0, "T52_multiplyVector3ByDoubleShorthandOperator3D");
//
//	assert(orig[2] == 60.0, "T52_multiplyVector3ByDoubleShorthandOperator3D");
//}
//
//void PointTests::T53_divide2Vector3sShorthandOperator3D()
//{
//	Point orig;
//	orig.addDimension(6);
//	orig.addDimension(10);
//	orig.addDimension(9);
//
//	Point divisor;
//	divisor.addDimension(2);
//	divisor.addDimension(5);
//	divisor.addDimension(3);
//
//	orig /= divisor;
//
//	assert(orig[0] == 3.0, "T53_divide2Vector3sShorthandOperator3D");
//
//	assert(orig[1] == 2.0, "T53_divide2Vector3sShorthandOperator3D");
//
//	assert(orig[2] == 3.0, "T53_divide2Vector3sShorthandOperator3D");
//
//	assert(&orig[0] != &divisor[0], "T53_divide2Vector3sShorthandOperator3D");
//
//	assert(&orig[1] != &divisor[1], "T53_divide2Vector3sShorthandOperator3D");
//
//	assert(&orig[2] != &divisor[2], "T53_divide2Vector3sShorthandOperator3D");
//}
//
//void PointTests::T54_divideVector3ByDoubleShorthandOperator3D()
//{
//	Point orig;
//	orig.addDimension(6);
//	orig.addDimension(10);
//	orig.addDimension(20);
//
//	double divisor = 2;
//
//	orig /= divisor;
//
//	assert(orig[0] == 3.0, "T54_divideVector3ByDoubleShorthandOperator3D");
//
//	assert(orig[1] == 5.0, "T54_divideVector3ByDoubleShorthandOperator3D");
//
//	assert(orig[2] == 10.0, "T54_divideVector3ByDoubleShorthandOperator3D");
//}
//
//void PointTests::T55_distance3D()
//{
//	Point test;
//	test.addDimension(5);
//	test.addDimension(10);
//	test.addDimension(20);
//
//	Point test2;
//	test2.addDimension(7);
//	test2.addDimension(3);
//	test2.addDimension(6);
//
//	double distance = test.distance(test2);
//
//	double alsoDistance = test2.distance(test);
//
//	assert(distance == alsoDistance, "T55_distance3D");
//
//	assert(distance == sqrt(249.0), "T55_distance3D");
//}
//
//void PointTests::T56_distanceSquared3D()
//{
//	Point test;
//	test.addDimension(5);
//	test.addDimension(10);
//	test.addDimension(20);
//
//	Point test2;
//	test2.addDimension(7);
//	test2.addDimension(3);
//	test2.addDimension(6);
//
//	double distance = test.distanceSquared(test2);
//
//	double alsoDistance = test2.distanceSquared(test);
//
//	assert(distance == alsoDistance, "T56_distanceSquared3D");
//
//	assert(distance == 249.0, "T56_distanceSquared3D");
//}
//
//void PointTests::T57_normalize3D()
//{
//	Point test;
//	test.addDimension(0);
//	test.addDimension(10);
//	test.addDimension(0);
//
//	Point test2;
//	test2.addDimension(10);
//	test2.addDimension(0);
//	test2.addDimension(0);
//
//	Point test3;
//	test3.addDimension(0);
//	test3.addDimension(0);
//	test3.addDimension(10);
//
//	Point test4;
//	test4.addDimension(4);
//	test4.addDimension(6);
//	test4.addDimension(8);
//
//	test.normalize();
//	test2.normalize();
//	test3.normalize();
//	test4.normalize();
//
//	assert(0.0 == test[0], "T57_normalize3D");
//	assert(1.0 == test[1], "T57_normalize3D");
//	assert(0.0 == test[2], "T57_normalize3D");
//
//	assert(1.0 == test2[0], "T57_normalize3D");
//	assert(0.0 == test2[1], "T57_normalize3D");
//	assert(0.0 == test2[2], "T57_normalize3D");
//
//	assert(0.0 == test3[0], "T57_normalize3D");
//	assert(0.0 == test3[1], "T57_normalize3D");
//	assert(1.0 == test3[2], "T57_normalize3D");
//
//	assert(0.371 < test4[0], "T57_normalize3D");
//	assert(0.557 < test4[1], "T57_normalize3D");
//	assert(0.742 < test4[2], "T57_normalize3D");
//	assert(0.372 > test4[0], "T57_normalize3D");
//	assert(0.558 > test4[1], "T57_normalize3D");
//	assert(0.743 > test4[2], "T57_normalize3D");
//
//
//	Point test5;
//	test5.addDimension(0);
//	test5.addDimension(0);
//	test5.addDimension(0);
//
//	try
//	{
//		test5.normalize();
//		assert(false, "T57_normalize3D");
//	}
//	catch (std::logic_error e)
//	{
//		assert(true, "T57_normalize3D");
//	}
//}
//
//void PointTests::T58_normalized3D()
//{
//	Point test;
//	test.addDimension(0);
//	test.addDimension(10);
//	test.addDimension(0);
//
//	Point test2;
//	test2.addDimension(10);
//	test2.addDimension(0);
//	test2.addDimension(0);
//
//	Point test3;
//	test3.addDimension(0);
//	test3.addDimension(0);
//	test3.addDimension(10);
//
//	Point test4;
//	test4.addDimension(4);
//	test4.addDimension(6);
//	test4.addDimension(8);
//
//	Point test1Normalized = test.normalized();
//	Point test2Normalized = test2.normalized();
//	Point test3Normalized = test3.normalized();
//	Point test4Normalized = test4.normalized();
//
//	assert(0.0 == test1Normalized[0], "T58_normalized3D");
//	assert(1.0 == test1Normalized[1], "T58_normalized3D");
//	assert(0.0 == test1Normalized[2], "T58_normalized3D");
//
//	assert(1.0 == test2Normalized[0], "T58_normalized3D");
//	assert(0.0 == test2Normalized[1], "T58_normalized3D");
//	assert(0.0 == test2Normalized[2], "T58_normalized3D");
//
//	assert(0.0 == test3Normalized[0], "T58_normalized3D");
//	assert(0.0 == test3Normalized[1], "T58_normalized3D");
//	assert(1.0 == test3Normalized[2], "T58_normalized3D");
//
//	assert(0.371 < test4Normalized[0], "T58_normalized3D");
//	assert(0.557 < test4Normalized[1], "T58_normalized3D");
//	assert(0.742 < test4Normalized[2], "T58_normalized3D");
//	assert(0.372 > test4Normalized[0], "T58_normalized3D");
//	assert(0.558 > test4Normalized[1], "T58_normalized3D");
//	assert(0.743 > test4Normalized[2], "T58_normalized3D");
//
//
//	Point test5;
//	test5.addDimension(0);
//	test5.addDimension(0);
//	test5.addDimension(0);
//
//	try
//	{
//		Point throwaway = test5.normalized();
//		assert(false, "T58_normalized3D");
//	}
//	catch (std::logic_error e)
//	{
//		assert(true, "T58_normalized3D");
//	}
//}
//
//void PointTests::T59_project3D()
//{
//	Point first = Point();
//	first.addDimension(3);
//	first.addDimension(4);
//	first.addDimension(-3);
//
//	Point second;
//	second.addDimension(2);
//	second.addDimension(0);
//	second.addDimension(6);
//
//	Point projected = second.project(first);
//
//	assert(-18.0 / 17.0 == projected[0], "T59_project3D");
//	assert(-24.0 / 17.0 == projected[1], "T59_project3D");
//	assert(18.0 / 17.0 == projected[2], "T59_project3D");
//}
//
//void PointTests::T60_outputOperator3D()
//{
//	Point test;
//	test.addDimension(55);
//	test.addDimension(703);
//	test.addDimension(5.5);
//
//	std::stringstream out;
//
//	out << test;
//
//	std::string testText = "(55, 703, 5.5)";
//
//	assert(testText == out.str(), "T60_outputOperator3D");
//}
//
//void PointTests::T61_perpendicular3D()
//{
//	Point first;
//	first.addDimension(5);
//	first.addDimension(5);
//	first.addDimension(11);
//
//	Point second = Point();
//	second.addDimension(-3);
//	second.addDimension(2);
//	second.addDimension(8);
//
//	Point perpendicular = first.perpendicular(second);
//
//	assert(8.3 > perpendicular[0], "T61_perpendicular3D");
//	assert(8.2 < perpendicular[0], "T61_perpendicular3D");
//
//	assert(2.9 > perpendicular[1], "T61_perpendicular3D");
//	assert(2.8 < perpendicular[1], "T61_perpendicular3D");
//
//	assert(2.4 > perpendicular[2], "T61_perpendicular3D");
//	assert(2.3 < perpendicular[2], "T61_perpendicular3D");
//
//	Point test2;
//	test2.addDimension(10.0);
//	test2.addDimension(0.0);
//	test2.addDimension(0.0);
//	Point test3;
//	test3.addDimension(5.0);
//	test3.addDimension(5.0);
//	test3.addDimension(5.0);
//
//	Point perpendicular2 = test3.perpendicular(test2);
//
//	assert(0.0 == perpendicular2[0], "T61_perpendicular3D");
//	assert(5.0 == perpendicular2[1], "T61_perpendicular3D");
//	assert(5.0 == perpendicular2[2], "T61_perpendicular3D");
//}
//
//void PointTests::T62_angle3D()
//{
//	Point first;
//	first.addDimension(5);
//	first.addDimension(5);
//	first.addDimension(5);
//
//	Point second = Point();
//	second.addDimension(-5);
//	second.addDimension(5);
//	second.addDimension(5);
//
//	double test1 = first.angle(second);
//
//	assert(70.52877 < test1, "T62_angle3D");
//	assert(70.52878 > test1, "T62_angle3D");
//
//	Point third;
//	third.addDimension(2);
//	third.addDimension(7);
//	third.addDimension(3);
//
//	Point fourth = Point();
//	fourth.addDimension(-4);
//	fourth.addDimension(-1);
//	fourth.addDimension(-3);
//
//	double test2 = third.angle(fourth);
//
//	assert(126.70982 < test2, "T62_angle3D");
//	assert(126.70983 > test2, "T62_angle3D");
//}
//
//void PointTests::T63_reflect3D()
//{
//	Point a;
//	a.addDimension(5);
//	a.addDimension(0);
//	a.addDimension(5);
//
//	Point b;
//	b.addDimension(0);
//	b.addDimension(5);
//	b.addDimension(0);
//
//	Point ab = a.reflect(b);
//
//	Point ba = b.reflect(a);
//
//	assert(-5.0 == ab[0], "T63_reflect3D");
//	assert(0.0 == ab[1], "T63_reflect3D");
//	assert(-5.0 == ab[2], "T63_reflect3D");
//	assert(0.0 == ba[0], "T63_reflect3D");
//	assert(-5.0 == ba[1], "T63_reflect3D");
//	assert(0.0 == ba[2], "T63_reflect3D");
//}
//
//void PointTests::T64_crossProduct3D()
//{
//	Point right;
//	right.addDimension(5);
//	right.addDimension(0);
//	right.addDimension(0);
//	Point up;
//	up.addDimension(0);
//	up.addDimension(5);
//	up.addDimension(0);
//	Point into;
//	into.addDimension(0);
//	into.addDimension(0);
//	into.addDimension(25);
//
//	assert(into[0] == right.crossProduct(up)[0], "T64_crossProduct3D");
//	assert(into[1] == right.crossProduct(up)[1], "T64_crossProduct3D");
//	assert(into[2] == right.crossProduct(up)[2], "T64_crossProduct3D");
//}
//Cody Ware
//6/30/19

#include "../headers/TransformTests.h"

void TransformTests::runAllTests()
{
	T1_testBigFive();
	T2_testSwitchMajors();
	T3_testGetSetTranslate();
	T4_testGetSetScale();
	T5_testGetSetXYZAxis();
	T6_testRotateZ();
	T7_testRotateY();
	T8_testRotateX();
	T9_testRotate();
	T10_testAxisAngleRotate();
	cout << "Passed: All Transform Tests\n";
}

void TransformTests::T1_testBigFive()
{
	//default constructor
	Transform x;

	assert(x.isRowMajor(), "defaults to row major");
	Transform a;

	a.toOtherMajor();

	//copy constructor
	Transform y(a);

	assert(!y.isRowMajor(), "test that copy constructor copies major");

	//move constructor
	Transform z(std::move(x));

	//operator=
	x=a;

	//move operator
	z = std::move(a);
}

void TransformTests::T2_testSwitchMajors()
{
	Transform a;

	a.toOtherMajor();

	assert(!a.isRowMajor(), "test that changing majors works");
}

void TransformTests::T3_testGetSetTranslate()
{
	Transform a;

	PhysicsVector x;
	x.addDimension(1);
	x.addDimension(2);
	x.addDimension(3);

	a.setTranslate(x);

	assert(a.getTranslate() == x, "make sure that the transform was set when row major");

	a.toOtherMajor();

	assert(a.getTranslate() == x, "changing majors to column major must maintain transform");

	Transform b;

	b.toOtherMajor();

	b.setTranslate(x);

	assert(b.getTranslate() == x, "make sure that transform is set when column major");

	assert(b.getTranslate() == x, "changing majors to row major must maintain transform");
}

void TransformTests::T4_testGetSetScale()
{
	Transform a;

	PhysicsVector x;
	x.addDimension(1);
	x.addDimension(2);
	x.addDimension(3);

	a.setScale(x);

	assert(a.getScale() == x, "make sure that the scale was set in row major");

	a.toOtherMajor();

	assert(a.getScale() == x, "changing majors to column major must maintain scale");

	Transform b;

	b.toOtherMajor();

	b.setScale(x);

	assert(b.getScale() == x, "make sure that setting scale in column major works");

	b.toOtherMajor();

	assert(b.getScale() == x, "make sure that changing major to row major maintains the scale");
}

void TransformTests::T5_testGetSetXYZAxis()
{
	Transform rowMajorTest;

	PhysicsVector rowMajorTestVector;
	rowMajorTestVector.addDimension(1);
	rowMajorTestVector.addDimension(2);
	rowMajorTestVector.addDimension(3);

	//xaxis
	rowMajorTest.setXAxis(rowMajorTestVector);

	assert(rowMajorTest.getXAxis() == rowMajorTestVector, "make sure xaxis get set");

	//yaxis
	rowMajorTestVector *= 2;
	rowMajorTest.setYAxis(rowMajorTestVector);

	assert(rowMajorTest.getYAxis() == rowMajorTestVector, "make sure y axis gets set");

	//zaxis
	rowMajorTestVector *= 2;
	rowMajorTest.setZAxis(rowMajorTestVector);

	assert(rowMajorTest.getZAxis() == rowMajorTestVector, "make sure z axis gets set");

	rowMajorTest.toOtherMajor();

	assert(rowMajorTest.getZAxis() == rowMajorTestVector, "make sure z axis is maintained after changing majors");
	rowMajorTestVector /= 2;
	assert(rowMajorTest.getYAxis() == rowMajorTestVector, "make sure y axis is maintained after changing majors");
	rowMajorTestVector /= 2;
	assert(rowMajorTest.getXAxis() == rowMajorTestVector, "make sure x axis is maintained after changing majors");

	//test again but start with a column major
	Transform columnMajorTest;
	columnMajorTest.toOtherMajor();

	PhysicsVector columnMajorTestVector;
	columnMajorTestVector.addDimension(1);
	columnMajorTestVector.addDimension(2);
	columnMajorTestVector.addDimension(3);

	//xaxis
	columnMajorTest.setXAxis(columnMajorTestVector);

	assert(columnMajorTest.getXAxis() == columnMajorTestVector, "make sure xaxis get set");

	//yaxis
	columnMajorTestVector *= 2;
	columnMajorTest.setYAxis(columnMajorTestVector);

	assert(columnMajorTest.getYAxis() == columnMajorTestVector, "make sure y axis gets set");

	//zaxis
	columnMajorTestVector *= 2;
	columnMajorTest.setZAxis(columnMajorTestVector);

	assert(columnMajorTest.getZAxis() == columnMajorTestVector, "make sure z axis gets set");

	columnMajorTest.toOtherMajor();

	assert(columnMajorTest.getZAxis() == columnMajorTestVector, "make sure z axis is maintained after changing majors");
	columnMajorTestVector /= 2;
	assert(columnMajorTest.getYAxis() == columnMajorTestVector, "make sure y axis is maintained after changing majors");
	columnMajorTestVector /= 2;
	assert(columnMajorTest.getXAxis() == columnMajorTestVector, "make sure x axis is maintained after changing majors");

}

void TransformTests::T6_testRotateZ()
{
	Matrix expectedAfterRotating45degrees;
	//hard coded numbers i got from doing paper math
	expectedAfterRotating45degrees[0][0] = 0.52532198881772973;
	expectedAfterRotating45degrees[0][1] = 0.85090352453411844;
	expectedAfterRotating45degrees[1][0] = -0.85090352453411844;
	expectedAfterRotating45degrees[1][1] = 0.52532198881772973;

	Transform x;

	Matrix actualAfter45DegreeZRotate = x.rotateZ(45);

	assert(actualAfter45DegreeZRotate == expectedAfterRotating45degrees, "rotating Z 45 degrees doesnt work as expected");
}

void TransformTests::T7_testRotateY()
{
	Matrix expectedAfterRotating45degrees;
	//hard coded numbers i got from doing paper math
	expectedAfterRotating45degrees[0][0] = 0.52532198881772973;
	expectedAfterRotating45degrees[0][2] = -0.85090352453411844;
	expectedAfterRotating45degrees[2][0] = 0.85090352453411844;
	expectedAfterRotating45degrees[2][2] = 0.52532198881772973;

	Transform x;

	Matrix actualAfter45DegreeYRotate = x.rotateY(45);

	assert(actualAfter45DegreeYRotate == expectedAfterRotating45degrees, "rotating Y 45 degrees doesnt work as expected");
}

void TransformTests::T8_testRotateX()
{
	Matrix expectedAfterRotating45degrees;
	//hard coded numbers i got from doing paper math
	expectedAfterRotating45degrees[1][1] = 0.52532198881772973;
	expectedAfterRotating45degrees[1][2] = 0.85090352453411844;
	expectedAfterRotating45degrees[2][1] = -0.85090352453411844;
	expectedAfterRotating45degrees[2][2] = 0.52532198881772973;

	Transform x;

	Matrix actualAfter45DegreeXRotate = x.rotateX(45);

	assert(actualAfter45DegreeXRotate == expectedAfterRotating45degrees, "rotating X 45 degrees doesnt work as expected");
}

void TransformTests::T9_testRotate()
{
	Matrix expectedAfterRotating;
	//hard coded numbers i got from doing paper math
	expectedAfterRotating[0][0] = 0.89204866381000347;
	expectedAfterRotating[0][1] = 0.4469983318002789;
	expectedAfterRotating[0][2] = -0.066645875810550259;
	expectedAfterRotating[1][0] = -0.066645875810550259;
	expectedAfterRotating[1][1] = 0.27596319193541492796;

	expectedAfterRotating[1][2] = 0.95885486072411519;
	expectedAfterRotating[2][0] = 0.44699833180027893556;
	expectedAfterRotating[2][1] = -0.85090352453411844;
	expectedAfterRotating[2][2] = 0.27596319193541492796;

	Transform x;

	Matrix actual = x.getRotationMatrix(45,45,45);

	assert(actual == expectedAfterRotating, "rotation matrix is not as expected");
}

void TransformTests::T10_testAxisAngleRotate()
{
}

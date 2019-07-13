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
	T6_testRotate();
	cout << "All Transform Tests Passed\n";
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

	Vector3 x(1, 2, 3);

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

	Vector3 x(1, 2, 3);

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

//TODO update so that this does bi directional testing for major change
void TransformTests::T5_testGetSetXYZAxis()
{
	Transform a;

	Vector3 x(1, 2, 3);
	
	//xaxis
	a.setXAxis(x);

	assert(a.getXAxis() == x, "make sure xaxis get set");

	//yaxis
	x *= 2;
	a.setYAxis(x);

	assert(a.getYAxis() == x, "make sure y axis gets set");

	//zaxis
	x *= 2;
	a.setZAxis(x);

	assert(a.getZAxis() == x, "make sure z axis gets set");

	a.toOtherMajor();

	assert(a.getZAxis() == x, "make sure z axis is maintained after changing majors");
	x /= 2;
	assert(a.getYAxis() == x, "make sure y axis is maintained after changing majors");
	x /= 2;
	assert(a.getXAxis() == x, "make sure x axis is maintained after changing majors");
}

void TransformTests::T6_testRotate()
{

}
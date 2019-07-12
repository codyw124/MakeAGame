//Cody Ware
//6/30/19

#include "../headers/TransformTests.h"

void TransformTests::runAllTests()
{
	T1_testBigFive();
	T2_testSwitchMajors();
	T3_testGetSetTranslate();
	T4_testGetSetScale();
	T5_testGetSetRotate();
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

	a.setTransform(x);

	a.toOtherMajor();

	assert(a.getTransform() == x, "changing majors must maintain transform");
}

void TransformTests::T4_testGetSetScale()
{

	Transform a;

	Vector3 x(1, 2, 3);

	a.setScale(x);

	a.toOtherMajor();

	assert(a.getScale() == x, "changing majors must maintain scale");
}

void TransformTests::T5_testGetSetRotate()
{

}

void TransformTests::T6_testRotate()
{

}
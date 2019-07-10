//Cody Ware
//6/30/19

#include "../headers/TransformTests.h"

void TransformTests::runAllTests()
{
	T1_testBigFive();
	T2_testSwitchMajors();
	cout << "All Transform Tests Passed\n";
}

void TransformTests::T1_testBigFive()
{
	//default constructor
	Transform x;
	Transform a;

	//copy constructor
	Transform y(x);

	//move constructor
	Transform z(std::move(x));

	//operator=
	x=a;

	//move operator
	z = std::move(a);
}

void TransformTests::T2_testSwitchMajors()
{
	
}


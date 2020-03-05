//cody ware
//6/25/2019

#include <iostream>
#include <vector>
#include "Test.h"
#include "PhysicsVectorTests.h"
#include "MatricesTests.h"
#include "TransformTests.h"
#include "PointTests.h"

int main()
{
    vector<Test*> tests;

	tests.push_back(new PhysicsVectorTests());
	tests.push_back(new PointTests());
    tests.push_back(new MatricesTests());
    tests.push_back(new TransformTests());

    for(Test* x : tests)
    {
        x->runAllTests();
    }

    std::cout << "Passed: All Tests Passed!\n";
    return 0;
}
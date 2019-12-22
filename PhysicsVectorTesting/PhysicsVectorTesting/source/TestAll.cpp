//cody ware
//6/25/2019

#include <iostream>
#include <vector>
#include "../headers/Test.h"
#include "../headers/PhysicsVectorTests.h"
#include "../headers/MatricesTests.h"
#include "../headers/TransformTests.h"
#include "../headers/GeometryTests.h"

int main()
{
    vector<Test*> tests;

	tests.push_back(new PhysicsVectorTests());
    tests.push_back(new MatricesTests());
    tests.push_back(new TransformTests());
    tests.push_back(new GeometryTests());

    for(Test* x : tests)
    {
        x->runAllTests();
    }

    std::cout << "Passed: All Tests Passed!\n";
    return 0;
}
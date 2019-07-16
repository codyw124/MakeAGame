//cody ware
//6/25/2019

#include <iostream>
#include <vector>
#include "../headers/Test.h"
#include "../headers/Vector2Tests.h"
#include "../headers/Vector3Tests.h"
#include "../headers/MatricesTests.h"
#include "../headers/TransformTests.h"
#include "../headers/GeometryTests.h"

int main()
{
    vector<Test*> tests;

    tests.push_back(new Vector2Tests());
    tests.push_back(new Vector3Tests());
    tests.push_back(new MatricesTests());
    tests.push_back(new TransformTests());
    tests.push_back(new GeometryTests());

    for(Test* x : tests)
    {
        x->runAllTests();
    }

    std::cout << "All Tests Passed!\n";
    return 0;
}
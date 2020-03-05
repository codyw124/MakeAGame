//cody ware
//6/25/2019

#pragma once

#include <iostream>
#include "CppUnitTest.h"

class Test
{
public:
    virtual void runAllTests() = 0;
	void assert(bool expression, std::string failMessage);
};
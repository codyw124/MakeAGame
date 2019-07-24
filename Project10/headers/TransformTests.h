//Cody Ware
//6/30/19

#pragma once

#include <iostream>
#include "Test.h"
#include "Transform.h"

using namespace std;

class TransformTests : public Test
{
    public:
        void runAllTests();
    private:
        void T1_testBigFive();
        void T2_testSwitchMajors();
		void T3_testGetSetTranslate();
		void T4_testGetSetScale();
		void T5_testGetSetXYZAxis();
		void T6_testRotateZ();
		void T7_testRotateY();
		void T8_testRotateX(); 
		void T9_testRotate();
};
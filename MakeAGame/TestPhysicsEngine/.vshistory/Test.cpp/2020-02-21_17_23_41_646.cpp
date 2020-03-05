//cody ware
//7/10/19

#include "Test.h"

void Test::assert(bool expression, std::string failMessage)
{
	std::wstring usableFailMessage(failMessage.begin(), failMessage.end());
	Assert::IsTrue(false, usableFailMessage.c_str());

	//if(!expression)
	//{
		//std::cerr << "Failed: " << failMessage << std::endl;
	//}
}

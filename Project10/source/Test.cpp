//cody ware
//7/10/19

#include "../headers/Test.h"

void Test::assert(bool expression, std::string failMessage)
{
	if(!expression)
	{
		std::cerr << failMessage << std::endl;
	}
}

//Cody Ware
//1/8/19

#pragma once

#include "IMatrix.h"

namespace GamePhysics
{
	class IMatrix
	{
		public:
			virtual void transpose() = 0;
	};
}

#include "SquareMatrix.h"

SquareMatrix::SquareMatrix(const int & r, const int & c)
{
	//if the dimensions they gave us would make a square
	if (r == c)
	{
		int* inverseData = new int[r*c];

		for (int i = 0; i < r*c; i++)
		{
			if (r == c)
			{
				inverseData[i] = 1;
			}
			else
			{
				inverseData[i] = 0;
			}
		}

		Matrix(r, c, inverseData);
	}
	else
	{
		//throw an exception
	}
}

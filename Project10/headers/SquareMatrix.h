//Cody Ware
//1/18/19

#pragma once

#include <iostream>
#include "Matrix.h"
#include "ISquareMatrix.h"

class SquareMatrix : public ISquareMatrix//, public Matrix
{
public:
	//default with no data is initialized to identity matrix
	SquareMatrix(const int& r, const int& c);
	
private:
	int**data_;
	int r_;
	int c_;
};
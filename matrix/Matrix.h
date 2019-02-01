//Cody Ware
//1/8/19

#pragma once

#ifdef GAMEPHYSICS_EXPORTS
#define __declspec(dllexport)
#else
#define __declspec(dllimport)
#endif

#include <iostream>
#include "IMatrix.h"

namespace GamePhysics
{
	class Matrix : public IMatrix
	{
	public:
		//constructor with values
		Matrix(const int& r, const int& c, const int* data);

		//copy constructor
		Matrix(const Matrix& other);

		//move constructor
		Matrix(Matrix&& other);

		//assignment operator
		Matrix& operator=(const Matrix& other);

		//move assignment operator
		Matrix& operator=(Matrix&& other);

		//destructor
		~Matrix();

		//bracket operator to get elements
		int* operator[](const int& i) const;

		//addition operator
		Matrix operator+(const Matrix& r) const;

		//subtraction operator
		Matrix operator-(const Matrix& r) const;

		//multiplication with another Matrix operator
		Matrix operator*(const Matrix& r) const;

		//multiply by a double operator
		Matrix operator*(const double& r) const;

		//shorthand addition operator
		Matrix& operator+=(const Matrix& r);

		//shorthand subtraction operator
		Matrix& operator-=(const Matrix& r);

		//shorthand multiplication operator with other Matrix
		Matrix& operator*=(const Matrix& r);

		//shorthand multiplication operator with a double
		Matrix& operator*=(const double& r);

		//equivalence operator
		bool operator==(const Matrix& r) const;

		//in equivalence operator
		bool operator!=(const Matrix& r) const;

		void transpose();

	private:
		//default constructor that is in private section so infered one doesnt exist
		Matrix();

		//deep copy for assignment operator and copy constructor
		void deepCopy(const Matrix& other);

		int r_;
		int c_;

		int** data_;
	};

	//output operator
	std::ostream& operator<<(std::ostream& os, const Matrix & v);
}

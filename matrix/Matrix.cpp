//Cody Ware
//1/9/19

#include "Matrix.h"

namespace GamePhysics
{
	//default constructor that does nothing. this just exists so inplicit one doesnt get made
	Matrix::Matrix()
	{

	}

	Matrix::Matrix(const int& r, const int& c, const int* data)
	{
		//set rows and columns
		r_ = r;
		c_ = c;

		//initialize first dimension
		//the number of rows we want
		data_ = new int*[r];

		//track what piece of data we need to place next
		int currentDataIndex = 0;

		//for each row 
		for(int row =  0; row < r; row++)
		{
			//give it the right number of columns
			data[row] = new int[c];

			for(int column = 0; column < c; column++)
			{
				//place a piece of data in the matrix
				data[row][column] = data[currentDataIndex];
				
				//move on to the next piece of data
				currentDataIndex++;
			}
		}
	}

	Matrix::Matrix(const Matrix& other)
	{

	}

	Matrix::Matrix(Matrix&& other)
	{

	}

	Matrix::~Matrix()
	{

	}

	int* Matrix::operator[](const int& i) const
	{
		return data_[i];
	}

	Matrix Matrix::operator+(const Matrix& other) const
	{
		//if both matrix sizes match
		if(r_ == other.r_ && c_ == other.c_)
		{
			//make a deep copy of other
			Matrix returnMatrix(other);

			//for each row 
			for(int row =  0; row < r_; row++)
			{
				//for each column
				for(int column = 0; column < c_; column++)
				{
					//for each spot add my values to the copy
					returnMatrix[row][column] += data_[row][column];
				}
			}
		}

		return returnMatrix;
	}

	Matrix Matrix::operator-(const Matrix& r) const
	{
		//if both matrix sizes match
		if(r_ == other.r_ && c_ == other.c_)
		{
			//make a deep copy of other
			Matrix returnMatrix(other);

			//for each row 
			for(int row =  0; row < r_; row++)
			{
				//for each column
				for(int column = 0; column < c_; column++)
				{
					//for each spot subtract my values to the copy
					returnMatrix[row][column] -= data_[row][column];
				}
			}
		}

		return returnMatrix;
	}

	Matrix Matrix::operator*(const Matrix& r) const
	{
		return Matrix(1,1);
	}

	Matrix Matrix::operator*(const double& scalar) const
	{
		//make a deep copy of myself
		Matrix returnMatrix(*this);

		//for each row 
		for(int row =  0; row < r_; row++)
		{
			//for each column
			for(int column = 0; column < c_; column++)
			{
				//for each spot multiply by scalar
				returnMatrix[row][column] *= scalar;
			}
		}
		

		return returnMatrix;
	}

	void Matrix::deepCopy(const Matrix& other)
	{

	}

	bool Matrix::operator!=(const Matrix& other) const
	{
		return !*this==other;
	}

	void Matrix::transpose()
	{
	}

	bool Matrix::operator==(const Matrix& other) const
	{
	}

	Matrix& Matrix::operator*=(const double& r)
	{
		return *this;
	}

	Matrix& Matrix::operator*=(const Matrix& r)
	{
		return *this;
	}

	Matrix& Matrix::operator-=(const Matrix& r)
	{
		return *this;
	}

	Matrix& Matrix::operator+=(const Matrix& r)
	{
		return *this;
	}

	Matrix& Matrix::operator=(Matrix&& other)
	{
		return *this;
	}

	Matrix& Matrix::operator=(const Matrix& other)
	{
		return *this;
	}

	std::ostream & operator<<(std::ostream & os, const Matrix & v)
	{
		// TODO: insert return statement here

		return os;
	}
}


//Cody Ware
//1/9/19

#include "../headers/Matrix.h"



Matrix Matrix::operator+(const Matrix& other) const
{
	Matrix returnMatrix;

	//if both matrix sizes match
	if (r_ == other.r_ && c_ == other.c_)
	{
		//make a deep copy of other
		returnMatrix = Matrix(other);

		//for each row 
		for (int row = 0; row < r_; row++)
		{
			//for each column
			for (int column = 0; column < c_; column++)
			{
				//for each spot add my values to the copy
				returnMatrix[row][column] += data_[row][column];
			}
		}
	}
	else
	{
		throw std::logic_error("Matrix dimensions must match.");
	}

	return returnMatrix;
}

Matrix Matrix::operator-(const Matrix& other) const
{
	Matrix returnMatrix;

	//if both matrix sizes match
	if (r_ == other.r_ && c_ == other.c_)
	{
		//make a deep copy of other
		returnMatrix = Matrix(other);

		//for each row 
		for (int row = 0; row < r_; row++)
		{
			//for each column
			for (int column = 0; column < c_; column++)
			{
				//for each spot subtract my values to the copy
				returnMatrix[row][column] -= data_[row][column];
			}
		}
	}
	else
	{
		throw std::logic_error("Matrix dimensions must match.");
	}

	return returnMatrix;
}

Matrix Matrix::operator*(const Matrix& r) const
{
	return Matrix();
}

Matrix Matrix::operator*(const double& scalar) const
{
	//make a deep copy of myself
	Matrix returnMatrix(*this);

	//for each row 
	for (int row = 0; row < r_; row++)
	{
		//for each column
		for (int column = 0; column < c_; column++)
		{
			//for each spot multiply by scalar
			returnMatrix[row][column] *= scalar;
		}
	}


	return returnMatrix;
}

bool Matrix::operator!=(const Matrix& other) const
{
	return !(*this == other);
}

void Matrix::transpose()
{
	//make new data with inverted dimensions
	double** newData = new double*[c_];
	for (int newDataRows = 0; newDataRows<r_; newDataRows++)
	{
		newData[newDataRows] = new double[r_];
	}

	//for each piece of data in the original 2 dimensions
	for (int row = 0; row < r_; row++)
	{
		for (int column = 0; column < c_; column++)
		{
			//set my data piece equal to what the others data piece is in this spot
			newData[column][row] = data_[row][column];
		}

		delete[] data_[row];
	}

	delete[] data_;

	data_ = newData;
	std::swap(r_, c_);
}

Matrix Matrix::transposed()
{
	Matrix returnValue = Matrix(*this);

	returnValue.transpose();

	return returnValue;
}

bool Matrix::operator==(const Matrix& other) const
{
	//check if dimension sizes match
	bool areEqual = r_ == other.r_ && c_ == other.c_;

	//if the dimensions were equal
	if (areEqual) 
	{
		//check the data
		int currentlyCheckedRow = 0;
		int currentlyCheckedColumn;

		//while no data has not matched and we have not checked all rows
		while(currentlyCheckedRow < r_ && areEqual)
		{
			currentlyCheckedColumn = 0;

			//while no data has not matched and we have  not checked all columns
			while (currentlyCheckedColumn < c_ && areEqual)
			{
				//make sure this piece of data matches
				areEqual = data_[currentlyCheckedRow][currentlyCheckedColumn] == other.data_[currentlyCheckedRow][currentlyCheckedColumn];

				currentlyCheckedColumn++;
			}

			currentlyCheckedRow++;
		}
	}

	return areEqual;
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
	*this = *this - r;
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& r)
{
	*this = *this + r;
	return *this;
}

Matrix& Matrix::operator=(Matrix&& other)
{
	deepCopy(other);

	for (int r = 0; r < other.r_; r++)
	{
		delete[] other.data_[r];
	}

	delete[] other.data_;

	other.data_ = NULL;

	other.r_ = 0;
	other.c_ = 0;

	return *this;
}

Matrix& Matrix::operator=(const Matrix& other)
{
	deepCopy(other);
	return *this;
}

std::ostream & operator<<(std::ostream & os, const Matrix & v)
{
	for (int r = 0; r < v.getRows(); r++)
	{
		os << "[\t";

		for (int c = 0; c < v.getColumns(); c++)
		{
			os << v.getData()[r][c] << '\t';
		}

		os << "]\n";
	}

	return os;
}
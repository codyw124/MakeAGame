//Cody Ware
//1/8/19

#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include "PhysicsHelper.h"

using namespace std;

const size_t DEFAULT_MATRIX_DIMENSIONS = 4;

template <class T>
class Matrix
{
	public:
		Matrix();
		Matrix(const size_t& r, const size_t& c);
		Matrix(const Matrix<T>& other);
		Matrix(Matrix&& other);
		~Matrix();		
		Matrix<T>& operator=(const Matrix<T>& other);
		Matrix<T>& operator=(Matrix<T>&& other);
		vector<T>& operator[](const size_t& i);
		const vector<T>& operator[](const size_t& i) const;
		bool operator==(const Matrix<T>& rhs) const;
		bool operator!=(const Matrix<T>& rhs) const;
		Matrix<T>& operator*=(const double& other);
		Matrix<T>& operator*=(const Matrix<T>& other);
		Matrix<T>& operator+=(const Matrix<T>& other);
		Matrix<T>& operator-=(const Matrix<T>& other);
		Matrix<T> operator*(const double& scalar)const;
		Matrix<T> operator*(const Matrix<T>& other)const;
		Matrix<T> operator+(const Matrix<T>& other) const;
		Matrix<T> operator-(const Matrix<T>& other) const;

		void transpose();
		Matrix<T> transposed() const;
		Matrix<T> getCut(const size_t& row, const size_t& column);
		T getDeterminant();
		Matrix<T> getMinors();
		T getMinor(const size_t& row, const size_t& column);
		Matrix<T> getCofactors();
		T getCofactor(const size_t& row, const size_t& column);
		Matrix<T> getAdjugate();
		Matrix<T> getInverse();

		size_t getRows() const;
		size_t getColumns() const;
		
	private:
		void deepCopy(const Matrix<T>& other);
		vector<vector<T>> data_;
		bool isSquare_;
};

template <class T>
Matrix<T>::Matrix()
{
	*this = Matrix(DEFAULT_MATRIX_DIMENSIONS,DEFAULT_MATRIX_DIMENSIONS);
}

template <class T>
Matrix<T>::Matrix(const size_t& r, const size_t& c)
{
	data_ = vector<vector<T>>();
	
	isSquare_ = r == c;

	for(size_t _r = 0; _r < r; _r++)
	{
		vector<T> v;
		
		for(size_t _c = 0; _c < c; _c++)
		{
			if(_r == _c)
			{
				v.push_back(1);
			}
			else
			{
				v.push_back(0);
			}
		}
		
		data_.push_back(v);
	}
}

template <class T>
Matrix<T>::Matrix(const Matrix<T>& other)
{
	deepCopy(other);
}

template <class T>
Matrix<T>::Matrix(Matrix&& other)
{
	deepCopy(other);

	other.data_.clear();

	other.isSquare_ = true;
}

template <class T>
Matrix<T>::~Matrix()
{
	
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other)
{
	deepCopy(other);

	return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator=(Matrix&& other)
{
	deepCopy(other);

	other.data_.clear();

	other.isSquare_ = true;

	return *this;
}

template <class T>
vector<T>& Matrix<T>::operator[](const size_t& i)
{
	return data_[i];
}

template <class T>
const vector<T>& Matrix<T>::operator[](const size_t& i) const
{
	return data_[i];
}

template <class T>
bool Matrix<T>::operator==(const Matrix<T>& other) const
{
	//check if dimension sizes match
	bool areEqual = getRows() == other.getRows() && getColumns() == other.getColumns();

	//if the dimensions were equal
	if (areEqual) 
	{
		//check the data
		size_t currentlyCheckedRow = 0;
		size_t currentlyCheckedColumn;

		//while no data has not matched and we have not checked all rows
		while(currentlyCheckedRow < getRows() && areEqual)
		{
			currentlyCheckedColumn = 0;

			//while no data has not matched and we have  not checked all columns
			while (currentlyCheckedColumn < getColumns() && areEqual)
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

template <class T>
bool Matrix<T>::operator!=(const Matrix<T>& rhs) const
{
	return !(*this == rhs);
}

template <class T>
Matrix<T>& Matrix<T>::operator*=(const double& other)
{
	*this = *this * other;
	return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& other)
{
	*this = *this * other;
	return *this;
}

template<class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& other)
{
	*this = *this + other;
	return *this;
}

template<class T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& other)
{
	*this = *this - other;
	return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const double& scalar) const
{
	//make a deep copy of myself
	Matrix<T> returnMatrix(*this);

	int r = data_.size();
	int c = data_[0].size();

	//for each row 
	for (int row = 0; row < r; row++)
	{
		//for each column
		for (int column = 0; column < c; column++)
		{
			//for each spot multiply by scalar
			returnMatrix[row][column] *= scalar;
		}
	}

	return returnMatrix;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const
{
	size_t innerDimension = getColumns();

	if(innerDimension != other.getRows())
	{
		throw std::logic_error("Matrix.h - operator*:Matrix inner dimensions must match.");
	}
	
	size_t newRows = getRows();
	size_t newColumns = other.getColumns();

	Matrix<T> ret(newRows, newColumns);

	for (size_t r = 0; r < newRows; r++)
	{
		for (size_t c = 0; c < newColumns; c++)
		{
			T currentSpotValue = T();

			for (size_t i = 0; i < innerDimension; i++)
			{
				currentSpotValue += data_[r][i] * other[i][c];
			}

			ret[r][c] = currentSpotValue;
		}
	}	

	return ret;
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const
{
	size_t r = getRows();
	size_t c = getColumns();

	Matrix<T> returnMatrix(r,c);

	//if both matrix sizes match
	if (r == other.getRows() && c == other.getColumns())
	{
		//make a deep copy of other
		returnMatrix = Matrix(other);

		//for each row 
		for (size_t row = 0; row < r; row++)
		{
			//for each column
			for (size_t column = 0; column < c; column++)
			{
				//for each spot add my values to the copy
				returnMatrix[row][column] += data_[row][column];
			}
		}
	}
	else
	{
		throw std::logic_error("Matrix.h - operator+:Matrix dimensions must match.");
	}

	return returnMatrix;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const
{
	size_t r = data_.size();
	size_t c = data_[0].size();

	Matrix<T> returnMatrix(r,c);

	//if both matrix sizes match
	if (r == other.data_.size() && c == other.data_[0].size())
	{
		//make a deep copy of other
		returnMatrix = Matrix(other);

		//for each row 
		for (size_t row = 0; row < r; row++)
		{
			//for each column
			for (size_t column = 0; column < c; column++)
			{
				//for each spot subtract my values to the copy
				returnMatrix[row][column] -= data_[row][column];
			}
		}
	}
	else
	{
		throw std::logic_error("Matrix.h - operator-:Matrix dimensions must match.");
	}

	return returnMatrix;
}

template<class T>
void Matrix<T>::transpose()
{
	vector<vector<T>> newData;

	//r and c are flipped here because we are transposing the matrix
	int c = data_.size();
	int r = data_[0].size();

	for(int _r = 0; _r < r; _r++)
	{
		vector<T> v;
		
		for(int _c = 0; _c < c; _c++)
		{
			v.push_back(data_[_c][_r]);
		}
		
		newData.push_back(v);
	}

	data_ = move(newData);
}

template<class T>
Matrix<T> Matrix<T>::transposed() const
{
	Matrix<T> copy(*this);

	copy.transpose();

	return copy;
}

template <class T>
size_t Matrix<T>::getRows() const
{
	return data_.size();
}

template <class T>
size_t Matrix<T>::getColumns() const
{
	size_t retVal = 0;
	
	if(!data_.empty())
	{
		retVal = data_[0].size();
	}

	return retVal;
}

template <class T>
void Matrix<T>::deepCopy(const Matrix<T>& other)
{
	data_ = vector<vector<T>>();

	int r = other.data_.size();
	int c = other.data_[0].size();
	
	for(int _r = 0; _r < r; _r++)
	{
		vector<T> v;
		
		for(int _c = 0; _c < c; _c++)
		{
			v.push_back(other.data_[_r][_c]);
		}
		
		data_.push_back(v);
	}

	isSquare_ = other.isSquare_;
}

template <class T>
std::ostream & operator<<(std::ostream & os, const Matrix<T>& v)
{
	for (size_t r = 0; r < v.getRows(); r++)
	{
		os << "[\t";

		for (size_t c = 0; c < v.getColumns(); c++)
		{
			os << v[r][c] << '\t';
		}

		os << "]\n";
	}

	return os;
}

template <class T>
Matrix<T> Matrix<T>::getCut(const size_t& row, const size_t& column)
{
	if(!isSquare_)
	{
		throw std::logic_error("Matrix.h - getCut:Matrix must be square\n");
	}

	size_t originalDimension = data_.size();

	Matrix<T> returnMatrix(originalDimension - 1, originalDimension - 1);

	const size_t MIN_SIZE = 2;

	if(originalDimension < MIN_SIZE)
	{
		throw std::logic_error("Matrix.h - getCut:Matrix does not meet minimum size requirement\n");
	}
	else if(row >= originalDimension)
	{
		throw std::logic_error("Matrix.h - getCut:row is out of bounds of the original Matrix\n");
	}
	else if(column >= originalDimension)
	{
		throw std::logic_error("Matrix.h - getCut:column is out of bounds of the original Matrix\n");
	}
	else
	{
		size_t newMatrixRowIndex = 0;
		size_t newMatrixColumnIndex;
		
		for(size_t currentRowInOrig = 0; currentRowInOrig < originalDimension; currentRowInOrig++)
		{
			newMatrixColumnIndex = 0;

			if(currentRowInOrig != row)
			{
				for(size_t currentColumnInOrig = 0; currentColumnInOrig < originalDimension; currentColumnInOrig++)
				{
					if(currentColumnInOrig != column)
					{
						returnMatrix[newMatrixRowIndex][newMatrixColumnIndex] =  this->data_[currentRowInOrig][currentColumnInOrig];
						newMatrixColumnIndex++;
					}
				}

				newMatrixRowIndex++;
			}
		}
	}
	
	return returnMatrix;
}

template <class T>
T Matrix<T>::getDeterminant()
{
	if(!isSquare_)
	{
		throw std::logic_error("Matrix.h - getDeterminant:Matrix must be square\n");
	}

	const size_t MIN_DIMENSIONS = 2;

	size_t dimensions = data_.size();

	T sum = T();
	if(dimensions >= MIN_DIMENSIONS)
	{
		//loop through any row of the matrix 
		for(size_t columnElement = 0; columnElement < data_.size(); columnElement++)
		{
			//sum up the result of multiplying each of the elements in the row by their respective cofactor.
			sum += this->data_[0][columnElement] * getCofactor(0,columnElement);
		}
	}
	else
	{
		sum += this->data_[0][0];
	}
	
	return sum;
}

template <class T>
Matrix<T> Matrix<T>::getMinors()
{
	size_t dimensions = data_.size();

	Matrix<T> returnMatrix(dimensions, dimensions);

	for(size_t row = 0; row < dimensions; row++)
	{
		for(size_t column = 0; column < dimensions; column++)
		{
			returnMatrix[row][column] = getMinor(row,column);
		}
	}

	return returnMatrix;
}

template <class T>
T Matrix<T>::getMinor(const size_t& row, const size_t& column)
{
	if(!isSquare_)
	{
		throw std::logic_error("Matrix.h - getMinor:Matrix must be square\n");
	}

	size_t originalDimension = data_.size();

	Matrix<T> smallerMatrix(originalDimension - 1, originalDimension - 1);

	const size_t MIN_SIZE = 2;

	if(originalDimension < MIN_SIZE)
	{
		throw std::logic_error("Matrix.h - getMinor:Matrix does not meet minimum size requirement\n");
	}
	else if(row >= originalDimension)
	{
		throw std::logic_error("Matrix.h - getMinor:row is out of bounds of the original Matrix\n");
	}
	else if(column >= originalDimension)
	{
		throw std::logic_error("Matrix.h - getMinor:column is out of bounds of the original Matrix\n");
	}
	else
	{
		smallerMatrix = getCut(row,column);
	}
	
	return smallerMatrix.getDeterminant();
}

template <class T>
Matrix<T> Matrix<T>::getCofactors()
{
	size_t dimensions = data_.size();

	Matrix<T> returnMatrix(dimensions, dimensions);

	for(size_t row = 0; row < dimensions; row++)
	{
		for(size_t column = 0; column < dimensions; column++)
		{
			returnMatrix[row][column] = getCofactor(row,column);
		}
	}

	return returnMatrix;
}

template <class T>
T Matrix<T>::getCofactor(const size_t& row, const size_t& column)
{
	if(!isSquare_)
	{
		throw std::logic_error("Matrix.h - getCofactor:Matrix must be square\n");
	}

	size_t originalDimension = data_.size();

	const size_t MIN_SIZE = 2;

	if(originalDimension < MIN_SIZE)
	{
		throw std::logic_error("Matrix.h - getCofactor:Matrix does not meet minimum size requirement\n");
	}
	else if(row >= originalDimension)
	{
		throw std::logic_error("Matrix.h - getCofactor:row is out of bounds of the original Matrix\n");
	}
	else if(column >= originalDimension)
	{
		throw std::logic_error("Matrix.h - getCofactor:column is out of bounds of the original Matrix\n");
	}

	return getMinor(row,column) * pow(-1,(row + column));
}

template <class T>
Matrix<T> Matrix<T>::getAdjugate()
{
	Matrix<T> ret = getCofactors();

	ret.transpose();

	return ret;
}

template <class T>
Matrix<T> Matrix<T>::getInverse()
{	
	Matrix<T> ret = Matrix(data_.size(), data_.size());

	T determinant = getDeterminant();

	if(!PhysicsHelper::epsilonCompare(determinant, 0.0))
	{
		ret = getAdjugate() * (1.0 / determinant);
	}

	return ret;
}
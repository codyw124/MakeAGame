#pragma once

#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>
#include <cmath>

using namespace std;

template <class T>
class Matrix
{
	protected:
		vector<vector<T>> data_;
		
	public:
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

		size_t getRows() const;
		size_t getColumns() const;
		
	private:
		void deepCopy(const Matrix<T>& other);
};

template <class T>
std::ostream& operator<<(std::ostream & os, const Matrix<T>& v);

template <class T>
Matrix<T>::Matrix(const size_t& r, const size_t& c)
{
	data_ = vector<vector<T>>();
	
	for(size_t _r = 0; _r < r; _r++)
	{
		vector<T> v;
		
		for(size_t _c = 0; _c < c; _c++)
		{
			v.push_back(0);
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
		throw std::logic_error("Matrix inner dimensions must match.");
	}
	
	size_t newRows = getRows();
	size_t newColumns = other.getColumns();

	Matrix<T> ret(newRows, newColumns);

	for (size_t r = 0; r < newRows; r++)
	{
		for (size_t c = 0; c < newColumns; c++)
		{
			for (size_t i = 0; i < innerDimension; i++)
			{
				ret[r][c] += data_[r][i] * other[i][c];
			}
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
		throw std::logic_error("Matrix dimensions must match.");
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
		throw std::logic_error("Matrix dimensions must match.");
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
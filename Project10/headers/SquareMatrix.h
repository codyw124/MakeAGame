//Cody Ware
//1/19/19

#pragma once

#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>
#include <cmath>
#include "../headers/Matrix.h"
#include "../headers/PhysicsHelper.h"

using namespace std;

template <class T>
class SquareMatrix : public Matrix<T>
{
	public:
		SquareMatrix(const size_t& dimensions);

		size_t getDimensions();
		SquareMatrix<T> getCut(const size_t& row, const size_t& column);
		T getDeterminant();
		SquareMatrix<T> getMinors();
		T getMinor(const size_t& row, const size_t& column);
		SquareMatrix<T> getCofactors();
		T getCofactor(const size_t& row, const size_t& column);
		SquareMatrix<T> getAdjugate();
		SquareMatrix<T> getInverse();
};

template <class T>
SquareMatrix<T>::SquareMatrix(const size_t& dimensions) : Matrix<T>(dimensions, dimensions)
{

}

template <class T>
size_t SquareMatrix<T>::getDimensions()
{
	return this->getRows();
}

template <class T>
SquareMatrix<T> SquareMatrix<T>::getCut(const size_t& row, const size_t& column)
{
	size_t originalDimension = getDimensions();

	SquareMatrix<T> returnMatrix(originalDimension-1);

	const size_t MIN_SIZE = 2;

	if(originalDimension < MIN_SIZE)
	{
		throw std::logic_error("Matrix does not meet minimum size requirement\n");
	}
	else if(row >= originalDimension)
	{
		throw std::logic_error("row is out of bounds of the original Matrix\n");
	}
	else if(column >= originalDimension)
	{
		throw std::logic_error("column is out of bounds of the original Matrix\n");
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
T SquareMatrix<T>::getDeterminant()
{
	const size_t MIN_DIMENSIONS = 2;

	size_t dimensions = getDimensions();

	T sum = T();
	if(dimensions >= MIN_DIMENSIONS)
	{
		//loop through any row of the matrix 
		for(size_t columnElement = 0; columnElement < getDimensions(); columnElement++)
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
SquareMatrix<T> SquareMatrix<T>::getMinors()
{
	size_t dimensions = getDimensions();

	SquareMatrix<T> returnMatrix(dimensions);

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
T SquareMatrix<T>::getMinor(const size_t& row, const size_t& column)
{
	size_t originalDimension = getDimensions();

	SquareMatrix<T> smallerMatrix(originalDimension - 1);

	const size_t MIN_SIZE = 2;

	if(originalDimension < MIN_SIZE)
	{
		throw std::logic_error("Matrix does not meet minimum size requirement\n");
	}
	else if(row >= originalDimension)
	{
		throw std::logic_error("row is out of bounds of the original Matrix\n");
	}
	else if(column >= originalDimension)
	{
		throw std::logic_error("column is out of bounds of the original Matrix\n");
	}
	else
	{
		smallerMatrix = getCut(row,column);
	}
	
	return smallerMatrix.getDeterminant();
}

template <class T>
SquareMatrix<T> SquareMatrix<T>::getCofactors()
{
	size_t dimensions = getDimensions();

	SquareMatrix<T> returnMatrix(dimensions);

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
T SquareMatrix<T>::getCofactor(const size_t& row, const size_t& column)
{
	size_t originalDimension = getDimensions();

	const size_t MIN_SIZE = 2;

	if(originalDimension < MIN_SIZE)
	{
		throw std::logic_error("Matrix does not meet minimum size requirement\n");
	}
	else if(row >= originalDimension)
	{
		throw std::logic_error("row is out of bounds of the original Matrix\n");
	}
	else if(column >= originalDimension)
	{
		throw std::logic_error("column is out of bounds of the original Matrix\n");
	}

	return getMinor(row,column) * pow(-1,(row + column));
}

template <class T>
SquareMatrix<T> SquareMatrix<T>::getAdjugate()
{
	SquareMatrix<T> ret = getCofactors();

	ret.transpose();

	return ret;
}

template <class T>
SquareMatrix<T> SquareMatrix<T>::getInverse()
{
	// T determinant = getDeterminant();
	
	// SquareMatrix<T> ret = SquareMatrix(getDimensions());

	// if(!)
	// {
	// 	ret = getAdjugate() * (1.0 / determinant);
	// }	

	SquareMatrix<T> ret;
	return ret;
}
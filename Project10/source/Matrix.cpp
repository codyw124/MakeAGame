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
		// void adjugate();
		// void inverse();
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

	if(originalDimension >= MIN_SIZE)
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

	T sum;
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

	if(originalDimension >= MIN_SIZE)
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
			returnMatrix = getCofactor(row,column);
		}
	}

	return returnMatrix;
}

template <class T>
T SquareMatrix<T>::getCofactor(const size_t& row, const size_t& column)
{
	size_t originalDimension = getDimensions();

	const size_t MIN_SIZE = 2;

	if(originalDimension >= MIN_SIZE)
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

// template <class T>
// void SquareMatrix<T>::adjugate()
// {

// }

// template <class T>
// void SquareMatrix<T>::inverse()
// {

// }

void T01_defaultConstructor();
void T02_copyConstructor();
void T03_moveConstructor();
void T04_assignmentOperator();
void T05_moveAssignmentOperator();
void T06_accessOperator();
void T07_transpose();
void T08_transposed();
void T09_multiplicationOperator();
void T10_additionOperator();
void T11_subtractionOperator();
void T12_equivalence();
void T13_outputoperator();
void T14_defaultConstructSquareMatrix();
void T15_cut();
void T16_testDeterminant();

int main()
{
	T01_defaultConstructor();
	T02_copyConstructor();
	T03_moveConstructor();
	T04_assignmentOperator();
	T05_moveAssignmentOperator();
	T06_accessOperator();
	T07_transpose();
	T08_transposed();
	T09_multiplicationOperator();
	T10_additionOperator();
	T11_subtractionOperator();
	T12_equivalence();
	T13_outputoperator();
	T14_defaultConstructSquareMatrix();
	T15_cut();
	T16_testDeterminant();

	cout<< "All Tests Passed" << endl;
}

void T01_defaultConstructor()
{
	Matrix<int> a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);
}

void T02_copyConstructor()
{
	Matrix<int> a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);

	Matrix<int> b(a);

	assert(0.0 == b[0][0]);
	assert(1.0 == b[0][1]);
	assert(2.0 == b[0][2]);
	assert(3.0 == b[1][0]);
	assert(4.0 == b[1][1]);
	assert(5.0 == b[1][2]);
	assert(6.0 == b[2][0]);
	assert(7.0 == b[2][1]);
	assert(8.0 == b[2][2]);

	b[0][0] = 7;

	assert(7.0 == b[0][0]);
	assert(0.0 == a[0][0]);
}

void T03_moveConstructor()
{
	//make a 3X3 matrix with those values
	Matrix<int> a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	//make sure they are in the matrix
	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);

	//make a matrix and move the memory of 'a' into this matrix
	Matrix<int> moveHere(std::move(a));

	//make sure the rows and columns reflect the dimensions of a matrix with no data
	assert(0 == a.getRows());
	assert(0 == a.getColumns());

	//make sure that everything got moved
	assert(0.0 == moveHere[0][0]);
	assert(1.0 == moveHere[0][1]);
	assert(2.0 == moveHere[0][2]);
	assert(3.0 == moveHere[1][0]);
	assert(4.0 == moveHere[1][1]);
	assert(5.0 == moveHere[1][2]);
	assert(6.0 == moveHere[2][0]);
	assert(7.0 == moveHere[2][1]);
	assert(8.0 == moveHere[2][2]);
}

void T04_assignmentOperator()
{
	//make a 3X3 matrix with those values
	Matrix<int> a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	//make sure they are in the matrix
	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);

	//make a matrix and move the memory of 'a' into this matrix
	Matrix<int> assignment(3, 3);

	assignment = a;

	//check that 'a' still has its original values
	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);

	//make sure that everything got moved
	assert(0.0 == assignment[0][0]);
	assert(1.0 == assignment[0][1]);
	assert(2.0 == assignment[0][2]);
	assert(3.0 == assignment[1][0]);
	assert(4.0 == assignment[1][1]);
	assert(5.0 == assignment[1][2]);
	assert(6.0 == assignment[2][0]);
	assert(7.0 == assignment[2][1]);
	assert(8.0 == assignment[2][2]);
}

void T05_moveAssignmentOperator()
{
	//make a 3X3 matrix with those values
	Matrix<int> a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	//make sure they are in the matrix
	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);

	//make a matrix and move the memory of 'a' into this matrix
	Matrix<int> moveHere = std::move(a);

	//make sure the rows and columns reflect the dimensions of a matrix with no data
	assert(0 == a.getRows());
	assert(0 == a.getColumns());

	//make sure that everything got moved
	assert(0.0 == moveHere[0][0]);
	assert(1.0 == moveHere[0][1]);
	assert(2.0 == moveHere[0][2]);
	assert(3.0 == moveHere[1][0]);
	assert(4.0 == moveHere[1][1]);
	assert(5.0 == moveHere[1][2]);
	assert(6.0 == moveHere[2][0]);
	assert(7.0 == moveHere[2][1]);
	assert(8.0 == moveHere[2][2]);
}

void T06_accessOperator()
{
	//make a 3X3 matrix with those values
	Matrix<int> a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	//make sure they are in the matrix
	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);

	const int X = 0;
	assert(0.0 == a[X][X]);
}

void T07_transpose()
{
	//make a 3X3 matrix with those values
	Matrix<int> a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	//make sure they are in the matrix
	assert(0.0 == a[0][0]);assert(1.0 == a[0][1]);assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);assert(4.0 == a[1][1]);assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);assert(7.0 == a[2][1]);assert(8.0 == a[2][2]);

	//transpose it
	a.transpose();

	//make sure they are transposed
	assert(0.0 == a[0][0]);assert(3.0 == a[0][1]);assert(6.0 == a[0][2]);
	assert(1.0 == a[1][0]);assert(4.0 == a[1][1]);assert(7.0 == a[1][2]);
	assert(2.0 == a[2][0]);assert(5.0 == a[2][1]);assert(8.0 == a[2][2]);
}

void T08_transposed()
{

	//make a 3X3 matrix with those values
	Matrix<int> a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	//make sure they are in the matrix
	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);

	//transpose it
	Matrix<int> transposed = a.transposed();

	//make sure they are transposed
	assert(0.0 == transposed[0][0]);
	assert(3.0 == transposed[0][1]);
	assert(6.0 == transposed[0][2]);
	assert(1.0 == transposed[1][0]);
	assert(4.0 == transposed[1][1]);
	assert(7.0 == transposed[1][2]);
	assert(2.0 == transposed[2][0]);
	assert(5.0 == transposed[2][1]);
	assert(8.0 == transposed[2][2]);
}

void T09_multiplicationOperator()
{
	//make a 3X3 matrix with those values
	Matrix<int> a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	//make sure they are in the matrix
	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);

	//multiply by 3
	Matrix<int> b = a * 3;

	//make sure matrix a is the same
	assert(0.0 == a[0][0]);
	assert(1.0 == a[0][1]);
	assert(2.0 == a[0][2]);
	assert(3.0 == a[1][0]);
	assert(4.0 == a[1][1]);
	assert(5.0 == a[1][2]);
	assert(6.0 == a[2][0]);
	assert(7.0 == a[2][1]);
	assert(8.0 == a[2][2]);

	//make sure matrix b has the right values
	assert(0.0 == b[0][0]);
	assert(3.0 == b[0][1]);
	assert(6.0 == b[0][2]);
	assert(9.0 == b[1][0]);
	assert(12.0 == b[1][1]);
	assert(15.0 == b[1][2]);
	assert(18.0 == b[2][0]);
	assert(21.0 == b[2][1]);
	assert(24.0 == b[2][2]);

	//use shorthand
	a *= 3;

	//make sure a has right values now
	assert(0.0 == a[0][0]);
	assert(3.0 == a[0][1]);
	assert(6.0 == a[0][2]);
	assert(9.0 == a[1][0]);
	assert(12.0 == a[1][1]);
	assert(15.0 == a[1][2]);
	assert(18.0 == a[2][0]);
	assert(21.0 == a[2][1]);
	assert(24.0 == a[2][2]);

	//make a 2X3 matrix and a 3X2 matrix and a 2X2 to test multiplying two matrices
	//make a 2X3 matrix with those values
	Matrix<int> x(2, 3);

	x[0][0] = 2;
	x[0][1] = 3;
	x[0][2] = 4;
	x[1][0] = 5;
	x[1][1] = 6;
	x[1][2] = 7;

	//make a 3X2 matrix with those values
	Matrix<int> y(3, 2);

	y[0][0] = 10;
	y[0][1] = 20;
	y[1][0] = 30;
	y[1][1] = 40;
	y[2][0] = 50;
	y[2][1] = 60;

	//make a 2X2 matrix with those values
	Matrix<int> z(2, 2);

	z[0][0] = 310;
	z[0][1] = 400;
	z[1][0] = 580;
	z[1][1] = 760;

	//check the operator=(Matrix other)
	assert(z == (x*y));

	//check the operator*=(Matrix other)
	x *= y;

	assert(z == x);
}

void T10_additionOperator()
{
	//make a 3X3 matrix with those values
	Matrix<int> a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	Matrix<int> b(3, 3);

	b[0][0] = 0.0;
	b[0][1] = 1.0;
	b[0][2] = 2.0;
	b[1][0] = 3.0;
	b[1][1] = 4.0;
	b[1][2] = 5.0;
	b[2][0] = 6.0;
	b[2][1] = 7.0;
	b[2][2] = 8.0;

	Matrix<int> aplusb(3, 3);

	aplusb[0][0] = 0.0;
	aplusb[0][1] = 2.0;
	aplusb[0][2] = 4.0;
	aplusb[1][0] = 6.0;
	aplusb[1][1] = 8.0;
	aplusb[1][2] = 10.0;
	aplusb[2][0] = 12.0;
	aplusb[2][1] = 14.0;
	aplusb[2][2] = 16.0;

	assert((a + b) == aplusb);

	b += a;

	assert(b == aplusb);

	//make a 2X2 matrix
	Matrix<int> twobytwo(2, 2);

	twobytwo[0][0] = 0.0;
	twobytwo[0][1] = 1.0;
	twobytwo[1][0] = 2.0;
	twobytwo[1][1] = 3.0;

	//do an operation that should thow an exception
	try
	{
		//if it doesnt throw it should fail
		a + twobytwo;
		assert(false);
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true);
	}
}

void T11_subtractionOperator()
{
	//make a 3X3 matrix with those values
	Matrix<int> a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	Matrix<int> b(3, 3);

	b[0][0] = 0.0;
	b[0][1] = 1.0;
	b[0][2] = 2.0;
	b[1][0] = 3.0;
	b[1][1] = 4.0;
	b[1][2] = 5.0;
	b[2][0] = 6.0;
	b[2][1] = 7.0;
	b[2][2] = 8.0;

	Matrix<int> aminusb(3, 3);

	aminusb[0][0] = 0.0;
	aminusb[0][1] = 0.0;
	aminusb[0][2] = 0.0;
	aminusb[1][0] = 0.0;
	aminusb[1][1] = 0.0;
	aminusb[1][2] = 0.0;
	aminusb[2][0] = 0.0;
	aminusb[2][1] = 0.0;
	aminusb[2][2] = 0.0;

	assert((a - b) == aminusb);

	b -= a;

	assert(b == aminusb);

	//make a 2X2 matrix
	Matrix<int> twobytwo(2, 2);

	twobytwo[0][0] = 0;
	twobytwo[0][1] = 1;
	twobytwo[1][0] = 2;
	twobytwo[1][1] = 3;

	//do an operation that should trhow an exception
	try
	{
		//if it doesn't throw it should fail
		a - twobytwo;
		assert(false);
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true);
	}
}

void T12_equivalence()
{
	Matrix<int> a(3, 3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	Matrix<int> b(a);

	Matrix<int> c(3, 3);

	c[0][0] = 4.0;
	c[0][1] = 4.0;
	c[0][2] = 4.0;
	c[1][0] = 4.0;
	c[1][1] = 4.0;
	c[1][2] = 4.0;
	c[2][0] = 4.0;
	c[2][1] = 4.0;
	c[2][2] = 4.0;

	Matrix<int> d(2, 3);

	d[0][0] = 4.0;
	d[0][1] = 4.0;
	d[0][2] = 4.0;
	d[1][0] = 4.0;
	d[1][1] = 4.0;
	d[1][2] = 4.0;

	//equal if same size and data
	assert(a == b);

	//not equal if same size different data
	assert(a != c);

	//not equal if different size similar data
	assert(d != c);

}

void T13_outputoperator()
{
	Matrix<int> a(3,3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	std::stringstream out;

	out << a;

	std::string testText = "[\t0\t1\t2\t]\n[\t3\t4\t5\t]\n[\t6\t7\t8\t]\n";

	assert(testText == out.str());
}

void T14_defaultConstructSquareMatrix()
{
	SquareMatrix<int> x(3);

	assert(x.getColumns() == 3);
	assert(x.getRows() == 3);
	assert(x.getDimensions() == 3);
}

void T15_cut()
{
	SquareMatrix<int> a(3);

	a[0][0] = 0.0;
	a[0][1] = 1.0;
	a[0][2] = 2.0;
	a[1][0] = 3.0;
	a[1][1] = 4.0;
	a[1][2] = 5.0;
	a[2][0] = 6.0;
	a[2][1] = 7.0;
	a[2][2] = 8.0;

	SquareMatrix<int> b = a.getCut(1,1);

	SquareMatrix<int> c(2);

	c[0][0] = 0;
	c[0][1] = 2;
	c[1][0] = 6;
	c[1][1] = 8;

	assert(b == c);

	SquareMatrix<int> d(1);

	//make sure you cant cut a 1 dimensional matrix
	try
	{
		d.getCut(1,1);
		assert(false);
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true);
	}

	//make sure that it throws an exception for out of range tests
	try
	{
		a.getCut(5,5);
		assert(false);
	}
	catch (std::logic_error e)
	{
		//otherwise it passed
		assert(true);
	}
}

void T16_testDeterminant()
{
	SquareMatrix<int> a(1);

	a[0][0] = 5.0;
	
	int adet = a.getDeterminant();

	assert(adet == 5);

	SquareMatrix<int> b(3);

	b[0][0] = 1.0;
	b[0][1] = 2.0;
	b[0][2] = 3.0;
	b[1][0] = 4.0;
	b[1][1] = 5.0;
	b[1][2] = 6.0;
	b[2][0] = 7.0;
	b[2][1] = 8.0;
	b[2][2] = 9.0;

	int bdet = b.getDeterminant();

	assert(bdet == 0);
}
// T getDeterminant();
// SquareMatrix<T> getMinors();
// T getMinor(const size_t& row, const size_t& column);
// SquareMatrix<T> getCofactors();
// T getCofactor(const size_t& row, const size_t& column);
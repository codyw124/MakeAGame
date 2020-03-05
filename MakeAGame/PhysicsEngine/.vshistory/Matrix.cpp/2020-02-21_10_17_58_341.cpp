//cody ware
//7/16/2019

#include "Matrix.h"

Matrix::Matrix()
{
	*this = Matrix(DEFAULT_MATRIX_DIMENSIONS, DEFAULT_MATRIX_DIMENSIONS);
}

Matrix::Matrix(const size_t& r, const size_t& c)
{
	rows_ = r;
	columns_ = c;
	data_ = new double*[rows_];
	for(size_t rowInitIndex = 0; rowInitIndex < rows_; rowInitIndex++)
	{
		data_[rowInitIndex] = new double[columns_];
		for (size_t columnInitIndex = 0; columnInitIndex < columns_; columnInitIndex++)
		{
			if (rowInitIndex == columnInitIndex)
			{
				data_[rowInitIndex][columnInitIndex] = 1;
			}
			else
			{
				data_[rowInitIndex][columnInitIndex] = 0;
			}
		}
	}

	isSquare_ = rows_ == columns_;
}

Matrix::Matrix(const Matrix& other)
{
	deepCopy(other);
}

Matrix::Matrix(Matrix&& other) noexcept
{
	deepCopy(other);

	other.data_.clear();

	other.isSquare_ = true;
}

Matrix::~Matrix()
{

}

Matrix& Matrix::operator=(const Matrix& other)
{
	deepCopy(other);

	return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept
{
	deepCopy(other);

	other.data_.clear();

	other.isSquare_ = true;

	return *this;
}

std::vector<double>& Matrix::operator[](const size_t& i)
{
	return data_[i];
}

const std::vector<double>& Matrix::operator[](const size_t& i) const
{
	return data_[i];
}

bool Matrix::operator==(const Matrix& other) const
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
		while (currentlyCheckedRow < getRows() && areEqual)
		{
			currentlyCheckedColumn = 0;

			//while no data has not matched and we have  not checked all columns
			while (currentlyCheckedColumn < getColumns() && areEqual)
			{
				//make sure this piece of data matches
				areEqual = PhysicsHelper::epsilonCompare(data_[currentlyCheckedRow][currentlyCheckedColumn], other.data_[currentlyCheckedRow][currentlyCheckedColumn]);

				currentlyCheckedColumn++;
			}

			currentlyCheckedRow++;
		}
	}

	return areEqual;
}

bool Matrix::operator!=(const Matrix& rhs) const
{
	return !(*this == rhs);
}

Matrix& Matrix::operator*=(const double& other)
{
	*this = *this * other;
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
	*this = *this * other;
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	*this = *this + other;
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	*this = *this - other;
	return *this;
}

Matrix Matrix::operator*(const double& scalar) const
{
	//make a deep copy of myself
	Matrix returnMatrix(*this);

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

Matrix Matrix::operator*(const Matrix& other) const
{
	size_t innerDimension = getColumns();

	if (innerDimension != other.getRows())
	{
		throw std::logic_error("Matrix.h - operator*:Matrix inner dimensions must match.");
	}

	size_t newRows = getRows();
	size_t newColumns = other.getColumns();

	Matrix ret(newRows, newColumns);

	for (size_t r = 0; r < newRows; r++)
	{
		for (size_t c = 0; c < newColumns; c++)
		{
			double currentSpotValue = 0;

			for (size_t i = 0; i < innerDimension; i++)
			{
				currentSpotValue += data_[r][i] * other.data_[i][c];
			}

			ret[r][c] = currentSpotValue;
		}
	}

	return ret;
}

Matrix Matrix::operator+(const Matrix& other) const
{
	size_t r = getRows();
	size_t c = getColumns();

	Matrix returnMatrix(r, c);

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

Matrix Matrix::operator-(const Matrix& other) const
{
	size_t r = data_.size();
	size_t c = data_[0].size();

	Matrix returnMatrix(r, c);

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

void Matrix::transpose()
{
	std::vector<std::vector<double>> newData;

	//r and c are flipped here because we are transposing the matrix
	int c = data_.size();
	int r = data_[0].size();

	for (int _r = 0; _r < r; _r++)
	{
		std::vector<double> v;

		for (int _c = 0; _c < c; _c++)
		{
			v.push_back(data_[_c][_r]);
		}

		newData.push_back(v);
	}

	data_ = move(newData);
}

Matrix Matrix::transposed() const
{
	Matrix copy(*this);

	copy.transpose();

	return copy;
}

size_t Matrix::getRows() const
{
	return data_.size();
}

size_t Matrix::getColumns() const
{
	size_t retVal = 0;

	if (!data_.empty())
	{
		retVal = data_[0].size();
	}

	return retVal;
}

void Matrix::deepCopy(const Matrix& other)
{
	data_ = std::vector<std::vector<double>>();

	int r = other.data_.size();
	int c = other.data_[0].size();

	for (int _r = 0; _r < r; _r++)
	{
		std::vector<double> v;

		for (int _c = 0; _c < c; _c++)
		{
			v.push_back(other.data_[_r][_c]);
		}

		data_.push_back(v);
	}

	isSquare_ = other.isSquare_;
}

Matrix Matrix::getCut(const size_t& row, const size_t& column)
{
	if (!isSquare_)
	{
		throw std::logic_error("Matrix.h - getCut:Matrix must be square\n");
	}

	size_t originalDimension = data_.size();

	Matrix returnMatrix(originalDimension - 1, originalDimension - 1);

	const size_t MIN_SIZE = 2;

	if (originalDimension < MIN_SIZE)
	{
		throw std::logic_error("Matrix.h - getCut:Matrix does not meet minimum size requirement\n");
	}
	else if (row >= originalDimension)
	{
		throw std::logic_error("Matrix.h - getCut:row is out of bounds of the original Matrix\n");
	}
	else if (column >= originalDimension)
	{
		throw std::logic_error("Matrix.h - getCut:column is out of bounds of the original Matrix\n");
	}
	else
	{
		size_t newMatrixRowIndex = 0;
		size_t newMatrixColumnIndex;

		for (size_t currentRowInOrig = 0; currentRowInOrig < originalDimension; currentRowInOrig++)
		{
			newMatrixColumnIndex = 0;

			if (currentRowInOrig != row)
			{
				for (size_t currentColumnInOrig = 0; currentColumnInOrig < originalDimension; currentColumnInOrig++)
				{
					if (currentColumnInOrig != column)
					{
						returnMatrix[newMatrixRowIndex][newMatrixColumnIndex] = this->data_[currentRowInOrig][currentColumnInOrig];
						newMatrixColumnIndex++;
					}
				}

				newMatrixRowIndex++;
			}
		}
	}

	return returnMatrix;
}

double Matrix::getDeterminant()
{
	if (!isSquare_)
	{
		throw std::logic_error("Matrix.h - getDeterminant:Matrix must be square\n");
	}

	const size_t MIN_DIMENSIONS = 2;

	size_t dimensions = data_.size();

	double sum = 0;
	if (dimensions >= MIN_DIMENSIONS)
	{
		//loop through any row of the matrix 
		for (size_t columnElement = 0; columnElement < data_.size(); columnElement++)
		{
			//sum up the result of multiplying each of the elements in the row by their respective cofactor.
			sum += this->data_[0][columnElement] * getCofactor(0, columnElement);
		}
	}
	else
	{
		sum += this->data_[0][0];
	}

	return sum;
}

Matrix Matrix::getMinors()
{
	size_t dimensions = data_.size();

	Matrix returnMatrix(dimensions, dimensions);

	for (size_t row = 0; row < dimensions; row++)
	{
		for (size_t column = 0; column < dimensions; column++)
		{
			returnMatrix[row][column] = getMinor(row, column);
		}
	}

	return returnMatrix;
}

double Matrix::getMinor(const size_t& row, const size_t& column)
{
	if (!isSquare_)
	{
		throw std::logic_error("Matrix.h - getMinor:Matrix must be square\n");
	}

	size_t originalDimension = data_.size();

	Matrix smallerMatrix(originalDimension - 1, originalDimension - 1);

	const size_t MIN_SIZE = 2;

	if (originalDimension < MIN_SIZE)
	{
		throw std::logic_error("Matrix.h - getMinor:Matrix does not meet minimum size requirement\n");
	}
	else if (row >= originalDimension)
	{
		throw std::logic_error("Matrix.h - getMinor:row is out of bounds of the original Matrix\n");
	}
	else if (column >= originalDimension)
	{
		throw std::logic_error("Matrix.h - getMinor:column is out of bounds of the original Matrix\n");
	}
	else
	{
		smallerMatrix = getCut(row, column);
	}

	return smallerMatrix.getDeterminant();
}

Matrix Matrix::getCofactors()
{
	size_t dimensions = data_.size();

	Matrix returnMatrix(dimensions, dimensions);

	for (size_t row = 0; row < dimensions; row++)
	{
		for (size_t column = 0; column < dimensions; column++)
		{
			returnMatrix[row][column] = getCofactor(row, column);
		}
	}

	return returnMatrix;
}

double Matrix::getCofactor(const size_t& row, const size_t& column)
{
	if (!isSquare_)
	{
		throw std::logic_error("Matrix.h - getCofactor:Matrix must be square\n");
	}

	size_t originalDimension = data_.size();

	const size_t MIN_SIZE = 2;

	if (originalDimension < MIN_SIZE)
	{
		throw std::logic_error("Matrix.h - getCofactor:Matrix does not meet minimum size requirement\n");
	}
	else if (row >= originalDimension)
	{
		throw std::logic_error("Matrix.h - getCofactor:row is out of bounds of the original Matrix\n");
	}
	else if (column >= originalDimension)
	{
		throw std::logic_error("Matrix.h - getCofactor:column is out of bounds of the original Matrix\n");
	}

	return getMinor(row, column) * pow(-1, (row + column));
}

Matrix Matrix::getAdjugate()
{
	Matrix ret = getCofactors();

	ret.transpose();

	return ret;
}

Matrix Matrix::getInverse()
{
	Matrix ret = Matrix(data_.size(), data_.size());

	double determinant = getDeterminant();

	if (!PhysicsHelper::epsilonCompare(determinant, 0.0))
	{
		ret = getAdjugate() * (1.0 / determinant);
	}

	return ret;
}

PHYSICSENGINE std::ostream& operator<<(std::ostream& os, const Matrix& v)
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
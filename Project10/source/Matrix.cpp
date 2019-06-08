#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/*
todo list

*/
template <class T>
class Matrix
{
	private:
		vector<vector<T>> data_;
		
	public:
		Matrix(const int& r, const int& c);
		Matrix(const Matrix<T>& other);
		Matrix(Matrix&& other);
		~Matrix();		
		Matrix<T>& operator=(const Matrix<T>& other);
		Matrix<T>& operator=(Matrix<T>&& other);
		vector<T>& operator[](const int& i);
		bool operator==(const Matrix<T>& rhs);
		bool operator!=(const Matrix<T>& rhs);
		void operator*(const Matrix<T>& other);
		void operator*(const double& other);

		void transpose();
		Matrix<T> transposed();

		int getRows();
		int getColumns();
		
	private:
		void deepCopy(const Matrix<T>& other);
};

template <class T>
Matrix<T>::Matrix(const int& r, const int& c)
{
	data_ = vector<vector<T>>();
	
	for(int _r =0; _r < r; _r++)
	{
		vector<T> v;
		
		for(int _c = 0; _c < c; _c++)
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
vector<T>& Matrix<T>::operator[](const int& i)
{
	return data_[i];
}

template <class T>
bool Matrix<T>::operator==(const Matrix<T>& rhs)
{

}

template <class T>
bool Matrix<T>::operator!=(const Matrix<T>& rhs)
{

}

template <class T>
void Matrix<T>::deepCopy(const Matrix<T>& other)
{
	data_ = vector<vector<T>>();

	int r = other.data_.size();
	int c = other.data_[0].size();
	
	for(int _r =0; _r < r; _r++)
	{
		vector<T> v;
		
		for(int _c = 0; _c < c; _c++)
		{
			v.push_back(other.data_[_r][_c]);
		}
		
		data_.push_back(v);
	}
}

template<class T>
void Matrix<T>::transpose()
{

}

template<class T>
Matrix<T> Matrix<T>::transposed()
{
	
}

template <class T>
int Matrix<T>::getRows()
{
	return data_.size();
}

template <class T>
int Matrix<T>::getColumns()
{
	int retVal = 0;
	
	if(!data_.empty())
	{
		retVal = data_[0].size();
	}

	return retVal;
}


void T01_defaultConstructor();
void T02_copyConstructor();
void T03_moveConstructor();
void T04_assignmentOperator();
void T05_moveAssignmentOperator();
void T06_accessOperator();
void T07_transpose();
void T08_transposed();
void T09_multiplicationOperator();

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
	Matrix<int> a = Matrix<int>(3, 3);

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
	x[1][0] = 4;
	x[1][1] = 5;
	x[2][0] = 6;
	x[2][1] = 7;

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

	z[0][0] = 0;
	z[0][1] = 1;
	z[1][0] = 2;
	z[1][1] = 3;

	//check the operator=(Matrix other)
	assert(z == (x*y));

	//check the operator*=(Matrix other)
	x *= y;

	assert(z == x);
}
//Cody Ware
//9/24/18 

#include <stdexcept>
#include <algorithm>
#include <ostream>
#include <cmath>
#include "PhysicsVector.h"

//default constructor
PhysicsVector::PhysicsVector()
{
	numberOfDimensions_ = 0;
    dimensionValues_ = NULL;
}

//constructor that takes a value
PhysicsVector::PhysicsVector(double* dimensionValues, const size_t& numberOfDimensions)
{
	dimensionValues_ = dimensionValues;
    numberOfDimensions_ = numberOfDimensions;
}

//copy constructor
PhysicsVector::PhysicsVector(const PhysicsVector& other)
{
	deepCopy(other);
}

//move constructor
PhysicsVector::PhysicsVector(PhysicsVector&& other) noexcept
{
	//get the dimension values
	dimensionValues_ = other.dimensionValues_;
	other.dimensionValues_ = NULL;

	//get the number of values also
	numberOfDimensions_ = other.numberOfDimensions_;
	other.numberOfDimensions_ = 0;
}

//assignment operator
PhysicsVector& PhysicsVector::operator=(const PhysicsVector& other)
{
	if (this != &other)
	{
		deepCopy(other);
	}

	return *this;
}

//move assignment operator
PhysicsVector& PhysicsVector::operator=(PhysicsVector&& other) noexcept
{
	if (this !=&other)
	{
		//get the dimension values
		dimensionValues_ = other.dimensionValues_;
		other.dimensionValues_ = NULL;

		//get the number of values also
		numberOfDimensions_ = other.numberOfDimensions_;
		other.numberOfDimensions_ = 0;
	}

	return *this;
}

//destructor
PhysicsVector::~PhysicsVector()
{
	numberOfDimensions_ = 0;
    delete[] dimensionValues_;
}

double& PhysicsVector::operator[](const size_t& i)
{
	if (i >= numberOfDimensions_)
	{
		throw std::range_error("operator[] out of range of this " + std::to_string(numberOfDimensions_) + "D vector\n");
	}
	return dimensionValues_[i];
}

//random access operator
const double& PhysicsVector::operator[](const size_t& i) const
{
	if (i >= numberOfDimensions_)
	{
		throw std::range_error("operator[] out of range of this " + std::to_string(numberOfDimensions_) + "D vector\n");
	}
	return dimensionValues_[i];
}

//the addition operator
PhysicsVector PhysicsVector::operator+(const PhysicsVector& r) const
{
	size_t newNumberOfDimensions = std::max(numberOfDimensions_, r.numberOfDimensions_); 
	double* newDimensionValues = new double[newNumberOfDimensions];
	for(size_t i = 0; i < newNumberOfDimensions; i++)
	{
		if(numberOfDimensions_ >= (i + 1))
		{
			newDimensionValues[i] = dimensionValues_[i];
		}
		else
		{
			newDimensionValues[i] = 0;
		}

		if(r.numberOfDimensions_ >= (i + 1))
		{
			newDimensionValues[i] += r[i];
		}
	}
	return PhysicsVector(newDimensionValues, newNumberOfDimensions);
}

//the subtraction operator
PhysicsVector PhysicsVector::operator-(const PhysicsVector& r) const
{
	size_t newNumberOfDimensions = std::max(numberOfDimensions_, r.numberOfDimensions_); 
	double* newDimensionValues = new double[newNumberOfDimensions];
	for(size_t i = 0; i < newNumberOfDimensions; i++)
	{
		if(numberOfDimensions_ >= (i + 1))
		{
			newDimensionValues[i] = dimensionValues_[i];
		}
		else
		{
			newDimensionValues[i] = 0;
		}

		if(r.numberOfDimensions_ >= (i + 1))
		{
			newDimensionValues[i] -= r[i];
		}
	}
	return PhysicsVector(newDimensionValues, newNumberOfDimensions);
}

//the multiplication operator for 2 PhysicsVectors
PhysicsVector PhysicsVector::operator*(const PhysicsVector& r) const
{
	size_t newNumberOfDimensions = std::max(numberOfDimensions_, r.numberOfDimensions_); 
	double* newDimensionValues = new double[newNumberOfDimensions];
	for(size_t i = 0; i < newNumberOfDimensions; i++)
	{
		if(numberOfDimensions_ >= (i + 1))
		{
			newDimensionValues[i] = dimensionValues_[i];
		}
		else
		{
			newDimensionValues[i] = 0;
		}

		if(r.numberOfDimensions_ >= (i + 1))
		{
			newDimensionValues[i] *= r[i];
		}
	}
	return PhysicsVector(newDimensionValues, newNumberOfDimensions);
}

//the multiplication operator for multiplying a vector by a double
PhysicsVector PhysicsVector::operator*(const double& r) const
{
	double* newDimensionValues = new double[numberOfDimensions_];
	for(size_t i = 0; i < numberOfDimensions_; i++)
	{
		newDimensionValues[i] = dimensionValues_[i] * r;
	}
	return PhysicsVector(newDimensionValues, numberOfDimensions_);
}

PhysicsVector PhysicsVector::operator*(const Matrix& mat) const
{
	const size_t MINIMUM_DIMENSIONS = 3;
	const size_t  MAXIMUM_DIMENSIONS = 4;

	if (numberOfDimensions_ != MINIMUM_DIMENSIONS)
	{
		throw std::range_error("Out of range. Must be a 3D Vector\n");
	}

	if (mat.getColumns() < MINIMUM_DIMENSIONS || mat.getColumns() > MAXIMUM_DIMENSIONS) 
	{
		throw std::range_error("Out of range. Matrix needs atleast 3 columns and no more than 4.\n");
	}

	PhysicsVector ret;
	ret.addDimension(dimensionValues_[0] * mat[0][0] + dimensionValues_[1] * mat[1][0] + dimensionValues_[2] * mat[2][0]);
	ret.addDimension(dimensionValues_[0] * mat[0][1] + dimensionValues_[1] * mat[1][1] + dimensionValues_[2] * mat[2][1]);
	ret.addDimension(dimensionValues_[0] * mat[0][2] + dimensionValues_[1] * mat[1][2] + dimensionValues_[2] * mat[2][2]);

	if (mat.getColumns() == MAXIMUM_DIMENSIONS)
	{
		ret[0] += 1 * mat[3][0];
		ret[1] += 1 * mat[3][1];
		ret[2] += 1 * mat[3][2];
	}

	return ret;
}

//division operator with another vector 2
PhysicsVector PhysicsVector::operator/(const PhysicsVector& r) const
{
	size_t newNumberOfDimensions = std::max(numberOfDimensions_, r.numberOfDimensions_); 
	double* newDimensionValues = new double[newNumberOfDimensions];
	for(size_t i = 0; i < newNumberOfDimensions; i++)
	{
		if(numberOfDimensions_ >= (i + 1))
		{
			newDimensionValues[i] = dimensionValues_[i];
		}
		else
		{
			newDimensionValues[i] = 0;
		}

		if(r.numberOfDimensions_ >= (i + 1))
		{
			newDimensionValues[i] /= r[i];
		}
	}
	return PhysicsVector(newDimensionValues, newNumberOfDimensions);
}

//division operator with a double
PhysicsVector PhysicsVector::operator/(const double& r) const
{
	double* newDimensionValues = new double[numberOfDimensions_];
	for(size_t i = 0; i < numberOfDimensions_; i++)
	{
		newDimensionValues[i] = dimensionValues_[i] / r;
	}
	return PhysicsVector(newDimensionValues, numberOfDimensions_);
}

//shorthand addition operator
PhysicsVector& PhysicsVector::operator+=(const PhysicsVector& r)
{
	size_t newNumberOfDimensions = std::max(numberOfDimensions_, r.numberOfDimensions_); 
	double* newDimensionValues = new double[newNumberOfDimensions];
	for(size_t i = 0; i < newNumberOfDimensions; i++)
	{
		if(numberOfDimensions_ >= (i + 1))
		{
			newDimensionValues[i] = dimensionValues_[i];
		}
		else
		{
			newDimensionValues[i] = 0;
		}

		if(r.numberOfDimensions_ >= (i + 1))
		{
			newDimensionValues[i] += r[i];
		}
	}
	numberOfDimensions_ = newNumberOfDimensions;
	delete dimensionValues_;
	dimensionValues_ = newDimensionValues;
	return *this;
}

//shorthand subtraction operator
PhysicsVector& PhysicsVector::operator-=(const PhysicsVector& r)
{
	size_t newNumberOfDimensions = std::max(numberOfDimensions_, r.numberOfDimensions_); 
	double* newDimensionValues = new double[newNumberOfDimensions];
	for(size_t i = 0; i < newNumberOfDimensions; i++)
	{
		if(numberOfDimensions_ >= (i + 1))
		{
			newDimensionValues[i] = dimensionValues_[i];
		}
		else
		{
			newDimensionValues[i] = 0;
		}

		if(r.numberOfDimensions_ >= (i + 1))
		{
			newDimensionValues[i] -= r[i];
		}
	}
	numberOfDimensions_ = newNumberOfDimensions;
	delete dimensionValues_;
	dimensionValues_ = newDimensionValues;
	return *this;
}

//shorthand multiplication operator with other vector
PhysicsVector& PhysicsVector::operator*=(const PhysicsVector& r)
{
	size_t newNumberOfDimensions = std::max(numberOfDimensions_, r.numberOfDimensions_); 
	double* newDimensionValues = new double[newNumberOfDimensions];
	for(size_t i = 0; i < newNumberOfDimensions; i++)
	{
		if(numberOfDimensions_ >= (i + 1))
		{
			newDimensionValues[i] = dimensionValues_[i];
		}
		else
		{
			newDimensionValues[i] = 0;
		}

		if(r.numberOfDimensions_ >= (i + 1))
		{
			newDimensionValues[i] *= r[i];
		}
	}
	numberOfDimensions_ = newNumberOfDimensions;
	delete dimensionValues_;
	dimensionValues_ = newDimensionValues;
	return *this;
}

PhysicsVector& PhysicsVector::operator*=(const Matrix& mat)
{
	const size_t MINIMUM_DIMENSIONS = 3;
	const size_t MAXIMUM_DIMENSIONS = 4;

	if (numberOfDimensions_ != MINIMUM_DIMENSIONS)
	{
		throw std::range_error("Out of range. Must be a 3D Vector\n");
	}

	if (mat.getColumns() < MINIMUM_DIMENSIONS || mat.getColumns() > MAXIMUM_DIMENSIONS)
	{
		throw std::range_error("Out of range. Matrix needs atleast 3 columns and no more than 4.\n");
	}

	//have to store elsewhere because was updating dimensionValues_[0] and then trying to use old value again
	double returnValue0 = dimensionValues_[0] * mat[0][0] + dimensionValues_[1] * mat[1][0] + dimensionValues_[2] * mat[2][0];
	double returnValue1 = dimensionValues_[0] * mat[0][1] + dimensionValues_[1] * mat[1][1] + dimensionValues_[2] * mat[2][1];
	double returnValue2 = dimensionValues_[0] * mat[0][2] + dimensionValues_[1] * mat[1][2] + dimensionValues_[2] * mat[2][2];

	if (mat.getColumns() == MAXIMUM_DIMENSIONS)
	{
		returnValue0 += 1 * mat[3][0];
		returnValue1 += 1 * mat[3][1];
		returnValue2 += 1 * mat[3][2];
	}

	dimensionValues_[0] = returnValue0;
	dimensionValues_[1] = returnValue1;
	dimensionValues_[2] = returnValue2;

	return *this;
}

//shorthand multiplication operator with a double
PhysicsVector& PhysicsVector::operator*=(const double& r)
{
	for (size_t i = 0; i < numberOfDimensions_; i++)
	{
		dimensionValues_[i] *= r;
	}
	return *this;
}

//shorthand division operator with other vector
PhysicsVector& PhysicsVector::operator/=(const PhysicsVector& r)
{
	size_t newNumberOfDimensions = std::max(numberOfDimensions_, r.numberOfDimensions_); 
	double* newDimensionValues = new double[newNumberOfDimensions];
	for(size_t i = 0; i < newNumberOfDimensions; i++)
	{
		if(numberOfDimensions_ >= (i + 1))
		{
			newDimensionValues[i] = dimensionValues_[i];
		}
		else
		{
			newDimensionValues[i] = 0;
		}

		if(r.numberOfDimensions_ >= (i + 1))
		{
			newDimensionValues[i] /= r[i];
		}
	}
	numberOfDimensions_ = newNumberOfDimensions;
	delete dimensionValues_;
	dimensionValues_ = newDimensionValues;
	return *this;
}

//shorthand  operator with a double
PhysicsVector& PhysicsVector::operator/=(const double& r)
{
	for (size_t i = 0; i < numberOfDimensions_; i++)
	{
		dimensionValues_[i] /= r;
	}
	return *this;
}

//equivalence operator
bool PhysicsVector::operator==(const PhysicsVector& r) const
{
	bool areSame = numberOfDimensions_ == r.numberOfDimensions_;
	if(areSame)
	{
		for(size_t i = 0; i < numberOfDimensions_ && areSame; i++)
		{
			areSame = dimensionValues_[i] == r[i];
		}
	}
	return areSame;
}

//the not equal operator
bool PhysicsVector::operator!=(const PhysicsVector& r) const
{
	return !(*this == r);
}

//returns the dot product of this and another PhysicsVector
double PhysicsVector::dot(const PhysicsVector& r) const
{
	size_t largerDimension = std::max(numberOfDimensions_, r.numberOfDimensions_);
	double dotProduct = 0;
	for(size_t i = 0; i < largerDimension; i++)
	{
		dotProduct += (dimensionValues_[i] * r[i]);
	}
	return dotProduct;
}

//gets the magnitude of this vector
double PhysicsVector::magnitude() const
{
	return sqrt(magnitudeSquared());
}

//gets the magnitude of this vector squared -- less expensive
double PhysicsVector::magnitudeSquared() const
{
	return dot(*this);
}

//gets the distance between this and another PhysicsVector
double PhysicsVector::distance(const PhysicsVector& other) const
{
	return (*this - other).magnitude();
}

// gets the distance squared between this and another PhysicsVector
double PhysicsVector::distanceSquared(const PhysicsVector& other) const
{
	return (*this - other).magnitudeSquared();
}

//rotates this vector by a given amount of degrees
PhysicsVector PhysicsVector::rotate2D(const double& degrees) const
{
	const size_t REQUIRED_DIMENSIONS = 2;
	if(numberOfDimensions_ != REQUIRED_DIMENSIONS)
	{
		throw std::range_error("Out of range. Must be a 2D Vector\n");
	}

	double radians = PhysicsHelper::degreesToRadians(degrees);

	double s = sin(radians);
	double c = cos(radians);
	
	double* newDimensionValues = new double[REQUIRED_DIMENSIONS];
	newDimensionValues[0] = dimensionValues_[0] * c - dimensionValues_[1] * s;
	newDimensionValues[1] = dimensionValues_[0] * s + dimensionValues_[1] * c;

	return PhysicsVector(newDimensionValues, REQUIRED_DIMENSIONS);
}

//rotates this vector by the given degrees on the given axis
PhysicsVector PhysicsVector::rotate3D(const double& degrees, Axis axis) const
{
	const size_t REQUIRED_DIMENSIONS = 3;
	if(numberOfDimensions_ != REQUIRED_DIMENSIONS)
	{
		throw std::range_error("Out of range. Must be a 3D Vector\n");
	}

	PhysicsVector ret;

	if(axis == X)
	{
		PhysicsVector newYZ;
		newYZ.addDimension(dimensionValues_[1]);
		newYZ.addDimension(dimensionValues_[2]);
		newYZ = newYZ.rotate2D(degrees);
		ret.addDimension(dimensionValues_[0]);
		ret.addDimension(newYZ[0]);
		ret.addDimension(newYZ[1]);
	}
	else if(axis == Y)
	{
		PhysicsVector newXZ;
		newXZ.addDimension(dimensionValues_[0]);
		newXZ.addDimension(dimensionValues_[2]);
		/*i think this needs to be negative degrees for this to work right otherwise it hink y rotations happen backwards
		not positive why but it works the same was as this calculator now https://www.vcalc.com/wiki/vCalc/V3+-+Vector+Rotation*/
		newXZ = newXZ.rotate2D(-degrees);
		ret.addDimension(newXZ[0]);
		ret.addDimension(dimensionValues_[1]);
		ret.addDimension(newXZ[1]);
	}
	else if(axis == Z)
	{
		PhysicsVector newXY;
		newXY.addDimension(dimensionValues_[0]);
		newXY.addDimension(dimensionValues_[1]);
		newXY = newXY.rotate2D(degrees);
		ret.addDimension(newXY[0]);
		ret.addDimension(newXY[1]);
		ret.addDimension(dimensionValues_[2]);
	}

	return ret;
}

//cross product for Physics vectors that are 3d
//TLDR; "doesnt" exist for 2d vectors but kind of does see explanation below
/**
You can't do a cross product with vectors in 2D space. The operation is not defined there.

However, often it is interesting to evaluate the cross product of two vectors assuming that 
the 2D vectors are extended to 3D by setting their z-coordinate to zero. This is the same 
as working with 3D vectors on the xy-plane.

If you extend the vectors that way and calculate the cross product of such an extended 
vector pair you'll notice that only the z-component has a meaningful value: x and y will 
always be zero.

That's the reason why the z-component of the result is often simply returned as a scalar. 
This scalar can for example be used to find the winding of three points in 2D space.

From a pure mathematical point of view the cross product in 2D space does not exist, the 
scalar version is the hack and a 2D cross product that returns a 2D vector makes no sense 
at all.
**/
PhysicsVector PhysicsVector::crossProduct(const PhysicsVector& other) const
{
	const size_t REQUIRED_DIMENSIONS = 3;
	if(numberOfDimensions_ != REQUIRED_DIMENSIONS && other.numberOfDimensions_ != REQUIRED_DIMENSIONS)
	{
		throw std::range_error("Out of range. Must be a 3D Vector\n");
	}

	double* newDimensionValues = new double[REQUIRED_DIMENSIONS];
	newDimensionValues[0] = dimensionValues_[1] * other[2] - dimensionValues_[2] * other[1];
	newDimensionValues[1] = dimensionValues_[1] * other[0] - dimensionValues_[0] * other[2];
	newDimensionValues[2] = dimensionValues_[0] * other[1] - dimensionValues_[1] * other[0];
	return PhysicsVector(newDimensionValues,REQUIRED_DIMENSIONS);
}

//normalizes this PhysicsVector
void PhysicsVector::normalize()
{
	double currentMagnitude = magnitude();

	if (currentMagnitude == 0.0)
	{
		throw std::logic_error("Can not normalize because it is impossible to / by zero.\n");
	}

	*this *= (1.0 / currentMagnitude);
}

//returns a PhysicsVector based on our PhysicsVector but with a magnitude on 1
PhysicsVector PhysicsVector::normalized() const
{
	double currentMagnitude = magnitude();

	if (currentMagnitude == 0.0)
	{
		throw std::logic_error("Can not normalize because it is impossible to / by zero.\n");
	}

	return *this * (1.0 / currentMagnitude);
}

//returns the angle of this vector
double PhysicsVector::angle(const PhysicsVector& other) const
{
	double m = sqrt(magnitudeSquared() * other.magnitudeSquared());
	return PhysicsHelper::radiansToDegrees(acos(dot(other) / m));
}

//returns a PhysicsVector with this vectors magnitude in the given direction
PhysicsVector PhysicsVector::project(const PhysicsVector& myMagnitudeInThisDirection) const
{
	return myMagnitudeInThisDirection * dot(myMagnitudeInThisDirection) /
		myMagnitudeInThisDirection.magnitudeSquared();
}

//returns a vector that is perpendicular to the given direction based on this vector
PhysicsVector PhysicsVector::perpendicular(const PhysicsVector& direction) const
{
	return *this - project(direction);
}

//returns a vector that reflects this vector
PhysicsVector PhysicsVector::reflect(const PhysicsVector& normal) const
{
	return  normal * (dot(normal) * 2.0) - *this;
}

//returns the number of dimensions that this vector is
size_t PhysicsVector::getNumberOfDimensions() const
{
	return numberOfDimensions_;
}

//adds a dimension with this value to this vector
void PhysicsVector::addDimension(const double& newDimensionValue)
{
	double* newDimensionValues = new double[numberOfDimensions_ + 1];

	for (size_t i = 0; i < numberOfDimensions_; i++) 
	{
		newDimensionValues[i] = dimensionValues_[i];
	}

	newDimensionValues[numberOfDimensions_] = newDimensionValue;
	numberOfDimensions_++;
	delete[] dimensionValues_;
	dimensionValues_ = newDimensionValues;
}

//deep copy
void PhysicsVector::deepCopy(const PhysicsVector& other)
{
	numberOfDimensions_ = other.numberOfDimensions_;

	dimensionValues_ = new double[numberOfDimensions_];

	for(size_t i = 0; i < numberOfDimensions_; i++)
	{
		dimensionValues_[i] = other[i];
	}
}

//output operator 
PHYSICSENGINE std::ostream& operator<<(std::ostream& os, const PhysicsVector& v)
{
	os << "(";
	for(size_t i = 0; i < v.getNumberOfDimensions(); i++)
	{
		os << v[i];
		if(i + 1 != v.getNumberOfDimensions())
		{
			os << ", ";
		}
	}
	os << ")";
	return os;
}
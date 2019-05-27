//Cody Ware
//9/24/18 

#include <stdexcept>
#include <algorithm>
#include <ostream>
#include <cmath>
#include "../headers/Vector2.h"

//default constructor
Vector2::Vector2()
{
	//allocate new memory and store 0s
	x_ = new double(0);
	y_ = new double(0);
}

//constructor that takes a value
Vector2::Vector2(const double & x, const double & y)
{
	//allocate new memory passing it the values
	x_ = new double(x);
	y_ = new double(y);
}

//copy constructor
Vector2::Vector2(const Vector2 & other)
{
	deepCopy(other);
}

//move constructor
Vector2::Vector2(Vector2 && other)
{
	x_ = new double;
	y_ = new double;

	//point to what is already allocated
	*x_ = *other.x_;
	*y_ = *other.y_;

	//point to default value elsewhere
	other.x_ = new double(0);
	other.y_ = new double(0);
}

//assignment operator
Vector2 & Vector2::operator=(const Vector2 & other)
{
	if (this != &other)
	{
		deepCopy(other);
	}

	return *this;
}

//move assignment operator
Vector2 & Vector2::operator=(Vector2 && other)
{
	if (this != &other)
	{
		//release resources
		delete x_;
		delete y_;

		//take others
		*x_ = *other.x_;
		*y_ = *other.y_;

		//default others pointing to new resource
		other.x_ = new double(0);
		other.y_ = new double(0);
	}

	return *this;
}

//destructor
Vector2::~Vector2()
{
	//delete the stuff that we allocated
	delete x_;
	delete y_;
}

//random access operator
double & Vector2::operator[](const int& i) const
{
	double* returnValue = nullptr;

	switch (i)
	{
	case 0: returnValue = x_;
		break;
	case 1: returnValue = y_;
		break;
	default: throw std::range_error("Out of range of 2d Vector.\n");
		break;
	}

	return *returnValue;
}

//the addition operator
Vector2 Vector2::operator+(const Vector2 & r) const
{
	return Vector2(*this->x_ + *r.x_, *this->y_ + *r.y_);
}

//the subtraction operator
Vector2 Vector2::operator-(const Vector2 & r) const
{
	return Vector2(*this->x_ - *r.x_, *this->y_ - *r.y_);
}

//the multiplication operator for 2 vector2s
Vector2 Vector2::operator*(const Vector2 & r) const
{
	return Vector2(*this->x_ * *r.x_, *this->y_ * *r.y_);
}

//the multiplication operator for multiplying a vector by a double
Vector2 Vector2::operator*(const double& r) const
{
	return Vector2(*this->x_ * r, *this->y_ * r);
}

//division operator with another vector 2
Vector2 Vector2::operator/(const Vector2 & r) const
{
	return Vector2(*this->x_ / *r.x_, *this->y_ / *r.y_);
}

//division operator with a double
Vector2 Vector2::operator/(const double & r) const
{
	return Vector2(*this->x_ / r, *this->y_ / r);
}

//shorthand addition operator
Vector2 & Vector2::operator+=(const Vector2 & r)
{
	*x_ += *r.x_;
	*y_ += *r.y_;
	return *this;
}

//shorthand subtraction operator
Vector2 & Vector2::operator-=(const Vector2 & r)
{
	*x_ -= *r.x_;
	*y_ -= *r.y_;
	return *this;
}

//shorthand multiplication operator with other vector
Vector2 & Vector2::operator*=(const Vector2 & r)
{
	*x_ *= *r.x_;
	*y_ *= *r.y_;
	return *this;
}

//shorthand multiplication operator with a double
Vector2 & Vector2::operator*=(const double & r)
{
	*x_ *= r;
	*y_ *= r;
	return *this;
}

//shorthand division operator with other vector
Vector2 & Vector2::operator/=(const Vector2 & r)
{
	*x_ /= *r.x_;
	*y_ /= *r.y_;
	return *this;
}

//shorthand  operator with a double
Vector2 & Vector2::operator/=(const double & r)
{
	*x_ /= r;
	*y_ /= r;
	return *this;
}

//equivalence operator
bool Vector2::operator==(const Vector2 & r) const
{
	return epsilonCompare(*this->x_, *r.x_)
		&& epsilonCompare(*this->y_, *r.y_);
}

//the not equal operator
bool Vector2::operator!=(const Vector2 & r) const
{
	return !(*this == r);
}

//returns the dot product of this and another vector2
double Vector2::dot(const Vector2 & r) const
{
	return (*this->x_ * *r.x_) + (*this->y_ * *r.y_);
}

//gets the magnitude of this vector
double Vector2::magnitude() const
{
	return sqrt(magnitudeSquared());
}

//gets the magnitude of this vector squared -- less expensive
double Vector2::magnitudeSquared() const
{
	return dot(*this);
}

//gets the distance between this and another vector2
double Vector2::distance(const Vector2 & other) const
{
	return (*this - other).magnitude();
}

// gets the distance squared between this and another vector2
double Vector2::distanceSquared(const Vector2 & other) const
{
	return (*this - other).magnitudeSquared();
}

//rotates this vector by a given amount of degrees
Vector2 Vector2::rotate(const double & degrees) const
{
	double radians = degreesToRadians(degrees);

	double s = sin(radians);
	double c = cos(radians);

	return Vector2(*x_ * c - *y_ * s, *x_ * s + *y_ * c);
}

//normalizes this vector2
void Vector2::normalize()
{
	double currentMagnitude = magnitude();

	if (currentMagnitude == 0.0)
	{
		throw std::logic_error("Can not normalize because it is impossible to / by zero.");
	}

	*this *= (1.0 / currentMagnitude);
}

//returns a vector2 based on our vector2 but with a magnitude on 1
Vector2 Vector2::normalized() const
{
	double currentMagnitude = magnitude();

	if (currentMagnitude == 0.0)
	{
		throw std::logic_error("Can not normalize because it is impossible to / by zero.");
	}

	return *this * (1.0 / currentMagnitude);
}

//returns the angle of this vector
double Vector2::angle(const Vector2 & other) const
{
	double m = sqrt(magnitudeSquared() * other.magnitudeSquared());
	return radiansToDegrees(acos(dot(other) / m));
}

//returns a vector2 with this vectors magnitude in the given direction
Vector2 Vector2::project(const Vector2 & myMagnitudeInThisDirection) const
{
	return myMagnitudeInThisDirection * dot(myMagnitudeInThisDirection) /
		myMagnitudeInThisDirection.magnitudeSquared();
}

//returns a vector that is perpendicular to the given direction based on this vector
Vector2 Vector2::perpendicular(const Vector2 & direction) const
{
	return *this - project(direction);
}

//returns a vector that reflects this vector
Vector2 Vector2::reflect(const Vector2 & normal) const
{
	return  normal * (dot(normal) * 2.0) - *this;
}

//deep copy
void Vector2::deepCopy(const Vector2 & other)
{
	x_ = new double(*other.x_);
	y_ = new double(*other.y_);
}

//output operator 
std::ostream & operator<<(std::ostream & os, const Vector2 & v)
{
	os << "(" << v[0] << ", " << v[1] << ")";
	return os;
}
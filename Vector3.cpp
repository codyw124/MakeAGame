//Cody Ware
//10/2/18

// #include "stdafx.h"
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <ostream>
#include "Vector3.h"

namespace GamePhysics
{
	//constructor that initialized instance with default values
	Vector3::Vector3()
	{
		//allocate new memory and store 0s
		x_ = new double(0);
		y_ = new double(0);
		z_ = new double(0);
	}

	//constructor that takes a value
	Vector3::Vector3(const double & x, const double & y, const double & z)
	{
		//allocate new memory passing it the values
		x_ = new double(x);
		y_ = new double(y);
		z_ = new double(z);
	}

	//copy constructor
	Vector3::Vector3(const Vector3 & other)
	{
		deepCopy(other);
	}

	//move constructor
	Vector3::Vector3(Vector3 && other)
	{
		x_ = new double;
		y_ = new double;
		z_ = new double;

		//point to what is already allocated
		*x_ = *other.x_;
		*y_ = *other.y_;
		*z_ = *other.z_;

		//point to default value elsewhere
		other.x_ = new double(0);
		other.y_ = new double(0);
		other.z_ = new double(0);
	}

	//assignment operator
	Vector3 & Vector3::operator=(const Vector3 & other)
	{
		if (this != &other)
		{
			deepCopy(other);
		}

		return *this;
	}

	//move assignment operator
	Vector3 & Vector3::operator=(Vector3 && other)
	{
		if (this != &other)
		{
			//release resources
			delete x_;
			delete y_;
			delete z_;

			//take others
			*x_ = *other.x_;
			*y_ = *other.y_;
			*z_ = *other.z_;

			//default others pointing to new resource
			other.x_ = new double(0);
			other.y_ = new double(0);
			other.z_ = new double(0);
		}

		return *this;
	}

	//destructor
	Vector3::~Vector3()
	{
		//delete the stuff that we allocated
		delete x_;
		delete y_;
		delete z_;
	}

	//random access operator
	double & Vector3::operator[](const int& i) const 
	{
		double* returnValue = nullptr;

		switch (i)
		{
		case 0: returnValue = x_;
			break;
		case 1: returnValue = y_;
			break;
		case 2: returnValue = z_;
			break;
		default: throw std::range_error("Out of range of 2d Vector");
			break;
		}

		return *returnValue;
	}

	//the addition operator
	Vector3 Vector3::operator+(const Vector3 & r) const
	{
		return Vector3(*this->x_ + *r.x_, *this->y_ + *r.y_, *this->z_ + *r.z_);
	}

	//the subtraction operator
	Vector3 Vector3::operator-(const Vector3 & r) const
	{
		return Vector3(*this->x_ - *r.x_, *this->y_ - *r.y_, *this->z_ - *r.z_);
	}

	//the multiplication operator for 2 Vector3s
	Vector3 Vector3::operator*(const Vector3 & r) const
	{
		return Vector3(*this->x_ * *r.x_, *this->y_ * *r.y_, *this->z_ * *r.z_);
	}

	//the multiplication operator for multiplying a vector by a double
	Vector3 Vector3::operator*(const double& r) const
	{
		return Vector3(*this->x_ * r, *this->y_ * r, *this->z_ * r);
	}

	Vector3 Vector3::operator/(const Vector3 & r) const
	{
		return Vector3(*this->x_ / *r.x_, *this->y_ / *r.y_, *this->z_ / *r.z_);
	}

	Vector3 Vector3::operator/(const double & r) const
	{
		return Vector3(*this->x_ / r, *this->y_ / r, *this->z_ / r);
	}

	Vector3 & Vector3::operator+=(const Vector3 & r)
	{
		*x_ += *r.x_;
		*y_ += *r.y_;
		*z_ += *r.z_;
		return *this;
	}

	Vector3 & Vector3::operator-=(const Vector3 & r)
	{
		*x_ -= *r.x_;
		*y_ -= *r.y_;
		*z_ -= *r.z_;
		return *this;
	}

	Vector3 & Vector3::operator*=(const Vector3 & r)
	{
		*x_ *= *r.x_;
		*y_ *= *r.y_;
		*z_ *= *r.z_;
		return *this;
	}

	Vector3 & Vector3::operator*=(const double & r)
	{
		*x_ *= r;
		*y_ *= r;
		*z_ *= r;
		return *this;
	}

	Vector3 & Vector3::operator/=(const Vector3 & r)
	{
		*x_ /= *r.x_;
		*y_ /= *r.y_;
		*z_ /= *r.z_;
		return *this;
	}

	Vector3 & Vector3::operator/=(const double & r)
	{
		*x_ /= r;
		*y_ /= r;
		*z_ /= r;
		return *this;
	}

	//equivalence operator
	bool Vector3::operator==(const Vector3 & r) const
	{
		return epsilonCompare(*this->x_, *r.x_)
			&& epsilonCompare(*this->y_, *r.y_)
			&& epsilonCompare(*this->z_, *r.z_);
	}

	//the not equal operator
	bool Vector3::operator!=(const Vector3 & r) const
	{
		return !(*this == r);
	}

	//returns the dot product of this and another Vector3
	double Vector3::dot(const Vector3 & r) const
	{
		return (*this->x_ * *r.x_) + (*this->y_ * *r.y_) + (*this->z_ * *r.z_);
	}
	
	//gets the magnitude of this vector
	double Vector3::magnitude() const 
	{
		return sqrt(magnitudeSquared());
	}
	
	//gets the magnitude of this vector squared -- less expensive
	double Vector3::magnitudeSquared() const
	{
		return dot(*this);
	}

	//gets the distance between this vector and another
	double Vector3::distance(const Vector3 & other) const
	{
		return (*this - other).magnitude();
	}

	//gets the distance squared between this vector and another
	double Vector3::distanceSquared(const Vector3 & other) const
	{
		return (*this - other).magnitudeSquared();
	}

	//normalizes this vector(makes it have a magnitude of 1 in the same direction)
	void Vector3::normalize()
	{
		double currentMagnitude = magnitude();

		if (currentMagnitude == 0.0)
		{
			throw std::logic_error("Can not normalize because it is impossible to / by zero.");
		}

		*this *= (1.0 / currentMagnitude);
	}

	//returns a normalized version of this vector
	Vector3 Vector3::normalized() const
	{
		double currentMagnitude = magnitude();

		if (currentMagnitude == 0.0)
		{
			throw std::logic_error("Can not normalize because it is impossible to / by zero.");
		}

		return *this * (1.0 / currentMagnitude);
	}

	//returns the angle between this and another vector
	double Vector3::angle(const Vector3 & other) const
	{
		double m = sqrt(magnitudeSquared() * other.magnitudeSquared());
		return radiansToDegrees(acos(dot(other) / m));
	}

	//returns a vector3 with this vectors magnitude in the given direction
	Vector3 Vector3::project(const Vector3 & myMagnitudeInThisDirection) const
	{
		return myMagnitudeInThisDirection * dot(myMagnitudeInThisDirection) /
			myMagnitudeInThisDirection.magnitudeSquared();
	}

	Vector3 Vector3::perpendicular(const Vector3 & direction) const
	{
		return *this - project(direction);
	}

	Vector3 Vector3::reflect(const Vector3 & normal) const
	{
		return  normal * (dot(normal) * 2.0) - *this;
	}

	Vector3 Vector3::crossProduct(const Vector3 & other)
	{
		double x = *y_ * other[2] - *z_ * other[1];
		double y = *z_ * other[0] - *x_ * other[2];
		double z = *x_ * other[1] - *y_ * other[0];
		return Vector3(x,y,z);
	}

	//deep copy
	void Vector3::deepCopy(const Vector3 & other)
	{
		x_ = new double(*other.x_);
		y_ = new double(*other.y_);
		z_ = new double(*other.z_);
	}

	std::ostream & operator<<(std::ostream & os, const Vector3 & v)
	{
		os << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
		return os;
	}
}
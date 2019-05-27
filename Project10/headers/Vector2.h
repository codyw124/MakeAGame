//Cody Ware
//9/24/18

#pragma once  

#include <iostream>
#include "PhysicsVector.h"
#include "IVector.h"

class  Vector2 : private PhysicsVector, public IVector
{
public:
	//default constructor
	Vector2();

	//constructor with values
	Vector2(const double& x, const double& y);

	//copy constructor
	Vector2(const Vector2& other);

	//move constructor
	Vector2(Vector2&& other);

	//assignment operator
	Vector2& operator=(const Vector2& other);

	//move assignment operator
	Vector2& operator=(Vector2&& other);

	//destructor
	~Vector2();

	//bracket operator to get elements
	double& operator[](const int& i) const;

	//addition operator
	Vector2 operator+(const Vector2& r) const;

	//subtraction operator
	Vector2 operator-(const Vector2& r) const;

	//multiplication with another vector operator
	Vector2 operator*(const Vector2& r) const;

	//multiply by a double operator
	Vector2 operator*(const double& r) const;

	//division operator with another vector 2
	Vector2 operator/(const Vector2& r) const;

	//division operator with a double
	Vector2 operator/(const double& r) const;

	//shorthand addition operator
	Vector2& operator+=(const Vector2& r);

	//shorthand subtraction operator
	Vector2& operator-=(const Vector2& r);

	//shorthand multiplication operator with other vector
	Vector2& operator*=(const Vector2& r);

	//shorthand multiplication operator with a double
	Vector2& operator*=(const double& r);

	//shorthand division operator with other vector
	Vector2& operator/=(const Vector2& r);

	//shorthand  operator with a double
	Vector2& operator/=(const double& r);

	//equivalence operator
	bool operator==(const Vector2& r) const;

	//inequivalence operator
	bool operator!=(const Vector2& r) const;

	//finds the dot product of this and another Vector2
	double dot(const Vector2& r) const;

	//finds the magnitude of this vector2
	double magnitude() const;

	//finds the vector squared of this vector2
	double magnitudeSquared() const;

	//gets the distance between this vector and another
	double distance(const Vector2& other) const;

	//gets the distance squared between this vector and another
	double distanceSquared(const Vector2& other) const;

	//rotates this vector by a given amount of degrees
	Vector2 rotate(const double& degrees) const;

	//normalizes this vector
	void normalize();

	//returns the normalized verison of this vector
	Vector2 normalized() const;

	//returns the angle of this vector
	double angle(const Vector2& other) const;

	//returns a vector2 with this vectors magnitude in the given direction
	Vector2 project(const Vector2& direction) const;

	//returns a vector that is perpendicular to the given direction based on this vector
	Vector2 perpendicular(const Vector2& direction) const;

	//returns a vector that reflects this vector
	Vector2 reflect(const Vector2& normal) const;

private:
	//deep copy for assignment operator and copy constructor
	void deepCopy(const Vector2& other);

	double * x_;
	double * y_;
};

//output operator 
std::ostream& operator<<(std::ostream& os, const Vector2 & v);

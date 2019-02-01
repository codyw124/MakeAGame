//Cody Ware
//10/2/18 

#pragma once  

#include "PhysicsVector.h"

namespace GamePhysics
{
	class Vector3 : public PhysicsVector
	{
	public:
		//default constructor 
		Vector3();

		//constructor with values
		Vector3(const double& x, const double& y, const double& z);

		//copy constructor
		Vector3(const Vector3& other);

		//move constructor
		Vector3(Vector3&& other);

		//assignment operator
		Vector3& operator=(const Vector3& other);

		//move assignment operator
		Vector3& operator=(Vector3&& other);

		//destructor
		~Vector3();

		//bracket operator to get elements
		double& operator[](const int& i) const;

		//addition operator
		Vector3 operator+(const Vector3& r) const;

		//subtraction operator
		Vector3 operator-(const Vector3& r) const;

		//multiplication with another vector operator
		Vector3 operator*(const Vector3& r) const;

		//multiply by a double operator
		Vector3 operator*(const double& r) const;

		//division operator with another vector 2
		Vector3 operator/(const Vector3& r) const;

		//division operator with a double
		Vector3 operator/(const double& r) const;

		//shorthand addition operator
		Vector3& operator+=(const Vector3& r);

		//shorthand subtraction operator
		Vector3& operator-=(const Vector3& r);

		//shorthand multiplication operator with other vector
		Vector3& operator*=(const Vector3& r);

		//shorthand multiplication operator with a double
		Vector3& operator*=(const double& r);

		//shorthand division operator with other vector
		Vector3& operator/=(const Vector3& r);

		//shorthand  operator with a double
		Vector3& operator/=(const double& r);

		//equivalence operator
		bool operator==(const Vector3& r) const;

		//inequivalence operator
		bool operator!=(const Vector3& r) const;

		//finds the dot product of this and another Vector3
		double dot(const Vector3& r) const;

		//finds the magnitude of this Vector3
		double magnitude() const;

		//finds the vector squared of this vector
		double magnitudeSquared() const;

		//gets the distance between this vector and another
		double distance(const Vector3& other) const;

		//gets the distance squared between this vector and another
		double distanceSquared(const Vector3& other) const;

		//normalizes this vector
		void normalize();

		//returns the normalized verison of this vector
		Vector3 normalized() const;

		//returns the angle of this vector
		double angle(const Vector3& other) const;

		//returns a Vector3 with this vectors magnitude in the given direction
		Vector3 project(const Vector3& myMagnitudeInThisDirection) const;

		//returns a vector that is perpendicular to the given direction based on this vector
		Vector3 perpendicular(const Vector3& direction) const;

		//returns a vector that reflects this vector
		Vector3 reflect(const Vector3& normal) const;

		//returns the cross product of the two vector3
		Vector3 crossProduct(const Vector3& other);

	private:
		//deep copy for assignment operator and copy constructor
		void deepCopy(const Vector3 & other);

		double * x_;
		double * y_;
		double * z_;
	};

	//output operator 
	std::ostream& operator<<(std::ostream& os, const Vector3 & v);
}
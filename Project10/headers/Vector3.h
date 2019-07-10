//Cody Ware
//10/2/18 

#pragma once 
 
#include <iostream>
#include "PhysicsHelper.h"

class  Vector3
{
public:
	Vector3();
	Vector3(const double& x, const double& y, const double& z);
	Vector3(const Vector3& other);
	Vector3(Vector3&& other);
	Vector3& operator=(const Vector3& other);
	Vector3& operator=(Vector3&& other);
	~Vector3();

	double& operator[](const int& i) const;
	Vector3 operator+(const Vector3& r) const;
	Vector3 operator-(const Vector3& r) const;
	Vector3 operator*(const Vector3& r) const;
	Vector3 operator*(const double& r) const;
	Vector3 operator/(const Vector3& r) const;
	Vector3 operator/(const double& r) const;
	Vector3& operator+=(const Vector3& r);
	Vector3& operator-=(const Vector3& r);
	Vector3& operator*=(const Vector3& r);
	Vector3& operator*=(const double& r);
	Vector3& operator/=(const Vector3& r);
	Vector3& operator/=(const double& r);
	bool operator==(const Vector3& r) const;
	bool operator!=(const Vector3& r) const;

	double dot(const Vector3& r) const;
	double magnitude() const;
	double magnitudeSquared() const;
	double distance(const Vector3& other) const;
	double distanceSquared(const Vector3& other) const;

	Vector3 crossProduct(const Vector3& other);

	void normalize();
	Vector3 normalized() const;
	double angle(const Vector3& other) const;
	Vector3 project(const Vector3& myMagnitudeInThisDirection) const;
	Vector3 perpendicular(const Vector3& direction) const;
	Vector3 reflect(const Vector3& normal) const;

private:
	void deepCopy(const Vector3& other);

	double * x_;
	double * y_;
	double * z_;
};

std::ostream& operator<<(std::ostream& os, const Vector3 & v);
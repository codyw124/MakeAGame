//Cody Ware
//9/24/18

#pragma once  

#include <iostream>
#include "PhysicsVector.h"

class  Vector2 : private PhysicsVector
{
public:
	Vector2();
	Vector2(const double& x, const double& y);
	Vector2(const Vector2& other);
	Vector2(Vector2&& other);
	Vector2& operator=(const Vector2& other);
	Vector2& operator=(Vector2&& other);
	~Vector2();

	double& operator[](const int& i) const;
	Vector2 operator+(const Vector2& r) const;
	Vector2 operator-(const Vector2& r) const;
	Vector2 operator*(const Vector2& r) const;
	Vector2 operator*(const double& r) const;
	Vector2 operator/(const Vector2& r) const;
	Vector2 operator/(const double& r) const;
	Vector2& operator+=(const Vector2& r);
	Vector2& operator-=(const Vector2& r);
	Vector2& operator*=(const Vector2& r);
	Vector2& operator*=(const double& r);
	Vector2& operator/=(const Vector2& r);
	Vector2& operator/=(const double& r);
	bool operator==(const Vector2& r) const;
	bool operator!=(const Vector2& r) const;

	double dot(const Vector2& r) const;
	double magnitude() const;
	double magnitudeSquared() const;
	double distance(const Vector2& other) const;
	double distanceSquared(const Vector2& other) const;

	Vector2 rotate(const double& degrees) const;
	
	void normalize();
	Vector2 normalized() const;
	double angle(const Vector2& other) const;
	Vector2 project(const Vector2& direction) const;
	Vector2 perpendicular(const Vector2& direction) const;
	Vector2 reflect(const Vector2& normal) const;

private:
	void deepCopy(const Vector2& other);

	double * x_;
	double * y_;
};

std::ostream& operator<<(std::ostream& os, const Vector2 & v);

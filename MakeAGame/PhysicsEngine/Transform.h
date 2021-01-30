//Cody Ware
//5/19/19

#pragma once

#ifndef PHYSICSENGINE_EXPORTS
#define PHYSICSENGINE __declspec(dllexport)
#else
#define PHYSICSENGINE __declspec(dllimport)
#endif

#include "Matrix.h"
#include "PhysicsVector.h"
#include "PhysicsHelper.h"

class PHYSICSENGINE Transform
{
public:
    Transform();
    Transform(const Transform& other);
	Transform(Transform&& other) noexcept;
    ~Transform();

    Transform& operator=(const Transform& other);
    Transform& operator=(Transform&& other) noexcept;

    void toOtherMajor();
    bool isRowMajor() const;
	PhysicsVector getTranslate() const;
	void setTranslate(const PhysicsVector& newTransform);
	void setTranslate(const double& x, const double& y, const double& z);
	PhysicsVector getScale() const;
	void setScale(const PhysicsVector& newScale);
	void setScale(const double& x, const double& y, const double& z);
	PhysicsVector getXAxis() const;
	void setXAxis(const PhysicsVector& newXAxis);
	void setXAxis(const double& x, const double& y, const double& z);
	PhysicsVector getYAxis() const;
	void setYAxis(const PhysicsVector& newYAxis);
	void setYAxis(const double& x, const double& y, const double& z);
	PhysicsVector getZAxis() const;
	void setZAxis(const PhysicsVector& newZAxis);
	void setZAxis(const double& x, const double& y, const double& z);

	//these can cause a Gibmal lock
	Matrix getRotationMatrix(const double& pitch, const double& yaw, const double& roll);
	Matrix rotateZ(const double& angle);
	Matrix rotateY(const double& angle);
	Matrix rotateX(const double& angle);

	Matrix axisAngle(const PhysicsVector& axis, double angle);

	Matrix getData() const;
    
private:
    Matrix data_;  
    bool isRowMajor_;

    void deepCopy(const Transform& other);
};

PHYSICSENGINE std::ostream& operator<<(std::ostream& os, const Transform& v);
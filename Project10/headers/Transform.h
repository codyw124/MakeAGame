//Cody Ware
//5/19/19

#pragma once

#include "Matrix.h"
#include "Vector3.h"
#include "PhysicsHelper.h"

class Transform
{
public:
    Transform();
    Transform(const Transform& other);
    Transform(Transform&& other);
    ~Transform();

    Transform& operator=(const Transform& other);
    Transform& operator=(Transform&& other);

    void toOtherMajor();
    bool isRowMajor() const;
	Vector3 getTranslate() const;
	void setTranslate(const Vector3& newTransform);
	void setTranslate(const double& x, const double& y, const double& z);
	Vector3 getScale() const;
	void setScale(const Vector3& newScale);
	void setScale(const double& x, const double& y, const double& z);
	Vector3 getXAxis() const;
	void setXAxis(const Vector3& newXAxis);
	void setXAxis(const double& x, const double& y, const double& z);
	Vector3 getYAxis() const;
	void setYAxis(const Vector3& newYAxis);
	void setYAxis(const double& x, const double& y, const double& z);
	Vector3 getZAxis() const;
	void setZAxis(const Vector3& newZAxis);
	void setZAxis(const double& x, const double& y, const double& z);

	Matrix getRotationMatrix(const double& pitch, const double& yaw, const double& roll);
	Matrix rotateZ(const double& angle);
	Matrix rotateY(const double& angle);
	Matrix rotateX(const double& angle);

	Matrix getData() const;
    
private:
    Matrix data_;  
    bool isRowMajor_;

    void deepCopy(const Transform& other);
};

std::ostream& operator<<(std::ostream& os, const Transform& v);
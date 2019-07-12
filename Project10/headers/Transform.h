//Cody Ware
//5/19/19

#pragma once

#include "Matrix.h"
#include "Vector3.h"

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
    bool isRowMajor();
	Vector3 getTransform();
	void setTransform(const Vector3& newTransform);
	void setTransform(const double& x, const double& y, const double& z);
	Vector3 getScale();
	void setScale(const Vector3& newScale);
	void setScale(const double& x, const double& y, const double& z);
	Vector3 getXAxis();
	void setXAxis(const Vector3& newXAxis);
	void setXAxis(const double& x, const double& y, const double& z);
	Vector3 getYAxis();
	void setYAxis(const Vector3& newXAxis);
	void setYAxis(const double& x, const double& y, const double& z);
	Vector3 getZAxis();
	void setZAxis(const Vector3& newXAxis);
	void setZAxis(const double& x, const double& y, const double& z);
    
private:
    Matrix<double> data_;   
    bool isRowMajor_;

    void deepCopy(const Transform& other);
};
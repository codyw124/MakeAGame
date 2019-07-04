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
    
private:
    Matrix<double> data_;   
    bool isRowMajor_;

    void deepCopy(const Transform& other);
};
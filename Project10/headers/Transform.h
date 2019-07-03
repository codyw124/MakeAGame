//Cody Ware
//5/19/19

#pragma once

#include "../headers/Matrix.h"

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
    
private:
    Matrix<double> data_;   
    bool isRowMajor_;

    void deepCopy(const Transform& other);
};
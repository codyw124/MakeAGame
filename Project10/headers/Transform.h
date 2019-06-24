//Cody Ware
//5/19/19

#pragma once

#include "../headers/Matrix.h"

class Transform
{
public:
    Transform();
    Transform(const Transform& other);
    Transform(const Transform&& other);
    ~Transform();

    Transform& operator=(const Transform& other);
    Transform operator=(const Transform&& other);
    
private:
    Matrix<double> data_;    
    const int TRANSFORM_DIMENSIONS = 4;

    void deepCopy();
};
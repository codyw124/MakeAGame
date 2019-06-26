//Cody Ware
//5/19/19

#include "../headers/Transform.h"

Transform::Transform() : data_(TRANSFORM_DIMENSIONS, TRANSFORM_DIMENSIONS)
{
}

Transform::Transform(const Transform& other): data_(other.data_)
{
    
}

Transform::Transform(Transform&& other) : data_(std::move(other.data_))
{
    
}

Transform::~Transform()
{
    
}

Transform& Transform::operator=(const Transform& other)
{
    deepCopy(other);
    return *this;
}

Transform Transform::operator=(Transform&& other)
{
    deepCopy(other);

	other.data_ = Matrix<double>(0,0);

	return *this;
}

void Transform::deepCopy(const Transform& other)
{
    data_ = other.data_;
}
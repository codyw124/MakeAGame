//Cody Ware
//5/19/19

#include "../headers/Transform.h"

Transform::Transform()
{
    isRowMajor_ = true;
}

Transform::Transform(const Transform& other)
{
    deepCopy(other);
}

Transform::Transform(Transform&& other)
{
    data_ = std::move(other.data_);

    isRowMajor_ = other.isRowMajor_;
    other.isRowMajor_ = true;
}

Transform::~Transform()
{
    
}

Transform& Transform::operator=(const Transform& other)
{
    deepCopy(other);
    return *this;
}

Transform& Transform::operator=(Transform&& other)
{
    data_ = std::move(other.data_);

    isRowMajor_ = other.isRowMajor_;
    other.isRowMajor_ = true;
	return *this;
}

void Transform::deepCopy(const Transform& other)
{
    data_ = other.data_;
    isRowMajor_ = other.isRowMajor_;
}

void Transform::toOtherMajor()
{
    data_.transpose();
    isRowMajor_ = !isRowMajor_;
}
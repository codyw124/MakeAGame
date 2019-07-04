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

bool Transform::isRowMajor()
{
    return isRowMajor_;
}

Vector3 Transform::getTransform()
{
    Vector3 ret;

    if(isRowMajor_)
    {
        ret = Vector3(data_[3][0], data_[3][1], data_[3][2]);
    }
    else
    {
        ret = Vector3(data_[0][3], data_[1][3], data_[2][3]);
    }

    return ret;
}

void Transform::setTransform(const Vector3& newTransform)
{
    if(isRowMajor_)
    {
        data_[3][0] = newTransform[0];
        data_[3][1] = newTransform[1];
        data_[3][2] = newTransform[2];
    }
    else
    {
        data_[0][3] = newTransform[0];
        data_[1][3] = newTransform[1];
        data_[2][3] = newTransform[2];
    }
}
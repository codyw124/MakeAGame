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
	setTransform(newTransform[0], newTransform[1], newTransform[2]);
}

void Transform::setTransform(const double& x, const double& y, const double& z)
{
	if (isRowMajor_)
	{
		data_[3][0] = x;
		data_[3][1] = y;
		data_[3][2] = z;
	}
	else
	{
		data_[0][3] = x;
		data_[1][3] = y;
		data_[2][3] = z;
	}
}

Vector3 Transform::getScale()
{
	return Vector3(data_[0][0], data_[1][1], data_[2][2]);
}

void Transform::setScale(const Vector3& newScale)
{
	setScale(newScale[0], newScale[1], newScale[2]);
}
void Transform::setScale(const double& x, const double& y, const double& z)
{
	data_[0][0] = x;
	data_[1][1] = y;
	data_[2][2] = z;
}

Vector3 Transform::getXAxis()
{

}

void Transform::setXAxis(const Vector3& newXAxis)
{

}

void Transform::setXAxis(const double& x, const double& y, const double& z)
{

}

Vector3 Transform::getYAxis()
{

}

void Transform::setYAxis(const Vector3& newXAxis)
{

}

void Transform::setYAxis(const double& x, const double& y, const double& z)
{

}

Vector3 Transform::getZAxis()
{

}

void Transform::setZAxis(const Vector3& newXAxis)
{

}

void Transform::setZAxis(const double& x, const double& y, const double& z)
{

}
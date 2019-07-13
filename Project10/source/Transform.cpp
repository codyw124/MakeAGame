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

bool Transform::isRowMajor() const
{
    return isRowMajor_;
}

Vector3 Transform::getTranslate() const
{
    Vector3 ret;

    if(isRowMajor_)
    {
		ret[0] = data_[3][0];
		ret[1] = data_[3][1];
		ret[2] = data_[3][2];
    }
    else
    {
		ret[0] = data_[0][3];
		ret[1] = data_[1][3];
		ret[2] = data_[2][3];
    }

    return ret;
}

void Transform::setTranslate(const Vector3& newTransform)
{
	setTranslate(newTransform[0], newTransform[1], newTransform[2]);
}

void Transform::setTranslate(const double& x, const double& y, const double& z)
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

Vector3 Transform::getScale() const
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

Vector3 Transform::getXAxis() const
{
	Vector3 ret;

	if (isRowMajor_)
	{
		ret[0] = data_[0][0];
		ret[1] = data_[0][1];
		ret[2] = data_[0][2];
	}
	else
	{
		ret[0] = data_[0][0];
		ret[1] = data_[1][0];
		ret[2] = data_[2][0];
	}

	return ret;
}

void Transform::setXAxis(const Vector3& newXAxis)
{
	setXAxis(newXAxis[0], newXAxis[1], newXAxis[2]);
}

void Transform::setXAxis(const double& x, const double& y, const double& z)
{
	if (isRowMajor_)
	{
		data_[0][0] = x;
		data_[0][1] = y;
		data_[0][2] = z;
	}
	else
	{
		data_[0][0] = x;
		data_[1][0] = y;
		data_[2][0] = z;
	}
}

Vector3 Transform::getYAxis() const
{
	Vector3 ret;

	if (isRowMajor_)
	{
		ret[0] = data_[1][0];
		ret[1] = data_[1][1];
		ret[2] = data_[1][2];
	}
	else
	{
		ret[0] = data_[0][1];
		ret[1] = data_[1][1];
		ret[2] = data_[2][1];
	}
	return ret;
}

void Transform::setYAxis(const Vector3& newYAxis)
{
	setYAxis(newYAxis[0], newYAxis[1], newYAxis[2]);
}

void Transform::setYAxis(const double& x, const double& y, const double& z)
{
	if (isRowMajor_)
	{
		data_[1][0] = x;
		data_[1][1] = y;
		data_[1][2] = z;
	}
	else
	{
		data_[0][1] = x;
		data_[1][1] = y;
		data_[2][1] = z;
	}
}

Vector3 Transform::getZAxis() const
{
	Vector3 ret;

	if (isRowMajor_)
	{
		ret[0] = data_[2][0];
		ret[1] = data_[2][1];
		ret[2] = data_[2][2];
	}
	else
	{
		ret[0] = data_[0][2];
		ret[1] = data_[1][2];
		ret[2] = data_[2][2];
	}

	return ret;
}

void Transform::setZAxis(const Vector3& newZAxis)
{
	setZAxis(newZAxis[0], newZAxis[1], newZAxis[2]);
}

void Transform::setZAxis(const double& x, const double& y, const double& z)
{
	if (isRowMajor_)
	{
		data_[2][0] = x;
		data_[2][1] = y;
		data_[2][2] = z;
	}
	else
	{
		data_[0][2] = x;
		data_[1][2] = y;
		data_[2][2] = z;
	}
}

Matrix<double> Transform::getData() const
{
	return data_;
}

std::ostream& operator<<(std::ostream& os, const Transform& v)
{
	os << v.getData() << endl;

	return os;
}

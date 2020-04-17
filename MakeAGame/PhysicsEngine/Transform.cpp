//Cody Ware
//5/19/19

#include "Transform.h"

Transform::Transform()
{
    isRowMajor_ = true;
}

Transform::Transform(const Transform& other)
{
    deepCopy(other);
}

Transform::Transform(Transform&& other) noexcept
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

Transform& Transform::operator=(Transform&& other) noexcept
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

PhysicsVector Transform::getTranslate() const
{
    PhysicsVector ret;

    if(isRowMajor_)
    {
		ret.addDimension(data_[3][0]);
		ret.addDimension(data_[3][1]);
		ret.addDimension(data_[3][2]);
    }
    else
    {
		ret.addDimension(data_[0][3]);
		ret.addDimension(data_[1][3]);
		ret.addDimension(data_[2][3]);
    }

    return ret;
}

void Transform::setTranslate(const PhysicsVector& newTransform)
{
	if (newTransform.getNumberOfDimensions() != 3) 
	{
		throw std::range_error("setTranslate(const PhysicsVector& newTransform) requires 3D Physics Vector");
	}

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

PhysicsVector Transform::getScale() const
{
	PhysicsVector ret;
	ret.addDimension(data_[0][0]);
	ret.addDimension(data_[1][1]);
	ret.addDimension(data_[2][2]);
	return ret;
}

void Transform::setScale(const PhysicsVector& newScale)
{
	if (newScale.getNumberOfDimensions() != 3)
	{
		throw std::range_error("setTranslate(const PhysicsVector& newTransform) requires 3D Physics Vector");
	}

	setScale(newScale[0], newScale[1], newScale[2]);
}
void Transform::setScale(const double& x, const double& y, const double& z)
{
	data_[0][0] = x;
	data_[1][1] = y;
	data_[2][2] = z;
}

PhysicsVector Transform::getXAxis() const
{
	PhysicsVector ret;

	if (isRowMajor_)
	{
		ret.addDimension(data_[0][0]);
		ret.addDimension(data_[0][1]);
		ret.addDimension(data_[0][2]);
	}
	else
	{
		ret.addDimension(data_[0][0]);
		ret.addDimension(data_[1][0]);
		ret.addDimension(data_[2][0]);
	}

	return ret;
}

void Transform::setXAxis(const PhysicsVector& newXAxis)
{
	if (newXAxis.getNumberOfDimensions() != 3)
	{
		throw std::range_error("setTranslate(const PhysicsVector& newTransform) requires 3D Physics Vector");
	}

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

PhysicsVector Transform::getYAxis() const
{
	PhysicsVector ret;

	if (isRowMajor_)
	{
		ret.addDimension(data_[1][0]);
		ret.addDimension(data_[1][1]);
		ret.addDimension(data_[1][2]);
	}
	else
	{
		ret.addDimension(data_[0][1]);
		ret.addDimension(data_[1][1]);
		ret.addDimension(data_[2][1]);
	}
	return ret;
}

void Transform::setYAxis(const PhysicsVector& newYAxis)
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

PhysicsVector Transform::getZAxis() const
{
	PhysicsVector ret;

	if (isRowMajor_)
	{
		ret.addDimension(data_[2][0]);
		ret.addDimension(data_[2][1]);
		ret.addDimension(data_[2][2]);
	}
	else
	{
		ret.addDimension(data_[0][2]);
		ret.addDimension(data_[1][2]);
		ret.addDimension(data_[2][2]);
	}

	return ret;
}

void Transform::setZAxis(const PhysicsVector& newZAxis)
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

Matrix Transform::getRotationMatrix(const double& pitch, const double& yaw, const double& roll)
{
	return (rotateZ(roll) * rotateX(pitch)) *rotateY(yaw);
}

Matrix Transform::rotateZ(const double& angle)
{
	Matrix ret;

	double angleConvertedToRadian = PhysicsHelper::degreesToRadians(angle);

	ret[0][0] = cos(angle);
	ret[0][1] = sin(angle);
	ret[1][0] = -sin(angle);
	ret[1][1] = cos(angle);

	return ret;
}

Matrix Transform::rotateX(const double& angle)
{
	Matrix ret;

	double angleConvertedToRadian = PhysicsHelper::degreesToRadians(angle);

	ret[1][1] = cos(angle);
	ret[1][2] = sin(angle);
	ret[2][1] = -sin(angle);
	ret[2][2] = cos(angle);


	return ret;
}

Matrix Transform::rotateY(const double& angle)
{
	Matrix ret;

	double angleConvertedToRadian = PhysicsHelper::degreesToRadians(angle);

	ret[0][0] = cos(angle);
	ret[0][2] = -sin(angle);
	ret[2][0] = sin(angle);
	ret[2][2] = cos(angle);

	return ret;
}

Matrix Transform::getData() const
{
	return data_;
}

std::ostream& operator<<(std::ostream& os, const Transform& v)
{
	os << v.getData() << std::endl;

	return os;
}

Matrix Transform::axisAngle(const PhysicsVector& axis, double angle) {
	angle = PhysicsHelper::degreesToRadians(angle);
	double c = cos(angle);
	double s = sin(angle);
	double t = 1.0 - cos(angle);

	double x = axis[0];
	double y = axis[1];
	double z = axis[2];
	if (!PhysicsHelper::epsilonCompare(axis.magnitude(), 1.0f)) {
		double inv_len = 1.0f / axis.magnitude();
		x *= inv_len;
		y *= inv_len;
		z *= inv_len;
	}

	Matrix ret(4,4);
	ret[0][0] = t * (x * x) + c; 
	ret[0][1] = t * x * y + s * z;
	ret[0][2] = t * x * z - s * y;
	ret[0][3] = 0.0f;
	ret[1][0] = t * x * y - s * z;
	ret[1][1] = t * (y * y) + c;
	ret[1][2] = t * y * z + s * x;
	ret[1][3] = 0.0f;
	ret[2][0] = t * x * z + s * y;
	ret[2][1] = t * y * z - s * x;
	ret[2][2] = t * (z * z) + c;
	ret[2][3] = 0.0f;
	ret[3][0] = 0.0f;
	ret[3][1] = 0.0f;
	ret[3][2] = 0.0f;
	ret[3][3] = 1.0f;

	return ret;
}


//mat4 Orthogonalize(const mat4& mat) {
//	vec3 xAxis(mat._11, mat._12, mat._13);
//	vec3 yAxis(mat._21, mat._22, mat._23);
//	vec3 zAxis = Cross(xAxis, yAxis);
//
//	xAxis = Cross(yAxis, zAxis);
//	yAxis = Cross(zAxis, xAxis);
//	zAxis = Cross(xAxis, yAxis);
//
//	return mat4(
//		xAxis.x, xAxis.y, xAxis.z, mat._14,
//		yAxis.x, yAxis.y, yAxis.z, mat._24,
//		zAxis.x, zAxis.y, zAxis.z, mat._34,
//		mat._41, mat._42, mat._43, mat._44
//	);
//}
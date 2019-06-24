//Cody Ware
//5/19/19

#include "../headers/Transform.h"

Transform::Transform() : data_(TRANSFORM_DIMENSIONS, TRANSFORM_DIMENSIONS)
{
}

Transform::Transform(const Transform& other): data_(other.data_)
{
    
}

Transform::Transform(const Transform&& other) : data_(std::move(other.data_))
{
    
}

Transform::~Transform()
{
    
}

Transform& Transform::operator=(const Transform& other)
{
    
}

Transform Transform::operator=(const Transform&& other)
{
    
}

void Transform::deepCopy()
{

}
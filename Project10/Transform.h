#pragma once
#include "Property.h"
#include "Vector3.h"

class Transform : public Component
{
private:
    Vector3 location_;
    Vector3 rotation_;
    
public:
    Transform();
    ~Transform();
};
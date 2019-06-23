//Cody Ware
//5/19/19

#pragma once

#include <string>
#include "Component.h"
#include "Vector3.h"

class Transform : public Component
{
private:
    Vector3 location_;
    Vector3 rotation_;
    
public:
    Transform();
    ~Transform();

    std::string toXML();
};
#pragma once
#include <vector>
#include "Component.h"

class GameObject
{
private:
    std::vector<Component> components;
public:
    GameObject();
    ~GameObject();
};
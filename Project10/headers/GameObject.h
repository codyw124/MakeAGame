#pragma once
#include <vector>
#include <string>
#include "Component.h"

class GameObject
{
private:
    std::vector<Component*> components_;
public:
    GameObject();
    ~GameObject();
    bool operator==(const GameObject& r) const;

    std::string toXML();
};
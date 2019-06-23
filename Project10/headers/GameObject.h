//Cody Ware
//5/19/19

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

    void save(std::string filename) const;
    void load(std::string filename);
};
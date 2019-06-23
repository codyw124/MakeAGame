//Cody Ware
//5/19/19

#pragma once

#include <queue>
#include <utility>
#include <string>
#include "Component.h"

class Animation : public Component
{
private:
    //std::queue<std::pair<sprite,size_t>> animation_;
    
public:
    Animation();
    ~Animation();

    std::string toXML();
};
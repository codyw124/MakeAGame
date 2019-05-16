#pragma once

class Component
{
private:
    
public:
    virtual ~Component() = 0;
    virtual std::string toXML() = 0;
};
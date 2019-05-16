#include "../headers/Transform.h"

Transform::Transform()
{
}

Transform::~Transform()
{
}

std::string Transform::toXML()
{
    std::string returnValue = "<transform>\n";
    returnValue += "<location>\n";
    returnValue += location_[0];
    returnValue += location_[1];
    returnValue += location_[2];
    returnValue += "</location>\n";
    returnValue += "<rotation>\n";
    returnValue += rotation_[0];
    returnValue += rotation_[1];
    returnValue += rotation_[2];
    returnValue += "</rotation>\n";
    returnValue += "</transform>\n";

    return returnValue;
}
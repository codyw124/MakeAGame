//Cody Ware
//5/19/19

#pragma once

#include <list>
#include <string>
#include "Matrix.h"
#include "SpriteSheet.h"

class GameObject
{
private:
    Matrix transform_;
    SpriteSheet* SpriteSheet_;
public:
    GameObject();
    ~GameObject();
    bool operator==(const GameObject& other) const;
    void setSpriteSheet(SpriteSheet* SpriteSheet);
    SpriteSheet* getSpriteSheet();
};
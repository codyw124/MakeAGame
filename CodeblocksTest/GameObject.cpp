//Cody Ware
//5/19/19

#include "GameObject.h"

GameObject::GameObject()
{
    transform_ = Matrix(3,3);
    transform_[0][0] = 0;
    transform_[1][1] = 0;
    transform_[2][2] = 0;
    SpriteSheet_ = NULL;
}

GameObject::~GameObject()
{
}

bool GameObject::operator==(const GameObject& other) const
{
    return transform_ == other.transform_ && SpriteSheet_ == other.SpriteSheet_;
}


void GameObject::setSpriteSheet(SpriteSheet* SpriteSheet)
{
    SpriteSheet_ = SpriteSheet;
}

SpriteSheet* GameObject::getSpriteSheet()
{
    return SpriteSheet_;
}
//Cody Ware
//5/19/19

#include "../headers/GameObject.h"

GameObject::GameObject()
{
    components_ = std::vector<Component*>();
}

GameObject::~GameObject()
{
}

std::string GameObject::toXML()
{
    std::string returnValue = "<gameobject>\n";

    for(Component* x : components_)
    {
        returnValue += x->toXML();
    }

    returnValue += "</gameobject>\n";

    return returnValue;
}

void GameObject::save(std::string filename) const
{

}

void GameObject::load(std::string filename)
{

}

bool GameObject::operator==(const GameObject & r) const
{
    bool areSame = true;

    if(components_.size() == r.components_.size())
    {
        for(size_t i = 0; i < components_.size(); i++)
        {
            if(components_[i] != r.components_[i])
            {
                areSame = false;
            }
        }
    }
    else
    {
        areSame = false;
    }

    return areSame;
}
#pragma once
#include <list>
#include <fstream>
#include "GameObject.h"

class Scene
{
private:
    std::list<GameObject> gameObjects_;
    
public:
    Scene();
    ~Scene();
    void addGameObject(GameObject toBeAdded);
    void removeGameObject(GameObject toBeRemoved);
    
    std::string toXML();
};
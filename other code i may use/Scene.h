//Cody Ware
//5/19/19

#pragma once

#include <list>
#include <fstream>
#include <string>
#include "GameObject.h"
#include "tinyxml2.h"

using namespace tinyxml2;

class Scene
{
private:
    std::list<GameObject> gameObjects_;
    bool fileExistsInCurrentDirectory(std::string filename);

public:
    Scene(std::string filename);
    ~Scene();
    void addGameObject(GameObject toBeAdded);
    void removeGameObject(GameObject toBeRemoved);
    
    std::string save();
};
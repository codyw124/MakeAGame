#pragma once
#include <list>
#include <fstream>
#include <string>
#include "GameObject.h"

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
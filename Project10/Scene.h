#pragma once
#include <vector>
#include <fstream>
// #include "GameObject.h"

class Scene
{
private:
    //std::vector<GameObject> gameObjects_;
    
public:
    Scene();
    ~Scene();

    void saveToFile(std::string fileName);
};
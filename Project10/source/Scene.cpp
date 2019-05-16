#include "../headers/Scene.h"

Scene::Scene(std::string filename)
{
    gameObjects_ = std::list<GameObject>();

    if(fileExistsInCurrentDirectory(filename))
    {
    }
}

Scene::~Scene()
{
}

std::string Scene::save()
{
    std::string returnValue = "<scene>\n";

    for(GameObject x : gameObjects_)
    {
        returnValue += x.toXML() + "\n";
    }

    returnValue += "</scene>";

    return returnValue;
}

void Scene::addGameObject(GameObject toBeAdded)
{
    gameObjects_.push_back(toBeAdded);
}

void Scene::removeGameObject(GameObject toBeRemoved)
{
    gameObjects_.remove(toBeRemoved);
}

bool Scene::fileExistsInCurrentDirectory(std::string filename)
{
    std::ifstream ifs (filename, std::ifstream::in);

    bool isGood = ifs.good();

    ifs.close();
    
    return isGood;
}
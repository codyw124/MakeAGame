#include "../headers/Scene.h"

Scene::Scene()
{
    gameObjects_ = std::list<GameObject>();
}

Scene::~Scene()
{
}

std::string Scene::toXML()
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
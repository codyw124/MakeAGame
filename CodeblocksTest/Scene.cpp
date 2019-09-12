//Cody Ware
//5/19/19

#include "Scene.h"

Scene::Scene()
{
    gameObjects_ = std::list<GameObject*>();
    renderer_ = NULL;
}

Scene::~Scene()
{
}

void Scene::addGameObject(GameObject* toBeAdded)
{
    gameObjects_.push_back(toBeAdded);
}

void Scene::removeGameObject(GameObject* toBeRemoved)
{
    gameObjects_.remove(toBeRemoved);
}

void Scene::setRenderer(SDL_Renderer* renderer)
{
    renderer_ = renderer;
}

std::list<GameObject*>& Scene::getGameObjects()
{
    return gameObjects_;
}

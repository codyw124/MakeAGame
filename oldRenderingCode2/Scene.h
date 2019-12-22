//Cody Ware
//5/19/19

#pragma once

#include <list>
#include <string>
#include <SDL2/SDL.h>
#include "GameObject.h"

class Scene
{
private:
    std::list<GameObject*> gameObjects_;

protected:
    SDL_Renderer* renderer_;

public:
    Scene();
    ~Scene();
    void addGameObject(GameObject* toBeAdded);
    void removeGameObject(GameObject* toBeRemoved);
    void setRenderer(SDL_Renderer* renderer);
    std::list<GameObject*>& getGameObjects();
};

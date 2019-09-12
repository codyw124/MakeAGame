//Cody Ware
//8/29/19

#pragma once

#include "Scene.h"
#include "SpriteSheet.h"


class HardCodedScene : public Scene
{
private:
    GameObject* firstObject;
    SpriteSheet* spriteSheet;
public:
    HardCodedScene(SDL_Renderer* renderer);
    ~HardCodedScene();
};

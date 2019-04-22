#pragma once
#include "Texture.h"

class Character : private Texture
{
private:
    int standingDownAnimation[];

    SDL_Rect gSpriteClips[];

    enum Direction{UP,DOWN,LEFT,RIGHT};
    enum Action{STANDING};

    Direction direction = DOWN;
    Action action = STANDING;


    int* currentAnimation;
    int currentAnimationFrame;

public:


};

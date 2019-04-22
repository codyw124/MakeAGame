#pragma once
#include "Character.h"

class Goku : public Character
{
private:
    
public:
    Goku(SDL_Renderer* renderer);
    ~Goku();
};

Goku::Goku(SDL_Renderer* renderer): Character
{
    setRenderer(renderer);
}

Goku::~Goku()
{
}

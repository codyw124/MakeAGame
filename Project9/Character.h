#pragma once
#include <map>
#include <queue>
#include <utility>
#include <SDL2/SDL_image.h>

class Character
{
public:
    enum Action{ STANDING, WALKING };
    enum Direction{ UP, DOWN, RIGHT };

    Character();
    ~Character();

    void loadSpriteSheet(std::string filepath, 
        int rowsOfSprites, int columnsOfSprites, 
        int widthOfSprites, int heightOfSprites, 
        int totalSpritesToLoad, SDL_Renderer* renderer);
    SDL_Rect* getNextSprite();
    const int& getSpriteWidth();
    const int& getSpriteHeight();
    SDL_Texture* getTexture();
    void setCurrentAnimation(std::queue<int>* animation);
    void setAnimation(Action action, Direction direction,
        std::queue<int> animation);
    std::queue<int>& getAnimation(Action action, Direction direction);

private:

    SDL_Renderer* renderer_;
    SDL_Texture* spriteSheet_;
    std::map<std::pair<Action,Direction>, std::queue<int>> animations_;
    std::queue<int>* currentAnimation_;
    SDL_Rect* spriteClips_;
    int numberOfSpritesLoaded_;

    void free();
};
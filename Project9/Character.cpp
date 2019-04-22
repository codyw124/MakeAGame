#include "Character.h"

Character::Character()
{
    //we need to initialize the sdl image library
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        throw std::runtime_error("SDL Image didnt load correctly\n");
    }

    //on creation we have no sprite sheet so point it to null
    spriteSheet_ = NULL;

    //create a new map to hold animations
    animations_ = std::map<std::pair<Action,Direction>, std::queue<int>>();

    //create a new queue to hold the current animation
    currentAnimation_ = NULL;

    //this array is empty for now but will hold the prite clips
    spriteClips_ = NULL;

    //we have yet tyo load any sprites
    numberOfSpritesLoaded_ = 0;

    //make our internal renderer point to nothing
    renderer_ = NULL;
}

Character::~Character()
{
    //free the memory allocated currently
    free();

    //quite the image library we initialized
    IMG_Quit();
}

void Character::free()
{
    //if we have pointed to a spritesheet thebn we need to destroy it and point to null
    if(spriteSheet_ != NULL)
    {
        SDL_DestroyTexture(spriteSheet_);
        spriteSheet_ = NULL;
    }

    //if we have an array of sprite clips we need to delete it and point it to null
    if(spriteClips_ != NULL)
    {
        delete [] spriteClips_;
        spriteClips_ = NULL;
    }

    //clear the animations that are stored in the animation map
    animations_.clear();

    //pop all the sprite indexs off of the current animation queue
    currentAnimation_ = NULL;

    //point our renderer back to nothing
    //leave it for the window to clean up
    renderer_ = NULL;

    numberOfSpritesLoaded_ = 0;
}

void Character::loadSpriteSheet(std::string filepath, 
    int rowsOfSprites, int columnsOfSprites, 
    int widthOfSprites, int heightOfSprites, 
    int totalSpritesToLoad, SDL_Renderer* renderer)
{
    //free the current allocations
    free();

    //point our renderer to the windows renderer where this character will be rendered
    renderer_ = renderer;

    //load the surface at the filepath that the user gave us
    SDL_Surface* loadedSurface = IMG_Load( filepath.c_str() );

    //if a texture could not be loaded from that file path throw an exception telling user that
    if( loadedSurface == NULL )
    {
        throw std::runtime_error("SDL surface didnt init correctly\n");
    }
    else
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

        //Create texture from surface pixels
        spriteSheet_ = SDL_CreateTextureFromSurface( renderer_, loadedSurface );

        if( spriteSheet_ == NULL )
        {
            throw std::runtime_error("SDL texture didnt load correctly\n");
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //initialize space for all the clips we will load
    spriteClips_ = new SDL_Rect[totalSpritesToLoad];

    //track whether or not we have loaded all the sprites
    bool loadedAllSprites = false;

    //for each row and column
    for(int r = 0; r < rowsOfSprites && !loadedAllSprites; r++)
    {
        for(int c = 0; c < columnsOfSprites && !loadedAllSprites; c++)
        {
            //mark the location of the start, the width, and the height of the current sprite clip
            spriteClips_[ numberOfSpritesLoaded_ ].x =   c * widthOfSprites;
            spriteClips_[ numberOfSpritesLoaded_ ].y =   r * heightOfSprites;
            spriteClips_[ numberOfSpritesLoaded_ ].w = widthOfSprites;
            spriteClips_[ numberOfSpritesLoaded_ ].h = heightOfSprites;

            //increment the number of sprites we have loaded
            numberOfSpritesLoaded_++;

            //check if we have loaded all sprites
            loadedAllSprites = numberOfSpritesLoaded_ == totalSpritesToLoad;
        }
    }
}

void Character::setAnimation(Action action, Direction direction,
    std::queue<int> animation)
{
    //create a pair out of the action and direction
    std::pair<Action,Direction> x = std::pair<Action,Direction>(action,direction);
    
    //map that pair to a queue of ints that mark the indexes for that action direcitons animation
    animations_.insert(std::pair<std::pair<Action,Direction>,std::queue<int>>(x,animation));
}

SDL_Rect* Character::getNextSprite()
{
    if(currentAnimation_ == NULL)
    {
        throw std::runtime_error("you havent set the current animation\n");
    }

    //get the next sprite
    int nextSprite =  currentAnimation_->front();

    //pop it off the front
    currentAnimation_->pop();

    //push it to the back of the queue
    currentAnimation_->push(nextSprite);

    //return the sprite that is at that spot
    return &spriteClips_[nextSprite];
}

const int& Character::getSpriteWidth()
{
    if(spriteClips_ == NULL)
    {
        throw std::runtime_error("you havent got any sprite clips yet\n");
    }

    return spriteClips_[0].w;
}

const int& Character::getSpriteHeight()
{
    if(spriteClips_ == NULL)
    {
        throw std::runtime_error("you havent got any sprite clips yet\n");
    }

    return spriteClips_[0].h;
}


SDL_Texture* Character::getTexture()
{
    return spriteSheet_;
}


void Character::setCurrentAnimation(std::queue<int>* animation)
{
    currentAnimation_ = animation;
}

std::queue<int>& Character::getAnimation(Action action, Direction direction)
{
    //create a pair out of the action and direction
    std::pair<Action,Direction> x = std::pair<Action,Direction>(action,direction);

    //return what is at that spot in the map
    return animations_[x];
}
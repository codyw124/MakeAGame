#include "Window.h"

Window::Window(const int& width, const int& height, const std::string& name)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        throw std::runtime_error("SDL didnt init correctly\n");
    }

    width_ = width;
    height_ = height;
    name_ = name;
    open_ = true;
    window_ = NULL;
    renderer_ = NULL;

    window_ = SDL_CreateWindow(
        name_.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        0);

    if (window_ == NULL)
    {
        throw std::runtime_error("ERROR:SDL didnt make a window correctly\n");
    }
    else
    {
        //create a renderer
        renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        //if the renderer didnt load  throw an error
        if (renderer_ == NULL)
        {
            throw std::runtime_error("ERROR:SDL didnt make a renderer\n");
        }

         //Initialize renderer color 
         SDL_SetRenderDrawColor( renderer_, 255, 255, 255, 255 ); 
    }
}

Window::~Window()
{
    free();
}

void Window::free()
{
    if (window_ != NULL)
    {
        SDL_DestroyWindow(window_);
        open_ = false;
        window_ = NULL;
    }

    SDL_Quit();
}

const int& Window::getHeight()
{
    return height_;
}

const int& Window::getWidth()
{
    return width_;
}

const std::string& Window::getName()
{
    return name_;
}

const bool& Window::isOpen()
{
    return open_;
}

void Window::runMainLoop()
{
    //Event handler
    SDL_Event e;

    //while not quit
    while (open_)
    {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT)
            {
                //free the window
                free();
            }
            //User presses a key
            else if (e.type == SDL_KEYDOWN)
            {
                //Select surfaces based on key press
                switch (e.key.keysym.sym)
                {
                case SDLK_w:
                    playerCharacter_->setCurrentAnimation(&playerCharacter_->getAnimation(playerCharacter_->WALKING, playerCharacter_->UP));
                    break;

                case SDLK_s:
                    playerCharacter_->setCurrentAnimation(&playerCharacter_->getAnimation(playerCharacter_->WALKING, playerCharacter_->DOWN));
                    break;

                case SDLK_a:
                    // playerCharacter_->setCurrentAnimation(&playerCharacter_->getAnimation(playerCharacter_->WALKING, playerCharacter_->LEFT));
                    break;

                case SDLK_d:
                    playerCharacter_->setCurrentAnimation(&playerCharacter_->getAnimation(playerCharacter_->WALKING, playerCharacter_->RIGHT));
                    break;

                case SDLK_j:
                    break;

                case SDLK_k:
                    break;

                case SDLK_b:
                    break;

                case SDLK_n:
                    break;

                case SDLK_r:
                    break;

                case SDLK_u:
                    break;

                default:
                    break;
                }
            }
             //User releases a key
            else if (e.type == SDL_KEYUP)
            {
                //Select surfaces based on key press
                switch (e.key.keysym.sym)
                {
                case SDLK_w:
                    playerCharacter_->setCurrentAnimation(&playerCharacter_->getAnimation(playerCharacter_->STANDING, playerCharacter_->UP));
                    break;

                case SDLK_s:
                    playerCharacter_->setCurrentAnimation(&playerCharacter_->getAnimation(playerCharacter_->STANDING, playerCharacter_->DOWN));
                    break;

                case SDLK_a:
                    // playerCharacter_->setCurrentAnimation(&playerCharacter_->getAnimation(playerCharacter_->STANDING, playerCharacter_->LEFT));
                    break;

                case SDLK_d:
                    playerCharacter_->setCurrentAnimation(&playerCharacter_->getAnimation(playerCharacter_->STANDING, playerCharacter_->RIGHT));
                    break;
                }
            }

            //Clear screen
            SDL_RenderClear(renderer_);

            //render the current player
            renderPlayer();

            //Update screen
            SDL_RenderPresent(renderer_);
        }
    }
}

void Window::setPlayer(Character& character)
{
    playerCharacter_ = &character;
}

void Window::renderPlayer()
{
    if(renderer_ == NULL)
    {
        throw std::runtime_error("cant render player because renderer isnt pointing anything\n");
    }
    if(playerCharacter_ == NULL)
    {
        throw std::runtime_error("cant render player because player isnt pointing anything\n");
    }
    
    SDL_Rect placeToRender = { 0,0, playerCharacter_->getSpriteWidth(), playerCharacter_->getSpriteHeight() };

    SDL_RenderCopy( renderer_, playerCharacter_->getTexture(), playerCharacter_->getNextSprite(), &placeToRender );
}

SDL_Renderer* Window::getRenderer()
{
    return renderer_;
}
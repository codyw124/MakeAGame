//Cody Ware
//5/19/19

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
    scene_ = NULL;

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
        window_ = NULL;
    }

    if(renderer_ != NULL)
    {
        SDL_DestroyRenderer(renderer_);
        renderer_ = NULL;
    }

    SDL_Quit();

    delete scene_;
    scene_ = NULL;

    open_ = false;
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
                    break;

                case SDLK_s:
                    break;

                case SDLK_a:
                    break;

                case SDLK_d:
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
                    break;

                case SDLK_s:
                    break;

                case SDLK_a:
                    break;

                case SDLK_d:
                    break;
                }
            }

            //Clear screen
            SDL_RenderClear(renderer_);

            for(GameObject* x : scene_->getGameObjects())
            {
                x->getSpriteSheet()->render();
            }

            //Update screen
            SDL_RenderPresent(renderer_);
        }
    }
}

SDL_Renderer* Window::getRenderer()
{
    return renderer_;
}

 void Window::setScene(Scene* scene)
 {
    scene_ = scene;
 }

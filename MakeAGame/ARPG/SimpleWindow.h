//Cody Ware
//5/19/19

#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include "WindowMainLoop.h"
#include "EventHandler.h"

class SimpleWindow : public EventHandler
{
private:
	int width_;
	int height_;
	std::string name_;
	SDL_Window* window_;
	SDL_Renderer* renderer_;
	bool open_;
	bool fullScreen_;
	void handleEvent(SDL_Event* event, SDL_Renderer* renderer);

public:
	SimpleWindow(const int& width, const int& height, const std::string& name, const bool& useFullScreen = false, const bool& initSDLImages = false, const bool& initSDLTTF = false);
	~SimpleWindow();

	void operator() (WindowMainLoop* mainLoop);
	void runMainLoop(WindowMainLoop* mainLoop);

	const int& getHeight();
	const int& getWidth();
	const std::string& getName();
	void free();
	const bool& isOpen();
	SDL_Renderer* getRenderer();
	SDL_Window* getWindow();
	void toggleFullscreen();
};

SimpleWindow::SimpleWindow(const int& width, const int& height, const std::string& name, const bool& useFullScreen, const bool& initSDLImages, const bool& initSDLTTF)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::runtime_error("SDL didnt initialize correctly\n");
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		throw std::runtime_error("SDL_image didnt initialize correctly\n");
	}

	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		throw std::runtime_error("SDL_ttf didnt initialize correctly\n");
	}

	width_ = width;
	height_ = height;
	name_ = name;
	open_ = true;
	window_ = NULL;
	renderer_ = NULL;
	fullScreen_ = true;

	if (useFullScreen) 
	{
		window_ = SDL_CreateWindow(
			name_.c_str(),
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			width,
			height,
			SDL_WINDOW_FULLSCREEN_DESKTOP);
	}
	else 
	{
		window_ = SDL_CreateWindow(
			name_.c_str(),
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			width,
			height,
			0);
	}

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
		SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
	}
}

SimpleWindow::~SimpleWindow()
{
	free();
}

void SimpleWindow::operator()(WindowMainLoop* mainLoop)
{
	runMainLoop(mainLoop);
}

void SimpleWindow::runMainLoop(WindowMainLoop* mainLoop)
{
	mainLoop->runMainLoop(window_, renderer_);
}

void SimpleWindow::free()
{
	if (window_ != NULL)
	{
		SDL_DestroyWindow(window_);
		window_ = NULL;
	}

	if (renderer_ != NULL)
	{
		SDL_DestroyRenderer(renderer_);
		renderer_ = NULL;
	}

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	open_ = false;
}

const int& SimpleWindow::getHeight()
{
	return height_;
}

const int& SimpleWindow::getWidth()
{
	return width_;
}

const std::string& SimpleWindow::getName()
{
	return name_;
}

SDL_Renderer* SimpleWindow::getRenderer()
{
	return renderer_;
}

SDL_Window* SimpleWindow::getWindow()
{
	return window_;
}

void SimpleWindow::toggleFullscreen()
{
	if (fullScreen_)
	{
		SDL_SetWindowFullscreen(window_, SDL_FALSE);
		fullScreen_ = false;
	}
	else
	{
		SDL_SetWindowFullscreen(window_, SDL_TRUE);
		fullScreen_ = true;
	}
}

const bool& SimpleWindow::isOpen()
{
	return open_;
}

void SimpleWindow::handleEvent(SDL_Event* event, SDL_Renderer* renderer)
{

}
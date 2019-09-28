//Cody Ware
//5/19/19

#pragma once

#include <list>
#include <string>
#include <SDL.h>
#include "Renderable.h"

class Scene
{
private:
	std::list<Renderable*> renderables_;

protected:
	SDL_Renderer* renderer_;

public:
	Scene();
	~Scene();
	void addRenderable(Renderable* toBeAdded);
	void removeRenderable(Renderable* toBeRemoved);
	void setRenderer(SDL_Renderer* renderer);
	const std::list<Renderable*>& getRenderables() const;
	void render() const;
};
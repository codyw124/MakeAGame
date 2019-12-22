//Cody Ware
//5/19/19

#pragma once

#include <list>
#include <string>
#include <SDL.h>
#include "Renderable.h"

class Scene : public Renderable
{
private:
	std::list<Renderable*> renderables_;

public:
	Scene();
	~Scene();
	void addRenderable(Renderable* toBeAdded);
	void removeRenderable(Renderable* toBeRemoved);
	const std::list<Renderable*>& getRenderables() const;
	void render(SDL_Renderer* renderer) const;
};
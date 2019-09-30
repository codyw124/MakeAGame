//Cody Ware
//5/19/19

#include "Scene.h"

Scene::Scene()
{
	renderables_ = std::list<Renderable*>();
}

Scene::~Scene()
{
}

void Scene::addRenderable(Renderable* toBeAdded)
{
	renderables_.push_back(toBeAdded);
}

void Scene::removeRenderable(Renderable* toBeRemoved)
{
	renderables_.remove(toBeRemoved);
}

const std::list<Renderable*>& Scene::getRenderables() const
{
	return renderables_;
}

void Scene::render(SDL_Renderer* renderer) const
{
	for (Renderable* renderables : renderables_) 
	{
		renderables->render(renderer);
	}
}

//Cody Ware
//5/19/19

#include "Scene.h"

Scene::Scene()
{
	renderables_ = std::list<Renderable*>();
	renderer_ = NULL;
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

void Scene::setRenderer(SDL_Renderer* renderer)
{
	renderer_ = renderer;
}

const std::list<Renderable*>& Scene::getRenderables() const
{
	return renderables_;
}

void Scene::render() const
{
	for (Renderable* renderables : renderables_) 
	{
		renderables->render(renderer_);
	}
}

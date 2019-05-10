#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::saveToFile(std::string fileName)
{
    std::ofstream outfile(fileName);

    outfile << "my text here!" << std::endl;

    outfile.close();
}
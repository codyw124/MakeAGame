#pragma once
#include <iostream>
#include <vector>
#include "tinyxml2.h"
#include "Renderable.h"
#include "Player.h"
#include "Chest.h"
#include "Item.h"
#include "Enemy.h"
#include "Wall.h"
#include "Menu.h"

using namespace tinyxml2;
using namespace std;
class XMLLoader
{
public:
	vector<GameObject*> operator()(const char* filename);

private:

};

vector<GameObject*> XMLLoader::operator()(const char* filename)
{
	vector<GameObject*> listOfRenderables;

	XMLDocument xml_doc;

	XMLError eResult = xml_doc.LoadFile(filename);

	XMLElement* renderables = xml_doc.FirstChildElement("GAME_OBJECTS");

	if (renderables == NULL)
	{
		throw std::runtime_error("XML Loader found no RENDERABLES in file\n"); ;
	}
	else
	{
		for (XMLElement* currentRenderable = renderables->FirstChildElement("GAME_OBJECT");
			currentRenderable != NULL;
			currentRenderable = currentRenderable->NextSiblingElement())
		{
			if (currentRenderable == NULL)
			{
				throw std::runtime_error("XML Loader found no GAME_OBJECT in GAME_OBJECTS\n");
			}
			else
			{

				const XMLAttribute* type = currentRenderable->FindAttribute("TYPE");

				if (strcmp(type->Value(), "PLAYER") == 0)
				{
					listOfRenderables.push_back(new Player({ currentRenderable->FirstChildElement("XLOCATION")->IntText(), currentRenderable->FirstChildElement("YLOCATION")->IntText() }));
				}
				else if (strcmp(type->Value(), "CHEST") == 0)
				{
					listOfRenderables.push_back(new Chest({ currentRenderable->FirstChildElement("XLOCATION")->IntText(), currentRenderable->FirstChildElement("YLOCATION")->IntText() }));
				}
				else if (strcmp(type->Value(), "ITEM") == 0)
				{
					listOfRenderables.push_back(new Item({ currentRenderable->FirstChildElement("XLOCATION")->IntText(), currentRenderable->FirstChildElement("YLOCATION")->IntText() }));
				}
				else if (strcmp(type->Value(), "ENEMY") == 0)
				{
					listOfRenderables.push_back(new Enemy({ currentRenderable->FirstChildElement("XLOCATION")->IntText(), currentRenderable->FirstChildElement("YLOCATION")->IntText() }));
				}
				else if (strcmp(type->Value(), "WALL") == 0)
				{
					listOfRenderables.push_back(new Wall({ currentRenderable->FirstChildElement("XLOCATION")->IntText(), currentRenderable->FirstChildElement("YLOCATION")->IntText() },
						currentRenderable->FirstChildElement("WIDTH")->IntText(), currentRenderable->FirstChildElement("HEIGHT")->IntText()));
				}
				else if (strcmp(type->Value(), "MENU") == 0)
				{
					listOfRenderables.push_back(new Menu());
				}
				else if (strcmp(type->Value(), "UI") == 0)
				{
					listOfRenderables.push_back(new UI());
				}
				else
				{
					throw std::runtime_error("XML Loader found no RENDERABLE with invalid type\n");
				}
			}
		}
	}

	return listOfRenderables;
}
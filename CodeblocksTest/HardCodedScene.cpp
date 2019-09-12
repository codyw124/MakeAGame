//Cody Ware
//8/29/19

#include "HardCodedScene.h"

HardCodedScene::HardCodedScene(SDL_Renderer* renderer)
{
    Scene();
    renderer_ = renderer;
    firstObject = new GameObject();
    spriteSheet = new SpriteSheet();
    spriteSheet->setRenderer(renderer);
    spriteSheet->loadTextureAndMetaData("Goku_SpriteSheet.png", "Goku_SpriteSheet.meta");
    spriteSheet->setClip("standing_down");
    firstObject->setSpriteSheet(spriteSheet);
    addGameObject(firstObject);
}

HardCodedScene::~HardCodedScene()
{
    delete firstObject;
    firstObject = NULL;
    delete spriteSheet;
    spriteSheet = NULL;
}

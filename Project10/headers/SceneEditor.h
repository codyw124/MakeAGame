//Cody Ware
//5/19/19

#pragma once

#include <string>
#include <iostream>
#include "../headers/Scene.h"
#include "../headers/GameObject.h"
#include "../headers/Component.h"

class SceneEditor
{
private:
    std::string mode_;
    bool workingOnFile_;
    Scene* currentScene_;
    GameObject* currentGameObject_;
    Component* currentComponent_;
    
public:
    SceneEditor();
    ~SceneEditor();

    void runMainLoop();

    void help();
};
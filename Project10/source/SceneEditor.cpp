#include "../headers/SceneEditor.h"

SceneEditor::SceneEditor()
{
    mode_ = "scene";
    workingOnFile_ = false;
    currentScene_ = NULL;
    currentGameObject_ = NULL;
    currentComponent_ = NULL;
}

SceneEditor::~SceneEditor()
{
}

void SceneEditor::runMainLoop()
{
    help();
}

void SceneEditor::help()
{

    std::cout << "Current Mode: " << mode_ << std::endl;
    std::cout << "---Valid Commands---" << std::endl;
    std::cout << "-list\t\tlists available " << mode_ << " files" << std::endl;
    std::cout << "-new\t\tcreates a new " << mode_ << " file" << std::endl;
    std::cout << "-select\t\tattempts to select a " << mode_ << " with the given filename" << std::endl;
    std::cout << "-delete\t\tdeletes if it exists" << std::endl;
    std::cout << "-mode\t\tchange what mode program is running in" << std::endl;

    if (workingOnFile_)
    {
        std::cout << "-save\tsaves the currently selected file" << std::endl;
        // std::cout<< "-remove\t\t\tremoves" << std::endl;
        std::cout << "-exit\texits currently selected file" << std::endl;
    }
    else
    {
        std::cout << "-exit\t\texits program" << std::endl;
    }

    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    SceneEditor x = SceneEditor();

    x.runMainLoop();

    return 0;
}
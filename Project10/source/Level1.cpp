//Cody Ware
//5/19/19

#include <iostream>
#include "../headers/Window.h"

using namespace std;

void createWindow();

int main(int argc, char *argv[])
{
    createWindow();
    return 0;
}

void createWindow()
{

    //make a window  with this width and height
    Window window = Window(240, 160, "Level 1");

    window.setScene("Level1.scene");

    window.runMainLoop();
}
//cody ware
//8/29/2019

#include <iostream>
#include "Window.h"
#include "HardCodedScene.h"

using namespace std;

int main()
{
    Window window(500,500,"test");
    HardCodedScene scene(window.getRenderer());
    window.setScene(&scene);
    window.runMainLoop();
    return 0;
}

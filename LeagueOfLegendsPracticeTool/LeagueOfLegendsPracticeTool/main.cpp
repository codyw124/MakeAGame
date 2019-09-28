#include <iostream>
#include "Window.h"
#include "Scene.h"
#include "Renderable.h"
#include "Square.h"

using namespace std;

int main(int argc, char* argv[])
{
	Window window(240,160,"test");
	Scene testScene;
	Square character(50,50,50,50);
	testScene.addRenderable(&character);
	window.setScene(&testScene);
	window.runMainLoop();
	return 0;
}
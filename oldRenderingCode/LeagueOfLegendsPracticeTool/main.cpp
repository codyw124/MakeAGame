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
	Square background(0,0,240,160);
	Square a(20, 50, 25, 25);
	Square b(50, 50, 25, 25);
	Square c(80, 50, 25, 25);
	testScene.addRenderable(&a);
	testScene.addRenderable(&b);
	testScene.addRenderable(&c);
	window.setScene(&testScene);
	window.runMainLoop();
	return 0;
}
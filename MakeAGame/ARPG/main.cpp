#include <SDL.h>
#include <stdio.h>
#include "SimpleWindow.h"
#include "ARPGMainLoop.h"

int main(int argc, char* args[])
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	SimpleWindow window(SCREEN_WIDTH, SCREEN_HEIGHT, "test");
	ARPGMainLoop test2;
	window.runMainLoop(&test2);

	return 0;
}
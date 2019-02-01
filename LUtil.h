#ifndef LUTIL_H
#define LUTIL_H

#include "LOpenGL.h"
#include <stdio.h>

//Screen Constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 1000;
const int SCREEN_FPS = 60;

const int COLOR_MODE_MULTI = 1;

bool initGL();

void update();

void render();

void handleKeys( unsigned char key, int x, int y );

#endif

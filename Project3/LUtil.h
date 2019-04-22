#ifndef LUTIL_H
#define LUTIL_H

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include "Geometry2D.h"
//Screen Constants
const int SCREEN_WIDTH = 240;
const int SCREEN_HEIGHT = 160;
const int SCREEN_FPS = 60;

bool initGL();
void update();
void render();
void handleKeys( unsigned char key, int x, int y );
void renderRectangle2D(Rectangle2D rect);

#endif

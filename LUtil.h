//cody ware
//open gl 1
//2/12/2019

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

//Screen constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_FPS = 60;
// bool closeWindow = false;

bool initGL();
void update();
void render();
void handleKeys( unsigned char key, int x, int y );

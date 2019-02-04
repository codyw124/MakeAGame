#pragma once

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

#include "FailedToLoadGlException.h"

class MyClass
{
public:
    MyClass(int argc, char* args[], const int& screenWidth, const int& screenHeight, const int & fps, void (*func)(void));
    ~MyClass();

private:
    void initGL(const int& width, const int & height);
    void initGLUT(int argc, char* args[], const int& width, const int & height, const int & fps, void (*func)(void));
    
};
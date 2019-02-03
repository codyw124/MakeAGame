#pragma once

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

#include "FailedToLoadGlException.h"

class MyClass
{
public:
    MyClass(int argc, char* args[], const int& screenWidth, const int& screenHeight);
    ~MyClass();

private:
    void initGL(const int& width, const int & height);
    void initGLUT(int argc, char* args[], const int& width, const int & height);
    
};
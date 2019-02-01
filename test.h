#pragma once

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

class MyClass
{
public:
    MyClass();
    MyClass(MyClass && other);
    MyClass(const MyClass & other);
    MyClass &operator=(MyClass &&  other);
    MyClass &operator=(const MyClass & other);
    ~MyClass();

private:
    void deepCopy(const MyClass & other);
    bool initGL();

    size_t _screenWidth;
    size_t _screenHeight;
    size_t _fps;
    bool _glInitialized;
    
};
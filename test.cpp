#include "test.h"

MyClass::MyClass()
{
    _screenWidth = 800;
    _screenHeight = 600;
    _fps = 60;
}
MyClass::MyClass(MyClass && other)
{
    _screenWidth = other._screenWidth;
    _screenHeight = other._screenHeight;
    _fps = other._fps;

    other._fps = 0;
    other._fps = 0;
    other._fps = 0;

}
MyClass::MyClass(const MyClass & other)
{
    deepCopy(other);
}
MyClass& MyClass::operator=(MyClass && other)
{
     _screenWidth = other._screenWidth;
    _screenHeight = other._screenHeight;
    _fps = other._fps;

    other._fps = 0;
    other._fps = 0;
    other._fps = 0;

    return *this;
}
MyClass& MyClass::operator=(const MyClass & other)
{
    deepCopy(other);
    return *this;
}
MyClass::~MyClass()
{
    
}
void MyClass::deepCopy(const MyClass & other)
{
    _screenWidth = other._screenWidth;
    _screenHeight = other._screenHeight;
    _fps = other._fps;
}

bool MyClass::initGL()
{
    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0.0, _screenWidth, _screenHeight, 0.0, 1.0, -1.0 );

    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        return false;
    }

    return true;
}
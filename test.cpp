#include "test.h"

MyClass::MyClass(int argc, char* args[], const int& screenWidth, const int& screenHeight, const int& fps, void (*func)(void))
{
    initGL(screenWidth, screenHeight);

    initGLUT(argc, args, screenWidth, screenHeight, fps, *func);
}

MyClass::~MyClass()
{
    
}

void MyClass::initGL(const int& width, const int & height)
{
    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0.0, width, height, 0.0, 1.0, -1.0 );

    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        throw FailedToLoadGlException("GL didnt load properly");
    }
}

void MyClass::initGLUT(int argc, char* args[], const int& width, const int & height, const int & fps, void (*func)(void))
{
    //initialize glut
	glutInit(&argc,args);

	//initialize the context version
	glutInitContextVersion(2,1);

	//initialize the display mode -- a double buffered window
	glutInitDisplayMode(GLUT_DOUBLE);

    //iniialize the window sizes
    glutInitWindowSize( width, height);

    //make the window and give it a name
    glutCreateWindow("OpenGL");

    glutDisplayFunc(*func);

}
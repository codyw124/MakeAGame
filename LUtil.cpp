#include "LUtil.h"

bool initGL()
{
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glClearColor( 0.f, 0.f, 0.f, 1.f );

    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        return false;
    }

    return true;
}

void update()
{

}

void render()
{
    glClear( GL_COLOR_BUFFER_BIT );

    //size , xloc, yloc
    Square a = mew Square(5, 0, 0);

    renderables.add(a);

    for(Renderable x : renderables)
    {
        x.render();      
    }

    glBegin( GL_QUADS );
        glVertex2f( -0.5f, -0.5f );
        glVertex2f(  0.5f, -0.5f );
        glVertex2f(  0.5f,  0.5f );
        glVertex2f( -0.5f,  0.5f );
    glEnd();

    glutSwapBuffers();
}

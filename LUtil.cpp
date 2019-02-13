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

    //Reset modelview matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Move to center of the screen
    glTranslatef( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, 0.f );

    //RYGB Mix
    glBegin( GL_QUADS ); 
        glColor3f( 0.f, 1.f, 1.f );
        glVertex2f( -50.f, -50.f );
        glVertex2f(  50.f, -50.f );
        glVertex2f(  50.f,  50.f );
        glVertex2f( -50.f,  50.f );
    glEnd();
    

    glutSwapBuffers();
}

void handleKeys( unsigned char key, int x, int y )
{
}

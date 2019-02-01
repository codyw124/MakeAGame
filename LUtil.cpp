#include "LUtil.h"

//The projection scale 
GLfloat gProjectionScale = 1.f;

bool initGL()
{
    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0 );

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

void update()
{

}

void render()
{
    //Clear color buffer
    glClear( GL_COLOR_BUFFER_BIT );

    //Reset modelview matrix 
    glMatrixMode( GL_MODELVIEW ); 
    glLoadIdentity();

    //Move to center of the screen 
    glTranslatef( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, 0.f );

    //Render top blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-100,-100);
        glVertex2f(0,0);
        glVertex2f(100,-100);
        glVertex2f(0,-200);
    glEnd();

    //Render left green
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-100,-100);
        glVertex2f(0,0);
        glVertex2f(0,200);
        glVertex2f(-100,100);
    glEnd();

    //Render right red
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(100,-100);
        glVertex2f(100,100);
        glVertex2f(0,200);
    glEnd();

    //Update screen
    glutSwapBuffers();
}

void handleKeys( unsigned char key, int x, int y ) 
{
    //handle wasd
    if(key == 'w') 
    {
          
    }
    else if(key == 'a') 
    {
          
    }
    else if(key == 's') 
    {
          
    }
    else if(key == 'd') 
    {
          
    }
}
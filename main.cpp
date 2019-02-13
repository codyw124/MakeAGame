#include "LUtil.h"

void runMainLoop( int val );

int main( int argc, char* args[] )
{
    glutInit( &argc, args );
    glutInitContextVersion( 2, 1 );
    glutInitDisplayMode( GLUT_DOUBLE );
    glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
    glutCreateWindow( "1" );
    
    if( !initGL() )
    {
        printf( "Unable to initialize GL!\n" );
        return 1;
    }
    
    glutKeyboardFunc( handleKeys );
    
    glutDisplayFunc( render );
    
    glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, 0 );
    
    glutMainLoop();

    return 0;
}

void runMainLoop( int val )
{
    update();
    render();

    // if(!closeWindow)
    // {
        glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, val );
    // }
}

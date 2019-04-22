#include "LUtil.h"

//Camera position
GLfloat gCameraX = 0.f, gCameraY = 0.f;

//make storange for game items
Rectangle2D* player;
std::list<Rectangle2D*> walls = std::list<Rectangle2D*>();
std::list<Circle*> goldKeys = std::list<Circle*>();
std::list<Circle*> silverKeys = std::list<Circle*>();

bool initGL()
{
    //Set the viewport
    glViewport(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT);

    //Initialize Projection Matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0);

    //Initialize Modelview Matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Save the default modelview matrix
    glPushMatrix();

    //Initialize clear color
    glClearColor(0.f, 0.f, 0.f, 1.f);

    //Check for error
    GLenum error = glGetError();
    if (error != GL_NO_ERROR)
    {
        printf("Error initializing OpenGL! %s\n", gluErrorString(error));
        return false;
    }

    loadGame();

    return true;
}

void update()
{
}

void render()
{
    //Clear color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    //Reset modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();

    //Save default matrix again
    glPushMatrix();

    //change color to green for walls
    glColor3f(0.f, 1.f, 0.f);

    //render walls
    for(Rectangle2D* x : walls)
    {
        //renderRectangle2D(*x);
    }

    //change color to blue for the player
    glColor3f(0.f, 0.f, 1.f);

    //render the player
    renderRectangle2D(player);

    //change the color to yellow for keys
    glColor3f(1.f,1.f,0.f);

    for(Circle* x : goldKeys)
    {
        //renderCircle(x);
    }

    //change the color to yellow for keys
    glColor3f(1.f,1.f,1.f);

    for(Circle* x : silverKeys)
    {
        //renderCircle(x);
    }

    //Update screen
    glutSwapBuffers();
}

void handleKeys(unsigned char key, int x, int y)
{
    //store the location
    GLfloat oldCameraY = gCameraY;
    GLfloat oldCameraX = gCameraX;
    float oldPlayerY = (*player).origin.y;
    float oldPlayerX = (*player).origin.x;

    //If the user pressed w/a/s/d, change camera position
    if (key == 'w')
    {
        gCameraY -= 10.f;
        (*player).origin.y -= 10.f;
    }
    else if (key == 's')
    {
        gCameraY += 10.f;
        (*player).origin.y += 10.f;
    }
    else if (key == 'a')
    {
        gCameraX -= 10.f;
        (*player).origin.x -= 10.f;
    }
    else if (key == 'd')
    {
        gCameraX += 10.f;
        (*player).origin.x += 10.f;
    }

    //check if there was a collision with each wall
    for (Rectangle2D* x : walls)
    {
        if (RectangleRectangle((*player), *x))
        {
            gCameraY = oldCameraY;
            gCameraX = oldCameraX;
            (*player).origin.y = oldPlayerY;
            (*player).origin.x = oldPlayerX;
        }
    }

    //check if there was a collision with each gold key
    for (Circle* x : goldKeys)
    {
        if (RectangleCircle((*player), *x))
        {
            goldKeys.remove(x);
            delete x;
        }
    }

    //check if there was a collision with each silver key
    for (Circle* x : silverKeys)
    {
        if (RectangleCircle((*player), *x))
        {
            silverKeys.remove(x);
            delete x;
        }
    }

    //Take saved matrix off the stack and reset it
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glLoadIdentity();

    //Move camera to position
    glTranslatef(-gCameraX, -gCameraY, 0.f);

    //Save default matrix again with camera translation
    glPushMatrix();
}

void renderRectangle2D(const Rectangle2D* rect)
{
    //move to the location
    glTranslated((*rect).origin.x, (*rect).origin.y, 0.f);

    //render the rect
    glBegin(GL_QUADS);
    glVertex2f(0.f, 0.f);
    glVertex2f((*rect).size.x, 0.f);
    glVertex2f((*rect).size.x, (*rect).size.y);
    glVertex2f(0.f, (*rect).size.y);
    glEnd();

    //move back to start location
    glTranslated(-(*rect).origin.x, -(*rect).origin.y, 0.f);
}

void renderCircle(const Circle* circ)
{
    //move to the location
    glTranslated((*circ).position.x, (*circ).position.y, 0.f);

    glBegin(GL_LINES);

    GLfloat x;
    GLfloat y;

    for (int i = 0; i < 360; i += 1)
    {
        glVertex2f((*circ).position.x, (*circ).position.y);

        x = (*circ).position.x + (*circ).radius * sin(0.0174f * i);
        y = (*circ).position.y + (*circ).radius * cos(0.0174f * i);
        glVertex2f(x, y);
    }

    glEnd();

    //move to the start location
    glTranslated(-(*circ).position.x, -(*circ).position.y, 0.f);
}

void loadGame()
{
//make the player size
vec2 playerSize(10.f, 10.f);

//make the players spawn point
Point2D playerSpawn((SCREEN_WIDTH / 2) - playerSize.x + gCameraX,
                    (SCREEN_HEIGHT / 2) - playerSize.y + gCameraY);

//make the player
player = new Rectangle2D(playerSpawn, playerSize);

//make and add each wall to our storage
walls.push_back(new Rectangle2D(Point2D(0.f, 0.f), vec2(SCREEN_WIDTH, 10.f)));
walls.push_back(new Rectangle2D(Point2D(0.0f, 0.f), vec2(10.f, SCREEN_HEIGHT)));
walls.push_back(new Rectangle2D(Point2D(SCREEN_WIDTH, SCREEN_HEIGHT), vec2(-10.f, -SCREEN_HEIGHT)));
walls.push_back(new Rectangle2D(Point2D(SCREEN_WIDTH, SCREEN_HEIGHT), vec2(-SCREEN_WIDTH, -10.f)));


//make goldKeys
goldKeys.push_back(new Circle(Point2D(100.f,100.f),10.f));

//make silverKeys
silverKeys.push_back(new Circle(Point2D(50.f,50.f),10.f));
}
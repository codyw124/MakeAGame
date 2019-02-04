#include <iostream>
#include "test.h"

using namespace std;

void render();
void update();

int main( int argc, char* args[] )
{

	MyClass test = MyClass(argc, args, 500,500, 60, render);

	return 0;
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glVertex2f(-0.5f,-0.5f);
	glVertex2f(0.5f,-0.5f);
	glVertex2f(0.5f,0.5f);
	glVertex2f(-0.5f,0.5f);
	glEnd();

	glutSwapBuffers();
}

void update()
{

}
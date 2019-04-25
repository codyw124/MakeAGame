#include <iostream>
#include "Window.h"
#include "Character.h"

using namespace std;

void runTests();
void runTestOne();
void runTestTwo();

int main(int argc, char* argv[])
{
    // runTests();
    runTestTwo();
    return 0;
}

void runTests()
{
    runTestOne();
    runTestTwo();
}

void runTestOne()
{
    cout<<"test 1" <<endl;

    //make a window  with this width and height
    Window x = Window(640,480, "test window");

    if(x.getHeight() != 480)
    {
        cout<<"get height is busted" <<endl;
    }

    if(x.getWidth() != 640)
    {
        cout<<"get width is busted" <<endl;
    }

    if(x.getName() != "test window")
    {
        cout<<"get name is busted" <<endl;
    }

    if(x.isOpen() != true)
    {
        cout<< "is open is preclose busted" <<endl;
    }

    //window should wait for you to close it
    cout<<"window should have waited for you to close it"<<endl;
    x.runMainLoop();

    x.free();

    if(x.isOpen() != false)
    {
        cout<< "is open after close is busted" <<endl;
    }
}

void runTestTwo()
{
    cout<<"test 2" <<endl;

    //make a window  with this width and height
    Window window = Window(240,160, "test window");

    Character character = Character();

    character.loadSpriteSheet("./Goku.png",23,23,32,32,507, window.getRenderer());

    std::queue<int> standingDownAnimation = std::queue<int>();
    standingDownAnimation.push(0);
    standingDownAnimation.push(1);

    std::queue<int> standingRightAnimation = std::queue<int>();
    standingRightAnimation.push(40);
    standingRightAnimation.push(41);

    std::queue<int> standingUpAnimation = std::queue<int>();
    standingUpAnimation.push(80);

    std::queue<int> walkingDownAnimation = std::queue<int>();
    walkingDownAnimation.push(2);
    walkingDownAnimation.push(3);
    walkingDownAnimation.push(4);
    walkingDownAnimation.push(5);

    std::queue<int> walkingRightAnimation = std::queue<int>();
    walkingRightAnimation.push(42);
    walkingRightAnimation.push(43);
    walkingRightAnimation.push(44);
    walkingRightAnimation.push(45);

    std::queue<int> walkingUpAnimation = std::queue<int>();
    walkingUpAnimation.push(81);
    walkingUpAnimation.push(82);
    walkingUpAnimation.push(83);
    walkingUpAnimation.push(84);

    character.setAnimation(character.STANDING, character.DOWN, standingDownAnimation);
    character.setAnimation(character.STANDING, character.RIGHT, standingRightAnimation);
    character.setAnimation(character.STANDING, character.UP, standingUpAnimation);
    character.setAnimation(character.WALKING, character.DOWN, walkingDownAnimation);
    character.setAnimation(character.WALKING, character.RIGHT, walkingRightAnimation);
    character.setAnimation(character.WALKING, character.UP, walkingUpAnimation);
    character.setCurrentAnimation(&(character.getAnimation(character.STANDING, character.DOWN)));

    window.setPlayer(character);

    window.runMainLoop();
}

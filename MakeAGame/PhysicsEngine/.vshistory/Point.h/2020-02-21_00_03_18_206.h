//Cody Ware
//7/26/19 

#pragma once

#ifdef PHYSICSENGINE_EXPORTS
#define PHYSICSENGINE __declspec(dllexport)
#else
#define PHYSICSENGINE __declspec(dllimport)
#endif

#include "PhysicsVector.h";

typedef PhysicsVector PHYSICSENGINE Point;
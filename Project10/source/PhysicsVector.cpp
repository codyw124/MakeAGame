//Cody Ware
//10/4/18

#include <cmath>
#include <cfloat>
#include <algorithm>
#include "../headers/PhysicsVector.h"

PhysicsVector::~PhysicsVector()
{
}

//converts degrees to radians
double PhysicsVector::radiansToDegrees(double radians)
{
    return radians * (HALF_CIRCLE_IN_DEGREES / M_PI);
}

//gets the degrees from radians
double PhysicsVector::degreesToRadians(double degrees)
{
    return degrees * (M_PI / HALF_CIRCLE_IN_DEGREES);
}

double PhysicsVector::correctDegrees(double degrees)
{
    while (degrees > 360.0f)
    {
        degrees -= 360.0f;
    }
    while (degrees < -360.0f)
    {
        degrees += 360.0f;
    }
    return degrees;
}

//compares two doubles using an epsilon
double PhysicsVector::epsilonCompare(double a, double b)
{
    //get the distance between the two numbers on a number line
    double distance = abs(a - b);

    //figure out which has a bigger absolute value
    double largestAbs = std::max(abs(a), abs(b));

    //epsilon is min, but it can be as high as the largest (abs * the epsilon)
    double maxAcceptableDistance = DBL_EPSILON * std::max(1.0, largestAbs);

    //return true if the distance less than the max acceptable distance
    return distance <= maxAcceptableDistance;
}
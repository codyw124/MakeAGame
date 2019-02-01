//Cody Ware
//10/4/18 

#pragma once  

namespace GamePhysics
{
	class PhysicsVector
	{
	public:
		virtual ~PhysicsVector() = 0;

		//helper functions
		static double radiansToDegrees(double radians);
		static double degreesToRadians(double degrees);
		static double correctDegrees(double degrees);
		static double epsilonCompare(double a, double b);

	private:
		static const int HALF_CIRCLE_IN_DEGREES = 180;
	};
}
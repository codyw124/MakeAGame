//Cody Ware
//1/9/19 

#pragma once  

namespace GamePhysics
{
	class IVector
	{
	public:

		//finds the magnitude of this IVector
		virtual double magnitude() const = 0;

		//finds the vector squared of this IVector
		virtual double magnitudeSquared() const = 0;

		//normalizes this vector
		virtual void normalize() = 0;
	};
}
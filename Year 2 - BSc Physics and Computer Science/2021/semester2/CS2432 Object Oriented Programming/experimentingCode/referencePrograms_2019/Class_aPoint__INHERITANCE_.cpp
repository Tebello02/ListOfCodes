/*
	NAME: Class{aPoint_INHERITANCE}.cpp
	
	FUNCTION:
	
	This class illustrates the concept of INHERITANCE in C++.
	
	Class aPoint is derived from class aTuple via "Public Inheritance".
	
	Class aTuple is defined in the C++ file: Class{aTuple}.cpp, which has been included in this
	definition of class aPoint file: Class{aPoint_INHERITANCE}.cpp
	
	Although class aPoint inherits everything from class aTupe, direct access to the data elements of
	class aTuple from class aPoint is restricted since all data in class aTuple is "private". Access
	to aTuple data from class aPoint can only be via the "public" member functions such as:
	
	(1) get_dimension() -- to access the dimension of the tuple
	(2) get_Coord(i) -- to get the value of point[i], the i-th coordinate
	(3) set_Coord(i, val) -- to assign point[i] the value, val -- i.e. point[i] = val
	
	(C) mofana mphaka; April 2021
*/


//	include the C++ source file, Class{aTuple}.cpp, containing class aTuple
#include <C:\Users\Mofan\OneDrive\Documents\CS2432{OOP}\Programs\Class{aTuple}.cpp>

//	Now, include the C++ maths library file for accessing functions like: sqrt (or pow)
#include <cmath>


#if !defined _A_POINT_
#define _A_POINT_

/**** C l a s s   D e c l a r a t i o n   &   C l a s s   I n t e r f a ce ****/

class aPoint : public aTuple<long double>
//	Define aPoint as aTuple whose coordinates are real numbers: aTuple<long double>
{
	// private data: *point & dimension will be inherited from aTuple
	
	//	Specific member functions for a Point
	public:		
		//	Class Constructor -- will use the class constructor for aTuple
		aPoint(long int _dimension = 1);

		//	Class Destructor -- empty. C++ scoping rules shall apply
		~aPoint() { }
		
		long double distance();	//	compute the Euclidean distance of this point from the origin
		
		bool operator ! ();		//	It returns TRUE (1) if this point is the origin, (0, 0, 0, ..., 0), FALSE (0) otherwise

		aPoint operator + (aPoint right);		//	Vector addition: add *this point to the point on the right -- *this + right
		aPoint operator - (aPoint right);		//	subtract the point on the right from *this point -- *this - right
		long double operator * (aPoint right);	//	Dot multiplication: *this * right
		aPoint operator * (long double right);	//	Scalar multiplication: *this * right
		
		/*
			NB: The non-member input/output redirection operators: >>, << will not be inherited (by class aPoint from class
			aTuple, since they are not memebr functions of aTuple), but they are already defined (for aTuple object) in the 
			C++ source file, Class{aTuple}.cpp, in which class aTuple is defined.
			
			So, by the C++ "scope rules", they are visible in this file, meaning they can be accessed and used as they are!
		*/
};


/**** C l a s s   I m p l e m e n t a t i o n ****/

aPoint :: aPoint(long int _dimension) : aTuple(_dimension)
//	(1) It creates aPoint as aTuple with dimension, _dimension, then
//	(2)	it sets all the coordinates to 0.
{
	for(_dimension = 0; _dimension < get_dimension(); _dimension++)
		//point[_dimension] = 0;
		set_Coord(_dimension, 0);
}

		
long double aPoint :: distance()
//	The distance of point (x0, x1, x2, ..., xN-1) from the origin is given by
//
//	sqrt(x0*x0 + x1*x1 + x2*x2 + ... + (xN-1)*(xN-1))
{
	long double sum = 0;
	
	for (long int i = 0; i < get_dimension(); i++)
		//sum = sum + point[i]*point[i]
		sum = sum + get_Coord(i) * get_Coord(i);
		
	return sqrt(sum);
}


bool aPoint :: operator ! ( )
//	Usage: ! P where P is a point.
//	Function: The operator returns TRUE (1) iff P == (0, 0, 0, ..., 0), FALSE (0) otherwise
{
	for (long int i = 0; i < this->get_dimension(); i++)
	{	
		if (this->get_Coord(i) != 0)
			//if (point[i] != 0)
			return false;
	}
		
	return true;
}


aPoint aPoint :: operator + (aPoint right)
//	Usage: P1 + P2 where P1 and P2 are points.
//	Function: The operator returns a new point which is the sum of the two points: P1 and P2
//	For any two points, (x0, x1, x2, ..., xN-1) and (y0, y1, y2, ..., yN-1)
//
//	(x0, x1, x2, ..., xN-1) + (y0, y1, y2, ..., yN-1) = (x0+y0, x1+y1, x2+y2, ..., (xN-1)+(yN-1))
//	
//	NB:
//	The two points can be added iff they have the same dimension otherwise the operator returns (0, 0, 0, ...,0).
{
	aPoint P(this->get_dimension());	//	Initially, create the point (0, 0, 0, ..., 0), the size of the point on the left
	
	if (this->get_dimension() == right.get_dimension())
	{
		for (long int i = 0; i < this->get_dimension(); i++)
			//P.point[i] = this->point[i] + right.point[i];
			P.set_Coord(i, this->get_Coord(i) + right.get_Coord(i));
	}
	
	return P;
}


aPoint aPoint :: operator - (aPoint right)
//	Usage: P1 - P2 where P1 and P2 are points.
//	Function: The operator returns a new point which is the difference: P1 - P2
//	For any two points, (x0, x1, x2, ..., xN-1) and (y0, y1, y2, ..., yN-1)
//
//	(x0, x1, x2, ..., xN-1) - (y0, y1, y2, ..., yN-1) = (x0-y0, x1-y1, x2-y2, ..., (xN-1)-(yN-1))
//	
//	NB:
//	The two points can be subtracted iff they have the same dimension otherwise the operator returns 0 (i.e. NULL).
{
	aPoint P(this->get_dimension());
	
	if (this->get_dimension() == right.get_dimension())
	{	
		for (long int i = 0; i < this->get_dimension(); i++)
			//P.point[i] = this->point[i] - right.point[i];
			P.set_Coord(i, this->get_Coord(i) - right.get_Coord(i));
	}
	
	return P;
}


aPoint aPoint :: operator * (long double right)
//	Usage: P1 * k where P1 is a point and k a scalar.
//
//	Function:
//	Multiplication of a point (x0, x1, x2, ..., xN-1) by a scalar k is given by
//
//	(x0, x1, x2, ..., xN-1) * k = (k*x0, k*x1, k*x2, ..., k*xN-1)
{
	aPoint P(this->get_dimension());
	
	for (long int i = 0; i < this->get_dimension(); i++)
		//P.point[i] = this->point[i] * right;
		P.set_Coord(i, this->get_Coord(i) * right);
	
	return P;
}


long double aPoint :: operator * (aPoint right)
//	Usage: P1 * P2 where P1 and P2 are points.
//
//	Function:
//	The Dot product of two points: (x0, x1, x2, ..., xN-1) and (y0, y1, y3, ..., yN-1) is given by
//
//	(x0, x1, x2, ..., xN-1) * (y0, y1, y3, ..., yN-1) = x0*y0 + x1*y1 + x2*y2 + ... + xN-1 * yN-1
//
//	NB: The dot product is possible iff the two points have equal dimensions, otherwise the operator returns a 0 (i.e. NULL)
{
	long double sum = 0;
	
	if (this->get_dimension() == right.get_dimension())
	{
		for (long int i = 0; i < this->get_dimension(); i++)
			//sum = sum + this->point[i] * right.point[i]
			sum = sum + this->get_Coord(i) * right.get_Coord(i);
	}
	
	return sum;
}


//	N o n - M e m b e r   F u n c t i o n s

long double distance(aPoint left, aPoint right)
//	Usage: distance(P1, P2), where P1 and P2 are points.
//
//	Function:
//	The distance between the two points (x0, x1, x2, ..., xN-1) and (y0, y1, y2, ..., yN-1) is given by
//
//	sqrt((x0 - y0)^2 + (x1 - y1)^2 + (x2 - y2)^2 + ... + (xN-1 - yN-1)^2)
{
	long double sum = 0;
	
	if (left.get_dimension() == right.get_dimension())
	{
		for (long int i = 0; i < left.get_dimension(); i++)
			//sum = sum + (left.point[i] - right.point[i]) * (left.point[i] - right.point[i]);
			sum = sum + (left.get_Coord(i) - right.get_Coord(i)) * (left.get_Coord(i) - right.get_Coord(i));
	}
	
	return sqrt(sum);
}


aPoint operator * (double left, aPoint right)
//	Usage: k * P1 where P1 is a point and k a scalar.
//
//	Function:
//	Scalar Multiplication (on the left), k * (x0, x1, x2, ..., xN-1) is given by:
//
//	k * (x0, x1, x2, ..., xN-1) = (k*x0, k*x1, k*x2, ..., k*xN-1)
{
	aPoint P(right.get_dimension());
		
	for (long int i = 0; i < P.get_dimension(); i++)
		//P.point[i] = left * right.point[i];
		P.set_Coord(i, left * right.get_Coord(i));	
		
	return P;
}
#endif


//	The main program for testing the class, aPoint

int main()
{
	aPoint	P1, 	// Declares P1 as a point 0 on the real line
			P2(2),	// Declares P2 as a 2D point with values: (1, 2)
			P3(3);	// Declares P3 as a 2D point with values: (3, 0)
	
	std::cout << "The Values of the Points: P1, P2 and P3 are as follows:\n";
	std::cout << "P1 = " << (P1) << "\n";
	std::cout << "P2 = " << (P2) <<  "\n";
	std::cout << "P3 = " << (P3) << "\n";
	
	
	std::cout << "Enter New values of P1:\n";
	std::cin >> P1;
	std::cout << "Enter New values of P2:\n";
	std::cin >> P2;
	std::cout << "Enter New values of P3:\n";
	std::cin >> P3;
		
	std::cout << "The New Values of the Points: P1, P2 and P3 are as follows:\n";
	std::cout << "P1 = " << (P1) << "\n";
	std::cout << "P2 = " << (P2) << "\n";
	std::cout << "P3 = " << (P3) << "\n";
	
	P1 = P2;
	std::cout << "New P1 after P1 = P2:\n";
	std::cout << "P1 = " << (P1) << "\n";
	
	P1.set_all_Coord(P3.get_all_Coord(), P3.get_dimension());
	
	std::cout << "New P1 after set_all coord using P3:\n";
	std::cout << "P1 = " << (P1) << "\n";
	
	// Compute and display the distance between the two points: P1 and P2
	std::cout << "\nThe Distance between " << (P1) << " and " << (P2) << " = " << distance(P1, P2) << "\n";
	
	//	Compute and display the vector sum of the two points: P1 and P2 -- P1 + P2
	std::cout << P1 << " + " << P3 << " = " << (P1 + P3) << "\n";
	
	//	Compute and display the vector sum of the two points: P1 and P2 -- P1 + P2
	std::cout << P1 << " + " << P2 << " = " << (P1 + P2) << "\n";
	
	//	Compute and display the vector subtraction of the two points: P1 and P2 -- P1 + P2
	std::cout << P1 << " - " << P2 << " = " << (P1 - P2) << "\n";
	
	//	Compute and display the dot product of the two points: P1 and P2 -- P1 * P2
	std::cout << P1 << " * " << P2 << " = " << (P1 * P2) << "\n";
	
	//	Compute and display the scalar multiplaction of point P1 by the scalar 2 -- P1 * 2
	std::cout << P1 << " * " << 2 << " = " << (P1 * 2) << "\n";
	std::cout << 4 << " * " << P3 << " = " << (4.0 * P3) << "\n";
	
	if (P1 == P2)
		std::cout << P1 << " == " << P2 << "\n";
		
	if (P1 != P2)
		std::cout << P1 << " != " << P2 << "\n";
	
	return 1;
}


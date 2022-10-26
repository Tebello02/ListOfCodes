/*
	NAME: Class{a2D_Point__INHERITANCE_Tutorial}.cpp
	AUTHOR: mofana mphaka April 2021
	
	FUNCTION:
	
	The class shows how inheritance can be done in C++:
	A class, a2D_Point, is derived from class aPoint through public inheritance.
*/


//	Include the source code containing the parent class, aPoint
#include <Class{aPoint__NO_FRIENDS}.cpp>

#if !defined _A_2D_POINT_
#define _A_2D_POINT_

/**** C l a s s   D e c l a r a t i o n   &   C l a s s   I n t e r f a ce ****/

class a2D_Point : public aPoint
{
	//	It inherits the following private data from aPoint:
	
	//	(1) point: The x and y coordinates are located as follows:
	//		x cooordinate = point[0]
	//		y cooordinate = point[1]
	//	(2) dimension.
	//		This is, by default, 2
	
	public:
		//	Class Constructor -- it will use the constructor for aPoint
		a2D_Point(long double xCoord = 0, long double yCoord = 0);

		//	Class Destructor -- empty. C++ scoping rules shall apply
		~a2D_Point() { }


		//	M e m b e r   F u n c t i o n s
		
		//	Input functions -- polymorphic
		
		void set_xCoord(long double xCoord = 0);	//	set the x coordinate; default is 0
		void set_yCoord(long double yCoord = 0);	//	set the y coordinate; default is 0
		void set_xyCoord(long double xCoord = 0, long double yCoord = 0);	//	set both the x and y coordinates

		//	Output functions
		long double get_xCoord();	//	get the value of the x coordinate
		long double get_yCoord();	//	get the value of the x coordinate
		long double * get_xyCoord();	//	get the two coordinates at once
		
		//	All Overloaded Member Operators: 
		
		//	Relational operator: =, ==, !=
		//	Arithmetic Operators: +, - , *
		
		//	will be inherited from class aPoint

		/*	HOWEVER, the following Non-Member functions and/or Operators will not be "inherited"
			by class a2D_Point from class aPoint (since they are not member functions of class aPoint),
			but they are defined in the C++ source file, Class{aPoint__NO_FRIENDS}.cpp, containing class aPoint.
			
			Thus, they are visible in this scope. So, they can be used as they are.
		
				
			(1)	long double distance(a2D_Point left, a2D_Point right);		//	Euclidean distance between the two points: left & right
			(2)	a2D_Point operator * (long double left, a2D_Point right);	//	Scalar multiplication on the left: left * right
			(3)	std::istream & operator >> (std::istream & input, a2D_Point &right);	//	>> overloaded for input. USAGE: std::cin >> right
			(4)	std::ostream & operator << (std::ostream & output, a2D_Point right);	//	<<, overloaded for output. USAGE: std::cout << right
		*/
};


/**** C l a s s   I m p l e m e n t a t i o n ****/

a2D_Point :: a2D_Point(long double xCoord, long double yCoord) : aPoint(2)
//	It creates a 2D Point as a Point in 2D, aPoint(2). That is, 
//	it creates an array of points, point, of dimension 2
{
	//	C++ code here
}


void a2D_Point :: set_xCoord(long double xCoord)
{
	//	C++ code here
}


void a2D_Point :: set_yCoord(long double yCoord)
{
	//	C++ code here
}


void a2D_Point :: set_xyCoord(long double xCoord, long double yCoord)
{
	//	C++ code here
}


long double a2D_Point :: get_xCoord()
{
	//	C++ code here
}


long double a2D_Point :: get_yCoord()
{
	//	C++ code here
}


long double * a2D_Point :: get_xyCoord()
{
	//	C++ code here
}
#endif


//	The main program for testing the class, a2D_Point
/*
int main()
{	
	//	Declare P1, P2 and P3 as pointers to objects of a2D_Point class
	a2D_Point	* P1, 
				* P2,
				* P3;
	
	//	Now, instatiate the objects pointed to with chosen values
	
	P1 = new a2D_Point, 		// Initialise P1 as a 2D point with values: (0, 0)
	P2 = new a2D_Point(1,2);	// Initialise P2 as a 2D point with values: (1, 2)
	P3 = new a2D_Point(3);		// Initialise P3 as a 2D point with values: (3, 0)
	
	std::cout << "The Values of the Objects Pointed to: *P1, *P2 and *P3 are as follows:\n";
	std::cout << "*P1 = " << (*P1) << "\n";
	std::cout << "*P2 = " << (*P2) << "\n";
	std::cout << "*P3 = " << (*P3) << "\n";
	
	P1->set_xyCoord(3, 4);	//	Equally one can write: *P1.set_xyCoord(3, 4);
	
	std::cout << "\nThe Values of *P1 have been re-setted to:\n";
	std::cout << (*P1) << "\n";
	
	// Compute and display the distance between the two points: P1 and P2
	std::cout << "\nThe Distance between " << (*P1) << " and " << (*P2) << " = " << distance(*P1, *P2) << "\n";
	
	std::cout << "\nNow, Enter The New Values of *P1, *P2 and *P3:\n";
	std::cout << "\nNew Values of *P1:\n";
	std::cin >> (*P1);
	std::cout << "\nNew Values of *P2:\n";
	std::cin >> (*P2);
	std::cout << "\nNew Values of *P3:\n";
	std::cin >> (*P3);
	
	std::cout << "\nThe New Values of the Objects Pointed to: *P1, *P2 and *P3 are as follows:\n";
	std::cout << "*P1 = " << (*P1) << "\n";
	std::cout << "*P2 = " << (*P2) << "\n";
	std::cout << "*P3 = " << (*P3) << "\n";
	
	//	Compute and display the vector sum of the two points: P1 and P2 -- P1 + P2
	std::cout << (*P1) << " + " << (*P2) << " = " << (*P1 + *P2) << "\n";
	
	//	Compute and display the vector subtraction of the two points: P1 and P2 -- P1 + P2
	std::cout << (*P1) << " - " << (*P2) << " = " << ((*P1) - (*P2)) << "\n";
	
	//	Compute and display the dot product of the two points: P1 and P2 -- P1 * P2
	std::cout << (*P1) << " * " << (*P2) << " = " << ((*P1) * (*P2)) << "\n";
	
	//	Compute and display the scalar multiplaction of point P1 by the scalar 2 -- P1 * 2
	std::cout << (*P1) << " * " << 2 << " = " << ((*P1) * 2) << "\n";
	
	if ((*P1) == (*P2))
		std::cout << (*P1) << " == " << (*P2) << "\n";
		
	if ((*P1) != (*P2))
		std::cout << (*P1) << " != " << (*P2) << "\n";
	
	return 1;
}
*/

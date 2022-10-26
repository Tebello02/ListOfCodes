#include <iostream>
#include <cmath>

/*
	NAME: Class{a2D_Point}.cpp
	AUTHOR: mofana mphaka February 2021
	
	FUNCTION:
	
	This class is one of the lab exercise for CS2432 students of 2020/21 class.
	
	It teaches students on many aspects of class contruction:
	
	(1) Data Encapsulation/Hiding -- usage of "private" keyword
	(2) Class Constructors/Initialisers and destructors
	(3) Class member functions
	(4) Operator overloading: as member functions and as non-member functions -- usage of "friend" keyword
	(5) Conditional compilation -- usage of "#ifndef ..."
	(6) The definition and usage of the object self pointer "this"
	
	Constructing a class for a point in a 2-Dimensional space -- a 2-D Point.
*/

#if !defined _A_2D_POINT_
#define _A_2D_POINT_

/**** C l a s s   D e c l a r a t i o n   &   C l a s s   I n t e r f a ce ****/

class a2D_Point
{
	//	D a t a   E n c a p s u l a t i o n
	
	private:
		double	xCoord,
						yCoord;	//	A point in 2D has the x and y coordinates, as data 			elements

	public:
		
		//	C l a s s   C o n s t r u c t o r s   a n d   D e s t r u c t o r s
		
		//	Class Constructor -- polymorphic
		//	By default, the constructor creates the point (0, 0)
		a2D_Point(double _xCoord = 0, double _yCoord = 0);

		//	Class Desstructor -- empty. C++ scoping rules shall apply
		~a2D_Point() { }


		//	M e m b e r   F u n c t i o n s
		
		//	Input functions -- polymorphic
		
		void set_xCoord(double _xCoord = 0);	//	set the x coordinate; default is 0
		void set_yCoord(double _yCoord = 0);	//	set the y coordinate; default is 0
		void set_xyCoord(double _xCoord = 0, double _yCoord = 0);	//	set both the x and y coordinates
		
		void input();			//	input both the x and y coordinates
		

		//	Output functions
		double get_xCoord();	//	get the value of the x coordinate
		double get_yCoord();	//	get the value of the x coordinate
		double * get_xyCoord();	//	get the two coordinates at once
		
		double distance();		//	compute the Euclidean distance of this point from the origin
		
		//	Display functions
		void display();					//	print the point as: (xCoord, yCoord)
		
		//	Overloaded Operators as Member Functions
		
		a2D_Point operator = (a2D_Point right);		//	Assigns the point on the right to this point -- *this = right
		bool operator == (a2D_Point right);		//	compare this point with the point on the right -- *this == right?
		bool operator != (a2D_Point right);

		a2D_Point operator + (a2D_Point right);		//	Vector addition: add *this point to the point on the right -- *this + right
		double operator * (a2D_Point right);		//	Dot multiplication: *this * right
		a2D_Point operator * (double right);			//	Scalar multiplication: *this * right
				
	
	// F r i e n d   F u n c t i o n s  (i.e. N o n - M e m b e r   F u n c t i o n s)
	
	friend double distance(a2D_Point left, a2D_Point right);	//	Euclidean distance between the two points: left & right
		
	//	Overloaded Operators as Friend Functions
	
	friend a2D_Point operator * (double left, a2D_Point right);	//	Scalar multiplication: left * right
	
	
	//	The insertion operator, >>, overloaded for input. USAGE: std::cin >> point
	friend std::istream & operator >> (std::istream & input, a2D_Point &right);
	
	//	The extraction operator, <<, overloaded for output. USAGE: std::cout << point
	friend std::ostream & operator << (std::ostream & output, a2D_Point right);
};


a2D_Point :: a2D_Point(double _xCoord, double _yCoord)
{
	xCoord = _xCoord;
	yCoord = _yCoord;
}


/**** C l a s s   I m p l e m e n t a t i o n ****/

void a2D_Point :: set_xCoord(double _xCoord)
{
	xCoord = _xCoord;
}


void a2D_Point :: set_yCoord(double _yCoord)
{
	yCoord = _yCoord;
}


void a2D_Point :: set_xyCoord(double _xCoord, double _yCoord)
{
	xCoord = _xCoord;
	yCoord = _yCoord;
}


double a2D_Point :: get_xCoord()
{
	return xCoord;
}


double a2D_Point :: get_yCoord()
{
	return yCoord;
}


double * a2D_Point :: get_xyCoord()
{
	double * xyCoord = new double[2];
	
	xyCoord[0] = xCoord;
	xyCoord[1] = yCoord;
	
	return xyCoord;
}

		
double a2D_Point :: distance()
//	The distance of point (x, y) from the origin is given by
//
//	sqrt(x*x + y*y)
{
	return pow(xCoord * xCoord + yCoord * yCoord, 0.5);
}


void a2D_Point :: input()
{
	std::cout << "Enter new X coordinate ";
	std::cin >> xCoord;
	
	std::cout << "Enter new Y coordinate ";
	std::cin >> yCoord;
}


void a2D_Point :: display()
{
	std::cout << "(" << xCoord << ", " << yCoord << ")";
}


a2D_Point a2D_Point :: operator = (a2D_Point right)
{
	this -> xCoord = right.xCoord;
	this -> yCoord = right.yCoord;
	
	return (*this);
}


bool a2D_Point :: operator == (a2D_Point right)
{
	return (this -> xCoord == right.xCoord) && (this -> yCoord == right.yCoord);
}


bool a2D_Point :: operator != (a2D_Point right)
{
	return (this -> xCoord != right.xCoord) || (this -> yCoord != right.yCoord);
}


a2D_Point a2D_Point :: operator + (a2D_Point right)
{
	a2D_Point P;
	
	P.xCoord = this->xCoord + right.xCoord;
	P.yCoord = this->yCoord + right.yCoord;
	
	return P;
}


a2D_Point a2D_Point :: operator * (double right)
//	Multiplication of point (x, y) by a scalar k is given by
//
//	(x, y) * k = (k*x, k*y)
{
	a2D_Point P;
	
	P.xCoord = this->xCoord * right;
	P.yCoord = this->yCoord * right;
	
	return P;
}


double a2D_Point :: operator * (a2D_Point right)
//	The Dot product of two points: (x1, y1) and (x2, y2) is given by
//
//	x1*x2 + y1*y2
{
	return this->xCoord * right.xCoord + this->yCoord * right.yCoord;
}


//	N o n - M e m b e r   F u n c t i o n s

double distance(a2D_Point left, a2D_Point right)
//	The distance between the two points (x1, y1) and (x2, y2) is given by
//
//	sqrt((x1 - x2)^2 + (y1 - y2)^2)
{
	double	xDiff = left.xCoord - right.xCoord,
					yDiff = left.yCoord - right.yCoord;
			
	return pow(xDiff * xDiff + yDiff * yDiff, 0.5);
}


a2D_Point operator * (double left, a2D_Point right)
//	Scalar Multiplication (on the leftt), k (x, y) is given by:
//
//	k * (x, y) = (k * x, k * y)
{
	a2D_Point P;
	
	P.xCoord = left * right.xCoord;
	P.yCoord = left * right.yCoord;
	
	return P;
}


std::istream & operator >> (std::istream & input, a2D_Point &right)
{
	std::cout << "Enter new X coordinate ";
	input >> right.xCoord;
	
	std::cout << "Enter new Y coordinate ";
	input >> right.yCoord;
	
	return input;
}

std::ostream & operator << (std::ostream & output, a2D_Point right)
{
	output << "(" << right.xCoord << ", " << right.yCoord << ")";
	
	return output;
}
#endif

//	The main program for testing the class, a2D_Point

int main()
{
	a2D_Point	P1, 			// Declares P1 as a 2D point with values: (0, 0)
						P2(1,2),	// Declares P2 as a 2D point with values: (1, 2)
						P3(3);		// Declares P3 as a 2D point with values: (3, 0)
	
	//	Now, display the values of the three points on the screen, using the overloaded operator "<<"
	
	std::cout << "The Values of the declared points: P1, P2 and P3 are as follows:\n";
	std::cout << P1 << "\n";
	std::cout << P2 << "\n";
	std::cout << P3 << "\n";
	
	P1.set_xyCoord(3, 4);	//	Now, re-set the values of P1 to (3, 4)
	
	std::cout << "\nThe Values of P1 have been re-setted to:\n";
	std::cout << P1 << "\n";
	
	// Compute and display the distance between the two points: P1 and P2
	std::cout << "\nThe Distance between " << P1 << " and " << P2 << " = " << distance(P1, P2) << "\n";
	
	//	Compute and display the vector sum of the two points: P1 and P2 -- P1 + P2
	std::cout << P1 << " + " << P2 << " = " << (P1 + P2) << "\n";
	
	//	Compute and display the dot product of the two points: P1 and P2 -- P1 * P2
	std::cout << P1 << " * " << P2 << " = " << (P1 * P2) << "\n";
	
	//	Compute and display the scalar multiplaction of point P1 by the scalar 2 -- P1 * 2
	std::cout << P1 << " * " << 2 << " = " << (P1 * 2) << "\n";
	
	if (P1 == P2)
		std::cout << P1 << " == " << P2 << "\n";
		
	if (P1 != P2)
		std::cout << P1 << " != " << P2 << "\n";
	
	return 1;
}
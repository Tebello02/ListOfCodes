#include <iostream>
#include <cmath>

/*
	NAME: Class{aPoint}.cpp
	AUTHOR: mofana mphaka March 2021
	
	FUNCTION:
	
	This class is one of the lab exercise for CS2432 students of 2020/21 class. It generalises
	the class a2D_Point to a point in an N dimensional space, inclusive of the 1D space -- the real line.
	
	The class still teaches students many aspects of class contruction, including Exceptions and Exception Handling:
	
	(1) Data Encapsulation/Hiding -- usage of "private" keyword
	(2) Class Constructors/Initialisers and a class destructor
	(3) Class member functions
	(4) Operator overloading: as member functions and as non-member functions -- usage of "friend" keyword
	(5) Conditional compilation -- usage of "#ifndef ..."
	(6) The definition and usage of the object self pointer "this"
	(7) Exceptions and Exception Handling: Usage of the "try" and "catch" block
*/

#if !defined _A_POINT_
#define _A_POINT_

/**** C l a s s   D e c l a r a t i o n   &   C l a s s   I n t e r f a ce ****/

class aPoint
{
	private:
		long double	* point;	//	an array of points , default is 1 point -- a point on the real line
		long int dimension;	//	the number of coordinates, i.e. N dimensional space -- 1D is the real line

	public:		
		//	Class Constructor -- polymorphic
		//	By default, the constructor creates the point 0 on the real line, dimension = 1
		//	It will create the point (0, 0) if dimension = 2, etc
		aPoint(long int _dimension = 1);

		//	Class Destructor -- empty. C++ scoping rules shall apply
		~aPoint() { }


		//	M e m b e r   F u n c t i o n s
		
		//	Input functions -- polymorphic
		
		void set_Coord(long int i = 0, long double value = 0);	//	set the i-th coordinate with the given value
		void set_all_Coord(long double * value, long int _dimension = 1);	//	set all the coordinates at once, with values
		
		void input();			//	input all the coordinates
		

		//	Output functions
		long double get_Coord(long int i = 0);	//	get the value of the i-th coordinate
		long double * get_all_Coord();	//	get all the coordinate values in a list
		
		long int get_length();		//	get the dimension of the point -- i.e. number of coordinates in the point
		long int get_size();		//	same as get_length() -- OOP redundancy
		long int get_dimension();	//	same as get_length(), get_size()
		
		long double distance();		//	compute the Euclidean distance of this point from the origin
		
		//	Display functions
		void display();					//	print the point as: x0, (x0, x1), (x0, x1, x2), etc 
		
		//	Overloaded Operators as Member Functions
		
		aPoint operator = (aPoint right);		//	Assigns the point on the right to this point -- *this = right
		bool operator == (aPoint right);		//	compare this point with the point on the right -- *this == right?
		bool operator != (aPoint right);

		aPoint operator + (aPoint right);		//	Vector addition: add *this point to the point on the right -- *this + right
		aPoint operator - (aPoint right);		//	subtract the point on the right from *this point -- *this - right
		long double operator * (aPoint right);		//	Dot multiplication: *this * right
		aPoint operator * (long double right);			//	Scalar multiplication: *this * right
				
	
	// F r i e n d   F u n c t i o n s  (i.e. N o n - M e m b e r   F u n c t i o n s)
	
	friend long double distance(aPoint left, aPoint right);	//	Euclidean distance between the two points: left & right
		
	//	Overloaded Operators as Friend Functions
	
	friend aPoint operator * (long double left, aPoint right);	//	Scalar multiplication: left * right
	
	
	//	The insertion operator, >>, overloaded for input. USAGE: std::cin >> point
	friend std::istream & operator >> (std::istream & input, aPoint &right);
	
	//	The extraction operator, <<, overloaded for output. USAGE: std::cout << point
	friend std::ostream & operator << (std::ostream & output, aPoint right);
};



/**** C l a s s   I m p l e m e n t a t i o n ****/

aPoint :: aPoint(long int _dimension)
//	It creates aPoint in the space given by _dimension, withh all the coordinates set to 0.
//	For example, if _dimension = 1 (which is the default), the point 0 is created on the real line
//	If _dimension = 2, then the point (0, 0) is created on the XY Plane (i.e. 2D space)
//	If _dimension = 3, then the point (0, 0, 0) is created in 3D space, etc
{
	if (_dimension < 1)
		_dimension = 1;	//	the least dimension is the real line -- 1D space
		
	dimension = _dimension;
	
	try
	{
		point = new long double[dimension];		//	the "new" operator might throw an exception, if no more memory available
		
		for(_dimension = 0; _dimension < dimension; _dimension++)
			point[_dimension] = 0;		//	the point is initially 0, (0, 0), (0, 0, 0), etc
	}
	catch(...)	//	catch any possible exceptions from the "try" block above
	{
		std::cout << "Memory Overflow -- Cannot Create the Points Array!";
		exit(0);	//	terminate the "main" function that called this class
	}
}


void aPoint :: set_Coord(long int i, long double value)
//	The i-th coordinate, point[i] is assigned the value, "value".
//	i.e. point[i] = value. NB: 0 <= i < dimension
//	NB:
//	The function makes sure that the index, i, is within the point's dimension: 0 <= i < dimension
{
	// C++ Code here
}


void aPoint :: set_all_Coord(long double * value, long int _dimension)
//	Given a list of values, * value, and their dimension, _dimension,
//	set_all_Coord(...) will set all the coordinates of the point the corresponding values.
{
	if (_dimension > dimension)
		_dimension = dimension;	//	Clip the given value to the actual point's dimension
		
	if (_dimension < 1)
		_dimension = 1;
		
	while(_dimension > 0)
	{
		point[_dimension-1] = value[_dimension-1];	//	Set each corresponding coordinate with the corresponding value
		_dimension--;
	}
		
}


long double aPoint :: get_Coord(long int i)
//	get the i-th coordinate of the point. That is, return point[i]
//	NB: 0 <= i < dimension. That is, the function Makes sure that the index, i, is within the point's dimension
{
	// C++ code here
}


long double * aPoint :: get_all_Coord()
//	Get all the coordinates of the point in a list
{
	long double * Coord = new long double[dimension];	//	The coordinates will be collected in Coord
	
	for(long int i = 0; i < dimension; i++)		//	copy each coordinate, point[i] into the
		Coord[i] = point[i];					//	corresponding Coord[i]
		
	return Coord;
}


long int aPoint :: get_length()
{
	return dimension;
}


long int aPoint :: get_size()
{
	return dimension;
}


long int aPoint :: get_dimension()
{
	return dimension;
}

		
long double aPoint :: distance()
//	The distance of point (x0, x1, x2, ..., xN-1) from the origin is given by
//
//	sqrt(x0*x0 + x1*x1 + x2*x2 + ... + (xN-1)*(xN-1))
{
	// C++ code here
}


void aPoint :: input()
{
	if (dimension < 2)
	{
		std::cout << "Enter a point on the real line ";
		std::cin >> point[0];
	}
	else
	{
		for (long int i = 0; i < dimension; i++)
		{
			std::cout << "Enter the " << (i+1);
			
			switch((i+1) % 10)
			{
				case 1: if ((i+1) != 11)
							std::cout << "st "; 
						break;
						
				case 2: if ((i+1) != 12)
							std::cout << "nd "; 
						break;
						
				case 3: if ((i+1) != 13)
							std::cout << "rd "; 
						break;
						
				default: std::cout << "th ";
			}
			
			std::cout << "coordinate ";
			
			std::cin >> point[i];
		}
	}
}


void aPoint :: display()
//	It displays a point as:
//	x0 -- if the point is on the real line, i.e. dimesion = 1
//	(x0, x1) -- if the point is in 2D space, i.e. dimesion = 2
//	(x0, x1, x2) -- if the point is in 3D space, i.e. dimesion = 3, etc
{
	if (dimension < 2)
		std::cout << point[0];	//	A point on the real line -- just display it
	else	//	More than one coordinate? A 2D, 3D , ..., point, display it as: (x0, x1, x2, ..., xN-1)
	{
		std::cout << "(";
	
		for (long int i = 0; i < dimension; i++)
		{
			std::cout << point[i];
		
			if (i < (dimension-1))
				std::cout << ", ";	//	separate coordinates with commas
		}
		std::cout <<  ")";
	}
}


aPoint aPoint :: operator = (aPoint right)
//	Usage: P1 = P2, where P1 and P2 are points.
//	Function: P1 is assigned the values of P2: dimension and all the coordinates.
{
	//	re-create this point with the size of the point on the right
	this->point = new long double[right.dimension];	
	this->dimension = right.dimension;
	
	//	Now, copy elementwise, the contents of the point on the right to this point (on the left)
	for (long int i = 0; i < this->dimension; i++)
		this->point[i] = right.point[i];
	
	return (*this);
}


bool aPoint :: operator == (aPoint right)
//	Usage: P1 == P2 where P1 and P2 are points.
//	Function: The operator returns TRUE (1) iff P1 == P2, FALSE (0) otherwise
//	NB:
//	Two points, P1, P2 are equal iff
//	1.	They have equal dimensions AND
//	2.	they have equal (i.e. identical) corresponding elements
{
	//	C++ code here
}


bool aPoint :: operator != (aPoint right)
//	Usage: P1 != P2 where P1 and P2 are points.
//	Function: The operator returns TRUE (1) iff P1 != P2, FALSE (0) otherwise
{
	return !(*this == right);
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
	aPoint P(this->dimension);	//	Initially, create the point (0, 0, 0, ..., 0), the size of the point on the left
	
	if (this->dimension == right.dimension)
	{
		for (long int i = 0; i < this->dimension; i++)
			P.point[i] = this->point[i] + right.point[i];
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
	aPoint P(this->dimension);
	
	if (this->dimension == right.dimension)
	{	
		for (long int i = 0; i < this->dimension; i++)
			P.point[i] = this->point[i] - right.point[i];
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
	aPoint P(this->dimension);
	
	for (long int i = 0; i < this->dimension; i++)
		P.point[i] = this->point[i] * right;
	
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
	//	C++ code here
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
	
	if (left.dimension == right.dimension)
	{
		for (long int i = 0; i < left.dimension; i++)
			sum = sum + (left.point[i] - right.point[i]) * (left.point[i] - right.point[i]);
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
		P.set_Coord(i, left * right.get_Coord(i));	//P.point[i] = left * right.point[i];
		
	return P;
}


std::istream & operator >> (std::istream & input, aPoint &right)
//	Usage: cin >> P where P is a point.
//
//	Function:
//	Component values of P are read from the keysboard.
{
	//	C++ code here
}

std::ostream & operator << (std::ostream & output, aPoint right)
//	Usage: cout << P where P is a point.
//
//	Function:
//	P is displayed on the screen as follows:
//	x0, if P is a point on the real line
//	(x0, x1), if P is a point in 2D space
//	(x0, x1, x3), if P is a point in 3D space, etc
{
	//	C++ code here
}
#endif


/*
//	The main program for testing the class, aPoint

int main()
{
	aPoint	P1, 	// Declares P1 as a point 0 on the real line
			P2(2),	// Declares P2 as a 2D point with values: (1, 2)
			P3(3);	// Declares P3 as a 2D point with values: (3, 0)
	
	std::cout << "The Values of the Points: P1, P2 and P3 are as follows:\n";
	std::cout << "P1 = " << (P1) << "\n";
	std::cout << "P2 = " << (P2) << "\n";
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
	
	P1.set_all_Coord(P3.get_all_Coord(), P3.get_size());
	
	std::cout << "New P1 after set_all corrd using P3:\n";
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
*/

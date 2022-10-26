/*
	FILE NAME: INTERFACE__class{a4SidedRegularPolygon}.cpp
	
	STUDENT ANSWER FILE NAME:	Lipholo__N__202000868__class{a4SidedRegularPolygon}.cpp
	
	
	STUDENT PARTICULARS: Lipholo  N  202000868
	E-MAIL ADDRESS: nelipholo@gmail.com
	
	QUESTIONS ASKED:
					Question 
					Question
					Question 
					Question

	QUESTIONS ANSWERED:
					Question 
					Question
					Question 
					Question
*/

#include <iostream>

/*
	a4SidedRegularPolygon:
	1.	a rectangle
	2.	a square
	
	a4SidedRegularPolygon has
		(a) Static (i.e. data) attributes
			1.	length
			2.	breadth
			
		(b) Behavioural (i.e. functional) attributes
			1.	perimeter
			2.	area
			*3.	compare: >, <, ..., e.g. A >= B?
			*4. assign: =. E.g A = B
*/

#if ! defined _A_4_SIDED_REGULAR_POLYGON_
#define _A_4_SIDED_REGULAR_POLYGON_

/*
	First, define a generic function, swap, to swap any two objects:
	
	swap(x, y) = (y, x)
*/
template <class T>
void swap(T & obj1, T & obj2)
{
	T TempObj = obj1;
	obj1 = obj2;
	obj2 = TempObj;
}


/*
	Now define an object class for a 4 sided, regular polygon:
	
	class a4SidedRegularPolygon ...
*/
class a4SidedRegularPolygon
{
	private:
		long double	length, breadth;
		
	public:
		~a4SidedRegularPolygon() {}
		a4SidedRegularPolygon (long double aLength = 1,long double aBreadth = 1);
		
		long double perimeter();	//	Perimeter of the created polygon
		long double area();	//	Area of the created polygon
		const char * name();	//	The Polygon name is "rectangle" or "square"
		
		void display();	//	Display the polygon
		void input();	//	Input the polygon's data: length & breadth
		
		long double getLength();	// Avail the polygon's length to a calling environment
		long double getBreadth();
		
		void setLength(long double aLength = 1);	//	Set the polygon's length to aLength
		void setBreadth(long double aBreadth = 1);
		
		// Overloaded Operators
		
		//	The Assignment Operator: =
		a4SidedRegularPolygon operator = (a4SidedRegularPolygon right);
		
		//	The Relational Operators: ==, >, <, <=, >=, !=
		bool operator == (a4SidedRegularPolygon right);
		bool operator > (a4SidedRegularPolygon right);
		bool operator < (a4SidedRegularPolygon right);
		bool operator <= (a4SidedRegularPolygon right);
		bool operator >= (a4SidedRegularPolygon right);
		bool operator != (a4SidedRegularPolygon right);
		
	//	Non-Member, Friend Functions/ Operators
	friend std::istream & operator >> (std::istream & input, a4SidedRegularPolygon & right);
	friend std::ostream & operator << (std::ostream & output, a4SidedRegularPolygon right);
};


// Question: 01
a4SidedRegularPolygon :: a4SidedRegularPolygon (long double aLength, long double aBreadth)
//	The length and breadth of a polygon are always positive
//	The length of a polygon is the longer side between: length and breadth
{	
	// C++ Code here
	if (aLength > 0)
	{
		length = aLength;
	}
	else
	{
		length = 1;
	}

	if (aBreadth > 0)
	{
		breadth = aBreadth;
	}
	else
	{
		breadth = 1;
	}

	if (length < breadth)
	{
		swap (aLength, aBreadth);
	}
}


// Question: 02
void a4SidedRegularPolygon :: setLength(long double aLength)
//	The length and breadth of a polygon are always positive
//	The length of a polygon is the longer side between: length and breadth
{
	// C++ Code here
	if (aLength > 0)
	{
		length = aLength;
	}
	else
	{
		length = 1;
	}
}


// Question: 03
void a4SidedRegularPolygon :: setBreadth(long double aBreadth)
//	The length and breadth of a polygon are always positive
//	The length of a polygon is the longer side between: length and breadth
{
	// C++ Code here
	if (aBreadth > 0)
	{
		breadth = aBreadth;
	}
	else
	{
		breadth = 1;
	}
}


long double a4SidedRegularPolygon :: perimeter()
{
	return 2 * (length + breadth);
}


long double a4SidedRegularPolygon :: area()
{
	return (length * breadth);
}

long double a4SidedRegularPolygon :: getLength()
{
	return length;
}

long double a4SidedRegularPolygon :: getBreadth()
{
	return breadth;
}


// Question: 04
void a4SidedRegularPolygon :: display()
/*	Displays the polygon as:

	Length:		length value
	Breadth:	breadth value
	Perimeter:	perimeter value
	Area:		area value
	Name:		name value (i.e. Square or Rectangle)
*/
{
	// C++ Code here
	a4SidedRegularPolygon data;

	if (length < breadth)
	{
		swap (data.length, data.breadth);
	}

	std::cout << "Length: " << length << "\n";
	std::cout << "Breadth: " << breadth << "\n";
	std::cout << "Perimeter: " << perimeter() << "\n";
	std::cout << "Area: " << area() << "\n\n";
  std::cout << "Name: " << name() << "\n\n";
}


// Question: 05
void a4SidedRegularPolygon :: input()
//	Allows user to enter both the breadth and the length of the polygon, interactively.
//	The length and breadth of a polygon are always positive
//	The length of a polygon is the longer side between: length and breadth
{
	// C++ Code here
  long double aLength,
              aBreadth;
  std::cout << "Please enter Length: "; std::cin >> aLength;
  std::cout << "Please enter Breath: "; std::cin >> aBreadth;

	if (aLength < aBreadth)
	{
		swap (aLength, aBreadth);
	}

  if (aLength > 0)
	{
		length = aLength;
	}
	else
	{
		length = 1;
	}

	if (aBreadth > 0)
	{
		breadth = aBreadth;
	}
	else
	{
		breadth = 1;
	}
}


// Question: 06
const char * a4SidedRegularPolygon :: name()
//	Returns the name as either RECTANGLE or SQUARE
//	N.B A Square has all the sides equal.
{
	// C++ Code here
  const char *aName;

  if (length == breadth)
  {
    aName = "Square";
  }
  else
  {
    aName = "Rectangle";
  }
  return (aName);
}


a4SidedRegularPolygon a4SidedRegularPolygon :: operator = (a4SidedRegularPolygon right)
{
	this -> length = right.length;
	this -> breadth = right.breadth;
	
	return (*this);
}


// Question: 07
bool a4SidedRegularPolygon :: operator == (a4SidedRegularPolygon right)
//	A regular polygon A (on the left) == a regular polgon B (on the right) iff
//	the area of A == the area of B
{
	// C++ Code here
  return (this ->area() == right.area());
}


// Question: 08
bool a4SidedRegularPolygon :: operator > (a4SidedRegularPolygon right)
{
	// C++ Code here
  return (this->area() > right.area());
}


// Question: 09
bool a4SidedRegularPolygon :: operator < (a4SidedRegularPolygon right)
{
	// C++ Code here
  return (this->area() < right.area());
}


// Question: 10
bool a4SidedRegularPolygon :: operator <= (a4SidedRegularPolygon right)
{
	// C++ Code here
  return (this->area() <= right.area());
}


// Question: 11
bool a4SidedRegularPolygon :: operator >= (a4SidedRegularPolygon right)
{
	// C++ Code here
  return (this->area() >= right.area());
}


// Question: 12
bool a4SidedRegularPolygon :: operator != (a4SidedRegularPolygon right)
{
	// C++ Code here
  return (this->area() != right.area());
}


// Question: 13
std::istream & operator >> (std::istream & input, a4SidedRegularPolygon & right)
//	same as input member function
{
	// C++ Code here
  long double aLength,
              aBreadth;
  std::cout << "Please enter Length: "; input >> aLength;
  std::cout << "Please enter Breath: "; input >> aBreadth;

  if (aLength > 0)
	{
		right.length = aLength;
	}
	else
	{
		right.length = 1;
	}

	if (aBreadth > 0)
	{
		right.breadth = aBreadth;
	}
	else
	{
		right.breadth = 1;
	}

	if (right.length < right.breadth)
	{
		swap (right.length, right.breadth);
	}
  return (input);
}

std::ostream & operator << (std::ostream & output, a4SidedRegularPolygon right)
//	same as display memeber function
{
	// C++ Code here
	if (right.length < right.breadth)
	{
		swap (right.length, right.breadth);
	}

  output << "Length: " << right.length << "\n";
	output << "Breadth: " << right.breadth << "\n";
	output << "Perimeter: " << right.perimeter() << "\n";
  output << "Area: " << right.area() << "\n\n";
  output << "Name: " << right.name() << "\n\n";
  return (output);
}
#endif

int main()
{
	a4SidedRegularPolygon F1, F3, F2(2,4);
	
	std::cout << "F1:\n\n" << F1;
	std::cout << "F2:\n\n" << F2;
	
	std::cout << "Enter New Data for F1:\n";
	std::cin >> F1;
	
	std::cout << "Enter New Data for F2:\n";
	std::cin >> F2;
	
	std::cout << "F1:\n\n" << F1;
	std::cout << "F2:\n\n" << F2;
	
	F3 = F2; F3.display();

	if (F1 != F2)
	{
		std::cout << "F1" << " != " << "F2" << "\n";
	}

	if (F2 >= F1)
	{
		std::cout << "F2" << " >= " << "F1" << "\n";
	}
	
	if (F1 <= F2)
	{
		std::cout << "F1" << " <= " << "F2" << "\n";
	}

	if (F2 > F1)
	{
		std::cout << "F2" << " > " << "F1" << "\n";
	}

	if (F1 < F2)
	{
		std::cout << "F1" << " < " << "F2" << "\n";
	}

	if (F2 == F3)
	{
		std::cout << "F2" << " == " << "F3" << "\n\n";
	}

	std::cout << "F3 Data: " << "\n";
	F3.display();
	return 1;
}
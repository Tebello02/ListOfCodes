#include <iostream>

/*
	NAME: Class{ACircle}.cpp
	AUTHOR: mofana mphaka January 2010
	
	FUNCTION:
	
	This class is the first lab exercise for CS2432 students of 2019/20 class.
	
	It teaches students on many aspects of class contruction:
	
	(1) Data Encapsulation/Hiding -- usage of "private" keyword
	(2) Class Constructors/Initialisers and destructors
	(3) Class member functions
	(4) Operator overloading: as member functions and as non-member functions -- usage of "friend" keyword
	(5) Conditional compilation -- usage of "#ifndef ..."
	(6) The definition and usage of the object self pointer "this"
*/

#if !defined _A_CIRCLE_
#define _A_CIRCLE_

class aCircle
{
	private:
		double radius;	//	radius is the only data element to a circle

	public:
		
		//	Class Constructors and Destructors
		
		//	Class Constructor -- polymorphic
		//	By default, the constructor creates a unit circle, i.e. _radius = 1
		aCircle(double _radius = 1);

		//	Class Desstructor -- empty. C++ scoping rules shall apply
		~aCircle() { }

		//	Member Functions
		
		//	Input functions
		void set(double length = 1);	//	set the radius length; default is the unit circle
		void input();					//	input radius
		double get();					//	get the value of radius

		//	Output functions
		double area();					//	Method to compute the area of the circle
		double circumference();         //Method to compute the circumference of a circle
		
		double diameter();

		//	Display functions
		void print();					//	print the circle's data: radius, area etc
		
		//	Overloaded Operators as Member Functions
		
		aCircle operator = (aCircle right);		//	Assigns the circle on the right to this circle -- *this = right
		bool operator == (aCircle right);		//	compare this circle with the circle on the right -- *this == right?
		bool operator >= (aCircle right);		//	*this >= right?
		bool operator > (aCircle right);		//	*this > right?
		bool operator < (aCircle right);		//	*this < right?
		bool operator <= (aCircle right);		//	*this <= right?
		
		
	//	Overloaded Operators as Friends -- Non-Member Functions
	
	friend std::istream & operator >> (std::istream & input, aCircle &right);
	friend std::ostream & operator << (std::ostream & output, aCircle right);
};


aCircle :: aCircle(double _radius)   //??a constructor
{
	radius = (_radius >= 1) ? _radius : 1;  //??if radius is less than <0....radius=1;
}


void aCircle :: set(double length)
{
	radius = (length >= 1) ? length : 1;
}


void aCircle :: input()
{
	do
	{
		std::cout << "Enter new Radius value ";
		std::cin >> radius;

		if (radius <= 0)
			std::cout << "Entered value is invalid -- Re-Enter\n";
	}
	while (radius <= 0);	// The radius cannot be 0 or less
}


double aCircle :: get()
{
	return radius;
}


double aCircle :: area()
{
	return 3.1415 * radius * radius;
}


double aCircle :: circumference()
{
	return 2 * 3.1415 * radius;
}


double aCircle :: diameter()
{
	return 2 * radius;
}


void aCircle :: print()
{
	std::cout << "CIRCLE:\n"
			  << "Radius:  " << get() << "\n"
		      << "Diameter:  " << diameter() << "\n"
			  << "Circumference:  " << circumference() << "\n"
			  << "Area:  " << area() << "\n";
}

//overloaded operators//
aCircle aCircle :: operator = (aCircle right)
{
	this -> radius = right.radius;
	return (*this);
}


bool aCircle :: operator == (aCircle right)
{
	return this -> radius == right.radius;
}


bool aCircle :: operator >= (aCircle right)
{
	return this -> radius >= right.radius;
}


bool aCircle :: operator > (aCircle right)
{
	return this -> radius > right.radius;
}


bool aCircle :: operator < (aCircle right)
{
	return this -> radius < right.radius;
}


bool aCircle :: operator <= (aCircle right)
{
	return this -> radius <= right.radius;
}
		

std::istream & operator >> (std::istream & input, aCircle &right)
{
	do
	{
		std::cout << "Enter new Radius value ";
		input >> right.radius;

		if (right.radius <= 0)
			std::cout << "Entered value is invalid -- Re-Enter\n";
	}
	while (right.radius <= 0);

	return input;
}

std::ostream & operator << (std::ostream & output, aCircle right)
{
	output	<< "CIRCLE:\n"
			<< "Radius:  " << right.get() << "\n"
		    << "Diameter:  " << right.diameter() << "\n"
			<< "Circumference:  " << right.circumference() << "\n"
			<< "Area:  " << right.area() << "\n";
	return output;
}
#endif


int main()
{
	aCircle circle1 = 4,	//	construct a circle, circle1, with a radius of 4 units
			circle2(2);		//	construct a circle, circle2, with a radius of 2 units

	std::cout << circle1 << "\n";
	std::cout << circle2 << "\n";
	
	std::cout << "circle1 == circle2  " << (circle1 == circle2)<< "\n";
	std::cout << "circle1 >= circle2  " << (circle1 >= circle2)<< "\n";
	std::cout << "circle1 > circle2  " << (circle1 > circle2)<< "\n";
	std::cout << "circle1 < circle2  " << (circle1 < circle2)<< "\n";
	std::cout << "circle1 <= circle2  " << (circle1 <= circle2)<< "\n";
	
	//	Enter new circle values
	std::cout << "\nEnter data for >> circle1 <<\n";
	circle1.input();	//	Use the member function: input
	
	std::cout << "\nEnter data for >> circle2 <<\n";
	std::cin >> circle2;	//	Use the overloaded operator: >> for input
	
	//	Now display the circles
	std::cout << "Data for >> circle1 <<\n";
	std::cout << circle1 << "\n";	//	Use the overloaded operator: << for output
	
	std::cout << "Data for >> circle2 <<\n";
	circle2.print();	//	Use the member function: print
	if (circle1.area()>circle2.area())
		std::cout<<"CIRCLE1 AREA IS LARGER THEREFORE,ITS BIGGER THAN CIRCLE2"<<std::endl;
		
	if(circle1.area()<circle2.area())
		std::cout<<"CIRCLE2 AREA IS LARGER THEREFORE,ITS BIGGER THAN CIRCLE1 "<<std::endl;
		
	if(circle1.area() == circle2.area())
		std::cout<<"THE TWO CIRCLES ARE EQUAL"<<std::endl;
	
	return 1;
}

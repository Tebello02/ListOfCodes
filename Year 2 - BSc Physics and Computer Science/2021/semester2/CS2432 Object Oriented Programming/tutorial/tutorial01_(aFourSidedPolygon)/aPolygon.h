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

#if !defined _A_4_SIDED_REGULAR_POLYGON_
#define _A_4_SIDED_REGULAR_POLYGON_

class a4SidedRegularPolygon
{
	private:
		long double	length, breadth;
		
	public:
		a4SidedRegularPolygon (long double aLength = 1,long double aBreadth = 1);
		~a4SidedRegularPolygon() {}
		
		
		long double perimeter();
		long double area();
		
		void display();
		
		// operators
		
		a4SidedRegularPolygon operator = (a4SidedRegularPolygon right);
		bool operator == (a4SidedRegularPolygon right);
};

a4SidedRegularPolygon :: a4SidedRegularPolygon (long double aLength, long double aBreadth)
{
	if (aLength > 0)
		length = aLength;
	else
		length = 1;
	
	if (aBreadth > 0)
		breadth = aBreadth;
	else
		breadth = 1;
	
	if (breadth > length)
	{
		long double temp = breadth;
		breadth = length;
		length = temp;
	}
}

long double a4SidedRegularPolygon :: perimeter()
{
	return 2 * (length + breadth);
}

long double a4SidedRegularPolygon :: area()
{
	return length * breadth;
}

void a4SidedRegularPolygon :: display()
{
	std::cout << "Length: " << length << "\n";
	std::cout << "Breadth: " << breadth << "\n";
	std::cout << "Perimeter: " << perimeter() << "\n";
	std::cout << "Area: " << area() << "\n\n";
}
#endif

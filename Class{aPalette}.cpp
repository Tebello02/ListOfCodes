/*
	FILE NAME: Class{aPalette}.cpp
	
	FUNCTION:
	
	The program shows how a class hierarchy of "friends" can be built.
	
	The example is that of a colour palette which requires a point. So, class aPalette
	declares class aPoint as a "friend".
	
	(C) Mofana Mphaka; February 2021
*/

#include <iostream>

#if !defined _a_COLOUR_PALETTE_
#define _a_COLOUR_PALETTE_

class aPalette
{
	friend class aPoint;
	
	friend std::istream & operator >> (std::istream & input, aPalette & right);
	friend std::ostream & operator << (std::ostream & output, aPalette right);

	private:
		//	A palette has three base colours: Red, Green and Blue
		//	Any colour can be produced by mixing the different intensities
		//	of each colour component. A colour intensity is an integer: 0..255
		int	red,
			green,
			blue;

	public:
		//	Construct a palette with intensity: _red, _green, _blue. 
		//	Default is black: Red = Green = Blue = 0
		aPalette(int _red = 0, int _green = 0, int _blue = 0);
		
		~aPalette() {}

		void set(int _red = 0, int _green = 0, int _blue = 0);
		//	Set the palette to some specified colour of different shades of
		//	Red, Green and Blue. Default is black: Red = Green = Blue = 0

		void input();
		//	Inputs the Red, Green, Blue colour intensities
		
		void display();
		//	Displays the colour intensities of the pallete as: Red(red) Gree(gree) Blue(blue)
};


aPalette :: aPalette(int _red, int _green, int _blue)
{
	red = (((_red >= 0) && (_red <= 255))? _red : 0);
	green = (((_green >= 0) && (_green <= 255))? _green : 0);
	blue = (((_blue >= 0) && (_blue <= 255))? _blue : 0);
}


void aPalette :: set(int _red, int _green, int _blue)
{
	red = (((_red >= 0) && (_red <= 255))? _red : 0);
	green = (((_green >= 0) && (_green <= 255))? _green : 0);
	blue = (((_blue >= 0) && (_blue <= 255))? _blue : 0);
}


void aPalette :: input()
{
	do
	{
		std:: cout << "Enter Colour RED Intensity [0 .. 255] "; std::cin >> red;
	}
	while ((red < 0) || (red > 255));
	
	do
	{
		std:: cout << "Enter Colour GREEN Intensity [0 .. 255] "; std::cin >> green;
	}
	while ((green < 0) || (green > 255));
	
	do
	{
		std:: cout << "Enter Colour BLUE Intensity [0 .. 255] "; std::cin >> blue;
	}
	while ((blue < 0) || (blue > 255));
}


void aPalette :: display()
{
	std::cout	<< "Red(" << red << ") "
				<< "Green(" << green << ") "
				<< "Blue(" << blue << ")";
}

std::istream & operator >> (std::istream & input, aPalette & right)
{
	do
	{
		std:: cout << "Enter Colour RED Intensity [0 .. 255] "; input >> right.red;
	}
	while ((right.red < 0) || (right.red > 255));
	
	do
	{
		std:: cout << "Enter Colour GREEN Intensity [0 .. 255] "; input >> right.green;
	}
	while ((right.green < 0) || (right.green > 255));
	
	do
	{
		std:: cout << "Enter Colour BLUE Intensity [0 .. 255] "; input >> right.blue;
	}
	while ((right.blue < 0) || (right.blue > 255));
	
	return input;
}


std::ostream & operator << (std::ostream & output, aPalette right)
{
	output	<< "Red(" << right.red << ") "
			<< "Green(" << right.green << ") "
			<< "Blue(" << right.blue << ")";
	
	return output;
}

	
class aPoint
{
	friend std::istream & operator >> (std::istream & input, aPoint & right);
	friend std::ostream & operator << (std::ostream & output, aPoint right);
	
	private:
		//	a Point in 2D has X Y coordinates
		double	xCoord,
				yCoord;

		//	a Point also has colour, which is a pallete
		aPalette	colour;

	public:
		//	Construct a point in 2D as (x, y); default is (0, 0)
		aPoint(double _xCoord = 0, double _yCoord = 0) : xCoord(_xCoord), yCoord(_yCoord) {}

		~aPoint() {}
		
		void set(double _xCoord = 0, double _yCoord = 0);
		//	Set the point to the specified coordinates: (x, y); Default is (0, 0)
		
		void setColour(int _red = 0, int _green = 0, int _blue = 0);
		//	Set the point colour to some specified colour: Red, Green, Blue; Default is black: (0, 0, 0).

		void display();
		//	Display the point colour as: Point: (x, Y)  Colour: Red(R) Green(G) Blue(B)
		
		void input();
		//	Input a point and its colour
};


void aPoint :: set(double _xCoord, double _yCoord)
{
	xCoord = _xCoord;
	yCoord = _yCoord;
}


void aPoint :: setColour(int _red, int _green, int _blue)
{
	colour.set(_red, _green, _blue);
}


void aPoint :: input()
{
	std::cout << "Enter the X coordinate "; std::cin >> xCoord;
	std::cout << "Enter the Y coordinate "; std::cin >> yCoord;
	
	std::cout << "Enter the colour for the point (" << xCoord << ", " << yCoord << ") below\n";
	colour.input();
}


void aPoint :: display()
{
	std::cout << "Point: (" << xCoord << ", " << yCoord << ") Colour: ";
	colour.display();
}


std::istream & operator >> (std::istream & input, aPoint & right)
{
	std::cout << "Enter the X coordinate "; input >> right.xCoord;
	std::cout << "Enter the Y coordinate "; input >> right.yCoord;
	
	std::cout << "Enter the colour for the point (" << right.xCoord << ", " << right.yCoord << ") below\n";
	input >> right.colour;
	
	return input;
}


std::ostream & operator << (std::ostream & output, aPoint right)
{
	output << "Point: (" << right.xCoord << ", " << right.yCoord << ") Colour: ";
	output << right.colour;
	
	return output;
}
#endif

/*
int main()
{
	aPoint P;
	
	std::cout << P << "\n";
	std::cin >> P;
	std::cout << P << "\n";
	
	return 1;
}
*/
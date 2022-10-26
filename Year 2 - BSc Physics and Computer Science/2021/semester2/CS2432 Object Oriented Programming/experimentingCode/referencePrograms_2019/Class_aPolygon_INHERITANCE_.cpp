/*
	FILE NAME: Class{aPolygon_INHERITANCE}.cpp
	FUNCTION:
		Class aPolygon is an abstract class designed as a base class for the derivation of other
		polygon classes such as: a triangle, class aTriangle, a circle, class aCircle and 
		a quadrilateral, class aQuadrilateral.
	
	(C) Mofana Mphaka; 2006
	Edited: March 2020, February 2021
*/

#include <iostream>

#include <C:\Users\Mofan\OneDrive\Documents\CS2432{OOP}\programs\number{functions}.cpp>

class aPolygon
{
	protected:
		long double	* sides,	//	There are N sides with different lengths
					* angles;	//	There are N angles with different sizes
		long int	no_of_sides;	//	The number of sides, N, of this polygon

	public:
		aPolygon(long int _sides = 1);
		/*
			It sets no_of_sides = _sides.
			If _sides < 3 then no_of_sides = 1.
			It then sets angles = sides = no_of_sides, and
			all the corresponding data values (of sides and angles) are set to 0
		*/

		virtual void input () = 0;	//	input the derived polygon
		virtual void display () = 0;	//	display the derived polygon

		~aPolygon() {}
};


class aTriangle : public aPolygon
{
	public:
		aTriangle();
		/*	It constructs a polygon of 3 sides with the angles: 90deg, 45deg, 45deg */

		~aTriangle() {}


		virtual void input();
		virtual void display();


		long double perimeter();
		/*	It computes the perimeter of the triangle */

		long double area();
		/*	It computes the area of the triangle */

		bool operator == (aTriangle right);
		/*	It returns true if this triangle is the same as the triangle on the right,
			false otherwise. (i.e Triangles are equal when they cover the same space,
			not necessarily identical in shape).
		*/

		bool operator != (aTriangle right);
		/*	It rturns true if this != right, false otherwise */

		bool operator > (aTriangle right);
		/*	It rturns true if this > right, false otherwise */

		bool operator < (aTriangle right);
		/*	It rturns true if this < right, false otherwise */
		
		bool operator >= (aTriangle right);
		/*	It rturns true if this >= right, false otherwise */

		bool operator <= (aTriangle right);
		/*	It rturns true if this <= right, false otherwise */


		aTriangle operator = (aTriangle right);
		/*	It computes this = right*/

		
	friend std::istream & operator >> (std::istream & input, aTriangle &right);
	/*	It scans the triangle input from input stream like keyboard. E.g. cin >> right*/

	friend std::ostream & operator << (std::ostream & output, aTriangle right);
	/*	It outputs the triangle onto an output stream like the screen. E.g. cout << right*/			
};


class aCircle : public aPolygon
{
	protected:
		long double radius;	//	The unique data element for every circle

	public:
		aCircle(long double _radius = 1);
		/*	It constructs a circle, default is the unit circle */

		~aCircle() { }

		virtual void input();
		virtual void display();

		
		void setRadius(double length = 1);
		/*	It (re)sets the radius of the given circle, default is the radius of unit length */

		long double area();
		/*	It computes and returns the area of the circle	*/

		long double circumference();
		/*	It computes and returns the circumference of the circle	*/

		long double diameter();
		/*	It computes and returns the diameter the circle	*/

		long double getRadius();
		/*	It avails the radius of the circle to the calling environment	*/

		
		bool operator > (aCircle right);
		/*	It returns true if this > right, false otherwies */

		bool operator >= (aCircle right);
		/*	It returns true if this >= right, false otherwies */

		bool operator < (aCircle right);
		/*	It returns true if this < right, false otherwies */

		bool operator <= (aCircle right);
		/*	It returns true if this < right, false otherwies */

		bool operator == (aCircle right);
		/*	It returns true if this == right, false otherwies */

		bool operator != (aCircle right);
		/*	It returns true if this != right, false otherwies */

		aCircle operator = (aCircle right);
		/*	It computes this = right */
		

	friend std::istream & operator >> (std::istream & input, aCircle &right);
	/*	It scans the circle input from input stream like keyboard. E.g. cin >> right*/

	friend std::ostream & operator << (std::ostream & output, aCircle right);
	/*	It displays the circle onto an output stream like the console. E.g. cout << right*/
};


class aQuadrilateral : public aPolygon
{
	/*	          d
		---------------------
		\ B+C            H2/
		  \              / c
		  a \  H1   A+D/
			  \------/
			      b
		A Quadrilateral = 2 triangles: Triangle abh (angles: A,H1,B) + cdh (angles: C,H2,D)
	*/
	private:
		long double	diagonal,	/* diagonal = side h */
					angleA,		
					angleB,
					angleC,
					angleD;
	public:
		aQuadrilateral();
		/*	It creates a a quadrilateral as a rectangle with dimensions: height = 3 units, length = 4 units */

		~aQuadrilateral() {}


		virtual void input();
		/*	It inputs the data of the quadrilateral: sides and angles */

		virtual void display();
		/*	It displays the quadrileteral: angles, sides, perimeter and area */


		long double perimeter();
		/*	It computes the perimeter of the quadrilateral */

		long double area();
		/*	It computes the area of the quadrilateral */

		aQuadrilateral operator = (aQuadrilateral right);
		/*	It assigns the quadrilateral right to this quadrilateral on the left */

		bool operator == (aQuadrilateral right);

		bool operator != (aQuadrilateral right);

		bool operator > (aQuadrilateral right);

		bool operator < (aQuadrilateral right);

		bool operator >= (aQuadrilateral right);

		bool operator <= (aQuadrilateral right);

	friend std::istream & operator >> (std::istream & input, aQuadrilateral & right);
	/*	same as the input member function */

	friend std::ostream & operator << (std::ostream & output, aQuadrilateral right);
	/*	same as the display member function */
};


aPolygon :: aPolygon (long int _sides)
{
	if (_sides < 3)	//	Check inconsistencies
		_sides = 1;

	no_of_sides = _sides;

	try
	{
		angles = new long double[no_of_sides];
		sides = new long double[no_of_sides];

		for(long int i = 0; i < no_of_sides; i++)
			angles[i] = sides[i] = 0;
	}
	catch(...)
	{
		std::cout << "\nCould not create the Polygon ... Aborting\n";
		exit(0);
	}
}
// -----------------------------------------------------------------


aTriangle :: aTriangle() : aPolygon(3)
/*
	Default constructor: It sets the triangle to a right-angled triangle of:
	(1) One 90 degree angle and two 45 degrees angles
	(2) Three sides of 5 cm long and the other two are computed using the sine rule
*/
{
	angles[0] = 90;	//	1st angle = 90 degrees
	angles[1] = 45;	//	2nd angle = 45 degrees
	angles[2] = 45;	//	3rd angle = 45 degrees

	sides[0] = 5;	//	1st side = 5 cm long -- the longest side (hypotenuse)
	
	//	So, side[1] = sin(angle[1])/sin(angle[0]) * side[0]
	sides[1] = sin(rad(angles[1]))/sin(rad(angles[0])) * sides[0];
	
	//	side[2] = sin(angle[2])/sin(angle[0]) * side[0]
	sides[2] = sin(rad(angles[2]))/sin(rad(angles[0])) * sides[0];
}


void aTriangle :: input()
{
	double anglesSum = 0;

	do
	{
		std::cout << "Enter the First angle, angle[0] ";
		std::cin >> angles[0];

		if (angles[0] <= 0)	//	Check inconsistencies
			angles[0] = 1;

		if (angles[0] >= 180)
			std::cout << "A triangle has more than ONE angle totally upto 180 degrees!\n"
						<< "Re-enter the correct angle value < 180\n";
	}
	while ((anglesSum + angles[0]) >= 180);
	
	anglesSum += angles[0];

	do
	{
		std::cout << "Enter the Second angle, angle[1] ";
		std::cin >> angles[1];

		if (angles[1] <= 0)	//	Check inconsistencies
			angles[1] = 1;

		if ((anglesSum + angles[1]) >= 180)
			std::cout << "A triangle has more than TWO angles totally upto 180 degrees!\n"
					  << "Re-enter the correct angle value < " << 180-anglesSum << "\n";
	}
	while ((anglesSum + angles[1]) >= 180);
		
	anglesSum += angles[1];

	//	The third angle, angles[2] = 180 - anglesSum
	angles[2] = 180 - anglesSum;
	std::cout << "\nThe Third angle, angle[2] = " << angles[2] << "\n";

	//	Input sides -- must be > 0 cm
	do
	{
		std::cout << "Enter the First side, side[0], opposite angle[0], " << angles[0] << "deg ";
		std::cin >> sides[0];

	if (sides[0] <= 0)
		std::cout << "A side of any Triangle can never be <= 0\n"
					<< "Re-Enter the correct length > 0\n";
	}
	while (sides[0] <= 0);

	//	Now compute all the corresponding lengths using the sine rule:
	//	sin(angle[0])/side[0] = sin(angle[1])/side[1] = sin(angle[2])/side[2]

	//	So, side[1] = sin(angle[1])/sin(angle[0]) * side[0]
	sides[1] = sin(rad(angles[1]))/sin(rad(angles[0])) * sides[0];
	
	//	side[2] = sin(angle[2])/sin(angle[0]) * side[0]
	sides[2] = sin(rad(angles[2]))/sin(rad(angles[0])) * sides[0];

	std::cout << "The other sides have been computed using the sine rule:\n";
	std::cout << "The Second side, side[1] = " << sides[1] << "\n";
	std::cout << "The Third side, side[2] = " << sides[2] << "\n";
}


void aTriangle :: display()
{
	int i;

	std::cout << "\nTRIANGLE:";
	std::cout << "\nAngles: ";
	std::cout << "(";

	for(i = 0; i < no_of_sides; i++)
	{
		std::cout << angles[i] << "deg";
		if (i < (no_of_sides - 1))
			std::cout << ", ";
	}
	std::cout << ")";
	
	std::cout << "\nSides: ";
	std::cout << "(";

	for(i = 0; i < no_of_sides; i++)
	{
		std::cout << sides[i] << "cm";
		if (i < (no_of_sides - 1))
			std::cout << ", ";
	}
	std::cout << ")\n";
	std::cout << "Perimeter: " << perimeter() << "cm\n";
	std::cout << "Area: " << area() << "cm^2\n";
}


long double aTriangle :: perimeter ()
{
	long double tPerimeter = 0;

	for (long int i = 0; i < no_of_sides; i++)
		tPerimeter += sides[i];

	return tPerimeter;
}


long double aTriangle :: area ()
{
	//	The area of the triangle, Area = (Base * height)/. For the triangle with sides A, B & C
	//	the sine rule gives: Area = (A*B*sine(<C))/2 = (A*C*sine(<B))/2, where base = side A
	return (sides[0] * sides[1] * sin(rad(angles[2]))) / 2;	//	(A*B*sine(<C))/2
}


aTriangle aTriangle :: operator = (aTriangle right)
{
	for(long int i = 0; i < no_of_sides; i++)
	{
		this->sides[i] = right.sides[i];
		this->angles[i] = right.angles[i];
	}

	return (*this);
}


bool aTriangle :: operator == (aTriangle right)
{
	return this->perimeter() == right.perimeter();
}


bool aTriangle :: operator != (aTriangle right)
{
	return !((*this) == right);
}


bool aTriangle :: operator > (aTriangle right)
{
	return this->perimeter() > right.perimeter();
}


bool aTriangle :: operator < (aTriangle right)
{
	return right > (*this);
}


bool aTriangle :: operator >= (aTriangle right)
{
	return (*this) > right || (*this) == right;
}


bool aTriangle :: operator <= (aTriangle right)
{
	return (*this) < right || (*this) == right;
}


std::istream & operator >> (std::istream & input, aTriangle &right)
{
	double anglesSum = 0;

	do
	{
		std::cout << "Enter the First angle, angle[0] ";
		input >> right.angles[0];

		if (right.angles[0] <= 0)	//	Check inconsistencies
			right.angles[0] = 1;

		if (right.angles[0] >= 180)
			std::cout << "A triangle has more than ONE angle totally upto 180 degrees!\n"
						<< "Re-enter the correct angle value < 180\n";
	}
	while ((anglesSum + right.angles[0]) >= 180);
	
	anglesSum += right.angles[0];

	do
	{
		std::cout << "Enter the Second angle, angle[1] ";
		input >> right.angles[1];

		if (right.angles[1] <= 0)	//	Check inconsistencies
			right.angles[1] = 1;

		if ((anglesSum + right.angles[1]) >= 180)
			std::cout << "A triangle has more than TWO angles totally upto 180 degrees!\n"
					  << "Re-enter the correct angle value < " << 180-anglesSum << "\n";
	}
	while ((anglesSum + right.angles[1]) >= 180);
		
	anglesSum += right.angles[1];

	//	The third angle, angles[2] = 180 - anglesSum
	right.angles[2] = 180 - anglesSum;
	std::cout << "\nThe Third angle, angle[2] = " << right.angles[2] << "\n";

	//	Input sides -- must be 1 cm or more
	do
	{
		std::cout << "Enter the First side, side[0], opposite angle[0], " << right.angles[0] << "deg ";
		input >> right.sides[0];

	if (right.sides[0] <= 0)
		std::cout << "A side of any Triangle can never be <= 0\n"
					<< "Re-Enter the correct length > 0\n";
	}
	while (right.sides[0] <= 0);

	right.sides[1] = sin(rad(right.angles[1]))/sin(rad(right.angles[0])) * right.sides[0];
	right.sides[2] = sin(rad(right.angles[2]))/sin(rad(right.angles[0])) * right.sides[0];

	std::cout << "The other sides have been computed using the sine rule:\n";
	std::cout << "The Second side, side[1] = " << right.sides[1] << "\n";
	std::cout << "The Third side, side[2] = " << right.sides[2] << "\n";

	return input;
}


std::ostream & operator << (std::ostream & output, aTriangle right)
{
	int i;

	output << "\nTRIANGLE:";
	output << "\nAngles: ";
	output << "(";

	for(i = 0; i < right.no_of_sides; i++)
	{
		output << right.angles[i] << "deg";
		if (i < (right.no_of_sides - 1))
			output << ", ";
	}
	output << ")";
	
	output << "\nSides: ";
	output << "(";

	for(i = 0; i < right.no_of_sides; i++)
	{
		output << right.sides[i] << "cm";
		if (i < (right.no_of_sides - 1))
			output << ", ";
	}
	output << ")\n";
	output << "Perimeter: " << right.perimeter() << "cm\n";
	output << "Area: " << right.area() << "cm^2\n";

	return output;
}


aCircle :: aCircle(long double _radius) : aPolygon(1)
{
	radius = (_radius > 0) ? _radius : 1;
	sides[0] = circumference();	//	a circle has 1 circular side, the circumference
	angles[0] = 360;	//	a circle has 1 angle, 360 degrees = 2PI radians
}


void aCircle :: setRadius(double length)
{
	radius = (length > 0) ? length : 1;
	sides[0] = circumference();
}


void aCircle :: input()
{
	do
	{
		std::cout << "Enter Radius ";
		std::cin >> radius;

		if (radius <= 0)
			std::cout << "Entered value is invalid -- Re-Enter\n";
	}
	while (radius <= 0);

	sides[0] = circumference();
}


long double aCircle :: getRadius()
{
	return radius;
}


long double aCircle :: area()
{
	return PI * radius * radius;
}


long double aCircle :: circumference()
{
	return 2 * PI * radius;
}


long double aCircle :: diameter()
{
	return 2 * radius;
}


void aCircle :: display()
{
	std::cout << "\nCIRCLE:\n"
			  << "Radius:  " << getRadius() << "cm\n"
		      << "Diameter:  " << diameter() << "cm\n"
			  << "Circumference:  " << sides[0] << "cm\n"
			  << "Area:  " << area() << "cm^2\n";
}


aCircle aCircle :: operator = (aCircle right)
{
	this->radius = right.radius;
	this->sides[0] = right.sides[0];
	return (*this);
}


bool aCircle :: operator == (aCircle right)
{
	return this->radius == right.radius;
}


bool aCircle :: operator > (aCircle right)
{
	return this->radius > right.radius;
}


bool aCircle :: operator != (aCircle right)
{
	return !((*this) == right);
}


bool aCircle :: operator < (aCircle right)
{
	return right > (*this);
}


bool aCircle :: operator >= (aCircle right)
{
	return ((*this) > right) || ((*this) == right);
}


bool aCircle :: operator <= (aCircle right)
{
	return ((*this) < right) || ((*this) == right);
}


std::istream & operator >> (std::istream & input, aCircle &right)
{
	do
	{
		std::cout << "Enter Radius ";
		input >> right.radius;

		if (right.radius <= 0)
			std::cout << "Entered value is invalid -- Re-Enter\n";
	}
	while (right.radius <= 0);

	right.sides[0] = right.circumference();

	return input;
}


std::ostream & operator << (std::ostream & output, aCircle right)
{
	output	<< "\nCIRCLE:\n"
			<< "Radius:  " << right.getRadius() << "cm\n"
		    << "Diameter:  " << right.diameter() << "cm\n"
			<< "Circumference:  " << right.sides[0] << "cm\n"
			<< "Area:  " << right.area() << "cm^2\n";
	return output;
}
//------------------------------------------------------------------


aQuadrilateral :: aQuadrilateral() : aPolygon(4)
// Default constructor: It creates a quadrilateral as two 3-4-5 Puthagorus triangles
{
	//	All the four angle are 90 degrees
	angles[0] = angles[1] = angles[2] = angles[3] = 90;

	//	All the 2 sides representing height are equal, all are 3 units long
	sides[0]= sides[2] = 3.0;

	//	All the other 2 sides representing length are equal, all are 4 units long
	sides[1]= sides[3] = 4.0;

	//	The hypotenuse -- the diagonal = 5 units, a 3-4-5 triangle
	diagonal = 5.0;

	//	Find angle A by the sine rule: sin A / 3 = sin 90 / 5 => A = arcsin(3/5*sin(90))
	angleA = deg(arcsin(3.0/5.0*sin(rad(90))));

	//	Now all the other angles are easily computed as:
	angleB = 180 - (90 + angleA);
	angleC = 90 - angleB;
	angleD = 90 - angleA;
}


void aQuadrilateral :: input()
{
	std::cout << "A Quadrilateral has four sides: a, b, c, d\n";
	do
	{
		std::cout << "Enter the 1st side, side a = "; std::cin >> sides[0];
		if (sides[0] <= 0)
			std :: cout << "\nRE-ENTER, A quadrilateral side is never <= 0!\n";
	}while (sides[0] <= 0);

	do
	{
		std::cout << "Enter the 2nd side, adjacent to " << sides[0] << ", side b = "; std::cin >> sides[1];
		if (sides[1] <= 0)
			std :: cout << "\nRE-ENTER, A quadrilateral side is never <= 0!\n";
	}while (sides[1] <= 0);
	
	do
	{
		std::cout << "Enter the angle (in degrees) between, side a = " << sides[0] << ", and side b = " << sides[1] << " ";
		std::cin >> angles[0]; // angle H1

		if (angles[0] <= 0)
			std :: cout << "\nRE-ENTER, A quadrilateral angle is never <= 0!\n";
		
		if (angles[0] >= 180)
			std :: cout << "\nRE-ENTER, A   c o n v e x   quadrilateral angle is never >= 180!\n";
	}while ((angles[0] <= 0) || (angles[0] >= 180));

	/* --- Computing the rest of the values of the 1st triangle: Triangle 1 ----*/

	//	Use the COSINE RULE to find the diagonal -- h: h = sqrt(a*a + b*b - 2ab Cos H1)
	diagonal = sqrt(sides[0]*sides[0] + sides[1]*sides[1] - 2*sides[0]*sides[1]*cos(rad(angles[0])));
	
	//	Use, once again,the COSINE RULE to find all the angles: A and B
	//	for angle A: a^2 = h^2 + b^2 - 2bh cos A => A = arccos((h^2+b^2-a^2)/2bh)
	angleA = deg(arccos((diagonal*diagonal+sides[1]*sides[1]-sides[0]*sides[0])/2*sides[1]*diagonal));

	angleB = 180 - (angleA + angles[0]);

	/* --- Computing the rest of the values for the 2nd triangle: Triangle 2 ----*/

	do
	{
		std::cout << "Enter the 3rd side, adjacent to " << sides[1] << ", side c = "; std::cin >> sides[2];
		if (sides[2] <= 0)
			std :: cout << "\nRE-ENTER, A quadrilateral side is never <= 0!\n";
	}while (sides[2] <= 0);
	
	do
	{
		std::cout << "Enter the angle (in degrees) between, side b = " << sides[1] << ", and side c = " << sides[2] << " ";
		std::cin >> angles[1]; // angle D

		if (angles[1] <= 0)
			std :: cout << "\nRE-ENTER, A quadrilateral angle is never <= 0!\n";
		
		if (angles[1] >= 180)
		{
			std :: cout << "\n\n A   c o n v e x   quadrilateral angle is never >= 180!\n";
			std :: cout << "RE-ENTER, a value < " << 180 << "\n\n";
		}
	}while ((angles[1] <= 0) || (angles[1] >= 180));

	angleD = angles[1] - angleA;

	//	use the COSINE RULE to compute side d -- the last side
	sides[3] = sqrt(diagonal*diagonal + sides[2]*sides[2] - 2*diagonal*sides[2]*cos(rad(angleD)));

	//	use COSINE RULE to compute the angle between sides c and d -- H2
	//	h^2 = c^2 + d^2 - 2cd cos H2 => H2 = arccos((c^2+d^2-h^2)/2cd)
	angles[2] = deg(arccos((sides[2]*sides[2]+sides[3]*sides[3]-diagonal*diagonal)/2*sides[2]*sides[3]));

	angleC = 180 - (angleD + angles[2]);

	angles[3] = angleB + angleC;
	
	std::cout << "\n\nAll the other Quadrilateral components are computed using the COSINE RULE:\n";
	std::cout << "side d = " << sides[3] << "\n";
	std::cout << "Angle between a = " << sides[0] << " and side d = " << sides[3] << " = " << angles[3] << "\n";
	std::cout << "Angle between c = " << sides[2] << " and side d = " << sides[3] << " = " << angles[2] << "\n\n";
}


void aQuadrilateral :: display()
{
	long int i;

	std::cout << "\nQUADRILATERAL:";
	std::cout << "\nAngles: ";
	std::cout << "(";

	for(i = 0; i < no_of_sides; i++)
	{
		std::cout << angles[i] << "deg";
		if (i < (no_of_sides - 1))
			std::cout << ", ";
	}
	std::cout << ")";
	
	std::cout << "\nSides: ";
	std::cout << "(";

	for(i = 0; i < no_of_sides; i++)
	{
		std::cout << sides[i] << "cm";
		if (i < (no_of_sides - 1))
			std::cout << ", ";
	}
	std::cout << ")\n";
	std::cout << "Perimeter: " << perimeter() << "cm\n";
	std::cout << "Area: " << area() << "cm^2\n";
}


long double aQuadrilateral :: perimeter ()
{
	long double tPerimeter = 0;

	for (long int i = 0; i < no_of_sides; i++)
		tPerimeter += sides[i];

	return tPerimeter;
}


long double aQuadrilateral :: area ()
{
	//	The area of the triangle, Area = (Base * height)/. For the triangle with sides A, B & C
	//	the sine rule gives: Area = (A*B*sine(<C))/2 = (A*C*sine(<B))/2 = (B*C*sine(<A))/2

	//	Area of Triangle 1: sides a,b,h -- a*b*sin(H1)
	long double Triangle1 = (sides[0] * sides[1] * sin(rad(angles[0])))/2;

	//	Area of Triangle 2: sides c,d,h -- a*b*sin(H2)
	long double Triangle2 = (sides[2] * sides[3] * sin(rad(angles[2])))/2;

	return Triangle1 + Triangle2;
}


aQuadrilateral aQuadrilateral :: operator = (aQuadrilateral right)
{
	this->diagonal = right.diagonal;
	this->angleA = right.angleA;
	this->angleB = right.angleB;
	this->angleC = right.angleC;
	this->angleD = right.angleD;
	this->no_of_sides = right.no_of_sides;

	this->angles = new long double[no_of_sides];
	this->sides = new long double[no_of_sides];

	for (long int i = 0; i < no_of_sides; i++)
	{
		this->sides[i] = right.sides[i];
		this->angles[i] = right.angles[i];
	}

	return (*this);
}


bool aQuadrilateral :: operator == (aQuadrilateral right)
{
	return (this->perimeter() == right.perimeter());
}


bool aQuadrilateral :: operator != (aQuadrilateral right)
{
	return !((*this) == right);
}


bool aQuadrilateral :: operator > (aQuadrilateral right)
{
	return (this->perimeter() > right.perimeter());
}


bool aQuadrilateral :: operator < (aQuadrilateral right)
{
	return (right.perimeter() > this->perimeter());
}


bool aQuadrilateral :: operator >= (aQuadrilateral right)
{
	return (*this) > right || (*this) == right;
}


bool aQuadrilateral :: operator <= (aQuadrilateral right)
{
	return (*this) < right || (*this) == right;
}


std::ostream & operator << (std::ostream & output, aQuadrilateral right)
{
	long int i;

	output << "\nQUADRILATERAL:";
	output << "\nAngles: ";
	output << "(";

	for(i = 0; i < right.no_of_sides; i++)
	{
		output << right.angles[i] << "deg";
		if (i < (right.no_of_sides - 1))
			output << ", ";
	}
	output << ")";
	
	output << "\nSides: ";
	output << "(";

	for(i = 0; i < right.no_of_sides; i++)
	{
		output << right.sides[i] << "cm";
		if (i < (right.no_of_sides - 1))
			output << ", ";
	}
	output << ")\n";
	output << "Perimeter: " << right.perimeter() << "cm\n";
	output << "Area: " << right.area() << "cm^2\n";

	return output;
}

	
std::istream & operator >> (std::istream & input, aQuadrilateral & right)
{
	std::cout << "A Quadrilateral has four sides: a, b, c, d\n";
	do
	{
		std::cout << "Enter the 1st side, side a = "; input >> right.sides[0];
		if (right.sides[0] <= 0)
			std :: cout << "\nRE-ENTER, A quadrilateral side is never <= 0!\n";
	}while (right.sides[0] <= 0);

	do
	{
		std::cout << "Enter the 2nd side, adjacent to " << right.sides[0] << ", side b = "; input >> right.sides[1];
		if (right.sides[1] <= 0)
			std :: cout << "\nRE-ENTER, A quadrilateral side is never <= 0!\n";
	}while (right.sides[1] <= 0);
	
	do
	{
		std::cout << "Enter the angle (in degrees) between, side a = " << right.sides[0] << ", and side b = " << right.sides[1] << " ";
		input >> right.angles[0]; // angle H1

		if (right.angles[0] <= 0)
			std :: cout << "\nRE-ENTER, A quadrilateral angle is never <= 0!\n";
		
		if (right.angles[0] >= 180)
			std :: cout << "\nRE-ENTER, A   c o n v e x  quadrilateral angle is never >= 180!\n\n";
	}while ((right.angles[0] <= 0) || (right.angles[0] >= 180));

	/* --- Computing the rest of the values of the 1st triangle: Triangle 1 ----*/

	//	Use the COSINE RULE to find the diagonal -- h: h = sqrt(a*a + b*b - 2ab Cos H1)
	right.diagonal = sqrt(right.sides[0]*right.sides[0] + right.sides[1]*right.sides[1]
					- 2*right.sides[0]*right.sides[1]*cos(rad(right.angles[0])));
	
	//	Now use the SINE RULE to find all the angles: A and B
	//	for angle A: a^2 = h^2 + b^2 - 2bh cos A => A = arccos((h^2+b^2-a^2)/2bh)
	right.angleA = deg(arccos((right.diagonal*right.diagonal + right.sides[1]*right.sides[1]
				   - right.sides[0]*right.sides[0])/2*right.sides[1]*right.diagonal));

	right.angleB = 180 - (right.angleA + right.angles[0]);

	/* --- Computing the rest of the values for the 2nd triangle: Triangle 2 ----*/

	do
	{
		std::cout << "Enter the 3rd side, adjacent to " << right.sides[1] << ", side c = "; input >> right.sides[2];
		if (right.sides[2] <= 0)
			std :: cout << "\nRE-ENTER, A quadrilateral side is never <= 0!\n";
	}while (right.sides[2] <= 0);
	
	do
	{
		std::cout << "Enter the angle (in degrees) between, side b = " << right.sides[1] << ", and side c = " << right.sides[2] << " ";
		input >> right.angles[1];
	
		if (right.angles[1] <= 0)
			std :: cout << "\nRE-ENTER, A quadrilateral angle is never <= 0!\n";
		
		if (right.angles[1] >= 180)
		{
			std :: cout << "\n\nA   c o n v e x   quadrilateral has 4 angles totalling 360!\n";
			std :: cout << "RE-ENTER, a value < " << 180 << "\n\n";
		}
	}while ((right.angles[1] <= 0) || (right.angles[1] >= 180));

	right.angleD = right.angles[1] - right.angleA;
	
	//	use the COSINE RULE to compute side d -- the last side
	right.sides[3] = sqrt(right.diagonal*right.diagonal + right.sides[2]*right.sides[2]
					 - 2*right.diagonal*right.sides[2]*cos(rad(right.angleD)));

	//	use COSINE RULE to compute the angle between sides c and d -- H2
	//	h^2 = c^2 + d^2 - 2cd cos H2 => H2 = arccos((c^2+d^2-h^2)/2cd)
	right.angles[2] = deg(arccos((right.sides[2]*right.sides[2] + right.sides[3]*right.sides[3]
					  - right.diagonal*right.diagonal)/2*right.sides[2]*right.sides[3]));

	right.angleC = 180 - (right.angleD + right.angles[2]);

	right.angles[3] = right.angleB + right.angleC;

	std::cout << "\n\nAll the other Quadrilateral components are computed using the COSINE RULE:\n";
	std::cout << "side d = " << right.sides[3] << "\n";
	std::cout << "Angle between a = " << right.sides[0] << " and side d = " << right.sides[3] << " = " << right.angles[3] << "\n";
	std::cout << "Angle between c = " << right.sides[2] << " and side d = " << right.sides[3] << " = " << right.angles[2] << "\n\n";

	return input;
}

/*		
int main()
{
	aCircle C;
	aTriangle T;
	aQuadrilateral Q;
	
	std::cout << C << "\n";
	std::cout << T << "\n";
	std::cout << Q << "\n";
	
	return 1;
}
*/

#include <iostream>
#include <cmath>	//	replaces math.h

/*
	FILE NAME: Class{aComplexNumber}.cpp

	FUNCTION:

	This defines a complex number class

  (c) mofana mphaka; January 2020
*/

// Begin _COMPLEX_NUMBER_CLASS_ Specification 

#ifndef _COMPLEX_NUMBER_CLASS_
#define _COMPLEX_NUMBER_CLASS_

/*
	The complex number abstract data type:

	1.	A complex number has two data components:

		x -- the real part
		y -- the imaginary part
	
		The representation is: x + iy, where i is the square root of -1

	2.	Complex number operations include:

		2.1	Add/subtract two complex numbers, x (x1+ix2) and y (y1+iy2).

			x + y = (x1+y1)+i(x2+y2)
			x - y = (x1-y1)+i(x2-y2)

		2.2	Multiply two complex numbers, x (x1+ix2) and y (y1+iy2).

			x * y = (x1+ix2)*(y1+iy2) = (x1.y1-x2.y2)+i(x1.y2+y1.x2)

		2.3	Take a modulus of a complex number, x (x1+ix2).

			|x| = sqrt[(x1+ix2)*(x1-iy2)] = sqrt[x1.x1 + x2.x2]

		2.4	Compare if two complex numbers, x any y are equal:

			x == y?

			or not equal
			
			x != y?

*/

class complex
{
	
	//	F r i e n d   F u n c t i o n   D e c l a r a t i o n s


	friend double mod(complex x);
	/*	computes the modulus of the complex object, x*/
		
	friend complex operator + (double x, complex y);
	/*	adds a real number x with a complex number y: x + y */

	friend complex operator - (double x, complex y);
	/*	subtracts a complex number y from a real number x: x - y */

	friend complex operator * (double x, complex y);
	/*	multiplies a real number x with a complex number y: x * y */

	friend bool operator == (double x, complex y);
	/*	returns true if the real number x equals the complex number y,
		false otherwise
	*/

	friend bool operator != (double x, complex y);
	/*	returns true if the real number x is not equal to the complex number y,
		false otherwise
	*/

	friend std::ostream & operator << (std::ostream & output, complex x);
	/*	outputs a complex number, x. E.g cout << x */

	friend std::istream & operator >> (std::istream & input, complex & x);
	/*	inputs a complex number, x. E.g cin >> x */


	//	P u b l i c   M e m b e r   F u n c t i o n s

	public:

		//	C l a s s   C o n s t r u c t o r  -- polymorphic and uses class initialisers
		
		complex (double realPart = 0, double imaginaryPart = 0) : RealPart(realPart), ImaginaryPart(imaginaryPart) {}
		/*	Creates a complex number object with the real part as the given
			value, realPart and the imaginary part as the value, imaginaryPart, otherwise the complex number is 0 */


		//	C l a s s   D e s t r u c t o r

		~complex () {}
		/*	Destroys a complex number object by ordinary C++ out of scope rules */


		//	C l a s s   m e m b e r   f u n c t i o n s:

		double getRealPart();
		/*	avails the real part component of the complex object */

		double getImaginaryPart();
		/*	avails the imaginary part component of the complex object */
				
		double mod();
		/*	computes the modulus of this complex object*/

		void display();
		/*	displays the complex object as: real part+i imaginary part: X +iY */

		void input();
		/*	allows for the input from the keyboard of the complex object 
			data components: real part and the imaginary part */

		// M e m b e r   o p e r a t o r s
		
		complex operator + (complex right);
		/* Adss this complex number to the complex number right: (*this) + right */
		
		complex operator + (double right);
		/* Adss this complex number to the real number right: (*this) + right */
	
		complex operator - (complex right);
		/* Subtracts the complex number right from this complex number: (*this) - right */
		
		complex operator - (double right);
		/* Subtracts the real number right from this complex number: (*this) - right */
	
		complex operator * (complex right);
		/* Multiplies this complex number with the complex number right: (*this) * right */
		
		complex operator * (double right);
		/* Multiplies this complex number with the real number right: (*this) * right */
		
		complex operator = (complex right);
		/* Assigns this complex number the value of the complex number right: (*this) = right */
		
		complex operator = (double right);
		/* Assigns this complex number the value of the real number right: (*this) = right */
		
		complex operator += (complex right);
		/* Plus assign: (*this) = (*this) + right */
		
		complex operator += (double right);
	
		complex operator -= (complex right);
		/* Subtract assign: (*this) = (*this) - right */
		
		complex operator -= (double right);
	
		complex operator *= (complex right);
		/* Multiply assign: (*this) = (*this) * right */
		
		complex operator *= (double right);
	
		bool operator == (complex right);
		/* Is this complex number equals the complex number right? */
		
		bool operator == (double right);
		/* Is this complex number equals the real number right? */

		bool operator != (complex right);
		/* Is this complex number not equal to the complex number right? */
		
		bool operator != (double right);
		/* Is this complex number not equal to the real number right? */


	//	P r i v a t e   D a t a   C o m p o n e n t s

	private:

		double	RealPart,
				ImaginaryPart;
};


//	M e m b e r   &   N o n - m e m b e r   F u n c t i o n s   S p e c i f i c a t i o n s


double complex :: getRealPart()
{ 
	return RealPart;
}

double complex :: getImaginaryPart() 
{ 
	return ImaginaryPart;
}


double complex :: mod()
/*	computes the modulus of this complex object, x (x1 + ix2): 
	|x1 + ix2| = sqrt(x1 * x1 + x2 * x2)
*/
{
	return(sqrt(this->RealPart * this->RealPart + this->ImaginaryPart * this->ImaginaryPart));
}


double mod(complex x)
/*	computes the modulus of the complex object, x */
{
	return(sqrt(x.RealPart * x.RealPart + x.ImaginaryPart * x.ImaginaryPart));
}


void complex :: display()
{
	if ((RealPart != 0) || (ImaginaryPart != 0))
	{
		// Display the real part

		if (RealPart != 0)
			std::cout << RealPart;

		// Display the imaginary part

		if (ImaginaryPart != 0)
		{
			if (ImaginaryPart > 0 )
				std::cout << "+i" << ImaginaryPart;

			else // (ImaginaryPart < 0 )
				std::cout << "-i" << (-1) * ImaginaryPart;
		}
	}
	else
		std::cout << 0; // The complex number is zero -- 0 + 0i
}


void complex :: input()
{
	std::cout << "Real Part? "; std::cin >> RealPart;
	std::cout << "Imaginary Part? "; std::cin >> ImaginaryPart;
}


//	O p e r a t o r    S p e c i f i c a t i o n s

complex complex :: operator + (complex right)
/*	adds the two complex objects: this, x,  and right, y
	x + y = (x1 + ix2)+(y1 + iy2) = (x1+y1) + i(x2+y2)
*/
{
	complex z;
	
	z = *this;	//	copy this to avoid side effects
	
	z.RealPart = z.RealPart + right.RealPart;
	z.ImaginaryPart = z.ImaginaryPart + right.ImaginaryPart;

	return z;
}

complex complex :: operator + (double right)
/*	adds the two objects: this complex number, x and real number right, y
	x + y = (x1+ix2) + y = x1 + y + i(x2)
*/
{
	complex z;
	
	z = *this;
	
	z.RealPart = z.RealPart + right;

	return z;
}


complex complex :: operator += (complex right)
{
	(*this) = (*this) + right;
	return(*this);
}


complex complex :: operator += (double right)
{
	(*this) = (*this) + right;
	return(*this);
}


complex	operator + (double x, complex y)
/*	adds the two objects: real number x and the complex number y
	x + y = x + (y1+iy2) = (x + y1) + i(y2)
*/
{
	complex z;
	
	z = y;
	
	z.RealPart = x + z.RealPart;
	return z;
}


complex complex :: operator - (complex right)
/*	subtracts the complex number right, y, from this complex number, x
	x - y = (x1 + ix2)-(y1 + iy2) = (x1-y1) + i(x2-y2)
*/
{
	complex z;
	
	z = *this;

	z.RealPart = z.RealPart - right.RealPart;
	z.ImaginaryPart = z.ImaginaryPart - right.ImaginaryPart;

	return z;
}

complex complex :: operator - (double right)
/*	subtracts the real number right, y, from this complex number, x
	x - y = (x1 + ix2) - y = (x1 - y) + i(x2)
*/
{
	complex z;
	
	z = *this;

	z.RealPart = z.RealPart - right;

	return z;
}

complex complex :: operator -= (complex right)
{
	(*this) = (*this) - right;
	return(*this);
}

complex complex :: operator -= (double right)
{
	(*this) = (*this) - right;
	return(*this);
}


complex	operator - (double x, complex y)
/*	subtracts the complex number y from the real number x
	x - y = x - (y1+iy2) = (x - y1) - i(y2)
*/
{
	complex z;
	
	z = y;
	
	z.RealPart = x - z.RealPart;
	z.ImaginaryPart = 0 - z.ImaginaryPart;
	
	return z;
}
	
complex complex :: operator * (complex right)
/*	multiplies the two complex objects: x and y
	x * y = (x1 + ix2)(y1 + iy2) = (x1.y1-x2.y2) + i(x1.y2+y1.x2)
*/
{
	complex z;
	
	z = *this;
	
	z.RealPart = z.RealPart * right.RealPart - z.ImaginaryPart * right.ImaginaryPart;
	z.ImaginaryPart = z.RealPart * right.ImaginaryPart + z.ImaginaryPart * right.RealPart;

	return z;
}

complex complex :: operator * (double right)
/*	multiplies this complex number, x, with the real number right, y -- scalar multiplication
	x * y = (x1+ix2) * y = x1*y + i(x2*y)
*/
{
	complex z;
	
	z = *this;
	
	z.RealPart = z.RealPart * right;
	z.ImaginaryPart = z.ImaginaryPart * right;

	return z;
}


complex complex :: operator *= (complex right)
{
	(*this) = (*this) * right;
	return(*this);
}

complex complex :: operator *= (double right)
{
	(*this) = (*this) * right;
	return(*this);
}


complex operator * (double x, complex y)
/*	multiplies the real number, x, with the complex number right, y -- scalar multiplication
	x * y = x * (y1+iy2) = x*y1 + i(x*y2)
*/
{	
	complex z;
	
	z = y;
	
	z.RealPart = x * z.RealPart;
	z.ImaginaryPart = x * z.ImaginaryPart;

	return z;
}
		
complex complex :: operator = (complex right)
/*	assigns this complex number, x, the value of the complex number right, y
	(x = y) = (x1 = y1), i(x2 = y2)
*/
{
	this -> RealPart = right.RealPart;
	this -> ImaginaryPart = right.ImaginaryPart;
	
	return (*this);
}

complex complex :: operator = (double right)
/*	assigns this complex number, x, the value of the real number right, y
	(x = y) = (x1 = y), i(x2 = 0)
*/
{
	this -> RealPart = right;
	this -> ImaginaryPart = 0;
	
	return (*this);
}


bool complex :: operator == (complex right)
{
	return((this->RealPart == right.RealPart) && (this->ImaginaryPart == right.ImaginaryPart));
}


bool complex :: operator == (double right)
{
	return((this->RealPart == right) && (this->ImaginaryPart == 0));
}


bool operator == (double x, complex y)
/*	returns true if the two complex numbers, x and y are the same,
	false otherwise
*/
{
	return((x == y.RealPart) && (y.ImaginaryPart == 0));
}


bool complex :: operator != (complex right)
{
	return !((*this) == right);
}


bool complex :: operator != (double right)
{
	return !((*this) == right);
}


bool operator != (double x, complex y)
/*	returns true if the two complex numbers, x and y are NOT the same,
	false otherwise
*/
{
	return( !(x == y));
}


std::ostream & operator << (std::ostream & output, complex x)
/*	outputs a complex number, x. E.g cout << x */
{
	
	if ((x.RealPart != 0) || (x.ImaginaryPart != 0))
	{
		// Display the real part

		if (x.RealPart != 0)
			output << x.RealPart;

		// Display the imaginary part

		if (x.ImaginaryPart != 0)
		{
			if (x.ImaginaryPart > 0 )
				output << "+i" << x.ImaginaryPart;

			else // (ImaginaryPart < 0 )
				output << "-i" << (-1) * x.ImaginaryPart;
		}
	}
	else
		std::cout << 0; // The complex number is zero -- 0 + 0i

	return(output);
}


std::istream & operator >> (std::istream & input, complex & x)
/*	inputs a complex number, x. E.g cin >> x */
{
	std::cout << "Real Part? "; input >> x.RealPart;
	std::cout << "Imaginary Part? "; input >> x.ImaginaryPart;
	return(input);
}

#endif // End of _COMPLEX_NUMBER_CLASS_ Specification

/*
int main()
{
	complex x(2,3);
	
	std::cout << 2 << " - " << x << " = " << (2-x) << "\n";
}
*/


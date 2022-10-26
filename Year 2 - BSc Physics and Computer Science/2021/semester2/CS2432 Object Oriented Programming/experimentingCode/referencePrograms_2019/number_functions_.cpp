/*	AUTHOR: Mofana Mphaka
	PROGRAM NAME: number{functions}.cpp
	FUNCTION:

	The file contains some number functions as follows:

	(1) It contains the natural logarithm, ln, and its natural base, e.
	(2) It again contains the three most commonly used trigonometric functions:
		sine, cosine and tangent and their inverses.
	(3)	It also contains the three most commonly used hyperbolic functions:
		sinh, cosh and tanh and their inverses.
	(4) There are other number functions like factorial, exponentiation, etc
		including important constants such as pi, PI.

	DATE: 9th September 2011
*/

#include<iostream>

#if !defined _NUMBER_FUNCTIONS_
#define _NUMBER_FUNCTIONS_

/*-------------------------------------------------------------------------*/
//																			/
// F u n c t i o n   P r o t o t y p e s									/
//																			/
/*-------------------------------------------------------------------------*/

long double exp(long double y, long n);
/*	It returns x to power n, n an integer exponent	*/

long double fact(long n);
/*	It returns n!	*/

long double round(long double x, long int dec_places = 0);
/*	It returns x rounded up to the given decimal places	*/

long double e(long double x, long double eps = 1e-100);
/*	It returns the natural base e to power x, correct to eps decimal places	*/

long double ln(long double x, long double eps = 1e-100);
/*	It returns the natural logarithm, ln, of x, correct to eps decimal places	*/

long double power(long double x, long double y, long double eps = 1e-100);
/*	It returns x to power y, correct to eps decimal places	*/

long double mod(long double x);
/*	It returns the absolute value of x -- |x|	*/

long double mod(long double x, long double y);
/*	It returns the remainder when dividing x by y i.e. reminder of x / y	*/

long double dist(long double x, long double y);
/*	It returns the distance between the numbers x and y i.e. |x - y|	*/

long double frac(long double x);
/* It returns the fractal part of the number x. E.g for x = 2.5, it returns 0.5 */

long double sqrt(long double x, long double eps = 1e-100);
/* it returns the square root of the real number x (if it exists) otherwise it returns 0 */

long double deg(long double x);
/*	It returns the corresponding degrees given x radians
	-- i.e. convert degrees to radians	*/

long double rad(long double x);
/*	It returns the corresponding radians given x degrees 
	-- i.e. convert degrees to radians	*/

long double sin(long double x, long double eps = 1e-100);
/*	It returns the sine value of x, correct to eps decimal places. x must be in radians	*/

long double cos(long double x, long double eps = 1e-100);
/*	It returns the cosine value of x, correct to eps decimal places. x must be in radians	*/

long double tan(long double x, long double eps = 1e-100);
/*	It returns the tangent value of x, correct to eps decimal places. x must be in radians	*/

long double arcsin(long double x, long double eps = 1e-100);
/*	It returns the sine inverse value of x, correct to eps decimal places	*/

long double arccos(long double x, long double eps = 1e-100);
/*	It returns the cosine inverse value of x, correct to eps decimal places	*/

long double arctan(long double x, long double eps = 1e-100);
/*	It returns the tangent inverse value of x, correct to eps decimal places	*/


const long double PI = 4 * arctan(1);


long double sinh(long double x, long double eps = 1e-100);
/*	It returns the sinh value of x, correct to eps decimal places	*/

long double cosh(long double x, long double eps = 1e-100);
/*	It returns the cosh value of x, correct to eps decimal places	*/

long double tanh(long double x, long double eps = 1e-100);
/*	It returns the tanh value of x, correct to eps decimal places	*/


long double arcsinh(long double x, long double eps = 1e-100);
/*	It returns the sinh inverse value of x, correct to eps decimal places	*/

long double arccosh(long double x, long double eps = 1e-100);
/*	It returns the cosh inverse value of x, correct to eps decimal places	*/

long double arctanh(long double x, long double eps = 1e-100);
/*	It returns the tanh inverse value of x, correct to eps decimal places	*/

long root(long N, long n = 2);
/*	It returns the nth root of positive integer N -- default is square root of N	*/

bool prime(long n);
/*	It returns true if the integer n is prime, false otherwise	*/

template <class Type>
Type getNumber(char * msg, /* limits */ Type LowerLimit, Type UpperLimit);
/*	It scans the keyboard for input that satisfies the given limits for the lower bound,
	LowerLimit, and the upper bound, UpperLimit	*/

template <class Type>
Type getNumber(char * msg, char LowerOrUpperLimit, Type Limit);
/*	It scans the keyboard for input that satisfies the given limit, LowerOrUpperLimit	*/

template <class Type>
bool WithinLimits(Type num, Type LowerLimit, Type UpperLimit);
/*	It returns true if the given number, num, is within the given limits: lower limit,
	LowerLimit, and the upper limit, UpperLimit. It returns false otherwise	*/

template <class Type>
bool WithinLimits(Type num, Type Limit, char LowerOrUpperLimit);
/*	It returns true if the given number, num, satisfies the given limits, Limit.
	The limit is specified as either lower or upper bound, LowerOrUpper	*/


/*	F u n c t i o n s   o n   l i s t   o f   n u m b e r s -- ARRAYS */

long double * input(long int & Length);
/*	It reads a an array of numbers from the user via the keyboard. It also sets the 
	length of the array.
*/

void print(long double * Array, long int Length);
/*	It displays the given array of numbers on the screen as: {a1, a2, a3, ..., aN}*/

long double * sum(long double num1, long double num2, long double step);
/*	It returns the sum of numbers between the two end points: num1 and num2.
	The numbers are equi-spaced with the incremental step, step*/

long double sum(long double * Array, long int Length);
/*	It returns the sum of an array, Array, of numbers of length, Length	*/

long double average(long double * Array, long int Length);
/*	It computes the average of the given array of numbers */

long double * square(long double * Array, long int Length);
/*	It squares the given array, element-wise. */

long double * minus(long double * Array1, long double * Array2, long int Length);
/*	It computes the vector subtraction: Array1 - Array2 */

long double * plus(long double * Array1, long double * Array2, long int Length);
/*	It computes the vector addition: Array1 + Array2 */

long double * times(long double * Array1, long double * Array2, long int Length);
/*	It computes the multiplication of Array1 by Array2, element-wise */

long double mod(long double * Array, long int Length);
/*	It computes the modulus of the given array, Array, -- |Array|*/

long double mod(long double * Array1, long double * Array2, long int Length);
/*	It computes the distance between the two arrays: |Array1 - Array2|*/

long double variance(long double * Array, long int Length);
/*	It computes the variance of the numbers in the given array, Array*/

long double * modify(long double * Array, long int Length, /* with */long double value, char operation = '\0');
/* It modifies the given array, Array, with the given value, value, according to the given
	instruction, operation. For example, if the operation = '+' then the given arrays is changed
	by adding the given value to each element of the input array.
*/

long double std_dev(long double * Array, long int Length);
/*	It computes the standard deviation of the numbers in the given array, Array*/

long double dot(long double * Array1, long double * Array2, long int Length);
/*	It computes the dot product of two arrays: Array1.Array2 */


/*-------------------------------------------------------------------------*/
//																			/
// F u n c t i o n   S p e c i f i c a t i o n s							/
//																			/
/*-------------------------------------------------------------------------*/

long double exp(long double y, long n)
//	Definition: exp(y, n) = y to power n
//
//	Inputs:		1.	The real number y, i.e the base
//				2.	The integer exponent n
//
//	Outputs:	a real number, y to power n 
{
	long double	exponent = 1;
	bool		negative = false;	// assume that n is not negative

	if (n < 0)
	{
		negative = true;
		n = (-1)*n;				// make n positive for iteration
	}

	while (n > 0)
	{
		exponent = exponent * y;
		n--;
	}

	if (negative)
		return (1/exponent);
	else
		return(exponent);
}


long double fact(long n)
//	Definition: fact(n) = n! 
//	Inputs:		The integer, n
//	Outputs:	n!
{
	long double product = 1;

	while (n > 0)
	{
		product = product * n;
		n--;
	}

	return(product);
}


long double round(long double x, long int dec_places)
//	Definition: round(x, dec_places) computes and returns the rounded value of x up to the given
//				decimal places, dec_places.
//	Inputs:		The (decimal) number x and the required decimal places to round upto, dec_places
//	Outputs:	x rounded up to the required number of deimal places.
{
	long double x_frac_part,
				decimal_places,
				new_x_num;

	long int  x_int_part;

	bool x_negative = (x < 0);

	x_int_part = (long int) x;	// return the integer part of the number x
	x_frac_part = x - x_int_part;	// return the fractal part of the number x
	

	if (x_negative)
	//	If the number x was negative make it (and its fractal part) positive for iteration
	{
		x = (-1) * x;
		x_frac_part = (-1) * x_frac_part;
	}

	if (x_frac_part > 0.0)
	//	Avoid trying to round up a whole number
	{
		if (dec_places < 0)
			dec_places = 0;

		//	compute the no. of decimal places to round up to
		//	We do so by creating a new number from the fractal part of the old number
		decimal_places = exp(10, dec_places);
		new_x_num = decimal_places * x_frac_part;	//	a new number with integer and fractal part

		//	compute the new integer and fractal part of the new number
		x_int_part = (long int) new_x_num;
		x_frac_part = new_x_num - x_int_part;

		if (x_frac_part >= 0.5)
		//	If the fraction of the new number >= 0.5 we round up the integer part
			x_int_part = x_int_part + 1;

		//	revert back to the original fraction -- excess decimal digits now chopped off
		x_frac_part = (long double) x_int_part / decimal_places;

		//	Now add the integral part of x to the rounded up fraction to get x rounded up
		x = (long int) x + x_frac_part;

		if (x_negative)
			return (-1) * x;
		else
			return x;
	}
	else
		return x;
}


long double e(long double x, long double eps)
//	Definition:	e(x, eps) computes the natural base e to the power x,
//				correct to eps decimal places.
//
//	Inputs:		1.	The number x
//				2.	The accuracy level, eps
//
//	Outputs:	e to power x, correct to eps decimal places
{
	long double	e1 = 0,		//	the first iterant, nth iterant of e
				e2 = 0;		//	the second iterant, n+1st iterant of e

	long	term = 0;	//	count on the nth term

	do
	{
		e1 = e1 + exp(x, term) / fact(term);
		e2 = e1 + exp(x, term + 1) / fact(term + 1);

		term++;
	}
	while (dist(e1, e2) >= eps);

	return(e2);
}


long double ln(long double x, long double eps)
//	Definition:	ln(x, eps) computes the natural logarithm of the positive
//				number x, correct to eps decimal places.
//
//	Inputs:		1.	The number x
//				2.	The accuracy level, eps
//
//	Outputs:	The natural logarithm of x, correct to eps decimal places
{
	long double	ln1 = 0,		//	the first iterant, nth iterant of ln
				ln2 = 0;		//	the second iterant, n+1st iterant of ln

	long	term = 1;	//	count on the nth term -- the first term starts at 1

	if (x <= 0)		//	a logarithm is defined only for x > 0
		return(0);

	bool x_reciprocated = false;	// assume 0 < x <= 1
	if (x > 1)
	// x > 1 -- reciprocate it, so that 0 < 1/x < 1
	{
		x_reciprocated = true;
		x = 1 / x;
	}

	do
	{
		ln1 = ln1 + (exp(-1, term - 1) * exp(x - 1, term)) / (term);
		ln2 = ln1 + (exp(-1, term) * exp(x - 1, term + 1)) / ((term + 1));
		term++;
	}
	while (dist(ln1, ln2) >= eps);

	if (x_reciprocated)
		return ( (-1) * ln2);
	else
		return(ln2);
}


long double power(long double x, long double y, long double eps)
//	Definition:	power(x, y) computes x to power y, for any numbers
//				x and y, x > 0, correct to eps number of decimal places,
//				the default being 100 decimal places.
//
//	Inputs:		1.	The number base x
//				2.	The exponent y
//
//	Outputs:	x to power y, correct to eps decimal places
{
	return e(y * ln(x, eps), eps);
}


long double mod(long double x)
// Definition: mod(x) is the absolute value of x -- |x|
//
//	Inputs:		The number x.
//
//	Outputs:	|x|
{
	if (x < 0)
		return (-1 * x);
	else
		return x;
}


long double mod(long double x, long double y)
//	Definition: mod(x, y) is the real remainder when x / y.
//				(i.e. x % y in real arithmetic).
//
//	Inputs:		1.	The enumarator x and 
//				2.	the denominator y
//
//	Outputs:	The remainder after the division x / y
{
	long double quotient, remainder;

	quotient = x / y;
	remainder = (quotient - long (quotient)) * y;

	return remainder;	//	remainder when x is divided by y
}


long double dist(long double x, long double y)
//	Definition: dist(x, y) is the distance between x and y.
//
//	Inputs:		1.	The first number, x and 
//				2.	the second number, y
//
//	Outputs:	|x - y|
{
	long double distance = x - y;

	if (distance < 0)
		return (-1) * distance;
	else
		return distance;
}


long double frac(long double x)
//	Definition:	frac(x) computes the fractal part the real number x.
//
//	Inputs:		The real number x
//
//	Outputs:	The fratal part of x.
{
	long int int_part = x;	//	take the integer part of the real number x
	return x - int_part;	//	return the fraction in x
}


long double sqrt(long double x, long double eps)
//	Definition:	sqrt(x) computes the square root of the real number x, x > 0, 
//				correct to eps number of decimal places, the default being 100 decimal places.
//
//	Inputs:		The real number x
//
//	Outputs:	The square root of x, correct to eps decimal places, otherwise 0, if x <= 0
{
	return e(0.5 * ln(x, eps), eps);
}


long double deg(long double x)
// Definition: deg(x), converts the given x radians to degrees
//
//	Inputs:		1.	The radians, x
//
//	Outputs:	The equivalent degrees.
{
	 return x * 180 / PI;
}


long double rad(long double x)
// Definition: rad(x), converts the given x degrees to radians
//
//	Inputs:		1.	The degrees, x
//
//	Outputs:	The equivalent radians.
{
	return PI * x / 180;
}


long double sin(long double x, long double eps)
//	Definition:	sin(x, eps) computes the sine value of x, in radians,
//				correct to eps decimal places.
//
//	Inputs:		1.	The number x in degrees
//				2.	The accuracy level, eps
//
//	Outputs:	sin x, correct to eps decimal places
{
	long double	sine1 = 0,		//	the first iterant, nth iterant of sine
				sine2 = 0;		//	the second iterant, n+1st iterant of sine

	long	term = 0;	//	count on the nth term

	//	The complete period of sin is: -2*PI to 2*PI radians

	if (mod(x) > 2 * PI)
		x = mod(x, 2 * PI);	//	make sure that the given angle is in the cycle: -2*PI <= x <= 2*PI

	do
	{
		sine1 = sine1 + exp(-1, term) * exp(x, 2 * term + 1) / fact(2 * term + 1);
		sine2 = sine1 + exp(-1, term+1) * exp(x, 2 * (term+1) + 1) / fact(2 * (term+1) + 1);

		term++;
	}
	while (dist(sine1, sine2) >= eps);

	return sine2;
}


long double cos(long double x, long double eps)
//	Definition:	cos(x, eps) computes the cosine value of x, in radians,
//				correct to eps decimal places.
//
//	Inputs:		1.	The number x
//				2.	The accuracy level, eps
//
//	Outputs:	cos x, correct to eps decimal places
{
	long double	cosine1 = 0,
				cosine2 = 0;

	long	term = 0;

	if (mod(x) > 2 * PI)
		x = mod(x, 2 * PI);

	do
	{
		cosine1 = cosine1 + exp(-1, term) * exp(x, 2 * term) / fact(2 * term);
		cosine2 = cosine1 + exp(-1, term+1) * exp(x, 2 * (term+1)) / fact(2 * (term+1));

		term++;
	}
	while (dist(cosine1, cosine2) >= eps);

	return(cosine2);
}


long double tan(long double x, long double eps)
//	Definition:	tan(x, eps) computes the tangent value of x, in radians,
//				correct to eps decimal places.
//
//	Inputs:		1.	The number x
//				2.	The accuracy level, eps
//
//	Outputs:	tan x, correct to eps decimal places
{
	return sin(x, eps) / cos(x, eps);	//	use the equation: tan x = sin x / cos x
}


long double arcsin(long double x, long double eps)
//	Definition:	arcsin(x, eps) computes the sine inverse of x,
//				correct to eps decimal places.
//
//	Inputs:		1.	The number x
//				2.	The accuracy level, eps
//
//	Outputs:	arcsin x, correct to eps decimal places, in degrees.
{
	long double	arcsine1 = 0,
				arcsine2 = 0;

	long	term = 0;

	if (mod(x) > 1)
		x = 1 / x;	//	arcsin is defined for |x| <= 1;
	
	do
	{
		arcsine1 = arcsine1 + (fact(2*term) * exp(x, 2*term+1)) / 
							   (exp(2, 2*term) * fact(term)*fact(term) * (2*term+1));

		arcsine2 = arcsine1 + (fact(2*(term+1)) * exp(x, 2*(term+1)+1)) / 
							   (exp(2, 2*(term+1)) * fact(term+1)*fact(term+1) * (2*(term+1)+1));

		term++;
	}
	while (dist(arcsine1, arcsine2) >= eps);

	return arcsine2;
}


long double arccos(long double x, long double eps)
//	Definition:	arcos(x, eps) computes the cosine inverse of x,
//				correct to eps decimal places.
//
//	Inputs:		1.	The number x
//				2.	The accuracy level, eps
//
//	Outputs:	arccos x, correct to eps decimal places, in degrees.
{
	return PI / 2 - arcsin(x, eps);	//	use the equation: arccos x = pi/2 - arcsin x
}


long double arctan(long double x, long double eps)
//	Definition:	artan(x, eps) computes the tan inverse of x,
//				correct to eps decimal places.
//
//	Inputs:		1.	The number x
//				2.	The accuracy level, eps
//
//	Outputs:	arctan x, correct to eps decimal places
{
	long double	arctan1 = 0,
				arctan2 = 0;

	long	term = 0;

	// for x such that x^2 < inf, arctan x is defined as:

	do
	{
		arctan1 = arctan1 + exp(x*x/(1+x*x), term) * fact(2*term) /
							(exp(2, 2*term) * fact(term)*fact(term) * (2*term+1));

		arctan2 = arctan1 + exp(x*x/(1+x*x), term+1) * fact(2*(term+1)) /
							(exp(2, 2*(term+1)) * fact(term+1)*fact(term+1) * (2*(term+1)+1));

		term++;
	}
	while (dist(arctan1, arctan2) >= eps);

	return(x / power(1 + x*x, 0.5) * arctan2);
}


long double sinh(long double x, long double eps)
//	Definition:	sinh(x, eps) computes the sinh value of x,
//				correct to eps decimal places.
//
//	Inputs:		1.	The number x
//				2.	The accuracy level, eps
//
//	Outputs:	sinh x, correct to eps decimal places
{
	return (e(x, eps) - e(-x, eps)) / 2;	//	use the equation: [sinh x = e(x) - e(-x)]/2
}


long double cosh(long double x, long double eps)
//	Definition:	cosh(x, eps) computes the cosh value of x,
//				correct to eps decimal places.
//
//	Inputs:		1.	The number x
//				2.	The accuracy level, eps
//
//	Outputs:	cosh x, correct to eps decimal places
{
	return (e(x, eps) + e(-x, eps)) / 2;	//	use the equation: [cosh x = e(x) + e(-x)]/2
}


long double tanh(long double x, long double eps)
//	Definition:	tanh(x, eps) computes the tanh value of x,
//				correct to eps decimal places.
//
//	Inputs:		1.	The number x
//				2.	The accuracy level, eps
//
//	Outputs:	tannh x, correct to eps decimal places
{
	return sinh(x, eps) / cosh(x, eps);	//	use the equation: tanh x = sinh x / cosh x
}


long double arcsinh(long double x, long double eps)
//	Definition:	arcsinh(x, eps) computes the sinh inverse of x,
//				correct to eps decimal places.
//
//	Inputs:		1.	The number x
//				2.	The accuracy level, eps
//
//	Outputs:	arcsinh x, correct to eps decimal places
{
	long double	arcsinh1 = 0,
				arcsinh2 = 0;

	long	term;

	if (mod(x) <= 1)
	{
		term = 0;	//	here term starts at 0

		do
		{
			arcsinh1 =	arcsinh1 + exp(-1, term) * (fact(2*term) * exp(x, 2*term+1)) / 
								   (exp(2, 2*term) * fact(term)*fact(term) * (2*term+1));

			arcsinh2 = arcsinh1 + exp(-1, term+1) * (fact(2*(term+1)) * exp(x, 2*(term+1)+1)) / 
								   (exp(2, 2*(term+1)) * fact(term+1)*fact(term+1) * (2*(term+1)+1));

			term++;
		}
		while (dist(arcsinh1, arcsinh2) >= eps);

		return(arcsinh2);
	}
	else	//	x >= 1 or x < -1
	{
		term = 1;	//	in this case term begins at 1

		do
		{
			arcsinh1 = arcsinh1 + exp(-1, term+1) * (fact(2*term) * exp(x, -2*term)) / 
								   (exp(2, 2*term) * fact(term)*fact(term) * (2*term));

			arcsinh2 = arcsinh1 + exp(-1, (term+1)+1) * (fact(2*(term+1)) * exp(x, -2*(term+1))) / 
								   (exp(2, 2*(term+1)) * fact(term+1)*fact(term+1) * (2*(term+1)));
			term++;
		}
		while (dist(arcsinh1, arcsinh2) >= eps);

		if (x >= 1)
			return ln(2*x, eps) + arcsinh2;
		else	// x < -1
			return ln(mod(2*x), eps) - arcsinh2;
	}
}


long double arccosh(long double x, long double eps)
//	Definition:	arccosh(x, eps) computes the cosh inverse of x,
//				correct to eps decimal places.
//
//	Inputs:		1.	The number x
//				2.	The accuracy level, eps
//
//	Outputs:	arccosh x, correct to eps decimal places
{
	long double	arccosh1 = 0,
				arccosh2 = 0;

	long	term = 1;	//	term starts at 1, not 0

	do
	{
		arccosh1 = arccosh1 + (fact(2*term) * exp(x, -2*term)) / 
							   (exp(2, 2*term) * fact(term)*fact(term) * (2*term));

		arccosh2 = arccosh1 + (fact(2*(term+1)) * exp(x, -2*(term+1))) / 
							   (exp(2, 2*(term+1)) * fact(term+1)*fact(term+1) * (2*(term+1)));

		term++;
	}
	while (dist(arccosh1, arccosh2) >= eps);

	return ln(2*x, eps) - arccosh2;
}


long double arctanh(long double x, long double eps)
//	Definition:	arctanh(x, eps) computes the tanh inverse of x,
//				correct to eps decimal places.
//
//	Inputs:		1.	The number x
//				2.	The accuracy level, eps
//
//	Outputs:	arctanh x, correct to eps decimal places
{
	long double	arctanh1 = 0,
				arctanh2 = 0;

	long	term = 0;

	if (mod(x) > 1)
		x = 1 / x;	//	arctanh is defined for |x| <= 1;
	
	do
	{
		arctanh1 = arctanh1 + exp(x, 2 * term + 1) / (2 * term + 1);
		arctanh2 = arctanh1 + exp(x, 2 * (term+1) + 1) / (2 * (term+1) + 1);
	
		term++;
	}
	while (dist(arctanh1, arctanh2) >= eps);

	return(arctanh2);
}


long root(long N, long n)
/* Definition: The nth integer root of N, (i.e N root n) root(N, n), is a minimal search.
				The least integer number z, from 0 onwards, such that

				(z + 1)^n - N > 0

				The default is square root, n = 2

	Input:	1.	Natural number N
			2.	the degree of the root, n

	Output:	The least z, satisfying: (z + 1)^n - N > 0

*/
{
	long z = 0;

	if (N >= 0)
	{
		if (n > 0)
			for (z = 0; ((exp(z + 1, n) - N) <= 0); z++);
	}

	return (z);
}


bool prime(long n)
//	Definition: if n is NOT prime then one of its prime factors lie between
//				2 and its root, root(n); otherwise n is prime.

//	Input:	long integer, n
//	Output:	true if n is prime, false otherwise
{
	if (n == 2) // n is prime -- the least prime = 2
		return(true);

	else if ((n % 2) == 0) // n is even -- n cannot be prime
		return(false);

	else
	// Since n is odd, it could be prime. So,
	// do a minimal search for possible primehood or not primehood of n
	{
		long rootN = root(n);
		bool _prime = true;

		long oddP = 3; // next odd prime after 2 is 3

		// Search for any prime factor between 2 and root(n)
		while((_prime) && (oddP <= rootN))
		{
			_prime = ((n % oddP) != 0);
			oddP = oddP + 2; // Pick the next possible odd (prime) factor
		}

		return(_prime);
	}
}


template <class Type>
Type getNumber(char * msg, /* limits */ Type LowerLimit, Type UpperLimit)
/*	Definition:	Get a number within the specified limits: lower limit, min,
				and upper limit, max.

	Inputs:		1.	message, msg, to display to the user
				2.	limits: min and max

	Outputs:	The integer number, num, min <= num <= max.
*/
{
	Type num;

	do
	{
		std::cout << msg << " [" << LowerLimit << ".." << UpperLimit << "] ";
		std::cin >> num;
	}
	while (!WithinLimits(num, LowerLimit, UpperLimit));

	return(num);
}


template <class Type>
Type getNumber(char * msg, char LowerOrUpperLimit, Type Limit)
/*	Definition:	Get a number within the specified limit of the upper or lower 
				bound of the defined limit, Limit.

	Inputs:		1.	message, msg, to display to the user
				2.	a character to indicate the type of the bound:
					'L' = lower bound, 'U' = upper bound
				3.	the limit value, Limit

	Outputs:	The integer number, num, satisfying the Limit value
*/
{
	Type num;

	do
	{
		std::cout << msg;
		switch(LowerOrUpperLimit)
		{
			case 'l':
			case 'L':	std::cout << " >= " << Limit << " "; break;
				
			case 'u':
			case 'U':	std::cout << " <= " << Limit << " "; break;

			default:	std::cout << " ";
		}
		std::cin >> num;
	}
	while (!WithinLimits(num, Limit, LowerOrUpperLimit));

	return(num);

}


template <class Type>
bool WithinLimits(Type num, Type LowerLimit, Type UpperLimit)
{
	return((num >= LowerLimit) && (num <= UpperLimit));
}



template <class Type>
bool WithinLimits(Type num, Type Limit, char LowerOrUpperLimit)
{
	switch(LowerOrUpperLimit)
	{
			case 'l':
			case 'L':	return(num >= Limit);
				
			case 'u':
			case 'U':	return(num <= Limit);
				
			default:	return(true);
	}
}


long double * sum(long double num1, long double num2, long double step)
//	Definition:	sum(...) computes the sum of all the numbers
//				between the first number, num1, and the last number, num2.
//				The numbers are step units apart.
//
//	Inputs:		1.	The two numbers marking the interval, num1 and num2
//				2.	The incremental step size, step
//
//	Outputs:	1.	The sum: num1 + num1+step + ... + N, N <= num2
//				2.	The total count, count, for the numbers added
{
	long double	sum = 0;
	long int count = 0;

	long double * output = new long double[2];	// output will be 2 things: sum and count

	if (num1 > num2)
	{
		// swap the two integers:
		long double tempStore = num1;
		num1 = num2;
		num2 = tempStore;
	}
	
	if (step < 0)
		step = (-1) * step;

	while (num1 <= num2)
	{
		sum += num1;
		num1 += step;
		count = count + 1;
	}

	output[0] = sum;	// First output pair is the sum
	output[1] = count;	// Second output pair is the count

	return(output);
}


long double sum(long double * Array, long int Length)
/*
	Definition: sum(...), returns the sum of the elements of the given array.

	Inputs:		1.	The array to be summed, Array.
				2.	The length of the array, Length.

	Outputs:	1.	The sum of the elements in the given array.
*/
{
	long double TempSum = 0;

	for(long int i = 0; i < Length; i++)
	{
		TempSum += Array[i];
	}

	return TempSum;
}


long double * input(long int & Length)
/*
	Definition: InputArray(...), allows user to enter all elements of the given array.

	Inputs:		1.	The array to be populated, Array, given by reference
				2.	The length of the array, Length.

	Outputs:	1.	The array is populated accordingly
				2.	The length of the array is set, as a side effect of pass by reference
*/
{	std::cout << "Enter the Array Length => ";
	std::cin >> Length;

	if (Length <= 0)
		Length = 1;

	long double * Array = new long double[Length];

	for(long int i = 0; i < Length; i++)
	{
		std::cout << "Enter Array[" << i+1 << "] ";
		std::cin >> Array[i];
	}

	return Array;
}


void print(long double * Array, long int Length)
/*
	Definition: print(...), prints the given array on the screen. The elements are
				enclosed in set braces and separated by commas: {x1, x2, x3, ..., xN}

	Inputs:		1.	The array to be printed, Array.
				2.	The length of the array, Length.

	Outputs:	1.	The array is displayed as: {x1, x2, x3, ..., xN}
*/
{
	std::cout << "{";
	for(long int i = 0; i < Length; i++)
	{
		std::cout << Array[i];
		if (i < Length - 1)
			std::cout << ", ";
	}
	std::cout << "}\n";
}


long double average(long double * Array, long int Length)
/*
	Definition: average(...), returns the average of the elements of the given array.
				The average(...) function is built as a composition of the sum(...) function
				and the division function.

	Inputs:		1.	The array to take average of, Array.
				2.	The length of the array, Length.

	Outputs:	1.	The average of the elements in the given array.
*/
{
	if (Length > 0)
		return sum(Array, Length) / Length;	//	Composition of the sum and division functions
	else
		return 0;
}


long double * square(long double * Array, long int Length)
/*
	Definition: square(...), returns a new array whose elements are squares of the corresponding
				elements of the input array.
				
	Inputs:		1.	The array to square the elements of, Array.
				2.	The length of the array, Length.

	Outputs:	1.	The new array whose elements are the squares of the corresponding
					elements of the input array.
*/
{
	if (Length <= 0)
		Length = 1;

	long double * TempArray = new long double[Length];	//	Create a new array to store the squares
	
	for(long int i = 0; i < Length; i++)
	{
		TempArray[i] = Array[i] * Array[i];
	}

	return TempArray;	//	return the array of squares
}

long double * minus(long double * Array1, long double * Array2, long int Length)
/*
	Definition: minus(...), returns a new array whose elements are the elements of Array1 - Array2
				
	Inputs:		1.	The two input arrays, Arra1 and Array2
				2.	The length of the two arrays, Length.

	Outputs:	1.	The new array: Array1 - Array2
*/
{
	if (Length <= 0)
		Length = 1;

	long double * TempArray = new long double[Length];
	
	for(long int i = 0; i < Length; i++)
	{
		TempArray[i] = Array1[i] - Array2[i];
	}

	return TempArray;	//	return the difference array
}

long double * plus(long double * Array1, long double * Array2, long int Length)
/*
	Definition: plus(...), returns a new array whose elements are the addition of the corresponding
				elements of the input arrays: Array1 + Array2.
				
	Inputs:		1.	The two input arrays, Array1 and Array2
				2.	The length of the arrays, Length.

	Outputs:	1.	The new array: Array1 + Array2.
*/
{
	if (Length <= 0)
		Length = 1;

	long double * TempArray = new long double[Length];
	
	for(long int i = 0; i < Length; i++)
	{
		TempArray[i] = Array1[i] + Array2[i];
	}

	return TempArray;
}

long double * times(long double * Array1, long double * Array2, long int Length)
/*
	Definition: times(...), returns a new array whose elements are the multiplication
				of the corresponding elements of the two input arrays, Array1 and Array2
				elements of the input array.
				
	Inputs:		1.	The two input arrays, Array1 and Array2.
				2.	The length of the arrays, Length.

	Outputs:	1.	The new array which is the vector multiplication of Array1 and Array2.
*/
{
	if (Length <= 0)
		Length = 1;

	long double * TempArray = new long double[Length];
	
	for(long int i = 0; i < Length; i++)
	{
		TempArray[i] = Array1[i] * Array2[i];
	}

	return TempArray;
}

long double mod(long double * Array, long int Length)
/*
	Definition: mod(...), computes and returns the Euclidian Norm of the given array.

				The mod(...) function is built as a composition of the following functions:
				
				1.	The sqrt(...) function
				2.	The sum(...) function
				3.	The square(...) function.
				
	Inputs:		1.	The array to compute the norm of, Array.
				2.	The length of the array, Length.

	Outputs:	1.	The Euclidian Norm of the given array.
*/
{
	return sqrt(sum(square(Array, Length), Length));	//	Composition of: sqrt, sum and square
}


long double mod(long double * Array1, long double * Array2, long int Length)
/*
	Definition: mod(...), polymorphic. It computes and returns the Euclidian Norm of
				the two vectors: Array1 and Array2 (of the same length).

				The mod(...) function is built as a composition of the following functions:
				
				1.	The sqrt(...) function
				2.	The sum(...) function
				3.	The square(...) function and
				4.	The minus(...) function
				
	Inputs:		1.	The two arrays, Array1 and Array2, to compute |Array1-Array2|.
				2.	The length of the arrays, Length.

	Outputs:	1.	The Euclidian Norm between the two arrays, |Array1-Array2|.
*/
{
	return sqrt(sum(square(minus(Array1, Array2, Length), Length), Length));
}


long double * modify(long double * Array, long int Length, /* with */ long double value, char operation)
/*
	Definition: modify(...), function computes and returns the new array whose elements are computed
				from the input array, Array, as follows: Each element of Array is modified by the given
				value, value, according to the given instruction, operation. For example, if operation = '-',
				then each value will be subtracted from each element of Array.
				
	Inputs:		1.	The input array, Array.
				2.	The length of the array, Length.
				3.	The modifier, value
				4.	The instruction, operation, the default being '\0', meaning just assign value to Array[i]

	Outputs:	1.	The modified array using the value and the instruction
*/
{
	
	if (Length <= 0)
		Length = 1;

	long double * TempArray = new long double[Length];
	
	for(long int i = 0; i < Length; i++)
	{
		switch(operation)
		{
			case '^':	TempArray[i] = power(Array[i], value); break;
			case '-':	TempArray[i] = Array[i] - value; break;
			case '+':	TempArray[i] = Array[i] + value; break;
			case '/':	TempArray[i] = Array[i] / value; break;
			case '*':	TempArray[i] = Array[i] * value; break;
			default :	TempArray[i] = value;
		}
	}

	return TempArray;
}


long double variance(long double * Array, long int Length)
/*
	Definition: variance(...), function computes and returns the variance of the numbers in the given
				array.
				
	Inputs:		1.	The input array, Array.
				2.	The length of the array, Length

	Outputs:	1.	The variance of the numbers in the array.
*/
{
	long double * MeanArray = modify(Array, Length, average(Array, Length));
	return sqrt(sum(square(minus(MeanArray, Array, Length), Length), Length));
}


long double std_dev(long double * Array, long int Length)
/*
	Definition: std(...), function computes and returns the standard deviation of the numbers
				n the given array.
				
	Inputs:		1.	The input array, Array.
				2.	The length of the array, Length

	Outputs:	1.	The standard deviation of the numbers in the array.
*/
{
	long double Average = average(Array, Length);

	if (Average < 0)
		Average = (-1) * Average;

	if (Average > 0)
		return variance (Array, Length) / Average;
	else
		return 0;
}


long double dot(long double * Array1, long double * Array2, long int Length)
/*
	Definition: dot(...), function computes the dot product between the two arrays: Array1 and
				Array2.
				
	Inputs:		1.	The input arrays, Array1 and Array2.
				2.	The length of the array, Length

	Outputs:	1.	The dot product: Array1.Array2
*/
{
	return sum(times(Array1, Array2, Length), Length);
}

/*-------------------------------------------------------------------------*/

#endif // End Definition of _NUMBER_FUNCTIONS_

/*
int main()
{
	long double x; int dec;

	std::cout << "Enter number to round up "; std::cin >> x;
	std::cout << "Enter number of dec to round upto "; std::cin >> dec;
	
	std::cout << x << " rounded up to " << dec << " decimal places = " << round(x, dec) << "\n";
	return 1;
}
*/

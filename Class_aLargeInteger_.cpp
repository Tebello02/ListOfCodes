#include <iostream>
#include <fstream>

#if !defined _A_LARGE_INTEGER_
#define _A_LARGE_INTEGER_

using namespace std;
/*
FILE NAME: Class{aLargeInteger}.cpp
AUTHOR: Mofana Mphaka
FUNCTION:

  This class is intended to augment the C++ long int. Approximately, the C++ long int has the
  range of 10 digits or so. Thus, this class was meant to cross that 10 digits barrier line so
  that users can have arbitrarily long integers, as long as the computer memory can handle.

(C) mofana mphaka; May 2019
*/


//	C l a s s   I n t e r f a c e

class aLargeInteger
{
	//	F r i e n d   O p e r a t o r s

	friend istream& operator >> (istream & input, aLargeInteger & right);
	/*	Inputs a large integer on the right, a digit at the time, via standard input stream e.g. cin >> X */

	friend ostream& operator << (ostream & output, aLargeInteger right);
	/*	Outputs a large integer on the right on the standard output stream e.g. cout << X */

	friend fstream& operator >> (fstream & input, aLargeInteger & right);
	/*	Reads a large integer from a binary file stream. E.g. file >> X */

	friend fstream& operator << (fstream & output, aLargeInteger right);
	/*	Writes a large integer to a binary file. E.g. file << X */

	friend	aLargeInteger operator + (long int left, aLargeInteger right);
	/*	It adds the integer on the left with the large integer on the right	*/

	friend	aLargeInteger operator - (long int left, aLargeInteger right);
	/*	It subtracts from the integer on the left the large integer on the right	*/

	friend	aLargeInteger operator * (long int left, aLargeInteger right);
	/*	It multiplies the digit on the left with the large integer on the right	*/

	friend	aLargeInteger operator / (long int left, aLargeInteger right);
	/*	It divides the integer on the left with the large integer on the right	*/

	friend	aLargeInteger operator % (long int left, aLargeInteger right);
	/*	It returns the remainder when left / right	*/

	friend	aLargeInteger operator ^ (long int left, aLargeInteger right);
	/*	It returns left raised to power right	*/


	friend bool operator == (long int left, aLargeInteger right);
		/*	It returns true if left == right, false otherwise	*/

	friend bool operator != (long int left, aLargeInteger right);
		/*	It returns true if left != right, false otherwise	*/

	friend bool operator >= (long int left, aLargeInteger right);
		/*	It returns true if left >= right, false otherwise	*/

	friend bool operator <= (long int left, aLargeInteger right);
		/*	It returns true if left <= right, false otherwise	*/

	friend bool operator > (long int left, aLargeInteger right);
		/*	It returns true if left > right, false otherwise	*/

	friend bool operator < (long int left, aLargeInteger right);
		/*	It returns true if left == right, false otherwise	*/


	//	F r i e n d   F u n c t i o n s

	friend void right_justify(aLargeInteger & left, aLargeInteger & right);
	/*	Right align the two integers. NB: except for a few cases, integer arithmetic
		requires that integers be right justified. E.g. aligning 1234 with 12 produces: 1234 and 0012
	*/

	friend void left_justify(aLargeInteger & left, aLargeInteger & right);
	/*	Left align the two integers. E.g. aligning 1234 with 12 produces: 1234 and 1200	*/

	friend aLargeInteger copy(aLargeInteger x);
	/*	It copies x to a large integer y on the left. i.e. y = copy(x)	*/

	friend aLargeInteger power(long int n, aLargeInteger x);
	/*	It raises n to power x, x is a large integer	*/

	friend aLargeInteger power(aLargeInteger x, long int n);
	/*	It raises x to power n, x is a large integer	*/

	friend aLargeInteger power(aLargeInteger x, aLargeInteger n);
	/*	It raises x to power n, x and n are large integers	*/

	friend aLargeInteger factorial(aLargeInteger n);
	/*	It computes the factorial of n	*/

	friend aLargeInteger sqrt(aLargeInteger n);
	/*	It computes the square root of the large integer n	*/

	friend aLargeInteger root(aLargeInteger x, long int n);
	/*	It computes the nth root of this lager integer x.	*/

	friend aLargeInteger root(long int x, aLargeInteger n);
	/*	It computes the nth root of this lager integer x.	*/

	friend bool prime(aLargeInteger n);
	/*	It returns true is this large integer n is prime, false otherwise	*/


	private:
		long int length;	//	The number of digits of this large integer
		int	* digit;		//	The array holding the actual digits of this large integer
		int sign;			//	The integer sign: 1 = positive, -1 = negative


	public:

		//	M e m b e r   O p e r a t o r s

		bool operator > (aLargeInteger right);
		/*	It compares the two large integers: this (on the left) and right.
			It returns true if this integer is bigger than the right integer, false otherwise
		*/

		bool operator > (long int right);
		/*	It returns true if this > right, false otherwise	*/

		bool operator == (aLargeInteger right);
		/*	It returns true if this == right, false otherwise	*/

		bool operator == (long int right);
		/*	It returns true if this == right, false otherwise	*/

		bool operator >= (aLargeInteger right);
		/*	It returns true if this >= right, false otherwise	*/

		bool operator >= (long int right);
		/*	It returns true if this >= right, false otherwise	*/

		bool operator < (aLargeInteger right);
		/*	It returns true if this < right, false otherwise	*/

		bool operator < (long int right);
		/*	It returns true if this < right, false otherwise	*/

		bool operator <= (aLargeInteger right);
		/*	It returns true if this <= right, false otherwise	*/

		bool operator <= (long int right);
		/*	It returns true if this <= right, false otherwise	*/

		bool operator != (aLargeInteger right);
		/*	It returns true if this != right, false otherwise	*/

		bool operator != (long int right);
		/*	It returns true if this != right, false otherwise	*/

		aLargeInteger operator = (aLargeInteger right);
		/*	It assigns the value of the right integer to this one on the left. E.g. X = right	*/

		aLargeInteger operator = (long int right);
		/*	It assigns the value of the integer on right to this large integer on the left. E.g. X = integer
			That is, it type casts a C++ long int to a large integer
		*/

		int operator [] (long int i);
		/*	It returns the i-th digit of this large integer, i.e digit = X[i] */

		aLargeInteger operator + (aLargeInteger right);
		/*	It adds the two large integers: this on the left and the one on the right. E.g X + Y	*/

		aLargeInteger operator + (long int right);
		/*	It adds this large integer with the integer on the right	*/

		aLargeInteger operator += (aLargeInteger right);
		/*	It returns left = left + right	*/

		aLargeInteger operator += (long int right);
		/*	It returns left = left + right	*/

		aLargeInteger operator - (aLargeInteger right);
		/*	It subtracts the large integer on the right from this large integer on the left. E.g. X - Y	*/

		aLargeInteger operator - (long int right);
		/*	It subtracts the integer on the right from this large integer on the left	*/

		aLargeInteger operator -= (aLargeInteger right);
		/*	It returns left = left - right	*/

		aLargeInteger operator -= (long int right);
		/*	It returns left = left - right	*/


		aLargeInteger operator * (long int right);
		/*	Scalar multiplication: It multiplies this large integer with the given integer on the right	*/

		aLargeInteger operator * (aLargeInteger right);
		/*	It multiplies the two large integers: this on the left and the one on the right. E.g X * Y	*/

		aLargeInteger operator *= (aLargeInteger right);
		/*	It returns left = left * right	*/

		aLargeInteger operator *= (long int right);
		/*	It returns left = left * right digit	*/


		aLargeInteger operator ^ (long int right);
		/*	It returns this large integer (on the left) raised to power right integer */

		aLargeInteger operator ^ (aLargeInteger right);
		/*	It returns this large integer raised to power large integer right */


		aLargeInteger operator / (aLargeInteger right);
		/*	Integer division: this left integer / right integer. E.g. 9 / 2 = 4 and 9 / 5 = 1, etc	*/

		aLargeInteger operator / (long int right);
		/*	Integer division: this large integer / right	*/

		aLargeInteger operator /= (aLargeInteger right);
		/*	It returns left = left / right	*/

		aLargeInteger operator /= (long int right);
		/*	It returns left = left / right digit	*/


		aLargeInteger operator % (aLargeInteger right);
		/*	It returns the remainder when this / right	*/

		aLargeInteger operator % (long int right);
		/*	It returns the remainder when this / right (integer)	*/


		void operator ++ (int dummyArgument);
		/*	Post increment a large integer X by 1, i.e. X++.	*/

		void operator -- (int dummyArgument);
		/*	Post decrement a large integer X by 1, i.e.X--.	*/


		//	M e m b e r   f u n c t i o n s   a n d   C o n s t r u c t o r s

		aLargeInteger(long int _Length = 1);
		/*	The set constructor: it creates a large integer with digit array of size _length.
			The default length = 1. The digit array will contain only zeroes and sign = 1.
		*/

		void shift_left(long int shifts);
		/*	It shifts the digits of the given integer to the left. E.g. 12 shifted 3 times becomes 12000	*/

		void shift_right(long int shifts);
		/*	It shifts the digits of the given integer to the right. E.g. 12 shifted 2 times becomes 0012	*/

		void resize(long int _length = 1);
		/*	It resizes this large integer to a new length, _length	*/

		void trim();
		/*	It trims this large integer by skipping leading zeroes	*/

		void reverse();
		/*	It reverses this large integer	*/

		bool prime();
		/*	It returns true if this large integer is prime, false otherwise	*/

		bool positive();
		/*	it returns true if sign > 0, false otherwise	*/

		bool negative();
		/*	it returns true if sign < 0, false otherwise	*/

		bool odd();
		/*	it returns true if this integer is odd, false otherwise	*/

		bool even();
		/*	it returns true if this integer is even, false otherwise	*/


		long int value();
		/*	It typecasts this large integer to C++ long int value	*/

		long int size();
		/*	It returns the length (i.e. the size) of this large integer	*/

		int * digits(long int & _length);
		/*	It returns the digits of this large integer and sets Length to the size of
			the large integer */

		aLargeInteger power(long int n);
		/*	It raises this integer to power n. E.g. X = X.power(2)-- X is squared	*/

		aLargeInteger power(aLargeInteger n);
		/*	It raises this integer to large integer n	*/

		aLargeInteger sqrt();
		/*	It computes the square root of this integer. E.g. X = X.sqrt()	*/

		aLargeInteger root(long int n);
		/*	It computes the nth root of this integer. E.g. X = X.root(3), cube root of X	*/

		aLargeInteger root(aLargeInteger n);
		/*	It computes the nth large integer root of this integer.	*/

		aLargeInteger factorial();
		/*	It computes the factorial of this integer. E.g. X = X.factorial()	*/
};


//	C l a s s   I m p l e m e n t a t i o n

aLargeInteger :: aLargeInteger(long int _length)
{
	length = (_length > 1)? _length : 1;

	digit = new int[length];

	for (long int i = 0; i < length; i++)
		digit[i] = 0;

	sign = 1;	//	0 is a positive integer
}


void aLargeInteger :: resize(long int _length)
{
	long int i, count;

	_length = (_length > 1)? _length : 1;

	if (_length > this->length)
		count = this->length;
	else
		count = _length;

	aLargeInteger newNum(_length);

	for (i = 0; i < count; i++)
		newNum.digit[i] = this->digit[i];

	this->length = _length;
	this->digit = newNum.digit;
}


long int aLargeInteger :: value()
/*	It typecasts this large integer to a C++ long int value	*/
{
	long int c_int = 0,
			 i;	//	count on the ith digit

	for (i = 0; i < length; i++)
		c_int = c_int * 10 + digit[i];

	c_int = sign * c_int;	//	compute the appropriate sign value

	return c_int;
}


long int aLargeInteger :: size()
/*	It returns the length of this large integer	*/
{
	return length;
}


bool aLargeInteger :: positive()
{
	return sign > 0;
}


bool aLargeInteger :: negative()
{
	return sign < 0;
}


bool aLargeInteger :: odd()
{
	return ((*this) % 2 != 0);
}


bool aLargeInteger :: even()
{
	return ((*this) % 2 == 0);
}


int * aLargeInteger :: digits(long int & _length)
/*	It returns the digits of this large integer and sets Length to the size of
	the large integer */
{
	_length = length;

	/*	protect the original digits of this large integer (from possible modification
		by the calling environment) by making a new copy */

	int * newDigit = new int [length];

	for (long int i = 0; i < length; i++)
		newDigit[i] = digit[i];

	return newDigit;	//	return the copy -- not the original digits
}


void aLargeInteger :: trim()
{
	long	int i,
			count = 0;	//	count on leading zeroes

	//	count & skip leading zeroes
	while (this->digit[count] == 0)
		count++;

	//	count counts the number of leading zero digits of this integer
	//	create a new integer to hold the trimmed digits -- length - count
	if (count > 0)
	{
		//	there are leading zero digits -- chop them off
		aLargeInteger trimmedNum(this->length - count);

		//	Now copy the trimmed digits to the new integer
		for (i = 0; (i < trimmedNum.length) && (count < this->length); i++, count++)
			trimmedNum.digit[i] = this->digit[count];

		this->length = trimmedNum.length;
		this->digit = trimmedNum.digit;
	}
}


void aLargeInteger :: shift_left(long int shifts)
{
	aLargeInteger newX(this->length+shifts);

	//	copy the contents of this to newX -- shifted left
	for(long int i = 0; i < this->length; i++)
		newX.digit[i] = this->digit[i];

	this->digit = newX.digit;
	this->length = newX.length;
}


void aLargeInteger :: shift_right(long int shifts)
{
	aLargeInteger newX(this->length+shifts);
	long int i, j;

	//	copy the contents of X to newX -- shifted right
	for(i = this->length - 1, j = newX.length - 1; i >= 0; i--, j--)
		newX.digit[j] = this->digit[i];

	this->digit = newX.digit;
	this->length = newX.length;
}


aLargeInteger aLargeInteger :: power(long int n)
/*	It raises this integer to power n. E.g. X = X.power(2)-- X is squared	*/
{
	aLargeInteger Power;

	if (n <= 0)
		Power = 1;
	else // if (n > 0)
	{
		Power = (*this);

		while(n > 1)
		{
			Power = Power * (*this);
			n--;
		}
	}

	return (Power);
}


aLargeInteger aLargeInteger :: power(aLargeInteger n)
{
	aLargeInteger Power;

	if (n <= 0)
		Power = 1;
	else // if (n > 0)
	{
		Power = (*this);

		while(n > 1)
		{
			Power = Power * (*this);
			n--;
		}
	}

	return (Power);
}


aLargeInteger aLargeInteger :: factorial()
{
	aLargeInteger product, n;

	product = 1, n = (*this);

	while (n > 0)
	{
		product = product * n;
		n--;
	}

	return(product);
}


aLargeInteger aLargeInteger :: sqrt()
/*	It computes the square root of this integer. E.g. X = X.sqrt().
	For a positive integer n, the square root of n, n.sqrt(), is given by
	n.sqrt() = minimum m = 0,1,2,...n such that (m + 1)^2 - n > 0
*/
{
	aLargeInteger m;	//	set m = 0, the first natural integer

	if ((*this) > 0)
		while ((((m + 1) * (m + 1)) - (*this)) <= 0)
			m++;

	return (m);
}


aLargeInteger aLargeInteger :: root(long int n)
/*	It computes the nth root of this integer. E.g. X = X.root(n).

	For a positive integer x, the nth root of x, x.root(n), is given by
	x.root(n) = minimum m = 0,1,2,... x such that (m + 1)^n - x > 0.

	For a negative integer x, the nth root of x, x.root(n), is given by
	if n is odd (i.e. roots for negative integers are possible iff the index is odd)
	x.root(n) = maximum m = -1, -2, -3, ... -x such that m^n - x <= 0.
*/
{
	aLargeInteger m;	//	set m = 0, the first natural integer

	if ( n > 0)
	{
		if ((*this) > 0)
			while (((m + 1).power(n) - (*this)) <= 0)
				m++;
		else	// this integer is negative
		{
			m = -1;	//	start with the maximum negative integer
			if ((n % 2) != 0)	//	only an odd index can produce a negative power
				while ((m.power(n) - (*this)) > 0)
					m--;
		}
	}

	return (m);
}


aLargeInteger aLargeInteger :: root(aLargeInteger n)
{
	aLargeInteger m;

	if ( n > 0)
	{
		if ((*this) > 0)
			while (((m + 1).power(n) - (*this)) <= 0)
				m++;
		else
		{
			m = -1;
			if (n.odd())
				while ((m.power(n) - (*this)) > 0)
					m--;
		}
	}

	return (m);
}


aLargeInteger copy(aLargeInteger x)
{
	aLargeInteger y(x.length);	//	create a new integer = x

	//	then copy the digits of x into y
	for (long int i = 0; i < x.length; i++)
		y.digit[i] = x.digit[i];

	y.sign = x.sign;	//	copy the sign as well

	return y;	//	return a copy of x as y
}


void right_justify(aLargeInteger & left, aLargeInteger & right)
//	Right justify this (integer on the left) with the integer on the right
{
	if (left.length < right.length)
		left.shift_right(right.length - left.length);
	else if (left.length > right.length)
		right.shift_right(left.length - right.length);
}


void left_justify(aLargeInteger & left, aLargeInteger & right)
{
	if (left.length < right.length)
		left.shift_left(right.length - left.length);
	else if (left.length > right.length)
		right.shift_left(left.length - right.length);
}


void aLargeInteger :: reverse()
{
	for(long int i = 0, j = this->length - 1;((i < this->length) && (i < j));(i++, j--))
	{
		int _digit = this->digit[i];
		this->digit[i] = this->digit[j];
		this->digit[j] = _digit;
	}
}


aLargeInteger power(aLargeInteger x, aLargeInteger n)
/*	It raises x to power n, x and n are large integers. n >= 0	*/
{
	aLargeInteger Power;

	if (n <= 0)
		Power = 1;
	else // if (n > 0)
	{
		Power = x;

		while(n > 1)
		{
			Power = Power * x;
			n--;
		}
	}

	return (Power);
}


aLargeInteger power(long int n, aLargeInteger x)
/*	It raises n to power x, x is a large integer	*/
{
	aLargeInteger Power;

	if (x <= 0)
		Power = 1;
	else // if (x > 0)
	{
		Power = n;

		while(x > 1)
		{
			Power = Power * n;
			x--;
		}
	}

	return (Power);
}


aLargeInteger power(aLargeInteger x, long int n)
/*	It raises x to power n, x is a large integer	*/
{
	aLargeInteger Power;

	if (n <= 0)
		Power = 1;
	else //	if (n > 0)
	{
		Power = x;

		while(n > 1)
		{
			Power = Power * x;
			n--;
		}
	}

	return (Power);
}


aLargeInteger factorial(aLargeInteger n)
/*	It computes the factorial of n. n >= 0	*/
{
	aLargeInteger product;

	product = 1;

	while (n > 0)
	{
		product = product * n;
		n--;
	}

	return(product);
}


aLargeInteger sqrt(aLargeInteger n)
/*	It computes the square root of the large integer n	*/
{
	aLargeInteger m;

	if (n > 0)
		while ((((m + 1) * (m + 1)) - n) <= 0)
			m++;

	return (m);
}


aLargeInteger root(aLargeInteger x, long int n)
/*	It computes the nth root of this lager integer x.	*/
{
	aLargeInteger m;

	if ( n > 0)
	{
		if (x > 0)
			while ((power(m + 1, n) - x) <= 0)
				m++;
		else
		{
			m = -1;
			if ((n % 2) != 0)
				while ((power(m, n) - x) > 0)
					m--;
		}
	}

	return (m);
}


aLargeInteger root(long int x, aLargeInteger n)
/*	It computes the nth root of this lager integer x.	*/
{
	aLargeInteger m;

	if ( n > 0)
	{
		if (x > 0)
			while ((power(m + 1, n) - x) <= 0)
				m++;
		else
		{
			m = -1;
			if (n.odd())
				while ((power(m, n) - x) > 0)
					m--;
		}
	}

	return (m);
}


bool prime(aLargeInteger n)
//	Definition: if n is NOT prime then one of its prime factors lie between
//				2 and its square root, n.sqrt(); otherwise n is prime.
{
	if (n == 2) // this large integer is prime -- the least prime = 2
		return(true);

	else if ((n % 2) == 0) // this large integer is even -- cannot be prime
		return(false);

	else
	// Since this large integer is odd, it could be prime. So,
	// do a minimal search for possible primehood or not primehood of it.
	{
		aLargeInteger sqrt, oddP;
		bool _prime = true;
		int nSign = n.sign;
		n.sign = 1;	//	make the integer positive for sqrt() function
		sqrt = n.sqrt();
		oddP = 3; // next odd prime after 2 is 3

		// Search for any prime factor between 2 and sqrt of this large integer
		while((_prime) && (oddP <= sqrt))
		{
			_prime = ((n % oddP) != 0);
			oddP = oddP + 2; // Pick the next possible odd (prime) factor
		}

		n.sign = nSign;	//	Restore the sign of the integer
		return(_prime);
	}
}


bool aLargeInteger :: prime()
{
	if ((*this) == 2)
		return(true);

	else if (((*this) % 2) == 0)
		return(false);

	else
	{
		aLargeInteger sqrt, oddP;
		bool _prime = true;

		int thisSign = this->sign;
		this->sign = 1;
		sqrt = this->sqrt();
		oddP = 3;

		while((_prime) && (oddP <= sqrt))
		{
			_prime = (((*this) % oddP) != 0);
			oddP = oddP + 2;
		}

		this->sign = thisSign;
		return(_prime);
	}
}


bool aLargeInteger :: operator > (aLargeInteger right)
{
	if (this->sign > right.sign)
		return true;	//	A positive integer is bigger than any negative integer
	else if (this->sign < right.sign)
		return false;	//	A negative integer is less than any positive integer
	else	//	this->sign == right.sign, compare the digits
	{
		aLargeInteger thisCopy;

		bool PositiveIntegers = ((this->sign > 0 ) && (right.sign > 0));

		//	Save the original value of this
		thisCopy = (*this);

		right_justify(thisCopy, right);	// will change the size of the shorter integer

		long int i = 0;

		while (i < thisCopy.length)
		{
			if (thisCopy.digit[i] > right.digit[i])
			{
				if (PositiveIntegers)
					return true;	//	this > right, for positive integers
				else
					return false;	//	this < right, for negative integers
			}
			else if (thisCopy.digit[i] == right.digit[i])
				i++;
			else
			{
				if (PositiveIntegers)
					return false;	//	this < right, for positive integers
				else
					return true;	//	this > right, for negative integers
			}
		}

		return false;	//	this == right
	}
}


bool aLargeInteger :: operator > (long int right)
{
	aLargeInteger rightNum;
	rightNum = right;
	return (*this) > rightNum;
}


bool operator > (long int left, aLargeInteger right)
{
	return right < left;
}


bool aLargeInteger :: operator == (aLargeInteger right)
{
	if (this->sign != right.sign)
		return false;	//	Integers with opposite signs cannot be equal
	else	//	similar signs, compare the digits
	{
		aLargeInteger thisCopy;

		thisCopy = (*this);

		right_justify(thisCopy, right);

		for (long int i = 0; i < thisCopy.length; i++)
			if (thisCopy.digit[i] != right.digit[i])
				return false;

		return true;
	}
}


bool aLargeInteger :: operator == (long int right)
{
	aLargeInteger rightNum;
	rightNum = right;
	return (*this) == rightNum;
}


bool operator == (long int left, aLargeInteger right)
{
	return right == left;
}


bool aLargeInteger :: operator >= (aLargeInteger right)
{
	return (*this) > right || (*this) == right;
}


bool aLargeInteger :: operator >= (long int right)
{
	aLargeInteger rightNum;
	rightNum = right;
	return (*this) >= rightNum;
}


bool operator >= (long int left, aLargeInteger right)
{
	return right <= left;
}


bool aLargeInteger :: operator < (aLargeInteger right)
{
	return right > (*this);
}


bool aLargeInteger :: operator < (long int right)
{
	aLargeInteger rightNum;
	rightNum = right;
	return (*this) < rightNum;
}


bool operator < (long int left, aLargeInteger right)
{
	return right > left;
}


bool aLargeInteger :: operator <= (aLargeInteger right)
{
	return right >= (*this);
}


bool aLargeInteger :: operator <= (long int right)
{
	aLargeInteger rightNum;
	rightNum = right;
	return (*this) <= rightNum;
}


bool operator <= (long int left, aLargeInteger right)
{
	return right >= left;
}


bool aLargeInteger :: operator != (aLargeInteger right)
{
	return !((*this) == right);
}


bool aLargeInteger :: operator != (long int right)
{
	aLargeInteger rightNum;
	rightNum = right;
	return (*this) != rightNum;
}


bool operator != (long int left, aLargeInteger right)
{
	return right != left;
}


int aLargeInteger :: operator [] (long int i)
/*	It returns the i-th digit of this large integer, i.e digit = X[i] */
{
	if (i >= length)
		i = length - 1;

	if (i < 0 )
		i = 0;

	return digit[i];
}


aLargeInteger aLargeInteger :: operator = (aLargeInteger right)
{
	this->length = right.length;
	this->sign = right.sign;
	this->digit = new int [right.length];

	for(long int i = 0; i < right.length; i++)
		this->digit[i] = right.digit[i];

	return (*this);
}


aLargeInteger aLargeInteger :: operator = (long int right)
/*	Type cast an integer on the right to a large integer X, i.e. X = integer	*/
{
	long int i = 0;
	int _digit;

	if (right < 0)
	//	this is a negative integer
	{
		this->sign = -1;
		right = (-1) * right;
	}
	else
		this->sign = 1;	//	this is a positive integer

	if (right < 10)
	{
		this->length = 1;
		this->digit = new int [this->length];
		this->digit[0] = right;
	}
	else
	{
		while(right > 0)
		{
			this->resize(i + 1);

			_digit = right % 10;// get the next most significant digit
			right = right / 10;	// get the next integer part

			this->digit[i] = _digit;
			i++;
		}
	}
	// The integer has been converted starting from the least significant digit
	// Thus, it has been reversed. So, reverse the output to the original sequence

	this->reverse();

	return (*this);
}


aLargeInteger aLargeInteger :: operator + (aLargeInteger right)
{
	if ((this->sign < 0) && (right.sign > 0))
	{
		//	-X + (+Y) = +Y - (+X)
		aLargeInteger thisNum;

		thisNum = (*this);
		thisNum.sign = 1;
		return right - thisNum;
	}
	else if ((this->sign > 0) && (right.sign < 0))
	{
		//	+X + (-Y) = +X - (+Y)
		aLargeInteger rightNum;

		rightNum = right;
		rightNum.sign = 1;
		return (*this) - rightNum;
	}
	else	//	Add like signs: -X + (-Y) or +X + (+Y)
	{
		aLargeInteger thisCopy;

		thisCopy = (*this);

		//	Align the integers to be added to the right -- right justify
		right_justify(thisCopy, right);

		//	Now the integers have been right justified
		//	Make space for the sum
		aLargeInteger sum(thisCopy.length + 1);

		long int i = 0;	//	index on digits
		int carry = 0;	//	Initially, carry forward = 0;

		for(i = thisCopy.length - 1; i >=0; i--)
		//	Add starting from the least significant digits
		{
			sum.digit[i+1] = (thisCopy.digit[i] + right.digit[i] + carry) % 10;
			carry = (thisCopy.digit[i] + right.digit[i] + carry) / 10;
		}
		sum.digit[0] = carry;	//	take care of possible overflow carry
		sum.sign = thisCopy.sign;	//	= right.sign

		sum.trim();
		return sum;
	}
}


aLargeInteger aLargeInteger :: operator + (long int right)
/*	Add this large integer with a digit on the right	*/
{
	aLargeInteger rightNum;
	rightNum = right;	// Type cast the digit on the right to a large integer
	return (*this) + rightNum;	//	then add
}


aLargeInteger operator + (long int left, aLargeInteger right)
{
	return right + left;
}


aLargeInteger aLargeInteger :: operator += (aLargeInteger right)
/*	It returns left = left + right	*/
{
	(*this) = (*this) + right;
	return (*this);
}


aLargeInteger aLargeInteger :: operator += (long int right)
/*	It returns left = left + right digit	*/
{
	aLargeInteger rightNum;
	rightNum = right;

	(*this) = (*this) + right;
	return (*this);
}


aLargeInteger aLargeInteger :: operator - (aLargeInteger right)
/*	Subtract the large integer on the right from this large integer on the left
*/
{
	if ((right.sign < 0) && (this->sign > 0))
	{
		//	+X - (-Y) = +X + (+Y)
		aLargeInteger rightNum;

		rightNum = right;
		rightNum.sign = 1;
		return (*this) + rightNum;	//	subtraction has been reduced to addition
	}
	else if ((right.sign > 0) && (this->sign < 0))
	{
		//	-X - (+Y) = -X + (-Y)
		aLargeInteger rightNum;

		rightNum = right;
		rightNum.sign = -1;
		return (*this) + rightNum;	//	Add the two negative integers
	}
	else
	{
		aLargeInteger thisCopy, left;

		thisCopy = (*this);

		right_justify(thisCopy, right);

		aLargeInteger newNum(thisCopy.length);

		left = thisCopy;

		if ((right.sign < 0) && (thisCopy.sign < 0))
		{
			//	-X - (-Y) = +Y - (+X)

			left = right;
			left.sign = 1;	//	+Y
			right = thisCopy;
			right.sign = 1;	//	+X
		}


		if (left < right)
		{
			//	Swap left with right and subtract the smaller integer from the larger one
			aLargeInteger tempNum;

			newNum.sign = -1;	//	the result is negative since we subtract the bigger integer
			tempNum = left;
			left = right;
			right = tempNum;
		}
		else
			newNum.sign = 1;	//	left >= right, sum is >= 0.

		long int i;

		//	Here left >= right. So, carry out the subtraction: left - right
		for (i = (left.length - 1); i >= 0; i--)
		{
			//	Fix the anomaly when a borrow was made from a digit whose value was zero
			//	The fix is:
			//	1. make this digit 9 and
			//	2. decrement the higher digit by 1
			if (left.digit[i] < 0)
			{
				left.digit[i] = 9;
				left.digit[i-1]--;
			}

			// Now subtract with a borrow
			if (left.digit[i] >= right.digit[i])
				newNum.digit[i] = left.digit[i] - right.digit[i];
			else
			{
				//	borrow from digit[i-1]
				//	i.e. 1. digit(i-1) = digit(i-1) - 1
				//		 2. digit(i) = digit(i) + 10
				//		 3. Then subtract
				left.digit[i-1]--;
				newNum.digit[i] = left.digit[i] + 10 - right.digit[i];
			}
		}

		newNum.trim();
		return newNum;
	}
}


aLargeInteger aLargeInteger :: operator - (long int right)
/*	Subtract the digit on the right from this large integer on the left	*/
{
	aLargeInteger rightNum;
	rightNum = right;
	return (*this) - rightNum;
}


aLargeInteger operator - (long int left, aLargeInteger right)
{
	aLargeInteger leftNum;
	leftNum = left;
	return leftNum - right;
}


aLargeInteger aLargeInteger :: operator -= (aLargeInteger right)
/*	It returns left = left - right	*/
{
	(*this) = (*this) - right;
	return (*this);
}


aLargeInteger aLargeInteger :: operator -= (long int right)
/*	It returns left = left - right digit	*/
{
	aLargeInteger rightNum;
	rightNum = right;

	(*this) = (*this) - right;
	return (*this);
}


aLargeInteger aLargeInteger :: operator * (long int right)
/*	Do full multiplication: scalar or array multiplication
*/
{
	int scalarSign;

	if (right < 0)
	{
		scalarSign = -1;	//	this right integer is negative
		right = scalarSign * right;	//	make the digits positive, for multiplication
	}
	else
		scalarSign = 1;	//	this right integer is positive

	if (right >= 10)
	{
		/*	If the right integer is more than 1 digit then
			typecast it to a large integer and perform the usual array multiplication
			on the two integers: this and right
		*/
		aLargeInteger rightNum;

		rightNum = right;
		rightNum.sign = scalarSign;
		return (*this) * rightNum;	//	full array multiplication
	}
	else
	{
		/*	If the right integer is a digit then
			perform a simple scalar multiplication of the digit array
		*/
		aLargeInteger product(this->length + 1);

		int carry = 0;
		long int i = 0;

		for(i = this -> length - 1; i >=0; i--)
		{
			product.digit[i+1] = (this->digit[i] * right + carry) % 10;
			carry = (this->digit[i] * right + carry) / 10;
		}
		product.digit[0] = carry;
		product.sign = this->sign * scalarSign;

		product.trim();
		return product;
	}
}


aLargeInteger aLargeInteger :: operator * (aLargeInteger right)
/*	Full array muliplication */
{
	long int shifts = 0, J;
	aLargeInteger product, productJ;

	for (J = right.length - 1; J >= 0; J--)
	{
		productJ = (*this) * right.digit[J];
		productJ.shift_left(shifts);
		productJ.sign = 1;	//	All partial products J are treated as positive

		product = product + productJ;
		shifts++;
	}

	//	Compute the appropriate sign for the multiplication
	product.sign = this->sign * right.sign;

	return product;
}


aLargeInteger operator * (long int left, aLargeInteger right)
{
	return right * left;
}


aLargeInteger aLargeInteger :: operator *= (aLargeInteger right)
/*	It returns left = left * right	*/
{
	(*this) = (*this) * right;
	return (*this);
}


aLargeInteger aLargeInteger :: operator *= (long int right)
/*	It returns left = left * right digit	*/
{
	aLargeInteger rightNum;
	rightNum = right;

	(*this) = (*this) * right;
	return (*this);
}


aLargeInteger operator ^ (long int left, aLargeInteger right)
/*	It raises the integer left to power right, right is a large integer	*/
{
	return power (left, right);
}


aLargeInteger aLargeInteger :: operator ^ (long int right)
/*	It raises this large integer to power right integer	*/
{
	return this->power(right);
}


aLargeInteger aLargeInteger :: operator ^ (aLargeInteger right)
/*	It raises *this large integer to power large integer on the right	*/
{
	return this->power(right);
}


aLargeInteger aLargeInteger :: operator / (aLargeInteger right)
/*	For positive integers X and Y, X / Y is defined as:
	the least m = 0, 1, 2, ... x such that (m + 1)y > x
*/
{
	//	start from 0
	aLargeInteger m; //	Constructor sets m to 0

	int thisSign = 1, rightSign = 1;

	//	make the enumerator and denominator positive, for iteration
	if (this->sign < 0)
	{
		thisSign = -1;
		this->sign = 1;
	}
	if (right.sign < 0)
	{
		rightSign = -1;
		right.sign = 1;
	}

	//	Then do the minimal search for X / Y (i.e. X and Y are now positive)
	if (right > 0)
		while((*this) >= ((m + 1) * right))
			m++;

	this->sign = thisSign;	//	pointer reference is persistent -- restore this sign
	right.sign = rightSign;

	m.sign = thisSign / rightSign;

	return m;
}


aLargeInteger aLargeInteger :: operator / (long int right)
{
	aLargeInteger rightNum;
	rightNum = right;
	return (*this) / rightNum;
}


aLargeInteger operator / (long int left, aLargeInteger right)
{
	aLargeInteger leftNum;
	leftNum = left;
	return leftNum / right;
}


aLargeInteger aLargeInteger :: operator /= (aLargeInteger right)
/*	It returns left = left / right	*/
{
	(*this) = (*this) / right;
	return (*this);
}


aLargeInteger aLargeInteger :: operator /= (long int right)
/*	It returns left = left / right digit	*/
{
	aLargeInteger rightNum;
	rightNum = right;

	(*this) = (*this) / right;
	return (*this);
}


aLargeInteger aLargeInteger :: operator % (aLargeInteger right)
{
	aLargeInteger quotient, remainder;

	quotient = (*this) / right;
	remainder = (*this) - (right * quotient);

	return remainder;
}


aLargeInteger aLargeInteger :: operator % (long int right)
{
	aLargeInteger rightNum;
	rightNum = right;

	return (*this) % rightNum;
}


aLargeInteger operator % (long int left, aLargeInteger right)
{
	aLargeInteger leftNum;
	leftNum = left;

	return leftNum % right;
}


void aLargeInteger :: operator ++ (int dummyArgument)
/*	Post increment a large integer X by 1, i.e. X++.	*/
{
	(*this) = (*this) + 1;
}


void aLargeInteger :: operator -- (int dummyArgument)
/*	Post decrement a large integer X by 1, i.e.X--.	*/
{
	(*this) = (*this) - 1;
}


bool is_sign(char ch)
{
	return ((ch == '+') || (ch == '-'));
}


bool is_digit(char ch)
{
	switch(ch)
	{
		case '0' :
		case '1' :
		case '2' :
		case '3' :
		case '4' :
		case '5' :
		case '6' :
		case '7' :
		case '8' :
		case '9' : return(true);
		default : return(false);
	}
}


int ch_to_digit(char ch)
{
	switch(ch)
	{
		case '0' : return(0);
		case '1' : return(1);
		case '2' : return(2);
		case '3' : return(3);
		case '4' : return(4);
		case '5' : return(5);
		case '6' : return(6);
		case '7' : return(7);
		case '8' : return(8);
		case '9' : return(9);
		default : return(0);
	}
}


istream& operator >> (istream & input, aLargeInteger & right)
{
	//	Character constants
	char	new_line = char(10),
			back_space = char(8),
			ch;

	long int i = 0;	//	count on the number of digits of the large integer

	//	Guard against buffered input -- always scan input one character ahead
	ch = getchar();

	right.sign = 1;	//	assume the integer to be positive
	do
	{
		if ((ch != back_space) && (ch != new_line) && (is_digit(ch) || is_sign(ch)))
		{
			if (is_sign(ch) && (i <= 0))	//	the leading character is a sign +/-, accept it
			{
				if (ch == '-')
					right.sign = -1;
				else
					right.sign = 1;
			}
			else if (is_digit(ch))	//	one more digit, accept it
			{
				right.resize(i+1);
				right.digit[i] = ch_to_digit(ch);
				i++;
			}
		}
		else if (ch == back_space)
		{
			//	delete the integer backwards
			if (i > 0)
			{
				i--;
				right.resize(i);
			}
		}

		//	scan the next digit from the keyboard

		ch = getchar();
	}
	while (ch != new_line);

	right.trim();
	return input;
}


ostream& operator << (ostream & output, aLargeInteger right)
{
	if (right.sign < 0)
		output << "-";

	for (long int i = 0; i < right.length; i++)
		output << right.digit[i];

	return output;
}


fstream& operator >> (fstream & input, aLargeInteger & right)
{
	//	Assume the stream is opened

	//	Read the size of the integer first
	if (input.good())
		input.read((char *) & right.length, sizeof(right.length));

	//	then read the sign
	if (input.good())
		input.read((char *) & right.sign, sizeof(right.sign));

	right.digit = new int[right.length]; // allocate memory for incoming digits

	//	and, finally read the whole integer a digit at a time
	for(long int i = 0; (i < right.length) && input.good(); i++)
		input.read((char *) & right.digit[i], sizeof(right.digit[i]));

	right.trim();
	return input;
}


fstream& operator << (fstream & output, aLargeInteger right)
{
	//	Assume the stream is opened

	//	Write the size of the integer first
	if (output.good())
		output.write((char *) & right.length, sizeof(right.length));

	//	then write the sign
	if (output.good())
		output.write((char *) & right.sign, sizeof(right.sign));

	//	and, finally write the whole integer a digit at a time
	for(long int i = 0; (i < right.length) && output.good(); i++)
		output.write((char *) & right.digit[i], sizeof(right.digit[i]));

	return output;
}


#endif
/*
int main()
{
	aLargeInteger X;// = 20;
	std::cout << "X = "  << X << "\n";
	std::cout << "Enter any large number to print its factorial = > " ;
	std::cin >> X;

	std::cout << "X = " << X << "\n";
	std::cout << X << "! = " << X.factorial() << "\n";

	if (X.prime())
		std::cout << "\nAnd also " << X << " is prime\n";
	else
	{
		std::cout << X << " is not a prime number\n";

		if (X.even())
			std::cout << X << " is an even number\n";
		else
			std::cout << X << " is an odd number\n";
	}

	return 1;
}
*/

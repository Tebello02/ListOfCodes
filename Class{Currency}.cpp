/*
	NAME: Class{Currency}.cpp
	FUNCTION:

	This library file implements currency as a class. Currency primitives like displaying
	money in standard form like M1,124,000.00, setting values to money variables and
	comparing money variable are implemented.

	(C) mofana mphaka; March 2007
		Edited: June 2021
*/


#include <c:\users\mofan\OneDrive\Documents\CS2432{OOP}\programs\String{Functions}.cpp>

#ifndef _CURRENCY_CLASS_
#define _CURRENCY_CLASS_

class currency
{
	//	F r i e n d   O p e r a t o r s

	//	I n p u t / o u t p u t

	friend std::istream & operator >> (std::istream & input, currency & money);
	/*	Inputs the currency variable, money, from the standard input stream */

	friend std::ostream & operator << (std::ostream & output, currency money);
	/*	Outputs the currency variable, money, onto the standard output stream */

	//	A r i t h m e t i c

	friend currency operator + (double left, currency right);
	/*	Adds the number on the left with the currency variable on the right */


	friend currency operator - (double left, currency right);
	/*	Subtracts the currency variable on the right from the number on the left */

	friend currency operator * (double left, currency right);
	/*	Multiplies the number on the left with the currency on the right*/


	friend currency operator / (double left, currency right);
	/*	Divides the number on the left with the currency on the right*/
	

	//	R e l a t i o n a l

	friend bool operator > (double left, currency right);
	/*	Returns true if the number on the left is larger than the value of the currency
		on the right, false otherwise*/

	friend bool operator < (double left, currency right);
	friend bool operator == (double left, currency right);
	
	friend bool operator >= (double left, currency right);
	
	friend bool operator <= (double left, currency right);
	
	friend bool operator != (double left, currency right);


	//	P r i v a t e    D a t a   C o m p o n e n t s

	private:
		double	amount;	//	currency amount
		char	symbol;	//	currency symbol. E.g. $, M, R, etc


	//	P u b l i c    M e m b e r   F u n c t i o n s  /  O p e r a t o r s

	public:

		//	C o n s t r u c t o r s
		
		//	Default constructor
		currency();
		/*	Creates currency object with default values: symbol = 'M', amount = 0*/

		//	Other constructors
		currency(char currencySymbol);
		/*	Creates currency object with currency symbol = currencySymbol, amount = 0*/

		currency(double anAmount);
		/*	Creates currency object with currency amount = anAmount, currency symbol = 'M'*/

		currency(char currencySymbol, double anAmount);
		/*	Creates a currency object with set values:
			currency symbol = currencySymbol and amount = anAmount */


		//	M e m b e r   F u n c t i o n s
		
		//	Set functions

		//	Default Set function
		void set();
		/*	Resets the currency values to defaults: symbol = "M" and amount = 0*/

		//	Other Set functions
		void set(char currencySymbol);
		/*	Sets the currency symbol to the value, currencySymbol. The value of
			currency amount is left as it is */

		void set(double anAmount);
		/*	Sets the currency amount to the value, anAmount. The currency symbol
			is left as it is */

		void set(char currencySymbol, double anAmount);
		/*	Sets the currency symbol to the value, currencySymbol, the currency
			amount to the value, anAmount*/


		//	Input functions
		void input();
		/*	Inputs all the currency values: currency amount and currency symbol,
			interactively, from the user via the keyboard*/

		//	Other Input functions
		void input(char currencySymbol);
		/*	Sets the currency symbol to currencySymbol and reads the currency
			amount, interactively, from the keyboard*/

		void input(double anAmount);
		/*	Sets the currency amount to anAmount and reads the currency
			symbol, interactively, from the keyboard*/

		void input(char currencySymbol, double anAmount);
		/*	Same as set(currencySymbol, anAmount) */
		
		void display();
		/*	Displays currency amount in the standard form. E.g. M1,234,567.00*/

		//	Output Member Functions
		double getCurrencyAmount() { return amount; }
		/*	Avails the value of the currency amount to the calling environment*/

		char getCurrencySymbol() { return symbol; }
		/*	Avails the value of the currency symbol to the calling environment*/

		
		//	M e m b e r    O p e r a t o r s
		
		currency operator = (currency right);
		/*	Assigns the currency on the right to this currency on the left */

		currency operator = (double right);
		/*	Assigns this currency on the left the value of the number on the right*/

		currency operator + (currency right);
		/*	Adds the two currency variables: this and right */

		currency operator + (double right);
		/*	Adds the currency variable on the left (this) with the number on the right */
		
		currency operator += (currency right);
		/*	Returns this = this + right */

		currency operator += (double right);
		/*	Returns this = this + right */


		currency operator - (currency right);
		/*	Subtracts the currency variable on the right from the currency on the left */

		currency operator - (double right);
		/*	Subracts the number on the right from the currency variable on the left*/

		currency operator -= (currency right);
		/*	Returns this = this - right */

		currency operator -= (double right);
		/*	Returns this = this - right */

		currency operator * (currency right);
		/*	Multiplies currency on the left with currency on the right of the operator*/

		currency operator * (double right);
		/*	Multiplies currency on the left with the number on the right */

		currency operator *= (currency right);
		/*	Returns this = this * right */

		currency operator *= (double right);
		/*	Returns this = this * right */


		currency operator / (currency right);
		/*	Divides the currency on the left with the currency on the right*/

		currency operator / (double right);
		/*	Divides the currency on the left with the number on the right*/

		currency operator /= (currency right);
		/*	Returns this = this / right */

		currency operator /= (double right);
		/*	Returns this = this / right */
		
		bool operator > (currency right);
		/*	Returns true if currency on the left is larger than the currency on the right.
			It returns false otherwise*/

		bool operator > (double right);
		/*	Returs true/false depending on whether the currency value on the left is bigger
			than the number on the right*/
	
		bool operator < (double right);

		bool operator == (currency right);
		bool operator < (currency right);
		bool operator == (double right);

		bool operator >= (currency right);
		bool operator >= (double right);

		bool operator <= (currency right);
		bool operator <= (double right);

		bool operator != (currency right);
		bool operator != (double right);
};


currency :: currency()
{
	amount = 0;
	symbol = 'M';
}

currency :: currency(char currencySymbol)
{
	amount = 0;
	symbol = upcase(currencySymbol);
}


currency :: currency(double anAmount)
{
	amount = anAmount;
	symbol = 'M';
}

currency :: currency(char currencySymbol, double anAmount)
{
	amount = anAmount;
	symbol = upcase(currencySymbol);
}


void currency :: set()
{
	amount = 0;
	symbol = 'M';
}


void currency :: set(char currencySymbol)
{
	symbol = upcase(currencySymbol);
	// amount = whatever value that was set before
}


void currency :: set(double anAmount)
{
	amount = anAmount;
	// symbol = whatever value that was set before
}


void currency :: set(char currencySymbol, double anAmount)
{
	amount = anAmount;
	symbol = upcase(currencySymbol);
}


void currency :: input()
{
	std::cout << "Enter Amount ";
	std::cin >> amount;
	std::cout << "Enter Currency Symbol ";
	std::cin >> symbol;
	symbol = upcase(symbol);
}


void currency :: input(char currencySymbol)
{
	symbol = upcase(currencySymbol);
	std::cout << "Enter Amount ";
	std::cin >> amount;
}


void currency :: input(double anAmount)
{
	amount = anAmount;
	std::cout << "Enter Currency Symbol ";
	std::cin >> symbol;
	symbol = upcase(symbol);
}


void currency :: input(char currencySymbol, double anAmount)
{
	amount = anAmount;
	symbol = upcase(currencySymbol);
}


void currency :: display()
//	Definition:	display(...), displays currency in standard format. E.g. M1,234.56
//
//	Input:		none
//
//	Output:		1.	Return type is void, but the currency amount is displayed formatted on
//					screen.
{
	long intAmount = amount;				//	get the integral part of the currency
	double fracAmount = amount - intAmount;	//	get the fraction part

	//	Covert both the integral and the fractional part to strings for manipulation
	char *	intAmountStr = int_to_str(intAmount),
		 *	fracAmountStr = dec_to_str(fracAmount),
		 *	currencyStr = "\0";

	long i, comma;	//	comma is used to separate thousands. e.g. 123,000 or 1,234,567, etc

	//	Place commas at appropriate places

	//	First, reverse the integral amount so that it is read from left to right
	//	from the least digit
	intAmountStr = reverse(intAmountStr);

	for (i = 0, comma = 1; i < str_len(intAmountStr); i++, comma++)
	{
		currencyStr = add(currencyStr, cstring(intAmountStr[i]));

		if ( (comma % 3 == 0) && ((i+1) < str_len(intAmountStr)))
			//	comma is inserted after 3 digits -- from the least digit
			currencyStr = add(currencyStr, ",");
	}

	//	Once more, reverse the integral amount so that it starts with the most significant digit
	//	with commas inserted at approapriate places.
	currencyStr = reverse(currencyStr);

	std::cout << symbol;
	for (i = 0; i < str_len(currencyStr); i++)
	{
		std::cout << currencyStr[i];
	}

	std::cout << ".";
	i = 2;

	//	Display the two digits after the decimal

	if (i < str_len(fracAmountStr))
	{
		//	There is at least 1 digit after the decimal, display it
		std::cout << fracAmountStr[i];
		i++;	//	move to the next possible digit

		if (i < str_len(fracAmountStr))
		{
			//	There are at least 2 digits after the decimal, display the 2nd digit
			std::cout << fracAmountStr[i];
			i++;
		}
		else
			//	There was only 1 digit after the decimal, pad with the trailing 0.
			std::cout << "0";
	}
	else
		//	There were no digits after the decimal, pad with the two trailing 0's
		std::cout << "00";

	std::cout << "\n";
}



//	M e m b e r   O p e r a t o r s   S p e c i f i c a t i o n


currency currency :: operator = (currency right)
{
	this->amount = right.amount;
	this->symbol = right.symbol;

	return(*this);
}


currency currency :: operator = (double right)
{
	this->amount = right;
	return(*this);
}


currency currency :: operator + (currency right)
{
	currency newCurrency = *this;	//	Copy this to avoid any possible side effetcs

	newCurrency = newCurrency.amount + right.amount;
	return(newCurrency);
}


currency currency :: operator + (double right)
{
	currency newCurrency = *this;

	newCurrency = newCurrency.amount + right;
	return(newCurrency);
}


currency currency :: operator += (currency right)
{
	*this = (*this) + right;
	return(*this);
}


currency currency :: operator += (double right)
{
	*this = (*this) + right;
	return(*this);
}


currency currency :: operator - (currency right)
{
	currency newCurrency = *this;

	newCurrency = newCurrency.amount - right.amount;
	return(newCurrency);
}


currency currency :: operator - (double right)
{
	currency newCurrency = *this;

	newCurrency = newCurrency.amount - right;
	return(newCurrency);
}


currency currency :: operator -= (currency right)
{
	*this = (*this) - right;
	return(*this);
}


currency currency :: operator -= (double right)
{
	*this = (*this) - right;
	return(*this);
}


currency currency :: operator * (currency right)
{
	currency newCurrency = *this;

	newCurrency = newCurrency.amount * right.amount;
	return(newCurrency);
}


currency currency :: operator * (double right)
{
	currency newCurrency = *this;

	newCurrency = newCurrency.amount * right;
	return(newCurrency);
}


currency currency :: operator *= (currency right)
{
	*this = *this * right;
	return(*this);
}


currency currency :: operator *= (double right)
{
	*this = *this * right;
	return(*this);
}


currency currency :: operator / (currency right)
{
	currency newCurrency = *this;

	newCurrency = newCurrency.amount / right.amount;
	return(newCurrency);
}


currency currency :: operator / (double right)
{
	currency newCurrency = *this;

	newCurrency = newCurrency.amount / right;
	return(newCurrency);
}


currency currency :: operator /= (currency right)
{
	*this = *this / right;
	return(*this);
}


currency currency :: operator /= (double right)
{
	*this = *this/ right;
	return(*this);
}


bool currency :: operator > (currency right)
{
	return((this->symbol == right.symbol) && (this->amount > right.amount));
}


bool currency :: operator > (double right)
{
	return(this->amount > right);
}


bool currency :: operator < (currency right)
{
	return((this->symbol == right.symbol) && (this->amount < right.amount));
}


bool currency :: operator < (double right)
{
	return(this->amount < right);
}


bool currency :: operator == (currency right)
{
	return((this->symbol == right.symbol) && (this->amount == right.amount));
}


bool currency :: operator == (double right)
{
	return(this->amount == right);
}


bool currency :: operator >= (currency right)
{
	return(((*this) > right) || ((*this) == right));
}


bool currency :: operator >= (double right)
{
	return(((*this).amount > right) || ((*this).amount == right));
}


bool currency :: operator <= (currency right)
{
	return(((*this) < right) || ((*this) == right));
}


bool currency :: operator <= (double right)
{
	return(((*this).amount < right) || ((*this).amount == right));
}


bool currency :: operator != (currency right)
{
	return(!((*this) == right));
}


bool currency :: operator != (double right)
{
	return(!((*this) == right));
}


//	F r i e n d   O p e r a t o r s   S p e c i f i c a t i o n

currency operator + (double left, currency right)
{
	currency newCurrency = right;

	newCurrency = newCurrency.amount + left;
	return(newCurrency);
}


currency operator - (double left, currency right)
{
	currency newCurrency = right;

	newCurrency = left - newCurrency.amount;
	return(newCurrency);
}


currency operator * (double left, currency right)
{
	currency newCurrency = right;

	newCurrency = left * newCurrency.amount;
	return(newCurrency);
}


currency operator / (double left, currency right)
{
	currency newCurrency = right;

	newCurrency = left / newCurrency.amount;
	return(newCurrency);
}


bool operator > (double left, currency right)
{
	return(left > right.amount);
}


bool operator < (double left, currency right)
{
	return(left < right.amount);
}


bool operator == (double left, currency right)
{
	return(left == right.amount);
}


bool operator >= (double left, currency right)
{
	return((left > right.amount) || (left == right.amount));
}


bool operator <= (double left, currency right)
{
	return((left < right.amount) || (left == right.amount));
}


bool operator != (double left, currency right)
{
	return(!(left == right));
}


std::istream & operator >> (std::istream & input, currency & money)
{
	std::cout << "Enter Amount ";
	input >> money.amount;
	std::cout << "Enter Currency Symbol ";
	input >> money.symbol;
	money.symbol = upcase(money.symbol);

	return(input);
}


std::ostream & operator << (std::ostream & output, currency money)
//	Definition:	<<(...), displays currency in standard form. It has the same effect
//				as the method, display().
{
	long intAmount = money.amount;
	double fracAmount = money.amount - intAmount;

	//	Covert both the integral and the fractional part to strings for manipulation
	char *	intAmountStr = int_to_str(intAmount),
		 *	fracAmountStr = dec_to_str(fracAmount),
		 *	currencyStr = "\0";

	long i, comma;	//	comma is used to separate thousands. e.g. 123,000 or 1,234,567, etc

	//	Place commas at appropriate places

	//	First, reverse the integral amount so that it is read from left to right
	//	from the least digit
	intAmountStr = reverse(intAmountStr);

	for (i = 0, comma = 1; i < str_len(intAmountStr); i++, comma++)
	{
		currencyStr = add(currencyStr, cstring(intAmountStr[i]));
		
		if ( (comma % 3 == 0) && ((i+1) < str_len(intAmountStr)))
			//	comma is inserted after 3 digits -- from the least digit
			currencyStr = add(currencyStr, ",");
	}

	//	Once more, reverse the integral amount so that it starts with the most significant digit
	//	with commas inserted at approapriate places.
	currencyStr = reverse(currencyStr);

	output << money.symbol;
	for (i = 0; i < str_len(currencyStr); i++)
	{
		output << currencyStr[i];
	}

	output << ".";
	i = 2;

	//	Display the two digits after the decimal

	if (i < str_len(fracAmountStr))
	{
		//	There is at least 1 digit after the decimal, display it
		output << fracAmountStr[i];
		i++;	//	move to the next possible digit

		if (i < str_len(fracAmountStr))
		{
			//	There are at least 2 digits after the decimal, display the 2nd digit
			output << fracAmountStr[i];
			i++;
		}
		else
			//	There was only 1 digit after the decimal, pad with the trailing 0.
			output << "0";
	}
	else
		//	There were no digits after the decimal, pad with the two trailing 0's
		output << "00";

	return(output);
}

#endif	//	Currency Class Specification Ends Here

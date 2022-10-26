/*
	FILE NAME: Class{aPersonsName}.cpp

	FUNCTION:

	This class encapsulates all the necessary data and methods on a person's
	name: surname and first name.

	(C) mofana mphaka; April 2020
*/

#include <iostream>

#include <C:\Users\Mofan\OneDrive\Documents\CS2432{OOP}\programs\class{aString}.cpp>
/*	This user defined library avails almost all string manipulation routines.
	e.g. upcase() -- converts any string to upper case
*/

#ifndef _a_PERSONS_NAME_CLASS_
#define _a_PERSONS_NAME_CLASS_

class aPersonsName
{
	//	F r i e n d   F u n c t i o n s

	friend std::istream & operator >> (std::istream & input, aPersonsName & Name);
	/*	Inputs name, Name, from the input stream, e.g. cin >> Name */

	friend std::ostream & operator << (std::ostream & output, aPersonsName Name);
	/*	Outputs name, Name, on the output stream, e.g. cout << Name */


	private:

		//	P r i v a t e   D a t a

		aString
			surname,
			first_name;

	public:

		//	P u b l i c   M e m b e r   F u n c t i o n s

		//	C o n s t r u c t o r s

		aPersonsName(char * aSurname = "", char * aFirst_name = "");
		/*	It initialises surname to aSurname, first_name to aFirst_name */
		
		//	D e s t r u c t o r

		~aPersonsName()	{}

		//	I n p u t   F u n c t i o n s

		void input(char * aSurname = "", char * aFirst_name = "");
		/*	It sets surname to the upper case of aSurname, and if it is empty, it inputs surname interactively 
			from the keyboard in upper case. It does the same to first_name. 
		*/
		
		void set(char * aSurname = "", char * aFirst_name = "");
		/*	It sets surname to aSurname in uppercase and first_name to aFirst_Name in uppercase */
		
		//	O u t p u t   F u n c t i o n s

		aString getSurname();
		/*	Avails the person's surname */

		char * surnameValue();
		/*	Avails the value of the person's surname */

		aString getFirstName();
		/*	Avails the person's first name */

		char * first_nameValue();
		/*	Avails the value of the person's first name */

		aPersonsName operator = (aPersonsName right);
		/*	Assigns the name on the right to this name (on the left of '=')*/

		bool operator == (aPersonsName right);
		/*	Returns true if this name is the same as the name on the right,
			false otherwise. That is, this name == right name?
		*/

		bool operator != (aPersonsName right);
		/*	returns true if this name <> right name, false otherwise */
		
		bool operator > (aPersonsName right);
		/*	returns true if this name > right name, false otherwise */
		
		bool operator < (aPersonsName right);
		/*	returns true if this name < right name, false otherwise */
		
		bool operator <= (aPersonsName right);
		/*	returns true if this name <= right name, false otherwise */
		
		bool operator >= (aPersonsName right);
		/*	returns true if this name >= right name, false otherwise */
				
		//	D i s p l a y   F u n c t i o n s
		
		void display();
		/*	Displays a person's name on the console */
};



//	M e m b e r   F u n c t i o n s   S p e c i f i c a t i o n


aPersonsName :: aPersonsName (char * aSurname, char * aFirst_name)
{
	surname = aSurname; surname.upcase();
	first_name = aFirst_name; first_name.upcase();
}


void aPersonsName :: input(char * aSurname, char * aFirst_name)
{
	surname = aSurname; surname.upcase();
	
	if (surname == "")
		surname.input("Surname ? ","abcdefghijklmnopqrstuvwxyz",'U');
		
	first_name = aFirst_name; first_name.upcase();
	
	if (first_name == "")
		first_name.input("First name (Initials)? ","abcdefghijklmnopqrstuvwxyz",'U');
}


void aPersonsName :: set(char * aSurname, char * aFirst_name)
{
	surname = aSurname; surname.upcase();	
	first_name = aFirst_name; first_name.upcase();
}


aString aPersonsName :: getSurname() 
{ 
	return surname;
}

char * aPersonsName :: surnameValue() 
{ 
	return surname.value();
}


aString aPersonsName :: getFirstName() 
{ 
	return first_name;
}


char * aPersonsName :: first_nameValue() 
{ 
	return first_name.value();
}


bool aPersonsName :: operator != (aPersonsName right) 
{ 
	return(!((*this) == right));
}


bool aPersonsName :: operator < (aPersonsName right) 
{ 
	return(right > (*this));
}

		
bool aPersonsName :: operator <= (aPersonsName right)
{ 
	return ((*this) < right) || ((*this) == right);
}
		
bool aPersonsName :: operator >= (aPersonsName right)
{ 
	return ((*this) > right) || ((*this) == right);
}

		
void aPersonsName :: display() 
{ 
	std::cout << surname << " " << first_name << "\n";
}


aPersonsName aPersonsName :: operator = (aPersonsName right)
/*	Assigns the name on the right to this name (on the left of '=')*/
{
	this->surname = right.surname;
	this->first_name = right.first_name;

	return(*this);
}


bool aPersonsName :: operator == (aPersonsName right)
/*	Returns true if this name is the same as the name on the right,
	false otherwise. That is, this name == right name?
*/
{
	return((this->surname == right.surname) &&
			(this->first_name == right.first_name));
}


bool aPersonsName :: operator > (aPersonsName right)
/*	returns true if this name > right name, false otherwise */
{
	if (this->surname > right.surname)
		return(true);
	else if ((this->surname == right.surname) &&
			 (this->first_name > right.first_name))
		return(true);
	else
		return(false);
}


//	F r i e n d   F u n c t i o n s   S p e c i f i c a t i o n

std::istream & operator >> (std::istream & input, aPersonsName & Name)
/*	Inputs name, Name, from the input stream, e.g. cin >> Name */
{
	
	//	Input the two strings

	std::cout << "Surname ? "; input >> Name.surname;
	std::cout << "First name (Initials)? "; input >> Name.first_name;
	
	//	Then normalise the strings to capital case

	Name.surname.upcase();
	Name.first_name.upcase();

	return(input);
}


std::ostream & operator << (std::ostream & output, aPersonsName Name)
/*	Outputs name, Name, on the output stream, e.g. cout << Name */
{
	output << Name.surname << " " << Name.first_name;
	return(output);
}

#endif // End of _a_PERSONS_NAME_CLASS_


/*
int main()
{
	aPersonsName X;
	
	//std::cin >> X;
	//std::cout << X << "\n";
	
	X.input();
	X.display();
	return 1;
}

*/
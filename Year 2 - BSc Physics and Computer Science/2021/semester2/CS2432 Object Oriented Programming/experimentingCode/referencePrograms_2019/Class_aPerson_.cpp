/* 
	PROGRAM NAME: Class{aPerson}.cpp

    FUNCTION:

	Construction of a persons class, by composition from classes:
	
	(1) aDate
	(2) aPersonsName

	(C) Mofana Mphaka; April 2020
*/


#include <C:\Users\Mofan\OneDrive\Documents\CS2432{OOP}\programs\Class{aDate}.cpp>
#include <C:\Users\Mofan\OneDrive\Documents\CS2432{OOP}\programs\Class{aPersonsName}.cpp>

#if !defined _a_PERSON_CLASS_
#define _a_PERSON_CLASS_

// Class Person definition
/*
	A person has:

		1.	A name which is two things

			1.1.	surname: surname of the person e.g. Mphaka
			1.2.	first name: e.g initials or a name like Mofana

			//	This will come from file: Class{aPersonsName}.cpp

		2.	Age:	a number like 41 (i.e 41 years old)
		3.	Gender:	It is M for Male and F for Female

		4.	The Date of Birth which consists of 3 things

			4.1.	year: the year in which the person was born. E.g. 1964
			4.2.	month: the month of the year in which the person was born
			4.3.	date: the date of the month of birth

		//	This will come from file: Class{aDate}.cpp

		5.	Address/Contacts
			This is a combination of location address and/or telephones
*/

class aPerson
{
	//	F r i e n d   F u n c t i o n s   D e c l a r a t i o n s

	friend std::istream & operator >> (std::istream & input, aPerson & Person);
	/*	Inputs all the Person's Bio-Data */

	friend std::ostream & operator << (std::ostream & output, aPerson Person);
	/*	Displays all the Person's Bio-Data */


	protected:

		aPersonsName	Name;
		aDate			DateOfBirth;
		char			Sex;
		int				Age;	//	Age will be computed from DateOfBirth and current date
		aString			Address,
						Citizenship;


	public:
		//	T h e   C o n s t r u c t o r  --  p o l y m o r p h i c

		aPerson(char * aSurname = "", char * aFirstName = "", int aYear = 1900, int aMonth = 1, int a_Date = 1, char aSex = 'M');
		
		//	T h e   D e s t r u c t o r

		~aPerson() {};

		//	I n p u t   F u n c t i o n s

		//	Date Input Functions

		void inputDateOfBirth();
		/*	Inputs the complete date of birth, interactively */

		void input(int aYear);
		/*	Sets year to aYear and inputs date and month, interactively */

		void input(int aYear, int aMonth);
		/*	Sets year to aYear, month to aMonth and inputs date, interactively */

		void input(int aYear, int aMonth, int aDay);
		/*	Inputs the date of birth as: aDay aMonth aYear */

		void inputName();
		/*	Inputs the complete name: surname, first name, interactively */

		void input(char * aSurname);
		/*	Sets surname to aSurname and inputs first name interactively */

		void input(char * aSurname, char * aFirstName);
		/*	Sets surname to aSurname and first_name to aFirstName */

		void inputSex();
		/*	Inputs the person's sex interactively */

		void inputAddress();
		/*	Inputs the person's Address interactively */

		void inputCitizenship();
		/*	Inputs the person's Citizenship interactively */

		void inputSex(char aSex);
		/*	Sets Sex to aSex, in upper case */

		void inputAddress(char * anAddress);
		/*	Sets Address to upper case anAddress */

		void inputCitizenship(char * aCitizenship);
		/*	Sets Citizenship to upper case aCitizenship*/

		void input();
		/*	Inputs: Name, Date of birth and Sex, Address and Citizenship
			interactively
		*/


		//	O u t p u t   F u n c t i o n s

		int getAge();
		/*	Avails the age of the person, computes it first if necessary */

		void computeAge();
		/*	Computes the person's age, using the date of birth and the
			current date
		*/

		char getSex();
		aDate getDateOfBirth();
		aPersonsName getName();

		//	There are 3 possible outputs from the Date of Birth
		int getYearOfBirth();
		int getMonthOfBirth();
		int getDateOfMonthOfBirth();

		//	there are 2 possible outputs from the Name 
		char * getSurname();
		char * getFirstName();
		
		char * getAddress();
		char * getCitizenship();
		
		//	D i s p l a y   F u n c t i o n s

		void display();
		/*	Displays all the Bio-Data of the person */

		void displaySex();
		/*	Displays the person's sex as: Male or Female [for M or F] */

		void displayDateOfBirth();
		/* Displays the Date of Birth in long date format, e.g. 1st January 1964 */

		void displayName();
		/*	Displays the person's name as: surname, first name */
};


aPerson :: aPerson(char * aSurname, char * aFirstName, int aYear, int aMonth, int a_Date, char aSex)
{
	Name.set(aSurname, aFirstName);
	DateOfBirth.set(aYear, aMonth, a_Date);
	Sex = ((aSex == 'm') || (aSex == 'M'))? 'M': 'F';
	Age = -1;
}


void aPerson :: inputDateOfBirth()
{
	std::cout << "Date of Birth Information:\n";
	DateOfBirth.input();
}


void aPerson :: input(int aYear)
{
	std::cout << "Date of Birth Information:\n";
	DateOfBirth.set(aYear);
}


void aPerson :: input(int aYear, int aMonth)
{
	std::cout << "Date of Birth Information:\n";
	DateOfBirth.set(aYear, aMonth);
}


void aPerson :: input(int aYear, int aMonth, int aDay)
{
	DateOfBirth.set(aYear, aMonth, aDay);
}

void aPerson :: inputName()
{ 
	Name.input();
}

void aPerson :: input(char * aSurname)
{
	Name.input(aSurname);
}

void aPerson :: input(char * aSurname, char * aFirstName)
{
	Name.input(aSurname, aFirstName);
}


void aPerson :: inputSex()
{
	do
	{
		std::cout << "Enter Sex [M/F]: ";
		std::cin >> Sex;

		switch(Sex)
		{
			case 'm':
			case 'M':	Sex = 'M'; break;

			case 'f':
			case 'F':	Sex = 'F'; break;
			default:	Sex = '\0';
		}
	}
	while (Sex == '\0');
}


void aPerson :: inputAddress()
{
	Address.input("Enter Address: ", 'U');	//	Input Address in upper case
}


void aPerson :: inputCitizenship()
{
	Citizenship.input("Enter Citizenship: ", 'U');
}


void aPerson :: inputSex(char aSex)
{ 
	((aSex == 'm') || (aSex == 'M'))? Sex = 'M': Sex = 'F';
}


void aPerson :: inputAddress(char * anAddress)
{
	Address = anAddress;
	Address.upcase();
}


void aPerson :: inputCitizenship(char * aCitizenship)
{
	Citizenship = aCitizenship;
	Citizenship.upcase();
}


int aPerson :: getAge()
/*	Avails the age of the person, computes it first if necessary */
{
	if (Age >= 0)
	//	Age has already been computed
		return(Age);
	else
	{
		computeAge();
		return(Age);
	}
}


char aPerson :: getSex() 
{ 
	return Sex; 
}

aDate aPerson :: getDateOfBirth() 
{ 
	return DateOfBirth;
}

aPersonsName aPerson :: getName() 
{ 
	return Name;
}

int aPerson :: getYearOfBirth() 
{ 
	return(DateOfBirth.getYear());
}

int aPerson :: getMonthOfBirth() 
{ 
	return(DateOfBirth.getMonth());
}

int aPerson :: getDateOfMonthOfBirth() 
{ 
	return(DateOfBirth.getDate());
}

char * aPerson :: getSurname() 
{ 
	return(Name.surnameValue());
}

char * aPerson :: getFirstName() 
{ 
	return(Name.first_nameValue());
}
		
char * aPerson :: getAddress() 
{ 
	return(Address.value());
}

char * aPerson :: getCitizenship()
{
	return(Citizenship.value());
}

void aPerson :: displaySex()
{ 
	(Sex == 'M')? std::cout << "Male\n": std::cout << "Female\n";
}

void aPerson :: displayDateOfBirth()
{ 
	DateOfBirth.display(1);	//	1 = long date format, 0 = short date format
}

void aPerson :: displayName() 
{ 
	Name.display();
}


void aPerson :: computeAge()
/*	Computes the person's age, using the date of birth and the
	current date
*/
{
	aDate CurrDate;

	std::cout << "Gathering Information for Computing Age for ";
	displayName();
	do
	{
		std::cout << "Enter the Current Date, after [" << DateOfBirth << "]:\n";
		std::cin >> CurrDate;
	}
	while (DateOfBirth > CurrDate);

	Age = (CurrDate - DateOfBirth)/12;
}


void aPerson :: input()
/*	Inputs: Name, Date of birth and Sex, interactively */
{
	std::cout << "Gathering Personal Information:\n";
	inputName();
	inputSex();
	inputDateOfBirth();
	inputAddress();
	inputCitizenship();
	computeAge();
}


void aPerson :: display()
/*	Displays all the Bio-Data of the person */

{
	std::cout << "Name [Surname, FirstName]: "; displayName();
	std::cout << "Sex          : "; displaySex();
	std::cout << "Date of Birth: "; displayDateOfBirth();
	
	if (Age >= 0)
		std::cout << "Age in Years : " << Age << "\n";

	std::cout << "Address      : " << Address << "\n";
	std::cout << "Citizenship  : " << Citizenship << "\n";
}


//	F r i e n d   F u n c t i o n s   S p e c i f i c a t i o n s

std::istream & operator >> (std::istream & input, aPerson & Person)
/*	Inputs all the Person's Bio-Data */
{
	std::cout << "Gathering Personal Information:\n";
	input >> Person.Name;
	
	Person.inputSex();

	std::cout << "Date of Birth Information:\n";
	input >> Person.DateOfBirth;
	
	Person.inputAddress();

	Person.inputCitizenship();

	Person.computeAge();

	return(input);
}


std::ostream & operator << (std::ostream & output, aPerson Person)
/*	Displays all the Person's Bio-Data */
{
	output << "Name [Surname, FirstName]: " << Person.Name << "\n";
	output << "Sex          : ";
	(Person.Sex == 'M')? output << "Male\n": output << "Female\n";
	output << "Date of Birth: "; 
	output << Person.DateOfBirth << "\n";

	if (Person.Age >= 0)
		output << "Age in Years : " << Person.Age << "\n";

	output << "Address      : " << Person.Address << "\n";
	output << "Citizenship  : " << Person.Citizenship << "\n";
	
	return(output);
}

#endif
/*
int main()
{
	aPerson P;
	
	std::cin >> P;
	std::cout << P;
	return 1;
}
*/

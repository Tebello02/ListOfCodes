/* 
	PROGRAM NAME: Class{aPerson_INHERITANCE}.cpp

    FUNCTION:

	Construction of a persons class by multiple inheritance from classes: aDate and aPersonsName

	(C) Mofana Mphaka; Febuary 2020
*/


#include <C:\Users\Mofan\OneDrive\Documents\CS2432{OOP}\programs\Class{aDate}.cpp>
#include <C:\Users\Mofan\OneDrive\Documents\CS2432{OOP}\programs\Class{aPersonsName}.cpp>


#if !defined _a_PERSON_CLASS_
#define _a_PERSON_CLASS_

class aPerson : public aPersonsName, public aDate
// class aPerson is derived by multiple inheritance from classes: aPersonsName and aDate
{
	//	F r i e n d   F u n c t i o n s   D e c l a r a t i o n s

	friend std::istream & operator >> (std::istream & input, aPerson & Person);
	/*	Inputs all the Person's Bio-Data. It also computes the person's age and wages. */

	friend std::ostream & operator << (std::ostream & output, aPerson Person);
	/*	Displays all the Person's Bio-Data */


	protected:	//	could be declared: private

		//	Name			it is inherited from class aPersonsName
		//	DateOfBirth		it is inherited from class aDate
		
		//	Additional Data Attributes for  class aPerson
		
		char			sex;			//	sex:- the gender of the person: [M]ale or [F]emale
		int				age;			//	age:- will be computed from year of birth and the current year
		double			hours_worked,	//	No. of hours worked by this person
						hourly_rate,	//	The hourly rate that will be set for wages computation
						wages;			//	wages = hours_worked * hourly_rate
						
		aString			Address,		//	A desriptive text to define the person's location
						Citizenship;	//	Another descriptive text to define the nationality of the person


	public:

		//	T h e   C o n s t r u c t o r  --  p o l y m o r p h i c

		aPerson(char * aSurname = "", char * aFirstName = "", int aYear = 1900, int aMonth = 1, int a_Date = 1, char aSex = 'M');
		/*	It uses class initialisers from the parent classes: aPersonsName & aDate to:
			(1) initialise: surname to aSurname, first_name to aFirstName and Date of birth as: a_Date, aMonth & aYear, and
			(2) initialises: age, hours_worked & hourly_rate as -1 and sex as aSex
			(3) otherwise the default values are assumed
		*/
		
		
		//	T h e   D e s t r u c t o r

		~aPerson() {};


		//	I n p u t   F u n c t i o n s

		//	Bio-Data Input Functions

		void inputSex();
		/*	Inputs sex interactively, in upper case */

		void inputSex(char aSex);
		/*	Sets sex to aSex, in upper case */

		void inputAddress();
		/*	Inputs the person's Address interactively */
		
		void inputCitizenship();
		/*	Inputs the person's Citizenship interactively */

		void inputAddress(char * anAddress);
		/*	Sets Address to upper case anAddress */

		void inputCitizenship(char * aCitizenship);
		/*	Sets Citizenship to upper case aCitizenship*/

		void input();
		/*	Inputs the whole Bio-data of the person: Name, Date of birth and sex, Address and Citizenship, ..., etc
			interactively. It also computes the person's age and wages.
		*/


		//	O u t p u t   F u n c t i o n s

		int get_age();
		/*	Avails the age of the person, computes it first if necessary */

		int compute_age();
		/*	Computes the person's age, using the year of birth and the
			current year
		*/
		
		double get_wages();
		/*	Avails the wages of the person, computes it first if necessary */
		
		double compute_wages();
		/*	Computes the person's wages, using the number of hours worked and the hourly rate
		*/

		char getSex();
		/*	avails the character value of sex: M or F */
		
		char * getAddress();
		/*	avail the value of address as a C string -- char * */
		
		char * getCitizenship();
		/*	avail the value of citizenship as a C string -- char * */
		
		
		//	D i s p l a y   F u n c t i o n s

		void display();
		/*	Displays all the Bio-Data of the person, on the screen */

		void displaySex();
		/*	Displays the person's sex as: Male or Female [for M or F] */
		
		
		//	M e m b e r    o p e r a t o r s
		
		bool operator == (aPerson right);
		/*	returns true if this person is as old as the person on the right	*/
		
		bool operator <= (aPerson right);
		/*	returns true if this person is as old as the person on the right, or less	*/
		
		bool operator >= (aPerson right);
		/*	returns true if this person is as old as the person on the right, or older	*/
		
		bool operator > (aPerson right);
		/*	returns true if this person is older than the person on the right	*/
		
		bool operator < (aPerson right);
		/*	returns true if this person is younger than the person on the right	*/
		
		bool operator != (aPerson right);
		/*	returns true if this person is not as old as the person on the right	*/		
};


aPerson :: aPerson(char * aSurname, char * aFirstName, int aYear, int aMonth, int a_Date, char aSex) :
			aPersonsName(aSurname, aFirstName), aDate(aYear, aMonth, a_Date)
/*	Sets Name.surname to aSurname, Name.first_name to aFirstName,
	Date of birth as: _aDate aMonth aYear, age as -1 and sex as aSex
*/
{
	sex = ((aSex == 'm') || (aSex == 'M'))? 'M': 'F';
	age = hours_worked = hourly_rate = wages = -1;
}



int aPerson :: get_age()
/*	Avails the age of the person, computes it first if necessary */
{
	if (age > 0)
	//	age has already been computed
		return(age);
	else
		return compute_age();
}


double aPerson :: get_wages()
/*	Avails the age of the person, computes it first if necessary */
{
	if (wages > 0)
	//	age has already been computed
		return(wages);
	else
		return compute_wages();
}


int aPerson :: compute_age()
{
	int current_year;

	std::cout << "Gathering Information for Computing age for: ";
	aPersonsName :: display();
	do
	{
		std::cout << "Enter the Current Year, after [" << aDate :: getYear() << "]:  ";
		std::cin >> current_year;
	}
	while (aDate :: getYear() > current_year);

	age = current_year - aDate :: getYear();
	
	return age;
}


double aPerson :: compute_wages()
{
	std::cout << "Gathering Information for Computing wages for: ";
	aPersonsName :: display();
	
	do
	{
		std::cout << "Enter hours worked, [must be > 0] ";
		std::cin >> hours_worked;
	}
	while (hours_worked < 0);

	do
	{
		std::cout << "Enter the set hourly rate, [must be > 0] ";
		std::cin >> hourly_rate;
	}
	while (hourly_rate < 0);
	
	wages = hours_worked * hourly_rate;
	
	return wages;
}

void aPerson :: inputSex()
{
	do
	{
		std::cout << "Enter sex [M/F]: ";
		std::cin >> sex;

		switch(sex)
		{
			case 'm':
			case 'M':	sex = 'M'; break;

			case 'f':
			case 'F':	sex = 'F'; break;
			default:	sex = '\0';
		}
	}
	while (sex == '\0');
}


void aPerson :: inputSex(char aSex)
{ 
	((aSex == 'm') || (aSex == 'M'))? sex = 'M': sex = 'F';
}


void aPerson :: input()
{
	std::cout << "Gathering Personal Information:\n\n";
	aPersonsName::input();
	inputSex();
	aDate :: input();
	inputAddress();
	inputCitizenship();
	compute_age();
	compute_wages();
}


void aPerson :: inputAddress()
{
	Address.input("Enter Address: ",'U');	//	Input Address in upper case
}


void aPerson :: inputCitizenship()
{
	Citizenship.input("Enter Citizenship: ", 'U');
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


char aPerson :: getSex() 
{ 
	return sex; 
}

		
char * aPerson :: getAddress() 
{ 
	return(Address.value());
}


char * aPerson :: getCitizenship() 
{ 
	return(Citizenship.value());
}


void aPerson :: display()
{
	std::cout << "\n\nName [Surname, FirstName]: "; aPersonsName :: display();
	std::cout << "Sex          : "; displaySex();
	std::cout << "Date of Birth: "; aDate :: display(1);
	
	if (age >= 0)
		std::cout << "Age in Years : " << age << "\n";

	if (wages >= 0)
		std::cout << "Wages in Maloti : " << "M" << wages << "\n";
		
	std::cout << "Address      : " << Address << "\n";
	std::cout << "Citizenship  : " << Citizenship << "\n";
}


void aPerson :: displaySex()
{ 
	(sex == 'M')? std::cout << "Male\n": std::cout << "Female\n";
}


//	M e m b er   O p e r a t o r s   S p e c i f i c a t i o n s

bool aPerson :: operator == (aPerson right)
{
	return this->age == right.age;
}


bool aPerson :: operator <= (aPerson right)
{
	return this->age <= right.age;
}


bool aPerson :: operator >= (aPerson right)
{
	return this->age >= right.age;
}

		
bool aPerson :: operator > (aPerson right)
{
	return this->age > right.age;
}

	
bool aPerson :: operator < (aPerson right)
{
	return this->age < right.age;
}
		
bool aPerson :: operator != (aPerson right)
{
	return this->age != right.age;
}


//	F r i e n d   O p e r a t o r s   S p e c i f i c a t i o n s

std::istream & operator >> (std::istream & input, aPerson & Person)
{
	std::cout << "Gathering Personal Information:\n";
	//input Name;
	Person.aPersonsName::input();
	
	Person.inputSex();

	std::cout << "Date of Birth Information:\n";
	//input date of birth
	Person.aDate::input();
	
	Person.inputAddress();

	Person.inputCitizenship();

	Person.compute_age();
	Person.compute_wages();

	return(input);
}


std::ostream & operator << (std::ostream & output, aPerson Person)
{
	output << "\n\nName [Surname, FirstName]: "; Person.aPersonsName::display();
	output << "\n";
	output << "Sex          : ";
	(Person.sex == 'M')? output << "Male\n": output << "Female\n";
	output << "Date of Birth: "; Person.aDate::display(1); 
	output << "\n";

	if (Person.age >= 0)
		output << "Age in Years : " << Person.age << "\n";

	if (Person.wages >= 0)
		output << "Wages in Maloti : " << "M" << Person.wages << "\n";

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

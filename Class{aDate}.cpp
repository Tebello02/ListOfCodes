
/*
	PROGRAM NAME: Class{aDate}.cpp
	FUNCTION:

	This program implements the date (year, month, date) as a class

	(C) mofana mphaka; April 2020
		Edited March 2021
*/

#include <iostream>

#ifndef _a_DATE_CLASS_
#define _a_DATE_CLASS_

/*
ADT aDate:

	Data Objects:

	1.	year: type = int; values must be after 1900
	2.	month: type = int; values = 1, 2, 3, ..., 12
	3.	date: type = int;
		values	=	1..28 or 29 (February depending on leap year or not)
					Others = 1..30 or 31 (depending on the month)

	Operations:

	1.	input/Set functions

		input();
		//	read date from keyboard -- interactive

		set( int aYear, int aMonth, int aDate);
		//	sets year name to aYear, month name to aMonth and date to aDate

	2.	display: short or long name -- e.g. 1st Jan 2006 or 1st January 2006
		display( int mode);

*/

class aDate
{
	//	F r i e n d   O p e r a t o r   O v e r l o a d i n g

	//	Input/Output Redirection Operators >> and <<

	friend std::istream & operator >> (std::istream & input, aDate & Date);
	/*
		It reads a date data interactively from the console -- same as input() function
	*/
	
	friend std::ostream & operator << (std::ostream & output, aDate Date);
	/*
		It displays a date data on the screen -- same as display(...) function
	*/
	
	
	private:

		//	P r i v a t e   D a t a   C o m p o n e n t s

		int year,	//	The year component of the date
			month,	//	The month component of the date
			date;	//	The date of the month

		//	P r i v a t e   M e m b e r   F u n c t i o n s
		
		void readYear();
		/*
			It reads the year data interactively from the console. Year must be after 1900
		*/
	
		void readMonth();
		/*
			It reads the month data interactively from the console. Month = 1 .. 12
		*/

		void readDate();
		/*
			It reads the date data interactively from the console. Date = 1 .. 28 or 29; 1 ..30 or 31
		*/


	public:

		//	M e m b e r   O p e r a t o r   O v e r l o a d i n g

		// Boolean Operators/Functions

		bool operator == (aDate Date2);
		/*
			It returns true if this date (on the left) = Date2 (on the right), false otherwise
		*/
		
		bool operator != (aDate Date2);
		/*
			It returns true if this date (on the left) <> Date2 (on the right), false otherwise
		*/
		
		bool operator > (aDate Date2);
		/*
			It returns true if this date (on the left) comes after Date2 (on the right), false otherwise
		*/
		
		bool operator < (aDate Date2);
		/*
			It returns true if this date (on the left) comes before Date2 (on the right), false otherwise
		*/
		
		bool operator >= (aDate Date2);
		bool operator <= (aDate Date2);
	
		//	The difference between two dates

		int operator - (aDate Date2);
		/*
			It computes and returns the number of months between this date (on the left) and Date2 (on the right)
		*/
		

		//	C l a s s    C o n s t r u c t o r

		aDate(int aYear = 1900, int aMonth = 1, int aDay = 1);
		/*	Sets year to aYear, month to aMonth and date to aDay. The default date is 1900 01 01 */
		

		//	C l a s s   D e s t r u c t o r

		~aDate() {};


		//	I n p u t   M e m b e r   F u n c t i o n s

		void input();
		/*	Input date interactively: year, month, date */
		
		void inputYear();
		/*	Input a year interactively */
		
		void inputMonth();
		/*	Input a month interactively */
		
		void inputDate();
		/*	Input a date interactively */
		
		void set(int aYear = 1900, int aMonth = 1, int aDay = 1);
		/*	Sets year to aYear, month to aMonth and date to aDay */
		
		void setYear(int aYear = 1900);
		/*	Sets year to aYear */

		void setMonth(int aMonth = 1);
		/*	Sets month to aMonth */

		void setDate(int aDay = 1);
		/*	Sets date to aday */

		//	O u t p u t   M e m b e r   F u n c t i o n s

		bool leap(int aYear);
		/*	returns true if aYear is a leap year; false otherwise */

		int getYear();
		/*	returns the year component of aDate */
		
		int getMonth();
		/*	returns the month component of aDate */
		
		int getDate();
		/*	returns the date component of aDate */
		

		//	D i s p l a y   M e m b e r   F u n c t i o n s
		
		void display(int Long = 0);
		/*	Displays the entire date, either in long format (Long = 1), e.g 1st January 1964
			or in short format (Long = 0), e.g. 1st Jan 1964 */
		
		void displayYear();
		/*	Displays the year component of aDate */
		
		void displayMonth(int Long = 0);
		/*	Displays the month, either in long format, e.g January
			or in short format, e.g. Jan */
		
		void displayDate();
		/*	Displays the date as 1st, 2nd, 3rd, etc */
};


aDate :: aDate(int aYear, int aMonth, int aDay)
{
	if (aYear < 1900)
		year = 1900;
	else
		year = aYear;

	if (month < 1)
		month = 1;
	else if (month > 12)
		month = 12;
	else
		month = aMonth;
	
	if (aDay < 1)
		aDay = 1;

	switch(month)
	{
		//	months with 31 days
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:	if (aDay > 31)
						date = 31;
					else
						date = aDay;
					break;
					
		//	months with 30 days
		case 4:
		case 6:
		case 9:
		case 11:	if (aDay > 30)
						date = 30;
					else
						date = aDay;
					break;
					
		//	month is February -- check leap year
		default:	if (leap(year))
					//	February has 29 days
					{
						if (aDay > 29)
							date = 29;
						else
							date = aDay;
					}
					else
					{
						if (aDay > 28)
							date = 28;
						else
							date = aDay;
					}
	}
}


int aDate :: getYear()
{
	return year;
}

		
int aDate :: getMonth()
{
	return month;
}

		
int aDate :: getDate()
{ 
	return date;
}
	
		
bool aDate :: leap(int aYear)
/*
	Gregorian Definition: A leap year is a year which is divisible by 4 and not by 100
	or it is divisible by 400.
*/
{
	return ((aYear % 4 == 0) && (aYear % 100 != 0)) || (aYear % 400 == 0);
}


void aDate :: input()
/*	Inputs year, month and date, interactively from the keyboard */
{	
	readYear();
	readMonth();
	readDate();
}


void aDate :: inputYear()
{	
	readYear();
}


void aDate :: inputMonth()
{	
	readMonth();
}


void aDate :: inputDate()
{	
	readDate();
}


void aDate :: setYear(int aYear)
{
	if (aYear < 1900)
		year = 1900;
	else
		year = aYear;
	
	//	Then chaeck that February has proper dates: 1 .. 28 or 1 .. 29
	if (month == 2)
	{
		if (leap(year))
			date = date % 30;	//	date = 0 ... 29
		else
			date = date % 29;	//	date = 0 ... 28
	}
		
	if (date <= 0)
		date = 1;	//	date = 1 .. 28, 1 .. 29, 1 .. 30, 1 .. 31
}


void aDate :: setMonth(int aMonth)
{
	if (aMonth < 1)
		month = 1;
	else if (aMonth > 12)
		month = 12;
	else
		month = aMonth;
		
	//	Check that the date is appropriate for the month
	switch(month)
	{
		//	months with 31 days
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:	date = date % 32;	//	Date = 0 .. 31
					break;
					
		//	months with 30 days
		case 4:
		case 6:
		case 9:
		case 11:	date = date % 31;	//	Date = 0 .. 30
					break;
					
		//	month is February -- check leap year
		default:	if (leap(year))
					//	February has 29 days
						date = date % 30;	//	Date = 0 .. 29
					else
						date = date % 29;	//	Date = 0 .. 28
	}
	
	if (date <= 0)
		date = 1;	//	Date = 1 .. 28, 1 .. 29, 1 .. 30, 1 .. 31	
}


void aDate :: setDate(int aDay)
{
	if (aDay < 1)
		aDay = 1;

	switch(month)
	{
		//	months with 31 days
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:	if (aDay > 31)
						date = 31;
					else
						date = aDay;
					break;
					
		//	months with 30 days
		case 4:
		case 6:
		case 9:
		case 11:	if (aDay > 30)
						date = 30;
					else
						date = aDay;
					break;
					
		//	month is February -- check leap year
		default:	if (leap(year))
					//	February has 29 days
					{
						if (aDay > 29)
							date = 29;
						else
							date = aDay;
					}
					else
					{
						if (aDay > 28)
							date = 28;
						else
							date = aDay;
					}
	}
}


void aDate :: set(int aYear, int aMonth, int aDay)
/*	Sets year to aYear, month to aMonth and date to aDay */
{
	if (aYear < 1900)
		year = 1900;
	else
		year = aYear;

	if (aMonth < 1)
		month = 1;
	else if (aMonth > 12)
		month = 12;
	else
		month = aMonth;
	
	if (aDay < 1)
		aDay = 1;

	switch(month)
	{
		//	months with 31 days
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:	if (aDay > 31)
						date = 31;
					else
						date = aDay;
					break;
					
		//	months with 30 days
		case 4:
		case 6:
		case 9:
		case 11:	if (aDay > 30)
						date = 30;
					else
						date = aDay;
					break;
					
		//	month is February -- check leap year
		default:	if (leap(year))
					//	February has 29 days
					{
						if (aDay > 29)
							date = 29;
						else
							date = aDay;
					}
					else
					{
						if (aDay > 28)
							date = 28;
						else
							date = aDay;
					}
	}
}


void aDate :: readYear()
// Inputs:	none
// Outputs:	int, year after 1900
{
	do
	{
		std::cout << "Enter Year [must be after 1900], => ";
		std::cin >> year;
	}
	while (year < 1900);
	
	//	Then chaeck that February has proper dates: 1 .. 28 or 1 .. 29
	if (month == 2)
	{
		if (leap(year))
			date = date % 30;	//	date = 0 ... 29
		else
			date = date % 29;	//	date = 0 ... 28
	}
		
	if (date <= 0)
		date = 1;	//	date = 1 .. 28, 1 .. 29, 1 .. 30, 1 .. 31
}


void aDate :: readMonth()
// Inputs:	none
// Outputs:	int, month = 1...12
{
	do
	{
		std::cout << "Enter Month of the Year [1...12] => ";
		std::cin >> month;
	}
	while ((month < 1) || (month > 12));
	
	//	Check that the date is appropriate for the month
	switch(month)
	{
		//	months with 31 days
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:	date = date % 32;	//	Date = 0 .. 31
					break;
					
		//	months with 30 days
		case 4:
		case 6:
		case 9:
		case 11:	date = date % 31;	//	Date = 0 .. 30
					break;
					
		//	month is February -- check leap year
		default:	if (leap(year))
					//	February has 29 days
						date = date % 30;	//	Date = 0 .. 29
					else
						date = date % 29;	//	Date = 0 .. 28
	}
	
	if (date <= 0)
		date = 1;	//	Date = 1 .. 28, 1 .. 29, 1 .. 30, 1 .. 31	
}


void aDate :: readDate()
// Get the correct date depending on the month and year
// outputs:	date
{
	bool incorrectDate = false;

	do
	{
		std::cout << "Enter Date of the month ";

		if ((month == 4) ||(month == 6) || (month == 9) || (month == 11))
		// months which have 30 days
		{
			std::cout << "[1...30] => ";
			std::cin >> date;
			incorrectDate = ((date < 1) || (date > 30));
		}
		else if (month != 2) // month has 31 days
		{
			std::cout << "[1...31] => ";
			std::cin >> date;
			incorrectDate = ((date < 1) || (date > 31));
		}
		else // month is February
		{
			if (leap(year)) // leap year, Feb has 29 days
			{
				std::cout << "[1...29] => ";
				std::cin >> date;
				incorrectDate = ((date < 1) || (date > 29));
			}
			else // not a leap year -- Feb has 28 days
			{
				std::cout << "[1...28] => ";
				std::cin >> date;
				incorrectDate = ((date < 1) || (date > 28));
			}
		}
	}
	while (incorrectDate);
}


void aDate :: display(int Long)
/*	Displays the entire date, either in long format, e.g 1st January 1964
	or in short format, e.g. 1st Jan 1964 */
{
	displayDate();
	displayMonth(Long);
	displayYear();
	std::cout << "\n";	//	Display the complete date will a line feed
}


void aDate :: displayYear()
/*	Displays the year component of aDate */
{
	std::cout << year << " ";
}


void aDate :: displayMonth(int Long)
/*	Displays the month, either in long format, e.g January
	or in short format, e.g. Jan */
{
	switch(month)
	{
	case 1:	(Long)? std::cout << "January " : std::cout << "Jan "; break;
	case 2:	(Long)? std::cout << "February ": std::cout << "Feb "; break;
	case 3:	(Long)? std::cout << "March ": std::cout << "Mar "; break;
	case 4:	(Long)? std::cout << "April " : std::cout << "Apr "; break;
	case 5:	(Long)? std::cout << "May " : std::cout << "May "; break;
	case 6:	(Long)? std::cout << "June " : std::cout << "Jun "; break;
	case 7:	(Long)? std::cout << "July " : std::cout << "Jul "; break;
	case 8:	(Long)? std::cout << "August " : std::cout << "Aug "; break;
	case 9:	(Long)? std::cout << "September " : std::cout << "Sept "; break;
	case 10:	(Long)? std::cout << "October " : std::cout << "Oct "; break;
	case 11:	(Long)? std::cout << "November " : std::cout << "Nov "; break;
	default:	(Long)? std::cout << "December " : std::cout << "Dec ";
	}
}


void aDate :: displayDate()
/*	Displays the date as 1st, 2nd, 3rd, etc */
{
	switch(date % 10)
	{
		case 1:	if (date != 11)
					std::cout << date << "st ";
				else
					std::cout << date << "th ";
				break;

		case 2:	if (date != 12)
					std::cout << date << "nd ";
				else
					std::cout << date << "th ";
				break;

		case 3:	if (date != 13)
					std::cout << date << "rd ";
				else
					std::cout << date << "th ";
				break;

		default:	std::cout << date << "th ";
	}
}


// o v e r l o a d e d   M e m b e r   o p e r a t o r s

bool aDate :: operator == (aDate Date2)
/*	Determine whether this date and Date2 are the same date */
{
	return((this->year == Date2.year) && (this->month == Date2.month)
			&& (this->date == Date2.date));
}


bool aDate :: operator != (aDate Date2)
/*	Determine whether this date is not the same date as Date2 */
{
	return(!(*this == Date2));		//	code re-use of operator "==" defined above
}


bool aDate :: operator > (aDate Date2)
/*	Determine whether this date comes after Date2 */
{
	if (this->year > Date2.year)
		return(true);
	else if ((this->year == Date2.year) && (this->month > Date2.month))
		return(true);
	else if ((this->year == Date2.year) && (this->month == Date2.month))
		return(this->date > Date2.date);
	else
		return(false);
}


bool aDate :: operator < (aDate Date2)
/*	Determine whether this date comes before Date2 */
{
	return Date2 > (*this);		//	code re-use of operator ">" defined above
}


bool aDate :: operator >= (aDate Date2)
/*	Determine whether this date comes on or after Date2 */
{
	return((*this > Date2) || (*this == Date2));	//	code re-use of operators ">" and "==" defined above
}


bool aDate :: operator <= (aDate Date2)
/*	Determine whether Date1 comes on or before Date2 */
{
	return Date2 >= (*this);		//	code re-use of operator ">=" defined above
}


int aDate :: operator - (aDate Date2)
/*	Returns the crude number of months between the two dates, this date and Date2 */
{
	int totalYears = 0, totalMonths = 0;

	totalYears = this->year - Date2.year;

	if (totalYears < 0)
		totalYears = (-1) * totalYears;	//	absolute value

	totalMonths = this->month - Date2.month;

	if (totalMonths < 0)
		totalMonths = (-1) * totalMonths;

	return(totalMonths + totalYears * 12);
}


// o v e r l o a d e d   F r i e n d   o p e r a t o r s

std::istream & operator >> (std::istream & input, aDate & Date)
/*	input Date like cin >> Date */
{
	bool InvalidDate = false;

	do
	{
		std::cout << "Enter Year [must be after 1900] => ";
		input >> Date.year;
	}
	while (Date.year < 1900);

	do
	{
		std::cout << "Enter Month [1..12] => ";
		input >> Date.month;
	}
	while ((Date.month < 1) || (Date.month > 12));

	do
	{
		if (Date.month == 2)
		{
			if (Date.leap(Date.year))
				std::cout << "Enter Date [1..29] => ";
			else
				std::cout << "Enter Date [1..28] => ";
		}
		else
		{
			switch(Date.month)
			{
				case 4:
				case 6:
				case 9:
				case 11:	std::cout << "Enter Date [1..30] => "; break;
				default:	std::cout << "Enter Date [1..31] => ";
			}
		}
		input >> Date.date;

		if (Date.month == 2)
		{
			if (Date.leap(Date.year))
				InvalidDate = ((Date.date < 1) || (Date.date > 29));
			else
				InvalidDate = ((Date.date < 1) || (Date.date > 28));
		}
		else
		{
			switch(Date.month)
			{
				case 4:
				case 6:
				case 9:
				case 11:	InvalidDate = ((Date.date < 1) || (Date.date > 30));
							break;
				default:	InvalidDate = ((Date.date < 1) || (Date.date > 31));
			}
		}
	}
	while (InvalidDate);
	return(input);
}


std::ostream & operator << (std::ostream & output, aDate Date)
/*	output Date like cout << Date */
{	
	switch(Date.date % 10)
	{
		case 1:	if (Date.date != 11)
					output << Date.date << "st ";
				else
					output << Date.date << "th ";
				break;

		case 2:	if (Date.date != 12)
					output << Date.date << "nd ";
				else
					output << Date.date << "th ";
				break;

		case 3:	if (Date.date != 13)
					output << Date.date << "rd ";
				else
					output << Date.date << "th ";
				break;

		default:	output << Date.date << "th ";
	}

	switch(Date.month)
	{
	case 1:	output << "January "; break;
	case 2:	output << "February "; break;
	case 3:	output << "March "; break;
	case 4:	output << "April "; break;
	case 5:	output << "May "; break;
	case 6:	output << "June "; break;
	case 7:	output << "July "; break;
	case 8:	output << "August "; break;
	case 9:	output << "September "; break;
	case 10:	output << "October "; break;
	case 11:	output << "November "; break;
	default:	output << "December ";
	}

	output << Date.year << " ";

	return (output);
}

#endif
// --- End of  a D a t e   C l a s s  Specification ---

/*
int main()
{
	aDate D1, D2;
	
	std::cout << "Enter Date1\n"; std::cin >> D1;
	std::cout << "Enter Date2\n"; std::cin >> D2;
	
	if (D1 == D2)
		std::cout << D1 << " == " << D2 << "\n";
	if (D1 <= D2)
		std::cout << D1 << " <= " << D2 << "\n";
	if (D1 >= D2)
		std::cout << D1 << " >= " << D2 << "\n";
	if (D1 > D2)
		std::cout << D1 << " > " << D2 << "\n";
	if (D1 < D2)
		std::cout << D1 << " < " << D2 << "\n";
	if (D1 != D2)
		std::cout << D1 << " <> " << D2 << "\n";
		
	return 1;
}
*/
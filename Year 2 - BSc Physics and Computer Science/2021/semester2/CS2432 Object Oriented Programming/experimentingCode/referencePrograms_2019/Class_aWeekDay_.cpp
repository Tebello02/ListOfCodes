#ifndef _a_WEEKDAY_CLASS_
#define _a_WEEKDAY_CLASS_

#include <iostream>
/*
	PROGRAM NAME: Class{aWeekDay}.cpp

	FUNCTION:

	A simple example class for the days of the week

	(C) mofana mphaka; 28 January 2006
	Edited: February 2021
*/

/*

ADT aWeekDay:

	Data Objects:

	1.	name: type = int; values = 1, 2, 3, ..., 7

	Operations:

	1.	input:	type = int, value 1..7; polymorphic:

		input();	//	read day from keyboard
		input( int aName);	//	set day name to aName

	2.	display: short or long name -- e.g. Sun or Sunday
		display( int mode);
*/

class aWeekDay
{
	private:

		int	name;

	public:

		// Class Constructor

		aWeekDay(int aName = 1);
		/*	Set the week day name as aName. The default is  First day = Sunday (i.e. name = 1) */

		
		// Class Destructor
		
		~aWeekDay() { }	//	empty -- use C++ scope rules

		void input ();
		/*	read a day name from the keyboard */

		void set(int aName = 1);
		/*	Set the week day name as aName */

		void display(int Long);
		/*	display day long, e.g. Sunday -- Long = 1, Sun -- Long = 0 */

		int getName();
		/*	Public member function to avail the private data element, name,
			to the calling object */
};


aWeekDay :: aWeekDay(int aName)
{
	if (aName < 1)
		name = 1;
	else if (aName > 7)
		name = 7;
	else
		name = aName;
}


void aWeekDay :: input ()
{
	do
	{
		std::cout << "Enter day of the week [1..7] => ";
		std::cin >> name;
	}
	while ((name < 1) || (name > 7));
}


void aWeekDay :: set(int aName)
{
	if (aName < 1)
		name = 1;
	else if (aName > 7)
		name = 7;
	else
		name = aName;
}


void aWeekDay :: display(int Long)
{
	switch(name)
	{
		case 1:	(Long) ? std::cout << "Sunday ":std::cout << "Sun "; break;
		case 2:	(Long) ? std::cout << "Monday ":std::cout << "Mon "; break;
		case 3:	(Long) ? std::cout << "Tuesday ":std::cout << "Tue "; break;
		case 4:	(Long) ? std::cout << "Wednesday ":std::cout << "Wed "; break;
		case 5:	(Long) ? std::cout << "Thursday ":std::cout << "Thu "; break;
		case 6:	(Long) ? std::cout << "Friday ":std::cout << "Fri "; break;
		default:	(Long) ? std::cout << "Saturday ":std::cout << "Sat "; break;
	}
}


int aWeekDay :: getName()
{ 
	return name; 
}
#endif // End of _a_WEEKDAY_CLASS_ Specification


/*
int main()
{
	aWeekDay D;
	
	D.display(1);
	return 1;
}
*/

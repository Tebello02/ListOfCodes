
/*
	FILE NAME: Class{aCourse}.cpp
	FUNCTION:
	A course description class

	(C) mofana mphaka; 19th July 2009
		Edited: February 2021
*/

#ifndef _a_COURSES_CLASS_
#define _a_COURSES_CLASS_

#include<C:\Users\Mofan\OneDrive\Documents\CS2432{OOP}\programs\Class{aString}.cpp>
class aCourse
{
	//	F r i e n d   F u n c t i o n s / O p e r a t o r s   D e c l a r a t i o n s

	friend std::istream & operator >> (std::istream & input, aCourse & Course);
	friend std::ostream & operator << (std::ostream & output, aCourse Course);

	private:
		
		aString		Code;
		/*	There are many more string descriptions for a course. E.g.
			Course Name, Course Synopses/outline, course lecturer(s), ...
		*/
		int				CreditHrs;
		double			Marks;

	public:

		// C o n s t r u c t o r

		aCourse(char * aCode = "", int aCreditHr = 1, double aMark = 0);
		/*	Sets Code to aCode, CreditHrs to aCreditHr, Marks to aMark */

		//	D e s t r u c t o r

		~aCourse() {}

		//	I n p u t   a n d   S e t   F u n c t i o n s

		void set(char * aCode = "", int aCreditHr = 1, double aMark = 0);
		/*	Sets Code to aCode, CreditHrs to aCreditHr, Marks to aMark */

		void inputCode();
		/*	Inputs course code, interactively */

		void inputCreditHrs();
		/*	Inputs course credit hours, interactively */

		void inputMarks();
		/*	Inputs course Marks, interactively */

		void input();
		/*	inputs the complete course information: Code, Credits and Marks
			interactively
		*/
		
		//	Output Functions

		double getMarks();
		/*	Avails the course Marks */
		
		char * getCode();
		/*	Avails the course Code */
		
		int getCreditHrs();
		/*	Avails the course Credit Hrs */
		
		//	Display Functions

		void display();
		/*	Displays course as: Code-CreditHrs  Marks, e.g. CS2431-4  80 */
};


aCourse :: aCourse(char * aCode, int aCreditHr, double aMark)
{
	Code = aCode;
	Code.upcase();
	((aCreditHr <= 36)&&(aCreditHr >= 1))? CreditHrs = aCreditHr : CreditHrs = 1;
	((aMark <= 100)&&(aMark >= 0))? Marks = aMark : Marks = 0;
}


void aCourse :: set(char * aCode, int aCreditHr, double aMark)
{
	Code = aCode;
	Code.upcase();
	((aCreditHr <= 36)&&(aCreditHr >= 1))? CreditHrs = aCreditHr : CreditHrs = 1;
	((aMark <= 100)&&(aMark >= 0))? Marks = aMark : Marks = 0;
}


void aCourse :: inputCode()
{
	do
	{
		Code.input("Enter Course Code: ",'U');
	}
	while (Code == "");
}


void aCourse :: inputCreditHrs()
{
	do
	{
		std::cout << "Enter Credit Hours [1..36]=> "; std::cin >> CreditHrs;
	}
	while ((CreditHrs < 1) || (CreditHrs > 36));
}


void aCourse :: inputMarks()
{
	do
	{
		std::cout << "Enter Marks [0..100]=> "; std::cin >> Marks;
	}
	while ((Marks < 0) || (Marks > 100));
}

void aCourse :: input()
{
	inputCode();
	inputCreditHrs();
	inputMarks();
}


double aCourse :: getMarks() 
{ 
	return(Marks);
}
		

char * aCourse :: getCode() 
{ 
	return(Code.value());
}

		
int aCourse :: getCreditHrs() 
{ 
	return(CreditHrs);
}


void aCourse :: display()
{
	if (Code != "")
		std::cout << Code << "-" << CreditHrs << " " << Marks << "\n";
}


//	F r i e n d   F u n c t i o n s / O p e r a t o r s   S p e c i f i c a t i o n s

std::istream & operator >> (std::istream & input, aCourse & Course)
{
	do
	{
		Course.Code.input("Enter Course Code: ", 'U');
	}
	while (Course.Code == "");
	
	do
	{
		std::cout << "Enter Credit Hours [1..36]=> "; input >> Course.CreditHrs;
	}
	while ((Course.CreditHrs < 1) || (Course.CreditHrs > 36));
	
	do
	{
		std::cout << "Enter Marks [0..100]=> "; input >> Course.Marks;
	}
	while ((Course.Marks < 0) || (Course.Marks > 100));

	return(input);
}


std::ostream & operator << (std::ostream & output, aCourse Course)
{
	if (Course.Code != "")
		output << Course.Code << "-" << Course.CreditHrs << " " << Course.Marks;

	return(output);
}
#endif // End of _a_COURSES_CLASS_ Specification

/*
int main()
{
	aCourse C("cs2432",4,90);
	std::cout << C << "\n";
	std::cin >> C;
	std::cout << C << "\n";
	C.set("P230", 6, 30);
	std::cout << C << "\n";
	return 1;
}
*/

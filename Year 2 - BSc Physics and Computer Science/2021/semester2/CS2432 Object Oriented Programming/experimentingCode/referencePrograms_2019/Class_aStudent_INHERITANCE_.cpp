/*
	FILE NAME: Class{aStudent_INHERITANCE}.cpp
	FUNCTION:
	A student class is inherited from a person's class

	(C) mofana mphaka; 14th February 2006
		Edited: February 2021
*/

#ifndef _a_STUDENTS_CLASS_
#define _a_STUDENTS_CLASS_

#include<C:\Users\Mofan\OneDrive\Documents\CS2432{OOP}\programs\Class{aPerson}.cpp>
#include<C:\Users\Mofan\OneDrive\Documents\CS2432{OOP}\programs\Class{aCourse}.cpp>

class aStudent	:	public aPerson
{
	private:
		aString		Institution,
					DegreeProgramme;

		aDate		DateOfEnrollment,			//	All dates initialised
					ExpectedDateOfCompletion;	//	to 1st January 1900

		int			YearOfStudy;

		aCourse		*Course;	//	List of courses taken by the student
		int			TotalCourses;
		double		OWM;
		aString		Recommendation;

		void initialiseStudentInfo();
		/*	Initialises all student's variables: OWM, etc */

		void initialiseCourseList();
		/*	Creates and allocates space for the student course list */

		bool found(aCourse & _aCourse);
		/*	Returns true is this course, _aCourse, is a member of the 
			student's courses, * Course
		*/

		void sort();
		/*	Sorts the student's courses on their descending order of their marks,
			for presentation of results. The sorting algorithm is bubble sort
		*/


	public:
		//	Constructor -- polymorphic

		aStudent(char * aSurname = "", char * aFirstName = "", int aYear = 1900, int aMonth = 1, int a_Date = 1, char aSex = 'M');

		//	Destructor

		~aStudent() {}

		//	Input Functions

		void inputDateOfEnrollment();
		/*	Inputs date of enrollment, interactively, ensuring that date of 
			enrollment comes after date of birth */

		void inputExpectedDateOfCompletion();
		/*	Inputs information on expected date of completion, interactively,
			ensuring that expected date of completion comes after date of enrollment */

		void inputInstitution();
		/*	Inputs the Institution's name interactively */

		void inputDegreeProgramme();
		/*	Inputs the degree programme interactively */

		void inputYearOfStudy();
		/*	Inputs the year of study interactively */

		void inputCourses();
		/*	Inputs all the student's courses: Course Codes, Credit Hrs & Marks */

		void input();
		/*	Inputs all the bio-data of student -- overrides input() of aPerson */


		//	Output Functions
		
		void displayDateOfEnrollment();
		/* Displays enrollment date in long date format, e.g. 1st January 1964 */

		void displayExpectedDateOfCompletion();
		/* Displays expected date of completion in long date format */

		void display();
		/*	Displays student's bio-data -- again overrides display() of aPerson */

		void displayCourses();
		/*	Displays student's courses as: Code - CreditHrs Marks Grades */


		//	Assessment Rules

		void assess();
		/*	Assesses the student according to the given rules */
};



aStudent :: aStudent(char * aSurname, char * aFirstName, int aYear, int aMonth, int _aDate, char aSex)
			: aPerson(aSurname, aFirstName, aYear, aMonth, _aDate, aSex)
//	Construct a student as a Person
{
	initialiseStudentInfo();	//	Then fill the student's particular info
}


void aStudent :: initialiseStudentInfo()
{
	Institution = DegreeProgramme = Recommendation = "";
	YearOfStudy = TotalCourses = OWM = 0;
}


void aStudent :: inputDateOfEnrollment()
{
	std::cout << "Date of Enrollment Information:\n";
	
	do
	{
		std::cout << "Enter Date after [" << DateOfBirth << "]\n";
		DateOfEnrollment.input();
	}
	while(DateOfEnrollment <= DateOfBirth);
}


void aStudent :: inputExpectedDateOfCompletion()
{
	std::cout << "Expected Date of Completion Information:\n";

	do
	{
		std::cout << "Enter Date after [" << DateOfEnrollment << "]\n";
		ExpectedDateOfCompletion.input();
	}
	while(ExpectedDateOfCompletion <= DateOfEnrollment);
}


void aStudent :: inputInstitution()
{
	Institution.input("Enter Name of Institution: ", 'U');
}


void aStudent :: inputDegreeProgramme()
{
	DegreeProgramme.input("Enter Degree Programme: ", 'U');
}


void aStudent :: inputYearOfStudy()
{
	do
	{
		std::cout << "Enter year of study [1..10] => ";
		std::cin >> YearOfStudy;
	}
	while ((YearOfStudy < 1) || (YearOfStudy > 10));
}


void aStudent :: input()
{
	aPerson::input();	//	Access input() of a aPerson
	inputInstitution();
	inputDegreeProgramme();
	inputYearOfStudy();
	inputDateOfEnrollment();
	inputExpectedDateOfCompletion();
	inputCourses();
	assess();
}

		
void aStudent :: displayDateOfEnrollment()
{ 
	DateOfEnrollment.display(1);
}


void aStudent :: displayExpectedDateOfCompletion()
{ 
	ExpectedDateOfCompletion.display(1);
}


void aStudent :: initialiseCourseList()
{
	std::cout << "How many courses for this student? ";
	std::cin >> TotalCourses;

	if (TotalCourses <= 0)
		TotalCourses = 1;

	try
	{
		Course = new aCourse [TotalCourses];
	}
	catch(...)
	{
		std::cout << "\nNot enough Memory to allocate student courses ... Aborting!";
		exit(0);
	}
}


void aStudent :: inputCourses()
{
	aCourse		NextCourse;

	if (TotalCourses <= 0)
		initialiseCourseList();
	
	std::cout << "Gathering Students Course Information:\n";

	for(int i = 0; i < TotalCourses; i++)
	{
		std::cout << "Next Course ?\n";
		bool DuplicateCourse = false;
		do
		{
			std::cin >> NextCourse;
			if (found(NextCourse))
			{
				DuplicateCourse = true;
				std::cout << NextCourse << " is already assigned the student ... Re-Enter\n";
			}
			else
			{
				Course[i] = NextCourse;
				DuplicateCourse = false;
			}
		}
		while (DuplicateCourse);
	}

	//	Now rank the student's courses by their marks
	sort();
}


bool aStudent :: found(aCourse & _aCourse)
{
	for(int i = 0; i < TotalCourses; i++)
	{
		if (Course[i].getCode() == _aCourse.getCode())
			return(true);
	}
	return(false);
}


void aStudent :: sort()
{
	bool sorted = false;

	while (!sorted)
	{
		sorted = true;
		for(int i = 0; i < TotalCourses - 1; i++)
		{
			if (Course[i].getMarks() < Course[i+1].getMarks())
			{
				sorted = false;
				// swap the two courses
				aCourse _aCourse = Course[i];
				Course[i] = Course[i+1];
				Course[i+1] = _aCourse;
			}
		}
	}
}


void aStudent :: assess()
/*	Assesses the student according to the given rules.

	RULES:

	OWM			RECOMMENDATION
	=================================================
	>= 75		First Class [ (i) ]
	70 - 74		Second Class, First Division [2(i)]
	60 - 69		Second Class, Second Division [2(ii)]
	50 - 59		Pass
	< 50		Fail

	OWM CALCULATION

	1.	Sum all course credit hrs 
	2.	Sum all the products: course credit hrs * marks
	3.	OWM = 1 / 2
  */
{
	int		TotalCreditHrs = 0;
	double	TotalWeightedMarks = 0;

	//	Compute OWM

	for(int i = 0; i < TotalCourses; i++)
	{
		TotalCreditHrs += Course[i].getCreditHrs();
		TotalWeightedMarks += Course[i].getCreditHrs() * Course[i].getMarks();
	}

	OWM = TotalWeightedMarks / TotalCreditHrs;

	//	Compute Recommendation

	(OWM >= 75)?	Recommendation = "First Class [ (i) ]" :
	(OWM >= 70)?	Recommendation = "Second Class, First Division [2(i)]" :
	(OWM >= 60)?	Recommendation = "Second Class, Second Division [2(ii)]" :
	(OWM >= 50)?	Recommendation = "Pass" :
					Recommendation = "Fail";
}


void aStudent :: displayCourses()
{
	std::cout << "\nList of Courses Taken:\n";

	for(int i = 0; i < TotalCourses; i++)
	{
		Course[i].display();
	}
}


void aStudent :: display()
{
	aPerson::display();	//	Access display() of a aPerson
	std::cout << "Institution                : " << Institution << "\n";
	std::cout << "Degree Programme           : " << DegreeProgramme << "\n";
	std::cout << "Year Of Study              : " << YearOfStudy << "\n";
	std::cout << "Date Of Enrollment         : "; DateOfEnrollment.display(1);
	std::cout << "Expected Date Of Completion: "; ExpectedDateOfCompletion.display(1);
	displayCourses();
	std::cout << "\nOWM:   " << OWM << "   Recommendation: " << Recommendation << "\n";
}
#endif // _a_STUDENTS_CLASS_ Specification
/*
int main()
{
	aStudent S("mphaka","mofana");
	S.input();
	S.display();
	return 1;
}*/

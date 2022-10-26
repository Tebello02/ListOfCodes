/*
	PROGRAM: Class{aWorker_INHERITANCE}

	FUNCTION:

	Application of Abstract classes and inheritance. Example instance of a Worker: deriving
	a full time worker and a part-time worker

	(C) mofana mphaka Mar 2007
		Edited: Februruary 2021
*/

#include <C:\Users\Mofan\OneDrive\Documents\CS2432{OOP}\programs\Class{aDate}.cpp>
#include <C:\Users\Mofan\OneDrive\Documents\CS2432{OOP}\programs\Class{aPersonsName}.cpp>
#include <C:\Users\Mofan\OneDrive\Documents\CS2432{OOP}\programs\Class{Currency}.cpp>


class a_worker
{
	protected:
		aPersonsName	name;
		char			sex;
		aDate			date_of_birth;
		currency		gross,
						net,
						tax;

	public:
		//	Default Constructor

		a_worker (char * type_of_worker)
		{
			//	Display on the console what type of worker is being created
			std::cout << "\n" << type_of_worker << "\n";

			//	Initialise gross, net and tax to 0
			gross = net = tax = 0;

			std::cout << "Enter the worker's Surname and Name:\n";
			name.input();	//	get name interactively from the user

			std::cout << "Enter " << name << "'s Date of Birth:\n";
			date_of_birth.input();	//	get date of birth interactively from the user

			sex = getGender();	//	get sex interactively from the user
		}

		//	Virtual member functions -- must be overriden by any derived class(es)
		virtual void computeGross() = 0;
		virtual void computeTax() = 0;
		virtual void display() = 0;

		//	Concrete member functions (they too could be overridden if needs be)
		void computeNet();
		char getGender();
};


class a_full_time_worker : public a_worker
{
	private:
		aString		ID;
		aDate		date_of_employment;

		currency	basic_pay,
					benefits[5];	//	Maximum number of benefits = 5

		int			total_benefits;

		//	private member functions
		void	grantBenefits();

	public:
		//	Default constructor
		a_full_time_worker();

		virtual void computeGross();
		virtual void computeTax();
		virtual void display();

		void	generateID(int index);
};


class a_part_time_worker : public a_worker
{
	private:
		currency	hourly_rate;
		double		hours_worked;

	public:
		//	Default constructor
		a_part_time_worker();

		virtual void computeGross();
		virtual void computeTax();
		virtual void display();
};


//	C l a s s   M e t h o d s   i m p l e m e n t a t i o n s

//	A  W o r k e r
//--------------------------------------------------------------
void a_worker :: computeNet()
{
	net = gross - tax;
}


char a_worker :: getGender()
// Inputs:	No parameters, but reads input from the keyboard
// Outputs:	char (either M or F).
{
	char Sex;

	do
	{
		std::cout << "Enter Gender [M/F]: ";
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

	return Sex;
}
//-------------------------------------------------------------------------


//	A   F u l l   T i m e   W o r k e r
//--------------------------------------------------------------------------
a_full_time_worker :: a_full_time_worker() : a_worker("FULL TIME Worker:")
//	Initialise the full time worker class as a "FULL TIME worker" -- just a message
//	on the console
{
	std::cout << "Enter Date of Employment for " << name << ":\n";

	do
	{
		std::cout << "Enter the date after " << date_of_birth << "\n";
		date_of_employment.input();
	}
	while (date_of_employment <= date_of_birth);

	generateID(0);
	grantBenefits();
}


void a_full_time_worker :: display()
//	Definition:	display(...), displays an employee.
//				
//	Input:		1.	none
//
//	output:		1.	The employee's information is displayed on the screen
{
	std::cout << "============================================================\n";
	std::cout << "Employment Number:  " << ID << "\n";
	std::cout << "Name:               " << name << "\n";
	std::cout << "Sex:                " << ((sex == 'M')? "Male" : "Female") << "\n";
	std::cout << "Date of Birth:      " << date_of_birth << "\n";
	std::cout << "Date of Employment: " << date_of_employment << "\n";

	std::cout << "Basic Pay (p.a):    " << basic_pay << "\n";
	std::cout << "Benefits (p.a):\n";

	for (int i = 0; i < total_benefits; i++)
	{
		std::cout << "        Benefit[" << i+1 << "]: " << benefits[i] << "\n";
	}

	std::cout << "Gross Salary (p.a): " << gross << "    (p.m):  " << gross/12 << "\n";
	std::cout << "Tax (p.a):          " << tax << "    (p.m):  " << tax/12 << "\n";
	std::cout << "Net Salary (p.a):   " << net << "    (p.m):  " << net/12 << "\n";
	std::cout << "============================================================\n";
}


void a_full_time_worker :: computeGross()
{
	std::cout << "Enter Basic Pay amount (p.a) for " << name << ": " ;
	basic_pay.input(basic_pay.getCurrencySymbol());

	gross = 0;

	for (int i = 0; i < total_benefits; i++)
		gross = gross + benefits[i];

	gross = gross + basic_pay;

	computeTax();
	computeNet();
}


void a_full_time_worker :: computeTax()
//	Definition:	computeTax(...), computes pay as you earn according to the set rules.
//
//	Input:		1.	none
//
//	Output:		1.	The tax, according to the following rules:
//				(a)	the first M8,000.00 is tax free
//				(b)	the next M20,000.00 is taxed at 15%
//				(c)	the next M40,000.00 is taxed at 25%
//				(d)	the balance is taxed at 35%
{
	currency	Gross;

	//	Get taxable income from Gross
	Gross = gross - 8000;	//	M8,000.00 is tax free
	tax = 0;

	if (Gross > 0)
	{
		//	Tax the next M20,000.00

		if (Gross > 20000)
		{
			tax = tax + 0.15 * 20000;
			Gross = Gross - 20000;
			
			//	Tax the Next M40,000.00
			if (Gross > 40000)
			{
				tax = tax + 0.25 * 40000;
				Gross = Gross - 40000;

				//	Tax the rest at 35%
				if (Gross > 0)
					tax = tax + Gross * 0.35;
			}
			else
				tax = tax + Gross * 0.25;
		}
		else
			tax = tax + Gross * 0.15;
	}
}


void a_full_time_worker :: grantBenefits()
{
	std::cout << "How many benefits does " << name << " have ? [Max = 5] ";
	std::cin >> total_benefits;

	if (total_benefits <= 0)
		total_benefits = 1;

	if (total_benefits > 5)
		total_benefits = 5;

	for (int i = 0; i < total_benefits; i++)
	{
		std::cout << "Enter the amount (p.a) of Benefit[" << i+1 << "] ";
		benefits[i].input(benefits[i].getCurrencySymbol());
	}
}


void a_full_time_worker :: generateID(int index)
//	Definition:	generateEmploymentNo(...), generates an employment number from an
//				employee's bio-data such as the names, dates (of birth and employment)
//				and sex. It then appends a serial number index, index, to it.
//
//	Input:		1.	The serial number to append at the end, index.
//
//	Output:		1.	The employment number, as a string
{
	ID = "\0";	//	Initiall ID = null string

	//	Concatenate the first 3 characters from Surname
	if (name.getSurname().size() > 0)
	{
		//	Surname has at least 1 character in it, append it to the employment number
		ID += name.getSurname()[0];

		if (name.getSurname().size() > 1)
			//	Surname is at least 2 characters, append the 2nd character
			ID += name.getSurname()[1];

		if (name.getSurname().size() > 2)
			//	Surname is at least 3 characters, append the 3rd character
			ID += name.getSurname()[2];
	}

	//	Then concatenate  "00" if employee is male otherwise "01"
	if (sex == 'M')
		ID += "00";
	else
		ID += "01";
	
	//	Then concatenate the first 3 characters from first name
	if (name.getFirstName().size() > 0)
	{
		ID += name.getFirstName()[0];

		if (name.getFirstName().size() > 1)
			ID += name.getFirstName()[1];

		if (name.getFirstName().size() > 2)
			ID += name.getFirstName()[2];
	}

	//	Then concatenate the date of birth

	//	First, concatenate the date
	if (date_of_birth.getDate() <= 9)
		//	Pad with the leading "0"
		ID += "0";

	ID += int_to_str(date_of_birth.getDate());

	//	Then, concatenate the month
	if (date_of_birth.getMonth() <= 9)
		ID += "0";

	ID += int_to_str(date_of_birth.getMonth());

	//	Then, last concatenate the year of birth
	ID += int_to_str(date_of_birth.getYear());

	//	Then, put the first dash
	ID += "-";
	
	//	Then concatenate the date of employment

	if (date_of_employment.getDate() <= 9)
		ID += "0";

	ID += int_to_str(date_of_employment.getDate());

	if (date_of_employment.getMonth() <= 9)
		ID += "0";

	ID += int_to_str(date_of_employment.getMonth());

	ID += int_to_str(date_of_employment.getYear());

	//	Then, put the second dash
	ID += "-";

	// Then, append the index number
	ID += int_to_str(index);
	//	the employment number has been fully generated
}
//--------------------------------------------------------------------------


//	A   P a r t   T i m e   W o r k e r
//--------------------------------------------------------------------------
a_part_time_worker :: a_part_time_worker() : a_worker("PART TIME Worker:")
//	Initialise the part-time worker class as a "PART TIME worker" -- just a message
//	on the console
{
	hours_worked = 0;
	hourly_rate = 0;
}


void a_part_time_worker :: display()
//	Definition:	display(...), displays a part time worker
//				
//	Input:		1.	none
//
//	output:		1.	The employee's information is displayed on the screen
{
	std::cout << "============================================================\n";
	std::cout << "Name:               " << name << "\n";
	std::cout << "Sex:                " << ((sex == 'M')? "Male" : "Female") << "\n";
	std::cout << "Date of Birth:      " << date_of_birth << "\n";
	std::cout << "Hours Worked:       " << hours_worked << "\n";
	std::cout << "Hourly Rate:        " << hourly_rate << "/hr\n";
	std::cout << "Gross Pay:          " << gross << "\n";
	std::cout << "Tax:                " << tax << "\n";
	std::cout << "Net Pay:            " << net << "\n";
	std::cout << "============================================================\n";
}


void a_part_time_worker :: computeGross()
{
	std::cout << "Enter Total Hours worked for " << name << " "; std::cin >> hours_worked;

	if (hours_worked < 0)
		hours_worked = 0;

	std::cout << "Enter Hourly Rate "; hourly_rate.input(hourly_rate.getCurrencySymbol());

	gross = hourly_rate * hours_worked;

	computeTax();
	computeNet();
}


void a_part_time_worker :: computeTax()
//	Definition:	computeTax(...), computes the income tax for a part-time worker according
//				the given rules.
//
//	Input:		1.	none
//
//	Output:		1.	The tax, according to the rule:
//					if gross > M8,000.00 then tax = 5% of gross, otherwise tax = 0.
{
	tax = 0;

	if (gross > 8000)
		tax = gross * 0.05;
}
//--------------------------------------------------------------------------


//	Main program to test the two derived classes
/*
int main()
{
	a_full_time_worker worker1;
	worker1.computeGross();

	a_part_time_worker worker2;
	worker2.computeGross();

	worker1.display();
	worker2.display();

	return 1;
}
*/

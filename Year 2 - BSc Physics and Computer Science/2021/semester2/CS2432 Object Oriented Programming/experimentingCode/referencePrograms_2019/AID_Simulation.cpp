/*
PROGRAM NAME: AIDS_Simulation.cpp
FUNCTION:

  The program applies the pseudo random generator function of C++
  to simulate a list of individuals having sex. After simulation the
  program then prints the HIV\AIDS status of each individual.

(C) mofana mphaka; January 2007
Edited: February 2021
*/

#include <iostream>
#include <cstdlib>
#include <ctime>


class aPerson
{
	private:
		int id;			//	An individual ID instead of a name for anonimity
		double status;	//	HIV/AIDS status of the individual
		int Condom,		//	Frequency count on the usage of condoms during sex
			NoCondom;	//	Frequency count on the non-usage of condoms during sex

	public:
		//	C l a s s   C o n s t r u c t o r 

		aPerson(int person = 0);
		/*	Sets id to person (default is 0), status and (non)usage of condoms to zero */

		//	C l a s s  D e s t r u c t o r
		~aPerson() {}

		//	C l a s s   M e m b e r   F u n c t i o n s

		void input();
		/*	Asks for id from the user via the keyboard
			sets status and (non)usage of condoms to 0 */

		void set(int person = 0);
		/*	Sets id to person, status and (non)usage of condoms to 0 */

		void display();
		/*	Displays the person's particulars including HIV/AIDS status */

		void have_sex();
		/*	Simulates the individul having sex */
};


aPerson::aPerson(int person)
{
	if (person < 0)
		person = (-1) * person;

	id = person;
	status = 0;
	Condom = NoCondom = 0;
}


void aPerson::set(int person)
{
	if (person < 0)
		person = (-1) * person;

	id = person;
	status = 0;
	Condom = NoCondom = 0;
}


void aPerson::input()
{
	std::cout << "Enter an Id ";
	std::cin >> id;

	if(id < 0)
		id = (-1) * id;
	
	status = 0;
	Condom = NoCondom = 0;
}


void aPerson::display()
{
	std::cout << id << "\t";

	if(status >= 0.75)
		std::cout << "Full Blown AIDS";
	else if (status >= 0.5)
		std::cout << "HIV Positive";
	else // status < 0.5)
		std::cout << "HIV Negative";
	std::cout << "\t" << NoCondom+Condom << "\t\t" << NoCondom << "\t\t" << Condom << "\n";
}


void aPerson::have_sex()
{
	if (status > 1)
		status = 1;
	else
	{
		//	Compute cumulative HIV/AIDS status of an individual when having sex
		//	1.	When Not using a condom the risk is 0.004
		//	2.	When using a condom the risk is 0.2 * 0.004 = 0.0008
		//		0.20 is an average failure rate of condoms.
		//	3.	On the average, an individual uses a condom 40% of the time during sex

		int j = rand() % 10;	//	retrieve a random number in the range: 0..9

		//	Decide, at random, whether an individual uses a condom or not

		if((j % 3) == 0)
		{
			//	An individual uses a condom 40% of the time during sex
			//	i.e j = 0, 3, 6, 9. These are 4 numbers out of 10, which is 40%
			status = status + 0.0008;
			Condom++;	//	Accumulate condom usage frequency
		}
		else
		{
			//	The rest of the other time, i.e. 60%, no condom is used
			status = status + 0.004;
			NoCondom++;
		}
	}
}


void makeSample(aPerson * person, int SampleSize)
//	Create a sample space of individuals of size, SampleSize
{
	int i;

	//	Assign ids to the individuals for anonimity
	for(i = 0; i < SampleSize; i++)
	{
		person[i].set(i+1);	//	Ids are just serial numbers from 1 to SampleSize
	}
}


void randomiseSample(int * RandomList, int Simulations, int SampleSize)
//	Make a random List of individuals: 0..SampleSize-1
{
	int i;

	srand(time(0));	//	set the random sequence to time random seed
	for(i = 0; i < Simulations; i++)
	{
		//	1.	Generate random numbers in the range: 0..SampleSize-1, and
		//	2.	Collect them in a list, RandomList.
		RandomList[i] = rand() % SampleSize;
	}
}


void simulateSampleSex(aPerson * person, int SampleSize, int * RandomList, int Simulations)
//	Simulate individuals having sex, at random
{
	int i, j;
	for(i = 0; i < Simulations; i++)
	{
		j = RandomList[i] % SampleSize;	//	Pick an individual at random: 0..SampleSize-1
		person[j].have_sex();			//	Let that individual have sex
	}
}


void displaySimulationResults(aPerson * person, int SampleSize)
//	Print HIV\AIDS status for each individual
{
	int i;

	std::cout << "\n\t\t\tSIMULATION RESULTS\n";
	std::cout << "\t\t\t==================\n";
	std::cout << "Id\t" << "Status\t\t" << "Sex Acts\t";
	std::cout << "No Condom\t" << "Using Condom\n";
	std::cout << "--------------------------------------------------------------------\n";
	for(i = 0; i < SampleSize; i++)
	{
		person[i].display();
	}
}


int main()
{
	aPerson * person;	//	A list of people to experiment with
	int * RandomList;	//	A list of random choices
	int SampleSize,		//	The number of individuals to experiment with
		Simulations;	//	The number of random choices to make

	char ans = 'Y';

	do
	{

		std::cout << "How many individuals to simulate?, i.e. Sample Size = ";
		std::cin >> SampleSize;

		std::cout << "How many Simulation Runs? ";
		std::cin >> Simulations;

		person = new aPerson [SampleSize];
		RandomList = new int[Simulations];

		//	Create a a sample space of individuals, SampleSize
		makeSample(person, SampleSize);

		//	Make a random List of individuals: 0..SampleSize-1
		randomiseSample(RandomList, Simulations, SampleSize);
		
		//	Simulate individuals having sex, at random
		simulateSampleSex(person, SampleSize, RandomList, Simulations);
		
		//	After simulation, print HIV\AIDS status for each individual
		displaySimulationResults(person, SampleSize);
		
		std::cout << "Anymore Simulations to Run? [Y/N]";
		std::cin >> ans;
	}
	while ((ans == 'Y')||(ans == 'y'));

	return(1);
}

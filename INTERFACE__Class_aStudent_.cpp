/*
	FILE NAME: Class{aStudent}.cpp
	
	FUNCTION:
	
	The file implements a class about student records.
	The class is also designed to store and retrieve student to and from file streams.
	The file stream can be a text file or a binary file.
		
	(C) mofana mphaka; March 2020
*/


#include <iostream>
#include <fstream>

#if ! defined _a_STUDENT_CLASS_
#define _a_STUDENT_CLASS_

using namespace std;

class aStudent
{
	//	D a t a   E n c a p s u l a t i o n 
	private:
		char	name[20];
		double	CWK,
				Exam,
				Overall;
		int     credit_hrs;
	
	//	M e m b e r   F u n c t i o n s   -- to give safe access to the encapsulated data
	public:
		aStudent();
		/*	It initialises the data elements as: 
			(1) name to empty string
			(2) CWK, Exam and Overall to minus one.
		*/
		
		~aStudent() {}
		
		void input();
		/*	It allows interactive input to the data values:
			(1) name -- must not be empty
			(2) CWK and Exam -- must be in the range: 0 ... 100
			(3) It allows for computation of Overall, if not already computed
		*/
		
		void display();
		/*	It displays the student data on the screen as:
		
			name	CWK		Exam	Overall
			
			NB: Only real data is displayed. For example if Exam = -1, it will not be displayed
		*/
		
		
		double	compute_overall(double CWk_weight = 0.40, double Exam_weight = 0.60);
		/*	It is polymorphic.
			It uses the given CWK and Exam weights (as fractions) to compute Overall.
			This function is not interactive, but it always makes sure that the sum of the weights always adds up to 1.
			
			For example, if CWK_weight = 0.3 and Exam_weight = 0.5, it will set CWK_weight to 0.3+0.2 = 0.5
			if CWK_weight = 0.3 and Exam_weight = 0.8, it will set CWK_weight to 1-0.8 = 0.2. It does similar
			computations if it is the Exam_weight that needs to be adjusted.
		*/
		
		void write(fstream & file, int binary = 1);
		/*	It writes this student to a file in binary, by default.	If binary = 0, it writes in text mode.
			NB: it assumes that "file" is opened and then it makes a guarded writing to the file
		*/
		
		void read(fstream & file, int binary = 1);
		/*	It reads this student from a file in binary, by default. If binary = 0, it reads in text mode.
			NB: it assumes that "file" is opened and then it makes a guarded reading from the file
		*/

		void save();
		/*	It allows the user to specify the file to save the student data to.
			It also allows the user to select the file format: Binary or Text.
			It then saves the student data in the specified file format
		*/
		
		void read();
		/*	It allows the user to specify the file to read the student data from.
			It also allows the user to select the file format: Binary or Text.
			It then reads the student data in the specified file format
		*/
		
	
	//	O v e r l o a d e d    M e m b e r   O p e r a t o r s
	
	aStudent operator = (aStudent right);
	/*	It assigns this student to the student on the right. I.e. The studnt on the left assumes all the data values of
		the student on the right
	*/
	
	bool operator == (aStudent right);
	/*	It returns true if this student and the student on the right have the same overall mark.
		It return false otherwise
	*/
	
	bool operator != (aStudent right);
	/*	It returns true if this student and the student on the right do not have the same overall mark.
		It return false otherwise
	*/
	
	bool operator > (aStudent right);
	/*	It returns true if this student has a better overall mark than the student on the right.
		It return false otherwise
	*/
	
	bool operator < (aStudent right);
	/*	It returns true if this student has a lower overall mark than the student on the right.
		It return false otherwise
	*/
	
	bool operator >= (aStudent right);
	/*	It returns true if this student has a better or equal overall mark than the student on the right.
		It return false otherwise
	*/
	
	bool operator <= (aStudent right);
	/*	It returns true if this student has a lower or equal overall mark than the student on the right.
		It return false otherwise
	*/
	
		
	//	O v e r l o a d e d    F r i e n d    O p e r a t o r s: The >> and << operators for both CONSOLE and FILE
	
	friend istream & operator >> (istream & input, aStudent & Student);
	/*	Interative input using the insertion operator, >>, -- same as input member function
	*/
	
	friend ostream & operator << (ostream & output, aStudent Student);
	/*	Displays student data on the screen using the extraction operator, <<, -- same as display member function
	*/
	
	
	friend fstream & operator >> (fstream & file, aStudent & Student);
	/*	It assumes that the file is opened. It reads the formatted student data from the text file.
		NB: the reading is guarded. That is, there will be no reading attempt if there is any problem with the file
	*/
	
	friend fstream & operator << (fstream & file, aStudent Student);
	/*	It assumes that the file is opened. It writes the formatted student data to the text file. The format is that the
		data elements: name, CWK, Exam and Overall are separated by a tab. This student data is separated from the
		next record by a newline.
		NB: the writing is guarded. That is, there will be no writing attempt if there is any problem with the file
	*/
};

#endif


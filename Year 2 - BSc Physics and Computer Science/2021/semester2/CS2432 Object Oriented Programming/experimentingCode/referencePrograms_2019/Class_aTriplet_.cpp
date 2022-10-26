/*
	NAME: Class{aTriplet}.cpp
	
	FUNCTION:
	
		The program shows inheritance in generic programming. In the program,
		initially, class "aPair" from the file "Class{aPair}.cpp, is created to hold a 
		pair of "things": (obj1, obj2). Then a derived class from class aPair, aTriplet,
		is created to hold 3 "things": (obj1, obj2, obj3).
	
	AUTHOR: mofana mphaka; April 2020
*/
#include <iostream>
#include <fstream>

#include <c:\users\mofan\OneDrive\documents\cs2432{oop}\programs\Class{aPair}.cpp>

#if ! defined _A_TRIPLET_CLASS_
#define _A_TRIPLET_CLASS_

template <class T1, class T2, class T3>
class aTriplet : public aPair<T1, T2>
{
	private:
		T3 obj3;	//	The 3rd component of the triplet. obj1 and obj2 are inherited from aPair
		
	public:
		//	T h e   g e t   a n d   s e t   d a t a   f u n c t i o n s
		
		T3 get_obj3();
		/*	Returns obj3 to any calling environment*/
		
		void set_obj3(T3 value3);
		/*	Sets the value obj3 to value */
		//-------------------------------------------------------------
		
		
		//	T h e   c o n s t r u c t o r  --  p o l y m o r p h i c   &   d e s t r u c t o r
		
		aTriplet(T1 value1 = 0, T2 value2 = 0, T3 value3 = 0);
		/*	It construts a triplet as three components: (value1, value2, value3).
			The default is void: (, , ).
		 */
		 
		~aTriplet() {}
		/*	It's empty. The structure will be destroyed using C++ scoping rules	*/
		//-------------------------------------------------------------
		
		
		//	O t h e r   M e m b e r   F u n c t i o n s
		
		void input();
		/*	It allows user to enter the the three components, interactively from the console */
		
		void display();
		/*	It displays the three components as: (obj1, obj2, obj3) */
		
		void write(std::fstream & file, int binary = 1);
		/*	It writes the triplet to a binary file (i.e. the default) or a text file as follows:
		
			(1)	The first component, obj1, is written then
			(2)	the second component, obj2 is written and lastly
			(3)	the third component, obj3 is written.
			
			In text mode, the components are separated by a tab and the triplet is ended with a newline
		*/
		
		void read(std::fstream & file, int binary = 1);
		/*	It reads the triplet from a binary file (i.e. the default) or a text file as follows:
		
			(1)	The first component, obj1, is read then
			(2)	the second component, obj2 is read and lastly
			(3)	the third component, obj3 is read
		*/
		
		void save();
		/*	It interactively allows the user to enter the name of the file to save the triplet to.
			Further it asks the user to enter the file mode of the file, i.e. whether the file is a
			"binary" or a "text" file.
			
			If the file can be opened, the triplet data is saved to that file, overwitting any existing data
		*/

		void read();
		/*	It interactively allows the user to enter the name of the file to read the triplet from.
			Further it asks the user to enter the file mode of the file, i.e. whether the file is a
			"binary" or a "text" file.
			
			The file is opened as read only.
		*/
		//-------------------------------------------------------------
		
		
		//	M e m b e r   O p e r a t o r s
		
		bool operator == (aTriplet<T1, T2, T3> right);
		/*	It returns true if the triplet on the right is the same as the triplet on the left,
			false otherwise */

		bool operator != (aTriplet<T1, T2, T3> right);
		/*	It computes !((*this) == right */

		aTriplet<T1, T2, T3> operator = (aTriplet<T1, T2, T3> right);
		/*	It computes: (*this) = right */
		//-------------------------------------------------------------
};


//	C l a s s   I m p l e m e n t a t i o n  --  
//	M e m b e r   F u n c t i o n s   S p e c i f i c a t i o n s

template <class T1, class T2, class T3>
aTriplet<T1, T2, T3> :: aTriplet(T1 value1, T2 value2, T3 value3) : aPair<T1, T2>(value1, value2), obj3(value3)
{
}


template <class T1, class T2, class T3>
void aTriplet<T1, T2, T3> :: input()
{
	//	Use the input function from aPair to enter the first 2 components
	aPair<T1, T2> :: input();
	
	//	Now input the third component
	std::cout << "Input the 3rd component, obj3 = ";
	std::cin >> obj3;
}


template <class T1, class T2, class T3>
void aTriplet<T1, T2, T3> :: display()
{
	std::cout << "(" << this ->aPair<T1, T2> :: get_obj1() << ", " << aPair<T1, T2> :: get_obj2() << ", " << obj3 << ")";
	//	NB: aPair<T1, T2> :: get_obj1() == this -> get_obj1() == get_obj1() == this ->aPair<T1, T2> :: get_obj1()
}


template <class T1, class T2, class T3>
T3 aTriplet<T1, T2, T3> :: get_obj3()
{
	return obj3;
}
		

template <class T1, class T2, class T3>
void aTriplet<T1, T2, T3> :: set_obj3(T3 value3)
{
	//	Assume "=" appropriately overloaded for class T3 or T3 is a basic type
	obj3 = value3;
}


template <class T1, class T2, class T3>
bool aTriplet<T1, T2, T3> :: operator == (aTriplet<T1, T2, T3> right)
{
	return	(this->get_obj1() == right.get_obj1()) && 
			(this->get_obj2() == right.get_obj2()) && 
			(this->obj3 == right.obj3);
}


template <class T1, class T2, class T3>
bool aTriplet<T1, T2, T3> :: operator != (aTriplet<T1, T2, T3> right)
{
	return !(*this == right);	//	Code re-use of operator "=="
}


template <class T1, class T2, class T3>
aTriplet<T1, T2, T3> aTriplet<T1, T2, T3> :: operator = (aTriplet<T1, T2, T3> right)
{
	this->set_obj1(right.get_obj1());
	this->set_obj2(right.get_obj2());
	this->set_obj3(right.obj3);
	
	return (*this);
}


template <class T1, class T2, class T3>
void aTriplet<T1, T2, T3> :: write(std::fstream & file, int binary)
{
	if (file.good())
	{
		if (binary)
		{
			try
			{
				T1 value1 = aPair<T1, T2> :: get_obj1();
				T2 value2 = aPair<T1, T2> :: get_obj2();
				T2 value3 = get_obj3();
				
				// Write the first component, value1
				file.write((char *) & value1, sizeof(value1));
			
				//	and the second component, value2
				file.write((char *) & value2, sizeof(value2));
				
				//	and the third component, value3
				file.write((char *) & value3, sizeof(value3));
			}
			catch(...)
			{
				std::cout << "File is Bad ... ABORTING!\n";
				exit(0);
			}
		}
		else	//	Text file mode
		{
			try
			{
				// Write obj1, obj2 and obj3, separated by a tab, ending with a newline
				file << this -> get_obj1() << "\t" << this -> get_obj2() << "\t" << get_obj3() << "\n";
			}
			catch(...)
			{
				std::cout << "File is Bad ... ABORTING!\n";
				exit(0);
			}
		}
	}
}


template <class T1, class T2, class T3>
void aTriplet<T1, T2, T3> :: read(std::fstream & file, int binary)
{
	if (file.good())
	{
		T1 value1;
		T2 value2;
		T3 value3;

		if (binary)
		{
			try
			{
				// Read the first component, value1
				file.read((char *) & value1, sizeof(value1));
			
				//	and the second component, value2
				file.read((char *) & value2, sizeof(value2));
				
				//	and the third component, value3
				file.read((char *) & value3, sizeof(value3));
			}
			catch(...)
			{
				std::cout << "File is Bad ... ABORTING!\n";
				exit(0);
			}
		}
		else	//	Text file mode
		{
			try
			{
				// Read the first component, obj1, and the second component, obj2
				file >> value1 >> value2 >> value3;
			}
			catch(...)
			{
				std::cout << "File is Bad ... ABORTING!\n";
				exit(0);
			}
		}
		
		this -> set_obj1(value1);
		this -> set_obj2(value2);
		set_obj3(value3);
	}
}


template <class T1, class T2, class T3>
void aTriplet<T1, T2, T3> :: save ()
{
	std::fstream file;
	char file_name[256], file_format;
	int	file_open_mode;
	
	do
	{
		std::cout << "Enter file name to Save the Triplet to  ";
		std::cin >> file_name;
	}while (file_name == "");
	
	do
	{
		std::cout << "\nWhat is the file format? [B]inary or [T]ext ? ";
		std::cin >> file_format;
	}while ((file_format != 'T') && (file_format != 't') && (file_format != 'b') && (file_format != 'B'));
	
	if ((file_format == 'b') || (file_format == 'B'))
	{
		file_open_mode = 1;	//	File format is binary
		file.open((char *) file_name, std::ios::out|std::ios::binary);
	}
	else
	{
		file_open_mode = 0;	//	text file format
		file.open((char *) file_name, std::ios::out);
	}

	if (file.good())
	{
		this->write(file, file_open_mode);
		std::cout << "\n" << (*this) << " saved to file ==> " << file_name << " <==\n";
	}
	else
		std::cout << "Could not open ==> " << file_name << " <== for writing ... something is wrong\n";

	file.close();
}


template <class T1, class T2, class T3>
void aTriplet<T1, T2, T3> :: read ()
{
	std::fstream file;
	char file_name[256], file_format;
	int	file_open_mode;
	
	do
	{
		std::cout << "Enter file name to Read the Triplet from  ";
		std::cin >> file_name;
	}while (file_name == "");
	
	do
	{
		std::cout << "\nWhat is the file format? [B]inary or [T]ext ? ";
		std::cin >> file_format;
	}while ((file_format != 'T') && (file_format != 't') && (file_format != 'b') && (file_format != 'B'));
	
	if ((file_format == 'b') || (file_format == 'B'))
	{
		file_open_mode = 1;	//	File format is binary
		file.open((char *) file_name, std::ios::in|std::ios::binary);
	}
	else
	{
		file_open_mode = 0;	//	text file format
		file.open((char *) file_name, std::ios::in);
	}


	if (file.good())
	{
		this->read(file, file_open_mode);
		std::cout << "\nRead " << (*this) << " from ==> " << file_name << " <==\n";
	}
	else
		std::cout << "Could not open ==> " << file_name << " <== for reading ... something is wrong\n";
	
	file.close();
}


//	O v e r l o a d e d    n o n - m e m b e r,  n o n - f r i e n d   o p e r a t o r s

template <class T1, class T2, class T3>
std::istream & operator >> (std::istream & input, aTriplet<T1, T2, T3> & T)
{
	T.aPair<T1, T2> :: input();
	
	//	Now input the third component
	T3 data;
	
	std::cout << "Input the 3rd component, obj3 = ";
	input >> data;
	T.set_obj3(data);
	
	return input;
}


template <class T1, class T2, class T3>
std::ostream & operator << (std::ostream & output, aTriplet<T1, T2, T3> T)
{
	std::cout << "(" << T.get_obj1() << ", " << T.get_obj2() << ", " << T.get_obj3() << ")";
}


template <class T1, class T2, class T3>
std::fstream & operator >> (std::fstream & input, aTriplet<T1, T2, T3> & right)
/*	Overload the insertion oporator, >>, to read the triplet right from the file, input.

	The triplet data is read as: obj1 obj2, obj3.
*/
{
	if (input.good())
	{
		T1 value1;
		T2 value2;
		T3 value3;
		
		try
		{
			// Read the 3 components: value1, value2 and value3
			input >> value1 >> value2 >> value3;
		}
		catch(...)
		{
			std::cout << "File is Bad ... ABORTING!\n";
			exit(0);
		}
		
		right.set_obj1(value1);
		right.set_obj2(value2);
		right.set_obj3(value3);
	}

	return(input);
}


template <class T1, class T2, class T3>
std::fstream & operator << (std::fstream & output, aTriplet<T1, T2, T3> right)
/*	Overload the extraction oporator, <<, to write the triplet right to the file, output.

	The triplet data is written as: obj1 <TAB> obj2 <TAB> obj3 <NEWLINE>.
*/
{
	if (output.good())
	{
		try
		{
			// Write obj1, obj2 and obj3, separated by a tab, ending with a newline
			output << right.get_obj1() << "\t" << right.get_obj2()  << "\t" << right.get_obj3() << "\n";
		}
		catch(...)
		{
			std::cout << "File is Bad ... ABORTING!\n";
			exit(0);
		}
	}

	return(output);
}		
#endif

/*
int main()
{
	aTriplet<double, double, double> T1, T2;
	
	std::cout << "Enter Data for the T1\n" ;
	std::cin >> T1;
	
	std::cout << "Enter Data for the T2\n" ;
	std::cin >> T2;
	
	//T.save();
	
	if (T1 == T2)
		std::cout << T1 << " == " << T2;
	else
		std::cout << T1 << " != " << T2;
	//T.read();
	
	return 1;
}
*/

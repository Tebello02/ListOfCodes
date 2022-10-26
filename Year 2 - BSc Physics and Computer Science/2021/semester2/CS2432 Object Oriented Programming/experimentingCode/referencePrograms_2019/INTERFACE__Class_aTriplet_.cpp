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

#include <Class{aPair}.cpp>

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
			(3)	the third component, obj3 is written and lastly
			
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
		/*	It returns true if the pair on the right is the same as the pair on the left,
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
	//	C++ Code Here
}


template <class T1, class T2, class T3>
void aTriplet<T1, T2, T3> :: display()
{
	//	C++ Code Here
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
	//	C++ Code Here
}


template <class T1, class T2, class T3>
bool aTriplet<T1, T2, T3> :: operator != (aTriplet<T1, T2, T3> right)
{
	//	C++ Code Here
}


template <class T1, class T2, class T3>
aTriplet<T1, T2, T3> aTriplet<T1, T2, T3> :: operator = (aTriplet<T1, T2, T3> right)
{
	//	C++ Code Here
}


template <class T1, class T2, class T3>
void aTriplet<T1, T2, T3> :: write(std::fstream & file, int binary)
{
	//	C++ Code Here
}


template <class T1, class T2, class T3>
void aTriplet<T1, T2, T3> :: read(std::fstream & file, int binary)
{
	//	C++ Code Here
}


template <class T1, class T2, class T3>
void aTriplet<T1, T2, T3> :: save ()
{
	//	C++ Code Here
}


template <class T1, class T2, class T3>
void aTriplet<T1, T2, T3> :: read ()
{
	//	C++ Code Here
}


//	O v e r l o a d e d    n o n - m e m b e r,  n o n - f r i e n d   o p e r a t o r s

template <class T1, class T2, class T3>
std::istream & operator >> (std::istream & input, aTriplet<T1, T2, T3> & T)
{
	//	C++ Code Here
}


template <class T1, class T2, class T3>
std::ostream & operator << (std::ostream & output, aTriplet<T1, T2, T3> T)
{
	//	C++ Code Here
}


template <class T1, class T2, class T3>
std::fstream & operator >> (std::fstream & input, aTriplet<T1, T2, T3> & right)
{
	//	C++ Code Here
}


template <class T1, class T2, class T3>
std::fstream & operator << (std::fstream & output, aTriplet<T1, T2, T3> right)
{
	//	C++ Code Here
}		
#endif


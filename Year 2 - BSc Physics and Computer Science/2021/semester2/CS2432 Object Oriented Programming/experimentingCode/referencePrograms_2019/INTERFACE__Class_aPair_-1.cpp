/*
	NAME: Class{aPair}.cpp
	
	FUNCTION:
		This is a container class for a pair of "things": (obj1, obj2).
		The class is an example of generic programming in C++ via the use
		of "templates".
	
	AUTHOR: mofana mphaka; April 2020
*/
#include <iostream>
#include <fstream>

#if ! defined _A_PAIR_CLASS_
#define _A_PAIR_CLASS_

template <class Type1, class Type2>

class aPair
{
	private:
		Type1	obj1;
		Type2	obj2;

	public:
		
		//	T h e   g e t   &   s e t   d a t a   f u n c t i o n s
		
		Type1 get_obj1();
		/*	It returns the value of obj1 to any calling environment */
		
		void set_obj1(Type1 value);
		/*	It sets the value of obj1 to value, i.e. obj1 = value */
		
		
		Type2 get_obj2();
		/*	It returns the value of obj1 to any calling environment */
		
		void set_obj2(Type2 value);
		/*	It assigns obj2 to value, i.e. obj2 = value */
		// --------------------------------------------------------------------

		
		//	M e m b e r   O p e r a t o r s
		
		bool operator == (aPair<Type1, Type2> right);
		/*	It returns true if the pair on the right is the same as the pair on the left,
			false otherwise */

		bool operator != (aPair<Type1, Type2> right);
		/*	It computes !((*this) == right */

		aPair<Type1, Type2> operator = (aPair<Type1, Type2> right);
		/*	It computes: (*this) = right */
		// --------------------------------------------------------------------


		//	T h e   C o n s t r u c t o r  &  D e s t r u c t o r
		
		aPair(Type1 val1 = 0, Type2 val2 = 0);
		/*	It constructs a pair with the given initial values. The default is void */

		~aPair() {}
		// --------------------------------------------------------------------

		
		//	O t h e r   M e m b e r   F u n c t i o n s
		
		void input();
		/*	It interactively allows user to enter values for the 1st component as obj1, and
			the 2nd component as obj2.
		*/
		
		void display();
		/*	It displays the pair as: (obj1, obj2) */
		
		void write(std::fstream & file, int binary = 1);
		/*	It writes the pair to a binary file (i.e. the default) or a text file as follows:
		
			(1)	The first component, obj1, is written then
			(2)	the second component, obj2, is written
			
			In text mode, the two components are separated by a tab and the pair is ended with a newline
		*/
		
		void read(std::fstream & file, int binary = 1);
		/*	It reads the pair from a binary file (i.e. the default) or a text file as follows:
		
			(1)	The first component, obj1, is read then
			(2)	the second component, obj2 is read
		*/
		
		void save();
		/*	It interactively allows the user to enter the name of the file to save the pair to.
			Further it asks the user to enter the file mode of the file, i.e. whether the file is a
			"binary" or a "text" file.
			
			If the file can be opened, the pair data is saved to that file, overwitting any existing data
		*/

		void read();
		/*	It interactively allows the user to enter the name of the file to read the pair from.
			Further it asks the user to enter the file mode of the file, i.e. whether the file is a
			"binary" or a "text" file.
			
			The file is opened as read only.
		*/
};


//	T h e   C l a s s   I m p l e m e n t a t i o n --
//	M e m b e r   F u n c t i o n s   S p e c i f i c a t i o n

template <class Type1, class Type2>
aPair<Type1, Type2> :: aPair(Type1 val1, Type2 val2): obj1(val1), obj2(val2)
{
}


template <class Type1, class Type2>
Type1 aPair<Type1, Type2> :: get_obj1()
{
	return obj1;
}


template <class Type1, class Type2>
void aPair<Type1, Type2> :: set_obj1(Type1 value)
{
	obj1 = value;
	//	assume "=" overlaoded for class Type1 or Type1 is a basic type
}


template <class Type1, class Type2>
Type2 aPair<Type1, Type2> :: get_obj2()
{
	return obj2;
}


template <class Type1, class Type2>
void aPair<Type1, Type2> :: set_obj2(Type2 value)
{
	obj2 = value;
	//	assume "=" overlaoded for class Type2 or Type2 is a basic type
}

		
template <class Type1, class Type2>
bool aPair<Type1, Type2> :: operator == (aPair<Type1, Type2> right)
{
	//	C++ Code Here
}


template <class Type1, class Type2>
aPair<Type1, Type2> aPair<Type1, Type2> :: operator = (aPair<Type1, Type2> right)
{
	//	C++ Code Here
}


template <class Type1, class Type2>
bool aPair<Type1, Type2> :: operator != (aPair<Type1, Type2> right)
{
	//	C++ Code Here
}

template <class Type1, class Type2>
void aPair<Type1, Type2> :: input ()
{
	//	C++ Code Here
}


template <class Type1, class Type2>
void aPair<Type1, Type2> :: display ()
{
	//	C++ Code Here
}


template <class Type1, class Type2>
void aPair<Type1, Type2> :: write(std::fstream & file, int binary)
{
	//	C++ Code Here
}


template <class Type1, class Type2>
void aPair<Type1, Type2> :: read(std::fstream & file, int binary)
{
	//	C++ Code Here
}


template <class Type1, class Type2>
void aPair<Type1, Type2> :: save ()
{
	//	C++ Code Here
}


template <class Type1, class Type2>
void aPair<Type1, Type2> :: read ()
{
	//	C++ Code Here
}


//--------------------------------------------------------------------------
//	N o n - M e m b e r   f u n c t i o n s   S p e c i f i c a t i o n s
//--------------------------------------------------------------------------

template <class Type1, class Type2>
std::istream & operator >> (std::istream & input, aPair<Type1, Type2> & right)
{
	//	C++ Code Here
}


template <class Type1, class Type2>
std::ostream & operator << (std::ostream & output, aPair<Type1, Type2> right)
{
	//	C++ Code Here
}


template <class Type1, class Type2>
std::fstream & operator >> (std::fstream & input, aPair<Type1, Type2> & right)
{
	//	C++ Code Here
}


template <class Type1, class Type2>
std::fstream & operator << (std::fstream & output, aPair<Type1, Type2> right)
{
	//	C++ Code Here
}


#endif


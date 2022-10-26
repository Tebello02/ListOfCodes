/*
	NAME: Class{aPair}.cpp
	
	FUNCTION:
		This is a container class for a pair of "things": (obj1, obj2).
		The class is an example of generic programming in C++ via the use
		of "templates".
	
	AUTHOR: mofana mphaka; April 2020
*/
#include <iostream>

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
	//	assume "=" overloaded for class Type1 or Type1 is a basic type
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
	//	assume "=" overloaded for class Type2 or Type2 is a basic type
}

		
template <class Type1, class Type2>
bool aPair<Type1, Type2> :: operator == (aPair<Type1, Type2> right)
{
	//	Assume "==" overloaded for both class Type1 and/or Type2 or 
	//	Type1 and/or Type2 are basic types
	return((this->obj1 == right.obj1) && (this->obj2 == right.obj2));
}


template <class Type1, class Type2>
aPair<Type1, Type2> aPair<Type1, Type2> :: operator = (aPair<Type1, Type2> right)
{
	this->obj1 = right.obj1;
	this->obj2 = right.obj2;

	return (*this);
}


template <class Type1, class Type2>
bool aPair<Type1, Type2> :: operator != (aPair<Type1, Type2> right)
{
	return(!((*this) == right));
}

template <class Type1, class Type2>
void aPair<Type1, Type2> :: input ()
{
	std::cout << "Input 1st component, obj1 = ";
	std::cin >> obj1;	//	Assume ">>" overloaded for class Type1 or Type1 is a basic type

	std::cout << "Input 2nd component, obj2 = ";
	std::cin >> obj2;	//	Assume ">>" overloaded for class Type2 or Type2 is a basic type
}


template <class Type1, class Type2>
void aPair<Type1, Type2> :: display ()
{
	//	Assume "<<" overloaded for Type1 and/or Type2 or 
	//	Type1 and/or Type2 are/is a basic type(s)
	std::cout << "(" << obj1 << ", " << obj2 << ")";
}


//--------------------------------------------------------------------------
//	N o n - M e m b e r   f u n c t i o n s   S p e c i f i c a t i o n s
//--------------------------------------------------------------------------

template <class Type1, class Type2>
std::istream & operator >> (std::istream & input, aPair<Type1, Type2> & right)
{
	Type1 value1;
	Type2 value2;
	
	// Assume that each component of the pair has >> overloaded or it is a built-in type
	std::cout << "Input 1st component, obj1 = ";
	input >> value1; right.set_obj1(value1);

	std::cout << "Input 2nd component, obj2 = ";
	input >> value2; right.set_obj2(value2);

	return(input);
}


template <class Type1, class Type2>
std::ostream & operator << (std::ostream & output, aPair<Type1, Type2> right)
{
	output << "(" << right.get_obj1() << ", " << right.get_obj2() << ")";

	return(output);
}
#endif

/*
int main()
{
	aPair<std::string, char> P("hello");
	
	std::cin >> P;
	std::cout << "\nThe Entered Pair = " << P << "\n";
	
	return 1;
}

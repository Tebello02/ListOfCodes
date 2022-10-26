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
		/*	It constructs a triplet as three components: (value1, value2, value3).
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
	//	Use the input function from aPair to enter the first 2 components
	aPair<T1, T2> :: input();
	
	//	Now input the third component
	std::cout << "Input the 3rd component, obj3 = ";
	std::cin >> obj3;
}


template <class T1, class T2, class T3>
void aTriplet<T1, T2, T3> :: display()
{
	std::cout << "(" << aPair<T1, T2> :: get_obj1() << ", " << aPair<T1, T2> :: get_obj2() << ", " << obj3 << ")";
	//	NB: aPair<T1, T2> :: get_obj1() == this -> get_obj1() == get_obj1()
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
	
	return output;
}
#endif

/*
int main()
{
	aTriplet<double, double, double> T1, T2;
	
	std::cout << "Enter Data for Triplet 1, T1\n" ;
	std::cin >> T1;
	std::cout << "\nEnter Data for Triplet 2, T2\n" ;
	std::cin >> T2;
	std::cout << "\nT1 = " << T1;
	std::cout << "\nT2 = " << T2;
	
	std::cout << "\n" << T1 << " == " << T2 << " = " << (T1 == T2) << "\n";
	std::cout << "\n" << T1 << " != " << T2 << " = " << (T1 != T2) << "\n";
	
	std::cout << "\n\nOld T1 = " << T1 << "\n";
	T1 = T2;
	std::cout << "\n\nNew T1 = " << T1 << "\n";
	
	return 1;
}
*/
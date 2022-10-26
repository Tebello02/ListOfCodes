#include <iostream>
/*	FILE NAME: Class{aWrapper}.cpp

	FUNCTION:
	
	The program shows generic data encapsulation (i.e. wrapping data inside a class), and how to
	declare non-member, non-friend overloaded operators. The example is that of the insertion, >>, 
	and extraction, <<, operators, for inputting and displaying the encapsulated generic data.
	
	AUTHOUR: (c) mofana mphaka; March 2020.
*/

template <class T>
class aWrapper
{
	private:
		T	object; //	Encapsulate the generic data in the variable, object

	public:
		void set(T data);	//	Declare the set function that will assign data to object
		T get();			//	Declare the get function that will avail the generic data
		
};


template <class T>
void aWrapper<T> :: set(T data)
{
	object = data;	//	let the generic data "object" contain this specific "data"
}


template <class T>
T aWrapper<T> :: get()
{
	return object;	//	avail the data of the generic "object"
}


//-------------------------------------------------------------------------//
// O v e r l o a d i n g   t h e   i n s e r t i o n, >>,  o p e r a t o r //
//					f o r   c l a s s   a W r a p p e r						 //
//-------------------------------------------------------------------------//

template <class T>
std::istream & operator >> (std::istream & input, aWrapper<T> & Wrap)
{
	//	input the object -- wrap it
	T data;
	std::cout << "Enter data  "; 
	input >> data;	//	assume >> is overloaded for class T
	
	Wrap.set(data);	//	Encapslate the data in class aWrapper
	
	return input;
}


//---------------------------------------------------------------------------//
// O v e r l o a d i n g   t h e   e x t r a c t i o n, <<,  o p e r a t o r //
//					f o r   c l a s s   a W r a p p e r						 //
//---------------------------------------------------------------------------//

template <class T>
std::ostream & operator << (std::ostream & output, aWrapper<T> UnWrap)
{
	//	output the object -- un-wrap it
	output << UnWrap.get();	//	assume << is overloaded for class T
	return output;
}

/*
int main()
{
	aWrapper<double> P;	// Encapsulate real numbers in P
	
	std::cin >> P;	// the specific real value will be given and wrapped in P
	std::cout << P;	//	the wrapped real value will be displayed
	return 1;
}
*/

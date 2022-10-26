#include <iostream>
/*	FILE NAME: Class{aWrapper__with_Friend_functions}.cpp

	FUNCTION:
	
	The program shows generic data encapsulation (i.e. wrapping data inside a class), and how to
	declare templated friend overloaded operators. The example is that of the insertion, >>, 
	and extraction, <<, operators, for inputting and displaying the encapsulated generic data.
	
	AUTHOUR: (c) mofana mphaka; May 2022.
*/

template <class T>
class aWrapper
{
	private:
		T	object; //	Encapsulate the generic data in the variable, object

	public:
		void set(T data);	//	Declare the set function that will assign data to object
		T get();			//	Declare the get function that will avail the generic data
		

	//	The insertion operator, >>, has a template class, T1 
	//	(i.e. not T, due to scope rules on T). Class T is still in scope here.
	template <class T1>
	friend std::istream & operator >> (std::istream & input, aWrapper<T1> & Wrap);

	//	The extraction operator, <<, has a template class, T1, why?
	//	The reason is that the previous T1 is out of scope here. This is a "new" T1
	template <class T1>
	friend std::ostream & operator << (std::ostream & output, aWrapper<T1> UnWrap);
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

//	We re-use the variable T here!, since the previous T is out of scope here.
//	Its scope ended with the class interface declaration.
template <class T>
std::istream & operator >> (std::istream & input, aWrapper<T> & Wrap)
{
	//	input the object -- wrap it
	std::cout << "Enter data  "; 
	input >> Wrap.object;	//	assume >> is overloaded for class T
	
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
	output << UnWrap.object;	//	assume << is overloaded for class T
	return output;
}


int main()
{
	aWrapper<double> P;	// Encapsulate real numbers in P
	
	std::cin >> P;	// the specific real value will be given and wrapped in P
	std::cout << P<<"\n";	//	the wrapped real value will be displayed
	
	aWrapper<std::string> P1;	// Now encapsulate strings in P1
	
	std::cin >> P1;	// the specific string value will be given and wrapped in P1
	std::cout << P1 << "\n";	//	the wrapped string will be displayed
	
	return 1;
}

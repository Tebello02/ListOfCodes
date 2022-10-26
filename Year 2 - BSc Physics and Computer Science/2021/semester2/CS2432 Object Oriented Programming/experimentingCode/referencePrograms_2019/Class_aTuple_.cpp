#include <iostream>

/*
	NAME: Class{aTuple}.cpp
	
	FUNCTION:
	
	This class generalises the concept of a point in an N dimensional space to a tuple in an N dimensional
	space. NB: a point has "real valued" coordinates. On the other hand a tuple contains any arbitrary components:
	real valued, strings, etc.
	
	The class shows the concept of "generic programming in C++" via the use of "templates" -- template classes.
	The class also shows how to avoid the usage of "friend" functions/classes, via the use of the "set" and "get"
	public member functions of the class.
	
	(1) Set functions (e.g. set_Coord(i)), and
	(2) Get functions (e.g. get_Coord(i) )
	
	(C) mofana mphaka; March 2021
*/

#if !defined _A_TUPLE_
#define _A_TUPLE_

/**** C l a s s   D e c l a r a t i o n   &   C l a s s   I n t e r f a ce ****/

template <class T>
class aTuple
{
	private:
		T	* point;	//	an array of components/coordinates (in the tuple) , default is 1 component
		long int dimension;	//	the number of components, i.e. N dimensional space

	public:		
		//	Class Constructor -- polymorphic
		//	By default, the constructor creates a tuple with one (1) component, with a default value
		//	It will create the 2-tuple (c0, c1), where c0 and c1 are components, if dimension = 2, etc
		aTuple(long int _dimension = 1);

		//	Class Destructor -- empty. C++ scoping rules shall apply
		~aTuple() { }


		//	M e m b e r   F u n c t i o n s
		
		//	Input functions -- polymorphic
		
		void set_Coord(long int i, T value);	//	set the i-th component with the given value
		void set_all_Coord(T * value, long int _dimension = 1);	//	set all the components at once, with values
		
		void input();			//	input all the components of the tuple
		

		//	Output functions
		T get_Coord(long int i = 0);	//	get the value of the i-th component
		T * get_all_Coord();	//	get all the component values in a list
		
		long int get_length();		//	get the dimension of the tuple -- i.e. number of components in the tuple
		long int get_size();		//	same as get_length() -- OOP redundancy
		long int get_dimension();	//	same as get_length(), get_size()
		
		//	Display functions
		void display();					//	print the tuple as: x0, (x0, x1), (x0, x1, x2), etc 
		
		//	Overloaded Operators as Member Functions
		
		
		aTuple<T> operator = (aTuple<T> right);		//	Assigns the tuple on the right to this tuple -- *this = right
		bool operator == (aTuple<T> right);		//	compare this tuple with the tuple on the right -- *this == right?
		bool operator != (aTuple<T> right);
};



/**** C l a s s   I m p l e m e n t a t i o n ****/

template <class T>
aTuple<T> :: aTuple(long int _dimension)
{
	if (_dimension < 1)
		_dimension = 1;	//	the least dimension is the 1D space
		
	dimension = _dimension;
	
	try
	{
		point = new T[dimension];	//	the "new" operator might throw an exception, if no more memory available
		
		//	Each component, point[i], 0 <= i <= dimension-1, is initialised according to the default constructor of T
	}
	catch(...)	//	catch any possible exceptions from the "try" block above
	{
		std::cout << "Memory Overflow -- Cannot Create the Tuple!";
		exit(0);	//	terminate the "main" function that called this class
	}
}


template <class T>
void aTuple<T> :: set_Coord(long int i, T value)
//	The i-th componet, point[i], is assigned the value, "value".
//	i.e. point[i] = value. NB: 0 <= i < dimension
//	NB:
//	The function makes sure that the index, i, is within the tuple's dimension: 0 <= i < dimension
{
	if (i > dimension)
		i = dimension - 1;
		
	if (i < 0)
		i = 0;
		
	point[i] = value;	//	assume "=" overloaded for class T
}


template <class T>
void aTuple<T> :: set_all_Coord(T * value, long int _dimension)
//	Given a list of values, * value, and their dimension, _dimension,
//	set_all_Coord(...) will set the components of the tuple to the corresponding values.
{
	if (_dimension > dimension)
		_dimension = dimension;	//	Clip the given value to the actual tuple's dimension
		
	if (_dimension < 1)
		_dimension = 1;
		
	while(_dimension > 0)
	{
		point[_dimension-1] = value[_dimension-1];	//	Set each corresponding component with the corresponding value
		_dimension--;
	}
		
}


template <class T>
T aTuple<T> :: get_Coord(long int i)
//	get the i-th component of the tuple. That is, return point[i]
//	NB: 0 <= i < dimension. That is, the function Makes sure that the index, i, is within the tuple's dimension
{
	if (i > dimension)
		i = dimension - 1;
		
	if (i < 0)
		i = 0;
		
	return point[i];
}


template <class T>
T * aTuple<T> :: get_all_Coord()
//	Get all the components of the tuple in a list
{
	T * Coord = new T[dimension];	//	The components will be collected in Coord
	
	for(long int i = 0; i < dimension; i++)		//	copy each component, point[i], into the
		Coord[i] = point[i];					//	corresponding Coord[i]
		
	return Coord;
}


template <class T>
long int aTuple<T> :: get_length()
{
	return dimension;
}


template <class T>
long int aTuple<T> :: get_size()
{
	return dimension;
}


template <class T>
long int aTuple<T> :: get_dimension()
{
	return dimension;
}


template <class T>
void aTuple<T> :: input()
//	It inputs all components/coordinates interactively via the keyboard.
//	It prompts the user: Enter the n-th componet
//	and then scans the console for the corresponding input
{
	if (dimension < 2)	//	Only one (1) Component
	{
		std::cout << "Enter a component ";
		std::cin >> point[0];
	}
	else	//	The tuple has 2 or more components: (c0, c1, c2, ..., cN-1)
	{
		for (long int i = 0; i < dimension; i++)
		{
			std::cout << "Enter the " << (i+1);
			
			switch((i+1) % 10)
			{
				case 1: if ((i+1) != 11)
							std::cout << "st "; 
						break;
						
				case 2: if ((i+1) != 12)
							std::cout << "nd "; 
						break;
						
				case 3: if ((i+1) != 13)
							std::cout << "rd "; 
						break;
						
				default: std::cout << "th ";
			}
			
			std::cout << "component ";
			
			std::cin >> point[i];
		}
	}
}


template <class T>
void aTuple<T> :: display()
//	It displays a tuple as:
//	x0 -- if the tuple is in 1 dimensional spce -- 1D
//	(x0, x1) -- if the tuple is in 2D space, i.e. dimesion = 2
//	(x0, x1, x2) -- if the point is in 3D space, i.e. dimesion = 3, etc
{
	if (dimension < 2)
		std::cout << point[0];	//	A component on a 1D space
	else	//	More than one component? A 2D, 3D , ..., tuple, display it as: (x0, x1, x2, ..., xN-1)
	{
		std::cout << "(";
	
		for (long int i = 0; i < dimension; i++)
		{
			std::cout << point[i];
		
			if (i < (dimension-1))
				std::cout << ", ";	//	separate components with commas
		}
		std::cout <<  ")";
	}
}


template <class T>
aTuple<T> aTuple<T> :: operator = (aTuple<T> right)
//	Usage: P1 = P2, where P1 and P2 are tuples (of the same type).
//	Function: P1 is assigned the values of P2: dimension and all the components.
{
	//	re-create this tuple with the size of the tuple on the right
	this->point = new T[right.dimension];	
	this->dimension = right.dimension;
	
	//	Now, copy elementwise, the contents of the tuple on the right to this tuple (on the left)
	for (long int i = 0; i < this->dimension; i++)
		this->point[i] = right.point[i];
	
	return (*this);
}


template <class T>
bool aTuple<T> :: operator == (aTuple<T> right)
//	Usage: P1 == P2 where P1 and P2 are tuples (of the same type).
//	Function: The operator returns TRUE (1) iff P1 == P2, FALSE (0) otherwise
//	NB:
//	Two tuples, P1, P2, are equal iff
//	1.	They have equal dimensions AND
//	2.	they have equal (i.e. identical) corresponding components
{
	if (this->dimension == right.dimension)
	{
		for (long int i = 0; i < this->dimension; i++)
		{	
			if (this->point[i] != right.point[i])	//	If the tuples differ by this component
				return false;						//	then they are not equal
		}
		
		return true;	//	All components are identical, then the tuples are equal
	}
	else
		return false;
}


template <class T>
bool aTuple<T> :: operator != (aTuple<T> right)
//	Usage: P1 != P2 where P1 and P2 are tuples.
//	Function: The operator returns TRUE (1) iff P1 != P2, FALSE (0) otherwise
{
	return !(*this == right);
}


//	N o n - M e m b e r   F u n c t i o n s

template <class T>
std::istream & operator >> (std::istream & input, aTuple<T> &right)
//	Usage: cin >> P where P is a tuple.
//
//	Function:
//	Component values of P are read from the keysboard.
{
	T value;
	
	if (right.get_dimension() < 2)
	{
		std::cout << "Enter a component ";
		input >> value;
		right.set_Coord(0, value);	//	right.point[0] = value
	}
	else
	{
		for (long int i = 0; i < right.get_dimension(); i++)
		{
			std::cout << "Enter the " << (i+1);
			
			switch((i+1) % 10)
			{
				case 1: if ((i+1) != 11)
							std::cout << "st "; 
						break;
						
				case 2: if ((i+1) != 12)
							std::cout << "nd "; 
						break;
						
				case 3: if ((i+1) != 13)
							std::cout << "rd "; 
						break;
						
				default: std::cout << "th ";
			}
			
			std::cout << "component ";
			
			input >> value;
			right.set_Coord(i, value);	//	right.point[i] = value;
		}
	}
	
	return input;
}


template <class T>
std::ostream & operator << (std::ostream & output, aTuple<T> right)
//	Usage: cout << P where P is a tuple.
//
//	Function:
//	P is displayed on the screen as follows:
//	x0, if P is a tuple in 1D
//	(x0, x1), if P is a tuple in 2D space
//	(x0, x1, x3), if P is a tuple in 3D space, etc
{
	if (right.get_dimension() < 2)
		output << right.get_Coord(0);	//	A tuple in 1D -- just display it!
	else	//	More than one component? A 2D, 3D , ..., tuple, display it as: (x0, x1, x2, ..., xN-1))
	{
		output << "(";
	
		for (long int i = 0; i < right.get_dimension(); i++)
		{
			output << right.get_Coord(i);
		
			if (i < (right.get_dimension()-1))
				output << ", ";	//	separate components with commas
		}
		output <<  ")";
	}
	
	return output;
}
#endif


//	The main program for testing the class, aTuple
/*
int main()
{
	aTuple<char>	P1; 	// Declares P1 as a 1D tuple, containing just 1 character
	aTuple<std::string>		P2(2);	// Declares P2 as a 2D tuple with 2 string values:
	aTuple<long double>	P3(3);	// Declares P3 as a 3D tuple with 3 real values:
	
	std::cout << "The DEFAULT Initial Values of: P1, P2 and P3 are as follows:\n";
	std::cout << "P1 = " << (P1) << "\n";
	std::cout << "P2 = " << (P2) <<  "\n";
	std::cout << "P3 = " << (P3) << "\n";
	
	
	std::cout << "Enter New values of P1, Must be CHARACTERS:\n";
	std::cin >> P1;
	std::cout << "Enter New values of P2, Must be STRINGS:\n";
	std::cin >> P2;
	std::cout << "Enter New values of P3, Must be NUMBERS:\n";
	std::cin >> P3;
		
	std::cout << "The New Values of: P1, P2 and P3 are as follows:\n";
	std::cout << "P1 = " << (P1) << "\n";
	std::cout << "P2 = " << (P2) << "\n";
	std::cout << "P3 = " << (P3) << "\n";
	
	P2.set_Coord(0,"Hello");
	std::cout << "After P2.set_coord(0, \"hello\"), P2 = " << (P2) << "\n";
	
	return 1;
}
*/


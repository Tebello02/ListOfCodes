/*--------------------------------------------------*/
/*	NAME: Class{aStack}.cpp							*/
/*	FUNCTION:										*/
/*		The program is a STACK ADT. This file can	*/
/*		be included in any program that may require	*/
/*		stack primitives.							*/
/*													*/
/*		NB: In this stack definition no friend      */
/*		operators are used.							*/
/*													*/
/*	(C) mofana mphaka April 2020					*/
/*--------------------------------------------------*/

#include <iostream>
#include <fstream>

// The stack abstract data type (ADT)

// A. Structure:
//    It has 3 things
//    1. A finite list of objects
//    2. Two markers: bottom and top
//       2.1 bottom -- it points to the bottom of the stack, i.e. bottom = 0
//       2.2 top -- it points to the top of the stack, top >= bottom

// B. Primitives:
//    Other than the closure operations:
//    1. create/initialise the stack
//    2. kill/destroy the stack
//    3. display/print the stack contents

//    The stack has the following primitives:
//    1. full -- returns true if the stack is full, false otherwise
//    2. empty -- returns true if the stack is empty, false otherwise
//    3. push -- push (i.e insert) an object on the top of the stack
//    4. pop -- pop (i.e take) an object off the top of the stack
//    5. _top -- returns the element at the top of the stack - without popping it off
//

#ifndef _a_STACK_
#define _a_STACK_

// ---------------------------------------------------------//
//				S T A C K   D E C L A R A T I O N			//
// ---------------------------------------------------------//

template <class type>
class aStack
{
	private:
		//	D a t a   M e m b e r s

		int bottom,	//	points to the bottom of the stack, i.e. bottom = 0
			top,	//	points to the top of the stack. Initially, top = bottom = 0
			length;	//	points to the current stack length, length >= 1

		type * data; //	array to hold stack objects

		//	M e m b e r   F u n c t i o n s

		void resize(int newLength, bool & OK);
		/*	resizes the length of the stack to the new length, newLength.
			It sets OK to true if the operation was successful, false otherwise*/

	public:
		//	C l a s s   C o n s t r u c t o r s

		aStack(int size = 1);
		/*	It constructs the stack of the given size -- default is 1 */

		//	C l a s s   D e s t r u c t o r 
		~aStack() { };
		/*	It destroys the class by scoping rules */

		//	C l a s s   O p e r a t o r s

		aStack<type> operator = (aStack<type> right);
		/*	It assigns the stack on the right to this stack */
		
		aStack<type> operator = (type object);
		/*	It pushes the given object, object, onto the stack */
		
		aStack<type> operator + (type object);
		/*	It pushes the given object, object, onto the stack */

		aStack<type> operator + (aStack<type> right);
		/*	It adds this stack with the stack on the right */

		aStack<type> operator += (type object);
		/*	It returns *this += object */

		aStack<type> operator += (aStack<type> right);
		/*	It returns *this += right */
		
		type operator -- (int dummy);
		/*	Post-decrement. It pops off stack, usage: stack-- */

		type operator -- ();
		/*	Pre-decrement. It pops off the stack, usage: --stack */


		//	M e m b e r   F u n c t i o n s

		
		void push(type object, bool & OK);
		/*	It pushes the given object, object, onto the stack
			OK = true if the operation was successful, false otherwise*/

		type  pop(bool & OK);
		/*	It pops off an object from the top of the stack.
			It sets OK to true if there was an object to pop off, false otherwise */

		bool full();
		/*	It returns true if the stack is full, false otherwise */

		bool empty();
		/*	It returns true if the stack is empty, false otherwise */

		type _top(bool & OK);
		/*	It avails the value of the object at the top of the stack.
			It does not pop the element off the stack.
			It sets OK to true if there was an object at the top of the stack, false otherwise */

		int _top();
		/*	It returns the value of the stack top marker -- top	*/
			
		int _bottom();
		/*	It returns the value of the stack bottom marker -- bottom	*/

		int _length();
		/*	It returns the length (i.e the size) of the stack -- length	*/

		int size();
		/*	It returns the size of the stack -- same as _length()	*/
		
		type _data(int i);
		/*	It returns the i-th element of the stack -- data[i]	*/

		void input();
		/*	It reads the entire stack contents from the input stream, interactively */

		void display();
		/*	It displays the entire stack contents on the output stream */
		
		void write(std::fstream & file, int binary = 1);
		/*	It writes the stack data to file (default is "binary"), as follows:
			(1) bottom is written first, then
			(2) top, then
			(3) length and finally
			(4) the stack array, from top to bottom -- Stack LIFO discipline
			
			It assumes that the stream is open
		*/
		
		void read(std::fstream & file, int binary = 1);
		/*	It reads the stack data from file (default is "binary"), as follows:
			(1) bottom is read first, then
			(2) top, then
			(3) length and finally
			(4) the stack array, from top to bottom -- restoring the original stack
			
			It assumes that the stream is open
		*/
		
		void save();
		/*	It allows the user to save the contents of the stack to a file of his/her choice.
			The file will be opened in binary or text mode and will overwrite any existing data in the fie.
		*/
		
		void load();
		/*	It allows the user to load/retrieve the contents of the stack from a file of his/her choice.
			The file will be opened in binary or text mode and will be in read only.
		*/
};



// ---------------------------------------------------------//
//			S T A C K   I M P L E M E N T A T I O N			//
// ---------------------------------------------------------//


/*	C o n s t r u c t o r s */
//-----------------------------------------------------------------------------

template <class type>
aStack<type>::aStack(int size)
// Definition:	It initialises the stack to the given length, size
//
//	Inputs:		1.	The length of the data array, size.
//
//	Outputs:	There is no return type, but the following happens:
//				1.	The length of the data array is length size.
//				2.	The markers: bottom and top point to the bottom of the stack
//				3.	The data array contains junk
{
	bottom = top = 0;
	
	length = ((size < 1)? 1 : size);

	try
	{
		data = new type[length]; // try allocating memory to the array length
	}
	catch(...) // If we cannot allocate memory for the array, say so and exit
	{
		std::cout << "Memory Overflow -- stack could not be created!\n\n";
		exit(0);
	}
}
//-----------------------------------------------------------------------------


/*	M e m b e r   F u n c t i o n s */
//-----------------------------------------------------------------------------
template <class type>
void aStack<type>::resize(int newLength, bool & OK)
//	Definition:	resize(...),resizes the length of the stack to the new length.
//				It reports success (OK = true) or failure (OK = false) of the operation.
//
//	Inputs:		1.	The new length of the stack to resize to, newLength
//				2.	The boolean flag, OK, passed by reference
//
//	Outputs:	The return type is void, but the following happens:
//				1.	The type is void, but the stack array is resized and
//				2.	both the top of stack and the length of the stack are set accordingly
//				3.	OK is set to true if the stack was resized, false otherwise

{
	OK = true;

	type * newData;

	try
	{
		if (newLength < 1)
			newLength = 1;

		if (top >= newLength)
			//	resize downwards, we lose any top element(s) of the stack
			top = newLength-1;

		if (length > newLength)
			length = newLength;

		//	create a new array
		newData = new type[newLength];

		//	now, copy the contents of the old array into the new array
		for(int i = 0; i < top; i++)
			newData[i] = data[i];

		//	finally, make the old array point to the new array
		data = newData;
		length = newLength;
	}
	catch(...)
	{
		std::cout << "Memory Overflow ... could not allocate memory for the stack!\n";
		OK = false;
	}
}


template <class type>
bool aStack<type>::full()
//	Definition:	full(), determines whether or not the stack is full.
//
//	Inputs:		none
//
//	Outputs:	1.	It returns true if the stack is full, false otherwise
{
	if ( (top + 1) >= length)
		return (true);
	else
		return (false);
}


template <class type>
bool aStack<type>::empty()
//	Definition:	empty(), determines whether or not the stack is empty.
//
//	Inputs:		none
//
//	Outputs:	1.	It returns true if the stack is empty, false otherwise
{
	if ((top - 1) < bottom)
		return (true);
	else
		return (false);
}


template <class type>
type aStack<type>::_top(bool & OK)
//	Definition:	_top(...), avails the value of the object at the top of the stack.
//				It does not pop the element off the stack.
//
//	Inputs:		1.	A flag (i.e. boolean variable), OK
//
//	Outputs:	1.	The value of the element at the top of the stack, if it exists
//				2.	OK = true if there was an object at the top of the stack, false otherwise
{
	type object;

	OK = true;

	if(!empty())
		object = data[top - 1];
	else
		OK = false;

	return object;
}


template <class type>
int aStack<type>::_top()
{
	return top;
}


template <class type>
int aStack<type>::_bottom()
{
	return bottom;
}


template <class type>
int aStack<type>::_length()
{
	return length;
}


template <class type>
int aStack<type>::size()
{
	return length;
}


template <class type>
type aStack<type>::_data(int i)
{
	return data[i];
}


template <class type>
void aStack<type>::push(type object, bool & OK)
//	Definition:	push(...), pushes the given object onto the top of the stack.
//				It resizes the stack accordingly if needs be.
//
//	Inputs:		1.	The object to push, object.
//				2.	The boolean flag, OK, passed by reference.
//
//	Outputs:	1.	The type is void, but the object is added to the stack.
//				2.	Ok is set to true is the object was pushed onto the stck, false otherwise
{
	if (full())
		resize(length+1, OK);
	
	if (OK)
	{
		data[top] = object;
		top = top + 1;
	}
	else
		std::cout << "Memory Overflow ... could not push the object onto the stack!\n";
}


template <class type>
type aStack<type>::pop(bool & OK)
//	Definition:	pop(...), pops off the object at the top of the stack.
//
//	Inputs:		1.	A flag (i.e. boolean variable), OK
//
//	Outputs:	1.	The element at the top of the stack, if it exists
//				2.	OK = true if there was an object at the top of the stack, false otherwise
{
	type object;

	OK = true;

	if (!empty())
	{
		top = top - 1;
		object = data[top];
	}
	else
		OK = false;
	
	return (object);
}



template <class type>
void aStack<type>::input()
//	Definition:	input(...), reads the elements of the stack from the user, interactively.
//				It resizes the stack length accordingly if needs be.
//
//	Inputs:		1.	Parameter list is empty, but the input environment is the console.
//
//	Outputs:	1.	The type is void, but objects are added to the stack
{
	bool more = false, OK = true;
	char ans;

	do
	{
		std::cout << "Enter the next stack object, Stack[" << top << "] ";
		
		if (full())
			resize(length+1, OK);
	
		if (OK)
		{
			std::cin >> data[top];
			top = top + 1;

			std::cout << "Anymore Stack elements [Y/N]? ";
			std::cin >> ans;

			more = ((ans == 'y') || (ans == 'Y'));
		}
		else
			more = false;
	}
	while (more);
}


template <class type>
void aStack<type>::display()
//	Definition:	display(), displays the stack contents in LIFO.
//
//	Inputs:		1.	Parameter list is empty, but the input environment is the console
//
//	Outputs:	1.	The type is void, but the stack contents are displayed on the console
{
	std::cout << "The Stack contents (in LIFO) are:" << "\n";
	for (int i = top-1; i >= bottom; i--)
		std::cout << data[i] << "\n";
}


template <class type>		
void aStack<type> :: write(std::fstream & file, int binary)
{
	if (file.good())
	{
		if (binary)
		{
			try
			{
				file.write((char *) & bottom, sizeof(bottom));
				file.write((char *) & top, sizeof(top));
				file.write((char *) & length, sizeof(length));
		
				//	Now write the contents of the stack -- data
				for(int i = top-1; i >= bottom; i--)
					file.write((char *) & data[i], sizeof(data[i]));
			}
			catch(...)
			{
				std::cout << "File is bad ... ABORTIN!\n";
				exit(0);
			}
		}
		else	//	write to text file
		{
			try
			{
				file << bottom << "\t" << top << "\t" << length << "\n";
		
				//	Now write the contents of the stack -- data
				for(int i = top-1; i >= bottom; i--)
					file << data[i] << "\n";
			}
			catch(...)
			{
				std::cout << "File is bad ... ABORTIN!\n";
				exit(0);
			}
		}
	}
}


template <class type>		
void aStack<type> :: read(std::fstream & file, int binary)
{
	if (file.good())
	{
		if (binary)
		{
			try
			{
				file.read((char *) & bottom, sizeof(bottom));
				file.read((char *) & top, sizeof(top));
				file.read((char *) & length, sizeof(length));
		
				//	Now allocate memory for incoming data
				data = new type[length];
			
				for(int i = top-1; i >= bottom; i--)
					file.read((char *) & data[i], sizeof(data[i]));
			}
			catch(...)
			{
				std::cout << "File is bad OR Could not allocate Memory for the Array ... ABORTIN!\n";
				exit(0);
			}
		}
		else	//	Read from a Text file
		{
			try
			{
				file >> bottom >> top >> length;
		
				//	Now allocate memory for incoming data
				data = new type[length];
				
				//	Now read the file into the stack
				for(int i = top-1; i >= bottom; i--)
					file >> data[i];
			}
			catch(...)
			{
				std::cout << "File is bad OR Could not allocate Memory for the Array ... ABORTIN!\n";
				exit(0);
			}
		}
	}
}

		
template <class type>		
void aStack<type> :: save()
{
	std::fstream file;
	char file_name[256], file_format;
	int	file_open_mode;
	
	do
	{
		std::cout << "Enter file name to save the contents of the stack to  ";
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
		std::cout << "Stack Contents SAVED to File ==> " << file_name << " <==\n";
	}
		
	file.close();
}


template <class type>
void aStack<type> :: load()
{
	std::fstream file;
	char file_name[256], file_format;
	int	file_open_mode;

	do
	{
		std::cout << "Enter file name to load the contents of the stack from  ";
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
		std::cout << "Stack Contents LOADED from File ==> " << file_name << " <==\n";
	}

	file.close();
}
		
//-----------------------------------------------------------------------------

/*	C l a s s   O p e r a t o r s	*/
//-----------------------------------------------------------------------------


template <class type>
aStack<type> aStack<type>::operator + (type object)
//	Definition:	operator + (...), pushes the given object onto the stack.
//				It has the same effect as the push(...) method.
//
//	Inputs:		1.	The given stack, stack.
//				2.	The given object, object, on the right of the operator
//
//	Outputs:	1.	The stack with the object added to the contents
{
	bool OK = true;

	if (this->full())
		this->resize((this->length)+1, OK);
	
	if (OK)
	{
		this->data[this->top] = object;
		this->top++;
	}

	return(*this);
}


template <class type>
aStack<type> aStack<type>::operator + (aStack<type> right)
//	Definition: operator + (...), adds this stack with the stack on the right
//
//	Inputs:		1.	The two stacks, this and right
//
//	Outputs:	1.	The right stack is added to this left stack.
{
	bool OK = true;

	this->resize((this->length)+(right.length), OK);

	if (OK)
	{
		for(int i = 0; i < right.top; i++)
		{
			this->data[this->top] = right.data[i];
			this->top++;
		}
	}

	return (*this);
}


template <class type>
aStack<type> aStack<type>::operator += (aStack<type> right)
{
	(*this) = (*this) + right;
	return (*this);
}


template <class type>
aStack<type> aStack<type>::operator += (type object)
{
	(*this) = (*this) + object;
	return (*this);
}



template <class type>
type aStack<type>::operator -- (int dummy)
//	Definition: operator -- (...), pops off the stack. It has the same effect as
//				the method, pop(...).
//
//	Inputs:		1.	The given stack, this stack
//
//	Outputs:	1.	Returns the element at the top of the stack.
{
	type object;

	if (!this->empty())
	{
		this->top--;
		object = this->data[this->top];
	}

	return(object);
}


template <class type>
type aStack<type>::operator -- ()
{
	type object = (*this)--;

	return(object);
}


template <class type>
aStack<type> aStack<type>::operator = (aStack<type> right)
//	Definition: operator = (...), assigns the stack on the right to this stack
//
//	Inputs:		1.	The two stacks, this stack and the one on the right, right
//
//	Outputs:	1.	This stack is assigned the value of the stack on the right
{
	bool OK = true;

	//	First, re-create this stack with the size of the stack on the right
	this->resize(right.length, OK);

	if (OK)
	{
		this->top = right.top;

		//	Now copy the contents of the stack on the right to this stack
		for(int i = 0; i < right.top; i++)
			this->data[i] = right.data[i];
	}

	return (*this);
}


template <class type>
aStack<type> aStack<type>::operator = (type object)
{
	*this = *this + object;
	return (*this);
}
		

//-----------------------------------------------------------------------------

/*	N o n - M e m b e r   O p e r a t o r s	*/
//-----------------------------------------------------------------------------


template <class type>
std::istream & operator >> (std::istream & input, aStack<type> & stack)
{
	bool more = false, OK = true;
	char ans;
	type object;

	do
	{
		std::cout << "Enter the next stack object, Stack[" << stack._top() << "] ";
		input >> object;
		
		stack.push(object, OK);
		
		if (OK)
		{
			std::cout << "Anymore Stack elements [Y/N]? ";
			std::cin >> ans;

			more = ((ans == 'y') || (ans == 'Y'));
		}
		else
			more = false;
	}
	while (more);
	
	return input;
}


template <class type>
std::ostream & operator << (std::ostream & output, aStack<type> stack)
{
	output << "The Stack contents (in LIFO) are:" << "\n";
	for (int i = stack._top()-1; i >= stack._bottom(); i--)
		output << stack._data(i) << "\n";
		
	return output;
}

#endif

/*
int main()
{
	aStack<double> s;
	
	//std::cin >> s;
	//std::cout << s;
	
	//s.save();
	s.load();
	//s = -1000;
	std::cout << s;
	return 1;
}
*/

#include <iostream>
/*
	FILE NAME: Class{anArray}.cpp

	FUNCTION:

	A template class for dynamic arrays in C++.

	(c) mofana mphaka; March 2020
*/

// ---- B e g i n  _a_DYNAMIC_ARRAY_CLASS_  S p e c i f i c a t i o n ----

#ifndef _a_DYNAMIC_ARRAY_CLASS_
#define _a_DYNAMIC_ARRAY_CLASS_

template <class Type>
class anArray
{
	//	P r i v a t e   D a t a   M e m b e r s

	private:
		Type *	data;	//	The array of Type elements

		long 	CurrPos,//	The pointer to current data element, CurrPos=0..length-1
				length;	//	The size (i.e. the dimension) of the data array

	
	//	P u b l i c   M e m b e r   f u n c t i o n s

	public:

		//	C l a s s   C o n s t r u c t o r s

		anArray(long aLength = 1);
		/*	Creates an array class of size aLength. Default length = 1 */
		

		//	C l a s s   D e s t r u c t o r

		~anArray()	{}
		/*	Deletes an array class, by scoping rules */


		//	T h e   g e t   a n d   s e t   d a t a   f u n c t i o n s
		
		Type get_data(long i);
		/* Returns data[i] */
		
		long	size();
		/*	Returns the size of the array (i.e. the dimension of the array) -- same as get_length() */
		
		long	get_length();
		/* same as size() */
		
		long	get_CurrPos();
		/*	Returns the current array index, CurrPos */


		//	M e m b e r   F u n c t i o n s

		void	input(Type object, bool & OK);
		/*	Inputs (i.e. appends) the data object, object, in the array, automatically
			resizing the array length if adding the object requires it.
			It sets OK to true if the object was appended, false otherwise
		*/

		void	input(Type object, long pos, bool & OK);
		/*	Inputs (i.e. inserts) the data object, object, into the array at position, pos, */

		void	input(Type object, char pos, bool & OK);
		/*	Inputs (i.e. inserts) the data object, object, into the array as follows:
			1.	if pos = 'R' then the object is inserted at the rear (i.e. appended)
			2.	if pos = 'F' then the object is inserted in front
		*/
			
		void	input();
		/*	Inputs (all) the data elements into the array, automatically
			resizing the length of the array if more input requires more space 
		*/

		void	remove(Type object, bool & flag);
		/*	Deletes the data object, object, from the array. It sets flag to true
			if successful, false otherwise 
		*/

		void	remove(long pos, bool & flag);
		/*	Deletes the data object at position, pos, from the array. It sets flag to true
			if successful, false otherwise 
		*/

		void	remove(char pos, bool & flag);
		/*	Deletes a data object as follows:
			1.	if pos = 'R' then the object at the rear is deleted
			2.	if pos = 'F' then the object at the front is deleted 
		*/

		void	remove()	{ CurrPos = -1;}
		/*	Asserts that the array has no elements, CurrPos points to -1 */

		void	display(char dir = 'F');
		/*	Displays the elements of the array as follows:
			1.	if dir = 'R' then the array is displayed in reverse
			2.	the default direction is that the the array is displayed forward 
		*/

		bool	full();
		/*	Returns true if the array is full, false otherwise */

		bool	empty();
		/*	Returns true if the array is empty, false otherwise */

		bool member (Type token, long & Position);
		/*	It returns true if token == data[i], i=0,1, ..., CurrPos, and sets position = i.
			It returns false otherwise.
			
			Same as the non-member function, found(...), at the end 
		*/

		void	resize(long newLength, bool & OK);
		/*	Resizes the old array to the new size, newLength.
			OK is set to true if the array can be resized, false otherwise
		*/

		void	swap(Type & object1, Type & object2);
		/*	Swaps the two objects, object1 and object2 */

		void	sort(char Direction = 'A');
		/*	It bubble sorts the elements according to the Direction order:
			If Direction = 'D' then sorting order is Descending, otherwise it is Ascending 
		*/

		Type	first(bool & flag);
		/*	Returns the first element of the array, if array is not empty and
			sets flag to true, it returns "junk" value otherwise and sets flag to false 
		*/

		Type	last(bool & flag);
		/*	Returns the last element of the array, if array is not empty and
			sets flag to true, it returns "junk" value otherwise and sets flag to false 
		*/
		
	//	O v e r l o a d e d   M e m b e r   o p e r a t o r s   D e c l a r a t i o n s
		
		anArray<Type> operator = (anArray<Type> Array2);
		/*	Assigns this array to Array2 on the right (i.e this = Array2) */

		Type		operator [] (long array_index);
		/*	The array index, array_index, always points to some array element */

		anArray<Type> operator + (anArray<Type> Array2);
		/*	Adds (i.e concatenates) wo arrays: array on the left and Array2 to get a new Array */

		anArray<Type> operator + (Type object);
		/*	Adds (i.e appends) the object, object, to the array on the left */
	
		anArray<Type> operator - (anArray<Type> Array2);
		/*	Subtracts (i.e excludes) Array2 from the array on the left (i.e left - Array2) to get a new Array */
	
		anArray<Type> operator - (Type object);
		/*	Subtracts (i.e deletes) the object, object, from the array on the left */

		anArray<Type> operator += (anArray<Type> Array2);
		/*	Returns this = this + array2 */

		anArray<Type> operator += (Type object);
		/*	Returns this = this + object */
	
		anArray<Type> operator -= (anArray<Type> Array2);
		/*	Returns this = this - array2 */
	
		anArray<Type> operator -= (Type object);
		/*	Returns this = this - object */
		
		Type operator -- ();
		/*	Pre-decrement: usage --Array:
			It deletes the object at the front of the Array and avails it to the calling environment 
		*/

		Type operator -- (int dummyArgument);
		/*	Post-decrement: usage Array--:
			It deletes the object at the rear of the Array and avails it to the calling environment 
		*/
		
		bool operator == (anArray<Type> Array2);
		/*	Returns true if this array = Array2, false otherwise. Array1 = Array2 if
			0.	Array1.length == Array2.length and
			1.	Every member of Array1 is in Array2 and ever member of Array2 is in Array1
		*/
		
		bool operator != (anArray<Type> Array2);
		/*	It returns true if this array <> Array2, false otherwise	*/

		bool operator > (anArray<Type> Array2);
		/*	Returns true if Array1 > Array2, false otherwise. Array1 > Array2 if
			0.	Array1.length > Array2.length and
			1.	Every member of Array2 is in Array1. (i.e. the subset rule)
		*/
	
		bool operator < (anArray<Type> Array2);
		/*	Returns true if Array2 > Array1, false otherwise. */

		bool operator >= (anArray<Type> Array2);
		/*	Returns true if Array1 >= Array2, false otherwise. Array1 >= Array2 if
			0.	Array1 > Array2 or Array1 == Array2
		*/
	
		bool operator <= (anArray<Type> Array2);
		/*	Returns true if Array2 >= Array1, false otherwise. */
		//non-Members declared as friend  functions
		template <class Type2>
		/*friend std:: istream & operator >> (std::istream & input,const anArray<Type2> &); //Array);
		friend std:: ostream & operator << <Type2> (std::istream & output,anArray<Type2> & Array);
		friend operator + (Type object, anArray<Type2> Array);
		friend bool found(Type token,anArray<Type2> Array,long & Position);*/ 
};


//	M e m b e r   f u n c t i o n s / o p e r a t o r s   S p e c i f i c a t i o n s


template <class Type>
anArray<Type> :: anArray(long aLength)
//	Definition: anArray(aLength) creates an array of length aLength
//
//	Usage:		anArray<Specific Type> Array(aLength);
//
//	Inputs:		1.	An integer specifying the size of the array to be created, aLength
//
//	Outputs:	1.	A data array of length, aLength, as a class
{
	
	CurrPos = -1;

	if (aLength < 1)
		aLength = 1;
	
	length = aLength;

	try
	{
		data = new Type [length];
	}
	catch(...)
	{
		std::cout << "\nCould not allocate memory for the Array ... aborting!\n";
		exit(0);
	}
}


template <class Type>
Type anArray<Type> :: get_data(long i)
{
	if (i < 0)			//	If i is negative them
		i = (-1) * i;	//	make it positive
		
	i = i % (CurrPos + 1);	//	Ensure that: 0 <= i <= CurrPos
	
	return data[i];
}


template <class Type>
long anArray<Type> :: size()
{
	return length;
}


template <class Type>
long anArray<Type> :: get_length()
{
	return length;
}


template <class Type>
long anArray<Type> :: get_CurrPos()	
{
	return CurrPos;
}


template <class Type>
bool anArray<Type> :: full()
{ 
	return ((CurrPos + 1) >= length);
}


template <class Type>
bool anArray<Type> :: empty()
{ 
	return (CurrPos < 0);
}
		
		
template <class Type>
bool anArray<Type> :: member (Type token, long & Position)
//	Definition:	member(...), searches for a token in the data array.
//				It returns true if token is found in the array, false otherwise.
//				Position is set to i, where Array[i] = token
//
//	Inputs:		1.	The token to be searched for, token.
//				2.	The position variable, Position, passed by reference
//
//	Outouts:	1.	It returns true if the token resides somewhere in the array,
//					false otherwise.
//				2.	0 <= Position < length if token is in the data array
//					Position = length if the token is not in the array.
{
	for(Position = 0; Position <= CurrPos; Position++)
	{
		if (data[Position] == token)
			return(true);
	}
	return(false);
}


template <class Type>
void anArray<Type> :: resize(long newLength, bool & OK)
//	Definition:	resize(...), copies the old array to the new array with new length
//
//	Inputs:		1.	The new length to resize to, newLength
//				2.	The boolean flag, OK, passed by reference
//
//	Outputs:	1.	The return type is void but the array is resized to the new length
//				2.	OK = true if the array was resized, false otherwise.
{
	OK = true;

	if (newLength < 1)
		newLength = 1;

	if (CurrPos > (newLength - 1))
		CurrPos = newLength - 1;	//	resize downwards

	try
	{
		Type * newData = new Type [newLength];

		//	Now copy the old array into the new array
		for(long i = 0; i <= CurrPos; i++)
			newData[i] = data[i];
		
		//	Now copy back the new array into the old array
		data = newData;
		length = newLength;
	}
	catch(...)
	{
		std::cout << "\nCould not allocate memory for the new Array!\n";
		OK = false;
	}
}


template <class Type>
void anArray<Type> :: swap(Type & object1, Type & object2)
//	Definition:	swap(x, y) swaps the two objects x and y, such that x will now
//				contain the value of y and y the value of x.
//
//	Inputs:		1.	The two objects, object1 and object2
//
//	Outputs:	1.	object1 has the value of object2 and vice versa
{
	Type tempObject = object1;
	object1 = object2;
	object2 = tempObject;
}


template <class Type>
void anArray<Type> :: sort(char Direction)
//	Definition:	sort(Direction) bubble sorts the array elements according to
//				the Direction order:
//				If Direction = 'D' then sorting order is Descending, otherwise
//				it defaults to Ascending (i.e. 'A').
//
//	Inputs:		1.	The sorting order, Direction
//
//	Outputs:	The array of objects are sorted in Direction order
{
	bool	sorted = false,
			SwapNeighbours;

	while (!sorted)
	{
		sorted = true;
		for(long i = 0; i <= CurrPos - 1; i++)
		{
			if ((Direction == 'd') || (Direction == 'D'))
				SwapNeighbours = (data[i] < data[i+1]);
			else // The default is Ascending
				SwapNeighbours = (data[i] > data[i+1]);

			if (SwapNeighbours)
			{
				sorted = false;
				Type tempObj = data[i];
				data[i] = data[i+1];
				data[i+1] = tempObj;
			}
		}
	}
}


template <class Type>
void anArray<Type> :: input(Type object, bool & OK)
//	Definition:	input(...), inputs (i.e. appends) the data object, object, to the array,
//				automatically resizing the array length if adding the object requires it.
//
//	Inputs:		1.	The object to append to the array, object
//				2.	A boolean flag, OK, passed by reference
//
//	Outputs:	1.	Return type is void but the object is appended to the array
//				2.	OK is set to true if the operation was successful, false otherwise
{
	OK = true;

	if (full())
		resize(length + 1, OK);
	
	if (OK)
	{
		CurrPos++;
		data[CurrPos] = object;
	}
}


template <class Type>
void anArray<Type> :: input(Type object, long pos, bool & OK)
//	Definition:	input(...), inserts the data object, object, into the array at position, pos.
//
//	Inputs:		1.	The object to insert into the array, object
//				2.	The index position, pos, where to insert the data object
//				3.	A boolean flag, OK, passed by reference
//
//	Outputs:	1.	Return type is void but the object is inserted at position, pos, in the array
//				2.	OK is set to true if the object was inserted, false otherwise
{
	OK = true;

	if (pos < 0)
		pos = 0;	//	we will insert in front -- data[0]

	if (pos > CurrPos)
		pos = CurrPos;	//	we will insert at the rear (i.e. append) -- data[CurrPos+1]

	if (full())
		resize(length + 1, OK);
	
	if (OK)
	{
		//	Shift array elements from pos to pos+1 to CurrPos+1
		for(long i = CurrPos+1; i > pos; i--)
			data[i] = data[i-1];

		//	Now increment CurrPos and slot the object at pos
		CurrPos++;
		data[pos] = object;
	}
}


template <class Type>
void anArray<Type> :: input(Type object, char pos, bool & OK)
//	Definition:	input(...), inserts the data object, object, into the array as follows:
//				1.	if pos = 'R' then the object is inserted at the rear (i.e. appended)
//				2.	if pos = 'F' then the object is inserted in front
//
//	Inputs:		1.	The object to append to the array, object
//				2.	The position, pos, where to insert the data object
//				3.	A boolean flag, OK, passed by reference
//
//	Outputs:	1.	Return type is void but the object is inserted accordingly into the array
//				2.	OK is set to true if the object was inserted, false otherwise
{
	OK = true;

	if (full())
		resize(length + 1, OK);
	
	if (OK)
	{
		long i, slot;

		if ((pos == 'f') || (pos == 'F'))
		{
			//	insert the object in front -- data[0]
			//	Shift array elements from 0 to 1 to CurrPos+1
			for(i = CurrPos+1; i > 0; i--)
				data[i] = data[i-1];
			slot = 0;
		}
		else 
			//	pos == 'R' or anything other than 'F'. So,
			//	insert the object at the rear (i.e. append) -- data[CurrPos+1]
			slot = CurrPos + 1;

		//	Now increment CurrPos and slot the object accordingly
		CurrPos++;
		data[slot] = object;
	}
}


template <class Type>
void anArray<Type> :: input()
//	Definition:	input() inputs (all) the data elements in the array, automatically
//				resizing the length of the array if more input requires more space
//
//	Inputs:		Argument list is empty, but the input environment is the console
//	
//	Outputs:	1.	Return type is void, but the data array is appropriately assigned.
{
	bool more = true, OK = true;
	char yes;

	if (full())
		resize(length + 1, OK);

	while (!full() && more && OK)
	{
		CurrPos++;
		std::cout << "Enter next element, data[" << CurrPos << "] = ";
		std::cin >> data[CurrPos];

		std::cout << "Anymore elements to enter ? [y/n]";
		std::cin >> yes;

		more = ((yes == 'y') || (yes == 'Y'));

		if (full() && more)
			resize(length + 1, OK);
	}
}


template <class Type>
void anArray<Type> :: remove(Type object, bool & flag)
//	Definition:	remove(...) deletes the data object, Object, from the array.
//				It sets flag to true if successful, false otherwise
//
//	Inputs:		1.	The data object, object
//				2.	The boolean variable, flag, passed by reference
//
//	Outputs:	1.	The return type is void, but the array has the data object removed.
//				2.	flag is set to true if the object was removed, false otherwise.
{
	long i = 0;
	flag = false;

	while((i <= CurrPos) && !(flag))
	{
		if (data[i] == object)
		{
			flag = true;

			//	Now pack array elements to close this gap

			for(long j = (i+1); j <= CurrPos; j++)
			{
				data[i] = data[j];
				i++;
			}

			//	Then adjust the CurrPos pointer by minus 1
			if (!empty())
				CurrPos--;
		}
		else
			i++;
	}
}



template <class Type>
void anArray<Type> :: remove(long pos, bool & flag)
//	Definition:	remove(...) deletes the data object at position, pos, from the array.
//				It sets flag to true if successful, false otherwise
//
//	Inputs:		1.	The position, pos, from where the deletion should be carried out
//				2.	The boolean variable, flag, passed by reference
//
//	Outputs:	1.	The return type is void, but the array has an object removed, if any
//				2.	flag is set to true if an object was removed, false otherwise.
{
	long i = 0;
	flag = false;

	while((i <= CurrPos) && !(flag))
	{
		if (i == pos)
		{
			flag = true;

			//	Now pack array elements to close this gap

			for(i = (pos+1); i <= CurrPos; i++)
			{
				data[pos] = data[i];
				pos++;
			}

			//	Then adjust the CurrPos pointer by minus 1
			if (!empty())
				CurrPos--;
		}
		else
			i++;
	}
}


template <class Type>
void anArray<Type> :: remove(char pos, bool & flag)
//	Definition:	remove(...) deletes a data object at position, pos, from the array as follows:
//				1.	if pos = 'R' then the object at the rear is deleted
//				2.	if pos = 'F' then the object at the front is deleted
//				It sets flag to true if successful, false otherwise
//
//	Inputs:		1.	The position, pos, from where the deletion should be carried out
//				2.	The boolean variable, flag, passed by reference
//
//	Outputs:	1.	The return type is void, but the array has an object removed, if any
//				2.	flag is set to true if an object was removed, false otherwise.
{
	long i = 0, slot = 0;
	flag = false;

	if ((pos == 'f') || (pos == 'F'))
		slot = 0;		//	delete the object at position 0 -- data[0]
	else
		slot = CurrPos;	//	delete the object at the last position -- data[CurrPos]

	if (!empty())
	{
		flag = true;

		//	Pack array elements to close this gap
		for(i = (slot+1); i <= CurrPos; i++)
		{
			data[slot] = data[i];
			slot++;
		}

		//	Then adjust the CurrPos pointer by minus 1
		if (!empty())
			CurrPos--;
	}
}


template <class Type>
Type anArray<Type> :: first(bool & flag)
//	Definition:	first(...) returns the first element of the array, if array is not empty
//				and	sets flag to true, it returns "junk" value otherwise and sets flag to false
//
//	Inputs:		1.	The boolean variable, flag.
//
//	Outputs:	1.	The first object in the array, if any
//				2.	flag = true if there was any first object in the array, false othwerwise

{
	Type object;
	flag = false;

	if (!empty())
	{
		flag = true;
		object = data[0];
	}
	return(object);
}


template <class Type>
Type anArray<Type> :: last(bool & flag)
//	Definition:	last(...) returns the last element of the array, if array is not empty
//				and sets flag to true. It returns "junk" otherwise and sets flag to false
//
//	Inputs:		1.	The boolean variable, flag.
//
//	Outputs:	1.	The last object in the array, if any
//				2.	flag = true if there was any last object in the array, false othwerwise
{
	Type object;
	flag = false;

	if (!empty())
	{
		flag = true;
		object = data[CurrPos];
	}
	return(object);
}


template <class Type>
void anArray<Type> :: display(char dir)
//	Definition:	display(dir), displays the elements of the array, according to the
//				direction order.
//				If dir = 'F', then the elements are displayed in order: 0, 1, 2, ..., N-1
//				else the elements are displayed in reverse: N-1, ..., 2, 1, 0
//
//	Inputs:		none
//	Ouputs:		The elements of the array are displayed on the console, 
//				according to the direction, dir, order.
{
	long i;

	std::cout << "{";

	if ((dir == 'f') || (dir == 'F'))
	{
		//	display the array element in order: 0, 1, 2, ..., N-1
		for(i = 0; i <= CurrPos; i++)
		{
			std::cout << data[i];
		
			if(i < CurrPos)
				std::cout << ", ";
		}
	}
	else
		//	display the array elements in reverse: N-1, N-2, ..., 2, 1, 0
		for(i = CurrPos; i >= 0 ; i--)
		{
			std::cout << data[i];
		
			if(i > 0)
				std::cout << ", ";
		}

	std::cout << "}";
	std::cout << "\n";
}


template <class Type>
anArray<Type> anArray<Type> :: operator = (anArray<Type> Array2)
//	Definition: = (...), assigns this array to the array on the right, Array2 (i.e this = Array2)
//
//	Procedure:	It copies Array2 into this array memberwise and data-wise
//
//	Inputs:		1.	This array on the left of =
//				2.	Array2 on the right of the operator.
//
//	Outputs:	This array (on the left) is assigned the value of Array2 (on the right)
{
	bool OK = true;

	this->resize(Array2.length, OK);	//	Resize this array to the length of Array2

	if (OK)
	{
		this->CurrPos = Array2.CurrPos;	//	Now copy each memeber of Array2 into this array

		for(long i = 0; i <= Array2.CurrPos; i++)
			this->data[i] = Array2.data[i];
	}

	return(*this);
}


template <class Type>
Type anArray<Type> :: operator [] (long array_index)
//	Definition:	[i], avails the object data[i]. Usage: array[i]. The operator always points
//				to some array data element. If the array index is out of bounds then this
//				function makes it point to either the lower bound or the upper bound.
//
//	Inputs:		1.	The array subscript, array_index.
//
//	Outputs:	1.	The array data element, data[array_index], 0 <= array_index <= CurrPos.
{
	Type ArrayElement;

	if (array_index >= CurrPos)
		array_index = CurrPos;

	if (array_index <= 0)
		array_index = 0;

	if (!empty())
		ArrayElement = data[array_index];

	return(ArrayElement);
}


template <class Type>
anArray<Type> anArray<Type> :: operator + (anArray<Type> Array2)
/*	Adds (i.e concatenates) the two arrays: Array left and Array2 to get a new Array

	Proedure: Append to the left array, each element of Array2.
	
	output: left = left + Array2
*/
{
	bool OK = true;
	long int i;
	
	anArray<Type> newArray;
	
	newArray = *this;	//	Copy this array to avoid any side effects
	
	for(i = 0; i <= Array2.CurrPos; i++)
			newArray.input(Array2.data[i], OK);
			
	return newArray;
}


template <class Type>
anArray<Type> anArray<Type> :: operator + (Type object)
//	Definition:	+(...) appends the object, object, into array on the left. It has the same effect
//				as the method input(object, OK) or input(object, 'R', OK).
//
//	Inputs:		1.	The array on the left of the operator,
//				2.	The object to insert on the right of the operator, object
//
//	Outputs:	1.	The array with the object appended.
{
	bool OK = true;
	
	anArray<Type> newArray;
	
	newArray = *this;
	
	newArray.input(object, OK);

	return newArray;
}


template <class Type>
anArray<Type> anArray<Type> :: operator - (anArray<Type> Array2)
/*	Subtracts (i.e excludes) Array2 from this (i.e this - Array2) to get a new Array.
	
	Procedure: remove each element of Array2 from this array
	
	Output: this = this - Array2
 */
{
	bool	OK = false;
	long int i;

	anArray<Type> newArray;
	
	newArray = *this;
	
	for(i = 0; i <= Array2.CurrPos; i++)
		newArray.remove(Array2.data[i], OK);	//	Remove each element of Array2 from newArray
	
	return newArray;
}


template <class Type>
anArray<Type> anArray<Type> :: operator - (Type object)
//	Definition:	-(...) excludes the object, object, from this Array. It has the same effect
//				as the method remove(object, OK).
//
//	Inputs:		1.	The array on the left of the operator, this
//				2.	The object to delete on the right of the operator, object
//
//	Outputs:	1.	The array with the object deleted.
{
	bool	OK = false;

	anArray<Type> newArray;
	
	newArray = *this;
	
	newArray.remove(object, OK);

	return newArray;
}


template <class Type>
anArray<Type> anArray<Type> :: operator += (anArray<Type> Array2)
{
	(*this) = (*this) + Array2;
	return (*this);
}


template <class Type>
anArray<Type> anArray<Type> :: operator += (Type object)
{
	(*this) = (*this) + object;
	return (*this);
}


template <class Type>	
anArray<Type> anArray<Type> :: operator -= (anArray<Type> Array2)
{
	(*this) = (*this) - Array2;
	return (*this);
}
	

template <class Type>
anArray<Type> anArray<Type> :: operator -= (Type object)
{
	(*this) = (*this) - object;
	return (*this);
}


template <class Type>
Type anArray<Type> :: operator -- ()
//	Definition:	Pre-decrement, --(...), deletes the object at the front of the Array.
//				It then avails this object to the calling environment.
//
//	Usage:		--Array
//
//	Inputs:		1.	The array on the right of the operator, this
//
//	Outputs:	1.	The array with the object deleted.
//				2.	The deleted object is availed to the calling environment.
{
	bool	OK = true;

	Type object;
	
	if (!this->empty())
	{
		object = this->data[0];	//	Get the object in front of the array
		this->remove('F', OK);	//	Then, delete it from the array
	}

	return(object);	//	Avail the object to the calling environment
}


template <class Type>
Type anArray<Type> :: operator -- (int dummyArgument)
//	Definition:	Post-decrement, --(...), deletes the object at the rear of the Array,
//				and avails it to the calling environment.
//
//	Usage:		Array--
//
//	Inputs:		1.	The array on the left of the operator, Array
//
//	Outputs:	1.	The array with the object deleted.
//				2.	The deleted object is availed to the calling environment.
{
	bool	OK = true;

	Type object;
	
	if (!this->empty())
	{
		object = this->data[this->CurrPos];	//	Get the object at the rear of the array
		this->remove(this->CurrPos, OK);	//	and delete it from the array
	}

	return(object);
}


template <class Type>
bool anArray<Type> :: operator == (anArray<Type> Array2)
/*	Returns true if Array1 = Array2, false otherwise. Array1 == Array2 if
	0.	Array1.length == Array2.length and
	1.	Every member of Array1 is in Array2 and every member of Array2 is in Array1
*/
{
	long int i, Pos;

	if (this->length == Array2.length)
	{
		//	Check that every member of Array1 is in Array2
		for(i = 0; i <= this->CurrPos; i++)
		{
			if (!found(this->data[i], Array2, Pos))
			//	Array1 <> Array2
				return(false);
		}

		//	Then check that every member of Array2 is in Array1
		for(i = 0; i <= Array2.CurrPos; i++)
		{
			if (!found(Array2.data[i], (*this), Pos))
			//	Array1 <> Array2
				return(false);
		}

		//	Array1 == Array2
		return(true);
	}
	else
		//	Array1 <> Array2
		return(false);
}


template <class Type>
bool anArray<Type> :: operator != (anArray<Type> Array2)
{
	return ! (*this == Array2);
}


template <class Type>
bool anArray<Type> :: operator > (anArray<Type> Array2)
/*	Returns true if Array1 > Array2, false otherwise. Array1 > Array2 if
	0.	Array1.length > Array2.length and
	1.	Every member of Array2 is in Array1. (i.e. The Subset Rule)
*/
{
	long int i, Pos;

	if (this->length > Array2.length)
	{
		//	Then check that every member of Array2 is in Array1
		for(i = 0; i <= Array2.CurrPos; i++)
		{
			if (!found(Array2.data[i], (*this), Pos))
				return(false);
		}

		//	Array1 > Array2
		return(true);
	}
	else
		//	Array1 < Array2
		return(false);
}


template <class Type>
bool anArray<Type> :: operator < (anArray<Type> Array2)
/*	Returns true if Array2 > this, false otherwise. */
{
	return(Array2 > (*this));
}


template <class Type>
bool anArray<Type> :: operator >= (anArray<Type> Array2)
/*	Returns true if Array1 >= Array2, false otherwise. Array1 >= Array2 if
	0.	Array1 > Array2 or Array1 == Array2
*/
{
	return(((*this) > Array2) || ((*this) == Array2));
}


template <class Type>
bool anArray<Type> :: operator <= (anArray<Type> Array2)
/*	Returns true if Array2 >= Array1, false otherwise */
{
	return(Array2 >= (*this));
}


//	N o n - M e m b e r,  F u n c t i o n s / O p e r a t o r s   S p e c i f i c a t i o n s

// now declared as friend function

template <class Type2>
std::ostream & operator << (std::ostream & output, anArray<Type2> Array)
/*	Prints the array, Array, on the output stream. E.g. cout << Array. */
{
	long i;
	
	output << "{";	//	Print the opening brace

	for(i = 0; i <= Array.get_CurrPos(); i++)
	{
		output << Array.get_data(i);
		
		if(i < Array.get_CurrPos())
			output << ", ";	//	Seperate array elements by comma
	}

	output << "}";	//	Print the closing brace
	return(output);
}


template <class Type2>
std::istream & operator >> (std::istream & input, anArray<Type> & Array)
/*	Inputs the array, Array, from the input stream. E.g. cin >> Array. */
{
	bool more = true, OK = true;
	char yes;
	
	Type data;

	while (more && OK)
	{
		
		std::cout << "Enter next element, data[" << Array.get_CurrPos()+1 << "] = ";
		input >> data;
		
		Array.input(data, OK);
		
		if (OK)
		{
			std::cout << "Anymore elements to enter ? [y/n]";
			std::cin >> yes;

			more = ((yes == 'y') || (yes == 'Y'));
		}
	}

	return(input);
}


template <class Type2>
anArray<Type2> operator + (Type2 object, anArray<Type2> Array)
//	Definition:	+(...) inserts the object, object, in front of the array, Array.
//				It has the same effect as the method input(object, 'F', OK) or the method
//				input(object, 0, OK).
//
//	Inputs:		1.	The object to insert on the left of the operator, object
//				2.	The array on the right of the operator, Array
//
//	Outputs:	1.	The array with the object inserted in front.
{
	bool OK = true;
	
	anArray<Type2> newArray;
	
	newArray = Array;	//	Copy the Array to avoid side effects

	newArray.input(object, 'F', OK);

	return newArray;
}


template <class Type2>
bool found (Type2 token, anArray<Type2> Array, long & Position)
/*	0.	Returns true if token is found in the array, Array, false otherwise
	1.	Position is set to i, where Array[i] = token
*/
{
	for(Position = 0; Position <= Array.get_CurrPos(); Position++)
	{
		if (Array.get_data(Position) == token)
			return(true);
	}
	return(false);
}

#endif
// ---- E n d   _a_DYNAMIC_ARRAY_CLASS_  S p e c i f i c a t i o n ----


int main()
{
	anArray<int>	array1(10), array2(5), array;

	long i;
	bool ok = true;
	
	//	Populate Array1
	for(i = 0; i < array1.size(); i++)
		array1.input(i, ok);

	//	Populate Array2
	for(i = 0; i < array2.size(); i++)
		array2.input(i+1, ok);

	std::cout << "Array1 = ";
	std::cout << array1 << "\n";
	
	std::cout << "Array2 = ";
	std::cout << array2 << "\n";

	std::cout << "\nArray1 + Array2 = ";
	std::cout << array1 + array2 << "\n";

	std::cout << "Array1 - Array2 = ";
	std::cout << array1 - array2 << "\n";

	array = array1 + array2;
	std::cout << "\nArray = Array1 + Array2 = ";
	std::cout << array << "\n";

	array = array1 - array2;
	std::cout << "Array = Array1 - Array2 = ";
	std::cout << array << "\n";

	std::cout << "\nAfter the above operations:\nArray1 = ";
	std::cout << array1 << "\nArray2 = " << array2 << "\nArray = " <<
		array << "\n\n";

	if (array1 <= array2)
		std::cout << "Array1 <= Array2\n";

	if (array1 >= array2)
		std::cout << "Array1 >= Array2\n";
	
	if (array1 == array2)
		std::cout << "Array1 == Array2\n";
	
	if (array1 < array2)
		std::cout << "Array1 < Array2\n";
	
	if (array1 > array2)
		std::cout << "Array1 > Array2\n";

	return(1);
}


/*
	FILE NAME: Class{aSet}.cpp

	FUNCTION:

	A template class for a set in C++. It implements all the set operations, except set compliment:
	
	For any two sets, S1 and S2 and an element, e
	
	A. Operations which result in a new set:
	
	(1) S1 + S2 is the union of S1 and S2
	(2) S1 - S2 is the set difference of S1 and S2, S1 - S2
	(3) S1 * S2 is the set intersection of S1 and S2, S1 * S2
	(4) S1 + e (or e + S1) is the set: S1 + {e}
	(5) S1 - e is the set: S1 - {e}

	B. Operations which result in a true or false value:
	
	(1) S1 < S2 is true if S1 is a proper subset of S2, false otherwise
	(2) S1 > S2 is true if S1 is a proper subset of S2, false otherwise
	(3) S1 == S2 is true if S1 is identical to S2, false otherwise
	(3) !S1 is true if S1 is empty, false otherwise, etc

	(c) mofana mphaka; April 2020
*/


#if !defined _a_SET_
#define _a_SET_

#include <iostream>


template <class Type>
class aSet
{
	//	P r i v a t e   D a t a / M e m b e r   f u n c t i o n s

	private:
		Type *	data;	//	The Set container of Type elements

		long	CurrPos,//	The pointer to current data element, CurrPos=0..length-1
				length;	//	The size (i.e. the dimension) of the data container

	
	//	P u b l i c   M e m b e r   f u n c t i o n s

	public:

		//	C l a s s   C o n s t r u c t o r s

		aSet();
		/*	Creates an empty Set */
		
		aSet(Type object);
		/*	Creates a singleton Set -- i.e. a set with just one element, object */

		//	C l a s s   D e s t r u c t o r

		~aSet()	{}
		/*	Deletes the set, by scoping rules */


		//	I n p u t   F u n c t i o n s

		void	input(Type object, bool & OK);
		/*	Inputs (i.e. appends) the data object, object, in the set, automatically
			resizing the set length if adding the object requires it.
			It sets OK true if the object was appended, false otherwise*/
			
		void	input();
		/*	Inputs (all) the data elements in the set, automatically
			resizing the length of the set if more input requires more space */


		//	D e l e t e   F u n c t i o n s

		void	remove(Type object, bool & flag);
		/*	Deletes the data object, object, from the set. It sets flag to true
			if successful, false otherwise */

		void	remove();
		/*	Deletes all the elements in the set */


		//	D i s p l a y   F u n c t i o n 

		void	display();
		/*	Displays the elements of the set, in first come first served.
			The elements are displayed as: {e0, e1, e2, ..., eN-1 }
		*/


		//	O u t p u t   F u n c t i o n s

		aSet<Type> operator + (aSet<Type> right);
		/*	makes a set union: this + right */

		aSet<Type> operator + (Type right);
		/*	Adds (i.e appends) the object right into the set */

		aSet<Type> operator - (aSet<Type> right);
		/*	Subtracts (i.e excludes) the set on the right from this set: this - right */

		aSet<Type> operator - (Type right);
		/*	Subtracts (i.e deletes) the object on the right from this set */
		
		aSet<Type> operator * (aSet<Type> right);
		/*	Intersection Rule: returns the intersection of this set and the set on the right: this * right */

		aSet<Type> operator * (Type right);
		/*	The intersection of this set and the object on the right */


		//	B o o l e a n   O p e r a t o r s
	
		bool operator == (aSet<Type> right);
		/*	Returns true if this set = the set on the right, false otherwise. */

		bool operator > (aSet<Type> right);
		/*	Returns true if this set > the right set, false otherwise. Superset Rule*/
	
		bool operator < (aSet<Type> right);
		/*	Returns true if this set > right set, false otherwise. Subset Rule */

		bool operator >= (aSet<Type> right);
		/*	Returns true if this >= right, false otherwise.	*/
	
		bool operator <= (aSet<Type> right);
		/*	Returns true if right >= this, false otherwise. */
		
		bool operator != (aSet<Type> right);
		/*	Returns true if this <> right, false otherwise. */
		
		bool operator ! ();
		/*	Returns true if this set is empty, false otherwise. */
		
		
		//	A s s i g n m e n t   O p e r a t o r s
		
		aSet<Type> operator = (aSet<Type> right);
		/*	Assigns this set to the set on the right (i.e this = right) */
		
		aSet<Type> operator = (Type right);
		/*	Assigns this set to the singleton set containing the element right */
		
		aSet<Type> operator += (aSet<Type> right);
		/*	Returns this = this + right */

		aSet<Type> operator += (Type right);
		
		aSet<Type> operator -= (aSet<Type> right);
		/*	Returns this = this - right */

		aSet<Type> operator -= (Type right);
		
		aSet<Type> operator *= (aSet<Type> right);
		/*	Retruns this = this * right */

		aSet<Type> operator *= (Type right);

		
		// M o r e   M e m b e r   F u n c t i o n s

		bool member (Type token);
		/*	returns true if token is in the set, false otherwise */

		void	resize(long newLength, bool & OK);
		/*	Resizes the current set to the new size, newLength.
			OK is set to true if the set can be resized, false otherwise
		*/
		
		bool	full();
		/*	Returns true if the set is full, false otherwise */

		bool	empty();
		/*	Returns true if the set is empty, false otherwise */

		long	size();
		/*	Returns the size of the set (i.e. the number of elements in the set) */

		long	get_length();
		/*	same as size()	*/
		
		long	get_CurrPos();
		/*	Returns the current set index, CurrPos */
		
		long	get_data(long i);
		/*	The look-up function: It returns the i-th element of the set, data[i]	*/
};


//	M e m b e r   f u n c t i o n s / o p e r a t o r s   S p e c i f i c a t i o n s


template <class Type>
aSet<Type> :: aSet()
//	Create an Empty Set
{
	
	CurrPos = -1;
	length = 1;

	try
	{
		data = new Type [length];
	}
	catch(...)
	{
		std::cout << "\nCould not allocate memory for the Set ... aborting!\n";
		exit(0);
	}
}


template <class Type>
aSet<Type> :: aSet(Type object)
//	Create a Singleton Set with element, object
{
	
	CurrPos = 0;
	length = 1;

	try
	{
		data = new Type [length];
		data[0] = object;
	}
	catch(...)
	{
		std::cout << "\nCould not allocate memory for the Set ... aborting!\n";
		exit(0);
	}
}


template <class Type>
bool	aSet<Type> :: full()
{ 
	return ((CurrPos + 1) >= length);
}


template <class Type>
bool	aSet<Type> :: empty()
{ 
	return (CurrPos < 0);
}


template <class Type>
long	aSet<Type> :: size()
{
	return length;
}


template <class Type>
long	aSet<Type> :: get_CurrPos()
{
	return CurrPos;
}


template <class Type>
long	aSet<Type> :: get_length()
{
	return length;
}


template <class Type>
long	aSet<Type> :: get_data(long i)
{
	return data[i];
}


template <class Type>
bool aSet<Type> :: member (Type token)
//	Set membership test: Return true if token is in the set, false otherwise
{
	//	C++ Code Here
}


template <class Type>
void aSet<Type> :: resize(long newLength, bool & OK)
//	Resize the set length, up or down
{
	OK = true;

	if (newLength < 1)
		newLength = 1;

	if (CurrPos > (newLength - 1))
		CurrPos = newLength - 1;	//	resize downwards

	try
	{
		Type * newData = new Type [newLength];

		//	Now copy the old set into the new set
		for(long i = 0; i <= CurrPos; i++)
			newData[i] = data[i];
		
		//	Now copy back the new set into the old set
		data = newData;
		length = newLength;
	}
	catch(...)
	{
		std::cout << "\nCould not allocate memory for the new Set!\n";
		OK = false;
	}
}


template <class Type>
void aSet<Type> :: input(Type object, bool & OK)
//	Add the element, object, to the set -- no duplicates. NB: Elements of a set are unique
{
	//	C++ Code Here
}


template <class Type>
void aSet<Type> :: input()
//	Input set elements interactively and uniquely
{
	//	C++ Code Here
}


template <class Type>
void	aSet<Type> :: remove()
{
	CurrPos = -1;
}


template <class Type>
void aSet<Type> ::	remove(Type object, bool & flag)
{
	//	C++ Code Here
}


template <class Type>
void aSet<Type> :: display()
//	Display set elements in a First-Come-First-Served (FCFS) strategy
{
	//	C++ Code Here
}


template <class Type>
aSet<Type> aSet<Type> :: operator = (aSet<Type> right)
{
	//	C++ Code Here
}


template <class Type>
aSet<Type> aSet<Type> :: operator = (Type right)
// Make this set a singleton containing the element on the right
{
	//	C++ Code Here
}


//	o p e r a t o r s   S p e c i f i c a t i o n s

template <class Type>
aSet<Type> aSet<Type> :: operator + (aSet<Type> right)
/*	Adds (i.e concatenates) the two sets: this and right to get a new Set: this = this + right
	Procedure:
	1.	Resize this set to have size this->length + right.length
	2.	Then, input all elements of the right set from 0 to right.CurrPoss into this
		set, CurrPos+1 upwards, without duplicates.
*/
{
	//	C++ Code Here
}


template <class Type>
aSet<Type> aSet<Type> :: operator += (aSet<Type> right)
{
	//	C++ Code Here
}


template <class Type>
aSet<Type> aSet<Type> :: operator + (Type right)
//	appends the object right to this set, without duplicates
{
	//	C++ Code Here
}


template <class Type>
aSet<Type> aSet<Type> :: operator += (Type right)
{
	//	C++ Code Here
}


template <class Type>
aSet<Type>	operator + (Type left, aSet<Type> right)
//	appends the object left to the set right, without duplicates
{
	//	C++ Code Here
}


template <class Type>
aSet<Type> aSet<Type> :: operator - (aSet<Type> right)
/*	Subtracts (i.e excludes) the right set from this set: this = this - right */
{
	//	C++ Code Here
}


template <class Type>
aSet<Type> aSet<Type> :: operator -= (aSet<Type> right)
{
	//	C++ Code Here
}


template <class Type>
aSet<Type> aSet<Type> :: operator - (Type right)
{
	//	C++ Code Here
}


template <class Type>
aSet<Type> aSet<Type> :: operator -= (Type right)
{
	//	C++ Code Here
}


template <class Type>
aSet<Type> aSet<Type> :: operator * (aSet<Type> right)
/*	Return the intersection of this and right */
{
	//	C++ Code Here
}


template <class Type>
aSet<Type> aSet<Type> :: operator *= (aSet<Type> right)
{
	//	C++ Code Here
}


template <class Type>
aSet<Type> aSet<Type> :: operator * (Type right)
{
	//	C++ Code Here
}


template <class Type>
aSet<Type> aSet<Type> :: operator *= (Type right)
{
	//	C++ Code Here
}


template <class Type>
bool aSet<Type> :: operator == (aSet<Type> right)
/*	Returns true if this = right, false otherwise. Set1 = Set2 if
	0.	The two sets have the same lengths, i.e. Set1.length = Set2.length, and
	1.	Every member of Set1 is in Set2 and every member of Set2 is in Set1
*/
{
	//	C++ Code Here
}


template <class Type>
bool aSet<Type> :: operator > (aSet<Type> right)
{
	//	C++ Code Here
}


template <class Type>
bool aSet<Type> :: operator < (aSet<Type> right)
{
	//	C++ Code Here
}


template <class Type>
bool aSet<Type> :: operator >= (aSet<Type> right)
{
	//	C++ Code Here
}


template <class Type>
bool aSet<Type> :: operator <= (aSet<Type> right)
{
	//	C++ Code Here
}


template <class Type>
bool aSet<Type> :: operator != (aSet<Type> right)
{
	//	C++ Code Here
}


template <class Type>
bool aSet<Type> :: operator ! ()
{
	//	C++ Code Here
}



template <class Type>
std::istream & operator >> (std::istream & input, aSet<Type> & right)
/*	Inputs the set, right, from the input stream. E.g. cin >> right. */
{
	//	C++ Code Here
}


template <class Type>
std::ostream& operator << (std::ostream & output, aSet<Type> right)
/*	Prints the set right on the output stream. E.g. cout << right. */
{
	//	C++ Code Here
}

#endif
// ---- E n d   _a_SET_  S p e c i f i c a t i o n ----


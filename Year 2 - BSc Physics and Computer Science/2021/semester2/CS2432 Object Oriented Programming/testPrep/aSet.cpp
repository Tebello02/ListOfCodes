
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
	(2) S1 > S2 is true if S1 is a proper superset of S2, false otherwise
	(3) S1 == S2 is true if S1 is identical to S2, false otherwise
	(3) !S1 is true if S1 is empty, false otherwise

	(c) mofana mphaka; April 2020;
	Edited: May 2021
*/


#if !defined _a_SET_
#define _a_SET_

#include <iostream>


template <class Type>
class aSet
{
	//	P r i v a t e   D a t a / M e m b e r   f u n c t i o n s

	private:
		Type *	data;	//	"data" contains the set elements

		long	CurrPos,//	The pointer to current data element, data[CurrPos]: CurrPos = 0...length-1
				length;	//	The dimension of the "data" array


	//	P u b l i c   M e m b e r   f u n c t i o n s

	public:

		//	C l a s s   C o n s t r u c t o r s

		aSet();
		/*	Creates an empty Set */

		aSet(Type object);
		/*	Creates a singleton Set -- i.e. a set with just one element, "object" */

		//	C l a s s   D e s t r u c t o r

		~aSet();
		/*	Deletes the set, by C++ scoping rules */


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
		/*	Returns true if this set > the right set, false otherwise -- The Superset Rule*/

		bool operator < (aSet<Type> right);
		/*	Returns true if this set > right set, false otherwise -- The Subset Rule */

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
		/*	Returns the size (i.e. the length) of the set */

		long	get_length();
		/*	same as size()	*/

		long	get_CurrPos();
		/*	Returns the current set index, CurrPos */

		long	get_data(long i);
		/*	The look-up function: It returns the i-th element of the set, data[i]	*/

		long	cardinality();
		/*	Returns the number of elements in the set */

		long operator + ();
		/*	same as cardinality. USAGE: no_elements = +S, for any set S */

};


//	M e m b e r   f u n c t i o n s / o p e r a t o r s   S p e c i f i c a t i o n s


template <class Type>
aSet<Type> :: aSet()
/*
	Create an Empty Set as follows:

	1. CurrPos is set to -1
	2. Length is set to 1
	3. Then, data is dynamically created as an array of length 1, with exception handling
*/
{
	//	C++ code here
	CurrPos = -1;
	length = 1;

	try
	{
	    data = new Type [length];
	}
	catch(...)
	{
	    std::cout << "\nCould not allocate memory for the set!\n";
	    exit(0);
	}
}


template <class Type>
aSet<Type> :: aSet(Type object)
/*
	Create a Singleton Set with element, object, as follows:

	1. CurrPos is set to 0
	2. Length is set to 1
	3. Then, data is dynamically created as an array of length 1, with exception handling and
	4. data[CurrPos] = object
*/
{
	//	C++ code here
	CurrPos = 0;
	length = 1;

	try
	{
		data = new Type [length];
		data[CurrPos] = object;
	}
	catch(...)
	{
		std::cout << "\nCould not allocate memory for the Set ... aborting!\n";
		exit(0);
	}
}


template <class Type>
aSet<Type> :: ~aSet()
//	Destroy the set object using the C++ scoping rules.
//	The scoping rules will aslo automatically delete the "data" array
{
}


template <class Type>
bool	aSet<Type> :: full()
/*
	CurrPos must obey the relation

	0 <= CurrPos <= length - 1

	If CurrPos + 1 >= length then the set is full
*/
{
	return ((CurrPos + 1) >= length);
}


template <class Type>
bool	aSet<Type> :: empty()
/*
	Set elements reside at: 0 ... CurrPos

	If CurrPos < 0 then the set is empty
*/
{
	return (CurrPos < 0);
}


template <class Type>
long	aSet<Type> :: size()
//	Returns the length of the "data" array, length
{
	return length;
}


template <class Type>
long	aSet<Type> :: get_CurrPos()
//	Returns the current index position of the "data" array, CurrPos
{
	return CurrPos;
}


template <class Type>
long	aSet<Type> :: get_length()
//	Same as size()
{
	return length;
}


template <class Type>
long	aSet<Type> :: get_data(long i)
/*
	It returns the i-th element in the set as follows:

	1.	It makes sure that i obeys the relation: 0 <= i <= CurrPos
	2.	Then, it returns data[i]
*/
{
	//	C++ code here
	if (0 < i)
        i = 0;
    if (i > CurrPos)
        i = CurrPos;

    return data[i];
}


template <class Type>
long	aSet<Type> :: cardinality()
/*
	The set elements are from 0 to CurrPos.
	So, the cardinality of the set is CurrPos + 1
*/
{
	return CurrPos + 1;
}


template <class Type>
bool aSet<Type> :: member (Type token)
/*
	Set membership test:

	It returns true if token is in the set, false otherwise
*/
{
	//	C++ code here
	bool flag = 0; 

	// an empty set cannot contain the token
	if(!empty())
    for (long int i = 0; i < CurrPos; i++)
    {
      if (data[i] == token)
        flag = 1;
    }

  return flag; // the token is not in this set;
}


template <class Type>
void aSet<Type> :: resize(long newLength, bool & OK)
/*
	The resize function:

	It resizes the set length, up or down as follows:

	1.	It makes sure that newLength is at least 1
	2.	Then, if CurrPos > newLength - 1 then the set length will be resized down to
		newLength (and CurrPos set to newLength - 1)
*/
{
	OK = true;

	if (newLength < 1)
		newLength = 1;		//	length is always a positive number

	if (CurrPos > (newLength - 1))
		CurrPos = newLength - 1;	//	The set length has been reduced, reduce CurrPos as well

	try
	{
		Type * newData = new Type [newLength];	//	Create a newData array of newLength

		//	Now copy the old data array to the newData array, element-wise
		for(long i = 0; i <= CurrPos; i++)
			newData[i] = data[i];

		//	Now make the old data array pointer points to the newData array
		data = newData;

		//	and adjust the length of the old data array to be the newLength
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
	//	C++ code here
	do
	{
		OK=true;
		if (full())
		{
			resize(length +1,OK);
		}
		if(OK)
		{
			CurrPos++;
			data[CurrPos]=object;
		}

		if (member(object))
		{
		std::cout<<object<<"already exits in the set \n";
		}
	}
	while(object == member(object));
}


template <class Type>
void aSet<Type> :: input()
//	Input (all) the set elements interactively and uniquely
{
	//	C++ code here
	Type element;
	long int elements;
	bool OK;
	std::cout << "How many elements to enter : ";
	std::cin >> elements;

	if (elements > 0)
    {
        std::cout << "\nNow, enter the element(s) :\n";
        while (elements > 0)
        {
            std::cin >> element;
            input(element, OK);
            if (OK)
                elements--;  // elements decrement if user entered elements uniquely
        }
    }
    else
        std::cout << "\nnumber of elements equals zero\n";
}


template <class Type>
void	aSet<Type> :: remove()
/*
	Remove all elements in the set:

	Since the set elements are from 0 to CurrPos then if
	CurrPos is set to -1, then the set is empty!
*/
{
	CurrPos = -1;
}


template <class Type>
void aSet<Type> ::	remove(Type object, bool & flag)
/*
	An object is removed from the set as follows:

	1.	If the object is located at the i-th position then
	2.	all elements above the i-th position are packed downwards to cover the i-th slot
		i.e. the i+1 element is slided to the i-th position, the i+2 is then slided to the i+1 position, etc
	3.	Then, the CurrPos is reduced by 1, provided it is not yet -1.
*/
{
	long i = 0;
	flag = false;

	while((i <= CurrPos) && !(flag))
	{
		if (data[i] == object)
		{
			flag = true;

			//	Now pack data elements to close this gap

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
void aSet<Type> :: display()
/*
	Display the set elements in a First-Come-First-Served (FCFS) strategy.

	The elements are displayed as: {e1, e2, e3, ..., eN}
*/
{
	//	C++ code here
	if (empty())
        std::cout << "{}\n";

    else if (CurrPos == 0)
        std::cout << "{ " << data[0] << " }\n";
    else
    {
        std::cout << "{ ";
        for (long int i = 0; i < length - 1; i++)
        {
            std::cout << data[i] << ", ";
        }
        std::cout << data[length - 1] << " }\n";
    }
}


//	o p e r a t o r s   S p e c i f i c a t i o n s

template <class Type>
long aSet<Type> :: operator + ()
//	Same as cardinality()
{
	return this->CurrPos + 1;
}


template <class Type>
aSet<Type> aSet<Type> :: operator = (aSet<Type> right)
/*
	The assignment operator:

	For any two sets A and B

	A = B

	means that the set A is assigned the values of set B as follows:

	1.	First, set A is resized to the length of B, then
	2.	B is copied onto A, element-wise
*/
{
	//	C++ code here
	bool OK;
	this->CurrPos = right.CurrPos;  // since resize does not change current position
	this->resize(right.length, OK); // change the length of A using tools of resize function
	if (OK)  // if resize is successfully
    {
        for (long i = 0; i <= CurrPos; i++)
            data[i] = right.data[i];
    }
    return (*this);
}


template <class Type>
aSet<Type> aSet<Type> :: operator = (Type right)
/*
	The assignment operator:

	For any set A and an element e,

	A = e

	means that the set A is assigned the value of e as follows:

	1.	The data array of set A is created/resized to length 1, then
	2.	the "data" array is made to hold, just that one element, "e"
*/
{
	//	C++ code here
	bool OK;
	this->CurrPos = 0;
	this->resize(1, OK);  // use resize since it has exception handling
	if (OK)
        this->data[CurrPos] = right;

    return (*this);
}


template <class Type>
aSet<Type> aSet<Type> :: operator + (aSet<Type> right)
/*	Adds (i.e concatenates) the two sets: this and right to get a new Set: this = this + right
	Procedure:
	1.	Resize this set to have size this->length + right.length
	2.	Then, input all elements of the right set from 0 to right.CurrPoss into this
		set, CurrPos+1 upwards, without duplicates.
*/
{
	//	C++ code here
	bool OK;
	if (!this->empty() && !right.empty()) // both sets must be non empty because their length is 1 if they are empty
        this->resize(this->length + right.length, OK); // so resizing will increase length e.g. if both sets are empty,
    // this sets will be resized to have length 2, and that is undesired!
    else if (this->empty() && !right.empty())
        (*this) = right;// since union of empty and nonempty set equals nonempty set (uses assignment operator)

    // now, if both sets are nonempty and OK is true, then elements that are not members are added
    if (OK)  // from this current position + 1
    {
        for (long int i = 0; i <= right.CurrPos; i++)
        {
            if (!this->member(right.data[i]))
                this->data[++this->CurrPos] = right.data[i];  // while current position of this set is incremented
        }
        this->length = this->CurrPos + 1;// ensure this set has correct length in case not all elements of right were added,
        // because they are already members
    }

    // if both sets are empty, then this will be returned as an empty set
	return (*this);
}


template <class Type>
aSet<Type> aSet<Type> :: operator += (aSet<Type> right)
/*
	For any two sets A and B

	A += B

	has the meaning

	A = A + B
*/
{
	//	C++ code here
	return (*this) + right;
}


template <class Type>
aSet<Type> aSet<Type> :: operator + (Type right)
//	appends the object right to this set, without duplicates
{
	//	C++ code here

    aSet S(right);
    (*this) + S;  // since union is already defined, and the sum is already stored in this set

	/* the code could also be:
	bool OK;
	if (!this->member(right)) // if right is not a member of this set
    {
        this->resize(this->length + 1, OK);
        if (OK)
            this->data[++this->CurrPos] = right;
        // we want current position to keep incrementing each time this function is called
    }*/

    return (*this); // unchanged or with a new element added
}


template <class Type>
aSet<Type> aSet<Type> :: operator += (Type right)
/*
	For any set A and an element e

	A += e

	has the meaning

	A = A + e
*/
{
	//	C++ code here
	return (*this) + right;
}


template <class Type>
aSet<Type>	operator + (Type left, aSet<Type> right)
//	appends the object left to the set right, without duplicates
{
	aSet<Type> newSet;

	newSet = right;	//	copy right to avoid possible side effects

	newSet = newSet + left;

	return newSet;
}


template <class Type>
aSet<Type> aSet<Type> :: operator - (aSet<Type> right)
/*	Subtracts (i.e excludes) the right set from this set: this = this - right */
{
	//	C++ code here
	bool flag;
	if (!right.empty())
    {
        for (long int i = 0; i < right.length; i++)
        {
            this->remove(right.data[i], flag); // no need to check whether data[i] is a member or not, since remove()
        } // checks membership before removing elements, however, remove() doesnt adjust length so:
        this->length = this->CurrPos + 1;  // we could also use flag to decrement length accordingly
    }
    return (*this);
}


template <class Type>
aSet<Type> aSet<Type> :: operator -= (aSet<Type> right)
/*
	For any two sets A and B

	A -= B

	has the meaning

	A = A - B
*/
{
	//	C++ code here
	return (*this) - right;
}


template <class Type>
aSet<Type> aSet<Type> :: operator - (Type right)
/*
	Subtracts the element on the right from this set on the left. That is,

	A - e

	for a set A and an element e
*/
{
	//	C++ code here
	aSet S(right);
	(*this) = (*this) - S;
}


template <class Type>
aSet<Type> aSet<Type> :: operator -= (Type right)
/*
	For any set A and an element e

	A -= e

	has the meaning

	A = A - e
*/
{
	//	C++ code here
	return (*this) - right;
}


template <class Type>
aSet<Type> aSet<Type> :: operator * (aSet<Type> right)
/*
	The intersection of any two sets A and B is the set C defined as follows:

	C = A * B

	where for any element c of C, c is both an element of A and an element of B
*/
{
	//	C++ code here
	aSet<Type> C;

	if (!this->empty())
    {
        for (long i = 0; i < this->length; i++)
        {
            if (right.member(this->data[i]))// if any member of this set is also a member of right then,
            {
                C + this->data[i]; // add it to C
                // no need to increment length and current position accordingly for a set C, since sum operator(+) takes care of that
            }
        }
    }

    return C;
}


template <class Type>
aSet<Type> aSet<Type> :: operator *= (aSet<Type> right)
/*
	For any two sets A and B

	A *= B

	has the meaning

	A = A * B
*/
{
	//	C++ code here
	(*this) = (*this) * right;
	return (*this);
}


template <class Type>
aSet<Type> aSet<Type> :: operator * (Type right)
/*
	For any set A and an element e

	A * e

	is a new set C defined as

	C = A * {e}
*/
{
	//	C++ code here
	aSet<Type> E(right), C;
	C = (*this) * E;
	return C;
}


template <class Type>
aSet<Type> aSet<Type> :: operator *= (Type right)
/*
	For any set A and an element e

	A *= e

	has the meaning

	A = A * e
*/
{
	//	C++ code here
	aSet<Type> E(right);
	(*this) = (*this) * E;
	return (*this);
}


template <class Type>
bool aSet<Type> :: operator == (aSet<Type> right)
/*	Returns true if this == right, false otherwise. Set1 == Set2 if
	0.	The two sets have the same cardinality, and
	1.	Every member of Set1 is in Set2 and every member of Set2 is in Set1
*/
{
	//	C++ code here
	if (!this->empty() && !right.empty())
    {
        if (this->length == right.length)
        {
            for (long i = 0; i < this->length; i++)
            {
                if (!this->member(right.data[i]))// if there is at least one element that is not common in the two sets,
                    return false; // they are different
            }
            return true;// if ever the if statement in the loop is never true, then the two sets are equivalent
        }
        return false;// if the if statement is not satisfied, then the two set are different
    }
    else if (this->empty() && right.empty())
        return true;   // two empty sets are considered as equivalent

    else // negating the if statement, we get false if one set is empty and the other is not, or vice versa
        return false;
    // NOTE: {1, 2, 3} and {3, 2, 1} are equivalent sets, since sets are unordered by defination
}


template <class Type>
bool aSet<Type> :: operator > (aSet<Type> right)
/*
	The Superset Rule:

	For any two sets A and B

	A > B

	if the following holds

	1.	The cardinality of A is bigger than the cardinality of B and
	2.	every element of B is in A.
*/
{
	//	C++ code here
    if (this->empty() && !right.empty())
        return false;// this set cannot contain right set if its empty and right is nonempty

    else if (!this->empty() && right.empty())
        return true;// if this set is nonempty and right sets is empty then it is contained in this set

    else // case where both sets are nonempty
    {
        if (this->length > right.length)
        {
            for (long i = 0; i < right.length; i++) // loop through the smaller set
            {
                if (!this->member(right.data[i]))
                    return false;
            }
            return true; // logic is similar to comparison operator overloading above
        }
        return false;
    }
}


template <class Type>
bool aSet<Type> :: operator < (aSet<Type> right)
/*
	The Subset Rule:

	For any two sets A and B

	A < B iff B > A
*/
{
	//	C++ code here
	return (right > (*this));
}


template <class Type>
bool aSet<Type> :: operator >= (aSet<Type> right)
/*
	For any two sets A and B

	A >= B iff either A > B or A == B
*/
{
	//	C++ code here
	return ((*this) > right || (*this) == right);
}

template <class Type>
bool aSet<Type> :: operator <= (aSet<Type> right)
/*
	For any two sets A and B

	A <= B iff either A < B or A == B
*/
{
	//	C++ code here
	return ((*this) < right || (*this) == right);
}


template <class Type>
bool aSet<Type> :: operator != (aSet<Type> right)
/*
	For any two sets A and B

	A != B iff ! (A == B)
*/
{
	//	C++ code here
	return !((*this) == right);
}


template <class Type>
bool aSet<Type> :: operator ! ()
/*
	For any set A

	!A iff A is an empty set
*/
{
	return this->empty();
}



template <class Type>
std::istream & operator >> (std::istream & input, aSet<Type> & right)
/*	Inputs the set, right, from the input stream. E.g. cin >> right. */
{
	//	C++ code here
	// code is similar to input function that inputs all elements
	Type element;
	long int elements;
	bool OK;
	std::cout << "How many elements to enter : ";
	std::cin >> elements;

	if (elements > 0)
    {
        std::cout << "\nNow, enter the element(s) :\n";
        while (elements > 0)
        {
            input >> element;
            right.input(element, OK);
            if(OK)
                elements--;  // elements decrement if user entered elements uniquely
        }
    }
    else
        std::cout << "\nthe set is empty\n";

    return input;
}


template <class Type>
std::ostream& operator << (std::ostream & output, aSet<Type> right)
/*
	Prints the set right on the output stream. E.g. cout << right.

	The elements are printed as: {e1, e2, e3, ..., eN}
*/
{
	//	C++ code here
	if (right.empty())
        output << "{}\n";

    else if (right.get_CurrPos() == 0)
        output << "{ " << right.get_data(0) << " }\n";
    else
    {
        std::cout << "{ ";
        for (long int i = 0; i < right.get_length() - 1 ; i++)
        {
            output << right.get_data(i) << ", ";
        }
        std::cout << right.get_data(right.get_length() - 1 ) << " }\n";
    }

    return output;
}

#endif
// ---- E n d   _a_SET_  S p e c i f i c a t i o n ----

int main()
{

	aSet<int> S1, S2, P;
	bool flag;

	std::cout << "\nEnter Elements of Set, S1\n"; S1.input(1, flag);
	std::cout << "\nEnter Elements of Set, S2\n"; std::cin >> S2;

	std::cout << "\nThe Sets are as follows:\n";
	std::cout << "\nS1 = " << S1 << "\n";
	std::cout << "\nS2 = " << S2 << "\n";

	std::cout << "\nCardinality of S1 =  " << (+S1) << "\n";
	std::cout << "\nCardinality of S1 =  " << (+S2) << "\n";

	P = S1;

	std::cout << "\nS1 - S2 = " << (S1-S2) << "\n";
	std::cout << "\nS1 + S2 = " << (S1+S2) << "\n";

	std::cout << "\nThe Sets are STILL as follows:\n";
	std::cout << "\nS1 = " << P << "\n";
	std::cout << "\nS2 = " << S2 << "\n";

	std::cout << "\nComparing the two Sets:\n";
	std::cout << "\nS1 == S2 " << (P == S2) << "\n";
	std::cout << "\nS1 > S2 " << (P > S2) << "\n";
	std::cout << "\nS1 < S2 " << (P < S2) << "\n";

	return 1;
}

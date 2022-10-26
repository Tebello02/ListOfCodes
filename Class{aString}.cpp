/*	NAME: Class{aString}.cpp
	FUNCTION:

		This is a string class. A string data structure is formed as an
		array of characters: char string[256].

		The class has many relational and arithmetic operators overloaded.

	(C) mofana mphaka; April 2020
*/

#include <iostream>

#ifndef _a_STRING_CLASS_
#define _a_STRING_CLASS_

class aString
{
	//	F r i e n d    I n p u t / O u t p u t   O p e r a t o r s

	friend std::istream & operator >> (std::istream & input, aString & str);
	/*	Inputs the string from the input stream such as the console */

	friend std::ostream & operator << (std::ostream & output, aString str);
	/*	Outputs the string to the standard output stream, e.g.the console */


	//	F r i e n d    R e l a t i o n a l   O p e r a t o r s

	friend bool operator == (char * left, aString right);
	/*	Returns true if the C string left = the string right, false otherwise */

	friend bool operator == (char left, aString right);
	/*	Returns true if the character left = the string right, false otherwise */

	friend bool operator != (char * left, aString right);
	/*	Returns true if the C string left <> the string right, false otherwise */

	friend bool operator != (char left, aString right);

	friend bool operator > (char * left, aString right);

	friend bool operator > (char left, aString right);

	friend bool operator < (char * left, aString right);

	friend bool operator < (char left, aString right);

	friend bool operator >= (char * left, aString right);

	friend bool operator >= (char left, aString right);

	friend bool operator <= (char * left, aString right);

	friend bool operator <= (char left, aString right);


	//	F r i e n d    A r i t h m e t i c   O p e r a t o r s

	friend aString operator + (char left, aString right);
	/*	Appends the character left in front of the string right */

	friend aString operator + (char * left, aString right);
	/*	Inserts the C string on the left in front of the string on the right*/

	friend aString operator - (char left, aString right);
	/*	Removes the character on the left from the string right */

	friend aString operator - (char * left, aString right);
	/*	Deletes the C string left from the string right */


	//	P r i v a t e   S e c t i o n

	private:
		
		//	P r i v a t e   D a t a   M e m b e r s

		char	string[256];	//	The string array -- static, maximum length = 256 characters
		int		str_length;		//	The lenght of the string array: 0 <= str_length <= 256


		//	P r i v a t e   M e m b e r   F u n c t i o n s

		char	upcase (char ch);
		/*	Turns ch upcase */

		char	lowcase (char ch);
		/*	Turns ch low case */

		int		str_len(char * cString);
		/*	Returns the length of the C string, cString */

		bool	member(char ch, char * cString);
		/*	Returns true if ch is a member of cString, false otherwise. */


		bool is_sign(char ch);
		/*	Returns true if ch is one of: +, -, false otherwise */
		
		bool is_digit(char ch);
		/*	Returns true if ch represents a digit, false otherwise */
		
		int ch_to_digit(char ch);
		/*	converts the character, ch, to a digit equivalent. E.g. '1' is converted to 1 */
		
		long double exp(long double y, long n);
		/*	Returns y to power n */
		
		bool is_alpha(char ch);
		/*	Returns true if ch represents a letter of alphabet, false otherwise */

		bool is_alpha_numeric(char ch);
		/*	Returns true if ch is alpha-numeric, false otherwise */


	//	P u b l i c   S e c t i o n

	public:

		//	C o n s t r u c t o r s

		aString();
		/*	Sets the string to an empty string, str_length = 0 */

		aString(char ch);
		/*	Sets the string to ch, str_length = 1 */

		aString(char * cString); 
		/*	Sets the string to the C string value, cString,
			str_length to the length of the string value */


		//	M e m b e r   F u n c t i o n s

		void	input(char * msg, char _case = '0', char delimeter = '\n');
		/*	Reads the string, including white space, from the keyboard.
			The input is terminated whith a delimeter (default is new line).
			The string is coverted to upper case if _case = U, lower case if _case = L,
			otherwise the string is left as is	*/

		void	input(char * msg, char * inputChars, char _case = '0', char delimeter = '\n');
		/*	Reads the string from the keyboard, accepting only the characters in the
			input character set, inputChars. */

		bool is_digit(int from = -1, int upTo = -1);
		/*	Returns true if this string represents a number, false otherwise */

		long int_num();
		/*	Returns the integer number equivalent of this string. Eg. "123" yeilds 123  */

		long double real_num();
		/*	Returns the real number equivalent of this string. Eg. "12.123" yeilds 12.123  */

		bool is_alpha(int from = -1, int upTo = -1);
		/*	Returns true if this string represents a name string, false otherwise */

		bool is_alpha_numeric(int from = -1, int upTo = -1);
		/*	Returns true if this string is alpha-numeric, false otherwise */

		void	insert(char ch);
		/*	Inserts the character, ch, in front of the string */

		void	insert(char * cString);
		/*	Inserts the C string, cString, in front of the string */

		void	insert(aString String);
		/*	same as insert(char * cString) */

		void	insert(char ch, int pos);
		/*	Inserts ch in the string at position pos */

		void	insert(char * cString, int pos);
		/*	Inserts the C string in the string starting at position pos */

		void	insert(aString String, int pos);
		/*	same as insert(aString String, int pos) */


		void	append(char ch);
		/*	Inserts the character, ch, at the rear of the string */

		void	append(char * cString);
		/*	Appends the given C string, cString, to the string */

		void	append(aString String);
		/*	same as append(char * cString) */


		void	remove(char ch);
		/*	Deletes the given character, first occurrence, from the string */

		void	remove(char ch, int pos);
		/*	Deletes the given character, ch, at position, pos, from the string */

		void	remove(char * cString);
		/*	Deletes all the characters in cString from the string */

		void	remove(aString String);
		/*	same as remove(char * cString) */

		void	remove_all(char ch);
		/*	Deletes all the occurrences of ch from the string */

		void	remove_all(char * cString);
		/*	Deletes all the occurrences of characters in cString from the string */

		void	remove_all(aString String);
		/*	same as remove_all(char * cString) */


		void	set(char * cString);
		/*	Assigns the string the value of cString */

		void	set(aString String);
		/*	same as set(char * cString) */


		void	display();
		/*	Displays the string on the console */


		void	lowcase();
		/*	Turns the string low_case */

		void	upcase();
		/*	Turns the string up_case */


		void	reverse();
		/*	Reverses the string */

		void	resize();
		/*	Resizes the string to zero length. i.e. empty string */

		void	resize(int str_len);
		/*	Resizes the string to length str_len, 0 <= str_len <= str_length */


		int		size();
		/*	Returns the length of the string, str_length */

		int		length();
		/*	Same as size() */

		char *	value();
		/*	Returns the string value. Useful for conversion to C string */

		char * substr(int from, int length);
		/*	Returns the substring starting at, from, with length, length */

		bool substr(char * SubString);
		/*	Returns true if SubString is a substring of this string, false otherwise. */

		bool substr(char * SubString, int & pos);
		/*	Returns true if SubString is a substring of this string and sets pos to the position
			where the substring starts, false otherwise. */
		
		bool substr(aString SubString);
		/*	Returns true if SubString is a substring of this string, false otherwise. */
		
		bool substr(aString SubString, int & pos);
		/*	Returns true if SubString is a substring of this string and sets pos to the position
			where the substring starts, false otherwise. */
		
		int locate(char ch);
		/*	Returns the position where the character, ch, is located in the string. */

		int locate(char ch, bool & found);
		/*	Returns the position where the character, ch, is located in the string. It sets found to true
			if the character is found, false otherwise. */

		int locate(char * SubString);
		/*	Returns the position where SubString is located in the string. */
		
		int locate(char * SubString, bool & found);
		/*	Returns the position where SubString is located in the string. It sets found to true
			if SubString is found, false otherwise. */
		
		int locate(aString SubString);
		/*	same as locate(char * SubString) above. */
		
		int locate(aString SubString, bool & found);
		/*	same as locate(char * SubString, bool & found) above. */
		
		bool	empty();
		/*	Returns true if null string, false otherwise */

		bool	full();
		/*	Returns true if the 256 length barrier of the string has
			been reached, false otherwise */

		aString	* tokens(int & no_of_tokens, char _case = '\0');
		/*	It breaks down this string into a list of tokens (i.e. words) and the
			number of words in the string is returned as no_of_tokens (i.e. pass by reference)
		*/
		

		//	M e m b e r   O p e r a t o r s

		aString	operator = (aString right);
		/*	Assigns this string to the string on the right */


		//	T y p e - c a s t i n g    o p e r a t o r s

		aString	operator = (char right);
		/*	Converts the character right to a string of one character */

		aString	operator = (char * right);
		/*	Converts the C string on the right to this type of string */


		//	R e l a t i o n a l    o p e r a t o r s
		
		bool operator == (aString right);
		/*	Returns true if the left string is the same as the right string,
			false otherwise */

		bool operator == (char * right);
		/*	Returns true if the left string is the same as the C string right,
			false otherwise */

		bool operator == (char right);
		/*	Returns true if the left string is the same as the character right,
			false otherwise */

		bool operator != (aString right);
		/*	Returns true if the left string is not equal the right string,
			false otherwise */

		bool operator != (char * right);

		bool operator != (char right);

		bool operator > (aString right);
		/*	If left string > right string, return true, false otherwise */

		bool operator > ( char * right);

		bool operator > (char right);

		bool operator < (aString right);

		bool operator < (char * right);

		bool operator < (char right);

		bool operator >= (aString right);

		bool operator >= (char * right);

		bool operator >= (char right);

		bool operator <= (aString right);

		bool operator <= (char * right);

		bool operator <= (char right);
	
		bool operator ! ();
		/*	Returns true if the string is non-empty, false otherwise */


		//	A r i t h m e t i c    O p e r a t o r s
		
		aString operator + (aString right);
		/*	Concatenate the string left with the string right */

		aString operator + (char right);
		/*	Appends the character right to the string left */
	
		aString operator + (char * right);
		/*	Appends a C string, char *, on the right with the string left */

		aString operator += (aString right);
		/*	Returns left = left + right */

		aString operator += (char right);
		aString operator += (char * right);


		aString operator - (aString right);
		/*	Deletes all the characters in the string right from string left */

		aString operator - (char right);
		/*	Removes the character on the right from the string left */

		aString operator - (char * right);
		/*	Deletes all the chars in the C string right from the string left */

		aString operator -= (aString right);
		/*	Returns left = left - right */

		aString operator -= (char right);

		aString operator -= (char * right);

		//	Subscript range checking

		char		operator [] (int str_index);
		/*	The string index, str_index, always points to some string character */
};


aString :: aString()
//	Definition:	Default constructor, it initialises the string to the null
//				string and str_length to 0.
{
	str_length = 1;
	string[0] = '\0';
}


aString :: aString(char ch)
//	Definition:	It sets the string to ch and str_length to 1.
{
	str_length = 2;
	string[0] = ch;
	string[1] = '\0';
}


aString :: aString(char * cString)
//	Definition: It instantiates the string with the set value, cString
{
	for(str_length = 0; cString[str_length] != '\0'; str_length++)
		string[str_length] = cString[str_length];

	string[str_length] = '\0';
}


aString * aString :: tokens(int & no_of_tokens, char _case)
{
	int	tCount = -1,	//	token count -- the tcount-th token/word so far
		sCount = 0;	//	count on the next character in the string

	no_of_tokens = 0;	//	number of tokens so far

	char	tab = '\t',
			space = char(32),
			null = '\0';

	aString	*	TokenStr,	//	The array of tokens
			*	NewTokenStr,	//	another array of tokens (i.e. a copy of TokenStr + a new token)
				Token;

	TokenStr = new aString [1];

	while(sCount < str_length)	//	while not end of line
	{
		if ((string[sCount] != tab) && (string[sCount] != space) &&
		   (string[sCount] != null))
		{
			//	if the character is not one of the specified delimeters: space, tab, etc, then
			//	it is part of a word/token -- so, accumulate the token string
			tCount++;	//	next token
			no_of_tokens++;
			//Token[0] = new aString[1];
			//Token[0] = '\0';	//	initialise the token to an empty string, initially

			while ((string[sCount] != tab) && (string[sCount] != space) &&
				  (string[sCount] != null))
			{
				//	accumulate the token characters
				//	converting each character token to the appropriate case
				if (upcase(_case) == 'U')
					Token += upcase(string[sCount]);
				else if (upcase(_case) == 'L')
					Token += lowcase(string[sCount]);
				else
					Token += string[sCount];

				sCount++;	//	next char in the string
			}
		}
		
		//	Now build the tokens array

		if (no_of_tokens < 2)
			//	only one token so far -- just add it to the token array
			TokenStr[tCount] = Token;
		else
		{
			//	create an additional space to contain the new token, just built
			NewTokenStr = new aString[no_of_tokens + 1];

			//	now copy old token str into the new token str
			for(int i = 0; i < tCount; i++)
				NewTokenStr[i] = TokenStr[i];

			NewTokenStr[tCount] = Token;	//	accept the newly created token
			
			//	Finally, point the old token str to this new location
			TokenStr = NewTokenStr;
		}

		if ((string[sCount] == tab) || (string[sCount] == space))
			sCount++;	//	next character in the input stream
	}

	return TokenStr;
}


char aString :: upcase (char ch)
//	Definition:	upcase(...), converts the given character, ch, to its upper
//				case character equivalent. For example 'a' to 'A'.
//
//	Input:	character, ch
//	Output:	upper case of ch
{
	int ASCII_Code = int(ch);

	if ((ASCII_Code >= 97) && (ASCII_Code <= 122))
		return(char(ASCII_Code - 32));
	else
		return(ch);
}

		
char aString :: lowcase (char ch)
//	Definition:	lowcase(...), converts the given character, ch, to its lower
//				case character equivalent. For example 'A' to 'a'.
//
//	Input:	character, ch
//	Output:	lower case of ch
{
	int ASCII_Code = int(ch);

	if ((ASCII_Code >= 65) && (ASCII_Code <= 90))
		return(char(ASCII_Code + 32));
	else
		return(ch);
}


int aString :: str_len(char * cString)
//	Definition:	str_len(...) computes and returns the length of the given
//				C string, cString.
{
	int length = 0;

	while(cString[length] != '\0')	//	C strings are null terminated
		length++;

	return(length);
}


bool aString :: member(char ch, char * list)
//	Definition:	member(...) determines whether or not a given character, ch, is
//				a member of the given list of characters, list,
//				
// Inputs:	1.	character, ch and
//			2.	a list of characters, list, e.g "yYnN"
//			
// Outputs:	True if ch is one of the characters in the list, false otherwise
{
	for (int i = 0; i < str_len(list); i++)
	{	
		if(upcase(list[i]) == upcase(ch))
			return (true);
	}

	return(false);
}


bool aString :: empty()
{
	return((str_length - 1) < 0);
}


bool aString :: full()
{
	return((str_length + 1) > 256);
}


bool aString :: is_digit(char ch)
//	Definition:	is_digit (...) checks if the input character, ch, represents 
//				a digit value or not.
{
	switch(ch)
	{
		case '0' :
		case '1' :
		case '2' :
		case '3' :
		case '4' :
		case '5' :
		case '6' :
		case '7' :
		case '8' :
		case '9' : return(true);
		default : return(false);
	}
}


bool aString :: is_digit(int from, int upTo)
//	Definition:	is_digit (...),returns true if string represents an integer,
//				from the index, from, up to the index, upTo.
//				It returns false otherwise.
{
	if ((upTo < 0) || (upTo > str_length))
		upTo = str_length - 1;

	if (from < 0)
		from = 0;

	if (from > upTo)
		return false;
	else
	{
		for (int i = from; i <= upTo; i++)
			if (!is_digit(string[i]))
				return false;

		return true;
	}
}


bool aString :: is_alpha(char ch)
//	Definition:	is_alpha (...) checks if the input character, ch, represents 
//				a letter of alphabet or not.
{
	switch(lowcase(ch))
	{
		case 'a' :
		case 'b' :
		case 'c' :
		case 'd' :
		case 'e' :
		case 'f' :
		case 'g' :
		case 'h' :
		case 'i' :
		case 'j' :
		case 'k' :
		case 'l' :
		case 'm' :
		case 'n' :
		case 'o' :
		case 'p' :
		case 'q' :
		case 'r' :
		case 's' :
		case 't' :
		case 'u' :
		case 'v' :
		case 'w' :
		case 'x' :
		case 'y' :
		case 'z' :
		case '_' : return(true);
		default : return(false);
	}
}


bool aString :: is_alpha(int from, int upTo)
//	Definition:	is_alpha (...),returns true if string represents a name string,
//				from the index, from, up to the index, upTo.
//				It returns false otherwise.
//
{
	if ((upTo < 0) || (upTo > str_length))
		upTo = str_length - 1;

	if (from < 0)
		from = 0;

	if (from > upTo)
		return false;
	else
	{
		for (int i = from; i <= upTo; i++)
			if (!is_alpha(string[i]))
				return false;

		return true;
	}
}


bool aString :: is_alpha_numeric(char ch)
//	Definition:	is_alpha_numeric (...) checks if the input character, ch, represents 
//				a letter of alphabet or a digit not.
//
{
	return (is_alpha(ch) || is_digit(ch));
}


bool aString :: is_alpha_numeric(int from, int upTo)
//	Definition:	is_alpha_numeric(...),returns true if string is alpha-numeric,
//				from the index, from, up to the index, upTo.
//				It returns false otherwise.
{
	if ((upTo < 0) || (upTo > str_length))
		upTo = str_length - 1;

	if (from < 0)
		from = 0;

	if (from > upTo)
		return false;
	else
	{
		for (int i = from; i <= upTo; i++)
			if (!is_alpha_numeric(string[i]))
				return false;

		return true;
	}
}


char * aString :: value()
//	Definition:	value(), typecasts aString to a C string.
//				It returns a copy of the string data -- not the actual string data
{
	char * cString = new char [str_length];

	for(int i = 0; i < str_length; i++)
		cString[i] = string[i];

	cString[str_length] = '\0';

	return cString;
}


char * aString :: substr(int from, int length)
//	Definition:	substr(...), returns a substring of length, length,
//				from position, from, in the string.
{
	int i, j;

	char * substring = new char[str_length+1];

	if (from < 0)
		from = 0;

	if ((length < 0) || (length >= str_length))
		length = str_length;

	//	Initialise the substring
	for(i = 0; i < str_length+1; i++)
		substring[i] = '\0';

	for(i = 0, j = from; ( (i < length) && (j < str_length)); i++, j++)
		substring[i] = string[j];

	return(substring);
}


bool aString :: substr(char * SubString)
//	Definition:	substr(...), returns true if the given string, SubString,
//				is a substring of this string.
{
	int	substr_len = str_len(SubString),
		pos = 0;
	
	aString	NewSubStr;

	if (substr_len <= str_length)
	{	
		while(pos < str_length)
		{
			NewSubStr = substr(pos, substr_len);

			if (NewSubStr == SubString)
				return true;
			else
				pos++;
		}

		return(false);
	}
	else
		return(false);
}


bool aString :: substr(aString SubString)
//	Definition:	substr(...), same as substr(char * SubString).
{
	return(substr(SubString.value()));
}


bool aString :: substr(char * SubString, int & pos)
//	Definition:	substr(...), returns true if the given string, SubString,
//				is a substring of this string. It sets pos as follows:
//				1.	0 <= pos < string length if SubString is a substring of this string
//				2.	pos = -1 if SubString is not a substring of this string
{
	int	substr_len = str_len(SubString);
	
	aString	NewSubStr;

	pos = -1;

	if (substr_len <= str_length)
	{
		//	SubString might be a substring of this string.
		//	Find the position, pos, where the substring starts in the string

		pos = 0;
	
		while(pos < str_length)
		{
			NewSubStr = substr(pos, substr_len);

			if (NewSubStr == SubString)
				return true;
			else
				pos++;
		}

		pos = -1;	//	SubString is not a substring of this string
		return(false);
	}
	else
		return(false);
}


bool aString :: substr(aString SubString, int & pos)
//	Definition:	substr(...), same as substr(char * SubString, int & pos).
{
	return(substr(SubString.value(), pos));
}


int aString :: locate(char ch, bool & found)
//	Definition: locate(ch, found), returns the position where the character, ch,
//				is located in the string. It sets found to true if the character
//				is found (first occurrence), false otherwise.
{
	int pos = 0;
	found = false;

	for(; pos < str_length; pos++)
		if (upcase(string[pos]) == upcase(ch))
		{
			found = true;
			return pos;
		}

	return(pos);	//	pos = str_length -- ch not located
}


int aString :: locate(char ch)
//	Definition: locate(ch, found), returns the position where the character, ch,
//				is located in the string. Position is set as follows:
//				1.	0 <= position < string length, if ch is located
//				2.	position = -1, if ch is not located.
{
	int pos = 0;
	
	for(; pos < str_length; pos++)
		if (upcase(string[pos]) == upcase(ch))
			return pos;

	pos = -1;	//	pos = -1, ch not located
	return(pos);
}


int aString :: locate(char * SubString, bool & found)
//	Definition:	locate(SubString, found), returns the position where SubString
//				is located in the string. It sets found to true if SubString is found,
//				false otherwise.
{
	int pos = 0;
	found = substr(SubString, pos);
	return pos;
}


int aString :: locate(char * SubString)
//	Definition:	locate(SubString, found), returns the position where SubString
//				is located in the string. It sets found to true if SubString is found,
//				false otherwise.
{
	int pos = 0;
	bool found = substr(SubString, pos);
	return pos;
}


int aString :: locate(aString SubString, bool & found)
/*	same as locate(char * SubString, bool & found) above. */
{
	int pos = 0;
	found = substr(SubString, pos);
	return pos;
}


int aString :: locate(aString SubString)
/*	same as locate(char * SubString) above. */
{
	int pos = 0;
	bool found = substr(SubString, pos);
	return pos;
}


void aString :: set(char * cString)
//	Definition:	set(...), sets the value of the string to a string value,
//				cString, and sets str_length to the length of cString.
{
	for(str_length = 0; cString[str_length] != '\0'; str_length++)
		string[str_length] = cString[str_length];

	string[str_length] = '\0';
}


void aString :: set(aString String)
//	Definition:	same as set(char * cString) above.
{
	set(String.value());
}


void aString :: input(char * msg, char _case, char delimeter)
//	Definition:	input(...), reads the entire string from the keyboard.
//				White space, except delimeter, is accepted as part of the
//				string input. In addition, the read string is
//				converted to upper case if _case = U or lower case if _case = L,
//				otherwise the string is left as is.
{
	char	null = char(0),
			back_space = char(8),
			ch;

	_case = upcase(_case);

	//	Now read the string upto length-1
	str_length = 0;
	std::cout << msg;

	ch = getchar();
	do
	{
		if ((ch != back_space) && (ch != delimeter) && (str_length < 256))
		{
			if (_case == 'U')
				ch = upcase(ch);
			else if (_case == 'L')
				ch = lowcase(ch);

			string[str_length] = ch;
			str_length++;
		}
		else if (ch == back_space)
		{
			//	delete the string backwards
			if (str_length >= 0)
				str_length--;
		}

		ch = getchar();
	}
	while ((ch != delimeter) && (str_length < 256));

	if (str_length >= 256)
		str_length = 256;
	else if (str_length <= 0)
		str_length = 0;

	string[str_length] = null;
}


void aString :: input(char * msg, char * inputChars, char _case, char delimeter)
//	Definition:	input(...), reads the entire string from the keyboard.
//				White space, except new line, is accepted as part of the
//				string input. In addition, the read string is
//				converted to upper case if _case = U or lower case if _case = L,
//				otherwise the string is left as is.
{
	char	null = char(0),
			back_space = char(8),
			ch;

	_case = upcase(_case);

	//	Now read the string upto length-1
	str_length = 0;
	std::cout << msg;

	ch = getchar();
	do
	{
		if ((ch != delimeter) && member(ch, inputChars) && (str_length < 256))
		{
			if (_case == 'U')
				ch = upcase(ch);
			else if (_case == 'L')
				ch = lowcase(ch);

			string[str_length] = ch;
			str_length++;
		}
		else if ((ch == back_space) && !member(ch, inputChars))
		{
			//	delete the string backwards
			if (str_length >= 0)
				str_length--;
		}

		ch = getchar();
	}
	while ((ch != delimeter) && (str_length < 256));

	if (str_length >= 256)
		str_length = 256;
	else if (str_length <= 0)
		str_length = 0;

	string[str_length] = null;
}


void aString :: insert(char ch)
//	Definition:	insert(...), inserts the character, ch, in front of the string
//				It has the same effect as operator: ch + string.
//	
{
	if (!full())
	{
		//	Shift characters from position 0 to 1 .. str_length

		for(int i = str_length; i > 0; i--)
			string[i] = string[i - 1];

		string[0] = ch;
		str_length++;
		string[str_length] = '\0';
	}
}


void aString :: insert(char * cString)
{
	for(int i = str_len(cString) - 1; i >= 0; i--)
		insert(cString[i]);
}


void aString :: insert(aString String)
{
	insert(String.value());
}


void aString :: insert(char ch, int pos)
//	Definition:	insert(...), inserts the character, ch, at position, pos, in
//				the string. If pos <= 0, ch is inserted in front of the string.
//				If pos >= str_length-1, ch is appended at the rear of the string.
{
	if (pos <= 0)
		pos = 0;	//	insert ch in front -- string[0]

	if (pos >= str_length)
		pos = str_length;	//	insert ch at the rear -- append

	if (!full())
	{
		for(int i = str_length; i > pos; i--)
			string[i] = string[i - 1];
		
		string[pos] = ch;
		str_length++;
		string[str_length] = '\0';
	}
}


void aString :: insert(char * cString, int pos)
{
	for(int i = 0; i < str_len(cString); i++)
	{
		insert(cString[i], pos);
		pos++;
	}
}


void aString :: insert(aString String, int pos)
{
	insert(String.value(), pos);
}


void aString :: append(char ch)
//	Definition:	append(...), appends the character, ch, at the rear of the string.
//				It has the same effect as the operator: string + ch
{
	if (!full())
	{
		string[str_length] = ch;
		str_length++;
		string[str_length] = '\0';
	}
}


void aString :: append(char * cString)
{
	for(int i = 0; i < str_len(cString); i++)
		append(cString[i]);
}


void aString :: append(aString String)
{
	append(String.value());
}


void aString :: remove(char ch)
//	Definition:	remove(...), deletes the first occurrence of character, ch, from the string.
//				It has the same effect as operator: string - ch.
//
//	Inputs:		1.	The character to delete, ch.
//
//	Outputs:	1.	The new string with ch removed.
{
	int		pos = 0;
	bool	found = false;

	while ((pos < str_length) && (!found))
	{
		if (upcase(string[pos]) == upcase(ch))
			found = true;
		else
			pos++;
	}

	if (found)
	//	delete the character at position pos
	{
		for(pos = pos; pos < str_length - 1; pos++)
			string[pos] = string[pos+1];

		//	Now adjust the length of the string by - 1
		str_length--;
		string[str_length] = '\0';
	}
}


void aString :: remove(char ch, int pos)
//	Definition:	remove(...), deletes the character, ch, at position, pos, from the string.
//
//	Inputs:		1.	The character to delete, ch.
//
//	Outputs:	1.	The new string with ch removed.
{
	if (pos < 0)
		pos = 0;
	else if (pos >= str_length)
		pos = str_length - 1;

	if (upcase(string[pos]) == upcase(ch))
	{
		for(pos = pos; pos < str_length - 1; pos++)
			string[pos] = string[pos+1];

		str_length--;
		string[str_length] = '\0';
	}
}


void aString :: remove(char * cString)
//	Definition:	remove(...), deletes the substring, cString, from the string.
//				It does nothing if cString is not a substring of the string.
//
{
	int pos;

	if (substr(cString, pos))
	{
		for(int i = 0; i < str_len(cString); i++)
			remove(cString[i], pos);
	}
}


void aString :: remove(aString String)
{
	remove(String.value());
}


void aString :: remove_all(char ch)
//	Definition:	remove_all(...), deletes all the occurrences of ch from this string.
//
//	Inputs:		1.	The character to delete, ch.
//
//	Outputs:	1.	The new string with ch removed.
{
	int		pos = 0;

	while (pos < str_length)
	{
		if (upcase(string[pos]) == upcase(ch))
		{
			for(int i = pos; i < str_length - 1; i++)
				string[i] = string[i+1];

			str_length--;
			string[str_length] = '\0';

			pos--;	//	decrement pos by 1 since all chars have shifted leftwards
		}

		pos++;		//	increment pos by 1 -- move forward
	}
}


void aString :: remove_all(char * cstring)
//	Definition:	remove_all(...), deletes all occurrences of characters in string
//
//	Inputs:		1.	The list of characters to delete, cstring.
//
//	Outputs:	1.	The new string with all the occurrences of characters in cstring removed.
{
	for (int pos = 0; pos < str_len(cstring); pos++)
		remove_all(cstring[pos]);
}


void aString :: remove_all(aString String)
{
	remove_all(String.value());
}


void aString :: display()
{
	std::cout << string << "\n";
}


int aString :: size()
{
	return str_length;
}


int aString :: length()
{
	return str_length;
}


void aString :: upcase()
{
	for(int i = 0; i < str_length; i++)
		string[i] = upcase(string[i]);
}


void aString :: lowcase()
{
	for(int i = 0; i < str_length; i++)
		string[i] = lowcase(string[i]);
}


void aString :: resize()
//	Definition:	resize(...),resizes the string to an empty string
{
	str_length = 0;
	string[0] = '\0';
}


void aString :: resize(int str_len)
//	Definition:	resize(...), resizes the string to str_len:
//				0 <= str_len <= str_length
{
	if (str_len <= 0)
		str_len = 0;

	if (str_len >= str_length)
		str_len = str_length;

	str_length = str_len;
	string[str_length] = '\0';
}


void aString :: reverse()
//	Definition:	reverse(), reverses the string.
{
	for(int i = 0, j = str_length - 1;((i < str_length) && (i < j));(i++, j--))
	{
		// Swap string[i] with string[j]
		char ch = string[i];
		string[i] = string[j];
		string[j] = ch;
	}
}


bool aString :: is_sign(char ch)
{
	return ((ch == '+') || (ch == '-'));
}


int aString :: ch_to_digit(char ch)
//	Definition:	ch_to_digit (...) converts the input character, ch, to the digit
{
	switch(ch)
	{
		case '0' : return(0);
		case '1' : return(1);
		case '2' : return(2);
		case '3' : return(3);
		case '4' : return(4);
		case '5' : return(5);
		case '6' : return(6);
		case '7' : return(7);
		case '8' : return(8);
		case '9' : return(9);
		default : return(0);
	}
}


long aString :: int_num()
//	Definition:	int_num () converts the input string to integer number
{
	//	integer = (+|-)? digits
	//	digits = digit (digit)*
	//	digit = [0-9]
	
	long integer = 0, i = 0, sign = 1;

	if (is_sign(string[0]))
	{
		if (string[0] == '-')
			sign = -1;
		i++;	//	skip the sign character, having noted it.
	}

	for(; ((i < str_length) && is_digit(string[i])); i++)
	{
		integer = integer * 10 + ch_to_digit(string[i]);
	}

	return(sign * integer);	//	return the number with appropriate sign
}


long double aString :: exp(long double y, long n)
//	Definition: exp(y, n) = y to power n
{
	long double	exponent = 1;
	bool		negative = false;	// assume that n is not negative

	if (n < 0)
	{
		negative = true;
		n = (-1)*n;				// make n positive for iteration
	}

	while (n > 0)
	{
		exponent = exponent * y;
		n--;
	}

	if (negative)
		return (1/exponent);
	else
		return(exponent);
}


long double aString :: real_num()
//	Definition:	real_num () converts the input string to its real number equivalent
{
	//	Number = digits (. digits)? ( e (+|-)? digits)?
	//	digits = digit (digit)*
	//	digit = [0-9]
	int i = 0,
		NumSign = 1;	// Assume the number is positive
		
	long double dec_frac = 0,	//	The extracted mantissa part
				NumValue = 0;	//	The value of the extracted number
				
	if (is_sign(string[i]))
	{
		if (string[i] == '-')
			NumSign = -1;	// The number is negative
		i++;
	}
	
	if (i < str_length)
		while ((i < str_length) && is_digit(string[i]))
		{
			NumValue = NumValue * 10 + ch_to_digit(string[i]);	//	build the integer part of the number
			i++;
		}
	
	if (i < str_length)
		if (string[i] == '.')	// possible decimal coming
		{
			//	Number = digits . digits
			i++;
		
			int j = 1;	//	j is the power index in exp(10, j)
		
			if (i < str_length)
				while ((i < str_length) && is_digit(string[i]))
				{		
					dec_frac = dec_frac + ch_to_digit(string[i])/exp(10, j);
					j++;
					i++;
				}
		}
	
	NumValue = NumValue + dec_frac;	//	add the integer part and the decimal fraction
	
	if (i < str_length)
		if ((string[i] == 'e')|| (string[i] == 'E'))	// possible mantissa - e [+|-] digits
		{
			//	Number = digits . digits e (+|-)? digits
			i++;
		
			char MantissaSign = '+';	// Assume the mantissa is positive
		
			dec_frac = 0;	//	dec_frac will hold the integer value of the mantissa
		
			if (i < str_length)
				if (is_sign(string[i]))	// signed mantissa
				{
					//	Number = digits . digits e (+|-) digits	
					MantissaSign = string[i];
					i++;
				}
		
			if (i < str_length)
				while ((i < str_length) && is_digit(string[i]))
				{
					//	Number = digits . digits e (+|-) digits
					dec_frac = dec_frac * 10 + ch_to_digit(string[i]);	//	build the exponent of the mantissa
					i++;
				}
			
			if (MantissaSign == '-')
				NumValue = NumValue * exp(10, -1 * dec_frac);
			else
				NumValue = NumValue * exp(10, dec_frac);
		}
	
	return NumSign * NumValue;
}


aString aString :: operator = (aString right)
{
	for(int i = 0; right.string[i] != '\0'; i++)
		this->string[i] = right.string[i];
	
	this->str_length = right.str_length;
	this->string[this->str_length] = '\0';

	return(*this);
}


aString aString :: operator = (char * right)
//	Type cast a C string, char *, to aString
{
	int i;

	for(i = 0; right[i] != '\0'; i++)
		this->string[i] = right[i];
	
	this->str_length = i;
	this->string[this->str_length] = '\0';

	return(*this);
}


aString aString :: operator = (char right)
//	Type cast a character, char, to aString
{
	this->string[0] = right;
	this->str_length = 1;
	this->string[1] = '\0';
	return(*this);
}


char aString :: operator [] (int str_index)
//	Always checks and asserts that the subscript, str_index, is within range
{
	if (this->empty())
		return('\0');
	else
	{
		if (str_index <= 0)
			return(string[0]);

		else if (str_index >= str_length)
			return(string[str_length - 1]);

		else
			return(string[str_index]);
	}
}


std::istream & operator >> (std::istream & input, aString & str)
{

	char	null = char(0),
			new_line = char(10),
			back_space = char(8),
			ch;

	//	Now read the string upto length-1
	str.str_length = 0;
	ch = getchar();
	do
	{
		if ((ch != back_space) && (ch != new_line) && (str.str_length < 256))
		{
			str.string[str.str_length] = ch;
			str.str_length++;
		}
		else if (ch == back_space)
		{
			//	delete the string backwards
			if (str.str_length >= 0)
				str.str_length--;
		}

		ch = getchar();
	}
	while ((ch != new_line) && (str.str_length < 256));

	if (str.str_length >= 256)
		str.str_length = 256;
	else if (str.str_length <= 0)
		str.str_length = 0;

	str.string[str.str_length] = null;

	return(input);
}


std::ostream & operator << (std::ostream & output, aString str)
{
	output << str.string;
	return (output);
}


bool aString :: operator == (aString right)
//	Definition:	Two strings, left and right are equal if and only if
//				1.	the left string has the same lenght as the right string and
//				2.	the two strings have identical characters in order.
{
	if(this -> str_length == right.str_length)
	{
		for (int i = 0; i < this -> str_length; i++)
			if(this -> string[i] != right.string[i])
				return (false);

		return (true);
	}
	else
		return(false);
}


bool aString :: operator == (char * right)
{
	aString right_str = right;	//	Type cast C string right to a string

	return(*this == right_str);
}


bool operator == (char * left, aString right)
{
	aString left_str = left;

	return(left_str == right);
}


bool aString :: operator == (char right)
{
	aString right_str = right;	//	Type cast char right to a string

	return(*this == right_str);
}


bool operator == (char left, aString right)
{
	aString left_str = left;

	return(left_str == right);
}


bool aString :: operator != (aString right)
{
	return(!(*this == right));
}


bool aString :: operator != (char * right)
{
	return(!(*this == right));
}


bool operator != (char * left, aString right)
{
	return(!(left == right));
}


bool aString :: operator != (char right)
{
	return(!(*this == right));
}


bool operator != (char left, aString right)
{
	return(!(left == right));
}


bool aString :: operator ! ()
//	Returns true if this string is not empty. That is, ~empty()
{
	return(( this -> str_length - 1) >= 0);
}


bool aString :: operator > (aString right)
//	Definition:	Left > right (i.e. L > R) if and only if
//				1.	L[0]>R[0] || L[0]==R[0]&&L[1]>R[1] || L[0]==R[0]&&L[1]==R[1]&&L[2]>R[2]...
//				2.	If the two strings are identical to some lenght N where one of them
//					ends, then the longer string is the one larger than the other.
{
	//	Use the shorter length of the two strings

	int count = (this -> str_length < right.str_length)? this -> str_length : right.str_length;

	int i = 0;

	while(i < count)
	{
		if (this->string[i] > right.string[i])
			//	The left char > right char. So, left string > right string
			return(true);

		else if (this->string[i] == right.string[i])
			//	The left char == the right char. So, compare the next two characters
			i++;

		else
			//	The left char < right char.
			return(false);
	}

	//	Up to this point left == right. So, compare their lengths
	if (this->str_length > right.str_length)
		return(true);
	else
		return(false);
}


bool aString :: operator > (char * right)
{
	aString right_str = right;	//	Type cast the C string right to a string
	
	return(*this > right_str);
}


bool operator > (char * left, aString right)
{
	aString left_str = left;
	
	return(left_str > right);
}


bool aString :: operator > (char right)
{
	aString right_str = right;
	
	return(*this > right_str);
}


bool operator > (char left, aString right)
{
	aString left_str = left;
	
	return(left_str > right);
}


bool aString :: operator < (aString right)
{
	return(right > (*this));
}


bool aString :: operator < (char * right)
{
	return(right > (*this));
}


bool operator < (char * left, aString right)
{
	return(right > left);
}


bool aString :: operator < (char right)
{
	return(right > (*this));
}


bool operator < (char left, aString right)
{
	return(right > left);
}


bool aString :: operator >= (aString right)
{
	return((*this > right) || (*this == right));
}


bool aString :: operator >= (char * right)
{
	return((*this > right) || (*this == right));
}


bool operator >= (char * left, aString right)
{
	return((left > right) || (left == right));
}


bool aString :: operator >= (char right)
{
	return((*this > right) || (*this == right));
}


bool operator >= (char left, aString right)
{
	return((left > right) || (left == right));
}


bool aString :: operator <= (aString right)
{
	return((*this < right) || (*this == right));
}


bool aString :: operator <= (char * right)
{
	return((*this < right) || (*this == right));
}


bool operator <= (char * left, aString right)
{
	return((left < right) || (left == right));
}


bool aString :: operator <= (char right)
{
	return((*this < right) || (*this == right));
}


bool operator <= (char left, aString right)
{
	return((left < right) || (left == right));
}


aString aString :: operator + (aString right)
//	Definition:	append the right string to the left string.
{
	int i, j;
	
	aString left;
	
	left = *this;	//	copy *this to avoid side effects

	for(i = left.str_length, j = 0; ((i < 256) && (j < right.str_length)); i++, j++)
		left.string[i] = right.string[j];

	left.str_length = i;
	left.string[left.str_length] = '\0';

	return(left);
}


aString aString :: operator + (char right)
{
	aString left;	
	
	left = *this;
	
	if (!left.full())
	{
		left.string[left.str_length] = right;
		left.str_length++;
		left.string[left.str_length] = '\0';
	}
	return(left);
}


aString operator + (char left, aString right)
{
	aString copy_right;
	copy_right = right;	//	copy right string to avoid side effects.
	
	if (!copy_right.full())
	{
		//	Shift characters from position 0 to 1 .. str_length

		for(int i = copy_right.str_length; i > 0; i--)
			copy_right.string[i] = copy_right.string[i - 1];

		copy_right.string[0] = left;
		copy_right.str_length++;
		copy_right.string[copy_right.str_length] = '\0';
	}
	return(copy_right);
}


aString aString :: operator + (char * right)
{
	aString left;
	left = *this;
	
	for(int i = 0; i < left.str_len(right); i++)
		left = left + right[i];

	return (left);
}


aString operator + (char * left, aString right)
{
	for(int i = right.str_len(left) - 1; i >= 0; i--)
		right = left[i] + right;

	return(right);
}


aString aString :: operator += (aString right)
{
	*this = *this + right;
	return(*this);
}


aString aString :: operator += (char right)
{
	*this = *this + right;
	return(*this);
}


aString aString :: operator += (char * right)
{
	*this = *this + right;
	return(*this);
}


aString aString :: operator - (char right)
{
	int		pos = 0;
	bool	found = false;
	
	aString left;
	left = *this;

	while ((pos < left.str_length) && (!found))
	{
		if (left.string[pos] == right)
			found = true;
		else
			pos++;
	}

	if (found)
	//	delete the character at position pos
	{
		for(pos = pos; pos < left.str_length - 1; pos++)
			left.string[pos] = left.string[pos+1];

		//	Now adjust the length of the string by - 1
		left.str_length--;
		left.string[left.str_length] = '\0';
	}

	return(left);
}


aString aString :: operator - (aString right)
{
	int pos;
	char * cString = right.value();
	
	aString left;
	left = *this;

	if (left.substr(cString, pos))
	{
		for(int i = 0; i < right.str_length; i++)
			left.remove(cString[i], pos);
	}

	return(left);
}


aString operator - (char left, aString right)
{
	aString left_str = left;

	return(left_str - right);
}


aString aString :: operator - (char * right)
{
	aString right_str = right;
	
	aString left;
	left = *this;

	return(left - right_str);
}


aString operator - (char * left, aString right)
{
	aString left_str = left;

	return(left_str - right);
}


aString aString :: operator -= (aString right)
{
	*this = *this - right;
	return(*this);
}


aString aString :: operator -= (char right)
{
	*this = *this - right;
	return(*this);
}


aString aString :: operator -= (char * right)
{
	*this = *this - right;
	return(*this);
}

#endif // Class aString ends here
/*
int main()
{
	aString S("hello");
	std::cout << S << "\n";
	S.input("Enter a String", 'u');
	S.display();
}
*/

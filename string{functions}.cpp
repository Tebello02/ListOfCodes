/*
	AUTHOR: Mofana Mphaka
	FILE NAME: string{functions}.cpp
	FUNCTION:
		This source code is intended to contain a list of some string
		functions some of which may not be contained in the standard C++ (class)
		libraries. E.g. cstdlib, string.

	DATE: (C) mofana mphaka; February 2010
*/

#include <iostream>

#ifndef _STRING_FUNCTIONS_
#define _STRING_FUNCTIONS_

/*-------------------------------------------------------------------------*/
//	There are no Function Prototypes only Function Specifications are given//
/*-------------------------------------------------------------------------*/

char upcase (char ch)
//	Definition:	upcase(...), converts the given character, ch, to its upper
//				case equivalent. For example 'a' is converted to 'A'.
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


char lowcase (char ch)
//	Definition:	lowcase(...), converts the given character, ch, to its lower
//				case equivalent. For example 'A' is converted to 'a'.
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


int str_len(char * cstring)
//	Definition:	str_len(...), computes and returns the length of the
//				given string, cstring.
//
//	Inputs:		The C string, cstring
//
//	Outputs:	The computed length of the given C string.
{
	int length;

	//	C(++) strings are null terminated. That is, the last character
	//	of the string is the null (i.e. '\0') character
	for(length = 0; cstring[length] != '\0'; length++);

	return(length);
}


char * upcase(char * list)
//	Definition:	upcase(...) converts the given list of characters, list,
//				to upper case.
//
//	Inputs:		The input list of characters, list
//
//	Outputs:	The list of characters in upper case
{
	int strLength = str_len(list);

	char * upcase_str = new char[strLength];

	for(int i = 0; i < strLength; i++)
	{
		upcase_str[i] = upcase(list[i]);
	}

	upcase_str[strLength] = '\0';

	return(upcase_str);
}


char * lowcase(char * list)
//	Definition:	str_lowcase(...) converts the given list of characters, list,
//				to lower case.
//
//	Inputs:		The input list of characters, list
//
//	Outputs:	The list of characters in lower case
{
	int strLength = str_len(list);

	char * lowcase_str = new char[strLength];

	for(int i = 0; i < strLength; i++)
	{
		lowcase_str[i] = lowcase(list[i]);
	}
	
	lowcase_str[strLength] = '\0';

	return(lowcase_str);
}


bool member(char ch, char * list)
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


char getAnswer(char * msg, char * options)
//	Definition:	getAnswer(...) gets a character input from the keyboard only
//				if the user types a correct character which must be one of the
//				listed character options.
//				
//	Inputs:	1.	The message, msg, to display and
//			2.	A list of answer options, options, to	choose from.

//	Output:	1.	An answer, char, which is one of the listed options
{
	char ans;

	do
	{
		std::cout << msg << " ";
		std::cin >> ans;
	}
	while (!member(ans, options));

	return (ans);
}


char * add(char * str1, char * str2)
//	Definition:	add(...), concatenates the two strings: str1 and str2
//				in that order.
//
//	Inputs:		1.	The first string, str1
//				2.	The second string, str2.
//
//	Outputs:	str1 + str2 (i.e. str2 appended to str1).
{
	int newLength = str_len(str1) + str_len(str2);

	char * newString = new char [newLength];
	int i, j;

	//	Append Str1 to newString
	for (i = 0; i < str_len(str1); i++)
		newString[i] = str1[i];
	
	//	Then, append Str2 to the result
	for (j = 0, i = str_len(str1); ((j < str_len(str2)) && (i < newLength)); i++, j++)
		newString[i] = str2[j];

	newString[newLength] = '\0';	//	trim the length of newString

	return(newString);
}


bool equal(char * left, char * right)
//	Definition:	equal(...), returns true if the string on the left is the same as
//				the string on the right.
//
//	Inputs:		1.	The string on the left, left and
//				2.	the string on the right.
//
//	Outputs:	1.	True iff left = right, false otherwise.
{
	if(str_len(left) == str_len(right))
	{
		for (int i = 0; i < str_len(left); i++)
			if(left[i] != right[i])
				return (false);

		return (true);
	}
	else
		return(false);
}


bool bigger (char * left, char * right)
//	Definition:	bigger(...), returns true if the string on the left is lexically
//				bigger than the string on the right.
//	
//	Inputs:		1.	The string on the left, left and
//				2.	the string on the right, right.
//
//	Outputs:	1.	True iff left > right, false otherwise.
{
	int count,
		left_length = str_len(left),
		right_length = str_len(right);

	//	Use the shorter length of the two strings
	count = (left_length < right_length)? left_length : right_length;

	int i = 0;

	while(i < count)
	{
		if (left[i] > right[i])
			//	The left char > right char. So, left string > right string
			return(true);

		else if (left[i] == right[i])
			//	The left char == the right char. So, compare the next two characters
			i++;

		else
			//	The left char < right char.
			return(false);
	}

	//	Up to this point left == right. So, compare their lengths
	if (left_length > right_length)
		return(true);
	else
		return(false);
}


char * copy(char * cString, int from = -1, int UpTo = -1)
//	Definition:	copy(...) returns a copy of the given C string, from the position, from,
//				up to the position, UpTo.
//
//	Inputs:		1.	The input C string, cString.
//				2.	The starting position in the string, from. The default is -1.
//				2.	The ending position in the string, UpTo. The default is -1.
//	
//	Outputs:	1.	The copy of the C string within the given range.
{
	int length = str_len(cString);
	char * cStringCopy;

	if (from < 0)
		from = 0;

	if ((UpTo < 0) || (UpTo >= length))
		UpTo = length - 1;

	if (from <= UpTo)
	{
		int copy_length = UpTo - from + 1;

		cStringCopy = new char [copy_length];

		for(int i = 0; ((i < copy_length) && (from <= UpTo)); i++, from++)
			cStringCopy[i] = cString[from];

		cStringCopy[copy_length] = '\0';
	}
	else
	{
		cStringCopy = new char [1];
		cStringCopy[0] = '\0';
	}

	return cStringCopy;
}


char * cstring(char ch)
//	Definition: cstring(...), typecasts a char to a C string.
//
//	Inputs:		1.	The input character, ch, to typecast.
//	
//	Outputs:	1.	The output C string of length 1 having the value of ch.
{
	char * cString  = new char[2];

	cString[0] = ch;
	cString[1] = '\0';

	return(cString);
}


char * substr(char * cstring, int from, int length)
//	Definition:	substr(...) extracts a substring from the given C string,
//				cstring, that starts at position, from, in the string and
//				runs for a length of length.
//				
//	Inputs:	1.	The C string, cstring
//			2.	The starting position, from
//			3.	The length of the substring to be extracted, length.

//	Output:	1.	The extracted substring
{
	int i, j;

	int strLength = str_len(cstring);

	char * substring = new char[strLength+1];

	if (from < 0)
		from = 0;

	if ((length < 0) || (length >= strLength))
		length = strLength;

	//	Initialise the substring to null string
	for(i = 0; i < strLength+1; i++)
		substring[i] = '\0';

	//	Now, fill it with the extracted characters from the input string
	for(i = 0, j = from; ( (i < length) && (j < strLength)); i++, j++)
		substring[i] = cstring[j];

	return(substring);
}


bool substr(char * left, char * right, int & pos)
//	Definition: substr(...), returns true if the string on the left is a substring
//				of the string on the right, false otherwise. It sets pos to the index
//				of the string where the substring left starts in the string right.
//
//	Inputs:		1.	The string on the left, left and
//				2.	the string on the right, right
//
//	Outputs:	1.	True iff left is a substring of right, false otherwise.
//				2.	The position pos is set as follows:
//					0 <= pos < right string length if left is the substring of right
//					pos = -1 if left is not a substring of right
{
	int	left_length = str_len(left),
		right_length = str_len(right);

	char * SubStr;

	pos = -1;

	if (left_length <= right_length)
	{
		//	left might be a substring of right.
		//	Find the position, pos, where in the right the substring starts.

		pos = 0;

		while(pos < right_length)
		{
			SubStr = substr(right, pos, left_length);

			if (equal(upcase(SubStr), upcase(left)))
				return true;
			else
				pos++;
		}

		pos = -1;	//	left is not a substring of right
		return(false);
	}
	else
		return(false);
}


bool substr(char * left, char * right)
//	Definition: substr(...), returns true if the string on the left is a substring
//				of the string on the right, false otherwise.
//
//	Inputs:		1.	The string on the left, left and
//				2.	the string on the right, right
//
//	Outputs:	1.	True iff left is a substring of right, false otherwise.
{
	int	left_length = str_len(left),
		right_length = str_len(right),
		pos = 0;

	char * SubStr;

	if (left_length <= right_length)
	{
		while(pos < right_length)
		{
			SubStr = substr(right, pos, left_length);

			if (equal(upcase(SubStr), upcase(left)))
				return true;
			else
				pos++;
		}

		return(false);
	}
	else
		return(false);
}


int locate(char ch, char * cstring)
//	Definition:	locate(...), computes and returns the position of the
//				given character (1st occurrence), ch, in the given string, cstring.
//
//	Inputs:		1.	The character, ch,
//				2.	The C string, cstring
//
//	Outputs:	The position where ch is located in the given C string as follows:
//				1.	0 <= position < cstring length, if ch is located in cstring
//				2.	position = -1, if ch is not in cstring.
{
	int pos;
	for(pos = 0; pos < str_len(cstring); pos++)
		if (upcase(cstring[pos]) == upcase(ch))
			return pos;

	pos = -1;	//	pos = -1, ch not located
	return(pos);
}


int locate(char ch, char * cstring, bool & flag)
//	Definition:	locate(...), computes and returns the position of the
//				given character (1st occurrence), ch, in the given string, cstring..
//				It sets flag = true if ch is found in the string, false otherwise.
//
//	Inputs:		1.	The character, ch,
//				2.	The C string, cstring
//				3.	The boolean variable, flag.
//
//	Outputs:	The position where ch is located in the given C string as follows:
//				1.	0 <= position < cstring length, if ch is located in cstring AND
//					flag is set to true
//				2.	position = length of cstring, if ch is not in cstring AND
//					flag is set to false.
{
	flag = false;
	int pos;

	for(pos = 0; pos < str_len(cstring); pos++)
		if (upcase(cstring[pos]) == upcase(ch))
		{
			flag = true;
			return pos;
		}

	return(pos);
}


int locate(char * substring, char * cstring, bool & flag)
//	Definition:	locate(...), computes and returns the position of the
//				given substring (1st occurrence) in the given C string, cstring.
//				It sets flag = true if substring is found in the string, false otherwise.
//
//	Inputs:		1.	The substring, substring,
//				2.	The C string, cstring
//				3.	The boolean variable, flag.
//
//	Outputs:	The position where substring is located in the given C string as follows:
//				1.	0 <= position < cstring length, if substring is located in cstring AND
//					flag is set to true
//				2.	position = cstring length, if substring is not in cstring AND
//					flag is set to false.
{
	int pos = 0;
	flag = substr(substring, cstring, pos);
	return pos;
}


char * remove(char ch, char * string)
//	Definition:	remove(...), deletes the first occurrence of character, ch, from the string.
//
//	Inputs:		1.	The character to delete, ch.
//				2.	The input string
//
//	Outputs:	1.	The new string with ch removed.
{
	int		pos = 0,
			str_length = str_len(string);

	bool	found = false;

	char * remove_str = copy(string);	//	copy string to avoid destroying it

	while ((pos < str_length) && (!found))
	{
		if (upcase(remove_str[pos]) == upcase(ch))
			found = true;
		else
			pos++;
	}

	if (found)
	//	delete the character at position pos
	{
		for(pos = pos; pos < str_length - 1; pos++)
			remove_str[pos] = remove_str[pos+1];

		//	Now decrement the length of the string by 1
		str_length--;
		remove_str[str_length] = '\0';
	}

	return remove_str;
}


char * remove(char ch, int pos, char * string)
//	Definition:	remove(...), deletes the character, ch, at position, pos, from the string.
//
//	Inputs:		1.	The character to delete, ch.
//				2.	The position where the character may be residing in the string, pos
//				3.	The input string to delete the character from, string.
//
//	Outputs:	1.	The new string with ch removed.
{
	int str_length = str_len(string);

	char * remove_str = copy(string);

	if (pos < 0)
		pos = 0;
	else if (pos >= str_length)
		pos = str_length - 1;

	if (upcase(remove_str[pos]) == upcase(ch))
	//	delete the character at position pos
	{
		for(pos = pos; pos < str_length - 1; pos++)
			remove_str[pos] = remove_str[pos+1];

		str_length--;
		remove_str[str_length] = '\0';
	}

	return remove_str;
}


char * remove(char * string1, char * string2)
//	Definition:	remove(...), deletes the string, string1, from the string, string2.
//				It does nothing if string1 is not a substring of string2.
//
//	Inputs:	1.	The string to remove, string1.
//			2.	The string to remove string1 from, string2.
//
//	Output:	1.	The output string with string1 deleted.
{
	int pos = 0,
		str_length = str_len(string2);

	char * remove_str = copy(string2);

	if (substr(string1, string2, pos))
	{
		for(int i = 0; i < str_length; i++)
			remove_str = remove(string1[i], pos, remove_str);
	}

	return remove_str;
}


char * remove_all(char ch, char * string)
//	Definition:	remove_all(...), deletes all the occurrences of ch from string.
//
//	Inputs:		1.	The character to delete, ch.
//				2.	The input string, string.
//
//	Outputs:	1.	The new string with ch removed.
{
	int		pos = 0,
			str_length = str_len(string);

	char * remove_str = copy(string);

	while (pos < str_length)
	{
		if (upcase(remove_str[pos]) == upcase(ch))
		//	delete the character at position pos
		{
			for(int i = pos; i < str_length - 1; i++)
				remove_str[i] = remove_str[i+1];

			//	Now decrement the length of the string by 1
			str_length--;
			remove_str[str_length] = '\0';

			pos--;	//	decrement pos by 1 since all chars have shifted leftwards
		}

		str_length = str_len(remove_str);	//	compute the new string length
		pos++;							//	increment pos by 1 -- move forward
	}

	return remove_str;
}


char * remove_all(char * string1, char * string2)
//	Definition:	remove_all(...), deletes all occurrences of characters in string1 from string2.
//
//	Inputs:		1.	The list of characters to delete, string1.
//				2.	The input string to delete the string1 characters from, string2
//
//	Outputs:	1.	The new string with all the occurrences of characters in string1 removed.
{
	char * remove_str = copy(string2);

	for (int pos = 0; pos < str_len(string1); pos++)
		remove_str = remove_all(string1[pos], remove_str);

	return remove_str;
}


void getString(char * prompt, char string[], int length, char Case = '0', char delimiter = '\n')
//	Definition:	getString(...) is polymorphic. This getString function reads a string
//				from the keyboard which terminates in some delimiter character, the default
//				being a new line. The string can include white space. When Case = U
//				the input string is converted to upper case. If Case = L, it is
//				converted to lower case, otherwise the string is returned as is -- the default.
//				
//	Inputs:	1.	The message to display on the console, message.
//			2.	The string to read characters into from the keyboard, string[]
//			3.	The string length, length.
//			4.	The case indicator, Case -- default = none (i.e. '0')
//			5.	The delimiter character, delimiter -- default = new line
//
//	Output:	1.	The input string with appropriate case and length.
{
	//	Character constants
	char	null = char(0),
			back_space = char(8),
			ch;

	std::cout << prompt;
	Case = upcase(Case);

	int i;

	if (length <= 0)
		length = 0;

	//	Initialise the string to null string
	for(i = 0; i < length; i++)
		string[i] = null;

	//	Now read the string upto length-1
	i = -1;
	ch = getchar();
	do
	{
		if ((ch != back_space) && (ch != delimiter) && (i < length))
		{
			i++;

			if (Case == 'U')
				ch = upcase(ch);
			else if (Case == 'L')
				ch = lowcase(ch);

			string[i] = ch;
		}
		else if (ch == back_space)
		{
			//	delete the string backwards
			if (i >= 0)
				i--;
		}

		ch = getchar();
	}
	while ((ch != delimiter) && (i < length));

	if (i >= length)
		i = length - 1;
	else if (i <= 0)
		i = -1;

	string[i+1] = null;
}


char * getString(char * prompt = "", char Case = '0', char delimiter = '\n')
//	Definition:	getString(...) is polymorphic. This function is different from the other
//				one above since it extracts a string from the keyboard.
//				
//	Inputs:	1.	The message to display on the console, message -- default = blank
//			2.	The case indicator, Case -- default = none (i.e. '0')
//			3.	The delimiter character, delimiter -- default = new line
//
//	Output:	1.	The extracted string with appropriate case.
{
	char	null = char(0),
			back_space = char(8),
			ch;

	std::cout << prompt;

	Case = upcase(Case);

	int i = -1, OldStrLen = 1;
	char * OldStr = new char[OldStrLen];

	ch = getchar();
	do
	{
		if ((ch != back_space) && (ch != delimiter))
		{
			i++;
			
			if (Case == 'U')
				ch = upcase(ch);
			else if (Case == 'L')
				ch = lowcase(ch);

			OldStr[i] = ch;

			char * NewStr = new char[OldStrLen];
			int j;

			//	Copy OldStr to this NewStr to save it
			for(j = 0; j < OldStrLen; j++)
				NewStr[j] = OldStr[j];

			//	Now original string is saved, recreate and expand its storage
			OldStr = new char[OldStrLen + 1];

			//	Now copy back its original contents, saved in NewStr
			for(j = 0; j < OldStrLen; j++)
				OldStr[j] = NewStr[j];

			OldStrLen++;
		}
		else if (ch == back_space)
		{
			//	delete the string backwards
			if (i >= 0)
			{
				i--;
				OldStrLen--;
			}
		}

		ch = getchar();
	}
	while ((ch != delimiter));

	OldStr[OldStrLen-1] = null;
	return OldStr;
}


char * getString(char * prompt, char * inputChars, char Case = '0', char delimiter = '\n')
//	Definition:	getString(...) is polymorphic. This function is different from the one above in
//				that the input character set, inputChars, must be given.
//				
//	Inputs:	1.	The prompt message to be displayed
//			2.	The input character set, inputChars.
//			3.	The case indicator, Case -- default = none (i.e. '0')
//			4.	The delimiter character, delimiter -- default = new line
//
//	Output:	1.	The input string with appropriate case and character set.
{
	char	null = char(0),
			back_space = char(8),
			ch;

	std::cout << prompt;

	Case = upcase(Case);

	int i = -1, OldStrLen = 1;
	char * OldStr = new char[OldStrLen];

	ch = getchar();
	do
	{
		if ((ch != delimiter) && member(ch, inputChars))
		{
			i++;
			
			if (Case == 'U')
				ch = upcase(ch);
			else if (Case == 'L')
				ch = lowcase(ch);

			OldStr[i] = ch;

			char * NewStr = new char[OldStrLen];
			int j;

			//	Copy OldStr to this NewStr to save it
			for(j = 0; j < OldStrLen; j++)
				NewStr[j] = OldStr[j];

			//	Now original string is saved, recreate and expand its storage
			OldStr = new char[OldStrLen + 1];

			//	Now copy back its original contents, saved in NewStr
			for(j = 0; j < OldStrLen; j++)
				OldStr[j] = NewStr[j];

			OldStrLen++;
		}
		else if ((ch == back_space) && !member(ch, inputChars))
		{
			//	delete the string backwards
			if (i >= 0)
			{
				i--;
				OldStrLen--;
			}
		}

		ch = getchar();
	}
	while ((ch != delimiter));

	OldStr[OldStrLen-1] = null;
	return OldStr;
}


char * getString(char * prompt, int strLength, char * inputSet, 
				 char * comparison = "=", char Case = '0', char delimiter = '\n')
//	Definition:	getString(...) extracts a string from the keyboard of length, strLength
//				(the default) containing only the chracters from the inputSet. If the
//				value of the variable "comparison" is given then the extracted string length
//				will be according to the "comparison" in relation to the integer "strLength".
//				For example, if comparison = ">" and strLength = 5, then the string of length
//				bigger than 5 characters long will be extracted
//				
//	Inputs:	1.	The prompt message to be displayed
//			2.	The sentinel string length, strLength
//			3.	The input character set, inputSet.
//			4.	The comparison criterion, comparison -- default being "="
//			5.	The case indicator, Case -- default = none (i.e. '0')
//			6.	The delimiter character, delimiter -- default = new line
//
//	Output:	1.	The input string with appropriate, length, character set and case.
{
	bool CorrectLength;
	char * inputStr;

	do
	{
		inputStr = getString(prompt, inputSet, Case, delimiter);

		if (comparison == "<")
			CorrectLength = (str_len(inputStr) < strLength);
		else if (comparison == ">")
			CorrectLength = (str_len(inputStr) > strLength);
		else if (comparison == "<=")
			CorrectLength = (str_len(inputStr) <= strLength);
		else if (comparison == ">=")
			CorrectLength = (str_len(inputStr) >= strLength);
		else if (comparison == "=")
			CorrectLength = (str_len(inputStr) == strLength);
		else // comparison = "<>" or !=
			CorrectLength = (str_len(inputStr) != strLength);
	}
	while (!CorrectLength);
	return inputStr;
}


char * * str_tokens(char * string, int & no_of_tokens, char _case = '\0')
//	Definition:	str_tokens(...) breaks down the given C string into its individual
//				word/tokens and returns the tokens array (char * *) to the calling
//				environment. It also returns the number of words/tokens in the string
//				as no_of_tokens. The tokens will be converted to upper (_case = 'u') or
//				lower (_case = 'l') case.
//				
//	Inputs:	1.	The C string, string
//			2.	The number of tokens to be computed, no_of_tokens, passed by reference
//			3.	The case indicator, _case -- default = null (i.e. '\0')
//
//	Output:	1.	The input array of string tokens with appropriate case.
//			2.	The count on the number of tokens built, no_of_tokens, as side effect.
{
	int	tCount = -1,	//	token count -- the tcount-th token/word so far
		sCount = 0;	//	count on the next character in the string

	no_of_tokens = 0;	//	no tokens so far

	char	tab = '\t',
			space = char(32),
			null = '\0';

	char * * TokenStr,	//	The array of tokens (i.e. array of strings char * *)
		 * * NewTokenStr,	//	another array of tokens (i.e. a copy of TokenStr + a new token)
		   * Token;

	TokenStr = new char * [1];

	while(sCount < str_len(string))	//	while not end of line
	{
		if ((string[sCount] != tab) && (string[sCount] != space) &&
		   (string[sCount] != null))
		{
			//	if the character is not one of the specified delimeters: space, tab, etc, then
			//	it is part of a word/token -- so, accumulate the token string
			tCount++;	//	next token
			no_of_tokens++;
			Token = "";	//	initialise the token to an empty string, initially

			while ((string[sCount] != tab) && (string[sCount] != space) &&
				  (string[sCount] != null))
			{
				Token = add(Token, cstring(string[sCount]));	//	accumulate the token characters
				sCount++;	//	next char in the string
			}
		}
		
		//	convert the token to the appropriate case
		if (upcase(_case) == 'U')
			Token = upcase(Token);
		else if (upcase(_case) == 'L')
			Token = lowcase(Token);
		
		//	Now build the tokens array

		if (no_of_tokens < 2)
			//	only one token so far -- just add it to the token array
			TokenStr[tCount] = Token;
		else
		{
			//	create an additional space to contain the new token, just built
			NewTokenStr = new char * [no_of_tokens + 1];

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


bool is_sign(char ch)
{
	return ((ch == '+') || (ch == '-'));
}


bool is_digit(char ch)
//	Definition:	is_digit (...) checks if the input character, ch, represents 
//				a digit value or not. A character representing a digit is any of
//				'0','1','2', ..., '9'.
//
//	Input:		The input character, ch
//
//	Output:		True if the character represents a digit, false otherwise
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


bool is_digit(char * str, int from = -1, int upTo = -1)
//	Definition:	is_digit (...),returns true if str represents an integer,
//				from the index, from, up to the index, upTo.
//				It returns false otherwise.
//
//	Input:		1.	The input C string, str
//				2.	The first index to start from, from -- default = -1.
//				3,	The last index to stop at, upTo -- default = -1
//
//	Output:		True if str represents an integer in the given range, false otherwise
{
	if ((upTo < 0) || (upTo > str_len(str)))
		upTo = str_len(str) - 1;

	if (from < 0)
		from = 0;

	if (from > upTo)
		return false;
	else
	{
		for (int i = from; i <= upTo; i++)
			if (!is_digit(str[i]))
				return false;

		return true;
	}
}


bool is_alpha(char ch)
//	Definition:	is_alpha (...) checks if the input character, ch, represents 
//				a letter of alphabet or not. A character representing a letter
//				of alphabet is one of 'a','b','c', ..., 'z' and '_'.
//
//	Input:		The input character, ch
//
//	Output:		True if the character represents a letter of alphabet, false otherwise
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


bool is_alpha(char * str, int from = -1, int upTo = -1)
//	Definition:	is_alpha (...),returns true if str represents a name string,
//				from the index, from, up to the index, upTo.
//				It returns false otherwise.
//
//	Input:		1.	The input C string, str
//				2.	The first index to start from, from -- default = -1.
//				3,	The last index to stop at, upTo -- default = -1
//
//	Output:		True if str represents a name in the given range, false otherwise
{
	if ((upTo < 0) || (upTo > str_len(str)))
		upTo = str_len(str) - 1;

	if (from < 0)
		from = 0;

	if (from > upTo)
		return false;
	else
	{
		for (int i = from; i <= upTo; i++)
			if (!is_alpha(str[i]))
				return false;

		return true;
	}
}


bool is_alpha_numeric(char ch)
//	Definition:	is_alpha_numeric (...) checks if the input character, ch, represents 
//				a letter of alphabet or a digit not.
//
//	Input:		The input character, ch
//
//	Output:		True if the character is alpha-numeric, false otherwise
{
	return (is_alpha(ch) || is_digit(ch));
}


bool is_alpha_numeric(char * str, int from = -1, int upTo = -1)
//	Definition:	is_alpha_numeric(...),returns true if str is alpha-numeric,
//				from the index, from, up to the index, upTo.
//				It returns false otherwise.
//
//	Input:		1.	The input C string, str
//				2.	The first index to start from, from -- default = -1.
//				3,	The last index to stop at, upTo -- default = -1
//
//	Output:		True if str is alpha-numric in the given range, false otherwise
{
	if ((upTo < 0) || (upTo > str_len(str)))
		upTo = str_len(str) - 1;

	if (from < 0)
		from = 0;

	if (from > upTo)
		return false;
	else
	{
		for (int i = from; i <= upTo; i++)
			if (!is_alpha_numeric(str[i]))
				return false;

		return true;
	}
}


int ch_to_digit(char ch)
//	Definition:	ch_to_digit (...) converts the input character, ch, to the digit
//				number it represents. The digit will be any of 0,1,2, ..., 9. If
//				the character is not a digit, the function returns a zero.
//
//	Input:		The input character, ch
//
//	Output:		The digit number the character represents, otherwise zero.
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


char digit_to_ch(long int digit)
//	Definition:	digit_to_ch (...) converts the input digit, digit, to the character
//				the digit represents.
//
//	Input:		The input digit, digit
//
//	Output:		The character the digit represents
{
	switch(digit)
	{
		case 1 : return('1');
		case 2 : return('2');
		case 3 : return('3');
		case 4 : return('4');
		case 5 : return('5');
		case 6 : return('6');
		case 7 : return('7');
		case 8 : return('8');
		case 9 : return('9');
		default : return('0');
	}
}


char * reverse(char * str)
//	Definition:	reverse(str), reverses the input string, str. It does so by
//				using two counters i and j. i counts upwards from 0 and j counts
//				downwards from str length - 1. At every instance we swap str[i]
//				with str[j] until j == i, at which stage the string is completely
//				reversed.
//
//	Input:		The input string, str
//
//	Output:		The string reversed
{
	char * reverse_str = copy(str);

	for(int i = 0, j = str_len(str) - 1;((i < str_len(str)) && (i < j));(i++, j--))
	{
		// Swap str[i] with str[j]
		char ch = reverse_str[i];
		reverse_str[i] = reverse_str[j];
		reverse_str[j] = ch;
	}
	return(reverse_str);
}

char * resize(char * str, int newLength)
//	Definition:	resize(str, newLength), resizes the input string to a new length, newLength
//			
//
//	Input:		1.	The input string, str
//				2.	The new length, newLength
//
//	Output:		The string with the new length
{
	int i, OldLength = str_len(str);
	
	if (newLength < 0)
		newLength = -1 * newLength;
	
	if (OldLength < newLength)
		OldLength = newLength;
	
	//	Allocate memory for new str
	char * NewStr = new char[newLength];

	//	Now copy the old str into the new str with new length
	for(i = 0; i < OldLength; i++)
	{
		NewStr[i] = str[i];
	}
	NewStr[newLength] = '\0';
	return(NewStr);
}


long str_to_int(char * str)
//	Definition:	str_to_int (...) converts the input stream, str, to its integer
//				equivalent. It converts the input up to the first non-digit character.
//
//	Input:		The input stream, str
//
//	Output:		The integer number the stream represents
{
	//	integer = (+|-)? digits
	//	digits = digit (digit)*
	//	digit = [0-9]
	
	long integer = 0, i = 0, sign = 1;

	if (is_sign(str[0]))
	{
		if (str[0] == '-')
			sign = -1;
		i++;	//	skip the sign character, having noted it.
	}

	for(; ((i < str_len(str)) && is_digit(str[i])); i++)
	{
		integer = integer * 10 + ch_to_digit(str[i]);
	}

	return(sign * integer);	//	return the number with appropriate sign
}


long double exp(long double y, long n)
//	Definition: exp(y, n) = y to power n
//
//	Inputs:		1.	The real number y, i.e the base
//				2.	The integer exponent n
//
//	Outputs:	a real number, y to power n 
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


long double str_to_num(char * str)
//	Definition:	str_to_num (...) converts the input string, str, to the number the
//				string represents. It converts the input up to the first non-digit character.
//				For example, the input 
//				"123.123" will be converted to 123.123.
//				"123." will be converted to 123
//
//	Input:		The input string, str
//
//	Output:		The number the string represents

{
	//	Number = digits (. digits)? ( e (+|-)? digits)?
	//	digits = digit (digit)*
	//	digit = [0-9]
	int i = 0,
		NumSign = 1;	// Assume the number is positive
		
	long double dec_frac = 0,	//	The extracted mantissa part
				NumValue = 0;	//	The value of the extracted number
				
	if (is_sign(str[i]))
	{
		if (str[i] == '-')
			NumSign = -1;	// The number is negative
		i++;
	}
	
	while ((i < str_len(str)) && is_digit(str[i]))
	{
		NumValue = NumValue * 10 + ch_to_digit(str[i]);	//	build the integer part of the number
		i++;
	}
	
	if ((i < str_len(str)) && (str[i] == '.'))	// possible decimal coming
	{
		//	Number = digits . digits
		i++;
		
		int j = 1;	//	j is the power index in exp(10, j)
		
		while ((i < str_len(str)) && is_digit(str[i]))
		{		
			dec_frac = dec_frac + ch_to_digit(str[i])/exp(10, j);
			j++;
			i++;
		}
	}
	
	NumValue = NumValue + dec_frac;	//	add the integer part and the decimal fraction
	
	if ((i < str_len(str)) && ((str[i] == 'e')|| (str[i] == 'E')))	// possible mantissa - e [+|-] digits
	{
		//	Number = digits . digits e (+|-)? digits
		i++;
		
		char MantissaSign = '+';	// Assume the mantissa is positive
		
		dec_frac = 0;	//	dec_frac will hold the integer value of the mantissa
		
		if ((i < str_len(str)) && is_sign(str[i]))	// signed mantissa
		{
			//	Number = digits . digits e (+|-) digits	
			MantissaSign = str[i];
			i++;
		}
		
		while ((i < str_len(str)) && is_digit(str[i]))
		{
			//	Number = digits . digits e (+|-) digits
			dec_frac = dec_frac * 10 + ch_to_digit(str[i]);	//	build the exponent of the mantissa
			i++;
		}
			
		if (MantissaSign == '-')
			NumValue = NumValue * exp(10, -1 * dec_frac);
		else
			NumValue = NumValue * exp(10, dec_frac);
	}
	
	return NumSign * NumValue;
}


char * int_to_str(long int_num)
//	Definition:	int_to_str(...), converts the given integer, int_num,
//				to a string that represents that integer. For example,
//				123 will be converted to "123".
//
//	Input:		The input integer number, int_num
//
//	Output:		The string representation of the given integer.
{
	char * string = new char[256];
	int i;
	char sign = '\0';

	//	Initialise the string to null string
	for(i = 0; i < 256; i++)
		string[i] = '\0';

	//	Reset the index
	i = 0;

	if (int_num < 0)
	{
		sign = '-';
		int_num = (-1) * int_num;	//	 make the number positive for iteration
	}

	if (int_num == 0)
		string[i] = digit_to_ch(0);
	else
	{
		
		while(int_num > 0)
		{
			long digit = int_num % 10;// get the next most significant digit
			int_num = int_num / 10;	// get the next integer part
			string[i] = digit_to_ch(digit);
			i++;
		}
	}
	
	// The number has been converted starting from the least significant digit
	// Thus, it has been reversed. So, reverse the output to the original sequence
	return(add(cstring(sign),reverse(string)));
}


char * dec_to_str(long double dec_num, long dec_places = 10)
//	Definition:	dec_to_str(...), converts the given decimal fraction, dec_num,
//				to a string that represents that decimal fraction, correct to
//				the given number of decimal places, dec_places. If the number is
//				not a proper fraction, the function extracts the fractal part and
//				converts to string.
//
//	Input:		1.	The input decimal fraction, dec_num
//				2.	The decimal number accuracy, dec_places (Default is 10)
//
//	Output:		The string representation of the given decimal fraction to the
//				given accuracy of decimal places.
{
	char * string = new char[256];
	int str_length;

	for(str_length = 0; str_length < 256; str_length++)
		string[str_length] = '\0';

	long digit, int_part;
	char sign = '\0';

	if (dec_num < 0)
	{
		sign = '-';
		dec_num = (-1) * dec_num;
	}
	
	//	make the number a proper decimal (if it was not originally)
	int_part = dec_num;
	dec_num = dec_num - int_part;

	string[0] = '.';	//	a fraction starts with the character: "."
	str_length = 1;	//	start the str at pos 1

	do
	{
		digit = dec_num * 10;// get the next digit
		dec_num = (dec_num * 10) - digit;
		string[str_length] = digit_to_ch(digit);
		str_length++;
	}
	while((dec_num > 0) && (str_length < dec_places));

	return(add(cstring(sign),string));	//	append the sign to the fraction
}


char * num_to_str(long double num, int dec_places = 10)
//	Definition:	num_to_str(...), converts the given number, num, to the string
//				that represents that number, correct to the given number of 
//				decimal places, dec_places (Default is 10 -- max digits for long int).
//
//	Input:		1.	The input number, num
//				2.	The number of decimal places required, dec_places
//
//	Output:		The string representation of the given number.
{
	char sign = '\0';

	if (num < 0)
	{
		sign = '-';
		num = (-1) * num;
	}

	long int_part = num;
	long double dec_part = num - int_part;
	
	char	*	int_part_str = int_to_str(int_part),
			*	dec_part_str = dec_to_str(dec_part, dec_places);

	return(add(cstring(sign), add(int_part_str, dec_part_str)));
}


long reverse(long num)
//	Definition:	reverse(num), reverses a long integer
//
//	Input:		The long integer number, num
//
//	Output:		The integer number reversed
{
	int sign = 1;

	if (num < 0)
	{
		sign = -1;
		num = (-1) * num;	//	make the number positive
	}

	char * numStr = reverse(int_to_str(num));
	return(sign * str_to_int(numStr));
}


long frac_to_int(long double dec_frac, long sig_digits = 10)
//	Definition:	frac_to_int(...), converts the fractal part of the given decimal, dec_frac,
//				to an integer of length, sig_digits (Default is 10 -- max digits for long int).
//				If the given number is not a proper fraction, the function extracts the
//				fractal part and convert to an integer.
//
//	Input:		1.	The decimal number, dec_frac
//				2.	The number of significant digits to keep, sig_digits
//
//	Output:		The integer number of appropriate value.
{
	int sign = 1;

	if (dec_frac < 0)
	{
		sign = -1;
		dec_frac = (-1) * dec_frac;
	}

	long int_num = dec_frac;

	dec_frac = dec_frac - int_num;	//	make sure that dec_frac is a fraction

	//	This is now a proper fraction -- process it
	int_num = 0;

	for(int i = 1; i < sig_digits; i++)
	{
		dec_frac = dec_frac * 10;	//	First decimal place is made the most significant digit
		int_num = int_num * 10 + dec_frac;
		dec_frac = dec_frac - long(dec_frac);	//	Get a new fraction to process
	}

	return sign * int_num;
}


long double reverse(long double num, long sig_digits = 10)
//	Definition:	reverse(num), reverses the given floating point number, num, with so many
//				given significant digits after the decimal, sig_digits, for the original number
//
//	Input:		The number, num
//
//	Output:		The number reversed
{
	int sign = 1;

	if (num < 0)
	{
		sign = -1;
		num = (-1) * num;
	}

	long	dec_part = frac_to_int(num, sig_digits),
			int_part = num;

	char	*	intStr = reverse(int_to_str(int_part)),
			*	decStr = reverse(int_to_str(dec_part));

	if (dec_part > 0)	//	this is a real number with a decimal part
		return(sign * str_to_num(add(add(decStr,"."),intStr)));
	else
		return(sign * str_to_int(intStr));	//	just an integer
}

#endif // End the Definition of _STRING_FUNCTIONS_

/*
int main()
{
	char * str = new char[10]; 
	std::cin >> str;
	std::cout << "The entered string =   " << str << "\n";
	char ch = char (0); int i = 0;
	std::cout << "Enter string   ";
	while (ch != '\n')
	{
		ch = getchar();
		if (ch != '\n')
		{
			str[i] = ch;
			i++;
			str = resize(str, i);
		}
	}//
	//str = resize(str, 5);
	std::cout << "The trimmed string =   " << str << "\n";

	return 1;
}
*/

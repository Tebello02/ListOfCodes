/*
	NAME: Class{anExpression}.cpp
	
	FUNCTION:
       The file contains a class called "anExpression" which is designed to
       evaluate arithmetic expressions, whose operands are numbers and the operators 
	   are the binary operators: +,-, *, / and ^. The result will, again, be a real number.
	   Scientific number representation is also supoorted. For example, one can write:
	   
	   1234.1e-2
	   
	   to mean the number
	   
	   12.341
       
       The format of the input string is as follows:
	   
	   Numbers and operators are separated by whitespace. Whitespace is: a space, a tab or a newline.
	   This means that, for example, to add 2 and 3, we write:
	   
	   2 + 3
	   
	   not
	   
	   2+3
	   
	   The amount of whitespace between operands and operators can be as much as the user wants.
	   
	   The expression is entered as a string from the keyboard. For this, the class
       uses the services of the class, "Class{aString}.cpp"

       The expression class uses the class "aStack" contained in the file  
       "Class{aStack}.cpp" to
	   
	   (1) convert the entered "infix" arithmetic expression to "postfix" expression equivalent
	   (2) evaluate the postfix expression to get the result (for the original infix expression).                
                                                                           
	AUTHOR: (c) mofana mphaka; April 2020                                  
*/

#include <iostream>
#include <c:\users\mofana\documents\cs2432{oop}\programs\class{aStack}.cpp>
#include <c:\users\mofana\documents\cs2432{oop}\programs\class{aString}.cpp>

#if ! defined	_an_EXPRESSION_CLASS_
#define 		_an_EXPRESSION_CLASS_

class anExpression
{
	public:
		/*	T h e   C o n s t r u c t o r   a n d   D e s t r u c t o r   f o r   a n E x p r e s s i o n	*/
		
		anExpression(char * anExpr = "");
		/*	The constructor -- polymorphic.
			It instantiates an expression as the given C string, anExpr. The default is an empty string.
		*/
		
		~anExpression () {};
		/*	The destructor. It's empty. The expression will be destroyed by the C++ scoping rules */


		/*	T h e   I n p u t  &  O u t p u t   F u n c t i o n s   f o r   a n E x p r e s s i o n	*/
		
		void input();
		/* It allows the user to enter the value of the expression from the keyboard, as follows:
		
			(1)	Prompt the user: Enter an (infix) Expression:
			(2) Wait for the user to enter an expression, as aString.
		*/
		
		void display();
		/*	It displays the expression on the screen, followed by a new line as:
		
			The Entered Expression is << EXPRESSION >>
		*/

		/*	T h e   g e t   a n d   s e t  f u n c t i o n s   f o r   a n E x p r e s s i o n */		
		
		aString get_expr();
		/*	It avails the expression as aString to any calling environment	*/
		
		char * get_expr_value();
		/*	It typecasts the expression to a C string, char *	*/
		
		void	set_expr(aString expr);
		/*	It sets the expression as the given aString expr	*/
		
		void	set_expr(char * expr);
		/*	It sets the expression as the given C string, expr	*/
		
		
		/*	T h e   A r i t h m e t i c   F u n c t i o n s   o n  T h e   E x p r e s s i o n	*/
		
		aString infix_to_postfix(aString infix_expr);
		/*	It converts the given infix expression, infix_expr, to its postfix expression equivalent,
			using the stack (algorithm).
			
			For example, for the infix expression 2 * 3 + 4, the function returns: 2 3 * 4 +
		*/
		
		double evaluate(aString postfix_expr, bool & valid_expr);
		/*	It evaluates the postfix expression, postfix_expr, (produced by the "infix_to_postfix" function (above)),
			using the stack (algorithm). 
			
			It sets valid_expr to "true" if postfix_expr is a correct arithmetic expression. It sets it "false" otherwise.
			
			For example, for the postfix epression: 2 3 * 4 +, the returned result is 10 (and valid_expr = true).
		*/

	private:
		aString	expression;
		/*	The data value of the entered expression	*/
		
		double	ch_to_digit(char ch);
		/*	It converts the given character, ch, to its number equavalent.
		
			For example, when ch = '9', the returned value will be 9.
		*/
		
		bool	opr (char ch);
		/*	It returns true if "ch" is an operator. Operators are any of the characters: +, -, *, /, ^
			and "brackets": (, )
		*/
		
		double	apply (char opr, double operand1, double operand2);
		/*	It returns the value of the application of the operator, opr, on the two arguments,
			operand1 and operand2.
			
			For example, apply(^, 2, 3) = 8. (i.e 2 ^ 3 = 8)
		*/
		
		double	exp(double x, long int y);
		/*	It returns x to the power y, i.e. x ^ y.
		
			For example, exp(2, 3) = 8 and exp(2, -3) = 0.125
		*/
		
		bool	has_precedence(char oprX, /* over */ char oprY);
		/*	It returns true if the operator X, oprX, has precedence over operator Y, oprY. It
			returns false otherwise.
			
			For example, has_precedence('*', '^') = false, but has_precedence('*', '/') = true
		*/
};


anExpression :: anExpression(char * anExpr)
{
	expression = anExpr;	//	Uses the overloaded "=" operator for class aString
}


aString anExpression :: get_expr()
{
	return expression;
}


char * anExpression :: get_expr_value()
{
	return expression.value();
}


void	anExpression :: set_expr(aString expr)
{
	expression = expr;	//	Uses the overloaded "=" operator for class aString
}


void	anExpression :: set_expr(char * expr)
{
	expression = expr;	
	//	Uses the overloaded "=" operator for class aString to typecasts a C string, expr, to aString, expression
}


void anExpression :: input()
{
	std::cout << "Enter an (Infix) Expression: "; 
	std::cin >> expression;	//	Uses the overloaded ">>" operator for class aString
}


void anExpression :: display()
{
	std::cout << "\nThe Entered Expression is << " << expression << " >>\n";
	//	Uses the overloaded "<<" operator for class aString, in std::cout << expression
}


double anExpression :: exp(double y, long int n)
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


double anExpression :: ch_to_digit(char ch)
// Convert ch to its integer equivalent if ch is in: '1'...'9'
// otherwise return a zero.
{
	switch(ch)
	{
		case '1': return (1);
		case '2': return (2);
		case '3': return (3);
		case '4': return (4);
		case '5': return (5);
		case '6': return (6);
		case '7': return (7);
		case '8': return (8);
		case '9': return (9);
		default : return (0);
	}
}


bool anExpression :: opr(char ch)
// Return true if ch is one of the operators
// false otherwise
{
	switch(ch)
	{
		case '+': return (true);
		case '-': return (true);
		case '*': return (true);
		case '/': return (true);
		case '^': return (true);
		case '(': return (true); // left and
		case ')': return (true); // right brackets are special operators
		default : return (false);
	}
}



double anExpression :: apply(char opr, double operand1, double operand2)
// Return the value when applying the binary operator, opr, to
// its binary operands: operand1 and operand2
{
	switch(opr)
	{
		case '+': return (operand1 + operand2);
		case '-': return (operand1 - operand2);
		case '*': return (operand1 * operand2);
		case '/': return (operand1 / operand2);
		case '^': return (exp(operand1, operand2));
		default : return (0);
	}
}


bool   anExpression :: has_precedence(char oprX, /* over */ char oprY)
// returns TRUE if oprX has precedence over oprY, FALSE otherwise
{
	switch(oprX)
	{
		// Addition/Subtraction Precedence Rules
		case '-':
		case '+': switch(oprY)
				  {
						case '-':
						case '+': // Addition/subtraction is left associative
						case ')': // has_precedence(oprX,')') for any oprX other than '('
								  return (true);
						default: // operator is either '/', '*', '^' or '('
								  return (false);
				  }
		
		// Multiplication/Division Precedence Rules
		case '/':
		case '*': switch(oprY)
				  {
					  	case '-':
						case '+': // Multiplication/Division has precedence over '+', '-'
						case '/':
						case '*': // Multiplication/Division is left associative
						case ')': // has_precedence(oprX,')') for any oprX other than '('
								  return (true);
						default: // operator is either '^' or '('
								 return (false);
				  }
		
		// Exponentiation Precedence Rules
		case '^': switch(oprY)
				  {
					  	case '-':
						case '+': 
						case '/':
						case '*': // Exponentiation has precedence over '+', '-','/', '*'
						case ')': // has_precedence(oprX,')') for any oprX other than '('
								  return (true);
						default: // oprY = '(' or '^' -- Exponentiation is not left associative
								 return (false);
				  }
			
		// Brackets Precedence Rules
			
		/* has_precedence('(', oprX) = false, for any operator oprX */
		
		case '(': switch(oprY)
				  {
					  	case '-':
						case '+': 
						case '/':
						case '*': 
						case '^': // '('has NO precedence over any operator: +, *, etc
								  return (false);//
						default:  return (true); // oprY = ')' or '('
				  }

		/*
			has_precedence(')', '(') = undefined -- it never happens in a correct expression
			has_precedence(oprX, ')') = true, for any operator oprX other than '('
			i.e
			has_precedence(')', ')') = true
			has_precedence('(', ')') = false
		*/
		
		default: // oprX = ')' 
				 if(oprY != ')') // operator is any operator other than ')'
					return (false);
				 else
					return (true); // ')' has precedence over ')'
	}
}


aString anExpression :: infix_to_postfix(aString infix_expr)
//	Convert the given infix expression, infix_expr, to its postfix (Reverse Polish Notation)
//	expression, using the stack algorthm.
{
	aStack<char> stack; // initialiase the operator stack -- contains characters

	aString postfix_expr = "", // initialise the postfix string to an empty string
		   add_str = "",      // add_str is a temporary variable used to grow postfix_expr
		   symbol;			//	symbol is the ith token of the infix_expr

	int i = 0,   		// count on the ith token of the infix expression string
		no_of_tokens;	//	the total number of tokens of the infix expression string
		
	bool	OK,			//	flag on success or failure of stack operations -- push/pop
			brackets = false; // flag for closing bracket(s)

	aString * str_token = infix_expr.tokens(no_of_tokens);	//	tokenise the infix_expr
	
	while (i < no_of_tokens) // while not end of input stream
	{
		symbol = str_token[i]; //	Get the next token -- symbol
		
		if (!(opr(symbol[0])))
			// symbol is an operand -- append it to the postfix string
			postfix_expr = postfix_expr + symbol + " ";	//	tokenise the postfix expr
		
		else
		// symbol is an operator -- a number of things need to be done
		{
			while ((!stack.empty()) && (has_precedence(stack._top(OK), /* over */ symbol[0]))
				   && !brackets)
			{
				/* 
				   The operator at the top of stack has precedence over the current operator
				   symbol. Therefore, add it to the postfix string -- provided it is not "(" or ")"
				*/
				add_str = add_str + stack.pop(OK);
				if ((add_str != "(") && (add_str != ")"))
					postfix_expr = postfix_expr + add_str + " ";
				else
					// discard brackets and move to the next input symbol
					brackets = true;

				add_str = ""; // revert back to the empty string
			}

			/*
			   Now, either the stack is empty or the current operator (symbol) has 
			   precedence over the one at the top of stack. Therefore, we must store it
			   and compare it with the next operator (symbol) which might be of higher
			   precedence. We, however, remove any ")"
			*/

			if ((stack.empty()) || (symbol[0] != ')'))
				// only the left bracket '(' is stored, as a marker, not the right bracket
				// all other operators are stored
				stack.push(symbol[0], OK);
		}
		i = i + 1;
		brackets = false; // any brackets before would have been dealt with
	} // while not end of input stream

	/*
	  At this point we have reached the end of the input stream. We must output all the
	  remaining operators from the operator stack onto the postfix string
	*/

	while (!stack.empty())
	{
		add_str = add_str + stack.pop(OK);

		if ((add_str != "(") && (add_str != ")"))
			postfix_expr = postfix_expr + add_str + " ";
		
		add_str = ""; // revert back to the empty string
	}

	return (postfix_expr);
}


double anExpression :: evaluate(aString expr, bool & valid_expr)
// Evaluate the postfix arithmetic expression, expr, using the stack algorithm
{
	int i = 0, 			//	count on the ith token of postfix expression, expr
		no_of_tokens;	//	the total number of tokens in expr
		
	bool OK;	//	flag on sucess or failure of stack operations -- push & pop

	double	result,
			operand1,
			operand2;

	aStack<double> stack; // initialise the stack to hold real values

	aString symbol;		//	the ith token of the expression, expr
	
	aString * str_token = expr.tokens(no_of_tokens);	//	tokenise the postfix expression, expr
	
	while (i < no_of_tokens) // while not end of input stream
	{
		symbol = str_token[i];	//	Get the ith token, symbol

		if (opr(symbol[0]))  // if the symbol is an operator, apply it and store the result, on the stack
		{
			operand2 = stack.pop(OK); 
			operand1 = stack.pop(OK);
			result = apply(symbol[0], operand1, operand2);
			stack.push(result, OK);
		}
		else // else if the symbol is an operand, get its value and store it, again on the stack
		{
			result = symbol.real_num();	//	Convert the symbol string into a real number
			stack.push(result, OK);
		}
		i = i + 1;
	}
	// here we are at the end of the input stream
	// the result of the postfix expression resides at the top of the stack
	result = stack.pop(OK);

	if (stack.empty())
	{
		valid_expr = true;	//	This is a correct arithmetic expression
		return result;		//	with a value
	}
	else
	{
		valid_expr = false;		//	Incorrect arithmetic expression
		return 0;
	}
}


/*	O v e r l o a d i n g   t h e   i n s e r t i o n, >>,  a n d 
	e x t r a c t i o n, <<,  o p e r a t o r s   f o r   a n E x p r e s s i o n
*/

std::istream & operator >> (std::istream & input, anExpression & expr)
{
	aString str;
	
	input >> str;	//	Use the overloaded ">>" operator for aString
	expr.set_expr(str);
	
	return input;
}


std::ostream & operator << (std::ostream & output, anExpression expr)
{
	output << expr.get_expr();	//	Use the overloaded "<<" operator for aString
	
	return output;
}
#endif

// A main program testing class anExpression
int main()
{
	char ans = 'Y';
	bool valid_expr;
	double result;

	anExpression	expression; // Instantiate an expression object -- expression
	
	aString			postfix_expression;

	while ((ans == 'y') || (ans =='Y'))
	{
		std::cout << "\nEnter an Infix Expression => "; std::cin >> expression;
		std::cout << "\n\nThe Entered Infix Expression = "; std::cout << expression << "\n";
		
		postfix_expression = expression.infix_to_postfix(expression.get_expr());
		
		std::cout << "\n\nIt's Postfix Equivalent = " << postfix_expression << "\n";
		
		result = expression.evaluate(postfix_expression, valid_expr);
		
		if (valid_expr)
			std::cout << "\n\nIt's Result = " << result;
		else
			std::cout << "\n\nThe Entered Expression ==> " << expression << " <==, is not a valid expression\n";
		
		std::cout << "\n\nAny more Expressions to try ?[Y/N]";
		std::cin >> ans;
	}

	return (1);
}

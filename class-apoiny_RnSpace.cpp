#include <iostream>
using namespace std;


#if !defined _A_POINT_
#define _A_POINT_

class aPoint {
	
	private:
		long double *point;
		long int dimension;
		
		
	public:
		aPoint(long int _dimension = 1);
		
		~aPoint(){ }
		
		//MEMBER FUNCTIONS
		
	void set_Coord(long int i = 0,long double value = 0);
	void set_all_coord(long double *value,long int _dimension);
	
	void input();
	
	long double get_Coord(long int i = 0);
	long double *get_all_coord();
	long int get_length();
	long int get_size();
	long int get_dimension();
	
	long double distance(); //from the origin
	
	void display();
	// OVERLOADED AS MEMBER FUNCTIONS
	aPoint operator = (aPoint right);		//	Assigns the point on the right to this point -- *this = right
	bool operator == (aPoint right);		//	compare this point with the point on the right -- *this == right?
	bool operator != (aPoint right);

	aPoint operator + (aPoint right);		//	Vector addition: add *this point to the point on the right -- *this + right
	aPoint operator - (aPoint right);		//	subtract the point on the right from *this point -- *this - right
	long double operator * (aPoint right);		//	Dot multiplication: *this * right
	aPoint operator * (long double right);			//	Scalar multiplication: *this * right
				
	
	// F r i e n d   F u n c t i o n s  (i.e. N o n - M e m b e r   F u n c t i o n s)
	
	friend long double distance(aPoint left, aPoint right);	//	Euclidean distance between the two points: left & right
		
	//	OVERLOADED AS FRIEND FUNCTIONS
	
	friend aPoint operator * (long double left, aPoint right);	//	Scalar multiplication: left * right
	
	
	//	The insertion operator, >>, overloaded for input. USAGE: std::cin >> point
	friend std::istream & operator >> (std::istream & input, aPoint &right);
	
	//	The extraction operator, <<, overloaded for output. USAGE: std::cout << point
	friend std::ostream & operator << (std::ostream & output, aPoint right);	
};


aPoint :: aPoint(long int _dimension)
{
	if (_dimension < 1)
		_dimension = 1;	//	the least dimension is the real line -- 1D space
		
	dimension = _dimension;
	
	try
	{
		point = new long double[dimension];		//	the "new" operator might throw an exception, if no more memory available
		
		for(_dimension = 0; _dimension < dimension; _dimension++)
			point[_dimension] = 0;		//	the point is initially 0, (0, 0), (0, 0, 0), etc
	}
	catch(...)	//	catch any possible exceptions from the "try" block above
	{
		std::cout << "Memory Overflow -- Cannot Create the Points Array!";
		exit(0);	//	terminate the "main" function that called this class
	}
}

void aPoint :: set_Coord(long int i, long double value) 
{
	
	for(int i= 0;i<dimension;i++){
		
	}	

}

void aPoint :: set_all_Coord(long double * value, long int _dimension)
{
	if (_dimension > dimension)
		_dimension = dimension;	//	Clip the given value to the actual point's dimension
		
	if (_dimension < 1)
		_dimension = 1;
		
	while(_dimension > 0)
	{
		point[_dimension-1] = value[_dimension-1];	//	Set each corresponding coordinate with the corresponding value
		_dimension--;
	}
		
}

long double aPoint :: get_Coord(long int i)
{
	
	
}


long double * aPoint :: get_all_Coord() 
{
	long double * Coord = new long double[dimension];	//	The coordinates will be collected in Coord
	
	for(long int i = 0; i < dimension; i++)		//	copy each coordinate, point[i] into the
		Coord[i] = point[i];					//	corresponding Coord[i]
		
	return Coord;
}

//REDUNDANCY 
long int aPoint :: get_length()
{
	return dimension;
}


long int aPoint :: get_size()
{
	return dimension;
}


long int aPoint :: get_dimension()
{
	return dimension;
}


long double aPoint :: distance()
{
	
	
}


void aPoint :: input()
{
	if (dimension < 2)
	{
		std::cout << "Enter a point on the real line ";
		std::cin >> point[0];
	}
	else
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
			
			std::cout << "coordinate ";
			
			std::cin >> point[i];
		}
	}
}

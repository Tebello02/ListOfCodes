#include <iostream>
#include "INTERFACE__class{a4SidedRegularPolygon}.h"

int main()
{
	a4SidedRegularPolygon F1, F2(2,4);
	
	std::cout << "F1:\n\n" << F1;
	std::cout << "F2:\n\n" << F2;
	
	std::cout << "Enter New Data for F1:\n";
	std::cin >> F1;
	
	std::cout << "Enter New Data for F2:\n";
	std::cin >> F2;
	
	std::cout << "F1:\n\n" << F1;
	std::cout << "F2:\n\n" << F2;
	
	return 1;
}
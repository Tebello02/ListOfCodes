// The main function to test class aWrapper 

#include <iostream>
#include "aWrapper.h"


int main()
{
  // Encapsulate real numbers in variable named var
  aWrapper <double> var;

  std::cin >> var;
  std::cout << var << "\n";

  // Encapsulate strings in a variable named var1
  aWrapper <std::string> var1;

  std::cin >> var1; // The string will be captured and
  std::cout << var1 << "\n";  // The wrapped string will be displayed

















  return 11;
}

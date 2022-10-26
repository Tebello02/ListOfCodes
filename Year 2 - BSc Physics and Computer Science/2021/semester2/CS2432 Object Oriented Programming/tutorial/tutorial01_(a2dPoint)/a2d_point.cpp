// Program Description: This is a modified Class{a2D_Point}.
//                      This modification makes use of the class as a 
//                      header file (a2d_point.h) included in a modified .cpp
//                       source code
//                      (#include "a2d_point.h")
//                      file. (This file is an answer to Tutorial_01)
// Author             : Lipholo N.
// Date               : March 23 2022 (Date of first completion)
// email address      : nelipholo@gmail.com


// ***** What's New ***** //
// Added the subtraction operator '-' (Overloaded). Available in the 
// header file a2d_point.h

#include <iostream>
#include "a2d_point.h"


// The main function to test our "a2d_point" object class



int main()
{
  a2d_point Point1,       // Declares Point1 as a 2D point with values: (0, 0)
            Point2(1, 2), // Declares Point2 as a 2D point with values: (1, 2)
            Point3(3);    // Declares Point2 as a 2D point with values: (3, 0)

  a2d_point Point4; // The new instance of the object a2d_point named Point4

  double num;
  num = 2;

  std::cout << "\n";
  // Below we shall display the values of the three points on the screen using
  // the overloaded '<<' operator
  std::cout << "The points below are declared using a constructor:" << "\n";
  std::cout << "Point1: " << Point1 << "\n";
  std::cout << "Point2: " << Point2 << "\n";
  std::cout << "Point3: " << Point3 << "\n";


  std::cout << "\n";
  // Function calls to the member function distance() to get the distance of the
  // given point(using a constructor), from the origin
  std::cout << "Below we print the distances of initial points from the origin: " << "\n";
  std::cout << "The distance of point 3 from the origin: " << Point3.distance() << "\n";
  std::cout << "The distance of point 2 from the origin: " << Point2.distance() << "\n";
  std::cout << "The distance of point 1 from the origin: " << Point1.distance() << "\n";


  std::cout << "\n";
  // Below we make different function calls to the 'get' functions
  std::cout << "Below we print the x and/or y coordinates for different points using the 'get' function: " << "\n";
  std::cout << "The y-coordinate for point1: " << Point1.get_yCoord() << "\n";
  std::cout << "The x-coordinate for point3: " << Point3.get_xCoord() << "\n";
  std::cout << "The x and y coordinates for point2-(x, y): " << "(" << *Point2.get_xyCoord() << ", " << *Point2.get_xyCoord() + 1 << ")" <<"\n";


  std::cout << "\n";
  // Below we change, x, y and xy coordinates for 3 points chosen at random
  // by making function calls to different 'set...' method(s)
  std::cout << "Below we make use of the method display() and set_var() at the same time to change the x, y and/or xy coordinates of 2d points: " << "\n";

  std::cout << "Point1 before set: "; Point1.display();
  std::cout << "\nPoint1 after set (set xCoord): ";
  Point1.set_xCoord(7); Point1.display();

  std::cout << "\n";
  std::cout << "Point2 before set: "; Point2.display();
  std::cout << "\nPoint2 after set (set yCoord): ";
  Point2.set_yCoord(9); Point2.display();
 
  std::cout << "\n";
  std::cout << "Point3 before set: "; Point3.display();
  std::cout << "\nPoint3 after set (set xyCoord): ";
  Point3.set_xyCoord(6,4); Point3.display();


  std::cout << "\n\n";
  // input() method function call(s) and also make use of the display() method
  // to see the new values captured using the input() method
  std::cout << "We make use of the input() method by creating a new point-Point4: " << "\n";
  Point4.input();
  std::cout << "Point4: ", Point4.display();


  std::cout << "\n\n";
  // Usage of the overloaded operators
  std::cout << "We make use of the overloaded '=' as follows: \n";
  std::cout << "Point2 before assignment: " << Point2 << "\n";

  std::cout << "Point2 after assigning Point3 coordinates: "; Point2 = Point3;
  std::cout << Point2 << "\n";

  std::cout << "We make use of the overloaded '==' as follows: \n";
  
  if (Point2 == Point2)
  {
    std::cout << Point2 << " == " << Point2;
  }

  std::cout << "\nWe make use of the overloaded '!=' as follows: \n";
 
  if (Point2 != Point4)
  {
    std::cout << Point2 << " != " << Point4;
  }

  std::cout << "\nWe make use of the overloaded '+' as follows: \n";
  std::cout << Point1 << " + " << Point2 << " = " << (Point1 + Point2);

  std::cout << "\nWe make use of the overloaded '*' (Dot Product) as follows: \n";
  std::cout << Point3 << " * " << Point4 << " = " << (Point3 * Point4);

  std::cout << "\nWe make use of the overloaded '*' (Scalar Multiplication) as follows: \n";
  std::cout << Point3 << " * " << num << " = " << (Point3 * num);


  std::cout << "\n";
  // Explicit usage/function calls of non-member functions
  std::cout << "\n Funtion call of the distance() method to find the distance between any two points: \n";

  std::cout << "Distance between: " << Point2 << " and " << Point3 << " is: " << distance(Point2, Point3);
  
  std::cout << "\n";
  // Scalar multiplication from the left
  std::cout << "Scaled vector. Multiplication from the left: \n";
  std::cout << num << " * " << Point3 << " = " << (num * Point3);


  // One last usage of overloaded string insertion operator and overloaded sting extraction operators
  std::cout << "\n\n";
  std::cout << "Setting new values using the overloaded string insertion operator '>>'(modifying Point1): \n";
  std::cin >> Point1;

  std::cout << "Printing the new values to the console using the overloaded string extraction operator '<<' (printing Point1): \n";
  std::cout << Point1;


  // Answer to question (2) of tutorial 01 - Making use of the new specification
  // to the overloaded '-' operator
  std::cout << "\n\n";
  std::cout << "The difference between two points (Treated as 2d vectors): ";
  std::cout << Point4 << " - " << Point3 << " = " << (Point4 - Point3);
  std::cout << "\n\n";

  return 1;
}
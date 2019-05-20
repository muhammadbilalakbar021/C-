#include "shapes.hpp"
#include <iomanip>
#include <iostream>

int main()
{

  int h, w;
  std::cout << "Please enter the width for shape: ";
  std::cin >> w;
  std::cout << "Please enter the height for shape: ";
  std::cin >> h;

  // Create an instance of the `Shape` object and set the width and height
  // according to the user's input
  shape s(w,h);

  std::cout << "Please enter the width for rectangle: ";
  std::cin >> w;
  std::cout << "Please enter the height for rectangle: ";
  std::cin >> h;

  // Create an instance of the `Rectangle` object and set its width and height
  // according to the user's input
  Rectangle r(w,h);

  std::cout << "Please enter the width for triangle: ";
  std::cin >> w;
  std::cout << "Please enter the height for triangle: ";
  std::cin >> h;

  // Create an instance of the `Triangle` object and set its width and height
  // according to the user's input
  Triangle t(w,h);

  // Assign the instance of the `Shape` object's width and height to these
  // variables
  int shape_width, shape_height;
  shape_height=s.getHeight_();
  shape_width=s.getWidth_();

  // Assign the instance of the `Rectangle` object's width, height and area to
  // these variables
  int rectangle_width, rectangle_height, rectangle_area;
  rectangle_width=r.getWidth_();
  rectangle_height=r.getHeight_();
  rectangle_area=r.calcArea();

  // Assign the instance of the `Triangle` object's width, height and area to
  // these variables
  int triangle_width, triangle_height, triangle_area;
  triangle_width=t.getWidth_();
  triangle_height=t.getHeight_();
  triangle_area=t.calcArea();

  std::cout << "Printing shape:\n"
            << "Width: " << std::setw(3) << std::left << shape_width
            << "Height: " << shape_height << "\n"
            << "Printing rectangle:\n"
            << "Width: " << std::setw(3) << std::left << rectangle_width
            << "Height: " << std::setw(3) << std::left << rectangle_height
            << "Area: " << rectangle_area << "\n"
            << "Printing triangle:\n"
            << "Width: " << std::setw(3) << std::left << triangle_width
            << "Height: " << std::setw(3) << std::left << triangle_height
            << "Area: " << triangle_area << "\n";


  return 0;
}

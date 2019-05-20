#include <iostream>

#include "car_comp.hpp"

int main()
{
  // Create four instances of a `Car` object using the different
  // constructors described below

  // Create a Car object using the default constructor and call it c1
  Car c1;

  // Create an `Identifier` object with the following information:
  // Name - Honda, ID - 3, License plate - 7B319X4
  Identifier identifier("Honda",3,"7B319X4");

  // Create a `Car` object using the constructor that accepts an `Identifier`
  // object and pass in the `Identifier` object you just created; call it c2

  Car c2(identifier);

  // Create a `Date` object with the following information:
  // Day - 4, Month - 11, Year - 2018

  Date date(4,11,2018);

  // Create a `Car` object using the constructor that accepts a `Date` object
  // and pass in the `Date` object you just created; call it c3
  Car c3(date);

  // Create a `Car` object using the constructor that accepts an `Identifier`
  // and `Date` object then pass in the `Identifier` and `Date` objects you
  // created previously; call it c4

  Car c4(identifier,date);

  // Print member function for `c1`
  c1.print();
  std::cout << "\n";

  // Print member function for `c2`
  c2.print();
  std::cout << "\n";

  // Print member function for `c3`
  c3.print();
  std::cout << "\n";

  // Print member function for `c4`
  c4.print();
  std::cout << "\n";

  // An instance of the `Identifier` object using the default constructor
  Identifier i;
  // An instance of the `Date` object using the default constructor
  Date d;

  // Call to set the `identity` of `c4` and pass in `i`
  c4.setIdentity_(i);

  // Call to set the `release date` of `c4` and pass in `d`
  c4.setRelease_date_(d);

  // Call to `print` `c4`
  c4.print();

  return 0;
}

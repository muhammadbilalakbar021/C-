#include "car.hpp"
#include <iomanip>
#include <iostream>

int main()
{
  int choice;
  std::string name;
  int year;
  double tank, mpg;
  double speed;

  // declare a pointer to a Car object here

  std::cout << "Ubiquitous on-board driving management software test: - "
               "Gas/battery level sensor - \n";
  std::cout << "What type of car is being tested?\n";
  std::cout << "1 - Gasoline Car\n";
  std::cout << "2 - Electric Car\n";
  std::cout << "0 - Exit\n";
  std::cin >> choice;
  std::cin.ignore();

  if (choice == 1) {

    std::cout << "What is the name of the car? ";
    std::getline(std::cin, name);
    std::cout << "What year is the car? ";
    std::cin >> year;
    std::cout << "How many gallons of gas can this car store? ";
    std::cin >> tank;
    std::cout << "How much MPG does this car have? ";
    std::cin >> mpg;

    // Use the car pointer declared above to dynamically declare an object of
    // type GasolineCar using the non default constructor with the user's input.
    // Take note that you need to delete the memory address stored in the car
    // pointer before dynamically allocating it to avoid memory leaks

    std::cout << "How fast do you want to drive this car per hour? ";
    std::cin >> speed;

    int hours = 0;
    do {
      hours++;
      // call the drive function on the car pointer to drive the car

    } while (/* Repeat the loop while the car is NOT empty */);
    std::cout << "It took " << name << ", " << hours
              << " hour(s) of driving to empty the tank\n";
  }
  else if (choice == 2) {
    std::cout << "What is the name of the car? ";
    std::getline(std::cin, name);
    std::cout << "What year is the car? ";
    std::cin >> year;

    // Use the car pointer declared above to dynamically declare an object of
    // type ElectricCar using the non default constructor with the user's input.
    // Take note that you need to delete the memory address stored in the car
    // pointer before dynamically allocating it to avoid memory leaks

    std::cout << "How fast do you want to drive this car per hour? ";
    std::cin >> speed;
    int hours = 0;

    do {
      hours++;
      // call the drive function on the car pointer to drive the car
    } while (/* Repeat the loop while the car is NOT empty */);
    std::cout << "It took " << name << ", " << hours
              << " hour(s) of driving to empty the battery\n";
  }
  else if (choice == 0) {
    std::cout << "Shutting down...\n";
  }
  else {
    std::cout << "Error - Shutting down...\n";
  }

  return 0;
}

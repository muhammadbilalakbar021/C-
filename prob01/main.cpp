#include <iostream>
#include <iomanip>
#include "breed.h"
#include "Pet.hpp"

const int MAX_SIZE = 100;

int main()
{
   //Create an array of MAX_SIZE Pet objects called `pet_arr`

      const int maxSize=100;
    int num_Pet=0;
    std::string name, breed, species, color;
    Pet pets[maxSize];
    double weight;
    do {
        std::cout << "Please enter the pet's name (q to quit): ";
        std::getline(std::cin, name);

        if (name == "q") {
            continue;
        }

        std::cout << "Please enter the pet's species: ";
        std::getline(std::cin, species);
        std::cout << "Please enter the pet's breed: ";
        std::getline(std::cin, breed);
        std::cout << "Please enter the pet's color: ";
        std::getline(std::cin, color);
        std::cout << "Please enter the pet's weight (lbs): ";
        std::cin >> weight;
        std::cin.ignore();

        // Create a breed object using the input from the user

        // Create a pet object using the input from the user

        pets[num_Pet].setName_(name);
        pets[num_Pet].setSpecies_(species);
        pets[num_Pet].setBreed_(breed);
        pets[num_Pet].setColor_(color);
        pets[num_Pet].setWeight_(weight);

        num_Pet++;
        // Store the newly-created pet object into the array. Use `num_pet` to
        // control the index where the pet object is placed and update it
        // accordingly

    } while (name != "q");

    std::cout << "Printing Pets:\n";

    for (int i = 0; i < num_Pet; i++) {
      std::cout << "Pet " << i + 1 << "\n";
      std::cout<< std::setw(8) << std::left << "Name :" << pets[i].getName_() <<"\n";
      std::cout<< std::setw(8) << std::left << "Species :" << pets[i].getSpecies_() <<"\n";
      std::cout<< std::setw(8) << std::left << "Breed :" << pets[i].getBreed_() <<"\n";
      std::cout<< std::setw(8) << std::left << "Color :" << pets[i].getColor_() <<"\n";
      std::cout<< std::setw(8) << std::left << "Weight :" << pets[i].getWeight_() <<"\n";
    }
  return 0;
}

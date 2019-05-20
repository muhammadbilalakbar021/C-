// Use << setw(8) << left to ensure there are 8 characters to the left
// of the pet information. For example:
// cout << setw(8) << left << "Name:" << the_name << endl;

#include <iostream>
#include <iomanip>
#include "Pet.hpp"
#include "breed.h"

Pet::Pet(const std::string &breed_, double weight_) : breed_(breed_), weight_(weight_) {}

breed b;

const std::string &Pet::getBreed_() const {
    return breed_;
}

void Pet::setBreed_(const std::string &breed_) {
    Pet::breed_ = breed_;
}

const double &Pet::getWeight_() const {
    return weight_;
}

void Pet::setWeight_(const double &weight_) {
    Pet::weight_ = weight_;
}
void Pet::Print()
{
    std::cout<< std::setw(8) << std::left << "Name :" << b.getName_();
}


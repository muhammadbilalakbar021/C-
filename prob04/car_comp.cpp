#include <iostream>

#include "car_comp.hpp"

Car::Car(const Identifier &identity_, const Date &release_date_):
identity_(identity_),
release_date_(release_date_){};

Car::Car(const Identifier &identity_):
identity_(identity_){};

Car::Car(const Date &release_date_):
release_date_(release_date_){};

Car::Car(){}

void Car::print()
{
  std::cout << "The name of the car is: " << identity_.getName() << std::endl;
  std::cout << "The id of the car is: " << identity_.getId() << std::endl;
  std::cout << "The license plate of the car is: " << identity_.getLicensePlate() << std::endl;
  std::cout << "The release date of the car is: " << release_date_.getMonth() << "/"
    << release_date_.getDay() << "/" << release_date_.getYear() << std::endl;
}

const Identifier &Car::getIdentity_() const {
    return identity_;
}

void Car::setIdentity_(const Identifier &identity_) {
    Car::identity_ = identity_;
}

const Date &Car::getRelease_date_() const {
    return release_date_;
}

void Car::setRelease_date_(const Date &release_date_) {
    Car::release_date_ = release_date_;
}

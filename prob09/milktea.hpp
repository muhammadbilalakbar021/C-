#ifndef MILKTEA_HPP
#define MILKTEA_HPP

#include <iomanip>
#include <iostream>
#include <string>

// Create class called `topping`
class Topping
{
  private:
    // Create private member variables
    std::string name_;
    double cost_;

  public:
    // Create default constructor
    Topping() : Topping("Boba", 0.50) {}

    // Create non-default constructor
    Topping(const std::string &name, double cost) : name_(name), cost_(cost) {}

    // Create accessors and mutators
    std::string getName() const { return name_; }
    void setName(const std::string &name) { name_ = name; }
    double getCost() const { return cost_; }
    void setCost(double cost) { cost_ = cost; }

    // Create member function to print out name and cost of the topping
    void printTopping() {
      std::cout << "Topping: " << name_ << "\n";
      std::cout << "Cost: $" << std::fixed << std::setprecision(2) << cost_
                << "\n";
    }
};

// Create the `MilkTea` class below...

#endif

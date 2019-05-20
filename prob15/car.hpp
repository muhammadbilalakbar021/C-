#include <string>

// Car history references:
// https://www.loc.gov/rr/scitech/mysteries/auto.html
// https://www.mercedes-benz.com/en/mercedes-benz/classic/history/benz-patent-motor-car/

class Car
{
  private:
    std::string name_;
    int year_;
    double speed_;

  public:
    Car() : Car("Steam automobile", 1769) {}
    Car(const std::string &name, int year)
      : name_(name), year_(year), speed_(0) {}

    void setName(const std::string &name) { name_ = name; }
    void setYear(int year) { year_ = year; }

    std::string getName() const { return name_; }
    int getYear() const { return year_; }
    double getSpeed() const { return speed_; }

    // Create the virtual functions as described in the readme for drive and isEmpty
};

//Implement the ElectricCar and GasolineCar class below.
